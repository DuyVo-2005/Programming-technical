#include<iostream>
#define max 100
#include<time.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int a[max];
	int n,i;
	n=20;
	srand(time(NULL));
	for(i=0;i<n;i++){
		a[i]=rand()%10;
		cout<<a[i]<<" ";
	}
	for(i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j]){
			int tam=a[i];
			a[i]=a[j];
			a[j]=tam;
		}
	}
	cout<<"\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	int dem=1;
	for(i=1; i<n;i++)
	{
		if(a[i]==a[i-1])
			dem++;
		else
		{
			cout<<"\n"<<a[i-1]<<" xuat hien "<<dem<<" lan";
			dem=1;
		}
	}
	cout<<"\n"<<a[n-1]<<" xuat hien "<<dem<<" lan";
}
