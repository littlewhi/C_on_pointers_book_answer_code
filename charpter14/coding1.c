#include "a.h"

void print_ledger_long( int i )
{  
    puts( "print_ledger_long" );
}

void print_ledger_detailed( int i )
{
    puts( "print_ledger_detailed" );
}

void print_ledger_default( int i )
{
    puts( "print_ledger_default" );
}

void print_ledger( int i )
{
#ifdef OPTION_LONG
    print_ledger_long( i );
#elif  defined( OPTION_DETAILED )
    print_ledger_detailed( i );
#else
    print_ledger_default( i );
#endif
}

void a1( void )
{
    print_ledger( 0 );
}
