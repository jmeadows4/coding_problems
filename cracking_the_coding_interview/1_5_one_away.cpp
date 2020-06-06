#include<iostream>
#include<string>
#include<unordered_map>
#include<cstdlib>
using namespace std;


/* check if a string is one operation away from another string. operations you can preform: 
  * add a character
  * remove a character
  * swap a character
*/

bool one_away(string s1, string s2){
  int size;
  //if they are the same size, only a swap would work
  if(s1.size() == s2.size()){
    bool swapped = false;
    size = s1.size();
    for(int i = 0; i < size; i++){
      if(s1[i] != s2[i]){
        if(swapped){
          return false;
        }
        else{
          swapped = true;
        }
      }
    }
  }
  else{
    //if there is more than a 2 character difference between the strings, nothing can be done
    if(abs(int(s1.size() - s2.size())) > 2){
      return false;
    }
    //else, the difference between the strings is 1.
    //make it easier by naming the strings by size
    string bigger, smaller;
    if(s1.size() > s2.size()){
      bigger = s1;
      smaller = s2;
    }
    else{
      bigger = s2;
      smaller = s1;
    }
    //doesn't make a difference whether we insert or remove
    bool removed = false;
    int big_it = 0;
    for(int small_it = 0; small_it < smaller.size(); small_it++){
      if(bigger[big_it] != smaller[small_it]){
        if(removed){
          return false;
        }
        else{
          removed = true;
        }
        small_it -= 1;
      }
      big_it += 1;
    }
  }
  return true;
}

int main(){
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  bool ans = one_away(s1, s2);
  if(ans){
    cout << "They are one away!" << endl;
  }
  else{
    cout << "They are not one away." << endl;
  }
  return 0;
}
