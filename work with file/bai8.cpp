//MSSV:23110196
//Ho Ten SV: Vo Le Khanh Duy
//Ngay sinh: 26/3/2005
//Lop: 231101B-PRTE230385_23_2_04
#include<iostream>
#include<fstream>
using namespace std;
struct DATE
{
	int ngay;
	int thang;
	int nam;
};
struct HOCSINH
{
	char MSHS[6];
	char hoten[31];
	DATE ngaysinh;
	char diachi[51];
	char phai[4];
	float diemtb;
};
void nhapDATE(DATE &a)
{
	cout<<"\nNhap ngay sinh: ";
	cin>>a.ngay;
	cout<<"Nhap thang sinh: ";
	cin>>a.thang;
	cout<<"Nhap nam sinh: ";
	cin>>a.nam;
}
void xuatDATE(DATE a)
{	
}
void nhapHS(HOCSINH &a)
{
	cout<<"Nhap ma so: ";
	cin.ignore();
	cin.getline(a.MSHS,6);
	cout<<"Nhap ho ten: ";
	cin.getline(a.hoten,31);
	cout<<"Nhap ngay thang nam sinh ";
	nhapDATE(a.ngaysinh);
	cout<<"Nhap dia chi: ";
	cin.ignore();
	cin.getline(a.diachi,51);
	cout<<"Nhap phai: ";
	cin.getline(a.phai,4);
	cout<<"Nhap diem trung binh: ";
	cin>>a.diemtb;
}
void nhapDS(HOCSINH a[],int &n)
{
	cout<<"Nhap so hoc sinh: ";
	cin>>n;
	while(n>50||n<=0)
	{
		cout<<"Nhap sai. Nhap lai so hoc sinh nho hon hoac bang 50: ";
		cin>>n;
	}
	for(int i=0;i<n;i++)
		nhapHS(a[i]);
}
bool lenLop(HOCSINH a)
{
	if(a.diemtb>=5)
		return true;
	return false;
}
int main()
{
	HOCSINH a[100];
	int n;
	fstream f;
	f.open("D:\\data8.txt",ios::out|ios::binary);
	int dem=0;
	nhapDS(a,n);
	for(int i=0;i<n;i++)
	{
		f<<a[i].MSHS<<endl;
		f<<a[i].hoten<<endl;
		f<<a[i].ngaysinh.ngay<<"/"<<a[i].ngaysinh.thang<<"/"<<a[i].ngaysinh.nam<<endl;
		f<<a[i].diachi<<endl;
		f<<a[i].phai<<endl;
		f<<a[i].diemtb<<endl;
		/*f.write((char*)&a[i],sizeof(HOCSINH));*/
	}
	for(int i=0;i<n;i++)
		if(lenLop(a[i]))
			dem++;
	f<<dem;
	
	f.close();
	return 0;
}
