#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream> 
using namespace std;
int f[13],s[13];
int PokerToNum(string s){//�N���J�P���P�Ʀr�ন�Ʀr0��51 
  int suit,num;
  switch(s[1]){//�Ʀr�GA�ন12�A2�ন0 
    case 'A':
	  num=12;
	  break;
    case 'K':
	  num=11;
	  break;
    case 'Q':
	  num=10;
	  break;
    case 'J':
	  num=9;
	  break;
	  case 'T':
	  num=8;
	  break;
	  default:
	  num=s[1]-'2';
	  break;
  }
  switch(s[0]){//���G�±�C���0�A�®�S���3 
    case 'C':
	  suit=0;
	  break;
    case 'D':
	  suit=1;
	  break;
    case 'H':
	  suit=2;
	  break;
    case 'S':
	  suit=3;
	  break;
  }
  return (suit*13+num);
}
bool IsSF(int *poker){//�P�ᶶ 
  if ((poker[4]-poker[0])==4){
    if ((poker[0]>=0)&&(poker[4]<13)) return true;
    if ((poker[0]>=13)&&(poker[4]<26)) return true;
    if ((poker[0]>=26)&&(poker[4]<39)) return true;
    if ((poker[0]>=39)&&(poker[4]<52)) return true;
  }
  return false;
}
bool IsF(int *poker){//�P�� 
  if ((poker[0]>=0)&&(poker[4]<13)) return true;
  if ((poker[0]>=13)&&(poker[4]<26)) return true;
  if ((poker[0]>=26)&&(poker[4]<39)) return true;
  if ((poker[0]>=39)&&(poker[4]<52)) return true;
  return false;
}
int fL(int *poker){//�p��Ĥ@��P���j�p 
  if (IsSF(poker)) return 9; //�P�ᶶ
  for(int i=0;i<13;i++) {
	  if (f[i]==4) return 8; //�|��
  }
  for(int i=0;i<13;i++) {
	  if (f[i]==2) {
	    for(int j=i+1;j<13;j++) {
        if (f[j]==3) return 7; //��Ī
	    }
	  }
	  if (f[i]==3) {
	    for(int j=i+1;j<13;j++) {
        if (f[j]==2) return 7; //��Ī
	    }
	  }
  }
  if (IsF(poker)) return 6; //�P�� 
  for(int i=0;i<9;i++) {
	  if ((f[i]==1)&&(f[i+1]==1)&&(f[i+2]==1)&&(f[i+3]==1)&&(f[i+4]==1)) {
      return 5; //���l
	  }
  }
  for(int i=0;i<13;i++) {
	  if (f[i]==3) {
      return 4; //�T�� 
	  }
  }
  for(int i=0;i<13;i++) {
	  if (f[i]==2) {
	    for(int j=i+1;j<13;j++) {
        if (f[j]==2) return 3; //���
	    }
	  }
  }
  for(int i=0;i<13;i++) {
        if (f[i]==2) return 2; //�@�� 
  }
  return 1;//���P
}
int sL(int *poker){//�p��ĤG��P���j�p
  if (IsSF(poker)) return 9; //�P�ᶶ
    for(int i=0;i<13;i++) {
	    if (s[i]==4) return 8; //�|��
    }
    for(int i=0;i<13;i++) {
	    if (s[i]==2) {
	    for(int j=i+1;j<13;j++) {
        if (s[j]==3) return 7; //��Ī
	    }
	  }
	  if (s[i]==3) {
	    for(int j=i+1;j<13;j++) {
        if (s[j]==2) return 7; //��Ī
	    }
	  }
  }
  if (IsF(poker)) return 6; //�P��
  for(int i=0;i<9;i++) {
	  if ((s[i]==1)&&(s[i+1]==1)&&(s[i+2]==1)&&(s[i+3]==1)&&(s[i+4]==1)) {
      return 5; //���l
	  }
  }
  for(int i=0;i<13;i++) {
	  if (s[i]==3) {
      return 4; //�T��
	  }
  }
  for(int i=0;i<13;i++) {
	  if (s[i]==2) {
	    for(int j=i+1;j<13;j++) {
        if (s[j]==2) return 3; //���
	    }
	  }
  }
  for(int i=0;i<13;i++) {
    if (s[i]==2) return 2; //�@��
  }
  return 1;//���P 
}
int winloss(int level){
  int fh,sh;
  if (level==9) { //�P�ᶶ 
    for(int i=12;i>3;i--){//��X�Ĥ@��P���̰���
	    if (f[i]==1) {
		    fh=i;
		    break;
	    }
	  }
    for(int i=12;i>3;i--){//��X�ĤG��P���̰���
	    if (s[i]==1) {
		    sh=i;
	  	  break;
	    }
	  }
	  if (fh>sh) return 1;
	  if (fh<sh) return -1;
  }
  if (level==8) { //�|�� 
    for(int i=12;i>=0;i--){//��X�Ĥ@��P���̰���
	    if (f[i]==4) {
		    fh=i;
		    break;
	    }
	  }
    for(int i=12;i>=0;i--){//��X�ĤG��P���̰���
	    if (s[i]==4) {
		    sh=i;
		    break;
	    }
	  }
	  if (fh>sh) return 1;
	  if (fh<sh) return -1;
  }
  if (level==7) { //��Ī
    for(int i=12;i>=0;i--){//��X�Ĥ@��P���̰���
	    if (f[i]==3) {
		    fh=i;
		    break;
	    }
	  }
    for(int i=12;i>=0;i--){//��X�ĤG��P���̰���
	    if (s[i]==3) {
		    sh=i;
		    break;
	    }
	  }
	  if (fh>sh) return 1;
	  if (fh<sh) return -1;
  }
  if (level==6) { //�P�� 
    for(int i=12;i>=0;i--){//�Ѱ���C 
	    if ((f[i]==1)&&(s[i]==0)) {//�Ĥ@�즳�A�ĤG��S��
		    return 1;
	    }
	    if ((f[i]==0)&&(s[i]==1)) {//�Ĥ@��S���A�ĤG�즳
		    return -1;
	    }
	  }
  }
  if (level==5) { //���l 
    for(int i=12;i>=0;i--){//��X�Ĥ@��P���̰���
	    if (f[i]==1) {
		    fh=i;
		    break;
	    }
	  }
    for(int i=12;i>=0;i--){//��X�ĤG��P���̰���
	    if (s[i]==1) {
		    sh=i;
		    break;
	    }
	  }
	  if (fh>sh) return 1;
	  if (fh<sh) return -1;
  }
  if (level==4) { //�T�� 
    for(int i=12;i>=0;i--){//��X�Ĥ@��P���̰���
	    if (f[i]==3) {
		    fh=i;
		    break;
	    }
	  }
    for(int i=12;i>=0;i--){//��X�ĤG��P���̰���
	    if (s[i]==3) {
		    sh=i;
		    break;
	    }
    }
	  if (fh>sh) return 1;
	  if (fh<sh) return -1;
  }
  if (level==3) { //��� 
    for(int i=12;i>=0;i--){
	    if ((f[i]==2)&&(s[i]<2)) {//�Ĥ@�즳�@��A�ĤG��S���@��
		    return 1;
	    }
	    if ((f[i]<2)&&(s[i]==2)) {//�Ĥ@��S���@��A�ĤG�즳�@��
		    return -1;
	    }
	  }
  }
  if (level==2) { //�@�� 
    for(int i=12;i>=0;i--){
	    if ((f[i]==2)&&(s[i]<2)) {//�Ĥ@�즳�@��A�ĤG��S���@��
		    return 1;
	    }
	    if ((f[i]<2)&&(s[i]==2)) {//�Ĥ@��S���@��A�ĤG�즳�@��
		    return -1;
	    }
	  }
  }
  if (level==1) { //���P 
    for(int i=12;i>=0;i--){//��X�Ĥ@��P�ĤG��P�A�Ĥ@�Ӥ��ۦP����
	    if ((f[i]==1)&&(s[i]==0)) {
		    return 1;
	    }
	    if ((f[i]==0)&&(s[i]==1)) {
		    return -1;
	    }
	  }
  }
}
int main(){
  int fp[5],sp[5],fLevel,sLevel;
  string line,str;
  int result;
  while(getline(cin,line)){
	  istringstream iss(line);
	  memset(s,0,sizeof(s));
	  memset(f,0,sizeof(f));
	  for(int i=0;i<5;i++){
	    iss >> str;
	    fp[i]=PokerToNum(str);//���*13+�ƭ�   ���:0-3,�ƭ�:0-12
  	}
	  for(int i=0;i<5;i++){
	    iss >> str;
	    sp[i]=PokerToNum(str);//���*13+�ƭ�   ���:0-3,�ƭ�:0-12
	  }
	  for(int i=0;i<5;i++){
	    f[fp[i]%13]++;//�p��Ĥ@��C�ӵP�Ʀr�X�{���W�v
	  }
	  for(int i=0;i<5;i++){
	    s[sp[i]%13]++;//�p��ĤG��C�ӵP�Ʀr�X�{���W�v
	  }
	  sort(fp,fp+5);//�̷Ӫ��P�ȱƧǲĤ@��P
	  sort(sp,sp+5);//�̷Ӫ��P�ȱƧǲĤG��P
	  fLevel=fL(fp);//�o��Ĥ@��P��level
	  sLevel=sL(sp);//�o��ĤG��P��level
	  if (fLevel > sLevel) cout << "�Ĥ@�쪱�a���"<<endl;
	  else if (fLevel < sLevel) cout << "�ĤG�쪱�a���"<<endl;
	  else {
      result=winloss(fLevel);//�ۦP�P���̷��D�رԭz�D�X���G
	    if (result == 1) cout << "�Ĥ@�쪱�a���"<<endl;
	    if (result == -1) cout << "�ĤG�쪱�a���"<<endl;
	  }
  }
}
