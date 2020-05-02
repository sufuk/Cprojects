#include<stdio.h>
#include<stdlib.h>
// You can also find in my github repository:
// https://github.com/sufuk/Cprojects
int main(){
int *p;
int i;
int a;
int sum = 0;
printf("Please enter the number of elements\n");
scanf("%d", &a);
p = (int*)malloc(a * sizeof(int));
for(i = 0; i < a ; i++){
  printf("Please enter the number [%d]\n", i+1);
  scanf("%d", &p[i]);
  sum += p[i];
}
printf("Sum of elements are :%d", sum);
free(p);
  return 0;
}
