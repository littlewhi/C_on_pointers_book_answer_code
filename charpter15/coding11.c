#include "a.h"
#include <limits.h>

typedef struct part_t{
    char desc[32];
    int cnt;
    double cost;
}part_t;

#define TYPE_NAME
    typedef double money_t;

/*
 * methods:
 * new description(<=20), quantity(>=0), cost-each(>=0):
 * * Create a new document about a kind of part.

 * buy part-number(>=1), quantity(>=0), cost-each(>=0)
 * * Add some more parts on part-number.

 * sell part-number(>=1), quantity(>=0), price-each(>=0)
 * * remove some parts and calculate profit and left value's sum.
 
 * delete part-number
 * * delete part document

 * print part-number
 * * print description, current quantity and sum value of the part of part-number.

 * print all
 * * print information in a table.

 * total
 * * calculate total sum of all parts' value.
 */
typedef struct storage_documents_t {

#define DATA
    part_t *parts;
    int num_parts;
    money_t *total_value_of_part;
    money_t total_value_of_parts;
    FILE *filep;

#define METHOD
    int (*sd_new)( struct storage_documents_t *self, const char *desc, size_t cnt, money_t cost );
    int (*sd_buy)( struct storage_documents_t *self, int pn, size_t cnt, money_t cost );
    int (*sd_sell)( struct storage_documents_t *self, int pn, size_t cnt, money_t price );
    int (*sd_delete)( struct storage_documents_t *self, int pn );
    int (*sd_print_pn)( struct storage_documents_t *self, int pn);
    int (*sd_print)( struct storage_documents_t *self );
    int (*sd_total)( struct storage_documents_t *self );

}storage_documents_t;


typedef struct control_pro{

DATA
    storage_documents_t *sd;
    FILE *file;
    char filename[50];
METHOD
    void (*cp_begin)( struct control_pro *self );
    void (*cp_end)( struct control_pro *self );
}control_pro_t;

static void set_part( part_t *dest, const char *desc, size_t cnt, money_t cost )
{
    strcpy( dest->desc, desc );
    dest->cnt = cnt;
    dest->cost = cost;
}

static int sd_new( struct storage_documents_t *self, const char *desc, size_t cnt, money_t cost )
{
    part_t *pp = self->parts;
    money_t *pt;
    int i;
    for( i = 0; i < self->num_parts; i++ )
    {
        if( pp[i].desc[0] == 0 )
        {
            set_part( pp + i, desc, cnt, cost );
            self->total_value_of_part[i] = cost * cnt;
            return i + 1;
        }
    }

    pp = realloc( self->parts, self->num_parts * 2 * sizeof( part_t ) );
    pt = realloc( self->total_value_of_part, self->num_parts * 2 * sizeof( money_t ) );
    if( !pp || !pt )
        return 0;
    self->parts = pp;
    self->total_value_of_part = pt;
    self->num_parts *= 2;
    set_part( pp + i, desc, cnt, cost );
    return i + 1;
}

static int sd_buy( struct storage_documents_t *self, int pn, size_t cnt, money_t cost )
{
    if( pn < 1 || pn > self->num_parts || !self->parts[pn - 1].desc[0] )
        return 0;

    part_t *pp = self->parts + pn - 1;
    pp->cnt += cnt;
    self->total_value_of_part[pn - 1] += cnt * cost;
    pp->cost = self->total_value_of_part[pn - 1] / pp->cnt;
    return pn;
}

static int sd_print_pn( struct storage_documents_t *self, int pn )
{
    if( pn < 1 || pn > self->num_parts )
    {
        printf( "Invalid part-number\n" );
        return 0;
    }

    printf( "part-number: %d\ndescription: %s\n", pn, self->parts[pn-1].desc );
    printf( "each-cost: %lf\n", self->parts[pn-1].cost );
    printf( "amount: %d\n", self->parts[pn-1].cnt );
    printf( "total value: %lf\n", self->total_value_of_part[pn-1] );
    return pn;
}

