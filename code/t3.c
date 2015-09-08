#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
  int cc,lc,wc,c,state;
  cc = 0;
  lc = 0;
  wc = 0;
  state = OUT;
  while((c = getchar()) != EOF)
  {
    cc++;
    if(c == '\n')
      lc++;
    if(c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if(state == OUT)
    {
      state = IN;
      wc++;
    }
  }
  printf("character:%d\tline:%d\tword:%d\n", cc, lc, wc);
}
