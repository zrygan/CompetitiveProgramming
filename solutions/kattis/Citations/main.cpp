#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Book
{
  int readtime;
  vector<int> citations;
};

int n;
vector<Book> books;
vector<int> size_subtree;
vector<int> D_subtree;
long long total_borrow_time = 0;

void compute_size_and_D(int u)
{
  if (books[u].citations.empty())
  {
    size_subtree[u] = 1;
    D_subtree[u] = 1 + books[u].readtime;
    return;
  }
  
  int s = 1;
  int d = 1 + books[u].readtime;

  for (int c : books[u].citations)
  {
    compute_size_and_D(c);
    s += size_subtree[c];
    d += D_subtree[c];
  }
  
  size_subtree[u] = s;
  D_subtree[u] = d;
}

int dfs(int u, int start_time)
{
  // include self
  int curr_time = start_time + 1;

  // sort citations, prio the least read time
  sort(books[u].citations.begin(), books[u].citations.end(), [](int a, int b)
       {
        double ra = (double)size_subtree[a] / D_subtree[a];
        double rb = (double)size_subtree[b] / D_subtree[b];
        return ra > rb; });

  for (int c : books[u].citations)
    curr_time = dfs(c, curr_time);

  curr_time += books[u].readtime;
  total_borrow_time += curr_time;
  return curr_time;
}

int main()
{
  cin >> n;
  books.resize(n + 1);
  size_subtree.resize(n + 1);
  D_subtree.resize(n + 1);

  vector<bool> has_parent(n + 1, false);

  for (int i = 1; i <= n; i++)
  {
    int t, k;
    cin >> t >> k;
    books[i].readtime = t;
    books[i].citations.resize(k);
    for (int j = 0; j < k; j++)
    {
      cin >> books[i].citations[j];
      has_parent[books[i].citations[j]] = true;
    }
  }

  int root = 1;
  for (int i = 1; i <= n; i++)
  {
    if (!has_parent[i])
    {
      root = i;
      break;
    }
  }

  compute_size_and_D(root);
  dfs(root, 0);

  cout << total_borrow_time;
}
