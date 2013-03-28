/*
 * Excercise 1-6: Verify that the expression getchar() != EOF is 0 or 1. 
 */

#include <stdio.h>

int main()
{
  int exprval;
  while((exprval = (getchar() != EOF)) ) {
    printf("Value of [getchar() != EOF] is %d\n", exprval);
  }
  printf("Value of [getchar() != EOF] is %d\n", exprval);
  return 0;
}
