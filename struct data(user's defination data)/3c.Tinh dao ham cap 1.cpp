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
donThuc daoHamCap1(donThuc a)
{
	donThuc kq;
	kq.heSo=a.heSo*a.mu;
	kq.mu=a.mu-1;
	return kq;
}
int main()
{
	donThuc kq, a;
	nhapDT(a);
	xuatDT(a);
	cout<<"\nCo dao ham cap 1 la: ";
	kq=daoHamCap1(a);
	xuatDT(kq);
}
