#include <stdlib.h>
#include <stdio.h>
#include "funcs.h"
/*
Semih Ufuk Güler
200011674 EEE #2
You can check the writing procces here:
https://github.com/sufuk/BIL132_Programming2/tree/master/projects/Checkers
*/
int main(){
char *b = NULL;
b = checkersboard();
readboard(b);
printf("\n WELCOME TO TURKISH CHECKKERS\n\n\n");
printf("WHITE --> O\nBLACK --> @\n\n\n");
game_engine(b, 0);
int a;
scanf("%d", &a);
  return 0;
}
