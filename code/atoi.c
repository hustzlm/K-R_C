#include <ctype.h>
#include <stdio.h>

int atoi(char s[])
{
  int i, sign, n;
  n = 0;
  for(i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '-' || s[i] == '+')
    i++;
  while(isdigit(s[i]))
  {
    n = 10 * n + s[i] - '0';
    i++;
  }
  return sign * n;
}

int main()
{
  char s[] = "   +1235cs3";
  int n;
  n = atoi(s);
  printf("%d\n", n);
  return 0;
}
