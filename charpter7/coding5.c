#include "a.h"

/* 
 * va_start(va_list ap, last) : iniiialize the list
 * va_arg(va_list ap, type ) : get the argument in order one by one
 * va_end(va_list ap) : destroy the list
 */

int print_integer( int val )
{
    return printf("%d", val);
}

int print_float( double val )
{
    return printf("%lf", val);
}

int print_string( const char *str )
{
    int i = 0;

    while( *str != 0)
    {
        ++i;
        putchar( *str++ );
    }
    return i;
}

int myprintf( const char *format, ...)
{
    va_list ap;
    int i, len = strlen(format), cnt = 0;

    /* 初始化可变列表 */
    va_start(ap, format);

    for( i = 0; i < len; i++ )
    {
        char c = format[i];
        
        /* 是%开头的，长度允许 */
        if( c == '%' && i + 1 < len)
        {
            switch ( format[i + 1] )
            {
                case 'd':
                    cnt += print_integer( va_arg( ap, int ) );
                    ++i;
                    continue;
                case 'f':
                    cnt += print_float( va_arg( ap, double ) );
                    ++i;
                    continue;
                case 'c':
                    putchar( va_arg( ap, int ) );
                    ++cnt;
                    ++i;
                    continue;
                case 's':
                    cnt += print_string( va_arg( ap, const char* ) );
                    ++i;
                    continue;
                default:
                    /* nothing to do, 
                     * just to run bellow code 
                     */
                    ;
            }
        }

        /* 非格式化字符直接打印 */
        putchar( c );
        cnt++;
    }

    va_end( ap );
    return cnt;
}

void a5( void )
{
    int cnt1, cnt2;
    cnt1 = printf( "I am a %s %d %f %c\n", "bigman", 100, 3.14, 'a' );
    cnt2 = myprintf( "I am a %s %d %f %c\n", "bigman", 100, 3.14, 'a' );

    if(cnt1 == cnt2)
    {
        puts( "OK" );
    }
    else
    {
        printf( "cnt1 = %d, cnt2 = %d\n", cnt1, cnt2 );
    }
}