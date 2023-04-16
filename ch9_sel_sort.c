/* ch9 sel_sort.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5     //亂數個數

void list(int *);
void swap(int *, int *);
void selection_sort(int *);
void selection_sort_2(int *);

int main()
{
    int i,array[N]; 
    // 產生N個亂數
    srand(time(NULL));
    for (i=0; i<N; i++)
        array[i] = rand() % 100 +1;
    // 印出亂數  
    printf("\nSource array ...\n->");
    for (i=0; i<N; i++) {
        printf("%8d", array[i]);
    }
    printf("\n");
    // 選擇排序
    //selection_sort(array);
    selection_sort_2(array);
    // 印出結果  
    printf("\nSorting ...\n->");
    for (i=0; i<N; i++) {
        printf("%8d", array[i]);
    }
    return 0;
}


void list(int *array)
{
    int i;

    for (i=0; i<N; i++) {
        printf("%8d", array[i]);
        if (((i+1) % 5) == 0)
            printf("\n");
    }
    // printf("\n");
}

void swap(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

void selection_sort(int *array)
{
    int i,cmp,min;
    
    for (i=0; i<N; i++) {
        min = i;
        for (cmp = i; cmp < N; cmp++){
            if (array[cmp] < array[min])
                min = cmp;
        }
        swap(&array[min], &array[i]);
    }
}

void selection_sort_2(int *array)
{
    int i,cmp,min;

    for (i=0; i<N; i++) {
        min = i;
        printf("Present array[%d] has the mininum num %d\n", min, array[min]);      
        for (cmp = i; cmp < N; cmp++)
            if (array[cmp] < array[min]){
                min = cmp;
                printf("Present array[%d] has the mininum num %d\n", min, array[min]);
                // printf("Present min = %d\n", array[min]);
            }
        printf("Swap array[%d] and array[%d]\n", i, min);
        printf("============================================\n");
        swap(&array[min], &array[i]);
        printf("->");
        list(array);
    }
}
