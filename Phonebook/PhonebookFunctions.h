
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
  con person;
  file_pointer = fopen("Contacts.txt", "r");
  while(!feof(file_pointer)){
    if(!fread(&person, sizeof(con), 1, file_pointer)){
      break;
    }
    printf("%s  %s", person.name, person.number);
    printf("\n");
  }
    fclose(file_pointer);
}
//               ADD CONTACT
void addcontact(FILE *file_pointer){
  printf("\nPlease enter the name of person\n");
  char personname[10];
  char personnumber[99];
  con person;
  int i = 1;
  scanf("%s", personname);
  file_pointer = fopen("Contacts.txt", "r");
  while(!feof(file_pointer)){
    if(!fread(&person, sizeof(con), 1, file_pointer)){
      break;
    }

      if(strcmp(person.name, personname) == 0){
        i = 0;
      }

      }

    fclose(file_pointer);
    if(i == 0){
      printf("\nPerson already exists try again\n");
    }
    if(i != 0){
      file_pointer = fopen("Contacts.txt", "a");
      strcpy(person.name, personname);
      printf("\nPlease enter the phone number of person\n");
      scanf("%s", personnumber);
      strcpy(person.number, personnumber);
      fwrite(&person, sizeof(con), 1, file_pointer);
    //  fputs("\n", file_pointer);
      fclose(file_pointer);
    }
}
//           SEARCH CONTACT
void searchcontact(FILE *file_pointer){
  con person;
  file_pointer = fopen("Contacts.txt", "r");
  printf("\nEnter the contact's name please\n");
  char personname[50];
  scanf("%s", personname);
  printf("\n Contacts named %s are:\n", personname);
  while(!feof(file_pointer)){
    if(!fread(&person, sizeof(con), 1, file_pointer)){
      break;
    }
    if(strcmp(person.name, personname) == 0){
      printf("%s  %s", person.name, person.number);
      printf("\n");
    }
  }
  fclose(file_pointer);
}
//         EDIT CONTACT
void submenuedit(){
  printf("\n[1] for changing name");
  printf("\n[2] for changing number");
  printf("\n[3] to exit\n");
}
void editcontact(FILE *file_pointer){
printf("\nEnter the name of contact please\n");
  char personname[15];
  char newname[15];
  char newnumber[15];
  scanf("%s", personname);
  con person;
  int i;
  int a;
  file_pointer = fopen("Contacts.txt", "rb+");
  while(!feof(file_pointer)){
    if(!fread(&person, sizeof(con), 1, file_pointer)){
      break;
    }
      if(strcmp(person.name, personname) == 0){
        i = 0;
        break;
      }
      }
    if(i != 0){
      printf("\nContact not found try again \n");
    }
    if(i == 0){
      printf("You are editing %s\n ", person.name);
      while(a != 3){
        submenuedit();
        scanf("%d", &a);
        if(a == 1){
          printf("\n Enter the new name please\n");
          scanf("%s", newname);
          strcpy(person.name, newname);
          printf("Name changed succesfully!\n");
        }
        if(a == 2){
          printf("\n Enter the new number please\n");
          scanf("%s", newnumber);
          strcpy(person.number, newnumber);
          printf("Number updated sucsessfully\n");
        }

      }
      fseek(file_pointer, -sizeof(person), SEEK_CUR);
      fwrite(&person, sizeof(con), 1, file_pointer);

    }
    fclose(file_pointer);
}
