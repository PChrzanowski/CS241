/*************************************************/
/* Philip Chrzanowski */
/* 09/16/2016 */
/* CS-241 Section #003 */
/*************************************************/

#include <stdio.h>
long temp = 0;
int tempLength = 0;
int commaSeen = 0;
int enterErrorChecking= 0;
int stopChecking = 0;
unsigned x = 0;
int xBits = 0;
int n = 0;
int p = 0;

void buildNum(int c);
void setNum(long temp, int tempLength);
int errorCheckBitsGrabbed(unsigned x, int n);
int getBits(unsigned x, int n, int p);
int main()
{
  int c;
  while(EOF != (c=getchar()))
    {
      if(c!= ',' && c!= '\n')
	{
	  buildNum(c);
	}
      if(c == ',')
	{
	  setNum(temp, tempLength);
	  commaSeen++;
	  temp = 0;
	  tempLength = 0;
	}
      if(c == '\n' && stopChecking == 0)
	{
	  setNum(temp, tempLength);
	  enterErrorChecking = 1;

	}
      if(enterErrorChecking == 1)
	{
	  if(p+1 < n)
	    {
	      printf("Error: too many bits requested from position\n");
	      stopChecking = 1;
	    }
	  if( p >= 32)
	    {
	      printf("Error: position out of range\n");
	      stopChecking = 1;
	    }
	  if( n >= 32)
	    {
	      printf("Error: number of bits out of range\n");
	      stopChecking = 1;
	    }
	  if(stopChecking != 1)
	    {
	      getBits(x,n,p);
	      stopChecking = 1;
	    }
	  stopChecking = 1;
	}
      if(c == '\n' && stopChecking == 1)
	{
	  temp = 0;
	  tempLength =0;
	  commaSeen = 0;
	  x = 0;
	  n = 0;
	  p = 0;
	  stopChecking = 0;
	  enterErrorChecking =0;
	}
    }
  return 0;
}

int getBits(unsigned x, int n, int p)
{
  printf("getbits(x=%u, p=%d, n=%d) = %d\n",x,p,n,(( x >> (p+1-n)) & ~(~0 << n)));
  return ( x >> (p+1-n)) & ~(~0 << n);
}

void buildNum(int c)
{
  switch(c)
    {
    case 48:
      temp = temp *10 + 0; 
      tempLength++;
      break;
    case 49:
      temp = temp *10 + 1; 
      tempLength++;
      break;
    case 50:
      temp = temp *10 + 2; 
      tempLength++;
      break;
    case 51:
      temp = temp *10 + 3; 
      tempLength++;
      break;
    case 52:
      temp = temp *10 + 4;
      tempLength++;
      break;
    case 53:
      temp = temp *10 + 5; 
      tempLength++;
      break;
    case 54:
      temp = temp *10 + 6; 
      tempLength++;
      break;
    case 55:
      temp = temp *10 + 7; 
      tempLength++;
      break;
    case 56:
      temp = temp *10 + 8; 
      tempLength++;
      break;
    case 57:
      temp = temp *10 + 9; 
      tempLength++;
      break;
    default:
      break;
    }
}
void setNum(long temp, int tempLength)
{
  if(commaSeen == 0)
    {
      if(temp > 4294967295){
	printf("Error: value out of range\n");
	stopChecking = 1;
      }
      x = temp;
    }
  if(commaSeen == 1)
    {
      p = temp;
    }
  if(commaSeen == 2)
    {
      n = temp;
    }
}
