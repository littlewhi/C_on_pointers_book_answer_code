#include "a.h"

int array_offset( int array_info[], ... )
{
    int dimensions = array_info[0];
    int lows[11], highs[11], args[10];
    int i;
    va_list ap;
    int loc = 0;

    if( dimensions > 10 )
        return -1;

    /* 存储每一维度的下标的上下限 */
    for( i = 1; i <= 2 * dimensions; i += 2 )
    {
        lows[i / 2] = array_info[i];
        highs[i / 2] = array_info[i + 1];

        if( highs[i / 2] < lows[i / 2] )
            return -1;
    }

    /* 记录每一维度的下标 */
    va_start(ap, array_info);
    for( i = 0; i < dimensions; i++)
    {
        args[i] = va_arg( ap, int );
    }

    /* 判断下标 */
    loc = args[dimensions - 1] - lows[dimensions - 1];
    if( loc < 0 )
        return -1;

    for( i = dimensions - 2; i >= 0; --i )
    {
        int low = lows[i];
        int high = highs[i];
        int p = args[i];
        
        if( p < low || p > high )
            return -1;
            
        loc = loc * (high - low + 1) + p - low;
    }
    
    va_end( ap );
    return loc;
}

struct {
    int x, y, z;
}tests[10] = {
    { 4, 1, -3 },
    { 5, 1, -3 },
    { 6, 1, -3 },
    { 4, 2, -3 },
    { 4, 3, -3 },
    { 4, 1, -2 },
    { 4, 1, -1 },
    { 5, 3, -1 },
    { 6, 5, 3 },
};

void a7( void )
{
    int array_info[] = { 3, 4, 6, 1, 5, -3, 3 };
    int i;
    for( i = 0; i < 9; ++i )
    {
        printf( "%d, %d, %d -> %d\n", tests[i].x, tests[i].y, tests[i].z, 
            array_offset( array_info, tests[i].x, tests[i].y, tests[i].z ) );
    }

}