#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
/* Given two strings, check if one is a permutation of the other. */


/* make a map for each string. Check one map against the other
   to see if they have the same count for each character. */
bool check_permutation(string s1, string s2){

  if( s1.size() != s2.size() ){
    return false;
  }

  const int size = s1.size();
  unordered_map<char, int> char_map1;
  unordered_map<char, int> char_map2;
  unordered_map<char, int>::iterator it;
  //make a map with the character count of first string
  for(int i = 0; i < size; i++){
    if(char_map1.find(s1[i]) == char_map1.end()){
      char_map1[s1[i]] = 1;
    }
    else{
      char_map1[s1[i]] += 1;
    }
  }
  //make a map with the character count of second string
  for(int i = 0; i < size; i++){
    if(char_map2.find(s2[i]) == char_map2.end()){
      char_map2[s2[i]] = 1;
    }
    else{
      char_map2[s2[i]] += 1;
    }
  }
  //iterate through the map and check if the counts are equal for
  //each character
  for(it = char_map1.begin(); it != char_map1.end(); it++){
      char val = it -> first;
      if (char_map2.find(val) != char_map2.end()){
        if ( char_map2[val] != it -> second){
          return false;
        }
      }
      else{
        return false;
      }
  }
  return true;
}


int main(){
  string s1, s2;
  cin >> s1 >> s2;
  bool ans = check_permutation(s1, s2);
  if(ans){
    cout << "One string is a permutation of the other." << endl;
  }
  else{
    cout << "They are not permutations of each other." << endl;
  }
}
