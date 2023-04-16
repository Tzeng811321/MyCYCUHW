#include <stdio.h>
#include <stdlib.h>
void show(void);
void insert(void);
void delete(void);
void search(void);
void flushbufer(void);

struct node
{
    char data;
    struct node *link;
    /* struct */
};
struct node *head, *current, *prev;

int main()
{
    char key;
    head = (struct node *)malloc(sizeof(struct node));
    head->link  = NULL;
    while (1)
    {
        /* menu */
        printf("\nFunction:  0 ==>[EXIT]        1 ==>[SHOW]");
        printf("\n           2 ==>[INSRET]      3 ==>[DELETE]");
        printf("\n                              4 ==>[SEARCH]");
        printf("\n");
        printf("請輸入選項 : ");
        key = getchar();
        flushbufer();
        switch (key)
        {
        case '0':
            printf("\nBye Bye  !!!\n");
            exit(1);
        case '1':
            show();
            break;
        case '2':
            insert();
            break;
        case '3':
            delete();
            break;
        case '4':
            search();
            break;
        default:
            printf("Wrong Choice !!!!!");
        }
    }
    return 0;
}
void show()
{
    int count;
    current = head->link;
    for (count = 0; current != 0; count++)
    {
        printf("%3c", current->data);
        current = current ->link;
    }
    printf("\n     %d character %s in total\n", count, (count>1) ? "s" : " ");
    
}
void insert()
{
    struct node *ptr;
    printf("Enter a alphabeta: ");
    char ins = getchar();
    flushbufer();
    prev = head;
    current = prev->link;
    // 按照英文排序
    while (current != NULL && current->data < ins)
    {
        prev = current;
        current = prev->link;
    }
    if((current != NULL) && (current->data == ins))
    {
        printf("\n    Character '%c' existed!\n",  ins);
        return;
    }
    ptr = (struct node *) malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n Not enough memory\n");
        return;
    }
    // construct link list
    ptr->data = ins;
    prev->link = ptr;
    printf("\n    Character '%c' inserted OK!\n",  ins);
}
void delete()
{
    printf("輸入欲刪掉的字元: ");
    char del = getchar();
    flushbufer();
    while (current != NULL && current->data <del)
    {
        prev = current;
        current = current->link;
    }
    if (current != NULL && current->data == del)
    {
        prev->link = current->link;
        free(current);
        printf("\n      Character '%c' delete ok!\n",del);
    }
    else
    {
        printf("\n      Character '%c' Not existed!\n",del);
    }
    
}
void search()
{
    int count = 1;
    printf("請輸入欲搜尋字元: ");
    char sear = getchar();
    flushbufer();
    current = head->link;
    while (current != NULL && current->data <sear)
    {
        current = current->link;
        count++;
    }
    if ((current != NULL) && (current->data == sear))
    {
        printf("\n     Character '%c' is #%d!\n", sear, count);
    }
    else
    {
        printf("\n     Character '%c' Not existed", sear);
    }
    
}
void flushbufer()
{
    while (getchar() != '\n')
    {
        continue;
    }
}
