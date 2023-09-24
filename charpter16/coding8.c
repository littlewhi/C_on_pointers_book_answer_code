#include "a.h"

void calculate_average_age( FILE *file )
{
    char buf[1024];
    char *st = NULL, *en = NULL;
    int av_age, num, i;

    if( !file )
        return;
    
    i = 0;
    while( fgets( buf, sizeof( buf ), file ) )
    {
        num = av_age = 0;
        for( st = en = buf; *en; ++en )
        {
            if( !isdigit( *en ) )
            {
                ++num;
                av_age += strtol( st, &en, 0 );
                st = en + 1;
            }
        } 
        printf( "%d : %d\n", i++, av_age / num );
    }
}

void a8( void )
{
    char filename[1024];
    FILE *f;

    printf( "Please enter filename\n" );
    scanf( "%s", filename );

    f = fopen( filename, "r" );
    calculate_average_age( f );
    fclose( f );
}
