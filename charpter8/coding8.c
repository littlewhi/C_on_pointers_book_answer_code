#include "a.h"

#define ON 1
#define OFF 0
#define ROW 8
#define COL 8

typedef char (board_type) [ROW][COL];

static int cnt;

static int check_surround( board_type board, int r, int c )
{
    int i;

    /* left straight */
    for( i = 1; c - i >= 0; i++ )
        if( board[r][c - i] == ON )
            return 0;
    /* left up */
    for( i = 1; r - i >= 0 && c - i >= 0; i++ )
        if( board[r - i][c - i] == ON )
            return 0;
    /* up */
    for( i = 1; r - i >= 0; i++ )
        if( board[r - i][c] == ON )
            return 0;
    /* right up */   
    for( i = 1; r - i >= 0 && c + i < COL; i++ )
        if( board[r - i][c + i] == ON )
            return 0;
    /* right straight */
    for( i = 1; c + i < COL; i++ )
        if( board[r][c + i] == ON )
            return 0;
    /* right down */
    for( i = 1; r + i < ROW && c + i < COL; i++ )
        if( board[r + i][c + i] == ON )
            return 0;
    /* down */
    for( i = 1; r + i < ROW; i++ )
        if( board[r + i][c] == ON )
            return 0;
    /* left down */
    for( i = 1; r + i < ROW && c - i >= 0; i++ )
        if( board[r + i][c - i] == ON )
            return 0;

    return 1;
}

static void get_some_board( board_type board, int r, int c, int val )
{
    int i;

    /* left straight */
    for( i = 1; c - i >= 0; i++ )
        board[r][c - i] += val;
    /* left up */
    for( i = 1; r - i >= 0 && c - i >= 0; i++ )
        board[r - i][c - i] += val;
    /* up */
    for( i = 1; r - i >= 0; i++ )
        board[r - i][c] += val;
    /* right up */   
    for( i = 1; r - i >= 0 && c + i < COL; i++ )
        board[r - i][c + i] += val;
    /* right straight */
    for( i = 1; c + i < COL; i++ )
        board[r][c + i] += val;
    /* right down */
    for( i = 1; r + i < ROW && c + i < COL; i++ )
        board[r + i][c + i] += val;
    /* down */
    for( i = 1; r + i < ROW; i++ )
        board[r + i][c] += val;
    /* left down */
    for( i = 1; r + i < ROW && c - i >= 0; i++ )
        board[r + i][c - i] += val;
}

/*
 * The grid which will be attacked is signed by '!',
 * and the grid which will be placed queen is a character of 'Q',
 * the empty gird is a '*'.
 */
static void print_board( board_type board, int row, int col )
{
    int i, j;
    for( i = 0; i < row; i++ )
    {
        for( j = 0; j < col; j++ )
        {
            if( board[i][j] == OFF )
                printf( "* " );
            else if( board[i][j] == ON )
                printf( "Q " );
            else
                printf( "! " );
        }
        printf( "\n\n" );
    }   
}

static int dfs( board_type board, int queens, int r )
{
    int i;

    if( !queens )
    {
        ++cnt;
        #if 0
        print_board( board, ROW, COL );
        printf( "\n" );
        #endif
        return 1;
    }

    if( r >= ROW )
        return 0;

    for( i = 0; i < COL; i++ )
    {
        if( board[r][i] == OFF && check_surround( board, r, i ) )
        {
            get_some_board( board, r, i, -1 );
            board[r][i] = ON;
            dfs( board, queens - 1, r + 1 );
            get_some_board( board, r, i, 1 );
            board[r][i] = OFF;
        }
    } 

    return 0; 
}

void a8( void )
{
    board_type board = { 0 };
    dfs( board, 8, 0 );
    printf( "%d\n", cnt );
}