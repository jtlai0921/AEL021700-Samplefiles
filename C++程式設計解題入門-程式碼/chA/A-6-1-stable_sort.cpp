#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;
bool cmpfi(double i,double j){
  return ((int)i<(int)j);
}
int main () {
  double num[] = {5.2, 3.4, 3.2, 4.6, 3.3};
  vector<double> mvec;
  vector<double>::iterator it;
  cout << "��l���" << endl; 
  for(int i=0;i<5;i++) cout << num[i] << ' ';
  cout << endl;
  mvec.assign(num,num+5);
  stable_sort(mvec.begin(),mvec.end());
  cout << "�ϥίB�I�ƶi�����P�Ƨ�" << endl; 
  for (it=mvec.begin(); it!=mvec.end(); ++it){
    cout  << *it << ' ';
  }
  cout << endl;
  mvec.assign(num,num+5);
  stable_sort(mvec.begin(),mvec.end(),cmpfi);
  cout<<"�N�B�I���ন��ƦA�i�����P�Ƨ�"<<endl;
  for (it=mvec.begin(); it!=mvec.end(); ++it){
    cout  << *it << ' ';
  }
  cout << endl;
}
