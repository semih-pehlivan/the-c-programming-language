/*
 * Exercise 1-19: Write a function reverse(s) that reverses the character 
 * string s. Use it to write a program that reverses its input a line at a 
 * time.
 */

#include <stdio.h>
#include "chapter1.h"

#define MAXLINE 2000

int main(){
  int len;
  char line[MAXLINE];

  while((len = bgetline(line,MAXLINE)) > 0){
    reverse_in_place((char *)line);
    printf(line);
  }
  return 0;
}
