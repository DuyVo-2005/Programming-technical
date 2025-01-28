//Vo Le Khanh Duy-23110196-26/3/2005-231101B
#include<iostream>
using namespace std;
#define max 100
#include<string.h>
struct hocPhan
{
	char maHP[10];
	char tenHP[20];
	int soTC;
};
void nhapHP(hocPhan &a)
{
		cout<<"\nNhap ma hoc phan: ";
		cin.ignore();
		cin.getline(a.maHP,10);
		cout<<"Nhap ten hoc phan: ";
		cin.getline(a.tenHP,20);
		cout<<"Nhap so tin chi: ";
		cin>>a.soTC;
}
void xuatHP(hocPhan a)
{
	cout<<a.maHP<<" ";
	cout<<a.tenHP<<" ";
	cout<<a.soTC<<endl;
}
int TCmax(hocPhan a[max], int n)
{
	int maxTC=a[0].soTC;
	int vt=0;
	for(int i=0;i<n;i++)
		if(a[i].soTC>maxTC)
		{
			maxTC=a[i].soTC;
			vt=i;
		}
	return vt;
}
void dem(char s[], int demTu)
{
	int ntam;
	char tam[50];
	int i=0;
	while(i<strlen(s))
	{
		int demCach=0;
		ntam=0;
		for(;i<strlen(s);i++)
		{
			if(tam[i]!=' ')
			{
				tam[ntam]=s[i];
				ntam++;
			}
			else
			{
				demCach++;
			}
			if(demCach==2)
			{
			   	tam[i]='\0';                               	       }
			if(strcmp(tam,"Nhap mon")==0)
				demTu++;
		}
	}
}
/*int dem(hocPhan a[], int n)
{
	for(int i;;)
	;
}*/

int main()
{
	hocPhan a[max];
	hocPhan b;
	int n;
	cout<<"Nhap tong so hoc phan: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nNhap hoc phan: "<<i;
		nhapHP(a[i]);
	}
	for(int i=0;i<n;i++)
		xuatHP(a[i]);
	cout<<"\n Hoc phan tin chi nhieu nhat: "<<TCmax(a,n);
	int demTu=0;
	for(int i=0;i<n;i++)
		dem(a[i].tenHP,demTu);
	cout<<demTu;
}
