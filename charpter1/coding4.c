#include <stdio.h>
#include <string.h>

int main( void )
{
    char cbuf[1024], nbuf[1024];
    int clen = 0, nlen;

    while( scanf( "%s", nbuf ) != EOF )
    {
        if( ( nlen = strlen( nbuf ) ) > clen )
        {
            strcpy( cbuf, nbuf );
            clen = nlen;
        }
    }

    puts( cbuf );

    return 0;

}