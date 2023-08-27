#include "a.h"

void copy_n( char dst[], char src[], int n )
{
    int i;
    for( i = 0; i < n && *src; i++ )
    {
        *dst++ = *src++;
    }

    if( i < n )
        *dst = '\0';
}

void a4( void )
{
    char s[40] = "hello";
    char d[40] = "world";

    printf( "src = %s\n", s );
    printf( "dst = %s\n", d );
    
    copy_n( d, s, strlen( s ) );
    printf( "dst = %s\n", d );
}