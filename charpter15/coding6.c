#include "a.h"

int calculate_length_of_int( void )
{
    char buf[128];
    sprintf( buf, "%d", INT_MAX );
    return strlen( buf );
}

int numeric_palindrome( int value )
{
    char buf[128];
    int i, j;
    
    sprintf( buf, "%d", value );
    j = strlen( buf ) - 1;
    i = 0;

    while( i < j )
        if( buf[i] != buf[j] )
            return 0;
        else
            ++i, --j;
    return 1;
}

void a6( void )
{
    int num;
    printf( "Please enter your number:\n" );
    scanf( "%d", &num );
    printf( "%d is %s a ""palindrome number\n", num, numeric_palindrome( num ) ? "" : "not");
}
