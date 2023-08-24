#include <stdio.h>
#include <ctype.h>

/* answer1 code */
void a1( void )
{
    int ch;
    while( ( ch = getchar() ) != EOF )
    {
        putchar( tolower( ch ) );
    }
}

/* answer2 code */
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


int main( int argc, char **argv )
{
    if( argc != 2 )
    {
        printf( "Usage: %s <OPTION>\n", argv[0] );
        printf( "OPTION: 1(coding1), 2(coding2), 3...\n" );
        printf( "Example: %s 1 \n", argv[0] );
        return -1;
    }
    
    switch( argv[1][0] )
    {
        case '1':
            a1();
            break;
        case '2':
            a2();
            break;
        default:
            puts( "Unkonwn option" );
            break;
    }
}
