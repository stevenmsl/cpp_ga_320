#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol320;

/* Example 1:
Input: "word"
Output:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/
tuple<string, vector<string>>
testFixture1()
{
  auto output = vector<string>{
      "word", "1ord", "w1rd", "wo1d", "wor1",
      "2rd", "w2d", "wo2", "1o1d", "1or1",
      "w1r1", "1o2", "2r1", "3d", "w3", "4"};
  return make_tuple("word", output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << Util::toString(get<1>(f)) << endl;
  auto result = Solution::generate(get<0>(f));
  cout << "result: " << Util::toString(result) << endl;
}

main()
{
  test1();
  return 0;
}