/* Distance of a marathon in yards
   ABC page 11 - variation 
   
   Mohammed Ali
   Dec 18, 2018
*/

#include <stdio.h>

int main(void)
{
  int miles = 26, yards = 385; 
  double kilometers; 
  
  kilometers = 1.609 * (miles + yards/1760.0);
  printf("\nA marathon is %lf kilometers.\n", kilometers);
  return 0;
}
