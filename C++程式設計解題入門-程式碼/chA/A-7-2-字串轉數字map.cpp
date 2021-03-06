#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
map<string,int> nmap;	//使用map將name轉成數字
map<string,int>::iterator it; 
int getCityIndex(string p){	//將name轉成數字，數字從0開始 
  if (nmap.find(p)==nmap.end()){
    int s=nmap.size();
    nmap[p]=s;
  }
  return nmap[p];
} 
int main(){
  string s[5]={"台北市","新北市","台中市","台南市","高雄市"};
  for(int i=0;i<5;i++){
    int index=getCityIndex(s[i]);
    cout << s[i] << " " << index <<endl;
  }
  for(it=nmap.begin();it!=nmap.end();it++){
    cout << it->first << " " << it->second << endl;
  }	
}
