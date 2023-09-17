#include "a.h"

void in_line_and_out( void )
{
    char line[128] = "";
    int i = 0;
    int ch;
    while( fgets( line, 128, stdin ) )
    {
        printf( "%s", line );
    }
}

void a2( void )
{
    in_line_and_out();
}
