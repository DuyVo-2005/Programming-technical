/* Ma so sinh vien: 23110196
 Ho va ten sinh vien: Vo Le Khanh Duy
 Ngay sinh:26/3/2005
 Lop:231101B-PRTE230385_23_2_04
*/
#include<iostream>
using namespace std;
#define max 10000
int n;
int Fibo[max];
int main(){
	cin>>n;
	Fibo[1]=Fibo[2]=1;
	for(int i=3;i<=n;i++){
		Fibo[i]=Fibo[i-1]+Fibo[i-2];
	}
	for(int i=1;i<=n;i++)
		cout<<Fibo[i]<<"\n";
	return 0;
}
