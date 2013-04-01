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
#define MAXWORDLEN 30

/* Histogram style */
#define HISTOHEIGHT 20
#define COLUMN_FULL "|"
#define COLUMN_EMPTY "."

int main(){
  int c, wl, i, l, maxfreq;
  double scale;
  
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
  
  /*
   * Scale all historgram numbers.
   * 
   * Take the highest frequency to be HISTOHEIGHT, and scale all others 
   * appropriately
   */
  maxfreq = 0;
  for( i = 0; i < MAXWORDLEN; i++){
    if (lenfreq[i] > maxfreq)
      maxfreq = lenfreq[i];
  }
  scale = (double) HISTOHEIGHT / (double) maxfreq;

  for( i = 0; i < MAXWORDLEN; i++){
    lenfreq[i] = lenfreq[i] * scale;
  }

  /* 
   * 
   */

  printf("Word length histogram:\n\n");
  
  for( l = HISTOHEIGHT; l > 0; --l){
    printf("  ");
    for( i = 0; i < MAXWORDLEN; i++){
      if(lenfreq[i] >= l){
        printf(COLUMN_FULL);
      }else{
        printf(COLUMN_EMPTY);
      }
    }
    printf("\n");
  }
  printf("\n");
   
  return 0;
}
