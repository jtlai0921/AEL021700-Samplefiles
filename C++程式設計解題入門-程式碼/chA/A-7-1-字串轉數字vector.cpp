#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<string> name;
vector<string>::iterator it;
int getCityIndex(string p){
  it=find(name.begin(),name.end(),p);  //�bname����M�r��p  
  if (it < name.end()) return it-name.begin();
  else if (it == name.end()){  //�䤣�� 
    name.push_back(p);         //�r��p�[�Jname     
    return name.size()-1;   
  } 
}
int main(){
  string s[5]={"�x�_��","�s�_��","�x����","�x�n��","������"};
  for(int i=0;i<5;i++){
    int index=getCityIndex(s[i]);
    cout << s[i] << " " << index <<endl;
  }
  for(int i=0;i<5;i++){
    cout << i <<" " << name[i] <<endl;
  }	
}
