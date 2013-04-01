/*
 * Exercise 1-16: Revise the main routine of the longest line program so it 
 * will correctly print the length of arbitrarily long input lines, and as 
 * much as possible of the text.
 */

#include <stdio.h>
#include "chapter1.h"

#define MARGIN 1 

/* Note that the length of the line must be longer than the long line suffix
   block. See NOTE_LINE_MAXLINE */
#if MARGIN
  /* This will depend on how wide the margin notes are.
     See NOTE_MARGIN_WIDTH for relevant code. */
  #define MAXLINE 66
#else
  #define MAXLINE 80
#endif


/*
 * Re-scoped. Now takes input and truncates smartly, letting long lines be 
 * shortened while still displaying their true length in the margin. Running
 * the program on its own source code is instructive.
 */
int main(){
  int len, linum, buflen, fraglen;
  char line[MAXLINE];
  char buf[MAXLINE];

  linum = 1;
  while((len = bgetline(line,MAXLINE)) > 0){
    
    /* Is this a full line? */
    if (line[len-1] == '\n'){
      /* yes */
#if MARGIN
      /* NOTE_WIDTH_MARGIN: The margin width is 14 as follows: */
      printf(" %04d (%4d): ",linum, len);
#endif
      printf(line);
      linum++;
    }else{
      /* no - We loop over getline until it is, 
         keeping a secondary buffer filled up. */
      while((fraglen = bgetline(buf,MAXLINE)) > 0){
        len += fraglen;
        if (buf[fraglen-1] == '\n'){
          /* We've reached the end of this long line.
             NOTE_LINE_MAXLINE:
             We write the end of the long line to the beginning buffer using a 
             split marker to show we've reduced it. Note that this will 
             restrict the minimum size of MAXLINE in order to fit the line 
             suffix. */
          buflen = bstrlen(buf);
          copy((char *) line+MAXLINE-19, " [...] ");
          copy((char *) line+MAXLINE-12, (char*)((buflen>12)?(buf+buflen-12):buf) );
#if MARGIN
          /* NOTE_WIDTH_MARGIN: The margin width is 14 as follows: */
          printf(" %04d (%4d): ",linum, len);
#endif
          printf(line);
          ++linum;
          break;
        }
      }
    }

  }
  return 0;
}
