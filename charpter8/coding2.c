#include "a.h"

/* 
 *  data part 
 */
const static int parts = 5;
/* In this function there is no usage of the data - tax_bot */
static int tax_bot[] = {
    0,      23350,
    56550,  117950,
    256500,
};
static int tax_top[] = {
    23350,      56660,
    117950,     256500,
    INT_MAX, 
};
static double tax_basic[] = {
    0,          3502.50,
    12798.50,   31832.50,
    81710.50,   
};
static double tax_percent[] = {
    .15,    .28,
    .31,    .36,
    .396,   
};

static float single_tax( float income )
{
    int i = -1;
    double cp_of_income = income;

    while( cp_of_income > 0 && i < parts )
    {
        cp_of_income -= tax_top[++i];
    }

    if( i < 0 )
        return -1.;
    return tax_basic[i] + tax_percent[i] * income;
}

void a2( void )
{
    float income;
    printf( "Please enter your income:\n" );
    scanf( "%f", &income );
    printf( "The tax of your income is %f\n", single_tax( income ) );
}