#include <stdio.h>
void buildNumber(int c);
int checkX(long temp);
long tempX = 0;
unsigned realX = 0;
long uncheckedX =0;
int checkingX = 1;
int checkingP = 0;
int checkingN = 0;
int main()
{
  int c;
  while (EOF != (c=getchar()))
    {
      if((c!=',' && c!= '\n'))
	{
      buildNumber(c);
	}
      else 
	{
	  if(checkX(tempX) == 1)
	    {
	    printf("Error: value of of range\n");
	    }
	  if(checkingX = 1)
	    {
	      checkingX = 0;
	      checkingP = 1;
	    }
	  if(checkingP = 1)
	    {
	      checkingP = 0;
	      checkingN = 1;
	    }
	}
      if(c == '\n')
	{
	  tempX = 0;
	  checkingX = 1;
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
