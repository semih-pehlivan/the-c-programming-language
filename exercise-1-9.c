/*
 * Excercise 1-9: Write a program to copy its input to its output, replacing 
 * each string of one or more blank by a single blank.
 */

#include <stdio.h>

int main()
{
  int c;
  int blanks = 0;

  while ((c = getchar()) != EOF){
    switch(c){
      case ' ':
        if(!(blanks > 0)){
          putchar(c);
        }
        blanks++;
        break;
        
      default: 
        blanks = 0;
        putchar(c); 
        break;
    } 
  }
  
 
  return 0;
}
