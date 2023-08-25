#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* answer1 code */
int match_char( const char ch, const char *chars )
{
    while( *chars )
    {
        if( ch == *chars++ )
            return 1;
    }

    return 0;
}

char *find_char( const char *source, const char *chars )
{
    if( source == NULL || chars == NULL )
        return NULL;

    while( *source )
    {
        if( match_char( *source, chars ) )
        {
            return (char *) source;
        }
        source += 1;
    }
    return NULL;
}

void a1( void )
{
    const char *source = "ABCDEF";
    const char *chars1 = "XYZJURYQQQQ";
    const char *chars2 = "XRCQEF";

    printf( "source = %s\n", source );
    printf( "chars1 = %s\n", chars1 );
    printf( "chars2 = %s\n", chars2 );
    printf( "find result 1 : %s\n",  find_char( source, chars1 ) ? "SUCCESS" : "FAILURE" );
    printf( "find result 2 : %s\n", find_char( source, chars2 ) ? "SUCCESS" : "FAILURE" );
}


/* answer2 code */
void get_next_array( const char *str, int next[] )
{
    int i, j;
    next[0] = -1;
    i = 0, j = -1;
    
    while( *( str + i ) )
    {
        if( j == -1 || *( str + j ) == *( str + i ) )
        {
            i += 1;
            j += 1;
            *( next + i ) = *( str + i ) == *( str + j ) ? *( next + j ) : j;
        }
        else
        {
            j = next[j];
        }
    }
}

char *find_substr( const char *str, const char *substr )
{
    int i = 0;
    int len = strlen( substr );
    int *next = (int *) malloc( len );
    
    get_next_array( substr, next );
    while( *str )
    {
        if( i == -1 )
        {
            i = 0, ++str;
        }
        else if( *str == *( substr + i ))
        {    
            ++str, ++i; 
            if( *(substr + i) == '\0' )
                return (char *) str - i;
        }
        else
        {    
            i = *( next + i );
        }
    }    
    return NULL;
}

int del_substr( char *str, const char *substr )
{
    char *pos_of_substr = NULL, *pos_after_substr = NULL;
    int len = strlen(substr);

    if( str == NULL || substr == NULL )
        return 0;
    /* 空字符串 */
    if( *substr == '\0' )
        return 1;

    /* use KMP to get substring position */
    if( ( pos_of_substr = find_substr( str, substr ) ) == NULL )
    {
        return 0;
    }

    pos_after_substr = pos_of_substr + len;
    while( *pos_after_substr != '\0' )
    {
        *pos_of_substr++ = *pos_after_substr++;
    }

    *pos_of_substr = '\0';    
    return 1;
}

void a2( void )
{
    char str[] = "ABCDEFG";
    const char *substr1 = "FGH", 
        *substr2 = "CDF", 
        *substr3 = "XABC",
        *substr4 = "CDE";
#if defined( _MY_ )
    char str_my[] = "abcabcabcddefej";
    char substr_my[] = "cddef";
    printf( "str = %s\nsubstr = %s\nfind result: %s\n", str_my, substr_my, find_substr( str_my, substr_my ) );
#endif

    printf( "str = %s\n", str );
    printf( "substr = %s, result : %d, str->%s\n", substr1, del_substr( str, substr1 ), str );
    printf( "substr = %s, result : %d, str->%s\n", substr2, del_substr( str, substr2 ), str );
    printf( "substr = %s, result : %d, str->%s\n", substr3, del_substr( str, substr3 ), str );
    printf( "substr = %s, result : %d, str->%s\n", substr4, del_substr( str, substr4 ), str );
}

/* answer3 code */
void swap( char *a, char *b )
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_string( char *string )
{
    char *tail = string + strlen( string ) - 1;
    while( string < tail )
        swap( string++, tail-- );
}

void a3( void )
{
    char str[] = "abcdef";
    printf( "str = %s\n", str );
    reverse_string( str );
    printf( "reversed string = %s\n", str );
}

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
    int result[1000] = { 0 };
    int *pos = result;
    int limit = 11;
#ifdef LIMIT_FOR_PRIME
    limit = LIMIT_FOR_PRIME;
#endif
    if( limit > 1000 )
    {
        printf( "limit is too large\n" );
        return;
    }
    printf( "limit =  %d\n", limit );
    
    Eratosthenes_prime( result, limit );
    while( *pos )
    {
        printf( "%d ", *pos++ );
    }
    puts("");
}


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
    int result[1000] = { 0 };
    int *pos = result;
    int limit = 11;
#ifdef LIMIT_FOR_PRIME
    limit = LIMIT_FOR_PRIME;
#endif 
    if( limit > 1000 )
    {
        printf( "limit is too large\n" );
        return;
    }
    printf( "limit =  %d\n", limit );
    
    Eratosthenes_prime_bit( result, limit );
    while( *pos )
    {
        printf( "%d ", *pos++ );
    }
    puts("");
}

/* entry main */
int main( int argc, char **argv )
{
    if( argc != 2 )
    {
        printf( "Usage: %s <OPTION>\n", argv[0] );
        printf( "OPTION: 1(coding1), 2(coding2), 3...\n" );
        printf( "Example: %s 1 \n", argv[0] );
        return -1;
    }
    
    switch( argv[1][0] )
    {
        case '1':
            a1();
            break;
        case '2':
            a2();
            break;
        case '3':
            a3();
            break;
#if 0
    4 and 5，I make all index is link to an odd number rather than 
all normal numbers being larger than 2. 
    The link between index and odd number is as follows.
    index 0 -> 3, index 1 -> 5,
    index 2 -> 7, index 3 -> 9, ...
    so : 
    index i -> (i * 2 + 3)
#endif
        case '4':
            a4();
            break;
        case '5':
            a5();
            break;
        default:
            puts( "Unkonwn option" );
            break;
    }
}
