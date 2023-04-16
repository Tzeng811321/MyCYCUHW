#include <stdio.h>
#include <stdlib.h>
void show(void);
void insert(void);
void finsert(char);
void delete(void);
void search(void);
void flushBuffer(void); 
void update_file(void);

struct node {
    char value;
    struct node *next;
};
struct node *head, *curt, *prev;

int main()
{
    char key;
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL; 

    /*Read data from "data.txt"*/
    FILE  *fp = fopen("data.txt","r");
    char buff[255];
    while(fscanf(fp, "%s", buff)!=EOF)
    {  
      finsert(buff[0]);
    }
   

    while (1) {
        printf("\n------------------------------------------");
        printf("\nFunction:  0 ==>[EXIT]        1 ==> [SHOW]");
        printf("\n           2 ==>[INSERT]      3 ==> [DELETE]");
        printf("\n           4 ==>[SEARCH]");
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
                update_file();  //Update the data to "data.txt" file.
                break;
            case '3' :  
                printf("\n------------------------------------------");
                delete();
                update_file();  //Update the data to "data.txt" file.
                break;
            case '4' :  
                printf("\n------------------------------------------");
                search();
                break;
            default  : printf("\n wrong choice");
       }
   }
    
   return 0;
}

void show() //case 1
{
    int count;    
    curt = head->next;
    printf("\n");
    for (count=0; curt!=NULL; count++) {
        printf("%3c", curt->value);
        curt = curt->next;
    }
    printf("\n  %d character%s in total\n", count, (count>1) ?"s" : "");
}
   
void insert() //case 2
{
    struct node *ptr;
    printf("\n輸入一字元: ");
    char ins = getchar();
    flushBuffer();
    prev = head;
    curt = prev->next;
    //按照英文字母排序
    while (curt != NULL && curt->value < ins) {
        prev = curt;
        curt = curt->next;
    }

    if ((curt != NULL) && (curt->value)) {
        printf("\n    Character '%c' existed!\n", ins);
        return;
    }

    ptr =(struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nNot enough memory\n");
        return;
    }
      
    /* construct next list */
    ptr->value = ins;
    ptr->next = prev->next;
    prev->next = ptr;

    printf("\n    Character '%c' inserted OK\n", ins);
}

void finsert(char buff) 
{
    struct node *ptr;
    printf("\n輸入一字元: ");
    char ins = buff;
    prev = head;
    curt = prev->next;
    //按照英文字母排序
    while (curt != NULL && curt->value < ins) {
        prev = curt;
        curt = curt->next;
    }

    if ((curt != NULL) && (curt->value)) {
        printf("\n    Character '%c' existed!\n", ins);
        return;
    }

    ptr =(struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nNot enough memory\n");
        return;
    }
      
    /* construct next list */
    ptr->value = ins;
    ptr->next = prev->next;
    prev->next = ptr;

    printf("\n    Character '%c' inserted OK\n", ins);

}

void delete() //case 3
{
    printf("\n輸入欲刪除的字元: ");
    char del = getchar();
    flushBuffer();
    prev = head;
    curt = prev->next;
    while (curt != NULL && curt->value < del) {
        prev = curt;
        curt = curt->next;
    }

    if (curt != NULL && curt->value == del) {
        prev->next = curt->next;
        free(curt);
        printf("\n    Character '%c' deleted OK!\n", del);
    }else{
        printf("\n    Character '%c' Not existed!\n", del);
    }
}

void search() //case 4
{
    int count = 1;
    printf("\n輸入欲搜尋的字元： ");
    char sear = getchar();
    flushBuffer();
    curt = head->next;
    while (curt != NULL && curt->value < sear) {
        curt=curt->next;
        count++;
    }

    if ((curt!=NULL) && (curt->value == sear))
        printf("\n    Character '%c' is #%d!\n", sear, count);
    else
        printf("\n    Character '%c' Not existed!\n", sear);
}

void flushBuffer()
{
    while (getchar() != '\n')
        continue;
}

void update_file(void)
{
    FILE *fptr = fopen("data.txt","w");
    prev = head;
    while (prev->next != NULL)
    {
        curt = prev->next;
        char put_data = curt->value;
        fprintf(fptr,"%c",put_data);
        prev = curt;
    }
    fclose(fptr);
}