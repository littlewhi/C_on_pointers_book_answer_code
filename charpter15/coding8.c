#include "a.h"

/*
 * Memory buffer for the line need to write in file. 
 */
static char buffer[64];
int file_to_dump( FILE *in, FILE *out )
{
    char buf[17];
    unsigned int offset_of_file = 0, len;
    int i, j, end = EOF;

    if( !in || !out )
        return 0;

    /* 
     * 为了防止最后一行为空行的问题，
     * 除了第一行外，其他的行的第一个字符都是换行符， 
     */
    j = 7;
    while( fgets( buf, sizeof( buf ), in ) )
    {
        /*
         * 处理内存缓冲区
         */
        len = strlen( buf );
        sprintf( buffer + (offset_of_file != 0 ), "%06X ", offset_of_file );
        
        for( i = 0; i < 16; ++i )
        {
            if(i % 4 == 0 )
                buffer[j++] = ' ';
            sprintf( buffer + j, "%02X", i < len ? buf[i] : '\0' );
            j += 2;
        }
        strcpy( buffer + j, "  *" );
        j += 3;

        for( i = 0; i < 16; ++i )
        {
            char ch = i < len ? buf[i] : '\0';
            buffer[j++] = isprint( ch ) ? ch : '.';
        }

        buffer[j++] = '*';

        /*
         * 最后的写入
         */
        if( fwrite( buffer, sizeof( char ), j, out ) != j )
        {
            fprintf( stderr, "Error writing" );
            return -1;
        }

        /*
         * 更新辅助变量，
         * 因为第一行与其他行不同，
         * 所以在循环尾部更新。
         */
        j = 8;
        offset_of_file += len;
        buffer[0] = '\n';
    }
    return 1;
}

void a8( void )
{
    char filename[64];
    FILE *in = NULL, *out = NULL;

    printf( "Please enter the filename you want to deal with.( Enter 0 for standard input stream)\n" );
    scanf( "%s", filename );
    if( strcmp( filename, "0" ) == 0 )
        in = stdin;
    else
        in = fopen( filename, "r" );
    if( !in )
    {
        fprintf( stderr, "Error opening %s\n", filename );
        return;
    }

    out = fopen( "out_for_test8", "w" );
    if( !out )
    {
        fprintf( stderr, "Error opening out_for_test8\n" );
        return;
    }

    file_to_dump( in, out );
}
