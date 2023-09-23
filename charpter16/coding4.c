#include "a.h"

static const char *weekday_names[] = {
    "Sun", "Mon", "Tue", 
    "Wed", "Thu", "Fri", 
    "Sat"
};

static int check_weekday( int year, int month, int day )
{
    struct tm t = { 0 };

    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    t.tm_hour = 12;

    mktime( &t );
    return t.tm_wday;
}

void a4( void )
{
    int year, month, day;
    printf( "Please enter a year:\n" );
    scanf( "%d", &year );
    printf( "Please enter a month:\n" );
    scanf( "%d", &month );
    printf( "Please enter a day:\n" );
    scanf( "%d", &day );

    printf( "The weekday is %s.\n", weekday_names[check_weekday( year, month, day )] );
}
