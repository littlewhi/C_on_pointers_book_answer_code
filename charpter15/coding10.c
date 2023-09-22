#include "a.h"

static unsigned int get_sum_of_file( FILE *file )
{
    unsigned int sum = 0;
    int i, read_count;
#define BUFFERSIZE 512
    unsigned char buffer[BUFFERSIZE];


    if( !file )
        return 0;

    while( ( read_count = fread( buffer, sizeof( char ), BUFFERSIZE, file ) ) )
    {
        for( i = 0; i < read_count; i++ )
        {
            sum += buffer[i];
        }
    }

    return sum;
}

static int calculate_check_sum( int argc, const char **argv)
{
    int i;
    FILE *fp = NULL;

    if( argc == 1 )
    {
        printf( "%d\n", get_sum_of_file( stdin ) ); 
        return 1;
    }

    if( argc == 2 && !strcmp( argv[1], "-f" ) )
    {
        printf( "-f illegal when reading standard input\n" );
        return 0;
    }

    for( i = 2; i < argc; i++ )
    {
        if( !( fp = fopen( argv[i], "r" ) ) )
        {
            fprintf( stderr, "Cannot open file : %s\n", argv[i] );
            return i - 2;
        }

        printf( "%d\n", get_sum_of_file( fp ) );
        fclose( fp );
    }
    return argc;
}

struct commandline_t{
    char *argv[16];
    int argc;
}cmds[8] = {
    { { "sum" }, 1 },
    { { "sum", "-f", "t10_data/hw" }, 3 },
    { { "sum", "-f" }, 2 }
};

void a10( void )
{
    int i, j;
    for( i = 0; i < 3; i++ )
    {
        for( j = 0; j < cmds[i].argc; j++ )
            printf( "%s ", cmds[i].argv[j] );
        puts( "" );

        calculate_check_sum( cmds[i].argc, (const char **)(cmds[i].argv) );
    }
}
