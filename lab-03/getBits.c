#include <stdio.h>
void buildX(int c);
void buildN(int c);
void getN(int n, int c);
void getP(int p, int c);
int checkX(long tempX, int xLength);
int checkN(int tempN);
long tempX = 0;
int tempN = 0;
int n = 0;
int xLength = 0;
unsigned realX = 0;
unsigned throwAwayX;
long uncheckedX =0;
int checkingX = 1;
int checkingN = 0;
int main()
{
  int c;
  while (EOF != (c=getchar()))
    {
      if(checkingX == 1 && c!= ',')
	{
	  buildX(c);
	}
      if(c == ',' && checkingX == 1)
	{
	  checkingX = 0;
	  if(checkX(tempX, xLength) == 1)
	    {
	      printf("Error: invalid value of x! \n");
	    }
	  else
	    {
	      printf("X is %u \n", realX);
	      checkingX = 0;
	      checkingN = 1;
	    }
	}
      if(checkingN == 1 && c!= ',')
	{
	  buildN(c);
	}
      if(checkingN ==1 && c== ',')
	{
	  if(checkN(tempN) == 1)
	    {
	      printf("N is larger than 32 \n");
	    }
	  else
	    {
	      printf("N is %d, \n" , n);
	    }
	}
    }
      if(c == '\n')
	{
	  tempX = 0;
	  tempN =0;
	  n=0;
	  xLength =0;
	  checkingX = 1;
	  checkingN = 0;
	}
return 0;
}

void buildN(int c)
{
  int z = c;
  switch (z)
    {
    case 48:
      tempN = tempN*10 + 0;
      break;
    case 49:
      tempN = tempN *10 + 1;
      break;
    case 50:
      tempN = tempN*10+ 2;
      break;
    case 51:
      tempN = tempN*10+ 3;
      break;
    case 52:
      tempN = tempN*10 + 4;
      break;
    case 53:
      tempN = tempN*10 + 5;
      break;
    case 54:
      tempN = tempN*10 + 6;
      break;
    case 55:
      tempN = tempN*10+ 7;
      break;
    case 56:
      tempN = tempN*10+ 8;
      break;
    case 57:
      tempN = tempN*10+ 9;
      break;
    default:
      break;
    }
}

void buildX(int c)
{
  int z = c;
  switch (z)
    {
    case 48:
      tempX = tempX*10 + 0;
      xLength++;
      break;
    case 49:
      tempX = tempX *10 + 1;
      xLength++;
      break;
    case 50:
      tempX = tempX*10+ 2;
      xLength++;
      break;
    case 51:
      tempX = tempX*10+ 3;
      xLength++;
      break;
    case 52:
      tempX = tempX*10 + 4;
      xLength++;
      break;
    case 53:
      tempX = tempX*10 + 5;
      xLength++;
      break;
    case 54:
      tempX = tempX*10 + 6;
      xLength++;
      break;
    case 55:
      tempX = tempX*10+ 7;
      xLength++;
      break;
    case 56:
      tempX = tempX*10+ 8;
      xLength++;
      break;
    case 57:
      tempX = tempX*10+ 9;
      xLength++;
      break;
    default:
      break;
    }
}

int checkX(long tempX, int xLength)
{
  if (tempX > 4294967290 || xLength > 10)
    {
      return 1;
    }
  else
    {
      realX = tempX;
      return 0;
    }
  return 0;
}

int checkN (int tempN)
{
  if(tempN > 32)
    {
      return 1;
      tempN =0;
    }
  else
    {
      n = tempN;
      return 0;
    }
  return 0;
}
