#include <stdio.h>
#include <math.h>
#include "mystructdefinitions.h"



int main(){

TDP_t pointA;
pointA.x = 0.00;
pointA.y = 3.00;

TDP_t pointB;
pointB.x = -4.00;
pointB.y = 0.00;
//functions defined in the mystructdefinitions.h

printf("%f", distancecalc(pointA, pointB));











  return 0;
}
