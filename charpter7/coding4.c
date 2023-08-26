#include "a.h"

#define LIST_SIZE 1024

int max_list( const int *list )
{
    int ret = -1;
    while( *list != -1 )
        ret = MAX( ret, *list++ );

    return ret;
}

void a4( void )
{
    int i = 0;
    int list[LIST_SIZE];
    while( 1 )
    {
        scanf( "%d", list + i );
        if( list[i] == -1 )
            break;

        i += 1;
        if( i == LIST_SIZE )
        {
            printf( "You enter too many numbers.\n" );
            break;
        }
    }
    list[ LIST_SIZE - 1] = -1;
    printf( "The maximum number in your list is %d.\n", max_list( list ) );
}