/*
 * Exercise 1-17: Write a program to print all input lines that are longer 
 * than 80 characters.
 */

#include <stdio.h>

#define LINELEN 80 

#define LONGLINE 0
#define NORMLINE 1

int main(){
  int c, state, i;
  char line[LINELEN+1];

  line[LINELEN] = 0;
  
  state = NORMLINE;
  i = 0;
  while((c = getchar()) != EOF){
    switch(c){
      case '\n':
        /* End of line, print out if LONGLINE, then reset to normal.*/
        if(state == LONGLINE){
          /* terminate the string */
          line[i] = 0;
          puts(line);
          state = NORMLINE;
        }
        i = 0;
        break;
      default:
        line[i++]=c;
        if(i >= LINELEN){
          state = LONGLINE;
          printf(line);
          i=0;
        }
        break;
    }
  }
  return 0;
}
