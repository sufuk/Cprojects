#include<stdio.h>

#define AA 4.00
#define BA 3.75
#define BB 3.5
#define CB 3.0
#define CC 2.5
#define CD 2.0
#define DD 1.5
#define DF 1.0
#define FF 0.0
int main() {










        float GANO = 0.00;
        float GNO = 0.00;
        float points[999];

        int numoflessons;
        int akts[999];
        int i;
        int totalcredit = 0;

        printf("Enter the Total Number of lessons \n ");
        scanf("%d", & numoflessons);

        for (i = 0; i < numoflessons; i++) {

                printf("\n Enter the Credit and Point of lesson %d \n", i + 1);

                scanf("%d%f", & akts[i], & points[i]);

                totalcredit += akts[i];
                GANO += akts[i] * points[i];

        }
        GNO = GANO / totalcredit;
        printf("%F", GNO);

        return 0;
}
