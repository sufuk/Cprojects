#include <stdio.h>
//#include "functions.h"
#include <stdlib.h>
int a; // simulation triggerer

void machinespeed_bar(int machinespeed){
  if(machinespeed <= 0){


    

  }


}
void temprature_bar(int temprature){
  if(temprature < 0){//Below the thermos
    printf("  _________\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |_______|\n");
  }
  else if(temprature < 10){//Little higher
    printf("  _________\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |#######|\n");

  }
  else if(temprature < 20){//Little higher
    printf("  _________\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |#######|\n");
    printf("  |#######|\n");

  }
  else if(temprature < 30){//Little higher
    printf("  _________\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");

  }
  else if(temprature < 40){//Little higher
    printf("  _________\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
  }
  else if(temprature < 50){//Little higher
    printf("  _________\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
  }
  else if(temprature < 60){//Little higher
    printf("  _________\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
  }
  else if(temprature < 70){//Little higher
    printf("  _________\n");
    printf("  |       |\n");
    printf("  |       |\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
  }
  else if(temprature < 80){//Little higher
    printf("  _________\n");
    printf("  |       |\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
  }
  else if(temprature < 90){//Little higher
    printf("  _________\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
  }
  else if(temprature < 100){//Little higher
    printf("  _#######_\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
    printf("  |#######|\n");
  }
}


/*

void mainmenu(FILE *file){
while(1){
  char recipename[20];
  char simname[20];
  printf("________________RECIPE__SIMULATOR_____________");
  printf("\n\n");
  printf("[1]List Recipes\n");
  printf("[2]Select A Recipe\n");
  printf("[3]Start Simulation\n");
  int x, y;
  scanf("%d", &x);
  if(x == 1){
  //  list_recipes(file);
  }
  else if(x == 2){
    printf("please enter the recipe party name\n");
    scanf("%s", recipename);
    recipe frecipe;
    file = fopen("output.bin", "rb");
    printf("\n Recipe named %s is:\n", recipename);
    while(!feof(file)){
      if(!fread(&frecipe, sizeof(recipe), 1, file)){
        break;
      }
      if(strcmp(frecipe.partyname, recipename) == 0){
        //print_struct(frecipe, file);
        //temprature_bar(frecipe.tub1temprature);
        a = 1;
        printf("\n");
      }
    }
    if(y == 1){//  Select the recipe
      a = 1;
    }
    else if(y == 0){
      printf("Try Again\n");
      a = 0;
    }
  fclose(file);
  }
   if(x == 3){//Simulation
    if(a == 1){// Simulation Start
      int i = 1;
      while(i == 1){

        }
    }
    else if(a == 0){//Select Recipe Again
      printf("Please Select Recipe Again\n");
    }
    else{
      printf("!! System ERROR\n\n");
    }

  }
  }
}
*/
