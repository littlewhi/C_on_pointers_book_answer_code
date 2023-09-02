#include "a.h"

unsigned int my_strlen( const char *str, unsigned int len )
{
    int i;
    for( i = 0; i < len && *str ; ++i, ++str )
        ;
    return i;
}

void a2( void )
{
    char str[] = { '1', '3', '3', '4' };
    printf( "The size of the special string is %lu.\n", sizeof( str ) );
    printf( "The length of the special string is %u.\n", my_strlen( str, sizeof( str ) ) );
}