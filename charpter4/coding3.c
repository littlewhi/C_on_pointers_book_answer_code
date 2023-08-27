#include "a.h"

#define IS_TRIANGLE( x, y, z ) \
    ( (x) + (y) > (z) )

void swap( double *x, double *y )
{
    double tmp = *x;
    *x = *y;
    *y = tmp;
}

void a3( void )
{
    double a, b, c;
    double max, min, mid;

    printf( "请输入第一条边长度：\n" );
    scanf( "%lf", &a );
    printf( "请输入第二条边长度：\n" );
    scanf( "%lf", &b );
    printf( "请输入第三条边长度：\n" );
    scanf( "%lf", &c );

    if( a < 0 || b < 0 || c < 0 )
    {
        printf( "Invalid data\n" );
        return;
    }

    /* 排序， a>b>c */
    if( a < b )
        swap( &a, &b );
    if( a < c )
        swap( &a, &c );
    if( b < c)
        swap( &b, &c );

    if( !( IS_TRIANGLE( c, b, a ) ) )
    {
        printf( "It is not a triangle.\n" );
        return;
    }

    if( a == c )        /* 最长边与最短边相等，一定是正三角 */
    {
        printf( "It is a right triangle.\n" );
    }
    else if( b == c )   /* 两个短边相等，等腰 */
    {
        printf( "It is an isosceles triangle.\n" );
    }
    else
    {
        printf( "It is a normal triangle.\n" );
    }
}