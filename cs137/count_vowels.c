#include <stdio.h>
#include <ctype.h>

int count_vowels (const char *s)
{
  char vowels[] = {'a', 'e', 'i', 'o', 'u'};
  int count = 0;

  for (; *s; s ++)
    for (int i = 0; i < 5; i ++)
      if (tolower(*s) == vowels[i])
      {
        count ++;
        break;
      }
  return count;
}

int main (void)
{
  char *hi = "Hello" " wOrld";
  printf ("\"%s\" contains %d vowels\n", hi, count_vowels (hi));
}
