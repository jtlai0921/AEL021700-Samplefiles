#include <iostream>
#include <cmath>
using namespace std;
bool mark[10001]; //�D�ϥοz��k�D��ơAtrue�D���  false��� 
void erase(int x){
  int sq = (int)sqrt(x);
  mark[1] = true;//1���O��� 
  for (int i=2; i<=sq; i++){
    if (!mark[i]){//�N2,3,5...���ƪ��ƬҤ��O��� 
      for (int j=i*i;j<=x;j+=i){
        mark[j] = true;
      }
    }
  }
}
int main(){
  erase(10000);//�Ұʿz��k�D��� 
  for(int n=2;n<=10000;n++){   
    if (!mark[n]){
      cout << n <<endl;               
    }  
  }
}
