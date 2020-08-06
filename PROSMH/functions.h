#include <stdio.h>
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
  file= fopen("output", "wb");
  if(file != NULL){
    fwrite(&frecipe, sizeof(struct recipe), 1, file);
    fclose(file);
  }
}

void print_struct(recipe frecipe, FILE *file){
  file = fopen("output", "rb");
  fread(&frecipe, sizeof(struct recipe), 1, file);
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
void list_recipes(recipe frecipe, FILE *file){
  fread(&frecipe, sizeof(struct recipe), 1, file);
}
void engine(){
  int i = 0;
  for(i != 6 ; ;){
    menu();
    printf("Please Select a function\n");
    scanf("%d", &i);
    if(i == 1){
      //List Recipes
    }
    else if(i == 2){
      //Search a Recipe
    }
    else if(i == 3){
      //Add a Recipe
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
