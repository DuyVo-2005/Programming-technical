/* Ma so sinh vien: 23110196
 Ho va ten sinh vien: Vo Le Khanh Duy
 Ngay sinh:26/3/2005
 Lop:231101B-PRTE230385_23_2_04
*/
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string.h>
struct linhKien{
	string tenLinhKien;
	string quyCach;
	char loaiLinhKien;
	int donGiaLoai1;
	int donGiaLoai2;
};
void nhapLinhKien(linhKien &a){
	cout<<"\nNhap ten linh kien: ";
	getline(cin,a.tenLinhKien);
	cout<<"\nNhap quy cach: ";
	getline(cin,a.quyCach);
	cout<<"Nhap loai linh kien (A hoac B): ";
	cin>>a.loaiLinhKien;
	cout<<"\nNhap don gia loai 1: ";
	cin>>a.donGiaLoai1;
	cout<<"\nNhap don gia loai 2: ";
	cin>>a.donGiaLoai2;
	cin.ignore();
}
void nhapDS(linhKien a[], int &n){
	cout<<"\nNhap so luong linh kien: ";
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
		nhapLinhKien(a[i]);
}
void xuatLinhKien(linhKien a){
	cout<<"\n"<<a.tenLinhKien;
	cout<<"\t"<<a.quyCach;
	cout<<"\t"<<a.loaiLinhKien;
	cout<<"\t"<<a.donGiaLoai1;
	cout<<"\t"<<a.donGiaLoai2;
}
void xuatDS(linhKien a[], int n){
	cout<<"\nDanh sach linh kien: ";
	for(int i=0;i<n;i++)
		xuatLinhKien(a[i]);
}
void sapTangTheoLoai(linhKien a[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++)
			if(a[i].loaiLinhKien>a[j].loaiLinhKien){
				linhKien temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
	}
}
void sapTangTheoTenLoaix(linhKien a[], int n, char x){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++)
			if((a[i].loaiLinhKien==x)&&(a[j].loaiLinhKien==x)&&a[i].tenLinhKien>a[j].tenLinhKien){
				linhKien temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
	}
}
int demLoaiA(linhKien a[], int n){
	int dem=0;
	for(int i=0;i<n;i++)
		if(a[i].loaiLinhKien=='A')
			dem++;
	return dem;
}
int main(){
	linhKien a[100];
	int n;
	nhapDS(a,n);
	sapTangTheoLoai(a,n);
	sapTangTheoTenLoaix(a,n,'A');
	sapTangTheoTenLoaix(a,n,'B');
	xuatDS(a,n);
	
	if(demLoaiA(a,n)>=10)
		cout<<"\nDa du 10 linh kien loai A can thiet de lap rap may! ";
	else
		cout<<"\nChua du 10 linh kien loai A can thiet de lap rap may! ";
	return 0;
}
