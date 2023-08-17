#include <stdarg.h>
#include <stdio.h>

int array_offset( int array_info[], ... )
{
    int dimension = array_info[0];
    int lows[11], highs[11];
    int i;
    va_list ap;
    int loc = 0;

    if( dimension > 10 )
        return -1;

    /* 存储每一维度的下标的上下限 */
    for( i = 1; i <= 2 * dimension; i += 2 )
    {
        lows[i / 2] = array_info[i];
        highs[i / 2] = array_info[i + 1];

        if( highs[i / 2] < lows[i / 2] )
            return -1;
    }

    /* 判断下标 */
    va_start(ap, array_info);
    for( i = 0; i < dimension; i++ )
    {
        int low = lows[i];
        int high = highs[i];
        int p = va_arg( ap, int );
        
        if( p < low || p > high )
            return -1;
            
        loc = loc * (high - low + 1) + p - low;
    }
    
    va_end( ap );
    return loc;
}

struct {
    int x, y, z;
}test[10] = {
    { 4, 1, -3 },
    { 4, 1, -2 },
    { 4, 1, 3 },
    { 4, 2, -3 },
    { 5, 1, -3 },
    { 6, 3, 1 },
};

int main( void )
{
    int array_info[] = { 3, 4, 6, 1, 5, -3, 3 };
    int i;
    for( i = 0; i < 6; ++i )
    {
        printf( "%d, %d, %d -> %d\n", test[i].x, test[i].y, test[i].z, 
            array_offset( array_info, test[i].x, test[i].y, test[i].z ) );
    }

    return 0;
}