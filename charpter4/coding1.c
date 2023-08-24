#include <stdio.h>
#include <stdlib.h>

void approximateNumber( double x )
{
    double approx = 1., next = 1.;
    int cnt = 0;
    
    do
    {
        approx = next;
        printf( "Number %d : %.30lf\n", cnt++, approx );
        next = ( approx + x / approx ) / 2.;
    }
    while( next != approx );
    
    printf( "The final result is %.9lf\n", approx );
}

/* User can select the number in command line argument */
int main( int argc, char **argv  )
{
    double val = 9.0;
    if( argc >= 2 )
        val = strtod( argv[1], NULL );

    printf( "This is what I will calculate : %.9lf\n", val );

    approximateNumber( val );

    return 0;
}