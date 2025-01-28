#include<iostream>
using namespace std;
struct donThuc
{
	int mu;
	float heSo;
};
void nhapDT(donThuc &a)
{
	cout<<"Nhap he so: ";
	cin>>a.heSo;
	cout<<"Nhap so mu: ";
	cin>>a.mu;
}
void xuatDT(donThuc a)
{
	cout<<a.heSo<<"x^"<<a.mu;
}
donThuc daoHam(donThuc &a)
{
	a.heSo=a.heSo*a.mu;
	a.mu=a.mu-1;
}
int main()
{
	donThuc a;
	nhapDT(a);
	xuatDT(a);
	int k;
	cout<<"\nNhap cap k dao ham: ";
	cin>>k;
	for(int i=0;i<k;i++)
	{
		daoHam(a);
	}
	xuatDT(a);
}
