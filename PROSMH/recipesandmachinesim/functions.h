#include <stdio.h>
#include <string.h>
#include "simulation.h"
typedef struct recipe {
  char partyname[20];
  char partytype[20];
  int wirenumber;
  char yarnNE[20];
  char yarntype[20];

  int tub1tension;
  int tub1temprature;
  double tub1elangationrate;

  int tub2tension;
  int tub2temprature;
  double tub2elangationrate;

  int machine_speed;
}recipe;
void write_struct(recipe frecipe, FILE *file){
  file= fopen("output.bin", "ab");
  if(file != NULL){
    fwrite(&frecipe, sizeof(struct recipe), 1, file);
    fclose(file);
  }
}

void print_struct(recipe frecipe, FILE *file){
  printf ("Party Name -> %s \nParty Type -> %s\nWire Number -> %d\nyarnNE -> %s\nYarn Type -> %s\n", frecipe.partyname,
  frecipe.partytype, frecipe.wirenumber, frecipe.yarnNE, frecipe.yarntype);
  printf("Tub 1 Tension -> %d\nTub 1 Temprature -> %d\nTube 1 Elangation Rate -> %lf\n", frecipe.tub1tension,
  frecipe.tub1temprature, frecipe.tub1elangationrate );
  printf("Tub 2 Tension -> %d\nTub 2 Temprature -> %d\nTube 2 Elangation Rate -> %lf\n", frecipe.tub2tension,
  frecipe.tub2temprature, frecipe.tub2elangationrate);
  printf("Machine Speed -> %d\n\n", frecipe.machine_speed);
  fclose(file);
}

void menu(){
  printf("\nMENU\n");
  printf("[1] List Recipes\n");
  printf("[2] Search a Recipe\n");
  printf("[3] Add a Recipe\n");
  printf("[4] Remove a Recipe\n");
  printf("[5] Edit a Recipe\n");
  printf("[6] Simulation\n");
  printf("[7] Exit\n");
}

