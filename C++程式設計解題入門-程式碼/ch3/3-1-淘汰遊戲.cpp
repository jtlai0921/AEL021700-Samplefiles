#include<iostream>
#include<cstring>
#define Size 101
using namespace std;
int main(){
  bool a[Size];
  int n,p,leave,c,i;
  while(cin >> n){
    cin >> p;
  	leave=0;//leave��ܤw�g�^�O���H��
  	i=2;//�Ĥ@�Ӥ��^�O
  	memset(a,0,sizeof(a));
  	while(leave<(n-1)){
  	  c=0;//c��ܶ��j�X�ӤH
  	  while(c<p){
  		if (a[i]==0){//�٨S�^�O
  		  c++;//���j�H�ƼW�[1
  		  if (i<n) i++;
  		  else i=1;//�^��s��1��
		  }else{
  		  if (i<n) i++;
  		  else i=1;//�^��s��1��				
		  }
	  }
	  while(a[i]==1){//�Y�w�g�^�O�A��U�@�ӥ��^�O
		  if (i<n) i++;
  	    else i=1;
	    }
	    a[i]=1;//�^�O
	    leave++;//�w�g���}�H�ƼW�[1
	  }
	  for(int j=1;j<=n;j++){//��X�̫᥼�^�O�s��
	    if (a[j]==0){
		    cout << j <<endl;
		    break; 
	    }
	  }
  }
}
