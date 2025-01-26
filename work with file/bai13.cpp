//MSSV:23110196
//Ho Ten SV: Vo Le Khanh Duy
//Ngay sinh: 26/3/2005
//Lop: 231101B-PRTE230385_23_2_04
#include<iostream>
#define max 100
#include<string.h>
using namespace std;
struct dauSach{
	string MaSSach;
	string TenSach;
	string TacGia;
	int SL;
};
void nhapDauSach(dauSach &a){
	cin.ignore();
	cout<<"\nNhap ma so sach: ";
	getline(cin,a.MaSSach);
	cout<<"\nNhap ten sach: ";
	getline(cin,a.TenSach);
	cout<<"\nNhap tac gia: ";
	getline(cin,a.TacGia);
	cout<<"\nNhap so luong: ";
	cin>>a.SL;
}
void nhapDS(dauSach a[], int &n){
	do{
		cout<<"\nNhap so luong dau sach (toi thieu 1, toi da 100): ";
		cin>>n;
	}while(n>100||n<1);
	for(int i=0;i<n;i++){
		nhapDauSach(a[i]);
	}
}
void xuatDauSach(dauSach a){
	cout<<"\nMa so sach: "<<a.MaSSach;
	cout<<"\nTen sach: "<<a.TenSach;
	cout<<"\nTac gia: "<<a.TacGia;
	cout<<"\nSo luong: "<<a.SL;
}
bool checkSachCoTrongDS(dauSach a[], int n, string nameOfBook){
	for(int i=0;i<n;i++)
		if(a[i].TenSach==nameOfBook)
			return true;
	return false;
}
void inThongTinVeSach(dauSach a[], int n, string nameOfBook){
	bool flag=false;
	int i=0;
	for(;i<n;i++)
		if(a[i].TenSach==nameOfBook)
		{
			flag=true;
			break;
		}
	if(flag){
		cout<<"\nThong tin quyen sach vua nhap: ";
		for(;i<n;i++){
			if(a[i].TenSach==nameOfBook)
				xuatDauSach(a[i]);
		}
	}
	else
		cout<<"\nKhong tim thay";
}
int tongSach(dauSach a[], int n){
	int tong=0;
	for(int i=0;i<n;i++)
		tong+=a[i].SL;
	return tong;
}
int main(){
	dauSach a[101];
	int n;
	nhapDS(a,n);
	
	string nameOfBook;
	cout<<"\nNhap ten quyen sach can tim: ";
	cin.ignore();
	getline(cin,nameOfBook);
	inThongTinVeSach(a,n,nameOfBook);
	
	cout<<"\nTong so sach co trong thu vien: "<<tongSach(a,n);
	return 0;
}
