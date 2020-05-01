#include <stdio.h>
#include <string.h>
#include "PhonebookFunctions.h"

/*you can see coding progress on my
 github repo : https://github.com/sufuk/Cprojects

Semih Ufuk Güler
200011674
EEE #2
*/


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
      deletecontact(fp1);
      break;

    case 5:
      editcontact(fp1);
      break;

    case 6:

      break;

        default:
            printf("ERROR try again");
            break;
    }
}

  return 0;
}
