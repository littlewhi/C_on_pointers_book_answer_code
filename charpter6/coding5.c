#include "a.h"
/* answer5 code */
/* charpter 5 answer4 function code */
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

/*
 * use the bit_array
 */
void discard_bit( char bit_array[], int i, int len )
{
    int step = i * 2 + 3;
    while( i < len )
    {
        set_bit( bit_array, i );
        i += step;
    }
}

void Eratosthenes_prime_bit( int result[], int limit )
{
    char *num_pool = NULL; 
    int num_of_ch, i, j;
    if( limit < 2 )
        return;
    result[0] = 2;
    if( limit == 2 )
        return;
    
    j = 1;
    limit = ( limit + 1 ) / 2 - 1;
    num_of_ch = limit / 8 + ( limit % 8 ? 1 : 0 );
    num_pool = (char *) calloc( num_of_ch, sizeof( char ) );

    for( i = 0; i < limit; i++ )
    {
        if( test_bit( num_pool, i ) )
            continue;
        *( result + j++) = i * 2 + 3;
        discard_bit( num_pool, i, limit );
    }
    free( num_pool );
}

void a5( void )
{
#ifdef LIMIT_FOR_PRIME
    int result[LIMIT_FOR_PRIME] = { 0 };
    int limit = LIMIT_FOR_PRIME;
#else
    int result[1000] = { 0 };
    int limit = 11;
#endif
    int *pos = result;
    
    printf( "limit =  %d\n", limit );
    
    Eratosthenes_prime_bit( result, limit );
    while( *pos )
    {
        printf( "%d ", *pos++ );
    }
    puts("");
}
