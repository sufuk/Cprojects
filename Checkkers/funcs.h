#include<stdio.h>
#include <stdlib.h>
#include <string.h>


#define ROWS 8
#define COLUMNS 8
#define BLACK  '0'
#define WHITE '1'
#define INITIAL_FILE	"board.txt"


void chessboard(char *b){

  b = malloc(ROWS * COLUMNS);
  memset(b, BLACK, ROWS*COLUMNS);
}
