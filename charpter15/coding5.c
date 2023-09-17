#include "a.h"

static int do_copy( FILE *src, FILE *dst )
{
    char line[128];
    int same_line = 0, special_line = 0;
    int len;
    if( !src || !dst )
        return 0;
    while( fgets( line, sizeof( line ), src ) )
    {
        len = strlen( line );
        if( same_line == 0 )
        {
            if( isdigit( line[0] ) )
            {
                special_line = 1;
            }
            if( line[len - 1] != '\n' )
            {
                same_line = 1;
            }
        }

        if( special_line )
            fprintf( dst, "%s", line );

        if( line[len - 1] == '\n' )
        {
            same_line = 0;
            special_line = 0;
        }

        
    }
    return 1;
}

static void copy_from_in_to_out_file( void )
{
    char in_file_name[128], out_file_name[128];
    FILE *in_file = NULL, *out_file = NULL;
    
    printf( "Please enter the file name which will be copied(length <= 127): \n" );
    if( !fgets( in_file_name, sizeof( in_file_name), stdin ) )
    {
        puts( "I do not get name.\nexit..." );
        return;
    }
    printf( "Please enter the file name which will be used to store the last file:\n" );
    if( !fgets( out_file_name, sizeof( out_file_name), stdin ) )
    {
        puts( "I do not get name.\nexit..." );
        return;
    }
    /* 去掉换行符 */
    in_file_name[strlen( in_file_name ) - 1] = 0;
    out_file_name[strlen( out_file_name ) - 1] = 0;

    in_file = fopen( in_file_name, "r" );
    out_file = fopen( out_file_name, "a" );
    if( !in_file || !out_file )
    {
        printf( "Could not open file: %s\n", strerror( errno ) );
        printf( "exit...\n" );
        if( in_file )
            fclose( in_file );
        if( out_file )
            fclose( out_file );
        return;
    }

    if( !do_copy( in_file, out_file ) )
    {
        printf( "I can not copy completely the file.\n" );
    }

    printf( "COPY SUCCESSFULLY\n" );
    fclose( in_file );
    fclose( out_file );
}

void a5( void )
{
    copy_from_in_to_out_file();
}
