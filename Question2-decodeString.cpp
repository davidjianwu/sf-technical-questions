#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string decodeString(string s);

int main() {
  string input;
  cout << "Enter a string to decode" << endl;
  cin >> input;
  cout << decodeString(input) << endl;
  return 0;
}

string decodeString(string s) {
  int recentOpeningIndex;
  int recentClosingIndex;
  string retVal = s;
  while(1) {
    //check if done
    for (int i = 0; i < retVal.length(); i++) {
      if(retVal[i] == '[') {
        break;
      }
      if(i == retVal.length()-1) {
        return retVal;
      }
    }
    for(int i = 0; i < retVal.length(); i++) {
      if(retVal[i] == '[') {
        recentOpeningIndex = i;
      }
      if(retVal[i] == ']') {
        recentClosingIndex = i;
        break;
      }
    }
    string sub = retVal.substr(recentOpeningIndex+1,recentClosingIndex-recentOpeningIndex-1);
    //cout << "Sub ==== " << sub << endl;
    string substr = "";
    string reps = retVal.substr(recentOpeningIndex-1,1);
    for(int i = 0; i < stoi(reps); i++) {
      substr += sub;
    }
    retVal.erase(recentOpeningIndex-1,recentClosingIndex-recentOpeningIndex+2);
    //cout << "After Erase: " << retVal << endl;
    retVal.insert(recentOpeningIndex-1,substr);
    //cout << "Iteration: " << retVal << endl;
  }
}
