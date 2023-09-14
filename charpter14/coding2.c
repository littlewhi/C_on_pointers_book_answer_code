#include "a.h"

cpu_type_t cpu_type( void )
{
    cpu_type_t t;
#if defined( VAX )
    t = CPU_VAX;
#elif defined( M68000 )
    t = CPU_M68000;
#elif defined( M68020 )
    t = CPU_M68020;
#elif defined( I80386 )
    t = CPU_80386;
#elif defined( X6809 )
    t = CPU_6809;
#elif defined( U3B2 )
    t = CPU_3B2;
#else
    t = CPU_UNKNOWN;
#endif
    return t;
}

void a2( void )
{
    printf( "%d\n", cpu_type() );
}
