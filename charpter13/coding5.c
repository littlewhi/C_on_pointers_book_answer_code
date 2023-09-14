#include "a.h"

/*
 * 每次只处理一个参数，且其位置必须是0。
*/
char **do_args( int argc, char **argv, char *control, 
    void (*do_arg)( int ch, char *value ), void (*illegal_arg)( int ch ) )
{
    int i, j, len, inc;
    char *pos = NULL;
    
    i = 1;
    if( argv[0][0] == '-')
    {
        j = 1;
        len = strlen( argv[0] );
        while( j < len )
        {
            if( ( pos = strchr( control, argv[0][j] ) ) != NULL )
            {
                if( pos[1] == '+' )
                {
                    if( i < argc )
                    {
                        do_arg( *pos, argv[i] );
                        i += 1;
                        j += 1;
                    } 
                    else
                    {
                        illegal_arg( *pos );
                        j += 1;
                    }
                        
                }
                else
                {
                    do_arg( *pos, NULL );
                    j += 1;
                }
            }
            else
            {
                illegal_arg( argv[0][j] );
                j += 1;
            }
        }
    }
    printf( "return &argv[%d]\n", i );
    return &argv[i];
}


void do_arg( int ch, char *value )
{
    printf( "do_arg( %c, %s )\n", ch, value ? value : "NIL" );
    fflush( stdout );
}

void illegal_arg( int ch )
{
    printf( "illegal_arg( %c )\n", ch );
    fflush( stdout );
}


struct test_data_t {
    char control[64];
    char *cmdline[16];
    int num_args;
#define NUM_TEST_DATA 8
}test_data[NUM_TEST_DATA];

void a5( void )
{
    int i, cnt = 0;
    test_data[cnt++] = (struct test_data_t) { "x", { "-x", "-y", "z" }, 3 };
    test_data[cnt++] = (struct test_data_t) { "x+y+z+", { "-x", "-y", "-z" }, 3 };
    test_data[cnt++] = (struct test_data_t) { "ab+cdef+g", { "-abcd", "-ef", "ghi", "jkl" }, 4 };
    test_data[cnt++] = (struct test_data_t) { "abcdef", { "-a", "b", "-c", "-d", "-e", "-f" }, 6 };
    for( i = 0; i < cnt; i++ )
        do_args( test_data[i].num_args, (char **) (test_data[i].cmdline), test_data[i].control, do_arg, illegal_arg );
}
