#include "a.h" 

static void matrix_multiply( int *m1, int *m2, int *r, int x, int y, int z )
{
    int i, j, k;
    for( i = 0; i < x; ++i )
    {
        for( j = 0; j < z; ++j )
        {
            int v = 0;
            for( k = 0; k < y; ++k )
            {
                v += m1[i * y + k] * m2[k * z + j];
            }
            r[i * z + j] = v;
        }
    }
}

void a5( void )
{
    int m1[][2] = { 
        { 2, -6 },
        { 3, 5 },
        { 1, -1 },
    };
    int m2[][4] = {
        { 4, -2, -4, -5 },
        { -7, -3, 6, 7 },
    };
    int r[3][4];
    int i, j;
    matrix_multiply( m1[0], m2[0], r[0], 3, 2, 4 );
    for( i = 0; i < 3; i++ )
    {
        for( j = 0; j < 4; j++ )
        {
            printf( "%3d ", r[i][j] );
        }
        puts("");
    }
}