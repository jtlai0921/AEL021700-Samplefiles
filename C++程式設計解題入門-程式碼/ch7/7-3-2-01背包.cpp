#include <iostream>
#include <cstring>
using namespace std;
int v[101],w[101],k[1001],p[101][1001];
int ks,n; 
int main(){
  while(cin>>n){
    for(int i=0;i<n;i++){
      cin>>w[i]>>v[i];
    }
    cin>>ks;
    memset(k,0, sizeof(k)); 
    memset(p,-1, sizeof(p)); 
    for(int i=0;i<n;i++){
      for(int j=ks;j>=w[i];j--){
        if (k[j-w[i]]+v[i]>k[j]){ 
          k[j]=k[j-w[i]]+v[i]; 
          p[i][j]=i; 
        }       
      }    
    } 
    cout << "�I�]�̤j�����Ȭ�" << k[ks] << endl;
    int j=ks;  
    for (int i=n-1;i>=0;i--){
      if(p[i][j]>=0){
        cout << "�N��"<<i+1<<"�Ӫ��~��J�I�]"<<endl;
        j-=w[i];
      }
    }
  }
}
