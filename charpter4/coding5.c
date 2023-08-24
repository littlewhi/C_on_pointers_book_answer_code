#include <string.h>
#include <stdio.h>

int main( void )
{
    char pbuf[256], cbuf[256];
    int isPrint = 0;

    while( fgets( cbuf, sizeof( cbuf ), stdin ) )
    {
        if( strcmp( cbuf, pbuf ) == 0 )
        {
            isPrint = 1;
            continue;
        }
        else if( isPrint == 1 )
        {
            printf( "%s", pbuf );
            isPrint = 0;
        }
        strcpy( pbuf, cbuf );
    }

    if( isPrint == 1 )
        printf( "%s", pbuf );

    return 0;
}