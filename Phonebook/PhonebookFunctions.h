
#include<stdio.h>
#include<string.h>
typedef struct contact{
  char name[99];
  char number[50];


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

  file_pointer = fopen("Contacts.txt", "r");
  char c;
  for(c ; file_pointer != NULL && c != EOF ;){
    c = fgetc(file_pointer);
    printf("%c", c);

  }

  fclose(file_pointer);

}

///////////////


void addcontact(FILE *file_pointer){

  file_pointer = fopen("Contacts.txt", "a");
  printf("\nPlease enter the name of person\n");

  char personname[99];
  char personnumber[50];
  con mycontact;

  scanf("%s", personname);
  strcpy(mycontact.name, personname);
  fputs(mycontact.name, file_pointer);
  fputs("  ", file_pointer);
  printf("\nPlease enter the phone number of person\n");
  scanf("%s", personnumber);
  strcpy(mycontact.number, personnumber);
  fputs(mycontact.number, file_pointer);
  fputs("\n", file_pointer);
  fclose(file_pointer);
}
