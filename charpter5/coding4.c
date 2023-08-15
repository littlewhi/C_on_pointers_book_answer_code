
/* 
 * set the bit on bit_number to one
 */
void set_bit( char bit_array[], unsigned int bit_number )
{
    bit_array[bit_number] = 1;
}

/*
 * set the bit on bit_number to zero
 */
void clear_bit( char bit_array[], unsigned int bit_number )
{
    bit_array[bit_number] = 0;
}

/*
 *  set the bit on bit_number to value
 */
void assign_bit( char bit_array[], unsigned int bit_number, int value )
{
    bit_array[bit_number] = value ? 1 : 0;
}

/*
 * return zero if the bit on bit_number is 0, otherwise return 1.
 */
int test_bit( char bit_array[], unsigned int bit_number )
{
    return bit_array[bit_number] ? 1 : 0;
}

#define ARRAY_SIZE 32

int main( void )
{
    char ba[ARRAY_SIZE];
    
    return 0;
}