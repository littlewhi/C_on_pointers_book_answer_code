#include "a.h"

/*
 * len is the number of characters will be appended to the end of dst at most minus oen,
 * because the '\0'  
 */
unsigned int my_strcat( char *dst, const char *src, unsigned int len )
{
    int i;
    char* end = dst + strlen( src );
    for( i = 0; i < len && *src; i++ )
    {
        *end++ = *src++;
    }
    if( i == len ) 
        *(end - 1) = '\0';
    else
        *end = '\0';
    return i;
}

void a4( void )
{
    char dst[16] = "abc";
    char src[16] = "abc";
    printf( "dst = %s\n", dst );
    printf( "src = %s\n", src );
    my_strcat( dst, src, 4 );
    printf( "new dst = %s\n", dst );
}