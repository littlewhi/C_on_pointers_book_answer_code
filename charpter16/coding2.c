#include "a.h"

int return_dice_value( void )
{
    static int document = 0;
    if( !document )
    {
        srand( time( NULL ) );
        document = 1;
    } 
    
    return rand() % 6 + 1;
}

void a2( void )
{
    int n, i;
    int percent_value[6] = { 0 };

    printf( "Please enter times for simulation of the program:\n" );
    scanf( "%d", &n );

    for( i = 0; i < n; i++ )
    {
        percent_value[return_dice_value() - 1] += 1;
    }

    for( i = 0; i < 6; i++ )
    {
        printf( "%d : %.4lf%%\n", i + 1, percent_value[i] * 100. / n );
    }
}
