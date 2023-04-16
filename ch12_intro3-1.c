#include <stdio.h>  
int main(){  
    FILE *fp;  
    char buff[255];//creating char array to store data of file  
    fp = fopen("test.txt", "r");  
    while(fscanf(fp, "%s", buff)!=EOF){  
        printf("%s ", buff );  
    }  
    fclose(fp);  
}