#include <stdio.h>
int board[9][9];
void clearArray();
int buildArray(int c, int x, int y);
int recursion (int x, int y);
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
    {
    for(j = 0; j < 9; j++)
      {
	printf("%d" , board[i][j]);
      }  
    }
   putchar('\n');
   putchar('\n');
}

int main()
{
  
  
  int c;
  while(EOF != (c=getchar()))
    {
      if(c!= '\n' && c!= '.')
	{
	  printf("%c",c);
	}
      if(c == '.')
	{
	  printf(".");
	}
      if(c!= '\n' && ignoreInput != 1)
	{
	  if( buildArray(c, inputCount/9,inputCount%9) != 1)
	{
	  ignoreInput = 1;
	}
	else
	  {
	    inputCount++;
	  }
	}
      if(c == '\n')
	{
	  printf("\n");
	  if(ignoreInput == 1 || inputCount != 81)
	    {
	      printf("Error\n\n");
	      purgeVars();
	    }
	  else
	    {
	      // printBoard();
	      if(recursion(0,0) == 0)
		{
		  printBoard();
		} 
	      else
		{
		  printf("No Solution\n\n");
		}
	    }
	}
    }
  return 0;
}
/*clears array and populates it with all zeros */
void clearArray()
{
  // printf("clearing array\n");
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
  int z = (c - '0');
  if(c >= '1' && c <= '9')
    {
      if(isValid(x,y,z) == 1)
	{
	  board[x][y] = z;
	  return 1;
	}
    }
  else if(c == '.')
    {
      board[x][y] = 0;
      return 1;
    }
  //printf("error at %d , %d, with value %d\n", x, y, z);
  return 0;
}

int recursion(int x, int y)
{
  // printf("entered recursion\n");
  int yLoc = y;
  int checkNum = 1;
  if(yLoc >= 9)
    {
      return 0;
    }
  else if (board[x][y] == 0)
    {
      // printf("x is %d, y is %d and its 0\n",x,y);
      for(checkNum = 1; checkNum <= 9; checkNum++)
	{
	  if(isValid(x,y,checkNum) == 1)
	    {
	      // printf("valid spot for insertion \n");
	      board[x][y] = checkNum;
	      if(x + 1 < 9)
		{
		  if (recursion(x + 1, y) == 0)
		    {
		      return 0;
		    }
		}
	      else
		{
		  if (recursion(0, y+1) == 0)
		    {
		      return 0;
		    }
		}
	    }
	}
      //  printf("Bottomed out at x=%d, y=%d\n", x, y);
      board[x][y] = 0;
    }
  else
    {
      if(x + 1 < 9)
	{
	  if(recursion(x + 1, y) == 0)
	    {
	      return 0;
	    }
	}
      else
	{
	  if (recursion(0, y+1) == 0)
	    {
	      return 0;
	    }
	    
	}     
    }
  return 1;
}
void purgeVars()
{
  // printf("purging\n");
  x = 0;
  y = 0;
  inputCount= 0;
  ignoreInput = 0;
  clearArray();
}

int isValid(int row, int column, int number)
{
  int i=0;
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
