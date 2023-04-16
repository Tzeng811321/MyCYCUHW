/* ch9 swap1.c */
#include <stdio.h>
void swap(int, int);
void swap_by_address(int *, int *);

int main()
{
    int x, y;
    x = 100;
    y = 200;
    printf("Initial ...\n");
    printf(" x = %d y = %d\n",x,y);
    //swap(x, y);  //incorrect
    swap_by_address(&x, &y);
    printf("\nAfter swapping ...\n");
    printf(" x = %d y = %d\n",x,y);
    return 0;
}
void swap_by_address(int *a, int *b)
{
    int temp;

    printf("\nIn swap_by_address() ...\n");
    printf(" *a = %d *b = %d\n", *a, *b);
    temp = *a;
    *a = *b;
    *b = temp;
    printf("End swap_by_address() ...\n");
    printf(" *a = %d *b = %d\n", *a, *b);
}

// void swap(int a, int b)
// {
//     int temp;
//     printf("\nIn swap() ...\n");
//     printf(" a = %d b = %d\n",a,b);
//     temp = a;
//     a = b;
//     b = temp;
//     printf("End swap() ...\n");
//     printf(" a = %d b = %d\n",a,b);
// }



