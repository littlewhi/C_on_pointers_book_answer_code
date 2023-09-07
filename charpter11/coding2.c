#include "a.h"

#define INIT_SIZE 512

int *get_number_from_input( void )
{
    int *buf = NULL, size = INIT_SIZE, *newbuf = NULL;
    int num = 0;
    int get_num;

    buf = malloc( sizeof(int) * INIT_SIZE );
    if( buf == NULL )
        return NULL;

    while( scanf("%d", &get_num) != EOF )
    {
        //getchar(); 
        if( num == size )
        {
            newbuf = realloc( buf, size *= 2 );
            if( newbuf == NULL )
            {
                printf( "realloc failed\n" );
                break;
            }
            buf = newbuf;
        }   
        buf[++num] = get_num;
    }
    buf[0] = num;
    return buf;
}

void print_int_num( int *nums )
{
    int n;

    if( nums == NULL )
        return;

    n = nums[0];
    for( int i = 1; i <= n; ++i )
    {
        printf( "nums[%d] = %d\n", i, nums[i] );
    }
}

void a2( void )
{
    int *ptr = NULL;
    print_int_num( ptr = get_number_from_input() );
    free( ptr );
}
