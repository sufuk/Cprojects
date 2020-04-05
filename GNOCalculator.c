#include<stdio.h>

int main() {


  /*
  Please type your grade like;
  AA = 4.00
  BA = 3.75
  BB = 3.5
  CB = 3.0
  CC = 2.5
  CD = 2.0
  DD = 1.5
  DF = 1.0
  FF = 0.0

*/







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
