#include "a.h"

void in_and_out( void )
{
    int ch;
    while( ( ch = getchar() ) != EOF )
        putchar( ch );
}

void a1( void )
{
    in_and_out();
}
