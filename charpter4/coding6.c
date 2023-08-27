#include "a.h"

int substr( char dst[], char src[], int start, int len )
{
    int i = 0;

    if( start < 0 || len < 0 )
    {
        *dst = 0;
        return 0;
    }

    while( *src && i < start )
        i += 1, src += 1;                   

    /* start过大 */
    if( i < start )
    {
        *dst = 0;
        return 0;
    }

    for( i = 0; i < len && *src; i++ )
    {
        *dst++ = *src++;
    }
    *dst = 0;

    return i;
    
}

void a6( void )
{
    char src[512] = "hello world!";
    char dst[512];

    substr( dst, src, strchr( src, 'w' ) - src, strlen( src ) );
    printf( "src = %s\n", src );
    printf( "dst = %s\n", dst );

}