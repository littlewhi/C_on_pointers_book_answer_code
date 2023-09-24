#include "a.h"

double compute_probability_same_birthday( int num )
{
    int y_days[365] = { 0 };
    int i, j, sum = 0;
    
    for( i = 0; i < 10000; ++i )
    {
        for( j = 0; j < num; ++j )
        {
            y_days[rand() % 365]++;
        }
        for( j = 0; j < 365; ++j )
        {
            if( y_days[j] == 2 )
            {
                sum += 1;
            }
        }
        memset( y_days, 0, sizeof(y_days) );
    }

    return sum / 10000.;
}

void a9( void )
{
    int num;
    srand( time( NULL ) );

    printf( "Please enter a number:\n" );
    while( scanf( "%d", &num ) != EOF )
    {
        printf( "%5.2lf%%\n", compute_probability_same_birthday( num ) );
        printf( "Please enter a number:\n" );
    }

}
