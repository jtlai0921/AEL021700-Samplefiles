#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
int v[50001];
bool test(int x){//�P�_���|��x�i�_�[�\�Ҧ����I
  int next,count=0;
  for(int i=0;i<n;){
	next=v[i]+x;
	count++;
	if (count > k) {//��a�x�ӼƤj��k
	  return false;
	}
	if ((v[n-1]<=next)&&(count<=k)) return true;//��F�̫�A�ȯ��A��a�x�ӼƤp�󵥩�k
    do{
      i++;
	}while (v[i] <= next);
  }
  return false;
}
int main(){
  int L,R,M,sta;
  while (cin>>n){
    cin >> k;
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    sort(v, v+n);
	if (k==1){
	  cout<< v[n-1]-v[0]<<endl;
	}else{
      L=1;//�̤p���|��1
      R=((v[n-1]-v[0])/k)+1;//�̤j���|((v[n-1]-v[0])/k)+1�@�w�i�H�]�t�Ҧ����I
      while(L<=R){//�ϥΤG���j�M
        M=(L+R)/2;
        if (test(M)) R=M;
        else L=M+1;
        if (L==R) break;
      }
      cout << R <<endl;
	}
  }
}
