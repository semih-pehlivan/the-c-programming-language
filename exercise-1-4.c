/*
 * Excercise 1-4: Write a program to print the corresponding Celsius to 
 * Fahrenheit table. 
 */

#include <stdio.h>

/* print Celcius-Farhenheit table
   for cel = -10, 0, ... 150; floating-point version */

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = -10;       /* lower limit of temperature table */
  upper = 150;      /* upper limit */
  step = 10;        /* step size */

  celsius = lower;

  printf("Cels  Fahr\n");
  printf("==========\n");
  
  while (celsius <= upper) {
    fahr = (celsius * (9.0/5.0)) + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius += step;
  }

  return 0;
}
