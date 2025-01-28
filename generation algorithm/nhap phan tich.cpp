#include<iostream>
using namespace std;
#include<vector>
#define max 100
vector <int> kq;
int a[max], n, na=0;
void xuatCauHinh(){
	for(int i=0;i<na;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int tong(){
	int s=0;
	for(int i=0;i<na;i++)
		s+=a[i];
	return s;
}
void phanTichSoNguyenThanhTongCacSoNguyen(int j){
	for(int i=n-1;i>=1;i--)
	{
		if(tong()<=n){
			a[j]=i;
			if(tong()==n)
				xuatCauHinh();
			else
			{
				phanTichSoNguyenThanhTongCacSoNguyen(j+1);
				na--;
			}
		}
		else
			na--;
	}
}
int main(int argc, char *argv[])
{
	cin>>n;
	phanTichSoNguyenThanhTongCacSoNguyen(0);
	return 0;
}
