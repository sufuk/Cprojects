#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){


  srand(time(NULL));
  int x;
  int i;
  int a;
  x = 100 * (rand() / RAND_MAX);
  printf("a")
  for(i = 0 ; a != x ; ){
    printf("Please enter a number\n");
    scanf("%d", &a);
    if(a == x){
      printf("You Won yourscore is %d \n", i);
    }
    if(a < x){
      printf("\n Go UP \n");
      i++;
    }
    if(a > x){
      printf("\nGo DOWN\n");
      i++;
    }

  }













  return 0;

}
