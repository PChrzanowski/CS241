#include <stdio.h>

unsigned x;
int  n, p;
int checkErrors(unsigned x, int n, int p);
unsigned getBits(unsigned x, int n, int p);

int main()
{
  int c;
  while ( EOF != (c=getchar()))
       {
	 fflush(stdin);
	 scanf("%u,%d,%d", &x, &n, &p);
	 checkErrors(x,n,p);
	 getBits(x,n,p);
       }

  return 0;

}
int  checkErrors(unsigned x, int n, int p)
{
  if(p >= 32)
    {
      printf("Error: number of bits out of range\n");
      return 0;
    }
  else  if (p+1-n < 0){
    printf("Error: too many bits requested from position\n");
    return 0;
  }
  printf("X is %u, N is %d, P is %d \n" , x,n,p);
  return 0;
}

unsigned getBits(unsigned x, int n, int p)
{
  return (x >> (p+1-n) & ~(~0 << n));
}
