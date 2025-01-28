#include<iostream>
using namespace std;
#define max 100
int n,k, x[max];
void xuatCauHinh(){
	for(int i=1;i<=k;i++)
		cout<<x[i]<<" ";
	cout<<endl;
}
void sinhToHop(){
	int i;
	for(i=1;i<=k;i++)
		x[i]=i;
	while(i>0){
		xuatCauHinh();
		i=k;
		while(i>0&&x[i]==n-k+i)
			i--;
		if(i>0){
			x[i]++;
			for(int j=i+1;j<=k;j++)
				x[j]=x[j-1]+1;
		}
	}
}
int main(){
	cin>>n>>k;
	sinhToHop();
	return 0;
}
