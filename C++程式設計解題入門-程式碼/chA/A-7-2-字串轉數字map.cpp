#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
map<string,int> nmap;	//�ϥ�map�Nname�ন�Ʀr
map<string,int>::iterator it; 
int getCityIndex(string p){	//�Nname�ন�Ʀr�A�Ʀr�q0�}�l 
  if (nmap.find(p)==nmap.end()){
    int s=nmap.size();
    nmap[p]=s;
  }
  return nmap[p];
} 
int main(){
  string s[5]={"�x�_��","�s�_��","�x����","�x�n��","������"};
  for(int i=0;i<5;i++){
    int index=getCityIndex(s[i]);
    cout << s[i] << " " << index <<endl;
  }
  for(it=nmap.begin();it!=nmap.end();it++){
    cout << it->first << " " << it->second << endl;
  }	
}
