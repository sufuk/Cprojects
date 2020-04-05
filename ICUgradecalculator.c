#include <stdio.h>


/*
In this code vise effects %30
an final %70

this can not be used as an offical tool for ıstanbul commerce university
your teacher probably gives grades differently

*/

int main(){

float vise;
float Final;
float average;
float x;
printf("Enter your Vise point\n");

scanf("%f", &vise);


printf("\nEnter your Final Point\n");

scanf("%f", &Final);

average = (vise * 30) + (Final * 70);

x = average / 100 ;


printf("%f", x);


if(91 <= x){

    printf("\n AA \n");

}


else if(81 <= x && x < 91){

    printf("\n BA \n");
}


else if(71 <= x && x < 81){

    printf("\n BB \n");
}


else if(61 <= x && x < 71){

    printf("\n CB \n");
}


else if(51 <= x && x < 61){

    printf("\n CC \n");
}

else if(41 <= x && x < 51){

    printf("\n CD \n");
}


else if(36 <= x && x < 41){

    printf("\n DD \n");
}


else if(31 <= x && x < 36){

    printf("\n DF \n");
}


else if(0 <= x && x <  31){

    printf("\n FF \n");
}

else{
    printf("Error Try Again");
}







    return 0;
}
