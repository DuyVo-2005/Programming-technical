#include<iostream>
using namespace std;
#define max 100
void xuatCauHinh(int x[], int k){
	for(int i=1;i<=k;i++)
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
void sinhVaXuatCacHoanVi(int x[], int n){
	int i=n, k;
	while(i>0){
		xuatCauHinh(x,n);
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
void copy(int a[], int b[], int n){
	for(int i=1;i<=n;i++)
		b[i]=a[i];
}
void sinhChinhHop(int n, int k, int x[]){
	int i, tmp[max];
	for(i=1;i<=k;i++)
		x[i]=i;
	while(i>0){
		copy(x,tmp,k);//thao tac hoan vi tren mang tmp de khong lam bien doi mang x, mang se dung tiep de sinh to hop
		sinhVaXuatCacHoanVi(tmp,k);
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
	int n,k, x[max];// mang x de chua cac cau hinh
	cin>>n>>k;
	sinhChinhHop(n,k,x);
	return 0;
}
