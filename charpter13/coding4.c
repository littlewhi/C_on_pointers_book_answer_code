#include "a.h"

void mySort( void *head, int n, int len_of_unit, int( *cmp )( const void *a, const void *b ) )
{
    /* qsort( head, len_of_unit, n, cmp ); */
    void *left, *right;
    void *pivot = NULL;

    if( n < 2 )
        return;

    pivot = (void *) malloc( len_of_unit );
    if( pivot == NULL )
        return;
    
    memcpy( pivot, head, len_of_unit );
    left = head;
    right = head + len_of_unit * (n - 1);
    while( left < right )
    {
        while( left < right && cmp( right, pivot ) >= 0 )
        {
            right -= len_of_unit;
        }
        if( left < right )
        {
            memcpy( left, right, len_of_unit );
            //right -= len_of_unit;
        }    

        while( left < right && cmp( left, pivot ) <= 0 )
        {
            left += len_of_unit;
        }
        if( left < right )
        {
            memcpy( right, left, len_of_unit );
            //left += len_of_unit;
        }
    }

    memcpy( left, pivot, len_of_unit );
    free( pivot );
    mySort( head, ( left - head ) / len_of_unit, len_of_unit, cmp );
    mySort( left + len_of_unit, (head + n * len_of_unit - left - len_of_unit) / len_of_unit, len_of_unit, cmp );
}

int comp( const void *a, const void *b )
{
    int ret = 0;
    if( *(int *)a > *(int *)b )
        ret = 1;
    else if( *(int *)a < *(int *)b )
        ret = -1;
    return ret;
}

void a4( void )
{
    int i;
    int arr[] = { 5, 4, 3, 2, 1 };
    int arr1[] = { 1, 1, 1 };
    mySort( arr, sizeof( arr ) / sizeof( arr[0] ), sizeof( int ), comp );
    mySort( arr1, 3, 4, comp );
    for( i = 0; i < sizeof( arr ) / sizeof( arr[0] ); ++i )
    {
        printf("%d\n", arr[i] );
    }
}
