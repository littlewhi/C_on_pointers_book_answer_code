#include "a.h"

/* entry main */
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
#if 0
    4 and 5，I make all index is link to an odd number rather than 
all normal numbers being larger than 2. 
    The link between index and odd number is as follows.
    index 0 -> 3, index 1 -> 5,
    index 2 -> 7, index 3 -> 9, ...
    so : 
    index i -> (i * 2 + 3)
#endif
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
