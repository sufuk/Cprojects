
#include<stdio.h>
#include<string.h>
typedef struct contact{
  char name[99];
  int number;


}con;


void menu(){
  printf("\nMENU\n");

  printf("[1] List Contacts\n");
  printf("[2] Search a Contact\n");
  printf("[3] Add a Contact\n");
  printf("[4] Remove a Contact\n");
  printf("[5] Exit\n");

}



////////////////////

void listcontact(FILE *file_pointer){
  con person2;
  file_pointer = fopen("Contacts.txt", "r");
  while(!feof(file_pointer)){
    fread(&person2, sizeof(con), 1, file_pointer);
    printf("%s  %d", person2.name, person2.number);
    printf("\n");
  }
    fclose(file_pointer);



}

//////////////


void addcontact(FILE *file_pointer){
  con person1;
  file_pointer = fopen("Contacts.txt", "a");
  printf("\nPlease enter the name of person\n");
  char personname[99];
  scanf("%s", personname);
  strcpy(person1.name, personname);
  printf("\nPlease enter the phone number of person\n");
  scanf("%d", &person1.number);
  fwrite(&person1, sizeof(con), 1, file_pointer);
  //fputs("\n", file_pointer);
  fclose(file_pointer);



}
