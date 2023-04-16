/* ch11 linklist.c */
//hell
#include <stdio.h>
#include <stdlib.h>
void show(void);
void insert(void);
void flushBuffer(void);

struct node {
    char data;
    struct node *link;
};
struct node *head, *current, *prev;

int main()
{
    char key;
    head = (struct node *)malloc(sizeof(struct node));
    head->link = NULL; //
    while (1) {
        printf("\n------------------------------------------");
        printf("\nFunction:  0 ==>[EXIT]      1 ==> [SHOW]    2 ==>[INSERT] ");
        printf("\n");
        printf("\n請輸入選項: ");
        key = getchar();
        flushBuffer();
        switch (key) {
            case '0' : 
                printf("\n------------------------------------------");
                printf("\nBye Bye !\n");
                exit(1);
            case '1' :  
                printf("\n------------------------------------------");
                show();
                break;
            case '2' :  
                printf("\n------------------------------------------");
                insert();
                break;
            default  : printf("\n wrong choice");
       }
   }
   return 0;
}

void show() //case 1
{
    int count;    
    current = head->link;
    printf("\n");
    for (count=0; current!=NULL; count++) {
        printf("%3c", current->data);
        current = current->link;
    }
    printf("\n  %d character%s in total\n", count, (count>1) ?"s" : "");
}
   
void insert() //case 2  :將輸入的字母加入鏈結
{
    printf("\n輸入一字元: ");
    char ins = getchar();
    flushBuffer();
    struct node *ins_node;
    current = head;
    while (current->link != NULL ) {
        current = current->link;
    }
    ins_node=(struct node *) malloc(sizeof(struct node));
    ins_node->data = ins;
    ins_node->link = NULL;
    current->link = ins_node;
    printf("\n    Character '%c' inserted OK\n", ins);
}


void flushBuffer()
{
    while (getchar() != '\n')
        continue;
}
