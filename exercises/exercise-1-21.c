/*
 * Exercise 1-21: Write a program entab that replaces strings of blanks by the 
 * minimum number of tabs and blanks to acheive the same spacing. Use the same 
 * tabstop as for detab. When either a tab or a single blank would suffice to 
 * reach a tab stop, which should be given preference? 
 */

#include <stdio.h>


#define TABWIDTH 4

int entab(int lindex, int blanks){
  int spaces;
  /* If the spaces reach a tabstop */
  if( ((lindex % TABWIDTH)+ blanks ) >= TABWIDTH){
    putchar('\t');
    spaces = TABWIDTH - (lindex % TABWIDTH);
    return entab(lindex+spaces, blanks-spaces);
  }else{ /* The spaces don't reach a tabstop */
    for(;blanks > 0; --blanks){
      lindex++;
      putchar(' ');
    }   
    return lindex;
  }
}



int main(){
  int c;
  int lindex = 0; /* Where in the line are we?*/
  int blanks = 0; 

  while((c = getchar()) != EOF){
    switch(c){
      case ' ':
        blanks++; 
        break; 
      case '\n': 
        if(blanks > 0){
          lindex = entab(lindex,blanks);
          blanks = 0;
        }
        putchar(c);
        lindex = 0;
        break;
      default:
        if(blanks > 0){
          lindex = entab(lindex,blanks);
          blanks = 0;
        }
        putchar(c);
        lindex++;
        break;
    }
  }
  return 0;
}
