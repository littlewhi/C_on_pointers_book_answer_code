#include "a.h"

linkNode *dll_find_head( linkNode *ptr )
{
    if( ptr == NULL )
        return NULL;
    while( ptr->pre )
        ptr = ptr->pre;
    return ptr;
}

linkNode *dll_find_tail( linkNode *ptr )
{
    if( ptr == NULL )
        return NULL;
    while( ptr->next )
        ptr = ptr->next;
    return ptr;
}

linkNode *dll_insert( linkNode *head, linkNode *tail, item_type item )
{
    linkNode *traversal_h = head;
    linkNode *insert_position_h = NULL, *insert_position_t = NULL;
    linkNode *new_node = NULL;
    
    /* 
     * 查看链表中是否存在item,
     * 并查找插入位置。
     */
    for( ; traversal_h; traversal_h = traversal_h->next )
    {
        if( traversal_h->item == item )
            return traversal_h;
        if( traversal_h->item > item )
            break;
    }

    insert_position_t = traversal_h;
    insert_position_h = traversal_h ? traversal_h->pre : tail;

    new_node = (linkNode *) malloc( sizeof( linkNode ) );
    new_node->item = item;
    
    new_node->next = insert_position_t;
    new_node->pre = insert_position_h;
    if( insert_position_h )
    {
        insert_position_h->next = new_node;
    }
    if( insert_position_t )
    {
        insert_position_t->pre = new_node;
    }
    return new_node;
}

Llist dll_return_a_LinkList( void )
{
    linkNode * tail = NULL, *node = NULL, *list = NULL;
    int a[] = { 0, 1, 2, 3, -1, 4, 6, 5 };
    for( int i = 0; i < sizeof( a ) / sizeof( a[0] ); i++ )
    {
        node = dll_insert( list, tail, a[i] );
        list = dll_find_head( node );
        tail = dll_find_tail( node );
    }
    return list;
}

void a3( void )
{
    linkNode * tail = NULL, *node = NULL, temp;
    Llist list = NULL;

    list = dll_return_a_LinkList();
    temp.next = dll_find_head( list );
    show_all_node( &temp );
    destory_a_LList( list );
}
