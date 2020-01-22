#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
struct node{
  int id;//���ޭ�
  char ch;//�r�� 
  int w;//�W�v 
  bool t;//t��true��ܬ��r���`�I 
  int le;//���䪺���ޭ� 
  int ri;//�k�䪺���ޭ� 
};
node hf[101];
deque<node> tmp;
char code[10];
bool cmp(node a,node b){//�W�v�V�֪��ƫe�� 
  return a.w<b.w;
}
void dfs(int id,int level){//��dfs���X�Ҧ��`�I�A�L�X�r���P�������s�X 
  if (!hf[id].t){
    code[level]='0';//����s�X0 
    dfs(hf[id].le,level+1);
    code[level]='1';//�k��s�X1 
    dfs(hf[id].ri,level+1);
  }else{
    cout << hf[id].ch <<" ";
    for(int i=0;i<level;i++) cout << code[i];
    cout << endl;
  }
}
int main(){
  int n,w,num;
  char c;
  while(cin>>n){
    tmp.clear();
    for(int i=0;i<n;i++){
      cin >> c >> w; 
      hf[i].id=i;
      hf[i].ch=c;
      hf[i].w=w;
      hf[i].t=true;
      tmp.push_back(hf[i]);
    }
    num=n;
    sort(tmp.begin(),tmp.end(),cmp);//�W�v�V�֪��ƫe�� 
    while(tmp.size()>1){
      node a,b,s;
      a=tmp.front();
      tmp.pop_front();
      b=tmp.front();
      tmp.pop_front();
      s.id=num;
      s.t=false;
      s.le=a.id;
      s.ri=b.id;
      s.w=a.w+b.w;
      hf[num]=s;
      tmp.push_back(s);
      sort(tmp.begin(),tmp.end(),cmp);//�W�v�V�֪��ƫe�� 
      num++;
    }
    dfs(tmp[0].id,0);
  }
}
