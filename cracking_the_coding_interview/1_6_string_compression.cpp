#include<iostream>
#include<string>
using namespace std;

/* Compress strings in this format:
   aabcccccaaa -> a2b1c5a3
   if the resulting string is not any shorter,
   return the original string.
*/

string compress_string(string s){
  string ans = "";
  int cur_count = 1;
  bool all_ones = true;
  const int size = s.size();
  for(int i = 0; i < size - 1; i++){
    if(s[i] == s[i+1]){
      all_ones = false;
      cur_count += 1;
    }
    else{
      ans += s[i];
      ans += to_string(cur_count);
      cur_count = 1;
    }
  }
  if(all_ones){
    return s;
  }
  ans += s[s.size()-1];
  ans += to_string(cur_count);
  return ans;

}

int main(){
  string s;
  cin >> s;
  string ans = compress_string(s);
  cout << ans << endl;

}
