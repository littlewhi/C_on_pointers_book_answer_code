#include "a.h"

/* len is the number of characters will be copied at most minus one
 * because of the '\0'
 */
unsigned int my_strcpy( char *dst, const char *src, unsigned int len )
{
    int i;
    for( i = 0; i < len && *src; i++ )
    {
        *dst++ = *src++;
    }
    if( i == len )
        *( dst - 1 ) = 0;
    else 
        *dst = 0;
    return i;
}

void a3( void )
{
    char dst[16];
    const char *src = "123456789000";
    my_strcpy( dst, src, 5 );
    printf( "original string is %s\n", src );
    printf( "new string is %s\n", dst );
    
}