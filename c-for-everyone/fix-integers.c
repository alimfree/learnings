/* Fix Dr P's mistake integers
 * Mohammed Ali
 * Dec 20, 2021
*/

#include<stdio.h>
#define PI 3.14159
int main(void)
{ 
 double radius;
 printf("Enter radius:");
 scanf("%lf", &radius);
 printf("volume is : %lf \n\n", 4*PI*radius*radius*radius/3);
 return 0;
}
