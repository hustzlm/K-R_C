#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define MAXLINES 5000
#define ALLOCSIZE 100000
char *lineptr[MAXLINES];

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int (*comp) (void *, void *));
int numcmp(char *, char *);

main(int argc, char *argv[])
{
  int nlines;
  int numeric = 0;

  if(argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  if((nlines = readlines(lineptr, MAXLINES)) >= 0)
  {
    qsort((void **) lineptr, 0, nlines-1, (int (*) (void *, void *)) (numeric ? numcmp : strcmp));
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
