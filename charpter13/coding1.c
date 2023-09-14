#include "a.h"
#include <ctype.h>

#define NUM_TO_COUNT 7

static int cnt_of_all_chars;
static int cnt_of_char[NUM_TO_COUNT];

int isnonprint( int c ) { return !isprint(c); }
typedef int( *func1 )( int );
static func1 check_func[] = {
    iscntrl,    isblank,    isdigit,
    islower,    isupper,    ispunct,
    isnonprint
};
/*
 * control - 0
 * blank - 1
 * number - 2
 * lower alpha - 3
 * upper alpha - 4
 * punctuation - 5
 * nonprintable - 6
 */

void porportation_of_char( void )
{
    int ch, i;
    while( ( ch = getchar() ) != EOF )
    {
        cnt_of_all_chars += 1;
        for( i = 0; i < NUM_TO_COUNT; i++ )
        {
            if( check_func[i]( ch ) )
                cnt_of_char[i] += 1;
        }
    }

    for( i = 0; i < NUM_TO_COUNT; i++ )
    {
        printf("\n%.4lf", cnt_of_char[i] * 1. / cnt_of_all_chars );
    }
    puts( "" );
}

void a1( void )
{
    porportation_of_char();
}
