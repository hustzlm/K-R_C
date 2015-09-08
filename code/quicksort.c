#include <stdio.h>

void qsort(int v[], int left, int right)
{
  int i, last;
  void swap(int v[], int i, int j);

  if(left >= right)
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for(i = left + 1; i <= right; i++)
  {
    if(v[i] < v[left])
      swap(v, ++last, i);
  }
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

void swap(int v[], int i, int j)
{
  int temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
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
  qsort(a, 0, 9);
  for(i=0; i<10; i++)
    printf("%2d", a[i]);
  putchar('\n');
}
