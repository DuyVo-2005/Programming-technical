#include<iostream>
#include<fstream>
using namespace std;
#define max 100
int n;//so goi hang cua cua hang
int M;//trong luong toi da cua tui
int F[max+1][max+1];//Bang phuong an chon gia cac mat hang cao nhat
int W[max];//chua trong luong cua goi hang thu i
int V[max];//chua gia tri cua goi hang thu i
//void enter(){
//	cin>>n>>M;
//	for(int i=1;i<=n;i++)
//		cin>>W[i]>>V[i];
//}
void enter(ifstream &f, int &n, int &M){
	f>>n>>M;
	for(int i=1;i<=n;i++)
		f>>W[i]>>V[i];
}
void optimize(){
	int i,j;//i la chi so mat hang, j la trong luong toi da
	for(i=1;i<=n;i++)
		for(j=0;j<=M;j++){
			F[i][j]=F[i-1][j];
			//ko chon goi thu i thi chon goi i-1(neu chon goi i duoc loi hon thi dat lai F[i][j])
			if(W[i]<=j&&F[i][j]<V[i]+F[i-1][j-W[i]])
				F[i][j]=V[i]+F[i-1][j-W[i]];
		}
}
void trace(ofstream &f){
	//truy vet tim nghiem toi uu
	f<<F[n][M]<<endl;
	while(n!=0){
		//truy vet bang phuong an tu hang n ve 0
		if(F[n][M]!=F[n-1][M])//co chon goi thu n
		{
			f<<n<<" ";
			M=M-W[n];//da chon goi M nen chi mang them cac goi co trong luong be hon M-W[n]
		}
		n--;
	}
}
int main(){
	ifstream f;
	f.open("BAG_INP.txt");
	enter(f,n,M);
	f.close();
	optimize();
	ofstream f2;
	f2.open("BAG_OUT.txt");
	trace(f2);
	f2.close();
	for(int i=0;i<=n;i++){
		for(int j=0;j<=M;j++)
			cout<<F[i][j]<<" ";
		cout<<endl;	
	}
	return 0;
}
/*
5 11
3 3
4 4
5 4
9 10
4 4
out:
11
5 2 1
*/

