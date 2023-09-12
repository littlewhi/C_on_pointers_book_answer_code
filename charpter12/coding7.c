#include "a.h"

typedef struct word_node {
    char *word;
    struct word_node *next;
}word_node;

typedef struct index_list_node {
    char alphabet;
    struct index_list_node *next;
    word_node *head;
} *ilist, ilist_node;

static void destroy_index_list( ilist list )
{
    ;
} 

/*
 * 二级链表有一个头指针
 */
static ilist create_index_list( void )
{
    ilist_node *pre = NULL, *node = NULL, *ret = NULL;
    word_node *str_node = NULL;
    int i;

    pre = (ilist_node *) malloc( sizeof(ilist_node) );
    str_node = (word_node *) malloc( sizeof(word_node) );
    if( pre == NULL || str_node == NULL )
        return NULL;
    str_node->next = NULL;
    pre->alphabet = 'a';
    pre->head = str_node;
    pre->next = NULL;
    ret = pre;

    for( i = 'b'; i <= 'z'; ++i )
    {
        node = (ilist_node *) malloc( sizeof(ilist_node) );
        str_node = (word_node *) malloc( sizeof(word_node) );
        if( node == NULL || str_node == NULL )
        {
            destroy_index_list( ret );
            return NULL;
        }

        str_node->next = NULL;
        node->alphabet = i;
        node->head = str_node;
        node->next = NULL;
        pre->next = node;
        pre = node;
    }

    return ret;
}

static ilist_node *find_fit_alpha( ilist list, const char ch )
{
    while( list )
    {
        if( list->alphabet == ch )
            return list;
        list = list->next;
    }
    return NULL;
}

static int check_word( const char *word )
{
    if( word == NULL )
        return 0;
    return isalpha( word[0] );
}

static int insert_index_list( ilist *list, const char *word )
{
    ilist_node *alpha_node = NULL;
    word_node *node_for_match = NULL, *pre = NULL;
    word_node *new_node = NULL;
    int result_of_comp;

    if( list == NULL || *list == NULL )
        return -1;
    if( check_word( word ) == 0 )
        return -1; 

    alpha_node = find_fit_alpha( *list, word[0] );
    node_for_match = alpha_node->head;

    while( node_for_match->next )
    {
        result_of_comp = strcmp( word, node_for_match->next->word );
        if( result_of_comp == 0 )
            return 0;
        if( result_of_comp > 0 )
            break;

        node_for_match = node_for_match->next;
    }

    new_node = ( word_node *) malloc( sizeof( word_node ) );
    new_node->word = (char *) malloc( strlen( word) + 1 );
    if( new_node == NULL || new_node->word == NULL )
        return -1;

    strcpy( new_node->word, word );
    new_node->next = node_for_match->next;
    node_for_match->next = new_node;
    return 1;
}

static void show_ilist( ilist list )
{
    word_node *node = NULL;
    while( list )
    {
        node = list->head->next;
        printf("%c:\n", list->alphabet );

        while( node )
        {
            printf("%s\n", node->word );
            node = node->next;
        }
        list = list->next;
    }
}

void a7( void )
{
    ilist list = create_index_list();
    
    insert_index_list( &list, "banana" );
    insert_index_list( &list, "apple" );
    insert_index_list( &list, "orange" );
    insert_index_list( &list, "bush" );
    
    show_ilist( list );
    
    destroy_index_list( list );
}