void list_recipes(FILE *file){
  recipe frecipe;
  file = fopen("output.bin", "rb");
  int a = 1;
  while(!feof(file)){
    if(!fread(&frecipe, sizeof(recipe), 1, file)){
      break;
    }
    printf("[%d]  %s", a, frecipe.partyname);
    printf("\n");
    a++;
  }
    fclose(file);
}
void search_recipe(FILE *file){
  recipe frecipe;
  file = fopen("output.bin", "rb");
  printf("\nEnter the Recipe's name please\n");
  char recipename[10];
  scanf("%s", recipename);
  printf("\n Recipe named %s is:\n", recipename);
  while(!feof(file)){
    if(!fread(&frecipe, sizeof(recipe), 1, file)){
      break;
    }
    if(strcmp(frecipe.partyname, recipename) == 0){
      print_struct(frecipe, file);
      printf("\n");
    }
  }
  fclose(file);
}
void add_recipe(FILE *file){
  printf("\nPlease enter a Name for Recipe\n");
  char party_name[20];
  char party_type[20];
  int wire_number;
  char iplikask_that[20];
  char yarn_type[20];

  int tub1_tension;
  int tub1_temprature;
  double tub1_elangationrate;

  int tub2_tension;
  int tub2_temprature;
  double tub2_elangationrate;

  int _machine_speed;
  recipe frecipe;
  int i = 1;
  scanf("%s", party_name);
  file = fopen("output.bin", "rb");
  while(!feof(file)){
    if(!fread(&frecipe, sizeof(recipe), 1, file)){
      break;
    }
      if(strcmp(frecipe.partyname, party_name) == 0){
        i = 0;
      }
      }
    fclose(file);
    if(i == 0){
      printf("\nRecipe name already exists try again\n");
    }
    if(i != 0){
      file = fopen("output.bin", "ab");
      strcpy(frecipe.partyname, party_name);
      printf("\nPlease enter the party type of recipe\n");
      scanf("%s", party_type);
      strcpy(frecipe.partytype, party_type);
      printf("\nPlease enter the Wire Number\n");
      scanf("%d", &wire_number);
      frecipe.wirenumber = wire_number;
      printf("\nPlease enter the yarnNE of recipe\n");
      scanf("%s", iplikask_that);
      strcpy(frecipe.yarnNE, iplikask_that);
      printf("\nPlease enter the yarn type of recipe\n");
      scanf("%s", yarn_type);
      strcpy(frecipe.yarntype, yarn_type);

      printf("\nPlease enter the Tub 1 Tension \n");
      scanf("%d", &tub1_tension);
      frecipe.tub1tension = tub1_tension;
      printf("\nPlease enter the Tub 1 Temprature \n");
      scanf("%d", &tub1_temprature);
      frecipe.tub1temprature = tub1_temprature;
      printf("\nPlease enter the Tub 1 Elangation Rate \n");
      scanf("%lf", &tub1_elangationrate);
      frecipe.tub1elangationrate = tub1_elangationrate;

      printf("\nPlease enter the Tub 2 Tension \n");
      scanf("%d", &tub2_tension);
      frecipe.tub2tension = tub2_tension;
      printf("\nPlease enter the Tub 2 Temprature \n");
      scanf("%d", &tub2_temprature);
      frecipe.tub2temprature = tub2_temprature;
      printf("\nPlease enter the Tub 2 Elangation Rate \n");
      scanf("%lf", &tub2_elangationrate);
      frecipe.tub2elangationrate = tub2_elangationrate;
      fwrite(&frecipe, sizeof(recipe), 1, file);
      printf("\nPlease enter the Machine Speed \n");
      scanf("%d", &_machine_speed);
      frecipe.machine_speed = _machine_speed;
      fclose(file);
    }
    fclose(file);
}
void remove_recipe(FILE *file){
  recipe frecipe;
  printf("\n Please enter the name of recipe you wanna delete \n");
  char party_name[10];
  scanf("%s", party_name);
  FILE *tmpf;
  tmpf = fopen("tmp", "wb");
  file = fopen("output.bin", "rb");
  while(fread(&frecipe, sizeof(recipe), 1, file)==1)
       {
           if(strcmp(frecipe.partyname, party_name) != 0){
               fwrite(&frecipe, sizeof(recipe), 1, tmpf);
                }
       }
       fclose(file);
       fclose(tmpf);
       remove("output.bin");
       rename("tmp", "output.bin");
       printf("recipe removed sucsessfully\n");

}
void clean_all(FILE *file){ //TODO
  file = fopen("output.bin", "w");
  fclose(file);
}
void submenuedit(){
  printf("\n[1] for changing Party Name");
  printf("\n[2] for changing Party Type");
  printf("\n[3] for changing Wire Number");
  printf("\n[4] for changing yarnNE");
  printf("\n[5] for changing Yarn Type");
  printf("\n[6] for changing Tub 1 Tension");
  printf("\n[7] for changing Tub 1 Temprature");
  printf("\n[8] for changing Tub 1 Elangation");
  printf("\n[9] for changing Tub 2 Tension");
  printf("\n[10] for changing Tub 2 Temprature");
  printf("\n[11] for changing Tub 2 Elangaiton");
  printf("\n[12] for changing Machine Speed");
  printf("\n[13] to exit\n");
}
void edit_recipe(FILE *file){
printf("\nEnter the name of recipe please\n");
  char party_name[20];
  char party_name_new[20];
  char party_type_new[20];
  int  wire_number_new;
  char iplikask_that_new[20];
  char yarn_type_new[20];
  int  tub1_tension_new;
  int  tub1_temprature_new;
  double  tub1_elangationrate_new;
  int  tub2_tension_new;
  int  tub2_temprature_new;
  double  tub2_elangationrate_new;
  int _machine_speed_new;
  scanf("%s", party_name);
  recipe frecipe;
  int i;
  int a;
  file = fopen("output.bin", "rb+");
  while(!feof(file)){
    if(!fread(&frecipe, sizeof(recipe), 1, file)){
      break;
    }
      if(strcmp(frecipe.partyname, party_name) == 0){
        i = 0;
        break;
      }
      }
    if(i != 0){
      printf("\nRecipe could not found try again \n");
    }
    if(i == 0){
      printf("You are editing %s\n ", frecipe.partyname);
      while(a != 13){
        submenuedit();
        scanf("%d", &a);
        if(a == 1){
          printf("\n Enter the new Party Name please\n");
          scanf("%s", party_name_new);
          strcpy(frecipe.partyname, party_name_new);
          printf("Party Name changed succesfully!\n");
        }
        if(a == 2){
          printf("\n Enter the new party type please\n");
          scanf("%s", party_type_new);
          strcpy(frecipe.partytype, party_type_new);
          printf("Party Type updated sucsessfully\n");
        }
        if(a == 3){
          printf("\n Enter the new Wire Number please\n");
          scanf("%d", wire_number_new);
          frecipe.wirenumber = wire_number_new;
          printf("Wire Number updated sucsessfully\n");
        }
        if(a == 4){
          printf("Please Enter The new yarnNE Please\n");
          scanf("%s", iplikask_that_new);
          strcpy(frecipe.yarnNE, iplikask_that_new);
          printf("yarnNE updated sucsessfully\n");
        }
        if(a == 5){
          printf("Please Enter The new Yarn Type Please\n");
          scanf("%s", yarn_type_new);
          strcpy(frecipe.yarntype, yarn_type_new);
          printf("Yarn type updated sucsessfully\n");
        }
        if(a == 6){
          printf("\n Enter the new Tub 1 Tension please\n");
          scanf("%d", tub1_tension_new);
          frecipe.tub1tension = tub1_tension_new;
          printf("Tub 1 Tension updated sucsessfully\n");
        }
        if(a == 7){
          printf("\n Enter the new Tub 1 Temprature please\n");
          scanf("%d", tub1_temprature_new);
          frecipe.tub1temprature = tub1_temprature_new;
          printf("Tub 1 Temprature updated sucsessfully\n");
        }
        if(a == 8){
          printf("\n Enter the new Tub 1 Elangaiton Rate please\n");
          scanf("%lf", tub1_elangationrate_new);
          frecipe.tub1elangationrate = tub1_elangationrate_new;
          printf("Tub 1 Elangaiton Rate updated sucsessfully\n");
        }
        if(a == 9){
          printf("\n Enter the new Tub 2 Tension please\n");
          scanf("%d", tub2_tension_new);
          frecipe.tub2tension = tub2_tension_new;
          printf("Tub 2 Tension updated sucsessfully\n");
        }
        if(a == 10){
          printf("\n Enter the new Tub 2 Temprature please\n");
          scanf("%d", tub2_temprature_new);
          frecipe.tub2temprature = tub2_temprature_new;
          printf("Tub 2 Temprature updated sucsessfully\n");
        }
        if(a == 11){
          printf("\n Enter the new Tub 2 Elangaiton Rate please\n");
          scanf("%lf", tub2_elangationrate_new);
          frecipe.tub2elangationrate = tub2_elangationrate_new;
          printf("Tub 2 Elangaiton Rate updated sucsessfully\n");
        }
        if(a == 12){
          printf("\n Enter the new Machine Speed please\n");
          scanf("%d", _machine_speed_new);
          frecipe.machine_speed = _machine_speed_new;
          printf("Machine Speed updated sucsessfully\n");
        }
      }
      fseek(file, -sizeof(recipe), SEEK_CUR);
      fwrite(&frecipe, sizeof(recipe), 1, file);

    }
    fclose(file);
}
void submenusim(){
  printf("[1]Select a Recipe\n");
  printf("[2]Start Simulation\n");
  printf("[3]Reset\n");
  printf("[4]Exit\n");
}
/*void recipeselect(FILE *file){
  int i;
  char party_name[20];
  char party_type[20];
  int wire_number;
  char iplikask_that[20];
  char yarn_type[20];

  int tub1_tension;
  int tub1_temprature;
  double tub1_elangationrate;

  int tub2_tension;
  int tub2_temprature;
  double tub2_elangationrate;
  int _machine_speed;
  printf("Please Enter The recipe Party Name\n");
  scanf("%s", party_name);
  recipe frecipe;
  file = fopen("output.bin", "rb+");
  while(!feof(file)){
    if(!fread(&frecipe, sizeof(recipe), 1, file)){
      break;
    }
      if(strcmp(frecipe.partyname, party_name) == 0){
        i = 0;
        break;
      }
      }
    if(i != 0){
      printf("\nRecipe could not found try again \n");
    }
    if(i == 0){
      printf("You are gonna simulate %s\n ", frecipe.partyname);
      strcpy(party_type, frecipe.partytype);
      wire_number = frecipe.wirenumber;
      strcpy(iplikask_that, frecipe.yarnNE);
      strcpy(yarn_type, frecipe.yarntype);
      tub1_tension = frecipe.tub1tension;
      tub1_temprature = frecipe.tub1temprature;
      tub1_elangationrate = frecipe.tub1elangationrate;
      tub2_tension = frecipe.tub2tension;
      tub2_temprature = frecipe.tub2temprature;
      tub2_elangationrate = frecipe.tub2elangationrate;
      _machine_speed = frecipe.machine_speed;

    }

}*/
void engine(FILE *file){
  int i = 0;
  while(i != 7){
    menu();
    printf("Please Select a function\n");
    scanf("%d", &i);
    if(i == 1){
      //List Recipes
      list_recipes(file);
    }
    else if(i == 2){
      //Search a Recipe
      search_recipe(file);
    }
    else if(i == 3){
      //Add a Recipe
      add_recipe(file);
    }
    else if(i == 4){
      //Remove a Recipe
      remove_recipe(file);
    }
    else if(i == 5){
      //Edit a Recipe
      edit_recipe(file);
    }
    else if(i == 6){//Simulation
      char party_name[20];
      char party_type[20];
      int wire_number;
      char iplikask_that[20];
      char yarn_type[20];

      int tub1_tension;
      int tub1_temprature;
      double tub1_elangationrate;

      int tub2_tension;
      int tub2_temprature;
      double tub2_elangationrate;
      int _machine_speed;
      submenusim();
      int p;
      scanf("%d", &p);
      if(p == 1){// Select a recipe
        int i;
        printf("Please Enter The recipe Party Name\n");
        scanf("%s", party_name);
        recipe frecipe;
        file = fopen("output.bin", "rb+");
        while(!feof(file)){
          if(!fread(&frecipe, sizeof(recipe), 1, file)){
            break;
          }
            if(strcmp(frecipe.partyname, party_name) == 0){
              i = 0;
              break;
            }
            }
          if(i != 0){
            printf("\nRecipe could not found try again \n");
          }
          if(i == 0){
            printf("You are gonna simulate %s\n ", frecipe.partyname);
            strcpy(party_type, frecipe.partytype);
            wire_number = frecipe.wirenumber;
            strcpy(iplikask_that, frecipe.yarnNE);
            strcpy(yarn_type, frecipe.yarntype);
            tub1_tension = frecipe.tub1tension;
            tub1_temprature = frecipe.tub1temprature;
            tub1_elangationrate = frecipe.tub1elangationrate;
            tub2_tension = frecipe.tub2tension;
            tub2_temprature = frecipe.tub2temprature;
            tub2_elangationrate = frecipe.tub2elangationrate;
            _machine_speed = frecipe.machine_speed;

          }

      }
      if(p == 2){// start Simulation
      
      }
      else if(p == 3){

      }// Reset Recipe
      else if(p == 4){// exit
        break;
      }
    }

    else if(i == 7){
      break;
    }
    else{
      printf("\nPlease Try Again\n");
    }
  }
}
