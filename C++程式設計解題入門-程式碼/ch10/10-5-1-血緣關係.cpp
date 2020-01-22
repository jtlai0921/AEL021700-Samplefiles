#include <cstdio>
#include <deque>
#include <algorithm>
#define MAX 100001
using namespace std;
deque<int> F[MAX];
int md;
int DFS(int x) {
  int max1, max2, result;
  if (F[x].size() == 0) return 0;//�S���p�ġA���j����
  if (F[x].size() == 1) return DFS(F[x][0])+1;//�p�ĥu���@��
  else {//�p�ĶW�L��ӥH�W
	for (int i = 0; i<F[x].size(); i++) {//���X�C�@�Ӥp�ġA��X�̪��`�ת��e��W�A�̪��`���x�s��max1�A�ĤG���`���x�s��max2
	  result = DFS(F[x][i]) + 1;//�Ӥp�Ī��`��
	  if (i == 0) max1 = result; //���X�Ĥ@�Ӥp�Į�
	  else if (i == 1) {//���X�ĤG�Ӥp�Į�
	    if (max1 >= result) max2 = result;
		else {
		  int tmp = max1;
		  max1 = result;
		  max2 = tmp;
		}
	  } else {//���X�ĤT�ӥH�᪺�p�Į�
		if (max1 <= result) {
		  max2 = max1;
		  max1 = result;
		}else if (max2 < result) max2 = result;
	  }
	}
    md = max(md, max1 + max2);//�������`�I����פj�󵥩�2�A�̤j��t���Y���p�Ĥ��̪��`�׻P�ĤG���`�׬ۥ[
    return max1;//�ѤW��U��M�L�{�A��������ץu��1�ɡA�I�s�uDFS(F[x][0])+1�v�A�ݭn�^��DFS(F[x][0])�����G�A�N�O�^��max1
  }
}
int main() {
  int a, b,root,rd,n;
  bool isChild[MAX];
  while (scanf("%d", &n) != EOF) {
	md = 0;
	for (int i = 0; i<n; i++) {
	  F[i].clear();
	  isChild[i] = false;
	}
	for (int i = 1; i<n; i++) {//�إߥ����˨�p�Ī����V��
	  scanf("%d %d", &a, &b);
	  F[a].push_back(b);
	  isChild[b] = true;//b�O�p�ġA�]�wisChild��true
	}
	for (int i = 0; i < n; i++) {//��Xroot
	  if (!isChild[i]) {//�u�n�����g�O�p�ġA�N�Oroot
		root = i;
		break;
	  }
	}
	rd = DFS(root);//rd���qroot�X�o�̪����סA�禡DFS�L�{�|�p��l�]�`�I���h�Ӥp�Ī��̪���Ӥp�Ī��׬ۥ[��md
	md=max(rd,md);//md���l�]�`�I���h�Ӥp�Ī��̪���Ӥp�Ī��׬ۥ[�Ard�Pmd���̤j
	printf("%d\n", md);
  }
}
