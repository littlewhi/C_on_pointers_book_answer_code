#include "a.h"

double approximateNumber( double x )
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

    return approx;
}

/* User can select the number in command line argument */
void a1( void )
{
    double val;
    printf( "Please enter a float number for calculation:\n" );
    scanf( "%lf", &val );    

    printf( "This is what I will calculate : %.9lf\n", val );
    
    printf( "The final result is %.9lf\n", approximateNumber( val ) );
}