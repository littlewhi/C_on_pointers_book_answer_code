#include "a.h"

/* answer4 code */
void discard( char *start, char *end, int step )
{
    while( start < end )
    {
        *start = 1;
        start += step;
    }
}

/*
 *  the content of some index in number pool if it is zero then is not discarded, otherwise it is discarded.
 */
void Eratosthenes_prime( int result[], int limit )
{
    char *num_pool = NULL, *pos_of_pool = NULL, *bottom_of_pool = NULL;
    int len, j, step;

    if( limit < 2 )
        return;
    result[0] = 2;
    if( limit == 2 )
        return;
    
    j = 1;                      /* the index of result array */
    len = ( limit + 1 ) / 2 - 1;
    num_pool = (char *) calloc( len, sizeof( char ) );
    bottom_of_pool = num_pool + len;
    
    /* 剔除数字 */
    for( pos_of_pool = num_pool; pos_of_pool < bottom_of_pool; pos_of_pool++ )
    {
        if( *pos_of_pool )
            continue;
        step = ( pos_of_pool - num_pool ) * 2 + 3;
        *( result + j++ ) = step;
        discard( pos_of_pool, bottom_of_pool, step );
    }
    free( num_pool );
}

void a4( void )
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
    
    Eratosthenes_prime( result, limit );
    while( *pos )
    {
        printf( "%d ", *pos++ );
    }
    puts("");
}
