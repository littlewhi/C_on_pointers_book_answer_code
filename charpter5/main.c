#include "a.h"

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
        case '3':
            a3();
            break;
        case '4':
            a4();
            break;
        case '5':
            a5();
            break;
        default:
            puts( "Unkonwn option" );
            break;
    }
}
