#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "library/removeWhiteSpaces.h"
#include "library/eraseSubstring.h"
#include "library/split.h"

using namespace std;

int main()
{
  fstream inputFile;
  inputFile.open("source/for_use_openhospital_bundle-language-en-properties--develop_en.properties", ios::in);

  fstream outputFile;
  outputFile.open("dist/output.json", ios::out);

  if (inputFile.is_open() & outputFile.is_open())
  {
    string line;
    char delimiter = '=';
    int bracketPairsCounter = 0;
    string currentObject = "";

    cout << "Processing file..." << endl;

    outputFile << "{" << endl;

    while (getline(inputFile, line))
    {
      int pos = line.find(delimiter);
      string path = line.substr(0, pos);
      string value = line.substr(pos + 1, line.length());

      removeWhiteSpaces(path);
      // removeWhiteSpaces(value);

      eraseSubstring(path, "angal.");

      vector<string> keys = split(path, '.');

      for (int i = 0; i < keys.size(); i++)
      {
        if (i != keys.size() - 1)
        {
          currentObject = keys[i];
          outputFile << "\"" + currentObject + "\"" + ": {" << endl;
          bracketPairsCounter++;
        }
        else
          outputFile << "\"" + keys[i] + "\": ";
      }

      outputFile << "\"" + value + "\"" << endl;

      while (bracketPairsCounter > 1)
      {
        outputFile << "}" << endl;
        bracketPairsCounter--;
      }
      outputFile << "}," << endl;
      bracketPairsCounter = 0;
    }

    outputFile << "}" << endl;

    inputFile.close();
    outputFile.close();

    cout << "Done!" << endl;
  }
  else
  {
    cout << "Couldn't open the file. :(" << endl;
  }
}
