
#include<stdio.h>
#include<string.h>
typedef struct contact{
  char name[99];
  char number[99];


}con;



////////////////////

void listcontact(){


}

///////////////


void addcontact(FILE *file_pointer){

  file_pointer = fopen("Contacts.txt", "w");
  printf("Please enter the name of person\n");
  char personname[99];
  for(; 0 < strlen(personname) ;){

    gets(personname);
    fputs(personname, file_pointer);


}
}
