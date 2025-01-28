#include<iostream>
#include<math.h>
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
float giaTri(donThuc a, float x)
{
	float kq;
	kq=pow(x,a.mu)*a.heSo;
	return kq;
}
int main()
{
	donThuc a;
	nhapDT(a);
	xuatDT(a);
	float x,kq;
	cout<<"\n Nhap gia tri x: ";
	cin>>x;
	cout<<"Gia tri don thuc tai x: "<<giaTri(a,x);
}
