#include <iostream> 
#include <algorithm>
#include <ctime>
#include <cstdlib>
#define Size 10
using namespace std;
bool cmp1(int i,int j){
  return (i<j);
}
bool cmp2(int i,int j){
  return (i>j);
}
void printA(int *a,int s){
  for(int i=0;i<s;i++){
    cout << a[i] << " ";
  }
  cout << endl;
}
int main () {
  int A[Size];
  srand(time(NULL));
  for (int i=0;i<Size;i++){ 
    A[i]=rand()%1000+1;
  }
  cout << "�Ƨǫe" << endl;
  printA(A,Size);
  sort(A,A+Size);
  cout << "�ϥ�sort(A,A+Size)�Ƨǫ�" << endl; 
  printA(A,Size);
  for (int i=0;i<Size;i++){ 
    A[i]=rand()%1000+1;
  }
  cout << "�Ƨǫe" << endl;
  printA(A,Size);
  sort(A,A+Size,cmp1);
  cout << "�ϥ�sort(A,A+Size,cmp1)�Ƨǫ�" << endl; 
  printA(A,Size); 
  for (int i=0;i<Size;i++){
    A[i]=rand()%1000+1;
  }
  cout << "�Ƨǫe" << endl;
  printA(A,Size);
  sort(A,A+Size,cmp2);
  cout << "�ϥ�sort(A,A+Size,cmp2)�Ƨǫ�" << endl; 
  printA(A,Size);
}
