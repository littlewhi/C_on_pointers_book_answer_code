#include "a.h"
/* 
 * set the bit on bit_number to one
 */
void set_bit( char bit_array[], unsigned int bit_number )
{
    bit_array[bit_number / 8] |= ( 1 << ( bit_number % 8 ) );
}

/*
 * set the bit on bit_number to zero
 */
void clear_bit( char bit_array[], unsigned int bit_number )
{
    bit_array[bit_number / 8] &= ~( 1 << ( bit_number % 8 ) );
}

/*
 *  set the bit on bit_number to value
 */
void assign_bit( char bit_array[], unsigned int bit_number, int value )
{
    if( value )
        set_bit( bit_array, bit_number );
    else
        clear_bit( bit_array, bit_number );
}

/*
 * return zero if the bit on bit_number is 0, otherwise return 1.
 */
int test_bit( char bit_array[], unsigned int bit_number )
{
    return bit_array[bit_number / 8] & ( 1 << ( bit_number % 8 ) ) ? 1 : 0;
}


#define ARRAY_SIZE 32

void a4( void )
{
    char ba[ARRAY_SIZE];

}