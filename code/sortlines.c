#include <string.h>
#include <stdio.h>

#define MAXLINE 1000
#define MAXLINES 5000
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int getline(char *s, int maxline)
{
  int i, c;
  for(i = 0; i < maxline-2 && (c = getchar()) != EOF && c != '\n'; i++)
    *s++ = c;
  if(c == '\n')
  {
    *s++ = '\n';
    i++;
  }
  *s = '\0';
  return i;
}

char *alloc(int n)
{
  if(allocbuf + ALLOCSIZE - allocp >= n)
  {
    allocp += n;
    return allocp - n;
  }
  else
    return NULL;
}

int readlines(char *lineptr[], int maxlines)
{
  char line[MAXLINE];
  char *p;
  int nlines, len;
  nlines = 0;
  while((len = getline(line, MAXLINE)) > 0)
    if(nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else
    {
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

void qsortline(char *lineptr[], int left, int right)
{
  int i, last;
  void swap(char *lineptr[], int i, int j);

  if(left >= right)
    return;
  swap(lineptr, left, (left + right)/2);
  last = left;
  for(i = left + 1; i <= right; i++)
  {
    if(strcmp(lineptr[i], lineptr[left]) < 0)
      swap(lineptr, ++last, i);
  }
  swap(lineptr, left, last);
  qsortline(lineptr, left, last-1);
  qsortline(lineptr, last+1, right);
}

void swap(char *v[], int i, int j)
{
  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void writelines(char *lineptr[], int nlines)
{
  while(nlines-- > 0)
    printf("%s\n", *lineptr++);
}

int main()
{
  char *lines[MAXLINES];
  int nlines;
  if((nlines = readlines(lines, MAXLINES)) >= 0)
  {
    qsortline(lines, 0, nlines-1);
    writelines(lines, nlines);
    return 0;
  }
  else
  {
    printf("error: input too big to sort\n");
    return 1;
  }
}
