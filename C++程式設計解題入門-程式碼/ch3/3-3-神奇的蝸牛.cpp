#include<iostream>
using namespace std; 
int main() {     
  int h,d,n,day;
  double ch,down,r; 
  while(cin >> h){
    cin >> d >> n;
    day=0;//�ثe�ĴX�� 
    ch=0;//�ثe���氪�� 
    down=(double)n;//�ߤW���U�Ӫ��Z�� 
    r=n/10.0;//�C���h���U�Ӫ��W�[�Z��           
    while(1){
      day++;
      ch=ch+d;//�դѩ��W�� 
      if (ch >= h) break;//�����           
      ch=ch-down;//�ߤW���U��
			if (ch <= 0) break;//����a�W 
      down=down+r;//�C�ѧ�s���U�Ӫ��Z��     
    }
    if(ch >= h) cout << "��" << day << "�Ѫ����" << endl;
    if(ch <= 0) cout << "��" << day << "�ѱ���a��" << endl;                   
  }
}
