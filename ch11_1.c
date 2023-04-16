/* ch11 struct.c */
#include <stdio.h>
#define NUM 2
struct client {
    char name[8];
    char id[8];
    int age;
    int weight;
};

int main()
{
    struct client who[NUM];
    int i;
    int total;
    printf("Input personal data...\n\n");
    for (i=0; i<NUM; i++) {
        printf("Number #%d :\n", i+1);
        printf(" Who ? ");
        scanf("%s", who[i].name);
        printf(" ID number ? ");
        scanf("%s", who[i].id);
        printf(" How old ? ");
        scanf("%d", &who[i].age);
        printf(" Weight ? ");
        scanf("%d", &who[i].weight);
        printf("\n");
    }

    printf("\nDATA LISTING ...\n\n");
    printf(" NUMBER   NAME    ID     AGE    WEIGHT");
    printf("\n\n");

    for (i = 0; i<NUM; i++) {
        printf(" #%d",i+1);
        printf(" %8s %8s",who[i].name,who[i].id);
        printf(" %5d %8d",who[i].age,who[i].weight);
        printf("\n");
    }

    for (i=0,total=0; i<NUM; i++)
        total += who[i].weight;
    printf("\n Total Weight : %d kg\n",total);
    return 0;
}
