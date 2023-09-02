#include "a.h"
#include <ctype.h>

struct chs{
    int control_char;
    int blank_char;
    int digit_char;
    int lower_char;
    int upper_char;
    int punctuation_char;
    int unprintable_char;
};

void print_percent( struct chs *chs, int cnt )
{
    printf( "control_char: %lf%%\n", chs->control_char * 100. / cnt );
    printf( "blank_char: %lf%%\n", chs->blank_char * 100. / cnt );
    printf( "digit_char: %lf%%\n", chs->digit_char * 100. / cnt );
    printf( "lower_char: %lf%%\n", chs->lower_char * 100. / cnt );
    printf( "upper_char: %lf%%\n", chs->upper_char * 100. / cnt );
    printf( "punctuation: %lf%%\n", chs->punctuation_char * 100. / cnt );
    printf( "unprintable: %lf%%\n", chs->unprintable_char * 100. / cnt );
}

void count_char_percent( struct chs *chs )
{
    int ch;
    int cnt = 0;
    while( ( ch = getchar() ) != EOF )
    {
        ++cnt;
        if( iscntrl( ch ) )
            chs->control_char++;
        if( isblank( ch ) )
            chs->blank_char++;
        if( isdigit( ch ) )
            chs->digit_char++;
        if( islower( ch ) )
            chs->lower_char++;
        if( isupper( ch ) )
            chs->upper_char++;
        if( ispunct( ch ) )
            chs->punctuation_char++;
        if( !isprint( ch ) )
            chs->punctuation_char++;
    }

    print_percent( chs, cnt );
}

void a1( void )
{
    struct chs *chs = (struct chs *) calloc( 1, sizeof( struct chs ) );
    count_char_percent( chs );
    free( chs );
}