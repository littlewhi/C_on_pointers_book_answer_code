#include "a.h"
#include <stdlib.h>

#define INIT_SIZE 512

char *get_string_from_input( void )
{
    char *str = NULL, *new_str = NULL;
    int len = 0, size = INIT_SIZE;
    char ch;

    str = (char *)malloc( INIT_SIZE );
    if( str == NULL )
        return NULL;

    while( ( ch = getchar() ) != EOF )
    {
        str[len++] = ch;
        
        if( len + 1 == size )
        {
            new_str = realloc( str, size *= 2 );
            if( new_str == NULL )
            {
                printf( "realloc failed\n" );
                break;
            }
            str = new_str;
        }
    }
    return str;
}

void a3( void )
{
    char *str = get_string_from_input();
    if( str == NULL )
        printf( "get_string_from_input failed\n" );

    printf( "\nThe input string is %s\n", str );
    free( str );
}
