#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int bitcount(unsigned x)
{
  int b;
  for(b = 0; x != 0; x >>= 1)
    if(x & 01)
      b++;
  return b;
}

int max(int a, int b)
{
  return (a > b) ? a : b;
}

void printline(int a[], int n)
{
  int i;
  for(i = 0; i < n; i++)
    printf("%6d%c", a[i], (i%10 == 9 || i == n - 1) ? '\n' : ' ');
}

int binsearch(int x, int a[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while(low <= high)
  {
    mid = (low + high) / 2;
    if(x < a[mid])
      high = mid - 1;
    else if(x > a[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

void reverse(char s[])
{
  int i, j, temp;
  for(i=0, j=strlen(s)-1; i<j; i++, j--)
  {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}

void itoa(int n, char s[])
{
  int i, sign;
  if((sign = n) < 0)
    n = -n;
  i = 0;
  do
  {
    s[i++] = n % 10 + '0';
  } while((n /= 10) > 0);
  if(sign<0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

int trim(char s[])
{
  int n;
  for(n = (strlen(s) - 1); n >= 0; n--)
    if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
      break;
  s[n+1] = '\0';
  return n+1;
}

// double atof(char s[])
// {
//   int i, sign;
//   double val, power;
//   for(i = 0; isspace(s[i]); i++)
//     ;
//   sign = (s[i] == '-') ? -1 : 1;
//   if(s[i] == '-' || s[i] == '+')
//     i++;
//   for(val=0.0; isdigit(s[i]); i++)
//     val = 10.0*val + s[i]-'0';
//   if(s[i] == '.')
//     i++;
//   for(power=1.0; isdigit(s[i]); i++)
//   {
//     val = 10*val + s[i]-'0';
//     power *= 10;
//   }
//   return sign*val/power;
// }

int main()
{
  // int i;
  // int a[93];
  // int n = 2;
  //
  // for(i = 0; i < 93; i++)
  //   a[i] = i;
  //
  // printline(a, 93);
  //
  // printf("You have %d item%s.\n", n, (n == 1) ? "" : "s");
  // printf("You have 2 items.");

  // int i;
  // int a[10];
  // for(i = 0; i < 10; i++)
  //   a[i] = i;
  // for(i = 0; i < 10; i++)
  //   printf("%d\t", binsearch(i, a, 10));
  // int ndigit[10];
  // int nwhite, nother, c, i;
  // for(i = 0; i < 10; i++)
  //   ndigit[i] = 0;
  // while((c = getchar()) != EOF)
  // {
  //   switch (c)
  //   {
  //     case '0': case '1': case '2': case '3': case '4':
  //     case '5': case '6': case '7': case '8': case '9':
  //       ndigit[c-'0']++;
  //       break;
  //     case ' ':
  //     case '\t':
  //     case '\n':
  //       nwhite++;
  //       break;
  //     default:
  //       nother++;
  //       break;
  //   }
  // }
  // for(i = 0; i < 10; i++)
  //   printf("%2d", ndigit[i]);
  //
  // char* s;
  // int n = 12350;
  // itoa(n ,s);
  // printf("%s\n", s);

  char s[] = "    -234.902";
  double f;
  f = atof(s);
  printf("%f\n", f);
}
