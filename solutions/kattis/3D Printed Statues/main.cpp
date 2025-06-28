#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n;
  cin >> n;

  cout << ceil(1 + log(n) / log(2));
  return 0;
}