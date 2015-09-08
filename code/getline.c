#include <stdio.h>

int getline(char *s, int limit)
{
  int c, i;
  for(i = 0; i < limit-2 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if(c == '\n')
    s[i++] = '\n';
  s[i] = '\0';
  return i;
}
