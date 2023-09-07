#include "a.h"

void *my_calloc(unsigned int num, unsigned int size_of_unit)
{
    void *ret_ptr = NULL;
    int i, j;
    if( num * size_of_unit == 0 )
        return NULL;
    
    ret_ptr = malloc( num * size_of_unit );
    if( ret_ptr == NULL )
        return NULL;

    /* memset( ret_ptr, 0, num*size_of_ptr ); */
    for( i = 0; i < num; i++ )
    {
        for( j = 0; j < size_of_unit; j++ )
        {
            *(char *)ret_ptr = 0;
        }
    }
    return ret_ptr;
}

void a1( void )
{
    int num, *ptr = NULL, i;
    printf( "Please enter a number for the memory allocation\n" );
    scanf( "%d", &num );

    ptr = (int *)my_calloc( num, sizeof( int ) );
    for( i = 0; i < num; i++ )
        printf("array[%d] = %d\n", i, num );

    free(ptr);
}
