#include <iostream>
#include <list>
using namespace std;
void printList(list<int>);
int main(){
  list<int> mlist;
  list<int>::iterator it;
  mlist.push_back(1);
  printList(mlist);
  mlist.push_back(2);
  printList(mlist);
  mlist.push_back(4);
  printList(mlist);
  it = mlist.begin();
  it++;
  it++;
  mlist.insert(it,3);
  cout << "���J3��" << endl;
  printList(mlist); 
  mlist.remove(2);
  cout << "���X2��" << endl;
  printList(mlist); 
}
void printList(list<int> a){
  cout <<"�ثeLinkedList������ơG";
  list<int>::iterator it;
  for (it=a.begin(); it!=a.end();it++){ 
    cout << *it << ' ';
  }
  cout << endl;   
}
