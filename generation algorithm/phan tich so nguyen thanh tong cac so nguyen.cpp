#include<iostream>
using namespace std;
#include<vector>
#define max 100
vector <int> kq;
int a[max], n, na=0;
void xuatCauHinh(){
	for(int i=0;i<kq.size();i++)
		cout<<kq[i]<<" ";
	cout<<endl;
	/*for(int i=0;i<na;i++)
		cout<<a[i]<<" ";
	cout<<endl;*/
}
int tong(){
	int s=0;
	for(int i=0;i<kq.size();i++)
		s+=kq[i];
	return s;
	/*for(int i=0;i<na;i++)
		s+=a[i];
	return s;*/
}
void phanTichSoNguyenThanhTongCacSoNguyen(int j){
	for(int i=n-1;i>=1;i--)
	{
		kq.push_back(i);
		//a[i]=j;
		if(tong()==n){
			xuatCauHinh();
		}
		else
		{
			if(tong()<n){
			//na++;	
				phanTichSoNguyenThanhTongCacSoNguyen(j+1);
			//na--;*/
				//kq.pop_back();
			}
			else
				//na--;
				kq.pop_back();
		}
		//kq.pop_back();
	/*	if(tong()<n){
			a[j]=i;
			phanTichSoNguyenThanhTongCacSoNguyen(j+1);
		}
		else
			if(tong()==n)
				xuatCauHinh();
			else
				na--;*/
	}
}
int main(int argc, char *argv[])
{
	cin>>n;
	phanTichSoNguyenThanhTongCacSoNguyen(0);
	return 0;
}
