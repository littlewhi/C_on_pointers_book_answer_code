#include "a.h"

static int identity_matrix( int *m, size_t size)
{
    int i, j, line;
    /* check if it is square */
    line = sqrt( size );
    if( line * line != size )
        return 0;

    for( i = 0; i < line; i++ )
    {
        for( j = 0; j < line; j++ )
        {
            if( i == j && m[i * line + j] != 1 ||
                i != j && m[i * line + j] != 0 )
                return 0;
        }
    }
    return 1;   
}

static void print_matrix( const int *mat, int line )
{   
    int i, j;
    for( i = 0; i < line; i++ )
    {
        for( j = 0; j < line; j++ )
            printf( "%+-3d ", mat[i * line + j] );

        printf( "\n" ); 
    }
}

void a4( void )
{
    int m1[3][3] = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1,
    };
    int m2[3][3] = {
        +1, 0, 1,
        -1, 0, 3,
        +0, 0, 1,
    };
    char *result[] = {
        "It is not a identity matrix",
        "It is a identity matrix",
    };

    print_matrix( m1[0], 3 );
    printf( "%s\n", result[identity_matrix( m1[0], 9 )] );
    print_matrix( m2[0], 3 );
    printf( "%s\n", result[identity_matrix( m2[0], 9 )] );
}