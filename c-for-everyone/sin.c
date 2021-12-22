/* Sin function
 * Write a program that prints the sine ofs a 
 * number between 0 and 1 exclusive
 * 
 * Mohammed Ali
 * Dec 21, 2021
*/

#include <math.h>
#include <stdio.h>

int main(void)
{
  double a; double sine_a;
  printf("\nEnter a value between 0 and 1 (non inclusive)\n");
  scanf("%lf", &a);
  if(a <= 0 || a >= 1 ){
    printf("input must be between 0 and 1 (non inclusive)\n\n");
    return 0;
  }
  sine_a = sin(a);
  printf("The sine of %lf is: %lf\n\n", a, sine_a); 
  return 0;
}
