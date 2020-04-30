#include <stdio.h>
#include <string.h>
#include "PhonebookFunctions.h"



int main(){
FILE *fp1;
int a;
for(a ; a != 6 ; ){
  menu();
  scanf("%d", &a);

  if(a == 1){


    listcontact(fp1);






}
//////////////

  if(a == 2){
    searchcontact(fp1);

}
//////////////////////7

  if(a == 3){

    addcontact(fp1);

}
////////////////777

  if(a == 4){



}

///////////////////7777777


if(a == 5){



}

else{
  printf("Try again please");
}

}





  return 0;
}
