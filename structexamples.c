#include <stdio.h>
#include "mystructdefinitions.h"

/* math.h included in the header file i dont know how to use ifndef
or ifdef something else so  please dont include math.h again
*/
int main(){

TDP_t pointA;
pointA.x = 0.00;
pointA.y = 3.00;

TDP_t pointB;
pointB.x = -4.00;
pointB.y = 0.00;
//functions defined in the mystructdefinitions.h

printf("distance betwwen pointA and pointb is %f\n", distancecalc(pointA, pointB));

//////////////////////////////////////////////////

TDP_t pointa = {1,2};
TDP_t pointb = {1,2};
TDP_t pointc = {1,2.00001};
printf("%d\n", isequal(pointa, pointb));
printf("%d\n", isequal(pointa, pointc));

////////////////////////////////////////////







  return 0;
}
