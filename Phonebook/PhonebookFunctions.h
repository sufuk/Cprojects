
#include<stdio.h>
#include<string.h>
typedef struct contact{
  char name[10];
  char number[15];
}con;
void menu(){
  printf("\nMENU\n");
  printf("[1] List Contacts\n");
  printf("[2] Search a Contact\n");
  printf("[3] Add a Contact\n");
  printf("[4] Remove a Contact\n");
  printf("[5] To edit a Contact\n");
  printf("[6] Exit\n");
}
//               LIST CONTACTS
void listcontact(FILE *file_pointer){
  con person2;
  file_pointer = fopen("Contacts.txt", "r");
  while(!feof(file_pointer)){
    if(!fread(&person2, sizeof(con), 1, file_pointer)){
      break;
    }
    printf("%s  %s", person2.name, person2.number);
    printf("\n");
  }
    fclose(file_pointer);
}
//               ADD CONTACT
void addcontact(FILE *file_pointer){
  printf("\nPlease enter the name of person\n");
  char personname[10];
  char personnumber[99];
  con person2;
  int i = 1;
  scanf("%s", personname);
  file_pointer = fopen("Contacts.txt", "r");
  while(!feof(file_pointer)){
    if(!fread(&person2, sizeof(con), 1, file_pointer)){
      break;
    }

      if(strcmp(person2.name, personname) == 0){
        i = 0;
      }

      }

    fclose(file_pointer);
    if(i == 0){
      printf("\nPerson already exists try again\n");
    }
    if(i != 0){
      file_pointer = fopen("Contacts.txt", "a");
      strcpy(person2.name, personname);
      printf("\nPlease enter the phone number of person\n");
      scanf("%s", personnumber);
      strcpy(person2.number, personnumber);
      fwrite(&person2, sizeof(con), 1, file_pointer);
      fclose(file_pointer);
    }
}
//           SEARCH CONTACT
void searchcontact(FILE *file_pointer){
  con person2;
  file_pointer = fopen("Contacts.txt", "r");
  printf("\nEnter the contact's name please\n");
  char personname[50];
  scanf("%s", personname);
  printf("\n Contacts named %s are:\n", personname);
  while(!feof(file_pointer)){
    if(!fread(&person2, sizeof(con), 1, file_pointer)){
      break;
    }
    if(strcmp(person2.name, personname) == 0){
      printf("%s  %s", person2.name, person2.number);
      printf("\n");
    }
  }
  fclose(file_pointer);
}
//         EDIT CONTACT
void editcontact(FILE *file_pointer){

}
