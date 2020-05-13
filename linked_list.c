#include <stdio.h>
#include <stdlib.h>
/*
Semih Ufuk Güler
200011674
*/
struct node{
	int data;
	struct node* next;
};
int print_list(struct node* n){
	printf("head ->");
	while(n != NULL){
		printf("%d->", n->data);
		n = n->next;
	}
	printf(" NULL\n\n");
	return 0;
}
int listlen(struct node* n){ // I created but not used, Firs I
	//think it can be handy but Then I realized  I dont need it
	int i = 0;
	while(n!=NULL){
        i++;
        n=n->next;
  }
  return i;
}
int position_finder(struct node* n, int y){
	int x;
	int i = 0;
	while(n != NULL){
		if((n->data) != y){
			i++;
		}
		else if((n->data) == y){
			x = i;
			break;
		}
		n = n->next;
	}
	return x;
}
void add_end(struct node *head, int val) {
    while(head->next != NULL) {
        head = head->next;
    }
    head->next = (struct node*) malloc(sizeof(struct node*));
    head->next->data = val;
    head->next->next = NULL;
}
int main(){
	struct node* head = NULL;
	printf("Before adding we have:\n");
	print_list(head);
	struct node* n = malloc(sizeof(struct node));
	n->data = 100;
	n->next = head;
	head = n;
	printf("after the first node we have:\n");
	print_list(head);
	n = malloc(sizeof(struct node));
	n->data = 200;
	n->next = head;
	head = n;
	printf("after the second node we have:\n");
	print_list(head);
	n = malloc(sizeof(struct node));
	n->data = 300;
	n->next = head;
	head = n;
	printf("after the third node we have:\n");
	print_list(head);
	n = malloc(sizeof(struct node));
	n->data = 400;
	n->next = head;
	head = n;
	printf("after the forth node we have:\n");
	print_list(head);
	int z = position_finder(head, 100);
	printf("\nThe position of 100 is: %d\n\n", z);
	add_end(head, 354);
	print_list(head);
}
