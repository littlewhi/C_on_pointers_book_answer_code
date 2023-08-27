#include "a.h"
/* answer1 code */
int match_char( const char ch, const char *chars )
{
    while( *chars )
    {
        if( ch == *chars++ )
            return 1;
    }

    return 0;
}

char *find_char( const char *source, const char *chars )
{
    if( source == NULL || chars == NULL )
        return NULL;

    while( *source )
    {
        if( match_char( *source, chars ) )
        {
            return (char *) source;
        }
        source += 1;
    }
    return NULL;
}

void a1( void )
{
    const char *source = "ABCDEF";
    const char *chars1 = "XYZJURYQQQQ";
    const char *chars2 = "XRCQEF";

    printf( "source = %s\n", source );
    printf( "chars1 = %s\n", chars1 );
    printf( "chars2 = %s\n", chars2 );
    printf( "find result 1 : %s\n",  find_char( source, chars1 ) ? "SUCCESS" : "FAILURE" );
    printf( "find result 2 : %s\n", find_char( source, chars2 ) ? "SUCCESS" : "FAILURE" );
}

