#include <algorithm>
#include <cctype>
#include <iterator>

using namespace std;

void removeWhiteSpaces(string &input)
{
  input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
}
