#include <iostream>
using namespace std;
int main(){
  int score[10]={45, 59, 62, 67, 70, 78, 83, 85, 88, 92};  
  int mid=5,left=0,right=9;
  while (score[mid] != 59){
    cout << "�ˬdscore[" << mid << "]=" << score[mid] << "�O�_����59" << endl; 
    if (left >=right){
      break;         
    }
    if (score[mid] > 59) {
      right=mid-1;       
    }else {
      left=mid+1;    
    }          
    mid=(left+right)/2;
    cout << "right��s��" << right << endl;
    cout << "left��s��" << left << endl; 
    cout << "mid��s��" << mid << endl;   
  }
  if (score[mid] == 59){
    cout << "���59��" << endl;               
  } else {
    cout << "�䤣��59��" << endl;     
  }
}