static void print_stars( int num )
{
    int i;
    for( i = 0; i < num; i++ )
        putchar( '*' );
}

static int parse_cmd( char *cmd, char **ret )
{
    char *p;
    int i;
    for( i = 0, p = strtok( cmd, " ,\n" ); p && i < 5; p = strtok( NULL, ", \n" ), i )
    {
        ret[i++] = p;
    }

    ret[i] = NULL;
    return 1;
}

static void cp_begin( control_pro_t *self )
{
    char cmd[256];
    int pn;
    char *argv[8];

    /* start screen */
    print_stars( 30 );
    puts( "" );
    print_stars( 30 );
    puts( "" );
    print_stars( 30 );
    puts( "" );
    printf( "Ready to go:\n");
    

    /* deal command-line */  
    /* No error reaction */
    while(1)
    {
        printf( ">: " );
        memset( argv, 0, sizeof( argv ) );
        fgets( cmd, sizeof(cmd), stdin );
        parse_cmd( cmd, argv );
        if( !argv[0] )
            continue; 
        if( !strcmp( argv[0], "new" ) )
        {
            pn = self->sd->sd_new( self->sd, argv[1], atoi( argv[2] ), atof( argv[3] ) );
            self->sd->sd_print_pn( self->sd, pn );
        }
        else if( !strcmp( argv[0], "buy" ) )
        {
            pn = self->sd->sd_buy( self->sd, atoi( argv[1] ), atoi( argv[2] ), atof( argv[3] ) );
            self->sd->sd_print_pn( self->sd, pn );
        }
        else if( !strcmp( argv[0], "sell" ) )
        {
            puts( "sell" );
        }
        else if( !strcmp( argv[0], "delete" ) )
        {
            puts( "delete" );
        }
        else if( !strcmp( argv[0], "print" ) )
        {
            if( !strcmp( argv[1], "all" ) )
            {
                self->sd->sd_print( self->sd );
            }
            else
            {
                self->sd->sd_print_pn( self->sd, atoi( argv[1] ) );
            } 
        }
        else if( !strcmp( argv[0], "total" ) )
        {
            puts( "total" );
        }
        else if( !strcmp( argv[0], "end" ) )
        {
            self->cp_end( self );
            printf( "Deal...\n" );
            printf( "Data has been stored in %s successfully.\n", self->filename );
            printf( "Exit...\n" );
            print_stars( 30 );
            puts( " " );
            return;
        }
        else
        {
            puts( "Unknown command" );
        }
    }
    
}

static void cp_end( control_pro_t *self )
{
    /* keep data into file */
}

static control_pro_t *init_cp( void )
{
    control_pro_t *pro = ( control_pro_t * ) malloc( sizeof( control_pro_t ) );
    if( !pro )
        return NULL;
    pro->sd = ( storage_documents_t * ) malloc( sizeof( storage_documents_t ) );
    if( !pro->sd )
        return NULL;
    /* cp init */
    pro->filename[0] = 0;
    pro->cp_begin = cp_begin;
    pro->cp_end = cp_end;

    /* sd init */
    pro->sd->num_parts = 256;
    pro->sd->parts = ( part_t * ) calloc( sizeof( part_t ),  pro->sd->num_parts );
    pro->sd->total_value_of_part = ( money_t * ) malloc( sizeof( money_t ) * pro->sd->num_parts );
    pro->sd->total_value_of_parts = 0;

    pro->sd->sd_new = sd_new;
    pro->sd->sd_buy = sd_buy;
    pro->sd->sd_print_pn = sd_print_pn;
    return pro;
}

static void destroy_cp( control_pro_t * pro )
{
    free( pro->sd->total_value_of_part );
    free( pro->sd->parts );
    free( pro->sd );
    free( pro );
}

void a11( void )
{
    control_pro_t *pro = init_cp();

    pro->cp_begin( pro );

    destroy_cp( pro );
}

