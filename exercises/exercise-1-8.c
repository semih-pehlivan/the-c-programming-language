/*
 * Excercise 1-8: Write a program to count blanks, tabs, and newlines
 */

#include <stdio.h>

int main()
{
  int c, nl, tabs, blanks;
  
  nl = 0;
  tabs = 0;
  blanks = 0;

  while ((c = getchar()) != EOF){
    switch(c){
      case '\n': nl++; break;
      case '\t': tabs++; break;
      case ' ': blanks++; break;
      default: break;
    }
  }
  
  printf("newlines: %4d\n", nl);
  printf("blanks:   %4d\n", blanks);
  printf("tabs:     %4d\n", tabs);
 
  return 0;
}
