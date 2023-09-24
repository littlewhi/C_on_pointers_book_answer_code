#include "a.h"

void insertion_sort( void *base, size_t num, size_t size, int( *comparison )( void *a, void *b ) )
{
    int i, j;
    void *tmp = malloc( size );

    for( i = 1; i < num; i++ )
    {
        memcpy( tmp, base + i * size, size );
        for( j = 0; j < i; j++)
        {
            if( comparison( base + j * size, base + i * size ) > 0 )
            {
                
                memmove( base + (j + 1) * size, base + j * size, size * (i - j) );
                break;
            }
        }
        memcpy( base + j * size, tmp, size );
    }
}

int cmp( void *a, void *b )
{
    return *( int * ) a - *( int * ) b;
}

int print_for( int *arr, int num )
{
    int i;
    for( i = 0; i < num; i++ )
    {
        printf( " %d ", arr[i] );
    }
    return 0;
}

void a10( void )
{
    int arr[] = {
        23, 44, 45, 4,
        45, 545, 5, 4,
        2, 4, 52, 4, -2
    };

    print_for( arr, sizeof( arr ) / sizeof( arr[0] ) );
    printf( "\n" );
    insertion_sort( arr, sizeof( arr ) / sizeof( arr[0] ), sizeof( int ), cmp );
    print_for( arr, sizeof( arr ) / sizeof( arr[0] ) );
    printf( "\n" );
}
