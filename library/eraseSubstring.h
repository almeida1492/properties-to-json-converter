#include <string>

using namespace std;

void eraseSubstring(string &input, const string &toErase)
{
  int pos = input.find(toErase);

  if (pos != string::npos)
  {
    input.erase(pos, toErase.length());
  }
}
