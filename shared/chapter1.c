#include <stdio.h>
#include "chapter1.h"

int bgetline(char s[], int lim){
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


void copy(char to[], const char from[]){
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


void reverse_in_place(char * s){
  char * k = s+bstrlen(s)-1;
  char t;
  while(k>s){
    t = *s;
    *s = *k;
    *k = t;
    s++;
    k--;
  }
}

