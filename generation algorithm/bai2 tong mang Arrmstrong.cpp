#include<iostream>
using namespace std;
#include<math.h>
int a[]={1,5,3,11,153,1634,999};//mang Amstrong, so armstrong 1,5,3,153,1634
int n=7;//so luong phan tu mang
int demChuSo(int n){
	int count=0;
	while(n>0){
		count++;
		n/=10;
	}
	return count;
}
bool kiemTraSoAmstrong(int n){
	int tong=0;
	int tmp=n;
	int k=demChuSo(n);//ky so
	while(tmp>0){
		tong+=pow(tmp%10,k);
		tmp/=10;
	}
	if(tong==n)
		return true;
	return false;
}
int tongPhanTuMangAmstrong(int a[]){
	int tong=0;
	for(int i=0;i<n;i++)
		if(kiemTraSoAmstrong(a[i]))
			tong+=a[i];
	return tong;
}
int main(){
	int tong=tongPhanTuMangAmstrong(a);
	cout<<tong;
	return 0;
}

