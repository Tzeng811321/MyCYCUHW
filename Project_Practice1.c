/* ex13-1c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //tolower toupper
#define TRUE 1
#define TEMP_PERCENT    0.30
#define MID_PERCENT     0.30
#define FINAL_PERCENT   0.40

struct student {
    char id[8];     /* 學號 */
    char name[10];  /* 姓名 */
    double temp_score;  /* 平時考與作業 */
    double mid_score;   /* 期中考分數 */
    double final_score; /* 期末考分數 */
    struct student *next;
};

struct student  *head, *prev, *current, *ptrnew, *temp;
char fname[20];
void insert();
void del();
void query();
void modify();
void display();
void write();
void flushBuffer(); 
double calaverage(struct student *);

int main()
{
    char ch;
    int count = 0, flag = 0;
    //產生head
    head =(struct student *)malloc(sizeof(struct student));
    head->next = NULL;

    while(TRUE) {
	    printf("\n*****************************************");
    	printf("\n* Type 'i' to enter new student's data  *");
	    printf("\n*      'd' to delete one student's data *");
        printf("\n*      'q' to query one student's data  *");
	    printf("\n*      'm' to modify one student's data *");
	    printf("\n*      'l' to list all students' data   *");
	    printf("\n*      'e' to exit program and save     *");
	    printf("\n*****************************************");
	    printf("\nplease enter your choice : ");

	    ch = tolower(getchar());//tolower函式:將輸入轉為小寫
	    flushBuffer();
	    switch(ch) {
	        case 'i' :
		        insert();
		        break;
	        case 'd' :
		        del();
		        break; 
		    case 'q':
                query();
                break;  
		    case 'm':
			    modify();
				break;
	        case 'l' :
		        display();
		        break;
	        case 'e' :
			    exit(0);
	        default  :
		        printf("\nPlease select one choice !\n");
        }
    }
    return 0;
}

/**** insert function ****/
void insert()
{
    //配置空間給新加入的資料
    ptrnew = (struct student *)malloc(sizeof(struct student));
    /* head is always empty */
    /* add a node to list front */

    printf("\nEnter ID            : ");
    scanf("%s", ptrnew->id);
    printf("Enter name          : ");
    scanf("%s", ptrnew->name);
    printf("Enter Temp Score    : ");
    scanf("%lf", &(ptrnew->temp_score));
    printf("Enter Mid Score     : ");
    scanf("%lf", &(ptrnew->mid_score));
    printf("Enter Final Score   : ");
    scanf("%lf", &(ptrnew->final_score));
    flushBuffer(); 
    /* new insert algorithm */
    prev = head;
    current = head->next;
    /*按照平均成績優到劣排序，找先資料該插入的位置(prev和current中間)。
    if this node's average is bigger then move to the next node of list*/
    while (current != NULL && calaverage(ptrnew) < calaverage(current)){
        prev = current;
        current = current->next; 
    }
    /* construct the list */
    
    ptrnew->next =  current;
    prev->next = ptrnew;
}

/**** delete function ****/
void del()
{
    char id[8];
    double average;
    printf("\nWhat student ID do you want to delete ? ");
    scanf("%s", id);
    flushBuffer(); 
    prev=head;
    current=head->next;
    while(current != NULL && strcmp(current->id, id) != 0) { 
	    prev = current;
        current = current->next; 
    }

    if(current == NULL) {
	    printf("Data not found\n");
	    return;
    } 
  
    printf("\n\n  學號     姓名       平時考與作業  ");
    printf("期中考  期末考  平均分數");
    printf("\n  -------  ---------    ------------  ");
    printf("------  ------  --------\n");
    printf("  %-7s", current -> id);
    printf("  %-10s", current -> name);
    printf("  %-13.1f", current -> temp_score);
    printf("  %-6.1f", current -> mid_score);
    printf("  %-6.1f", current -> final_score);

    average = calaverage(current);
    printf("  %5.1f\n", average);

    printf("\nAre you sure to delete this record ? (Y/N) : ");
    if (toupper(getchar()) == 'Y'){
    	prev->next = current->next;
        free(current); //釋放不用的記憶體位置
  	    printf("\nRecord deleted.\n");
    }
    else
        printf("\nRecord not deleted.\n");
    flushBuffer(); 
}

// /**** query function *****/ 
void query()
{
	char id[8];
	double average;
	printf("\nWhich student ID do you want to query  ? ");
	scanf("%s", id);
	flushBuffer();
	current=head->next;
	while(current != NULL && strcmp(current->id, id))
		current=current->next; 

	if(current == NULL) {
		printf("Data is not found\n");
	    return;
    }
	printf("\n\n  學號     姓名        平時考與作業  ");
	printf("期中考  期末考  平均分數");
    printf("\n  -------  ---------   ------------  ");
	printf("------  ------  --------\n");
    printf("  %-7s", current -> id);
	printf("  %-10s", current -> name);
	printf("  %-13.1f", current -> temp_score);
	printf("  %-6.1f", current -> mid_score);
	printf("  %-6.1f", current -> final_score);

    average = calaverage(current);
    printf("  %5.1f\n", average);
}

/*** modify function ****/
void modify()
{
	char id[8];
	printf("\nWhich student ID do you want to modify ? ");
	scanf("%s", id);
	flushBuffer();
	prev = head;
	current=head->next;
    //尋找ID
	while(current != NULL && strcmp(current->id, id)) {
	    prev = current;
		current=current->next; 
    }
	if(current == NULL) {
		printf("Data is not found\n");
	    return;
    }
   
	/* input new data */
    printf("\nEnter ID            : ");
    scanf("%s", current->id);
    printf("Enter name          : ");
    scanf("%s", current->name);
    printf("Enter Temp Score    : ");
    scanf("%lf", &current->temp_score);
    printf("Enter Mid Score     : ");
    scanf("%lf", &current->mid_score);
    printf("Enter Final Score   : ");
    scanf("%lf", &current->final_score);
    flushBuffer();
    
    /* 重新調整 */
	prev->next = current->next;
	temp = current; 
	/* new insert algorithm */
    prev = head;
    current = prev->next;
    /*if this node's average is bigger then move to the next node of list*/
    while (current != NULL && calaverage(temp) < calaverage(current)){
        prev = current;
        current = current->next; 
    }
    /* construct the list */
    temp->next = current;
    prev->next = temp;
}

// /**** list function ****/
void display()
{
    double average;
    if( head->next == NULL)//list沒有資料
	    printf("\n list is empty\n");
    else {
       	printf("\n\n  學號     姓名        平時考與作業  ");
		printf("期中考  期末考  平均分數");
    	printf("\n  -------  ---------   ------------  ");
		printf("------  ------  --------\n");
        current = head->next;
	    while(current != NULL){//印出直到最後一筆資料
	        printf("  %-7s", current -> id);
	        printf("  %-10s", current -> name);
	        printf("  %-13.1f", current -> temp_score);
	        printf("  %-6.1f", current -> mid_score);
	        printf("  %-6.1f", current -> final_score);
            average = calaverage(current);
  	        printf("  %5.1f\n", average);
		    current = current -> next;
	    }
    }
}

double calaverage(struct student *current)//算平均成績
{
	double avg;
	
	avg = current->temp_score * TEMP_PERCENT    +
 	      current->mid_score * MID_PERCENT     +
		  current->final_score * FINAL_PERCENT;
	return avg;
}

void flushBuffer()
{
	while (getchar() != '\n')
		continue; 
}

