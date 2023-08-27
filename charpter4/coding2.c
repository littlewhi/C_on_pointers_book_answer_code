#include "a.h"

int isPrime( int val )
{
    int i;

    if( val < 2 )
        return 0;
    
    if( val < 4 )
        return 1;

    for( i = (int) sqrt( val ); i >= 2; --i )
    {
        if( val % i == 0 )
            return 0;
    }
    return 1;
}

void a2( void )
{
    int i;
    for( i = 1; i < 100; ++i )
    {
        if( isPrime(i) )
        {
            printf( "%d ", i );
        }
    }
    puts( "" );
}