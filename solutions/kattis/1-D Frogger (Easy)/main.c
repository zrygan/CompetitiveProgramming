#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, s, m;
  scanf("%d %d %d", &n, &s, &m);

  int *board = malloc(sizeof(int) * n + 1);
  for (int i = 1; i <= n; i++)
    scanf("%d", &board[i]);

  int moves = 0;

  while (1)
  {
    if (board[s] == m)
    {
      printf("magic\n");
      break;
    }

    if (board[s] == 0)
    {
      printf("cycle\n");
      break;
    }

    int t = s;
    s += board[s];
    moves++;
    board[t] = 0;

    if (s < 1)
    {
      printf("left\n");
      break;
    }

    if (s > n)
    {
      printf("right\n");
      break;
    }
  }

  printf("%d\n", moves);
  free(board);
  return 0;
}