#include "a.h"

typedef void( *fp )( void );
static const fp func_table[] = {
	NULL, a1, a2, 
	a3, a4, a5, 
	a6, a7, a8, 
	a9, a10, a11, 
	a12, a13, a14, 
	a15, a16, a17
};

static const int ft_size = sizeof( func_table ) / sizeof( func_table[0] );

int main( int argc, char **argv )
{
    int sw, size;
    if( argc != 2 )
    {
        printf( "Usage: %s <OPTION>\n", argv[0] );
        printf( "OPTION: 1(coding1), 2(coding2), 3...\n" );
        printf( "Example: %s 1 \n", argv[0] );
        return -1;
    }
    
    sw = atoi( argv[1] );
    if( sw <= 0 || sw >= ft_size )
        puts( "Unknown option" );
    
    func_table[sw]();
}
