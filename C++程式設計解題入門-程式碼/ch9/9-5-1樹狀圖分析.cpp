#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define MAX 100001
using namespace std;
int p[MAX];//p[i]=j�A���i�����ˬ�j
int d[MAX];//�����`�I�`��
int num[MAX];//�����`�I���l�`�I�ӼơA�l�`�I�p��L��N��1
deque<int> t;//�x�s���`�I
int main(){
  int n,k,c;
  long long int sum;//1+2+3+...+100000�A�|�W�Xint�d��
  while (scanf("%d",&n) != EOF) {
    sum = 0;
    memset(d,-1,sizeof(d));
    memset(p,0,sizeof(p));
    memset(num,0,sizeof(num));
    for (int i = 1; i<=n; i++) {
      scanf("%d",&k);
      if (k == 0){
        t.push_back(i);//���`�I
        d[i]=0;//���`�I�`�׬�0
      }else{
        num[i]=k;
        for(int j=0;j<k;j++){
          scanf("%d",&c);
          p[c] = i;//�ϥΰ}�Cp����c��parent��i
        }
      }
    }
    int node;
    while(!t.empty()){
      node = t.front();//���X���`�I
      t.pop_front();
      d[p[node]]=max(d[p[node]],d[node]+1);//���ۤv���`�׻P�q�l�`�I�[1�����j��
      num[p[node]]--;//�qt�����X��A�Ӹ`�I�����˸`�I�Ӽƴ�1
      if (num[p[node]] == 0){//��Ҧ��l�`�I�����X�L��
        t.push_back(p[node]);//�[�J�Ӹ`�I���C
      }
    }
    for (int i = 1; i<=n; i++) {
      sum += d[i];
    }
    cout << node << endl;//�̫�@�ӱqt���X���N�Oroot
    cout << sum << endl;
  }
}
