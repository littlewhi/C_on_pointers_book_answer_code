#include "a.h"

void do_test1( int *arr, int n )
{
    int i;
    for( i = 0; i < 10000; i++ )
    {
        arr[rand() % n] += 1;
    }

    for( i = 0; i < n; i++ )
    {
        printf( "%d : %d\n", i, arr[i] );
    }
}

void test1( void )
{
    int arr[16];
    int i;

    for( i = 2; i <= 10; i++ )
    {
        memset( arr, 0, sizeof(arr) );
        do_test1( arr, i );
        printf( "\n" );
    }
}

void do_test2( int *arr, int data[][16], int n )
{
    int i, j;

    for( i = 0; i < 10000; i++ )
    {
        data[rand() % n][rand() % n] += 1;
    }

    for( i = 0; i < n; i++ )
    {
        for( j = 0; j < n; j++ )
        {
            printf( "%d ", data[i][j] );
        }
        printf( "\n" );
    }
}

void test2( void )
{
    int arr[16], data[16][16];
    int i;

    for( i = 2; i < 11; i++ )
    {
        memset( arr, 0, sizeof(arr) );
        memset( data, 0, sizeof(data) );
        printf( "do test %d\n", i );
        do_test2( arr, data, i );
        printf( "\n" );
    }
}

void a7( void )
{
    srand( time( NULL ) );
    printf( "test1 : \n" );
    test1();
    printf( "test2 : \n" );
    test2();
}
