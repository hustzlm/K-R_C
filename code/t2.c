#include <stdio.h>

main()
/*{
  int c;

  c = getchar();
  while(c != EOF)
  {
    putchar(c);
    c = getchar();
  }
}*/

{
  int c;

  while((c = getchar()) != EOF)
    putchar(c);

  printf("EOF:%d\n", EOF);
}
