#include "a.h"

void my_strncat( char *dest, const char *src, int dest_len )
{
    char *end = NULL;
    int i, dlen;
    dlen = strlen( dest );
    end = dest + dlen;
    for( i = dlen; i < dest_len && (*end++ = *src++) != 0; i++ )
        ;
    if( i == dest_len )
        *(end - 1) = 0;
}

void a5( void )
{
    char dest[10] = "A string";
    const char *src = "another";

    printf( "dest = %s\n", dest );
    printf( "src = %s\n", src );
    my_strncat( dest, src, sizeof( dest ) );
    printf( "new dest = %s\n", dest );

}