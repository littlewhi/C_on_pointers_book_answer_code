int static_variable = 5;

void f( void )
{
    register int i1, i2, i3, i4, i5, i6, i7,
        i8, i9, i10;
    register char *c1, *c2, *c3, *c4,
        *c5, *c6, *c7, *c8, *c9, *c10;
    extern int a_very_long_name_to_see_how_long_they_can_be;
    double dbl;
    int func_ret_int();
    double func_ret_double();
    char *func_ret_char_ptr();

    /*
     * 寄存器变量最大数量
    */
    i1 = 1; i2 = 2; i3 = 3; i4 = 4;
    i5 = 5; i6 = 6; i7 = 7; i8 = 8; 
    i9 = 9; i10 = 10;
    c1 = (char *) 1; c2 = (char *) 2; c3 = (char *) 3; c4 = (char *) 4;
    c5 = (char *) 5; c6 = (char *) 6; c7 = (char *) 7; c8 = (char *) 8;
    c9 = (char *) 9; c10 = (char *) 10;

    /*
     * 外部名字
    */
    a_very_long_name_to_see_how_long_they_can_be = 1;

    /*
     * 函数调用/返回协议、堆栈帧（过程活动记录）
    */
    i2 = func_ret_int( 10, i1, i10 );
    dbl = func_ret_double();
    c1 = func_ret_char_ptr( c1 );
}

int func_ret_int( int a, int b, register int c )
{
    int d;
    d = b - 6;
    return a + b + c;
}

double func_ret_double( void )
{
    return 3.14;
}

char *func_ret_char_ptr( char *c )
{
    return c + 1;
}