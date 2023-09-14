#include "a.h"

typedef struct linkNode {
    int item;
    struct linkNode *next;
} *Llist, linkNode;

typedef void( *deal_func_t )( linkNode *);

void traverse_list( Llist list, deal_func_t deal )
{
    if( list == NULL )
        return;

    linkNode *head = list->next;
    while( head )
    {
        deal( head );
    }

}

void a2( void )
{

}
