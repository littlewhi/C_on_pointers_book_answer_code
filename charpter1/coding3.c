#include "a.h"

void a3( void )
{
    int ch;
    signed char checksum = -1;
    while( (ch = getchar()) != EOF )
    {
        checksum += ch;
    }

    printf( "%d\n", checksum );
}