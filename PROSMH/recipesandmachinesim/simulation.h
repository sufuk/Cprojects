#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void machinespeed_bar0(){
  printf("                  90    100             \n");
  printf("             80              110        \n");
  printf("                                        \n");
  printf("         70                      120    \n");
  printf("                                        \n");
  printf("       60                          130  \n");
  printf("                      OO                \n");
  printf("       50             OO          140   \n");
  printf("                      |                 \n");
  printf("        40            |          150    \n");
  printf("                      |                 \n");
  printf("           30         |        160      \n");
}
void machinespeed_bar30(){
  printf("                  90    100             \n");
  printf("             80              110        \n");
  printf("                                        \n");
  printf("         70                      120    \n");
  printf("                                        \n");
  printf("       60                          130  \n");
  printf("                     OO                 \n");
  printf("       50            OO           140   \n");
  printf("                   /                    \n");
  printf("                 /                      \n");
  printf("        40     /                 150    \n");
  printf("             /                          \n");
  printf("           30                  160      \n");
}
void machinespeed_bar40(){
  printf("                  90    100             \n");
  printf("             80              110        \n");
  printf("                                        \n");
  printf("         70                      120    \n");
  printf("                                        \n");
  printf("       60                          130  \n");
  printf("                     OO                 \n");
  printf("       50            OO           140   \n");
  printf("                   %                    \n");
  printf("                %                       \n");
  printf("           40                    150     \n");
  printf("                                        \n");
  printf("              30             160      \n");
}
void machinespeed_bar50(){
  printf("                  90    100             \n");
  printf("             80              110        \n");
  printf("                                        \n");
  printf("         70                      120    \n");
  printf("                                        \n");
  printf("       60                          130  \n");
  printf("                      OO                \n");
  printf("       50+++++++++++++OO          140   \n");
  printf("                                        \n");
  printf("        40                       150    \n");
  printf("                                        \n");
  printf("           30                  160      \n");
}
void machinespeed_bar60(){
  printf("                  90    100             \n");
  printf("             80              110        \n");
  printf("                                        \n");
  printf("         70                      120    \n");
  printf("                                        \n");
  printf("       60                          130  \n");
  printf("           #                            \n");
  printf("               ^   _                    \n");
  printf("                     %OO                \n");
  printf("       50             OO          140   \n");
  printf("                                        \n");
  printf("        40                       150    \n");
  printf("                                        \n");
  printf("           30                  160      \n");
}
void machinespeed_bar70(){
  printf("                  90    100             \n");
  printf("             80              110        \n");
  printf("                                        \n");
  printf("         70                      120    \n");
  printf("            ^                           \n");
  printf("       60     ^                    130  \n");
  printf("                ^                       \n");
  printf("                  ^                     \n");
  printf("                    ^ OO                \n");
  printf("       50             OO          140   \n");
  printf("                                        \n");
  printf("        40                       150    \n");
  printf("                                        \n");
  printf("           30                  160      \n");
}
void machinespeed_bar80(){
  printf("                  90    100             \n");
  printf("             80              110        \n");
  printf("               ^                        \n");
  printf("         70     ^                120    \n");
  printf("                 ^                      \n");
  printf("       60         ^                130  \n");
  printf("                   ^                    \n");
  printf("                    ^                   \n");
  printf("                      OO                \n");
  printf("       50             OO          140   \n");
  printf("                                        \n");
  printf("        40                       150    \n");
  printf("                                        \n");
  printf("           30                  160      \n");
}
void machinespeed_bar90(){
  printf("                  90    100             \n");
  printf("             80   |         110         \n");
  printf("         70        |            120     \n");
  printf("                    |                   \n");
  printf("       60            |              130 \n");
  printf("                      |                 \n");
  printf("                       |                \n");
  printf("                      OO                \n");
  printf("       50             OO          140   \n");
  printf("                                        \n");
  printf("        40                       150    \n");
  printf("                                        \n");
  printf("           30                  160      \n");
}
void machinespeed_bar100(){
  printf("                  90    100             \n");
  printf("             80           |  110        \n");
  printf("         70              |       120    \n");
  printf("       60               |          130  \n");
  printf("                       |                \n");
  printf("                      OO                \n");
  printf("       50             OO          140   \n");
  printf("                                        \n");
  printf("        40                       150    \n");
  printf("                                        \n");
  printf("           30                  160      \n");
}

void machinespeed_bar(int speed){
  if(speed <= 0){
    machinespeed_bar0();
  }
  else if(speed <= 30){
    machinespeed_bar30();
  }
  else if(speed <= 40){
    machinespeed_bar40();
  }
  else if(speed <= 50){
    machinespeed_bar50();
  }
  else if(speed <= 60){
    machinespeed_bar60();
  }
  else if(speed <= 70){
    machinespeed_bar70();
  }
  else if(speed <= 80){
    machinespeed_bar80();
  }
  else if(speed <= 90){
    machinespeed_bar90();
  }
  else if(speed <= 100){
    machinespeed_bar100();
  }
}
void temprature_bar0(){
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
void temprature_bar10(){
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

void temprature_bar20(){
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

void temprature_bar30(){
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

void temprature_bar40(){
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
void temprature_bar50(){
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
void temprature_bar60(){
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
void temprature_bar70(){
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
void temprature_bar80(){
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
void temprature_bar90(){
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
void temprature_bar100(){
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
void temprature_bar(int temprature){
  if(temprature < 0){//Below the thermos
    temprature_bar0;
  }
  else if(temprature < 10){//Little higher
    temprature_bar10;

  }
  else if(temprature < 20){//Little higher
    temprature_bar20();

  }
  else if(temprature < 30){//Little higher
    temprature_bar30();

  }
  else if(temprature < 40){//Little higher
    temprature_bar40();
  }
  else if(temprature < 50){//Little higher
    temprature_bar50();
  }
  else if(temprature < 60){//Little higher
    temprature_bar60();
  }
  else if(temprature < 70){//Little higher
    temprature_bar70();
  }
  else if(temprature < 80){//Little higher
    temprature_bar80();
  }
  else if(temprature < 90){//Little higher
    temprature_bar90();
  }
  else if(temprature < 100){//Little higher
    temprature_bar100();
  }
}
void simulationscreen(int machinespeed, int temprature){

  temprature_bar(temprature);





}
