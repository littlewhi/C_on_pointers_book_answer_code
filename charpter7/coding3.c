#include "a.h"
#include <ctype.h>

static int ascii_to_integer( const char *str )
{
    int ret = 0;
    while( *str )
    {
        if( isdigit( *str ) )
            ret = ret * 10 + ( *str++ - '0' );
        else
           return 0; 
    }
    return ret;
}

void a3( void )
{
    char buf[16];
    printf( "Please enter a number for the transformation:(at most 9 char)\n" );
    scanf( "%9s", buf );
    printf( "The original number string = %s\n", buf );
    printf( "The digital number = %d\n", ascii_to_integer( buf ) );
}