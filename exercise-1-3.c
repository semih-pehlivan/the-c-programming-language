/*
 * Excercise 1-3: Modify the temperature program to print a heading above the 
 * table 
 */

#include <stdio.h>

/* print Farhenheit-Celcius table
   for fahr = 0, 20, ... 300; floating-point version */

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 20;       /* lower limit of temperature table */
  upper = 300;      /* upper limit */
  step = 20;        /* step size */

  fahr = lower;

  printf("Fahr  Cels\n");
  printf("==========\n");
  
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
  return 0;
}
