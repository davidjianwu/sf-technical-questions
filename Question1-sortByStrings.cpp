#include <iostream>
#include <string>

std::string sortByStrings(std::string s, std::string t);

int main() {
  std::cout << sortByStrings("weather","therapyw") << std::endl;
  std::cout << sortByStrings("good","odg") << std::endl;
  return 0;
}

std::string sortByStrings(std::string s, std::string t) {
  std::string sortedString = "";
  for(int i = 0; i < t.length(); i++) {
    for(int j = 0; j < s.length(); j++) {
      if(t[i] == s[j]) {
        sortedString += s[j];
      }
    }
  }
  return sortedString;
}
