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
  printf("Enter a value between 0 and 1 (non inclusive)");
  scanf("%lf", &a);
  sine_a = sin(a);
  printf("The sine of %lf is: %lf\n", a, sine_a); 
  return 0;
}
