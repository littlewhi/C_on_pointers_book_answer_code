#include "a.h"

linkNode *sll_reverse( linkNode *node )
{
    linkNode *head = NULL;
    if( node == NULL ) 
        return NULL;
    if( node->next == NULL )
        return node;
    head = sll_reverse( node->next );
    node->next->next = node;
    node->next = NULL;
    return head;
}

void a4( void )
{
    Llist list = return_a_LinkList();
    show_all_node( list );
    list->next = sll_reverse( list->next );
    printf( "After reversed list:\n" );
    show_all_node( list );
    destory_a_LList( list );
}
