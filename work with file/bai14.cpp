/* Ma so sinh vien: 23110196
 Ho va ten sinh vien: Vo Le Khanh Duy
 Ngay sinh:26/3/2005
 Lop:231101B-PRTE230385_23_2_04
*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct mayTinh{
	string loaiMay;
	string noiSanXuat;
	float thoiGianBaoHanh;
};
void nhapMayTinh(mayTinh &a){
	cout<<"\nNhap loai may: ";
	getline(cin,a.loaiMay);
	cout<<"\nNhap noi san xuat: ";
	getline(cin,a.noiSanXuat);
	cout<<"\nNhap thoi gian bao hanh (don vi: nam): ";
	cin>>a.thoiGianBaoHanh;
	cin.ignore();
}
void nhapDS(mayTinh a[], int &n){
	cout<<"\nNhap so luong may tinh: ";
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
		nhapMayTinh(a[i]);
}
void thongKeThoiGianBaoHanh1Nam(mayTinh a[], int n){
	int dem=0;
	cout<<"\nCac mat hang bao hanh 1 nam: ";
	for(int i=0;i<n;i++)
		if(a[i].thoiGianBaoHanh==1)
		{
			dem++;
			cout<<"\n"<<a[i].loaiMay;
		}
	cout<<"\nTong so cac mat hang bao hanh 1 nam: "<<dem;
}
void inDanhSachMayTinhXuatXuTuMy(mayTinh a[], int n){
	cout<<"\nDanh sach may tinh xuat xu tu My: ";
	for(int i=0;i<n;i++)
		if(a[i].noiSanXuat=="My"||a[i].noiSanXuat=="my"||a[i].noiSanXuat=="MY")
			cout<<"\n"<<a[i].loaiMay;
}
int main(){
	mayTinh a[100];
	int n;
	nhapDS(a,n);
	thongKeThoiGianBaoHanh1Nam(a,n);
	inDanhSachMayTinhXuatXuTuMy(a,n);
	return 0;
}
