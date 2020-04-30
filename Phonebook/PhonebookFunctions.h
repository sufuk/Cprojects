
#include<stdio.h>
#include<string.h>
typedef struct contact{
  char name[99];
  char number[50];


}con;



////////////////////

void listcontact(){


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
  fputc("\n", filepointer);
  printf("\nPlease enter the phone number of person\n");
  scanf("%s", personnumber);
  strcpy(mycontact.number, personnumber);
  fputs(mycontact.number, file_pointer);
  fclose(file_pointer);
}
