#include <stdio.h>

typedef char * va_list_;
#define va_start_( va, param ) ( (va) = ( (va_list_) &( param ) ) + sizeof( param ) )
#define va_end_( va ) ( (va) = NULL )
#define va_next_( va, type ) ( *( (type *) va++ ) )

int func_ret_int( int a, int b, int c );
void call_printf();
void use_va( int last, ... )
{
    va_list_ list;
    va_start_( list , last );
    int a = va_next_( list, int );
    printf( "%d\n", a );
}

int main( void )
{
    int x, y, z, d;
    int c = func_ret_int( 1, 2, 3 );   
    printf( "%d\n", c ); 
    x = 0;
    y = 1;
    z =2;
    d = 3;
    printf( "%d %d %d %d %d\n", x, y, z, d, 33 );
    call_printf();
    use_va( 1, 2 ); 
    return 0;
}
