/*
    Solution (1) by Zhean Ganituen (zrygan)
    For Leetcode #18
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    int n = nums.size();
    vector<vector<int>> quads;

    if (n < 4)
      return quads;

    sort(nums.begin(), nums.end());

    for (int a = 0; a < n - 3; a++)
    {
      if (a > 0 && nums[a] == nums[a - 1])
        continue;

      for (int b = a + 1; b < n - 2; b++)
      {
        if (b > a + 1 && nums[b] == nums[b - 1])
          continue;

        for (int c = b + 1; c < n - 1; c++)
        {
          if (c > b + 1 && nums[c] == nums[c - 1])
            continue;

          for (int d = c + 1; d < n; d++)
          {
            if (d > c + 1 && nums[d] == nums[d - 1])
              continue;

            long long sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];

            if (sum == target)
            {
              quads.push_back({nums[a], nums[b], nums[c], nums[d]});
            }
          }
        }
      }
    }
    return quads;
  }
};