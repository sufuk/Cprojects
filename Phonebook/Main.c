#include <stdio.h>
#include <string.h>
#include "PhonebookFunctions.h"



int main(){
FILE *fp1;
int a;
for(a ;  a !=6  ; ){
  menu();
  scanf("%d", &a);
  switch(a)
  {
    case 1:
      listcontact(fp1);
      break;

    case 2:
      searchcontact(fp1);
      break;

    case 3:
      addcontact(fp1);
      break;

    case 4:

      break;

    case 5:

      break;

    case 6:

      break;


        default:
            printf("Error! operator is not correct");
    }















/*  if(a == 1){


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




*/
}



  return 0;
}
