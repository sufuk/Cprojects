#include<stdio.h>



int main(){

  FILE *fileptr1, *fileptr2 ;
  char c;

  fileptr1 = fopen("myfile2.txt", "r");
  fileptr2 = fopen("copy.txt", "w");

  for(c ; (fileptr1 != NULL && fileptr2 != NULL) && (c != EOF) ;){
    c = fgetc(fileptr1);
    if(c != EOF){
    fputc(c, fileptr2);
  }
  /* last if statement not really neceassary but if
  you dont use for loop runs one last  time even
  if c = EOF
*/
}
  fclose(fileptr1);
  fclose(fileptr2);

  return 0;
}
