#include<stdio.h>



main(){

  FILE *fs, *ft ;
  char ch;
  fs = fopen ("myfile.c", "r");
  if(fs == NULL){
    puts("cannot open source file");
  }
  ft = fopen("copy.c", "w");
  if(ft == NULL){
    puts("cannotopen target file");
    fclose(fs);
  }
  while(1){
    ch = fgetc(fs);

    if(ch == EOF)
    break;
    else
    fputc( ch, ft);
    }

  fclose(fs);
  fclose(ft);
  
}
