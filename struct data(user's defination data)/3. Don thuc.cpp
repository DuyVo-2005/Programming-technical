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
donThuc tichDT(donThuc a, donThuc b)
{
	donThuc kq;
	kq.heSo=a.heSo*b.heSo;
	kq.mu=a.mu+b.mu;
	return kq;
}
donThuc thuongDT(donThuc a, donThuc b)
{
	donThuc kq;
	kq.heSo=a.heSo/b.heSo;
		kq.mu=a.mu-b.mu;
	return kq;
}
int main()
{
	donThuc a, b, kq;
	nhapDT(a);
	xuatDT(a);
	cout<<endl;
	nhapDT(b);
	xuatDT(b);
	cout<<endl;
	/*kq=tichDT(a,b);
	xuatDT(a);
	cout<<"*";
	xuatDT(b);
	cout<<"=";
	xuatDT(kq);*/
	kq=thuongDT(a,b);
	xuatDT(a);
	cout<<" / ";
	xuatDT(b);
	cout<<"=";
	xuatDT(kq);
}
