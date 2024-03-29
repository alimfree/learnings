/* Mohammed Ali Dec, 25, 2021
 * iteration and loops page 165 ABC chapter 4
*/

#include <stdio.h>

int main(void)
{
  int blanks = 0, digits = 0, letters = 0, others = 0;
  int c;	// use for int value of character
  while((c = getchar()) != EOF )
  {
    if (c == ' ')
      ++blanks;
    else if ( c >= '0' && c <= '9')
      ++digits;
    else if ( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
      ++letters; 
    else
      ++others;
  }
  printf(" blanks = %d, digits = %d, letters = %d,",
	  blanks, digits, letters);
  printf(" others = %d\n\n", others);
  return 0;
}
