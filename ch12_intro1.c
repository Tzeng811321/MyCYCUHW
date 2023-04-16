#include <stdio.h>

int main(){
    FILE *fp;
    int aa=2023; 
    
    fp = fopen("test.txt", "w");
    fprintf(fp, "This is testing for fprintf.\n");
    fprintf(fp, "%s %s %s %d.\n", "We", "are", "in", aa);
    fputs("This is testing for fputs.", fp);
    fclose(fp);


    return 0;
}