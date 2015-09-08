#include <stdio.h>

void shellsort(int v[], int n)
{
  int gap, i, j, temp;
  for(gap = n/2; gap > 0; gap /= 2)
    for(i = gap; i < n; i++)
      for(j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
        {
          temp = v[j];
          v[j] = v[j+gap];
          v[j+gap] = temp;
        }
}

int main()
{
  int a[10];
  int i;
  a[0] = 3;
  a[1] = 6;
  a[2] = 1;
  a[3] = 7;
  a[4] = 0;
  a[5] = 9;
  a[6] = 2;
  a[7] = 8;
  a[8] = 4;
  a[9] = 5;
  for(i=0; i<10; i++)
    printf("%2d", a[i]);
  putchar('\n');
  shellsort(a, 10);
  for(i=0; i<10; i++)
    printf("%2d", a[i]);
  putchar('\n');
}
