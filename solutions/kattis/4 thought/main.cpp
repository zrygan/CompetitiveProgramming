#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

int eval_expr(vector<string> tokens)
{
  for (int i = 1; i < tokens.size() - 1;)
  {
    if (tokens[i] == "*")
    {
      int left = stoi(tokens[i - 1]);
      int right = stoi(tokens[i + 1]);
      tokens[i - 1] = to_string(left * right);
      tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
    }
    else if (tokens[i] == "/")
    {
      int left = stoi(tokens[i - 1]);
      int right = stoi(tokens[i + 1]);
      if (right == 0)
        return 1e9; // Avoid divide-by-zero
      tokens[i - 1] = to_string(left / right);
      tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
    }
    else
    {
      i += 2;
    }
  }

  int result = stoi(tokens[0]);
  for (int i = 1; i < tokens.size(); i += 2)
  {
    int val = stoi(tokens[i + 1]);
    if (tokens[i] == "+")
      result += val;
    else if (tokens[i] == "-")
      result -= val;
  }
  return result;
}

int main()
{
  int m;
  cin >> m;
  vector<int> n(m);
  for (int i = 0; i < m; i++)
    cin >> n[i];

  unordered_map<int, string> combos;
  string ops[4] = {"+", "-", "*", "/"};
  // combos[0] = "4 * 4 - 4 * 4"

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < 4; k++)
      {
        stringstream ss;
        ss << "4 " << ops[i] << " 4 " << ops[j] << " 4 " << ops[k] << " 4";
        string expr = ss.str();

        stringstream ts(expr);
        vector<string> tokens;
        string tok;
        while (ts >> tok)
          tokens.push_back(tok);

        int val = eval_expr(tokens);
        if (combos.find(val) == combos.end())
        {
          combos[val] = expr;
        }
      }
    }
  }

  for (int i = 0; i < m; i++)
  {
    if (combos.find(n[i]) != combos.end())
      cout << combos[n[i]] << " = " << n[i] << endl;
    else
      cout << "no solution" << endl;
  }
}
