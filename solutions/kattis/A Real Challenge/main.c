#include <stdio.h>
#include <math.h>

int main() {
  long long a;
  scanf("%lld", &a);
  printf("%.20f\n", 4 * sqrt((double)a));
  return 0;
}