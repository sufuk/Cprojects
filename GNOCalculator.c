#include<stdio.h>

int  main(){


float GANO = 0.00;
float GNO = 0.00;
int numoflessons;
int akts[999];
float points[999];
int i;
int totalcredit = 0;

printf("Enter the Total Number of lessons \n ");

scanf("%d", &numoflessons);

for(i=0;i<numoflessons;i++){

printf("\n Enter the Credit and Point of lesson %d \n", i+1);

scanf("%d%f", &akts[i], &points[i]);

totalcredit += akts[i];

GANO += akts[i] * points[i] ;

}

GNO = GANO/totalcredit;

printf("%F",GNO);



    return 0;
}