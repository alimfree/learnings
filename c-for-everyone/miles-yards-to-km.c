
/* 
   Read in Miles and yards and return kilometers
   Mohammed Ali
   Dec, 18 2021
*/

#include <stdio.h>

int main(void)
{
  int miles, yards;
  double kilometers;
  printf("Input miles and yards as integers:");
  scanf("%d%d", &miles,  &yards);
  printf("miles = %d, yards = %d\n", miles, yards);
  kilometers = 1.609 * (miles + yards/1760.0);
  printf("kilometers = %f\n\n", kilometers);
  return 0;
}


