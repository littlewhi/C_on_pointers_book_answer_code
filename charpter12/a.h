#ifndef _A_H_
#define _A_H_

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int item_type;
typedef struct linkNode {
    item_type item;
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

#endif
