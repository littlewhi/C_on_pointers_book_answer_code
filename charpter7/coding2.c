#include "a.h"

static int gcd( int m, int n )
{
    int r;
    if( m <= 0 || n <= 0)
        return 0;
    if( ( r = m % n ) == 0 )
        return n;

    return gcd( m , r );
}

void a2( void )
{
    int m, n;
    printf( "Please enter two numbers for m n:\n" );
    scanf("%d %d", &m, &n );
    printf( "The greatest common divisor of the two numbers %d and %d is %d.\n", m, n, gcd( MAX(m, n) , MIN(m, n) ) );
}