#include "a.h"

static int hermite( int n, int x )
{
    if( n <= 0 )
        return 1;
    if( n == 1 )
        return x * 2;

    return x * 2 * hermite( n - 1, x ) - (n - 1) * 2 * hermite( n - 2, x );
}

void a1( void )
{
    int n, x;
    printf( "Please enter two number for n x:\n" );
    scanf( "%d %d", &n, &x );
    printf( "The Hermite Polynomials result is %d\n", hermite( n, x ) );
}