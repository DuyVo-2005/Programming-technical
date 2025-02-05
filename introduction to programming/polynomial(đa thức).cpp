#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
float tinhDaThucTaiX(/*vector <float> a*/ float a[], float x, int n);
void nhapDaThuc(/*vector <float> a*/float a[], int &n){
	float tmp;
	cout<<"Nhap bac da thuc: ";
	cin>>n;
	for(int i=0;i<=n;i++){
		cout<<"Nhap a["<<i<<"]= ";
		//cin>>tmp;
		cin>>a[i];
		//a.push_back(tmp);
	}
}
int main(int argc, char *argv[])
{
	float a[50];//vector <float> a;
	float x;
	int n;
	cout<<"Nhap x: ";
	cin>>x;
	nhapDaThuc(a,n);
	cout<<tinhDaThucTaiX(a,x,n);
	return 0;
}
float tinhDaThucTaiX(/*vector <float> a*/float a[], float x, int n){
	float s=0;
	s+=a[0];
	for(int i=1;i<=n;i++)
	{
		s+=(a[i]*pow(x,i));
	}
	return s;
}
