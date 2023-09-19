#include "a.h"

static char buffer[512];

/*
 * 在fp文件中查找存在str的行，
 * 找到就返回ret指针，否则NULL
 * 如果fp是空指针
 * 就会继续在上一次传入的文件中，
 * 寻找str。
 */
static char *find_line( FILE *fp, const char *str, char *ret )
{
    static FILE *sfp;
    if( fp )
        sfp = fp;
    if( !sfp || !str || !ret )
        return NULL;

    while( fgets( ret, 512 * sizeof( char ), sfp ) )
    {
        if( strstr( ret, str ) )
            return ret;
    }

    return NULL;
}

/*
 * files的结尾用一个NULL标记
 */
static void my_fgrep( const char *dest_str, const char *files[] )
{
    FILE *fp = NULL;
    int line_number;
    char *res = NULL;

    for( ; files && *files; files++ )
    {
        if( !(fp = fopen( *files, "r" ) ) )
        {
            fprintf( stderr, "ERROR opening file %s : %s\n", *files, strerror( errno ) );
            return ;
        }

        for( res = find_line( fp, dest_str, buffer ); res ; res = find_line( NULL, dest_str, buffer ) )
            printf( "%s:%s", *files, buffer );
        
        fclose( fp );
    }    
}

void a9( void )
{
    const char *files[] = {
        "coding1.c", "coding2.c", "coding3.c",
        "coding4.c", "coding5.c", "coding6.c"
    };
    printf( "This is files:\n" );
    for( int i = 0; i < 6; ++i )
    {
        printf( "%s\n", files[i] );
    }
    printf( "This is results of fgrep \"void \" files\n" );
    my_fgrep( "void ", files );
}
