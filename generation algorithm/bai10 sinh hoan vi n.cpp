#include<iostream>
using namespace std;
#define max 100
int n, x[max];
void xuatCauHinh(){
	for(int i=1;i<=n;i++)
		cout<<x[i]<<" ";
	cout<<endl;
}
void hoanVi(int &x, int &y){
	int tmp=x;
	x=y;
	y=tmp;
}
void daoChuoi(int x[], int n, int begin, int end){
	while(begin<end){
		hoanVi(x[begin],x[end]);
		begin++;
		end--;
	}
}
void sinhHoanVi(int n){
	int i,k;
	for(i=1;i<=n;i++)
		x[i]=i;
	while(i>0){
		xuatCauHinh();
		i=n-1;
		while(i>0&&x[i]>x[i+1])
			i--;
		if(i>0){//chua phai cau hinh cuoi
			k=n;
			while(x[k]<x[i])
				k--;
			hoanVi(x[i],x[k]);
			daoChuoi(x,n,i+1,n);
		}
	}
}
int main(){
	cin>>n;
	sinhHoanVi(n);
	return 0;
}
