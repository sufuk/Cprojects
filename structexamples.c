#include <stdio.h>
#include "mystructdefinitions.h"

/* math.h included in the header file i dont know how to use ifndef
or ifdef something else so  please dont include math.h again
*/
int main(){

TDP_t pointA;
pointA.x = 0.00;
pointA.y = 3.00;
pointA.z = 1.00;

TDP_t pointB;
pointB.x = -4.00;
pointB.y = 0.00;
pointB.z = 5.00;
//functions defined in the mystructdefinitions.h

printf("distance betwwen pointA and pointb is %f\n", distancecalc(pointA, pointB));

//////////////////////////////////////////////////

TDP_t pointa = {1, 2, 3};
TDP_t pointb = {1, 2, 3};
TDP_t pointc = {1, 2, 3.0001};
printf("%d\n", isequal(pointa, pointb));
printf("%d\n", isequal(pointa, pointc));

////////////////////////////////////////////


float a = 1;
float b = 1;
float c = 2;
float d = 2;
complex_n mynum1= {a, b};
complex_n mynum2= {c, d};

complex_n resultsum = sum(mynum1, mynum2);

printf("resultsum real = %f\nresultsum img = %f \n", resultsum.real, resultsum.img);

///////////////////////////////////

TDP_t mypointa = {5, 6, 3};
printf("mypointa x is %f mypointa y is %f and z is %f\n", mypointa.x, mypointa.y, mypointa.z);

movepoint(&mypointa, 5, 4, 7);
printf("mypointa new x is %f and mypointa new y is %f and new z is %f\n", mypointa.x, mypointa.y, mypointa.z);



  return 0;
}
