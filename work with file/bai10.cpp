//MSSV:23110196
//Ho Ten SV: Vo Le Khanh Duy
//Ngay sinh: 26/3/2005
//Lop: 231101B-PRTE230385_23_2_04
#include<iostream>
#include<fstream>
#define max 100
#include<string.h>
using namespace std;
struct matHang{
	string maHang;
	string tenMatHang;
	int soLuong;
	int donGia;
	int soLuongTon;
	int thoiGianBaoHang;//thang
};
void nhapHang(matHang &a){
	cout<<"Nhap ma hang: ";
	cin.ignore();
	getline(cin,a.maHang);
	cout<<"Nhap ten mat hang: ";
	getline(cin,a.tenMatHang);
	cout<<"Nhap so luong: ";
	cin>>a.soLuong;
	cout<<"Nhap don gia: ";
	cin>>a.donGia;
	cout<<"Nhap so luong ton: ";
	cin>>a.soLuongTon;
	cout<<"Nhap thoi gian bao hanh: ";
	cin>>a.thoiGianBaoHang;
}
void nhapDS(matHang a[], int &n){
	cout<<"Nhap so luong mat hang: ";
	cin>>n;
	for(int i=0;i<n;i++)
		nhapHang(a[i]);
}
int main(){
	int n;
	matHang a[max];
	nhapDS(a,n);
	fstream f;
	f.open("D:\\data10.txt",ios::out);
	int soLuongTonMax=a[0].soLuongTon;
	int soluongTonMin=a[0].soLuongTon;
	int posMax=0;
	int posMin=0;
	int giaMax=a[0].donGia;
	int posGiaMax=0;
	for(int i=1;i<n;i++){
		if(a[i].soLuongTon>soLuongTonMax)
		{
			posMax=i;
			soLuongTonMax=a[i].soLuongTon;
		}
		if(a[i].soLuongTon<soluongTonMin)
		{
			posMin=i;
			soluongTonMin=a[i].soLuongTon;
		}
		if(a[i].donGia>giaMax)
		{
			giaMax=a[i].donGia;
			posGiaMax=i;
		}
	}
	f<<"Mat hang co so luong ton nhieu nhat: "<<a[posMax].tenMatHang<<endl;
	f<<"Mat hang co so luong ton it nhat: "<<a[posMin].tenMatHang<<endl;
	f<<"Mat hang co gia cao nhat: "<<a[posGiaMax].tenMatHang<<endl;
	
	f<<"Nhung mat hang co thoi gian bao hanh lon hon 12 thang: "<<endl;
	for(int i=0;i<n;i++){
		if(a[i].thoiGianBaoHang>12)
			f<<a[i].tenMatHang<<endl;
	}
	
	f<<"Mat hang theo thu tu tang dan so luong ton: "<<endl;
	int temp=soluongTonMin;
	while(temp<=soLuongTonMax){
		for(int i=0;i<n;i++)
			if(temp==a[i].soLuongTon)
				f<<a[i].tenMatHang<<endl;
		temp++;
	};
	f.close();
	return 0;
}
