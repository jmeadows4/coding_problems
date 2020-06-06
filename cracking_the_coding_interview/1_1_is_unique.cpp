#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

/* Implement an algorithm to determine if a string has all unique characters.

   (Not solved)What if you cannot use additional data structures? */

bool is_unique(string s){

  unordered_map<char, int> char_count;
  unordered_map<char, int>::iterator it;
  const int size = s.size();
  for(int i = 0; i < size; i++){
    it = char_count.find(s[i]);
    if(it == char_count.end()){
      char_count.insert({s[i], 1});
    }
    else{
      return false;
    }
  }
  return true;
}

int main(){
  string s;
  cin >> s;
  bool ans = is_unique(s);
  if(ans){
    cout << "Your string is unique." << endl;
  }
  else{
    cout << "Your string is not unique." << endl;
  }


  return 0;
}
