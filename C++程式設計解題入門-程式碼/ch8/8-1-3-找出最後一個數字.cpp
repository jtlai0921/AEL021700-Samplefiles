#include <iostream>
#include <queue>
using namespace std;
int main(){
  int n,v;
  queue<int> q;
  while(cin >>n){
    for(int i=0;i<n;i++){
      cin >> v;
      q.push(v);
    }
    while(q.size()>1){
      v=q.front();
      cout << "�N"<<v<<"�[��̫�" << endl;
      q.pop();
      q.push(v);
      v=q.front();
      cout << "�N"<<v<<"�[��̫�" << endl;
      q.pop();
      q.push(v);
      v=q.front();
      cout << "�N"<<v<<"�R��" << endl;
      q.pop();      
    }
    cout << "�Ѿl�̫�@�Ӹ��X��"<<q.front()<<endl; 
  }
}
