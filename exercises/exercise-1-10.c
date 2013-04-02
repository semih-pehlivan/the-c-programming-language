/*
 * Excercise 1-0: Write a program to copy its input to its output, replacing
 * each tab by \t, each backspace by \b, and each backslash by \\. This makes
 * tabs and backspaces visible in an unabiguous way.
 */

#include <stdio.h>

int main()
{
  int c;

  while ((c = getchar()) != EOF){
    switch(c){
      case '\t': printf("\\t"); break;
      case '\b': printf("\\b"); break;
      case '\\': printf("\\\\"); break;
      case ' ': printf("\\_"); break;
      default: 
        putchar(c); 
        break;
    } 
  }
  
 
  return 0;
}
