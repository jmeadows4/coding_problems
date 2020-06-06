#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

/* replace all spaces in a string with "%20". True length of string is given. */
/* true length is the length of the final string */

string urlify(string s, int true_length){
  string url = s;
  int url_iter = url.size() - 1;
  //start from the back. fill in the new string unless you find a space
  for(int s_iter = true_length - 1; s_iter >= 0; s_iter--){
    if(s[s_iter] == ' '){
      url[url_iter] = '0';
      url[url_iter-1] = '2';
      url[url_iter-2] = '%';
      url_iter -= 3;
    }
    else{
      url[url_iter] = s[s_iter];
      url_iter -= 1;
    }
  }

  return url;
}

int main(){
  string s;
  int true_length;
  getline(cin, s);
  cin >> true_length;
  string url = urlify(s, true_length);
  cout << url << endl;

  return 0;
}
