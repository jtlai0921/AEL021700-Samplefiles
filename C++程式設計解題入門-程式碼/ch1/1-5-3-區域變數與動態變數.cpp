#include <iostream>
using namespace std;
int main(){
  int a[100000];//�ϰ��ܼơA�x�s�bstack�Ϭq 
  cout << a << endl;
  cout << a+1 << endl;
  cout << a+2 << endl;
  int *b;
  b=new int(100000);//�ʺA�ܼơA�x�s�bheap�Ϭq 
  cout <<b << endl;
  cout <<b+1 << endl;
  cout <<b+2 << endl;
}
