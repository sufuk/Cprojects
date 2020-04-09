#include <stdio.h>
#include <string.h>

typedef struct person {

  int age;
  char firstname[6];
  char lastname[6];
  int student_number;
  char department[4];
}person_t;



int main(){

person_t myperson;
myperson.age = 19;
strcpy(myperson.firstname, "Sufuk");
strcpy(myperson.lastname, "Guler");
myperson.student_number = 200011674;
strcpy(myperson.department, "EEE");


printf("mypersons's:\nFirst Name is %s\nLast Name is %s\nStudent Number is %d\nDepartmen is %s", myperson.firstname,
myperson.lastname, myperson.student_number, myperson.department);




  return 0;
}
