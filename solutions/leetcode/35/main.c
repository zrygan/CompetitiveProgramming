#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target)
{
  int low = 0, high = numsSize;

  while (low < high)
  {
    int mid = low + ((high - low) / 2);

    if (nums[mid] > target)
      high = mid; // no - 1
    else if (nums[mid] < target)
      low = mid + 1;
    else return mid;

  }

  return low;
}

#define n 2

int main()
{
  int nums[n] = {1,3};

  printf("%d", searchInsert(nums, n, 2));
}
