#include "a.h"

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
