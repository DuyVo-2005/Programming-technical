#include<iostream>
using namespace std;
#define maxd 100
#define maxc 100
#include<stdlib.h>
#include<time.h>
void nhapMaTran(float a[][maxc], int &nd, int &nc)
{
	cout<<"Nhap so dong: ";
	cin>>nd;
	cout<<"Nhap so cot: ";
	cin>>nc;
	srand(time(NULL));
	for(int i=0;i<nd;i++)
		for(int j=0;j<nc;j++)
			/*a[i][j]=rand()%100;*/
			{
				cout<<"Nhap a["<<i<<"]["<<j<<"]= ";
				cin>>a[i][j];
			}
}
void xuatMaTran(float a[][maxc], int nd, int nc)
{
	for(int i=0;i<nd;i++)
	{
		for(int j=0;j<nc;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
}
bool checkCotTangDan(float a[][maxc], int nd, int posCot)
{
	for(int i=0;i<nd-1;i++)
		if((a[i][posCot])>a[i+1][posCot])
			return false;
	return true;
}
int main()
{
	float a[maxd][maxc];
	int nd, nc, i, posCot;
	nhapMaTran(a,nd,nc);
	xuatMaTran(a,nd,nc);
	bool flag=false;
	for(i=0;i<nc;i++)
		if(checkCotTangDan(a,nd,i))
		{
			flag=true;
			posCot=i;
			break;
		}
	if(flag)
	{
		cout<<"Cot thoa yeu cau :";
		for(i=0;i<nd;i++)
			cout<<a[i][posCot]<<"\t";
	}
	else
		cout<<"Khong co";
}
