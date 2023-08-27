#include "a.h"

#define LINE 10

typedef int ( matrix_type ) [LINE][LINE];

static int identity_matrix( matrix_type m )
{
    int i, j;
    for( i = 0; i < LINE; i++ )
    {
        for( j = 0; j < LINE; j++ )
        {
            if( i == j && m[i][j] != 1 ||
                i != j && m[i][j] != 0 )
                return 0;
        }
    }
    return 1;
}

void a3( void )
{
    int i, j;
    matrix_type mat = {
        { 1, },
        { 23, 1 },
        { 0, 0, 1 },
        { 0, 0, 0, 1 },
        { 0, 0, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    };

    puts( "matrix as follow:" );
    for( i = 0; i < LINE; i++ )
    {
        for( j = 0; j <LINE; j++ )
            printf( "%-3d ", mat[i][j] );

        printf( "\n" );
    }  

    if( identity_matrix( mat ) )
        printf( "It is identity matrix\n" );
    else
       printf( "It is not identity matrix\n" ); 
}