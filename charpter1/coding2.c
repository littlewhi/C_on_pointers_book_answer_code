#include <stdio.h>
#include <stdlib.h>

#define CONTROL_SPACE 1024

#if 0
int main(void)
{
    int row_num = 0;
    int ch, i = 0, size;
    char *buf = malloc(CONTROL_SPACE);
    size = CONTROL_SPACE;

    while((ch = getchar()) != EOF)
    {
        if(ch == '\n')
        {
            buf[i] = '\0';
            printf("%d : %s\n", row_num++, buf);
            i = 0;
            continue;
        }

        buf[i++] = ch;
        if(i == size)
        {
            size += CONTROL_SPACE;
            buf = realloc(buf, size);
        }
    }

    free(buf);
    return 0;
}
#endif

/* c语言的输出缓冲如下三种情况刷新：
 * 1. 遇到'\n'
 * 2. 使用fflush()函数，
 * 3. 程序结束（正常结束，如果是错误导致中断停止，往往不会刷新，调试时可以每个语句加上fflush()）
 */
int main(void)
{
    int line = 0;
    int begin = 1;
    int ch;
    while((ch = getchar()) != EOF)
    {
        if(begin == 1)
        {
            begin = 0;
            printf("%d : ", line++);
        }

        putchar(ch);

        if(ch == '\n')
        {
            begin = 1;
        }
    }

    return 0;
}