#include<stdio.h>
#include "mystringlibary.h"


int main(){


char eren[] = "erdem" ;

printf("eren's length is %d\n", my_strlen(eren));

char str4[] = "sufuk";
char str5[] = "sufuk";


printf("comparement of str4 and str5 is %d\n", my_strcmp(str4, str5));



char str10[] = "izmit";
char str11[] = "basiskele";

my_strcpy(str10, str11);

printf("%s \n", str10);



char stra[] = "sufuk";
char strb[] = "erdem";
my_strcat(stra, strb);
printf("\n %s", stra);
char strc[] = "sufuk";
char strd[] = "erdem";
my_strncat(strc, strd, 3);
printf("\n%s", strc);
  return 0;
}
