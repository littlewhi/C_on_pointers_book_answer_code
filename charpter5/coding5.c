#include <stdio.h>

int fill_bit( int num )
{
    int i, ret = 1;

    if( num == 0 )
        return 0;

    for( i = 1; i < num; i++ )
    {
        ret <<= 1;
        ret |= 1;
    }
    return ret;
}

int store_bit_field( int original_value, int value_to_store, unsigned int starting_bit, unsigned int ending_bit )
{
    int mask1 = fill_bit( starting_bit + 1 ) - fill_bit( ending_bit );
    int mask2 = fill_bit( starting_bit - ending_bit + 1 );

    original_value &= ~mask1;    /* 将要被放置数据的位置零 */
    value_to_store &= mask2;     /* 留下要被放置的数据位的数据 */
    original_value |= value_to_store << ending_bit; /* 置位 */

    return original_value; 
}

int main( void )
{
    printf( "%x\n", store_bit_field( 0xffff, 0x123, 13, 9 ) );

    return 0;
}