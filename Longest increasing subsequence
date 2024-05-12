#include<iostream>
using namespace std;
#include<vector>
void enter(vector<float>&a,int &n){
	for(int i=1;i<=n;i++)
		cin>>a[i];
}
void optimize(vector<float>a,int n,vector<int>&L,vector<int>&T){
	a[0]=INT_MIN;
	a[n+1]=INT_MAX;
	L[n+1]=1;
	int i,j;
	for(i=n;i>=0;i--){
		int jmax=n+1;
		for(j=i+1;j<=n+1;j++)
			if(a[j]>a[i]&&L[j]>L[jmax])
				jmax=j;
		L[i]=L[jmax]+1;
		T[i]=jmax;//luu vi tri phan tu lien sau la a[jmax]
	}
}
void result(vector<float>a,int n,vector<int>L,vector<int>T){
	cout<<L[0]-2<<endl;//do dai thuc su cua day con(tru 2 mut)
	
	int i=T[0];//bat dau truy vet
	while(i!=n+1){
		cout<<a[i]<<" ";
		i=T[i];
	}
}
int main(){
	int n;
	cin>>n;
	vector<float>a(n+2);//chua mang ban dau
	vector<int>L(n+2);//chua chieu dai day con tu vi tri thu i
	vector<int>T(n+2);//luu lai phan tu phia sau no cua day con
	enter(a,n);
	optimize(a,n,L,T);
	result(a,n,L,T);
	return 0;
}
/*
in: 11
1 2 3 8 9 4 5 6 20 9 10
*/
/*out: 8
1 2 3 4 5 6 9 10
*/
