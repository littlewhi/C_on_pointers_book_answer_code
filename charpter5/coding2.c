#include "a.h"

void a2( void )
{
    int ch;
    while( ( ch = getchar() ) != EOF )
    {
        if( isupper( ch ) )
        {
            if( isupper( ch + 13 ) )
                ch += 13;
            else
                ch -= 13;
        }
        else if( islower( ch ) )
        {
            if( islower( ch + 13 ) )
                ch += 13;
            else
                ch -= 13;
        }

        putchar( ch );
    }
}

