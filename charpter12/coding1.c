#include "a.h"

int count_nodes( Llist list )
{
    int cnt = 0;
    while( list )
    {
        cnt += 1;
        list = list->next;
    }
    return cnt;
}

void a1( void )
{
    Llist list = return_a_LinkList(); 
    if( list == NULL )
    {
        printf( "getting a LinkList fails\n" );
        return;
    }

    printf( "The count of nodes in the list is %d\n", count_nodes( list->next ) );
    destory_a_LList( list );
}
