#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol320
{
  class Solution
  {
  private:
    static void _generate(int i, int n, string s, string &w, vector<string> &abbs);

  public:
    static vector<string> generate(string word);
  };
}
#endif