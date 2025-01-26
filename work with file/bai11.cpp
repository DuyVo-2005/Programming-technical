/* Ma so sinh vien: 23110196
 Ho va ten sinh vien: Vo Le Khanh Duy
 Ngay sinh:26/3/2005
 Lop:231101B-PRTE230385_23_2_04
*/
#include<iostream>
#include<fstream>
#include<stdlib.h>
#define max 100
#include<string.h>
using namespace std;
struct sinhVien{
	string maSV;
	string tenSV;
	int namSinh;
	float toan;
	float li;
	float hoa;
	float tb;
};
void nhapSV(sinhVien &a){
	cout<<"Nhap ma sinh vien: ";
	cin.ignore();
	getline(cin,a.maSV);
	cout<<"Nhap ten sinh vien: ";
	getline(cin,a.tenSV);
	cout<<"Nhap nam sinh: ";
	cin>>a.namSinh;
	cout<<"Nhap diem toan: ";
	cin>>a.toan;
	cout<<"Nhap diem li: ";
	cin>>a.li;
	cout<<"Nhap diem hoa: ";
	cin>>a.hoa;
	cout<<"Nhap diem trung binh: ";
	cin>>a.tb;
}
void nhapDS(sinhVien a[], int &n)
{
	cout<<"Nhap so luong sinh vien: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		nhapSV(a[i]);
	}
}
void xuatSV(sinhVien a){
	cout<<"\nMa sinh vien: "<<a.maSV;
	cout<<"\nTen sinh vien: "<<a.tenSV;
	cout<<"\nNam sinh: "<<a.namSinh;
	cout<<"\nDiem toan: "<<a.toan;
	cout<<"\nDiem li: "<<a.li;
	cout<<"\nDiem hoa: "<<a.hoa;
	cout<<"\nDiem trung binh: "<<a.tb;
}
void xuatSVRaFile(sinhVien a, fstream &f){
	f<<"\nMa sinh vien: "<<a.maSV;
	f<<"\nTen sinh vien: "<<a.tenSV;
	f<<"\nNam sinh: "<<a.namSinh;
	f<<"\nDiem toan: "<<a.toan;
	f<<"\nDiem li: "<<a.li;
	f<<"\nDiem hoa: "<<a.hoa;
	f<<"\nDiem trung binh: "<<a.tb;
}
void xuatDS(sinhVien a[], int n){
	cout<<"\nDanh sach sinh vien:";
	for(int i=0;i<n;i++)
		xuatSV(a[i]);
}
void sapMangTang(float a[], int n){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j]){
				float tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
}
float maxTB(sinhVien a[], int n){
	float maxTB=a[0].tb;
	for(int i=0;i<n;i++)
		if(a[i].tb>maxTB)
			maxTB=a[i].tb;
	return maxTB;
}
void sapMangGiam(float a[], int n){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]<a[j]){
				float tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
}
void xoa(float a[], int &n, int pos){
	for(int i=pos;i<n-1;i++)
		a[pos]=a[pos+1];
	n--;
}
void xoaPhanTuTrung(float a[], int &n){
	for(int i=0;i<n-1;i++)
		if(a[i]==a[i+1])
			xoa(a,n,i+1);
}
void DSTBTangDan(sinhVien a[], int n, fstream &f){
	float diemTrungBinh[max];
	int nTB=n;
	for(int i=0;i<n;i++)
		diemTrungBinh[i]=a[i].tb;
	sapMangTang(diemTrungBinh,nTB);
	xoaPhanTuTrung(diemTrungBinh,nTB);
	f<<"\nDanh sach tang dan diem trung binh: ";
	for(int i=0;i<nTB;i++)
	{
		for(int j=0;j<n;j++)
			if(a[j].tb==diemTrungBinh[i]){
				xuatSVRaFile(a[j],f);
			}
	}
}
void DSGiamDanToan(sinhVien a[], int n){
	float diemT[max];
	int nT=n;
	for(int i=0;i<n;i++)
		diemT[i]=a[i].toan;
	sapMangGiam(diemT,nT);
	xoaPhanTuTrung(diemT,nT);
	cout<<"\nDanh sach giam dan diem toan: ";
	for(int i=0;i<nT;i++)
	{
		for(int j=0;j<n;j++)
			if(a[j].toan==diemT[i]){
				xuatSV(a[j]);
			}
	}
}
int main(){
	sinhVien a[max];
	int n;
	nhapDS(a,n);
	fstream f;
	f.open("D:\\data11.txt",ios::out|ios::binary);
	for(int i=0;i<n;i++)
		f.write((char*)&a[i],sizeof(sinhVien));
	f.close();
	
	sinhVien b[max];
	fstream f2;
	f2.open("D:\\data11.txt",ios::in|ios::binary);
	for(int i=0;i<n;i++)
		f2.read((char*)&b[i],sizeof(sinhVien));
	f2.close();
	xuatDS(b,n);
	
	cout<<"\nSinh vien co diem trung binh cao nhat: ";
	for(int i=0;i<n;i++)
		if(b[i].tb==maxTB(b,n))
			cout<<"\n"<<b[i].tenSV;
	
	fstream f3;
	f3.open("D:\\data11_2",ios::out);		
	DSTBTangDan(b,n,f3);
	f3.close();
	
	DSGiamDanToan(b,n);
	
	cout<<"\nCac sinh vien co diem trung binh lon hon 5 va khong co mon nao duoi 3: ";
	for(int i=0;i<n;i++)
		if((b[i].tb>5)&&(b[i].toan>=3)&&(b[i].li>=3)&&(b[i].hoa>=3))
			xuatSV(b[i]);
			
	cout<<"\nSinh vien co tuoi lon nhat: ";
	int minNamSinh=b[0].namSinh;
	int posNamSinh=0;
	for(int i=1;i<n;i++){
		if(b[i].namSinh<minNamSinh){
			minNamSinh=b[i].namSinh;
			posNamSinh=i;
		}			
	}
	cout<<b[posNamSinh].tenSV;
	
	string ten;
	cin.ignore();
	cout<<"\nNhap ten sinh vien: ";
	getline(cin,ten);
	bool flag=false;
	for(int i=0;i<n;i++)
		if(b[i].tenSV==ten)
		{
			flag=true;
			break;
		}
	if(flag==true){
		cout<<"\nThong tin sinh vien co ten vua nhap: ";
		for(int i=0;i<n;i++)
			if(b[i].tenSV==ten)
				xuatSV(b[i]);
	}
	else
		cout<<"\nTen sinh vien vua nhap khong co trong danh sach! ";
	return 0;
}
