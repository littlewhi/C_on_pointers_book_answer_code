#include "a.h"

char *my_strcpy_end( char *dest, const char *src )
{
    while( ( *dest++ = *src++ ) != '\0' )
        ;
    return dest - 1;
}

void a6( void )
{
    char dest[16] = "123";
    const char *src = "4";
    printf( "%d\n", *my_strcpy_end( dest, src ) );
}