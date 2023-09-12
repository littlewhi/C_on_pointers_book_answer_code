#ifndef _A_H_
#define _A_H_

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef int item_type;
typedef struct linkNode {
    item_type item;
    /* the member--pre is only used in functions whose names have a 'dll_' prefix */
    struct linkNode *pre;
    struct linkNode *next;
} linkNode, *Llist;

void a1( void );
void a2( void );
void a3( void );
void a4( void );
void a5( void );
void a6( void );
void a7( void );

Llist return_a_LinkList( void );
void destory_a_LList( Llist list );
void show_all_node( Llist list );
linkNode *dll_find_head( linkNode *ptr );
linkNode *dll_find_tail( linkNode *ptr );
linkNode *dll_insert( linkNode *head, linkNode *tail, item_type item );
Llist dll_return_a_LinkList( void );
linkNode *Llist_find_value( Llist list, item_type item, int( *comp )( item_type, item_type) );
#endif
