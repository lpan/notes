#include <locale.h>
#include <wchar.h> // wchar_t, size is implementation dependent!

int main (void)
{
  wchar_t wc = L'\x3b1';
  setlocale (LC_ALL, "en_US.UTF-8");
  wprintf (L"%c\n", wc);
  wprintf (L"%zu\n", sizeof (wchar_t));

  return 0;
}
