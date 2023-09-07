#include "a.h"

linkNode *Llist_find_value( Llist list, item_type item, int( *comp )( item_type, item_type) )
{
    if( list == NULL ) 
        return NULL;
    
    list = list->next;
    while( list )
    {
        if( comp( list->item, item ) == 0 )
            return list;
        list = list->next;
    }
    return NULL;
}

int comp( item_type a, item_type b )
{
    return memcmp( &a, &b, sizeof( item_type ) );
}

void a2( void )
{
    item_type item;
    linkNode *node = NULL;
    Llist list = NULL;

    printf( "Please enter you want to find value in list\n" );
    scanf( "%d", &item );

    list = return_a_LinkList();
    node = Llist_find_value( list, item, comp );
    printf( "%s\n", node ? "find it" : "find nothing" );
    show_all_node( list );
    destory_a_LList( list );
}
