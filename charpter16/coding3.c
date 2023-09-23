#include "a.h"

void show_time( void )
{
    time_t t = time( NULL );
    struct tm *local_time = localtime( &t );

    printf( "秒针：%d\n", local_time->tm_sec );
    printf( "分针 %d\n", local_time->tm_min );
    printf( "时针：%d\n", local_time->tm_hour );
}

void a3( void )
{
    show_time();
}
