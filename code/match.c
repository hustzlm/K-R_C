#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
  char line[MAXLINE];
  int found = 0;

  while(getline(line, MAXLINE) > 0)
    if(strindex(line, pattern) >= 0)
    {
      printf("%s", line);
      found++;
    }
  return found;
}
/* getline: get line into s, return length */
int getline(char s[], int limit)
{
  int c, i;
  for(i = 0; i < limit-2 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if(c == '\n')
    s[i++] = '\n';
  s[i] = '\0';
  return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
  int i, j, k;
  for(i=0; i <= strlen(s)-strlen(t); i++)
  {
    for(j=i, k=0; s[j] == t[k] && t[k] != '\0'; j++, k++)
      ;
    if(t[k] == '\0' && k > 0)
      return i;
  }
  return -1;
}
