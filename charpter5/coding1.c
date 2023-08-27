#include "a.h"

void a1( void )
{
    int ch;
    while( ( ch = getchar() ) != EOF )
    {
        putchar( tolower( ch ) );
    }
}
