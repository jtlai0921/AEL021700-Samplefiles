#include <iostream>
#include <set>
#include <string>
#include <cctype>
using namespace std;
int main(){
  set<string> dic;
  set<string>::iterator it;
  string word;
  while(cin>>word){
    if (word == "EOI") break;
    for(int i=0;i<word.length();i++){
      if (isalpha(word[i])){
        word[i]=tolower(word[i]);
      } 
    }
    dic.insert(word);      
  }
  cout << "�H�U���Ҧ���r" << endl;
  for(it=dic.begin();it!=dic.end();it++){ 
    cout << *it<<endl;
  } 
}
