#include<stdio.h>
#include<string.h>
int main(){

  FILE *fileptr;
  char s[100];
  fileptr = fopen("myfile3.txt", "w");



    printf("\n If you have file named myfile3.txt \nfile's data is cleaned sorry but \n");
    printf("please enter a few lines of text \n");

  for( ; 0 < strlen(s) ; ){
    gets(s);
    fputs(s, fileptr);
    fputs("\n", fileptr);
    }


  return 0;
}
