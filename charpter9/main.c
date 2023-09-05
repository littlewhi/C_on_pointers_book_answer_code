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
		case '7':
			a7();
			break;
		case '8':
			a8();
			break;
		case '9':
			a9();
			break;
		case '10':
			a10();
			break;
		case '11':
			a11();
			break;
		case '12':
			a12();
			break;
		case '13':
			a13();
			break;
		case '14':
			a14();
			break;
		case '15':
			a15();
			break;
		case '16':
			a16();
			break;
		case '17':
			a17();
			break;
		default:
			puts( "Unkonw options" );
			break;
	}
}
