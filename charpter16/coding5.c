#include "a.h"

double wind_chill( double temp, double velocity )
{
    double A, B, C, X, dt;

    A = 10.45;
    B = 10.;
    C = -1;
    X = 1.78816;
    dt = 33-temp;

    return dt * ( A + B * sqrt( velocity ) + C * velocity ) /
        ( A + B * sqrt( X ) + C * X );
}

void a5( void )
{
    printf( "temp = %lf, velocity = %lf\n", -5., 10. );
    printf( "WindChill = %lf\n", wind_chill( -5., 10. ) );
}
