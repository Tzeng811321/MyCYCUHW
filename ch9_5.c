/* ch9 two_ptr.c */
#include<stdio.h>
int main( )
{
    int a[] = {0, 1, 2, 3, 4};
    int *p[] = {a, a+1, a+2, a+3, a+4};

    printf("p=%p, p+1=%p\n", p, p+1);
    printf("(sizeof(p)/5)=%d\n", (sizeof(p) / 5));
    printf("sizeof(int *)=%d\n", sizeof(int *));    //指標的儲存大小=>8
    printf("*p[2] = %d, *(a+2) = %d\n", *p[2], *(a+2));

    return 0;
}
