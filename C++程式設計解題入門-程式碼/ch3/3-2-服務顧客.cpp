#include <iostream>
#include <cstring>
using namespace std;
int main(){
  int n,t,now,ans; 
  int arr[200],time[200],ser[600];
  while(cin >> t){
  	cin >> n;
  	for(int i=0;i<n;i++){
    	cin >> arr[i] >> time[i];      
  	}
  	memset(ser,0,sizeof(ser));
  	now=-1;//�A�ȥثe�ȤH�������ɶ� 
  	ans=0;
  	for(int i=0;i<n;i++){
  		if (now>=t*60) break; //�W�L�A�Ȯɶ� 
    	if (arr[i]>=now){//�ȤH���ߨ�έ�n�ȤH���} 
    		for(int j=arr[i];j<arr[i]+time[i];j++){
    			if (j>=t*60) break;//�W�L�A�Ȯɶ� 
					ser[j]=1;//ser[]��1�A��ܪA�ȫȤH 
				}
				now=arr[i]+time[i];//�A�ȥثe�ȤH�������ɶ� 
			}else{//�ȤH�ݭn���� 
    		for(int j=now;j<now+time[i];j++){
    			if (j>=t*60) break;//�W�L�A�Ȯɶ�
    			ser[j]=1;//ser[]��1�A��ܪA�ȫȤH
				}
				now=now+time[i];//�A�ȥثe�ȤH�������ɶ� 				
			}    
  	}
		for(int i=0;i<t*60;i++){//�p��S���ȤH���ɶ� 
    	if (ser[i]==0){
    		ans++;
			}     
  	}
		cout << ans << endl;  	
	}   
}
