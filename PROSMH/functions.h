#include <stdio.h>
#include <string.h>
typedef struct recipe {
  char partyname[20];
  char partytype[20];
  int wirenumber;
  char iplikaskthat[20];
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
  file= fopen("output", "ab");
  if(file != NULL){
    fwrite(&frecipe, sizeof(struct recipe), 1, file);
    fclose(file);
  }
}

void print_struct(recipe frecipe, FILE *file){
  printf ("Party Name -> %s \nParty Type -> %s\nWire Number -> %d\nIplikaskthat -> %s\nYarn Type -> %s\n", frecipe.partyname,
  frecipe.partytype, frecipe.wirenumber, frecipe.iplikaskthat, frecipe.yarntype);
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
  printf("[6] Exit\n");
}

void list_recipes(FILE *file){
  recipe frecipe;
  file = fopen("output", "rb");
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
  file = fopen("output", "rb");
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
  file = fopen("output", "rb");
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
      file = fopen("output", "ab");
      strcpy(frecipe.partyname, party_name);
      printf("\nPlease enter the party type of recipe\n");
      scanf("%s", party_type);
      strcpy(frecipe.partytype, party_name);
      printf("\nPlease enter the Wire Number\n");
      scanf("%d", &wire_number);
      frecipe.wirenumber = wire_number;
      printf("\nPlease enter the iplikaskthat of recipe\n");
      scanf("%s", iplikask_that);
      strcpy(frecipe.iplikaskthat, iplikask_that);
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
      fclose(file);
    }
}

void engine(FILE *file){
  int i = 0;
  for(i != 6 ; ;){
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
    }
    else if(i == 5){
      //Edit a Recipe
    }
    else if(i == 6){
      printf("\nGoodbye");
    }
    else{
      printf("\nPlease Try Again\n");
    }
  }
}
