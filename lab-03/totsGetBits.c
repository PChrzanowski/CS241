#include <stdio.h>
void buildNumber(int c);
void getN(int n, int c);
void getP(int p, int c);
int checkX(long tempX);
long tempX = 0;
unsigned realX = 0;
int n , p;
long uncheckedX =0;
int checkingX = 1;
int getRest =0;
int main()
{
  int c;
  while (EOF != (c=getchar()))
    {
      if(checkingX == 1 && c!= ',')
	{
	  buildNumber(c);
	}
      if(c == ',' && checkingX == 1)
	{
	  checkingX = 0;
	  //  getRest = 1;
	  if(checkX(tempX) == 1)
	    {
	      printf("Error: invalid value of x! \n");
	    }
	  else
	    {
	      printf("X is %u\n", realX);
	    }
	}
      if(c == '\n')
	{
	  tempX = 0;
	  checkingX = 1;
	  // getRest = 0;
	}

    }
      return 0;
}

void buildNumber(int c)
{
  int z = c;
  switch (z)
    {
    case 48:
      // printf("Saw a 0 \n");
      tempX = tempX*10 + 0;
      break;
    case 49:
      // printf("Saw a 1 \n");
      tempX = tempX *10 + 1;
      break;
    case 50:
      // printf("Saw a 2 \n");
      tempX = tempX*10+ 2;
      break;
    case 51:
      // printf("Saw a 3 \n");
      tempX = tempX*10+ 3;
      break;
    case 52:
      //printf("Saw a 4 \n");
      tempX = tempX*10 + 4;
      break;
    case 53:
      // printf("Saw a 5 \n");
      tempX = tempX*10 + 5;
      break;
    case 54:
      //printf("Saw a 6 \n");
      tempX = tempX*10 + 6;
      break;
    case 55:
      // printf("Saw a 7 \n");
      tempX = tempX*10+ 7;
      break;
    case 56:
      // printf("Saw a 8 \n");
      tempX = tempX*10+ 8;
      break;
    case 57:
      // printf("Saw a 9 \n");
      tempX = tempX*10+ 9;
      break;
    default:
      // printf("You shouldn't be here!\n");
      break;
    }
  // printf("temp is currently %ld \n" , temp);
}

int checkX(long tempX)
{
  if (tempX > 4294967290)
    {
      return 1;
    }
  else
    {
      realX = tempX;
      // printf("Set real X to %u \n" ,realX);
      return 0;
    }
  return 0;
}
