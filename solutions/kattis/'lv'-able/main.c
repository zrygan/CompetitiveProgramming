#include <stdio.h>
#include <stdlib.h>

int lv(int N, char *s)
{
  int has_l = 0, has_v = 0;

  for (int i = 0; i < N; i++)
  {
    if (s[i] == 'l')
      has_l = 1;
    if (s[i] == 'v')
      has_v = 1;

    if (i < N - 1 && s[i] == 'l' && s[i + 1] == 'v')
      return 0;
  }

  return (has_l || has_v) ? 1 : 2;
}

int main()
{
  int N;
  char *s;

  scanf("%d", &N);

  s = malloc(N + 1);
  scanf("%s", s);

  printf("%d", lv(N, s));

  free(s);

  return 0;
}