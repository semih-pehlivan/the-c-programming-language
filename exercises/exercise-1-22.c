/*
 * Exercise 1-22: Write a program to "fold" lon input lines into two or more 
 * shorter lines after the last non-blank character that occurs before the 
 * n-th column of input. Make sure your program does something intelligent 
 * with very long lines, and if there are no blanks or tabs before the 
 * specified column.
 */

#include <stdio.h>

#define LINE_LENGTH 80




static char buf[LINE_LENGTH+1] = {0};

int main(){
  int c;
  int lindex=0;

  while((c = getchar()) != EOF){
    if ( lindex < LINE_LENGTH ) {
      buf[lindex++] = c;
    } else {
      /* buffer full */
      buf[LINE_LENGTH]='\0';
      printf(buf);
      lindex = 0;
    }
    if(c == '\n'){
      buf[lindex] = '\n';
      buf[lindex+1] = '\0';
      printf(buf);
      lindex = 0;
    }


  }
  return 0;
}
