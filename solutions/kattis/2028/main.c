#include <stdio.h>

void process_line(int line[4], int reverse)
{
  int tmp[4] = {0};
  int idx = 0;

  if (!reverse)
  {
    for (int i = 0; i < 4; i++)
    {
      if (line[i] != 0)
        tmp[idx++] = line[i];
    }

    for (int i = 0; i < 3; i++)
    {
      if (tmp[i] != 0 && tmp[i] == tmp[i + 1])
      {
        tmp[i] *= 2;
        tmp[i + 1] = 0;
      }
    }

    int final[4] = {0};
    idx = 0;
    for (int i = 0; i < 4; i++)
    {
      if (tmp[i] != 0)
        final[idx++] = tmp[i];
    }

    for (int i = 0; i < 4; i++)
      line[i] = final[i];
  }
  else
  {
    for (int i = 3; i >= 0; i--)
    {
      if (line[i] != 0)
        tmp[idx++] = line[i];
    }

    for (int i = 0; i < 3; i++)
    {
      if (tmp[i] != 0 && tmp[i] == tmp[i + 1])
      {
        tmp[i] *= 2;
        tmp[i + 1] = 0;
      }
    }

    int final[4] = {0};
    idx = 0;
    for (int i = 0; i < 4; i++)
    {
      if (tmp[i] != 0)
        final[idx++] = tmp[i];
    }

    for (int i = 0; i < 4; i++)
      line[i] = final[3 - i];
  }
}

int main()
{
  int grid[4][4];

  for (int i = 0; i < 4; i++)
    scanf("%d %d %d %d", &grid[i][0], &grid[i][1], &grid[i][2], &grid[i][3]);

  int move;
  scanf("%d", &move);

  if (move == 0 || move == 2)
  {
    for (int i = 0; i < 4; i++)
      process_line(grid[i], move == 2);
  }
  else
  {
    for (int i = 0; i < 4; i++)
    {
      int col[4];
      for (int j = 0; j < 4; j++)
        col[j] = grid[j][i];

      process_line(col, move == 3);

      for (int j = 0; j < 4; j++)
        grid[j][i] = col[j];
    }
  }

  for (int i = 0; i < 4; i++)
    printf("%d %d %d %d\n", grid[i][0], grid[i][1], grid[i][2], grid[i][3]);

  return 0;
}