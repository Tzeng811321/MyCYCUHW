/* ch9 ptr_var.c */
#include <stdio.h>
int main()
{
    int num = 16;
    int *ptr_num;   //宣告pointer儲存空間
    printf(" num = %d \t\t&num = %p\n",num,&num);
    printf(" size of int= %d\n",sizeof(int));
    ptr_num = &num;
    printf(" *ptr_num = %d \t\tptr_num = %p \t\t&ptr_num = %p\n",
                *ptr_num, ptr_num, &ptr_num);
    printf(" size of int*= %d\n",sizeof(int*));

    return 0;
}