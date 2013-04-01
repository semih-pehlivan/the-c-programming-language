/*
 * Excercise 1-15: Rewrite the temperature conversion program of section 1.2 to
 * use a function for conversion.
 */

#include <stdio.h>


float fahr2cel(float fahr){
  return (5.0/9.0) * (fahr-32.0);
}


int main()
{
  float fahr;
  int lower, upper, step;

  lower = 20;       /* lower limit of temperature table */
  upper = 300;      /* upper limit */
  step = 20;        /* step size */

  fahr = lower;

  printf("Fahr  Cels\n");
  printf("==========\n");
  
  while (fahr <= upper) {
    printf("%3.0f %6.1f\n", fahr, fahr2cel(fahr));
    fahr = fahr + step;
  }
  return 0;
}
