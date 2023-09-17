#include "a.h"

static void in_line_and_out( void )
{
    char line[128];
    int i;
    while( fgets( line, 5, stdin ) )
    {
        printf( "%s", line );
    }
}

void a3( void )
{
    in_line_and_out();
}
