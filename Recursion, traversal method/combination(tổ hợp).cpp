#include<iostream>
using namespace std;
#define max 100
int a[max], n, k;
bool isNotChosen[max];
void createBoolArray(bool a[], int n){
	for(int i=1;i<=n;i++)
		isNotChosen[i]=true;
} 
void displayArray(int a[], int n){
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
void Try(int i){
	for(int j=1;j<=n;j++)
	{
		if(isNotChosen[j]){
			a[i]=j;
			if(i==k)
				displayArray(a,k);
			else
			{
				isNotChosen[j]=false;
				Try(i+1);
				isNotChosen[j]=true;
			}
		}
	}
}
int main(int argc, char *argv[])
{
	cin>>n>>k;
	createBoolArray(isNotChosen,n);
	Try(1);
	return 0;
}
