/*
 * Excercise 1-13: Write a program to print a histogram of the lengthe of 
 * words in its input. It is easy to draw a histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 */

#include <stdio.h>
#include <assert.h>

#define INWORD 0
#define OUTWORD 1

/* I don't think there are many words as long in english! */
#define MAXWORDLEN 40

int main(){
  int c, wl, i, l;
  
  int lenfreq[MAXWORDLEN] = {0};

  wl = 0;

  while ( (c = getchar()) != EOF ){
    assert(wl >= 0); /* Something very wrong happened if it isn't */
    
    switch(c){
      case '\n':
      case ' ':
      case '\t':
        if(wl > 0 ){
          ++lenfreq[wl-1]; /* array is 0-indexed */ 
        }
        /*else{
          fprintf(stderr, "[Error]: Words of this length are unsupported: %d\n", wl);
          break;
        }*/
        wl = 0;
        break;
      default:
        ++wl;
    }
  }
  printf("\n");
  printf("length: frequency:\n");
  printf("\n");
  for (i = 0; i < MAXWORDLEN; i++){
    printf("[%4d]: ", i+1);
    for(l = lenfreq[i]; l>0; --l){
      putchar('*');
    }
    putchar('\n');
  }
  
  
  return 0;
}
