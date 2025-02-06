#include<iostream>
#define maxd 100
#define maxc 100
#include<time.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
void nhapMaTran(int a[][maxc], int &nd, int &nc)
{
	cout<<"Nhap so dong: ";
	cin>>nd;
	cout<<"Nhap so cot: ";
	cin>>nc;
	srand(time(NULL));
	for(int i=0;i<nd;i++)
		for(int j=0;j<nc;j++)
		{
			a[i][j]=rand()%202-100;
		}
}
bool checkChan(int n)
{
	if(n%2==0)
		return true;
	return false;
}
bool checkCP(int n)
{
	int canNguyen=sqrt(n);
	if(canNguyen*canNguyen==n)
		return true;
	return false;
}
void xuatMaTran(int a[][maxc], int nd, int nc)
{
	for(int i=0;i<nd;i++)
	{
		for(int j=0;j<nc;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}	
}
int tongDong(int a[][maxc], int nc, int pos)
{
	int s=0;
	for(int i=0;i<nc;i++)
		s+=a[pos][i];
	return s;
}
int main(int argc, char *argv[])
{
	int a[maxd][maxc], nd, nc;
	nhapMaTran(a,nd,nc);
	xuatMaTran(a,nd,nc);
	int i,j;
	bool flag=false;
	int xmax;
	int ymax;
	for(i=0;i<nd;i++)
	{
		for(j=0;j<nc;j++)
			if(checkChan(a[i][j]))
			{
				flag=true;
				xmax=i;
				ymax=j;
				break;
			}
		break;
	}
	if(flag)
	{
		cout<<"Vi tri phan tu chan dau tien: "<<xmax<<"\t"<<ymax;
	}
	else
		cout<<"Mang khong co phan tu chan ";
	int dem=0;
	for(i=0;i<nd;i++)
		for(j=0;j<nc;j++)
		{
			if(checkCP(a[i][j]))
				if(i==0||i==nd-1||j==0||j==nc-1)
					dem++;
		}
	cout<<"\nSo luong so chinh phuong tren duong bien: "<<dem;
	int dongMaxTong=0;
	int maxTong=tongDong(a,nc,0);
	for(i=1;i<nd;i++)
		if(tongDong(a,nd,i)>maxTong)
		{
			maxTong=tongDong(a,nd,nc);
			dongMaxTong=i;
		}
	cout<<"\nDong max tong: "<<dongMaxTong;
}
