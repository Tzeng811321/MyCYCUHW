/* ch9 pointer(指標) 一般宣告*/
#include <stdio.h>
void func_call(void);
int global_int=5;
int main()
{
    int num = 10;
    char ch1 = 'A';
    double double1 = 3.14;
    int a=0;
    printf("------------------------------------------------------------------------\n");
    printf("In main() ...\n");
    printf(" num \t\t= %d \t\t &num \t\t= %x\n", num, a=&num); 
    printf(" global_int \t= %d \t\t &global_int \t= %p\n", global_int, &global_int);
    printf(" ch1 \t\t= %c \t\t &ch1 \t\t= %p\n", ch1, &ch1);
    printf(" double1 \t= %.2f \t\t &double1 \t= %p\n", double1, &double1);

    func_call();
    return 0;
}
void func_call(void)
{
    int num = 15;
    printf("\nIn func_call() ...\n");

    printf(" num \t\t= %d \t\t &num \t\t= %p\n", num, &num);
    printf(" global_int \t= %d \t\t &global_int \t= %p\n", global_int, &global_int);
}
