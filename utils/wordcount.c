#include <stdio.h>

#define INWORD 0
#define OUTWORD 1

/* Counts lines, words and characters in stdin */
int main(){
  int c, nl, nw, nc, state;

  state = OUTWORD;
  nl = nw = nc = 0;

  while ( (c = getchar()) != EOF ){
    ++nc;
    switch(c){
      case '\n':
        ++nl;
      case ' ':
      case '\t':
        state = OUTWORD;
        break;
      default:
        if(state == OUTWORD){
          ++nw;
        }
        state = INWORD;
    }
  }
  printf("lines: %d\nwords: %d\ncharacters: %d\n", nl, nw, nc);
  return 0;
}
