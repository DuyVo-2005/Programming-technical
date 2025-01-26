/* Ma so sinh vien: 23110196
 Ho va ten sinh vien: Vo Le Khanh Duy
 Ngay sinh:26/3/2005
 Lop:231101B-PRTE230385_23_2_04
*/
#include<iostream>
#include<fstream>
using namespace std;
struct PHANSO{
	int tuSo;
	int mauSo;
};
void rutGonPS(PHANSO &a);
void nhapPS(PHANSO &a)
{
	cout<<"Nhap tu so: ";
	cin>>a.tuSo;
	cout<<"Nhap mau so: ";
	cin>>a.mauSo;
	while((a.tuSo<-10)||(a.tuSo>10)||(a.tuSo==0)||(a.mauSo<-10)||(a.mauSo>10)||(a.mauSo==0))
	{
		cout<<"Nhap tu so: ";
		cin>>a.tuSo;
		cout<<"Nhap mau so: ";
		cin>>a.mauSo;
	}
}
void xuatPS(PHANSO a)
{
	rutGonPS(a);
	cout<<a.tuSo<<" "<<a.mauSo;
}
void xuatPSRaFile(PHANSO a, fstream &file){
	rutGonPS(a);
	file<<a.tuSo<<" "<<a.mauSo<<" ";
}
int ucln(int a, int b)
{
	while(b!=0)
	{
		int temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}
void rutGonPS(PHANSO &a)
{
	int UCLN=ucln(a.tuSo,a.mauSo);
	a.tuSo/=UCLN;
	a.mauSo/=UCLN;
}
PHANSO tongPS(PHANSO a, PHANSO b)
{
	PHANSO kq;
	kq.tuSo=a.tuSo*b.mauSo+a.mauSo*b.tuSo;
	kq.mauSo=a.mauSo*b.mauSo;
	rutGonPS(kq);
	return kq;
}
PHANSO hieuPS(PHANSO a, PHANSO b)
{
	PHANSO kq;
	kq.tuSo=a.tuSo*b.mauSo-a.mauSo*b.tuSo;
	kq.mauSo=a.mauSo*b.mauSo;
	rutGonPS(kq);
	return kq;
}
PHANSO tichPS(PHANSO a, PHANSO b)
{
	PHANSO kq;
	kq.tuSo=a.tuSo*b.tuSo;
	kq.mauSo=a.mauSo*b.mauSo;
	rutGonPS(kq);
	return kq;
}
PHANSO thuongPS(PHANSO a, PHANSO b)
{
	PHANSO kq;
	kq.tuSo=a.tuSo*b.mauSo;
	kq.mauSo=a.mauSo*b.tuSo;	
	rutGonPS(kq);	
	return kq;
}
void nghichDaoPS(PHANSO &a)
{
	int temp=a.tuSo;
	a.tuSo=a.mauSo;
	a.mauSo=temp;
}
int soSanhPS(PHANSO a, PHANSO b)
{
	if((float(a.tuSo)/a.mauSo)>(float(b.tuSo)/b.mauSo))
		return 1;
	if((float(a.tuSo)/a.mauSo)<(float(b.tuSo)/b.mauSo))
		return -1;
	if((float(a.tuSo)/a.mauSo)==(float(b.tuSo)/b.mauSo))
		return 0;
}
void nhapMangPS(PHANSO a[], int &n)
{
	cout<<"Nhap so phan tu mang: ";
	cin>>n;
	while(n>50)
	{
		cin>>n;
	}
	for(int i=0;i<n;i++)
		nhapPS(a[i]);
}
void xuatMangPS(PHANSO a[], int n)
{
	for(int i=0;i<n;i++)
	{
		xuatPS(a[i]);
		cout<<" ";
	}
}
void xuatMangPSRaFile(PHANSO a[], int n, fstream &file){
	for(int i=0;i<n;i++){
		xuatPSRaFile(a[i],file);
		cout<<" ";
	}
}
int main(int argc, char *argv[])
{
	PHANSO a[100];
	int n;
	nhapMangPS(a,n);
	fstream file;
	file.open("D:\\data9.txt",ios::out);
	xuatMangPSRaFile(a,n,file);
	file<<endl;
	
	PHANSO max=a[0];
	for(int i=1;i<n;i++)
		if(soSanhPS(a[i],max)==1)
			max=a[i];
	//file<<"\nPhan so lon nhat: ";
	xuatPSRaFile(max,file);
	file<<endl;
	
	PHANSO tong;
	//file<<"\nTong cac phan so: ";
	if(n==0)
		file<<"0";
	if(n==1)
		xuatPS(a[0]);
	if(n>=2)
	{
	tong=tongPS(a[0],a[1]);
	}
	for(int i=2;i<n;i++)
		tong=tongPS(tong,a[i]);
	xuatPSRaFile(tong,file);
	file<<endl;
	
	PHANSO tich;
	//file<<"\nTich cac phan so: ";
	if(n==0)
		file<<"0";
	if(n==1)
		xuatPSRaFile(a[0],file);
	if(n>=2)
	{
	tich=tichPS(a[0],a[1]);
	}
	for(int i=2;i<n;i++)
		tich=tichPS(tich,a[i]);
	xuatPSRaFile(tich,file);
	file<<endl;
	
	//file<<"\nNghich dao cac phan so: ";
	for(int i=0;i<n;i++){
		nghichDaoPS(a[i]);
	}
	xuatMangPSRaFile(a,n,file);
	return 0;
}
