/*
 * Exercise 1-18: Write a program to remove trailing blanks and tabs from each 
 * line of input, and delete entirely blank lines.
 */

#include <stdio.h>

#define MAXLINE 1000

int isblank(char c){
  return c == '\t' || c == ' ' || c == '\n';
}

int main(){
  int index,c;
  char buf[MAXLINE];

  index = 0;
  while(((c=getchar()) != EOF) && index < 2048){
    buf[index++] = c;
    switch(c){
      case '\n':
        for(;isblank(buf[index-1]);--index )
          ; 
        buf[index] = '\n';
        buf[index+1] = '\0';
        if(index > 0)
          printf(buf);
        index = 0;
        break;
      default:
        break;
    }
  }
  if (c != EOF){
    fprintf(stderr, "[Error]: Encountered a very long line\n");
    return 1;
  }
  return 0;
}
