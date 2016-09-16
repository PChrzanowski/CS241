/*************************************************/
/* Philip Chrzanowski */
/* 08/30/2016 */
/* CS-241 Section 001 */
/*************************************************/

#include <stdio.h>
void summary(void);
void lineSummary(int c,int d);

int charCount;
int totalLines = 1;
int totalWords;
int lineWord;
int lineChar;
int printStartNum = 1;
int mostCharLine = 0;
int mostChar = 0;
int mostWords = 0;
int mostWordLine = 0;
int potentialWord = 0;
int firstCharInLine = 1;

int main()
{
  int c;
  int x = 1;

  while (EOF != (c = getchar()))
    {
      if(printStartNum == 1)
	{
	  printf("%d.",totalLines);
	  printStartNum = 0;
	}
       if(c == '\n')
	 {
	   firstCharInLine =1;
	   /*prints a [word,character] summary of the line*/
	   lineSummary(x,lineChar);
	  printf("\n");
	  /*check if the line just done had the most characters*/
	  if(lineChar > mostChar)
	    {
	      mostCharLine = totalLines;
	      mostChar = lineChar;
	    }
	  /*check if the line done had the most words*/
	  if(lineWord > mostWords)
	    {
	      mostWords = lineWord;
	      mostWordLine = totalLines;
	    }
	  /*increment total lines, set line character and word to 0*/
	  totalLines++;
	  x++;
	  lineChar = 0;
	  lineWord = 0;
	  printStartNum = 1;
	}
       /*if the character is anything thats not \n */
      else if (c != '\n')
	{
	  if(firstCharInLine == 1)
	    {
	      if(c != ' ' && c!='\t')
		{
		  lineWord++;
		  totalWords++;
		  firstCharInLine = 0;
		  potentialWord = 0;
		}
	    }
	  /*if it is not a blank character and not a multiple space in a row*/
	  else if(c != ' ' && potentialWord == 1)
	  {
	    if(c != '\t')
	      {
	    lineWord++;
	    totalWords++;
	    potentialWord = 0;
	      }
	  }
	  /*prints the character and add the character to the line and the total*/
	   printf("%c",c);
	   lineChar++;
	   charCount++;
	   /*if we have found a space reset the potential of the word existing*/
	   if(c == ' ' || c == '\t')
	     {
		  potentialWord = 1;
	    }
	}
    }
  /*print a summary of the whole program*/
  summary();
  return 0;
}
void lineSummary(int c , int x)
{
  printf("[%d;%d]",lineWord,x);
}


void summary(void)
{
  printf("%d lines, %d words, %d characters\n" ,(totalLines -1),totalWords,charCount);
  printf("With %d, line %d has the most characters\n",mostChar,mostCharLine);
  printf("With %d, line %d has the most words\n" , mostWords, mostWordLine);
}
