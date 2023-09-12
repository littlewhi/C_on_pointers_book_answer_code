#include "a.h"

int dll_remove( linkNode **rootp, linkNode *node )
{
    if( rootp == NULL || *rootp == NULL || node == NULL )
        return -1;
        
    while( (*rootp)->next && (*rootp)->next != node )
        (*rootp) = (*rootp)->next;

    if( (*rootp)->next == NULL )
        return 0;

    (*rootp)->next = node->next;
    if( node->next )
        node->next->pre = *rootp;
    free( node );
    return 1;
}

static int cmp( item_type a, item_type b )
{
    return a == b ? 0 : 1;
}

void a6( void )
{
    item_type num;
    linkNode *list = (linkNode *) malloc( sizeof(linkNode) );
    Llist head = list;
    if( list == NULL )
        return;

    list->next = dll_return_a_LinkList();
    show_all_node( list );
    
    printf( "Please enter a number to remove from the list\n" );
    scanf( "%d", &num );
    if( dll_remove( &list, Llist_find_value( list, num, cmp ) ) )
        printf( "removed : \n" );
    show_all_node( head );
    destory_a_LList( head );
}
