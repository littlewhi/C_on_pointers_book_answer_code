#include "x.h"

int main( void )
{
    int val = 45;
    printf( "the increment of %d is %d\n", val, increment( val ) );
    printf( "the negation of %d is %d\n", val, negate( val ) );

    return 0;
}
