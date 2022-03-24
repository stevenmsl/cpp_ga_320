#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>
using namespace sol320;
using namespace std;

/*takeaways
  - given a abbreviation, you can go either way recursively
    - keep abbreviating it
    - or treat it as new string and start all over again
  - use "word" as an example
    - we rush to the end and abbreviate everything into a number: 4.
      We record it, and it is the first abbreviation we found
    - we then backtrack a step and look at "3d", which means the first
      three chars have been abbreviated but we keep the 4th char d
      - treat it as a new baseline
      - nothing to look at after the char "d", so we are done here and
        we record "3d" as the second abbreviation
    - we backtrack again and now look at "2r"
      - we have two choices here
      - abbreviate the next char d and get 2r1. Record 2r1
      - or we choose to have a new baseline 2rd
        - which we can't get any further. Record 2rd
*/

void Solution::_generate(int i, int n, string abbred, string &w, vector<string> &abbs)
{
  if (i == w.size())
  {
    if (n != 0)
      abbred += to_string(n);
    abbs.push_back(abbred);
    return;
  }

  /* keep abbreviating until you can't */
  _generate(i + 1, n + 1, abbred, w, abbs);
  /* backtrack and start over with a new baseline
     - one example is s=2r, which comes from "2"+w[2]
     - what we are saying here is to treat 2r as if
       it's a new string we want to abbreviate, but
       nothing has been abbreviated yet. That's why
       we set n to zero
  */
  auto newBL = abbred + (n == 0 ? "" : to_string(n)) + w[i];
  _generate(i + 1, 0, newBL, w, abbs);
}

vector<string> Solution::generate(string word)
{
  auto abbs = vector<string>();
  _generate(0, 0, "", word, abbs);
  return abbs;
}