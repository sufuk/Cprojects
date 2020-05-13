#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};



void printlist(struct Node *n){
  while(n!=NULL){
    printf("%d", n->data);
    n = n->next;
  }
}
int main(){
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;
  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));

  head->data = 1;
  head->next = second;
  second->data = 2;
  second->next = third;
  third->data = 3;
  third->next = NULL;
  printlist(head);

  struct Node* head1 = NULL;
  struct Node* second1 = NULL;
  struct Node* third1 = NULL;

  head1 = (struct Node*)malloc(sizeof(struct Node));
  second1 = (struct Node*)malloc(sizeof(struct Node));
  third1 = (struct Node*)malloc(sizeof(struct Node));

  head1->data = 4;
  head1->next = second1;
  second1->data = 5;
  second1->next = third1;
  third1->data = 6;
  third1->next = head;
  printlist(head1);
  return 0;



}
