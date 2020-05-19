/*
Semih Ufuk Güler
200011674 EEE #2
You can check the writing procces here:
https://github.com/sufuk/BIL132_Programming2/tree/master/projects/Checkers
*/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 8
#define COLUMNS 8
#define BLACK  'B'
#define WHITE 'W'
#define WHITEDAMA '#'
#define BLACKDAMA '$'
#define WHITEWOOD '_'
#define INITIAL_FILE	"board.txt"
char* checkersboard(){
  char *p = malloc(ROWS * COLUMNS);
  memset(p, WHITEWOOD, ROWS * COLUMNS);
  return p;
}
void readboard(char *b){
  int i;
  FILE *f = fopen(INITIAL_FILE, "r");
  if(f == NULL){
    printf("Can not open file %s\n", INITIAL_FILE);
    exit(EXIT_FAILURE);
  }
  for(i=0 ; i < ROWS * COLUMNS ; i++){
    *(b + i) = fgetc(f);
  }
fclose(f);
}
void print_board(char *b){
	int i,j;
	int index = 0;
	for(i=0;i<ROWS;i++){
		for(j=0;j<COLUMNS;j++){
			index = i*COLUMNS + j;
			if(b[index] == BLACK){
				printf("|_@_");
      }
      if(b[index] == WHITE){
        printf("|_O_");
      }
		  if(b[index] == WHITEWOOD){
        printf("|___");
      }
      if(b[index] == WHITEDAMA){
        printf("|_#_");
      }
      if(b[index] == BLACKDAMA){
        printf("|_$_");
      }
    }
		printf("|\n");
	}
}
void destroy_board(char *b){
	free(b);
}
void make_dama(char *b){
  int i;
  int j;
  for(i = 0 ; i < 8 ; i++){
    if(*(b + i) == BLACK){
      *(b + i) = BLACKDAMA;
    }
  }
  for(j = 56; j < 64 ; j++){
    if(*(b + j) == WHITE){
      *(b + j) = WHITEDAMA;
    }
  }
}
int is_valid_move(char *b, int turn, int x0, int y0, int x1, int y1){
  int index0 = (y0 * 8) + x0;
  int n;
  int index1 = (y1 * 8) + x1;
  if(turn == 0){
    if(*(b + index0) == 'W'){
      if(index1 == (index0 + 1)){
      //RIGHT
        if(*(b + index1) != '_'){
          n = 0;
        }
        else if(*(b + index1) == '_'){
          if(index1 % 8 != 0){
          n = 1;
        }
        }
      }
      else if(index1 == (index0 - 1)){
        //LEFT
        if(*(b + index1) != '_'){
          n = 0;
        }
        else if(*(b + index1) == '_'){
          if(index0 % 8 != 0){
            n = 1;
          }
        }
      }
      else if(index1 == (index0  + 8)){
        //FOWARD
        if(*(b + index1) != '_'){
          n = 0;
        }
        else if(*(b + index1) == '_'){
          n = 1;
        }
      }
      else{
        n = 0;
      }
    }
    else if(*(b + index0) == WHITEDAMA){
      if((index0 > index1) && ((index0 - index1) % 8 == 0)){
        //BACKWARD
        if(*(b + index1) == WHITEWOOD){
          int index2;
          int breaker = 0;
          for(index2 = index1 + 8 ; (index2 < index0) && (breaker != 1) ; ){
            if(*(b + index2) != WHITEWOOD){
              n = 0;
              breaker = 1;
            }
            else if(*(b + index2) == WHITEWOOD){
              n = 1;
            }
            index2 += 8;
          }
        }
        else if(*(b + index1) != WHITEWOOD){
          n = 0;
        }
      }
      else if((index1>index0) && ((index0-index1) % 8 == 0)){
        //FOWARD
        if(*(b + index1) == WHITEWOOD){
          int index2;
          int breaker = 0;
          for(index2 = index1 - 8 ; (index2 > index0) && (breaker != 1) ; ){
            if(*(b + index2) != WHITEWOOD){
              n = 0;
              breaker = 1;
            }
            else if(*(b + index2) == WHITEWOOD){
              n = 1;
            }
            index2 -= 8;
          }
        }
        else if(*(b + index1) != WHITEWOOD){
          n = 0;
        }
      }
      else if(index0>index1){
        //LEFT
        if((index0 - index1) >= 8){
          n = 0;
        }
        else if((index0 - index1) < 8){
          int index2;
          if(index0 % 8  == 0){
            n = 0;
          }
          else if(index0 % 8 != 0){
            for(index2 = index0  ; (index2 % 8) != 0 ; ){
              index2 -= 1;
              if(*(b + index2) == WHITEWOOD){
                n = 1;
              }
              else if(*(b + index2) != WHITEWOOD){
                n = 0;
              }
            }
          }
        }
      }
      else if(index1>index0){
        //RIGHT
        if((index1 - index0) >= 8){
          n = 0;
        }
        else if((index1 - index0) < 8){
          int index2;
          if((index0 + 1) % 8  == 0){
            n = 0;
          }
          else if((index0 + 1) % 8 != 0){
            for(index2 = index0  ; ((index2 + 1) % 8) != 0 ; ){
              index2 += 1;
              if(*(b + index2) == WHITEWOOD){
                n = 1;
              }
              else if(*(b + index2) != WHITEWOOD){
                n = 0;
              }
            }
          }
        }
      }

    }
  }
  //BLACK
else if(turn == 1){
    if(*(b + index0) == BLACK){
      if(index1 == (index0 + 1)){
        //RIGHT
        if(*(b + index1) != '_'){
          n = 0;
        }
        else if(*(b + index1) == '_'){
          if(index1 % 8 != 0){
            n = 1;
          }
          else{
            n = 0;
          }
        }
      }
      else if(index1 == (index0 - 1)){
        //LEFT
        if(*(b + index1) != '_'){
          n = 0;
        }
        else if(*(b + index1) == '_'){
          if(index0 % 8 != 0){
            n = 1;
          }
        }
      }
      else if(index1 == (index0 - 8)){
        //FOWARD
        if(*(b + index1) != '_'){
          n = 0;
        }
        else if(*(b + index1) == '_'){
          n = 1;
        }
      }
      else{
        n = 0;
      }
    }
    else if(*(b + index0) == BLACKDAMA){
      if((index0 > index1) && ((index0 - index1) % 8 == 0)){
        //BACKWARD
        if(*(b + index1) == WHITEWOOD){
          int index2;
          int breaker = 0;
          for(index2 = index1 + 8 ; (index2 < index0) && (breaker != 1) ; ){
            if(*(b + index2) != WHITEWOOD){
              n = 0;
              breaker = 1;
            }
            else if(*(b + index2) == WHITEWOOD){
              n = 1;
            }
            index2 += 8;
          }
        }
        else if(*(b + index1) != WHITEWOOD){
          n = 0;
        }
      }
      else if((index1>index0) && ((index0-index1) % 8 == 0)){
        //FOWARD
        if(*(b + index1) == WHITEWOOD){
          int index2;
          int breaker = 0;
          for(index2 = index1 - 8 ; (index2 > index0) && (breaker != 1) ; ){
            if(*(b + index2) != WHITEWOOD){
              n = 0;
              breaker = 1;
            }
            else if(*(b + index2) == WHITEWOOD){
              n = 1;
            }
            index2 -= 8;
          }
        }
        else if(*(b + index1) != WHITEWOOD){
          n = 0;
        }
      }
      else if(index0>index1){
        //LEFT
        if((index0 - index1) >= 8){
          n = 0;
        }
        else if((index0 - index1) < 8){
          int index2;
          if(index0 % 8  == 0){
            n = 0;
          }
          else if(index0 % 8 != 0){
            for(index2 = index0  ; (index2 % 8) != 0 ; ){
              index2 -= 1;
              if(*(b + index2) == WHITEWOOD){
                n = 1;
              }
              else if(*(b + index2) != WHITEWOOD){
                n = 0;
              }
            }
          }
        }
      }
      else if(index1>index0){
        //RIGHT
        if((index1 - index0) >= 8){
          n = 0;
        }
        else if((index1 - index0) < 8){
          int index2;
          if((index0 + 1) % 8  == 0){
            n = 0;
          }
          else if((index0 + 1) % 8 != 0){
            for(index2 = index0  ; ((index2 + 1) % 8) != 0 ; ){
              index2 += 1;
              if(*(b + index2) == WHITEWOOD){
                n = 1;
              }
              else if(*(b + index2) != WHITEWOOD){
                n = 0;
              }
            }
          }
        }
      }

    }
  }
 return n;
}
void movement(char *b, int turn, int x0, int y0, int x1, int y1){
  int index2 = (8*y0) + x0;
  int index3 = (8*y1) + x1;
  if(turn == 0){
    *(b + index3) = WHITE;
    *(b + index2) = WHITEWOOD;
  }
  if(turn == 1){
    *(b + index3) = BLACK;
    *(b + index2) = WHITEWOOD;
  }
}
int can_eat(char *b, int turn){
  int n = 0;
  int i;
  if(turn == 0){
    //white
    for(i = 0; i < COLUMNS*ROWS ; i++){
      if(*(b + i) == WHITE){
        if((((*(b + i - 1) == BLACK) || (*(b + i - 1) == BLACKDAMA)) && (*(b + i - 2) == WHITEWOOD))&&(i % 8 != 0)){
          n++;
        }
        if(((*(b + i + 1) == BLACK) || (*(b + i + 1) == BLACKDAMA)) && (*(b + i + 2) == WHITEWOOD)){
          if(((i + 1) % 8) != 0){
            n++;
          }
        }
        if(((*(b + i + 8) == BLACK) || (*(b + i + 8) == BLACKDAMA)) && (*(b + i + 16) == WHITEWOOD)){
          n++;
        }
      }
      if(*(b + i) == WHITEDAMA){
        int a;
        for(a = i + 1 ; ((a % 8) != 0) && a < 64 ; a++ ){
          if((*(b + a) == BLACK) || (*(b + a) == BLACKDAMA)){
            if(*(b + a + 1) == WHITEWOOD){
              n++;
            }
          }
        }
        for(a = i - 1 ; ((i % 8) != 0) && i > 0 ; a--){
          if((*(b + a) == BLACK) || (*(b + a) == BLACKDAMA)){
            if(*(b + a - 1) == WHITEWOOD){
              n++;
            }
          }
        }
        for(a = i - 8 ; a >= 0  ; ){
          if((*(b + a) == BLACK) || (*(b + a) == BLACKDAMA)){
            if(*(b + a - 16) == WHITEWOOD){
              n++;
            }
          }
          a -= 8;
        }
        for(a = i + 8 ; a < 64  ; ){
          if((*(b + a) == BLACK) || (*(b + a) == BLACKDAMA)){
            if(*(b + a + 16) == WHITEWOOD){
              n++;
            }
          }
          a += 8;
        }
      }
    }
  }
  else if(turn == 1){
    //black
    for(i = 0; i < COLUMNS*ROWS ; i++){
      if(*(b + i) == BLACK){
        if(((*(b + i - 1) == WHITE) || (*(b + i - 1) == WHITEDAMA)) && (*(b + i - 2) == WHITEWOOD)){
          if((i % 8) != 0){
            n++;
          }
        }
        if((((*(b + i + 1) == WHITE) || (*(b + i + 1) == WHITEDAMA)) && (*(b + i + 2) == WHITEWOOD))&&((i + 1) % 8 != 0)){
          n++;
        }
        if(((*(b + i - 8) == WHITE) || (*(b + i - 8) == WHITEDAMA)) && (*(b + i - 16) == WHITEWOOD)){
          n++;
        }
      }
      if(*(b + i) == BLACKDAMA){
        int a;
        for(a = i + 1 ; ((a % 8) != 0) && a < 64 ; a++ ){
          if((*(b + a) == WHITE) || (*(b + a) == WHITEDAMA)){
            if(*(b + a + 1) == WHITEWOOD){
              n++;
            }
          }
        }
        for(a = i - 1 ; ((i % 8) != 0) && i > 0 ; a--){
          if((*(b + a) == WHITE) || (*(b + a) == WHITEDAMA)){
            if(*(b + a - 1) == WHITEWOOD){
              n++;
            }
          }
        }
        for(a = i - 8 ; a >= 0  ; ){
          if((*(b + a) == WHITE) || (*(b + a) == WHITEDAMA)){
            if(*(b + a - 16) == WHITEWOOD){
              n++;
            }
          }
          a -= 8;
        }
        for(a = i + 8 ; a < 64  ; ){
          if((*(b + a) == WHITE) || (*(b + a) == WHITEDAMA)){
            if(*(b + a + 16) == WHITEWOOD){
              n++;
            }
          }
          a += 8;
        }
      }
    }
  }
  return n;
}
void eating(char *b, int turn, int x4, int y4, int x5, int y5, int x6, int y6){
  int index4 = y4*8 + x4;
  int index5 = y5*8 + x5;
  int index6 = y6*8 + x6;
  if(turn == 0){
    //whıte turn
    if(*(b + index4) == WHITE){
    *(b + index4) = WHITEWOOD;
    *(b + index5) = WHITEWOOD;
    *(b + index6) = WHITE;
    }
    else if(*(b + index4) == WHITEDAMA){
    *(b + index4) = WHITEWOOD;
    *(b + index5) = WHITEWOOD;
    *(b + index6) = WHITEDAMA;
    }
  }
  if(turn == 1){
    //black turn
    if(*(b + index4) == BLACK){
    *(b + index4) = WHITEWOOD;
    *(b + index5) = WHITEWOOD;
    *(b + index6) = BLACK;
    }
    else if(*(b + index4) == BLACKDAMA){
    *(b + index4) = WHITEWOOD;
    *(b + index5) = WHITEWOOD;
    *(b + index6) = BLACKDAMA;
    }
  }
}
void move(char *b, int turn){
  int x0;
  int y0;
  int z0;
  int index0;
  int breaker = 0;
  if(turn == 0){
    while(breaker != 1){
      printf("\nPlease enter which piece you wanna move\n");
      printf("X: ");
      scanf("%d", &x0);
      printf("\nY: ");
      scanf("%d", &y0);
      index0 = (8*y0) + x0;
      if(*(b + index0) == WHITE){
        printf("\nPlease enter where you wanna move\n");
        printf("\n[1] SOUTH\n");
        printf("\n[2] WEST\n");
        printf("\n[3] EAST\n");
        int a0;
        scanf("%d", &a0);
        if(a0 == 1){
          z0 = is_valid_move(b, turn, x0, y0, x0, y0+1);
          if(z0 == 1){
            movement(b, turn, x0, y0, x0, y0+1);
            breaker = 1;
          }
          else if(z0 == 0){
            printf("\nincorrect input try again\n");
          }
        }
        else if(a0 == 2){
          z0 = is_valid_move(b, turn, x0, y0, x0-1, y0);
          if(z0 == 1){
            movement(b, turn, x0, y0, x0-1, y0);
            breaker = 1;
          }
          else if(z0 == 0){
            printf("\nincorrect input try again\n");
          }
        }
        else if(a0 == 3){
          z0 = is_valid_move(b, turn, x0, y0, x0+1, y0);
          if(z0 == 1){
            movement(b, turn, x0, y0, x0+1, y0);
            breaker = 1;
          }
          else if(z0 == 0){
            printf("\nincorrect input try again\n");
          }
        }
      }
      if(*(b + index0) == WHITEDAMA){
        printf("\nPlease enter where you wanna move\n");
        int x1;
        int y1;
        printf("\nX: ");
        scanf("%d", &x1);
        printf("\nY: ");
        scanf("%d", &y1);
        int z1;
        z1 = is_valid_move(b, turn, x0, y0, x1, y1);
        if(z1 == 1){
          movement(b, turn, x0, y0, x1, y1);
          breaker = 1;
        }
        else if(z1 == 0){
          printf("\nincorrect input try again\n");
        }
      }
    }
  }
  if(turn == 1){
    while(breaker != 1){
      printf("\nPlease enter which piece you wanna move\n");
      printf("X: ");
      scanf("%d", &x0);
      printf("\nY: ");
      scanf("%d", &y0);
      index0 = (8*y0) + x0;
      if(*(b + index0) == BLACK){
        printf("\nPlease enter where you wanna move\n");
        printf("\n[1] NORTH\n");
        printf("\n[2] WEST\n");
        printf("\n[3] EAST\n");
        int a0;
        scanf("%d", &a0);
        if(a0 == 1){
          z0 = is_valid_move(b, turn, x0, y0, x0, y0-1);
          if(z0 == 1){
            movement(b, turn, x0, y0, x0, y0-1);
            breaker = 1;
          }
          else if(z0 == 0){
            printf("\nincorrect input try again\n");
          }
        }
        else if(a0 == 2){
          z0 = is_valid_move(b, turn, x0, y0, x0-1, y0);
          if(z0 == 1){
            movement(b, turn, x0, y0, x0-1, y0);
            breaker = 1;
          }
          else if(z0 == 0){
            printf("\nincorrect input try again\n");
          }
        }
        else if(a0 == 3){
          z0 = is_valid_move(b, turn, x0, y0, x0+1, y0);
          if(z0 == 1){
            movement(b, turn, x0, y0, x0+1, y0);
            breaker = 1;
          }
          else if(z0 == 0){
            printf("\nincorrect input try again\n");
          }
        }
      }
      if(*(b + index0) == BLACKDAMA){
        printf("\nPlease enter where you wanna move\n");
        int x1;
        int y1;
        printf("\nX: ");
        scanf("%d", &x1);
        printf("\nY: ");
        scanf("%d", &y1);
        int z1;
        z1 = is_valid_move(b, turn, x0, y0, x1, y1);
        if(z1 == 1){
          movement(b, turn, x0, y0, x1, y1);
          breaker = 1;
        }
        else if(z1 == 0){
          printf("\nincorrect input try again\n");
        }
      }
    }
  }
}
int isvalid_eat(char *b, int turn, int x, int y, int direction){
 int n;
 int index0 = 8*y + x;
 if(turn == 0){
   if(*(b + index0) == WHITE){
     if(((direction == 1) && (*(b + index0 + 8) == BLACK)) && (*(b + index0 + 16) == WHITEWOOD)){
       n = 1;
     }
     else if(((direction == 2) && (*(b + index0 - 1) == BLACK)) && (*(b + index0 - 2) == WHITEWOOD)){
       n = 1;
     }
     else if(((direction == 3) && (*(b + index0 + 1) == BLACK)) && (*(b + index0 + 2) == WHITEWOOD)){
       n = 1;
     }
   }
   else{
     n = 0;
   }
 }
 else if(turn == 1){
   if(*(b + index0) == BLACK){
     if(((direction == 1) && (*(b + index0 - 8) == WHITE)) && (*(b + index0 - 16) == WHITEWOOD)){
       n = 1;
     }
     else if(((direction == 2) && (*(b + index0 - 1) == WHITE)) && (*(b + index0 - 2) == WHITEWOOD)){
       n = 1;
     }
     else if(((direction == 3) && (*(b + index0 + 1) == WHITE)) && (*(b + index0 + 2) == WHITEWOOD)){
       n = 1;
     }
   }
   else{
     n = 0;
   }
 }
return n;
}
int isvalid_dama_eat(char *b, int turn, int x0, int y0, int x1, int y1, int x2, int y2, int direction){
  int n;
  int index0 = (8 * y0) + x0;
  int index1 = (8 * y1) + x1;
  int index2 = (8 * y2) + x2;
  if(turn == 0){
    if(*(b + index0) == WHITEDAMA){
      if((*(b + index1) == BLACK) || (*(b + index1) == BLACKDAMA)){
        if(*(b + index2) == WHITEWOOD){
          if(direction == 1){
            if(((index1 - index0) % 8 == 0) && ((index2 - index1) % 8 == 0)){
              n = 1;
            }
            else{
              n = 0;
            }
          }
          else if(direction == 2){
            if(((index1 - index0) % 8 == 0) && ((index2 - index1) % 8 == 0)){
              n = 1;
            }
            else{
              n = 0;
            }
          }
          else if(direction == 3){
            if((((index0 - index1) < 7) && ((index0 - index2) < 8)) && ((index1 - index2) < 6)){
              n = 1;
            }
            else{
              n = 0;
            }
          }
          else if(direction == 4){
            if((((index0 + index1) < 7) && ((index0 + index2) < 8)) && ((index1 + index2) < 6)){
              n = 1;
            }
            else{
              n = 0;
            }
          }
          else{
            n = 0;
          }
        }
        else{
          n = 0;
        }
      }
      else{
        n = 0;
      }
    }
    else{
      n = 0;
    }
  }
  else if(turn == 1){
    if(*(b + index0) == BLACKDAMA){
      if((*(b + index1) == WHITE) || (*(b + index1) == WHITEDAMA)){
        if(*(b + index2) == WHITEWOOD){
          if(direction == 1){
            if(((index1 - index0) % 8 == 0) && ((index2 - index1) % 8 == 0)){
              n = 1;
            }
            else{
              n = 0;
            }
          }
          else if(direction == 2){
            if(((index1 - index0) % 8 == 0) && ((index2 - index1) % 8 == 0)){
              n = 1;
            }
            else{
              n = 0;
            }
          }
          else if(direction == 3){
            if((((index0 - index1) < 7) && ((index0 - index2) < 8)) && ((index1 - index2) < 6)){
              n = 1;
            }
            else{
              n = 0;
            }
          }
          else if(direction == 4){
            if((((index0 + index1) < 7) && ((index0 + index2) < 8)) && ((index1 + index2) < 6)){
              n = 1;
            }
            else{
              n = 0;
            }
          }
          else{
            n = 0;
          }
        }
        else{
          n = 0;
        }
      }
      else{
        n = 0;
      }
    }
    else{
      n = 0;
    }
  }
  return n;
}
void eat(char *b, int turn){
  int x0;
  int y0;
  int breaker = 0;
  int a;
  int z;
  int index0;
  if(turn == 0){
    while(breaker != 1){
      printf("\n Please enter which piece you want to use\n");
      printf("X: ");
      scanf("%d", &x0);
      printf("\nY: ");
      scanf("%d", &y0);
      index0 = (8 * y0) + x0;
      if(*(b + index0) == WHITE){
        printf("\nPlease enter which direction you eat\n");
        printf("[1]FOWARD\n[2]LEFT\n[3]RIGHT\n");
        scanf("%d", &a);
        z = isvalid_eat(b, turn, x0, y0, a);
        if(z == 1){
          if(a == 1){
            eating(b, turn, x0, y0, x0, y0+1, x0, y0+2);
            breaker = 1;
          }
          else if(a == 2){
            eating(b, turn, x0, y0, x0-1, y0, x0-2, y0);
            breaker = 1;
          }
          else if(a == 3){
            eating(b, turn, x0, y0, x0+1, y0, x0+2, y0);
            breaker = 1;
          }
        }
        else{
          printf("\nincorect input please try again\n");
        }
      }
      else if(*(b + index0) == WHITEDAMA){
        int x1, y1, z1, x2, y2, direction;
        printf("\nPlease enter eating direction\n");
        printf("\n[1] NORTH\n");
        printf("\n[2] SOUTH\n");
        printf("\n[3] WEST\n");
        printf("\n[4] EAST\n");
        scanf("%d", &direction);
        printf("\nPlease enter which piece you wanna eat\n");
        printf("X: ");
        scanf("%d", &x1);
        printf("\nY: ");
        scanf("%d", &y1);
        printf("\nPlease enter where you will be after eating\n");
        printf("X: ");
        scanf("%d", &x2);
        printf("\nY: ");
        scanf("%d", &y2);
        z1 = isvalid_dama_eat(b, turn, x0, y0, x1, y1, x2, y2, direction);
        if(z1 == 1){
          eating(b, turn, x0, y0, x1, y1, x2, y2);
          breaker = 1;
        }
        else if(z1 == 0){
          printf("\n invalid input please try again\n");
        }
      }
      else{
        printf("\n incorect input please try again\n");
      }
    }
  }
  if(turn == 1){
    while(breaker != 1){
      printf("\n Please enter which piece you want to use\n");
      printf("X: ");
      scanf("%d", &x0);
      printf("\nY: ");
      scanf("%d", &y0);
      index0 = (8 * y0) + x0;
      if(*(b + index0) == BLACK){
        printf("\nPlease enter which direction you eat\n");
        printf("[1]FOWARD\n[2]LEFT\n[3]RIGHT\n");
        scanf("%d", &a);
        z = isvalid_eat(b, turn, x0, y0, a);
        if(z == 1){
          if(a == 1){
            eating(b, turn, x0, y0, x0, y0-1, x0, y0-2);
            breaker = 1;
          }
          else if(a == 2){
            eating(b, turn, x0, y0, x0-1, y0, x0-2, y0);
            breaker = 1;
          }
          else if(a == 3){
            eating(b, turn, x0, y0, x0+1, y0, x0+2, y0);
            breaker = 1;
          }
        }
        else{
          printf("\nincorect input please try again\n");
        }
      }
      else if(*(b + index0) == BLACKDAMA){
        int x1, y1, z1, x2, y2, direction;
        printf("\nPlease enter eating direction\n");
        printf("\n[1] NORTH\n");
        printf("\n[2] SOUTH\n");
        printf("\n[3] WEST\n");
        printf("\n[4] EAST\n");
        scanf("%d", &direction);
        printf("\nPlease enter which piece you wanna eat\n");
        printf("X: ");
        scanf("%d", &x1);
        printf("\nY: ");
        scanf("%d", &y1);
        printf("\nPlease enter where you will be after eating\n");
        printf("X: ");
        scanf("%d", &x2);
        printf("\nY: ");
        scanf("%d", &y2);
        z1 = isvalid_dama_eat(b, turn, x0, y0, x1, y1, x2, y2, direction);
        if(z1 == 1){
          eating(b, turn, x0, y0, x1, y1, x2, y2);
          breaker = 1;
        }
        else if(z1 == 0){
          printf("\n invalid input please try again\n");
        }
      }
      else{
        printf("\n incorect input please try again\n");
      }
    }
  }
}
int checkmatchstatus(char *b){
  int i,j;
  int index = 0;
  int blackpieces = 0;
  int whitepieces = 0;
  int n;
  for(i=0;i<ROWS;i++){
    for(j=0;j<COLUMNS;j++){
      index = i*COLUMNS + j;
      if(b[index] == BLACK){
        blackpieces++;
      }
      if(b[index] == WHITE){
        whitepieces++;
      }
    }
  }
  if(blackpieces == 0){
    n = 0;
  }
  else if(whitepieces == 0){
    n = 1;
  }
  else{
    n = 2;
  }
return n;
}
void game_engine(char *b, int turn){
  int lap = 1;
  while(checkmatchstatus(b) == 2){
    printf("\n\n");
    print_board(b);
    printf("\n\n");
    printf("\nLap: %d\n", lap);
    if(can_eat(b, turn) != 0){
      while(can_eat(b, turn) != 0){
        if(turn == 0){
          printf("\nWHITES TURN\n");
        }
        else if(turn == 1){
          printf("\nBLACKS TURN\n");
        }
        printf("You can eat \n");
        eat(b, turn);
        if(can_eat(b, turn) == 0){
          if(turn == 0){
            turn = 1;
          }
          else if(turn == 1){
            turn = 0;
          }
        }
        printf("\n\n");
        print_board(b);
        printf("\n\n");
      }
    }
    else if(can_eat(b, turn) == 0){
      if(turn == 0){
        printf("\nWHITES TURN\n");
      }
      if(turn == 1){
        printf("\nBLACKS TURN\n");
      }
      move(b, turn);
      if(turn == 0){
        turn = 1;
      }
      else if(turn == 1){
        turn = 0;
      }
    }
    make_dama(b);
    if(checkmatchstatus(b) == 0){
      printf("\nWHITE WON\n");
      break;
    }
    else if(checkmatchstatus(b) == 1){
      printf("\nBLACK WON\n");
      break;
    }
    else if(checkmatchstatus(b) == 2){
      lap++;
    }
  }
}
