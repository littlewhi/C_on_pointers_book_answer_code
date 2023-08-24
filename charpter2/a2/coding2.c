#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SHOW_RESULT(vst) puts( vst ? "Not couple" : "Coupled" )

/* 注释正常结束返回0， 读出错返回1 */
int deal_comments( int fd )
{
    char buf[4] = "";
    while( read( fd, buf, 2 ) == 2 )
    {
        if( strcmp( buf, "*/") )
            return 0;
    }
    return 1;
}

int main( int argc, char **argv )
{
    int fd;
    int vst = 0;
    char buf[4];

    if( argc != 2 )
    {
        printf( "Usage: %s <filename>\n", argv[0] );
        return -1;
    }

    fd = open( argv[1], O_RDONLY );
    if( fd < 0 )
    {
        fprintf( stderr, "Eerror opening %s\n", argv[1] );
        return -1;
    }

    while( read( fd, buf, 1) == 1 )
    {
        if( buf[0] == '{' )
        {
            --vst;
        }
        else if( buf[0] == '}' )
        {
            ++vst;
        }
        else if( buf[0] == '/')
        {
            /* 读空 */
            if( read( fd, buf, 1 ) != 1 )
            {
                break;
            }
            /* 注释 */
            if( buf[0] == '*' )
            {
                if( deal_comments( fd ) )
                {
                    break;
                }
            }
        }
    }

    SHOW_RESULT(vst);
    close( fd );

}