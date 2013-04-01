/*
 * Escercise 1-12: Write a program that prints its output one word per line.
 */

#include <stdio.h>

#define INWORD 0
#define OUTWORD 1

/* Counts lines, words and characters in stdin */
int main(){
  int c, state;

  state = OUTWORD;

  while ( (c = getchar()) != EOF ){
    switch(c){
      case '\n':
      case ' ':
      case '\t':
        state = OUTWORD;
        break;
      default:
        if(state == OUTWORD){
          putchar('\n');
        }
        state = INWORD;
        putchar(c);
    }
  }
  putchar('\n');
  return 0;
}
