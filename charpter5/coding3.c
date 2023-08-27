
#include "a.h"
#if 0
void setBit( unsigned int *val, int bit, int pos )
{
    if( bit != 0 )
    {
        *val |= (1 << pos);
    }
    else
    {
        *val &= ~(1 << pos);
    }
}

unsigned int reverse_bits( unsigned int value )
{
    int len = sizeof( unsigned int ) * 8;
    int i;
    unsigned int ret = value;

    for( i = 0; i < len; i++ )
    {
        setBit( &ret, value & ( 1 << i ) ? 1 : 0, len - i -1 );
        setBit( &ret, value & ( 1 << (len - i - 1) ) ? 1 : 0, i );
    }

    return ret;
}
#endif

/* answer */
unsigned int reverse_bits( unsigned int value )
{
    int ans = 0;
    int i;
    
    for( i = 1; i != 0; i <<= 1 )
    {
        ans <<= 1;
        if( value & 1 )
        {
            ans |= 1;
        }
        value >>= 1;
    }

    return ans;
}


void a3( void )
{
    printf( "%u\n ", reverse_bits( 25 ) );
}