#include<iostream>
#include<algorithm>
using namespace std;
struct job{
  int x;
  int ic; 
};
bool cmp1(job a,job b){ 
  if (a.ic==b.ic) a.x<b.x;//�Y��Q�ۦP�A�I��ɶ������Ʀb�e��
  return a.ic>b.ic;//��Q�����Ʀb�e��
}
bool cmp2(job a,job b){
  return a.x<b.x;//�I��ɶ������Ʀb�e��
}
int main(){
  int n,now,c;
  job jb[101],ans[101];
  while(cin>>n){
    for(int i=0;i<n;i++){
      cin >> jb[i].x >> jb[i].ic; 
    }
    sort(jb,jb+n,cmp1);//��Q�����Ʀb�e���A�Y��Q�ۦP�A�I��ɶ������Ʀb�e��
    ans[0]=jb[0];//�}�Cans�x�s�T�w�|���檺�u�@ 
    c=1;
    for(int i=1;i<n;i++){
      int j;
      bool found=false;
      for(j=0;j<c;j++){//�Njb[i]�[�J�|�v�T�A��jb[i].x�ۦP�Τj�@�I(�S���ۦP��)�I��ɶ� 
        if (ans[j].x >= jb[i].x){//��M�}�Cans����x�A���S���j��ε���jb[i].x���u�@ 
          found=true;
          break;
        }
      }
      while((found)&&(j<(c-1))&&(ans[j+1].x==ans[j].x)) j++;//�N�}�Cans�����̫ᤣ����ans[j].x���������� 
      if (!found){//�Y�}�Cans����x�S���j�󵥩�jb[i].x�Ajb[i]�i�H����[�J�}�Cans 
        ans[c]=jb[i];
        c++;
        sort(ans,ans+c,cmp2);//�I��ɶ������Ʀb�e��
      }else	if ((j+1)<jb[i].x) {//�Y�}�Cans����x�������j�󵥩�jb[i].x�A(j+1)��ܥثe�p��ε���jb[i].x�ӼơA�Y (j+1)<jb[i].x��ܦ����B 
        ans[c]=jb[i];
        c++;
        sort(ans,ans+c,cmp2);//�I��ɶ������Ʀb�e��
      }
    }
    int sum=0;
    for(int i=0;i<c;i++){
      sum+=ans[i].ic;
    }
    cout << sum << endl;
  }
}
