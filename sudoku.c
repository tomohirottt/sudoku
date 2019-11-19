#include <stdio.h>
#include <stdbool.h>

void display(int nums[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", nums[i][j]);
        }
        printf("\n");
    }
}

void solve(int nums[9][9])
{
  bool filled = false;
    while (filled == false) {
      filled = true;
      for (int i = 0; i < 9; i++)
      {
          for (int j = 0; j < 9; j++)
          {
              if (nums[i][j] == 0)
              {
                  filled = false;
                  int matchnumber = 0;
                  int matchcount = 0;
                  for (int n = 1; n <=9; n++)
                  {
                      bool overlapping = false;
                      for (int k = 0; k < 9; k++)
                      {
                          if (nums[k][j] == n)
                          {
                              overlapping = true;
                          }
                      }

                      for (int l = 0; l < 9; l++)
                      {
                          if (nums[i][l] == n)
                          {
                              overlapping = true;
                          }
                      }

                      for (int k = i - (i % 3); (k % 3) < 2; k++)
                      {
                          for (int l = j - (j % 3); (l % 3) < 2; l++)
                          {
                              if (nums[k][l] == n)
                              {
                                  overlapping = true;
                              }
                          }
                      }

                      if (overlapping == false)
                      {
                          matchnumber = n;
                          matchcount++;
                      }

                  }

                  if (matchcount == 1)
                  {
                      nums[i][j] = matchnumber;
                  }
              }
          }
      }
    }
}

void main()
{
    int nums[9][9] = {
        {3, 8, 7, 0, 0, 6, 1, 0, 0},
        {0, 0, 5, 9, 0, 0, 3, 0, 0},
        {0, 9, 2, 0, 5, 0, 0, 0, 0},
        {0, 0, 8, 0, 6, 2, 9, 0, 0},
        {5, 6, 0, 4, 0, 0, 0, 7, 0},
        {0, 2, 4, 0, 1, 7, 0, 3, 0},
        {0, 4, 9, 3, 8, 0, 0, 0, 1},
        {8, 7, 0, 6, 2, 1, 4, 5, 0},
        {1, 5, 6, 7, 9, 4, 8, 2, 3}};
    display(nums);
    solve(nums);
    printf("\n");
    display(nums);
}
