#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
/* Check if you can rearrange a string so that it is a palindrome */

/* map the string and see if the number of characters is divisible by two.
   Remember that there can be a single middle character. */
bool make_palindrome(string s){
  unordered_map<char, int> char_count;
  const int size = s.size();
  for(int i = 0; i < size; i++){
    if(char_count.find(s[i]) == char_count.end()){
      char_count[s[i]] = 1;
    }
    else{
      char_count[s[i]] += 1;
    }
  }
  unordered_map<char, int>::iterator it;
  bool middle_taken = false;
  for(it = char_count.begin(); it != char_count.end(); it++){
    if(it->second % 2 != 0){
      if(middle_taken){
        return false;
      }
      else{
        middle_taken = true;
      }
    }
  }
  return true;
}

int main(){
  string s;
  getline(cin, s);
  bool ans = make_palindrome(s);
  if(ans){
    cout << "It is possible to make a palindrome." << endl;
  }
  else{
    cout << "It is not possible to make a palindrome." << endl;
  }
  return 0;
}
