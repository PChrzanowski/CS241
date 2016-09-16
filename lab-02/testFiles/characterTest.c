/*************************************************/
/* Philip Chrzanowski */
/* 08/30/2016 */
/* CS-241 Section 001 */
/*************************************************/

#include <stdio.h>
void charCountUp(int c);
void lineCountUp(int c);
void summary(void);
void lineChop(int c);

int charCount;
int totalLines;

int main()
{
  int c;
  int x = 1;

  while (EOF != (c = getchar()))
    {
      if(c == '\n')
	{
	  printf ("Line %d has %d charcters\n",x,charCount);
	  lineCountUp(c);
	  x++;
	}
      else if( c!= 10)
	{
      printf("%d\n",c);
	  charCount++;
      }
    }
  summary();
}


void charCountUp(int c)
{
  charCount++;
}

void lineCountUp(int c)
{
  totalLines++;
}

void summary(void)
{
  printf("There are %d characters and %d lines ",charCount,totalLines);
}
