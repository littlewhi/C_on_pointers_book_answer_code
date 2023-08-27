#include "a.h"

/* answer3 code */
void swap( char *a, char *b )
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_string( char *string )
{
    char *tail = string + strlen( string ) - 1;
    while( string < tail )
        swap( string++, tail-- );
}

void a3( void )
{
    char str[] = "abcdef";
    printf( "str = %s\n", str );
    reverse_string( str );
    printf( "reversed string = %s\n", str );
}
