#include <stdio.h>
#include <string.h>
#include "functions.h"
int main(){


recipe my_recipe1;


strcpy(my_recipe1.partyname, "Sufuk");
strcpy(my_recipe1.partytype, "Sucker");
my_recipe1.wirenumber = 10;
strcpy(my_recipe1.iplikaskthat, "3/5");
strcpy(my_recipe1.yarntype, "Coton");
my_recipe1.tub1tension = 20;
my_recipe1.tub1temprature = 32;
my_recipe1.tub1elangationrate = 1.5343;

my_recipe1.tub2tension = 20;
my_recipe1.tub2temprature = 32;
my_recipe1.tub2elangationrate = 1.5343;

my_recipe1.machine_speed = 20;

recipe my_recipe2;


strcpy(my_recipe2.partyname, "Cigdem");
strcpy(my_recipe2.partytype, "Sucker");
my_recipe2.wirenumber = 10;
strcpy(my_recipe2.iplikaskthat, "3/5");
strcpy(my_recipe2.yarntype, "Coton");
my_recipe2.tub1tension = 20;
my_recipe2.tub1temprature = 32;
my_recipe2.tub1elangationrate = 1.5343;

my_recipe2.tub2tension = 20;
my_recipe2.tub2temprature = 32;
my_recipe2.tub2elangationrate = 1.5343;

my_recipe2.machine_speed = 20;

FILE *file;

write_struct(my_recipe1, file);
//print_struct(my_recipe1, file);
write_struct(my_recipe2, file);
//print_struct(my_recipe2, file);
engine(file);


  return 0;
}
