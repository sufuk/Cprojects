#include<stdio.h>
#include<string.h>
int main(){

  FILE *fileptr;
  char s[80];
  fileptr = fopen("myfile3.txt", "w");

  if(fileptr == NULL){
    printf("File can not be opened \n");
    }

    printf("\n If you have file named myfile3.txt file's data is cleaned sorry but \n");
    printf("please enter a few lines of text \n");

  for( ; 0 < strlen(s) ; ){
    gets(s);
    fputs(s, fileptr);
    fputs("\n", fileptr);
      }


  return 0;
}
