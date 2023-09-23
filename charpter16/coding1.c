#include "a.h"

int get_min_base( const char *origin, int dest )
{
    int i;
    int n;
    for( i = 2; i < 36; ++i )
    {
        n = strtol( origin, NULL, i);
        if( n >= dest )
            return i;
    }
    return 0;
}

void a1( void )
{
    int num;
    printf( "Please enter a number:\n" );
    while( scanf( "%d", &num ) != EOF )
    {
        printf( "%d\n", get_min_base( "29", num ) );
    }
}
