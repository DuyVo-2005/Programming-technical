//MSSV:23110196
//Ho Ten SV: Vo Le Khanh Duy
//Ngay sinh: 26/3/2005
//Lop: 231101B-PRTE230385_23_2_04
#include<iostream>
#define max 100
#include<string.h>
using namespace std;
struct VIDEO{
	string tenPhim;
	string theLoai;
	string tenDaoDien;
	string tenDienVienNamChinh;
	string tenDienVienNuChinh;
	int namSanXuat;
	string hangSanXuat;
};
void nhapVideo(VIDEO &a){
	cout<<"Nhap ten phim: ";
	getline(cin,a.tenPhim);
	cout<<"Nhap the loai (hinh su, tinh cam, hai): ";
	getline(cin,a.theLoai);
	/*}while((a.theLoai.compare("hinh su")!=0)||(a.theLoai.compare("tinh cam")!=0)||(a.theLoai.compare("hai")!=0));*/
	cout<<"Nhap ten dao dien: ";
	getline(cin,a.tenDaoDien);
	cout<<"Nhap ten dien vien nam chinh: ";
	getline(cin,a.tenDienVienNamChinh);
	cout<<"Nhap ten dien vien nu chinh: ";
	getline(cin,a.tenDienVienNuChinh);
	cout<<"Nhap nam san xuat: ";
	cin>>a.namSanXuat;
	cout<<"Nhap hang san xuat: ";
	cin.ignore();
	getline(cin,a.hangSanXuat);
}
void nhapDS(VIDEO a[], int &n){
	cout<<"Nhap so luong video: ";
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
		nhapVideo(a[i]);
}
void inDSTheLoaix(VIDEO a[],int n, string x){
	
	for(int i=0;i<n;i++)
		if(a[i].theLoai==x)
			cout<<a[i].tenPhim<<endl;
}
void inDSDoDienVienXDong(VIDEO a[],int n, string x){
	for(int i=0;i<n;i++)
		if(a[i].tenDienVienNamChinh.compare(x)==0)
			cout<<a[i].tenPhim<<endl;
}
void inDSDoDaoDienxDung(VIDEO a[],int n, string x){
	for(int i=0;i<n;i++)
		if(a[i].tenDaoDien.compare(x)==0)
			cout<<a[i].tenPhim<<endl;
}
int main(){
	VIDEO a[max];
	int n;
	nhapDS(a,n);
	
	string theLoai;
	cout<<"Nhap ten the loai: ";
	getline(cin,theLoai);
	inDSTheLoaix(a,n,theLoai);
	
	string tenNamDienVien;
	cout<<"Nhap ten nam dien vien chinh: ";
	getline(cin,tenNamDienVien);
	inDSDoDienVienXDong(a,n,tenNamDienVien);
	
	string tenDaoDien;
	cout<<"Nhap ten dao dien: ";
	getline(cin,tenDaoDien);
	inDSDoDaoDienxDung(a,n,tenDaoDien);
}
