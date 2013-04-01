/*
 * Exercise 1-19: Write a function reverse(s) that reverses the character 
 * string s. Use it to write a program that reverses its input a line at a 
 * time.
 */

#include <stdio.h>

#define MAXLINE 2000

int getline(char s[], int lim){
   int c, i;

   for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
     s[i]=c;
   }
   if(c == '\n') {
     s[i] = c;
     i++;
   }
   s[i] = 0;
   return i;
}


void copy(char to[], char from[]){
  int i = 0;
  while((to[i] = from[i]) != '\0'){
    ++i;
  }
}


int bstrlen(const char * str){
  const char * s;
  for (s = str; *s; ++s)
    ;
  return (s - str);
}


void reverse_in_place(char s[]){
  int i = 0;
  int k = bstrlen(s)-1;
  char t;
  while(k>i){
    t = s[i];
    s[i] = s[k];
    s[k] = t;
    i++;
    k--;
  }
}

int main(){
  int len;
  char line[MAXLINE];

  while((len = getline(line,MAXLINE)) > 0){
    reverse_in_place(line);
    printf(line);
  }
  return 0;
}
