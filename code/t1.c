#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* print Fahrenheit-Celsius table
  for fahr = 0, 20, ..., 300 */

main()
{
/*  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;
*/
  int fahr;

  for(fahr = LOWER; fahr <= UPPER; fahr += STEP)
    printf("%3d%7.1f\n", fahr, 5.0 / 9.0 * (fahr - 32));
}
