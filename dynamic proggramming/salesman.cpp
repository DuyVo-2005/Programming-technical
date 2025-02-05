#include<iostream>
using namespace std;
#include<fstream>
#define voCuc 999999
#include<vector>
#define max 100
int a[max][max];
int x[max+1];
vector<int>bestWay;
bool visited[max+1];
int T[max];
int n, m;
int minSpending=voCuc;//chi phi di thap nhat
void init(){
	ifstream f;
	f.open("TOURISM.txt");
	f>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j)
				a[i][j]=0;
			else
				a[i][j]=voCuc;
	for(int i=1;i<=m;i++)
	{
		int j, k;
		f>>j>>k;
		f>>a[j][k];
		a[k][j]=a[j][k];
	}
	f.close();
}
void thu(int j){
	for(int i=2;i<=n;i++){
		if(visited[i]==false){
			x[j]=i;
			T[j]=a[x[j-1]][i]+T[j-1];
			if(T[j]<minSpending)
				if(j<n){
					visited[i]=true;
					thu(j+1);
					visited[i]=false;
				}
				else
					if(T[n]+a[x[n]][1]<minSpending){
						minSpending=T[n]+a[x[n]][1];
						bestWay.clear();
						for(int i=1;i<=n;i++)
							bestWay.push_back(x[i]);
					}
		}
	}
}
void printResult(){
	ofstream f;
	f.open("TOURISM_OUT.txt");
	if(minSpending==voCuc)
		f<<"No solution";
	else{
		for(int i=0;i<bestWay.size();i++)
			f<<bestWay[i]<<"->";
		f<<"1";
		f<<"\nCost: "<<minSpending;
	}
}
int main(int argc, char *argv[])
{
	init();
	x[1]=1;
	T[1]=0;
	visited[1]=true;
	thu(2);
	printResult();
	return 0;
}
