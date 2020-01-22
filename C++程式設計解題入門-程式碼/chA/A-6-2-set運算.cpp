#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
int main () {
  int p[5] = {1,3,5,7,9};
  int q[5] = {2,3,4,5,6};
  vector<int> u(10),i(10),d(10);   
  vector<int>::iterator it;
  sort(p,p+5);
  sort(q,q+5);
  cout << "p���X�������G"; 
  for(int j=0;j<5;j++) cout << p[j] <<" ";
  cout << endl;
  cout << "q���X�������G"; 
  for(int j=0;j<5;j++) cout << q[j] <<" ";
  cout << endl;
  it=set_union(p,p+5,q,q+5,u.begin());                                      
  u.resize(it-u.begin());
  cout << "�p�����G��"<<endl;    
  for (it=u.begin(); it!=u.end(); ++it){
    cout  << *it << ' ';	
  }
  cout << endl;
  it=set_intersection(p,p+5,q,q+5,i.begin());                                      
  i.resize(it-i.begin());
  cout << "�涰���G��"<<endl;    
  for (it=i.begin(); it!=i.end(); ++it){
    cout  << *it << ' ';	
  }
  cout << endl;  
  it=set_difference(p,p+5,q,q+5,d.begin());                                      
  d.resize(it-d.begin());
  cout << "�t�����G��"<<endl;    
  for (it=d.begin(); it!=d.end(); ++it){
    cout  << *it << ' ';	
  }
  cout << endl;
}
