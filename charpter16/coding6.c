#include "a.h"

double payment( double amount, double interest, int years )
{
    double i = interest / 12 * 0.01;
    double p = years * 12;

    return amount * i / ( 1 - pow( 1 + i, -p ) );
}

void a6( void )
{
    double amount = 100000., interest = 8.;
    int years = 20;

    printf( "amount = %.2lf, interest = %.2lf, years = %d\n", amount, interest, years );
    printf( "payment of every month = %.2lf\n", payment( amount, interest, years ) );
}
