#include<stdio.h>
#include "mystringlibary.h"


int main(){


char eren[] = "erdem" ;

printf("erdem's length is %d\n", my_strlen(eren));

char str4[] = "sufuk";
char str5[] = "erdem";


printf("comparement of sufuk and erdem is %d\n", my_strcmp(str4, str5));



char str10[] = "izmit";
char str11[] = "basiskele";

my_strcpy(str10, str11);

printf(" if we copy str11 to str10 our str10 is %s \n", str10);



char stra[] = "sufuk";
char strb[] = "guler";
my_strcat(stra, strb);
printf("if ve concerate stra and strb we get  %s \n", stra);
char strc[] = "sufuk";
char strd[] = "erdem";
my_strncat(strc, strd, 3);
printf("If we concerate 3 character of strd's to strc we get\n%s", strc);


char stru[] = "sufuk";
char strj[] = "erdem";
my_strncpy(stru, strj, 3);

printf("\n If we copy 3 digits to stru we get %s\n", stru);
char strh[] = "sufukggg";
char strt[] = "sufu4";
printf("if we compare 3 character of strh and strt we get %d", my_strncmp(strh, strt, 3));
  return 0;
}
