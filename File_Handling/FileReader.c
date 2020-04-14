#include<stdio.h>



int main(){

FILE *file_pointer;
char c;




file_pointer = fopen("myfile.txt", "r");

for(c ; file_pointer != NULL && c != EOF ;){
  c = fgetc(file_pointer);
  printf("%c", c);

}

fclose(file_pointer);





return 0;
}
