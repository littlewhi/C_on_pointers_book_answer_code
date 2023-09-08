#include "a.h"

int sll_remove( linkNode **rootp, linkNode *node )
{
    if( rootp == NULL || *rootp == NULL )
        return -1;

    while( (*rootp)->next && (*rootp)->next != node )
        *rootp = (*rootp)->next;
    
    if( (*rootp)->next == NULL )
        return 0;
    
    (*rootp)->next = node->next;
    free( node );
    return 1;
}

int cmp( item_type a, item_type b )
{
    return a == b ? 0 : 1;
}

void a5( void )
{
    Llist list = return_a_LinkList();
    Llist head = list;
    linkNode *node = NULL;
    item_type item;
    show_all_node( list );
    printf( "Please enter a number you want to delete\n" );
    node = Llist_find_value( list, item, cmp );
    if( sll_remove( &list, Llist_find_value( list, item, cmp ) ) == 1 )
    {
        printf( "This is the list dealt\n" );
        show_all_node( head );
    }
    destory_a_LList( head );
}
