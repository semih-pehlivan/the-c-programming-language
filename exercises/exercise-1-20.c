/*
 * Exercise 1-20:write a program detab that replaces the tabs in the input with
 * the proper number of blanks to space to the next tab stop. Assume a fixed 
 * set of tab stops, say every n columns. Should n be a variable of a symbolic 
 * parameter?
 */

#include <stdio.h>


/*
 * TABWIDTH is a symbolic parameter, but should be a variable that is accepted
 * as part of the arguments to main.
 */
#define TABWIDTH 4

/*
 * detab is character based to avoid the problem of line buffering, which 
 * would limit maximum line length.
 */
int main(){
  int c;
  int newspaces = 0;
  int lindex = 0; /* Where in the line are we?*/
  

  while((c = getchar()) != EOF){
    switch(c){
      case '\n': 
        lindex = 0;
        putchar(c);
        break;
      case '\t':
        newspaces =  TABWIDTH - (lindex % TABWIDTH);
        /*
        printf("\nDEBUG: lindex=%d ns=%d tabwidth=%d\n",lindex,newspaces,TABWIDTH);
        */
        lindex += newspaces;
        for (;newspaces > 0; --newspaces){
          putchar(' ');
        }
        break; 
      default:
        putchar(c);
        lindex++;
        break;
    }
  }
  return 0;
}
