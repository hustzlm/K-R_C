#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000
#define MAXLINES 5000
#define ALLOCSIZE 100000
char *lineptr[MAXLINES];

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort1(void *lineptr[], int left, int right, int (*comp) (void *, void *));
int numcmp(char *, char *);

main(int argc, char *argv[])
{
  int nlines;
  int numeric = 0;

  if(argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  if((nlines = readlines(lineptr, MAXLINES)) >= 0)
  {
    qsort1((void **) lineptr, 0, nlines-1, (int (*) (void *, void *)) (numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  }
  else
  {
    printf("input too big to sort\n");
    return 1;
  }
}

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

void writelines(char *lineptr[], int nlines)
{
  while(nlines-- > 0)
    printf("%s\n", *lineptr++);
}

void qsort1(void *v[], int left, int right, int (*comp) (void *, void *))
{
  int i, last;

  void swap(void *[], int, int);

  if(left >= right)
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for(i=left+1; i<=right; i++)
    if((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort1(v, left, last-1, comp);
  qsort1(v, last+1, right, comp);
}

int numcmp(char *s1, char *s2)
{
  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);
  if(v1 < v2)
    return -1;
  else if(v1 > v2)
    return 1;
  else
    return 0;
}

void swap(void *v[], int i, int j)
{
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
