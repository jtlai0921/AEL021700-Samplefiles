#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
  return a<b;
}
int main(){
  int n,now,wait;
  int jb[101];
  while(cin>>n){
    for(int i=0;i<n;i++){
      cin >> jb[i]; 
    }
    sort(jb,jb+n,cmp);//�Ѥp��j�Ƨ� 
    now=0;
    wait=0;//�`���ݮɶ� 
    for(int i=0;i<n-1;i++){
      now+=jb[i];
      wait+=now;
    }
    cout << (double)wait/n << endl;
  }
}
