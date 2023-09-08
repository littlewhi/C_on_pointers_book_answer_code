#include "a.h"

#define LINKLIST_SIZE 16
#define LINKLIST_MAX_VALUE 100

Llist return_a_LinkList()
{
    linkNode *node_pre = NULL, *node_next = NULL;
    linkNode *ret = NULL;
    ret = node_pre = (linkNode *) calloc( 1, sizeof( linkNode ) );

    if( ret == NULL )
        return NULL;
    
    srand( time( NULL ) );
    
    for( int i = 0; i < LINKLIST_SIZE; ++i )
    {
        node_next = (linkNode *) calloc( 1, sizeof( linkNode ) );
        if( node_next == NULL )
            return ret;

        node_next->item = rand() % LINKLIST_MAX_VALUE;
        node_pre->next = node_next;
        node_pre = node_next;
    }

    return ret;
}

void destory_a_LList( Llist list )
{
    linkNode *node = NULL;

    while( list )
    {
        node = list->next;
        free( list );
        list = node;
    }
}

void show_all_node( Llist list )
{
    if( list == NULL )
        return;

    list = list->next;
    while( list )
    {
        printf("%d\n", list->item );
        fflush( stdout );
        list = list->next;
    }
}