#include <stdio.h>
int board[9][9]= {0};
void clearArray();
int buildArray(int c, int x, int y);
int notValid(int x, int y, int value);
int checkCol(int x, int y, int value);
int checkRow(int x, int y, int value);
int checkBox(int x, int y, int value);
int recursion (int boardArray[][9], int x, int y);
void purgeVars();
int ignoreInput = 0;
int inputCount = 0;
int solved = 0;
int x = 0;
int y = 0;
int value;

void printBoard()
{
  int i, j;
  for (i = 0; i < 9; i++)
    for(j = 0; j < 9; j++)
    {
      printf("%d" , board[i][j]);
    }

  putchar('\n');
  
}
void print2d()
{
 int i, j;
  for (i = 0; i < 9; i++)
    {
    for(j = 0; j < 9; j++)
    {
      printf("%d" , board[i][j]);
    }
    putchar('\n');
    }
}
        

int main()
{
  
  
  int c;
  clearArray();
  while(EOF != (c=getchar()))
  {
    if(c!= '\n' && (c!= '.'))
    {
      printf("%c",c);
    }
    else if(c == '.')
    {
      printf(".");
    }
    if(c != '\n' && ignoreInput != 1){
      if(buildArray(c,inputCount/9,inputCount%9) != 0)
      {
        printf("Ignoring Input \n");
        ignoreInput = 1;
      }
      else
      {
        x++;
        y++;
        inputCount++;
      }
    }
    /*If we see a new line character reset all of the items and we have solved or tried to solve the last puzzle*/
    if(c == '\n')
    {
      printf("\n");
      if(inputCount != 81 || ignoreInput == 1)
	    {
	      printf("Error \n");
	      purgeVars();
	    }
      else
	{
	  if(recursion(board,0,0) == 1)
        {
          printf("No solution \n");
          purgeVars();
        }
	  else
	    {
	      // printf("Solution found \n");
          print2d();
	    }
	 
	}
    }
  }
  return 0;
}
/*clears array and populates it with all zeros */
void clearArray()
{
  int x,y;
  for(x = 0; x < 9; x++) {
    for(y = 0; y < 9 ; y++) {
      board[x][y] = 0;
    }
  }
}
/*reads in the text and builds the array */
int buildArray(int c, int x, int y)
{
  if( c >= '1' && c <= '9'){
    if(isValid(x,y,(c - '0')) == 1){
      board[x][y] = c - '0';
      return 0;
    }
  } 
  else if( c == '.'){
    board[x][y] = 0;
    return 0;
  }
  printf("Not valid character \n");
  return 1;
}

/* wrapper function that calls checkCol, checkRow, and checkBox and errors if there was an invalid character placement in one of them */

int isValid(int row, int column, int value;) {
    int i=0;
    int row = row;
    int column = column;
    int number = value;
    int sectorRow = 3*(row/3);
    int sectorCol = 3*(column/3);
    int row1 = (row+2)%3;
    int row2 = (row+4)%3;
    int col1 = (column+2)%3;
    int col2 = (column+4)%3;
 
    /* Check for the value in the given row and column */
    for (i=0; i<9; i++) {
        if (board[i][column] == number) return 0;
        if (board[row][i] == number) return 0;
    }
 
    /* Check the remaining four spaces in this sector */
    if(board[row1+sectorRow][col1+sectorCol] == number) return 0;
    if(board[row2+sectorRow][col1+sectorCol] == number) return 0;
    if(board[row1+sectorRow][col2+sectorCol] == number) return 0;
    if(board[row2+sectorRow][col2+sectorCol] == number) return 0;
    return 1;
}
int recursion(int boardArray[][9] , int x, int y)
{
  // printf("entered recursion\n");
  int yLoc = y;
  int checkNum = 1;
  if(yLoc >= 9)
  {
    return 0;
  }
  else if (boardArray[x][y] == 0)
  {
    for(checkNum = 1; checkNum <= 9; checkNum++)
    {
      if(isValid(x,y,checkNum) == 1)
	    {
	      // printf("valid spot for insertion \n");
	      boardArray[x][y] = checkNum;
	      if(x + 1 < 9)
        {
          if (recursion(boardArray, x + 1, y) == 0)
          {
            return 0;
          }
        }
	      else
        {
          if (recursion(boardArray, 0, y+1) == 0)
          {
            return 0;
          }
        }
	    }
    }
    //  printf("Bottomed out at x=%d, y=%d\n", x, y);
    boardArray[x][y] = 0;
  }
  else
  {
    if(x + 1 < 9)
    {
      if(recursion(boardArray, x + 1, y) == 0)
	    {
	      return 0;
	    }
    }
    else
    {
      if (recursion(boardArray, 0, y+1) == 0)
	    {
	      return 0;
	    }
	    
    }     
  }
  return 1;
}
void purgeVars()
{
  x = 0;
  y = 0;
  inputCount= 0;
  ignoreInput = 0;
  clearArray();
}
