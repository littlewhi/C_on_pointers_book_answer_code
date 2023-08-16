#include <stdio.h>
#include <string.h>

#define MILLION (unsigned int) (1e6)
#define THOUSAND (unsigned int) (1000)
#define HUNDRED (unsigned int) (100)
#define TEN (unsigned int) (10)
#define ONE (unsigned int) (1)
/* 0 - 19*/
const char *word_to_num_under[] = {
    "ZERO",    "ONE",     "TWO",       "THREE",    "FOUR",
    "FIVE",    "SIX",     "SEVEN",     "EIGHT",    "NINE",
    "TEN",     "ELEVEN",  "TWELVE",    "THIRTEEN", "FOURTEEN",
    "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN",
};
/*20, 30, 40, ..., 90 */
const char *word_to_num_top[] = {
    "TWENTY", "THIRTY",  "FORTY",  "FIFTY",
    "SIXTY",  "SEVENTY", "EIGHTY", "NINETY",
};

/* express the number in amount in tha way of words.
 * if amount = 1234,
 * the function will put "one thousand thirty four" in buffer.
 * so you need insure the buffer's space is enough.
 * note ： the most unit is million(10 ^ 6)
 */
void written_amount( unsigned int amount, char *buffer )
{
    int div;
    /* check if there is number in million unit */
    if( (div = amount / MILLION) != 0 ) 
    {
        written_amount( div, buffer );
        strcat( buffer, " MILLION" );
        amount = amount % MILLION;

    }
    /* check if there is number in thousand unit */
    if( (div = amount / THOUSAND) != 0 )
    {
        written_amount( div, buffer);
        strcat( buffer, " THOUSAND" );
        amount = amount % THOUSAND;
    }
    /* check if there is number in hundred unit */
    if( (div = amount / HUNDRED) != 0 )
    {
        written_amount( div, buffer );
        strcat( buffer, " HUNDRED" );
        amount = amount % HUNDRED;
    }
    /* check if there is number in ten unit */
    if( (div = amount / TEN) != 0 )
    {
        /* if buffer is "" and then don't add space' ' */
        strcmp( buffer, "" ) == 0 ? (char *) NULL : strcat( buffer, " ");
        if( div == 1 )  /* if there is one ten in amount */
        {
            strcat( buffer, word_to_num_under[amount] );
            return; /* these special number can be expressed at once, so stop here */
        }
        else            /* if ther is more than one ten in amount */
        {
            strcat( buffer, word_to_num_top[div - 2] );
        }
        amount = amount % TEN;
    }
    /* check if there is number in one unit */
    if( (div = amount / ONE) != 0 )
    {
        strcmp( buffer, "" ) == 0 ? (char *) NULL : strcat( buffer, " ");
        strcat( buffer, word_to_num_under[amount] );
    }
}

int main( void )
{
    char buffer[1024] = "";
    written_amount( 16312, buffer );

    puts(buffer);

    return 0;
}