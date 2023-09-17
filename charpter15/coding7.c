#include "a.h"

int read_line( FILE *in, int *ages, int len, int *cnt, int *sum )
{
    char line[128];
    char *ptr = NULL;
    int lsum = 0, lcnt = 0;

    if( fgets( line, sizeof( line ), in ) )
    {
        for( ptr = strtok( line, " " ); ptr; ptr = strtok( NULL, " " ) )
        {
            ages[ lcnt ] = atoi( ptr );
            lsum += ages[ lcnt++ ];
        }  
        *cnt = lcnt;
        *sum = lsum;
        return 1;
    }
    return 0;
}

void read_age( const char *filename )
{
#define LEN 10
    FILE *fr = NULL;
    int ages[LEN], cnt = 0, sum = 0, i; 

    fr = fopen( filename, "r" );
    if( fr == NULL )
    {
        fprintf( stderr, "ERROR: Could not open %s for reading", filename );
        return;
    }

    while( read_line( fr, ages, LEN, &cnt, &sum ) )
    {
        printf( "%5.2f: ", sum * 1.0 / cnt );
        for( i = 0; i < cnt; i++ )
        {
            printf( "%d ", ages[i] );
        }
        printf( "\n" );
        fflush( stdout );
        sum = cnt = 0;
    }
    fclose( fr );
}

void a7( void )
{
    char filename[128] = "";
    printf( "Please enter your filename:\n" );
    scanf( "%s", filename );
    read_age( filename );
}
