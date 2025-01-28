/* Ma so sinh vien: 23110196
Ho va ten sinh vien: Vo Le Khanh Duy
Ngay sinh: 26/3/2005
Lop: 231101B-PRTE230385_23_2_04*/
#include<iostream>
#include<fstream>
using namespace std;
#define max 20
const int maxC=INT_MAX;
/*int inputFile[20]={4,6,
				   1,2,3,
				   1,3,2,
				   1,4,1,
				   2,3,1,
				   2,4,2,
				   3,4,4};*/
int a[max][max]; //ma tran chi phi
int x[max+1];//de thu cac kha nang
int bestWay[max+1];//de ghi nhan nghiem
int T[max+1];// luu chi phi tu x[0] den x[i]
int Free[max];//danh dau true neu chua di qua thanh pho i
int n;// so thanh pho
int m;// so duong di
int minSpending;//chi phi hanh trinh toi uu
void enter(){
	int i, j, k;
	ifstream f;
	f.open("D:\\bai16in.txt");
	f>>n>>m;
	for(i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j)
				a[i][j]=0;
			else
				a[i][j]=maxC;
	for(k=1;k<=m;k++){
		f>>i>>j>>a[i][j];
		a[j][i]=a[i][j];
	}
	f.close();
}
void init(){
	for(int i=1;i<=n;i++)
		Free[i]=1;//fillChar
	Free[1]=0;//cac thanh pho khac chua di qua ngoai tru 0
	x[1]=1;//xuat phat tu 0
	T[1]=0;//chi phi tai thanh pho xuat phat la 0
	minSpending=maxC;
}
void Try(int i){//thu chon cac x[i]
	for(int j=2;j<=n;j++)//thu cac thanh pho tu 1 den n-1
		if(Free[j]==1){
			x[i]=j;//thu di
			T[i]=T[i-1]+a[x[i-1]][j];
			if(T[i]<minSpending)
				if(i<n-1){//neu chua den duoc x[i-1]
					Free[j]=0;// danh dau thanh pho vua thu
					Try(i+1);//tim kha nang chon x[i+1]
					Free[j]=1;// bo danh dau
				}
				else
					if(T[n]+a[x[n]][1]<minSpending){
						minSpending=T[n]+a[x[n]][1];
						for(int i=1;i<=n;i++)
							bestWay[i]=x[i];
					}
		}
}
void printResult(){
	if(minSpending==maxC)
		cout<<"No solution";
	else{
		for(int i=1;i<=n;i++)
			cout<<bestWay[i]<<"->";
		cout<<"1";
		cout<<"\nCost: "<<minSpending;
	}
}
int main(int argc, char *argv[])
{
	enter();
	init();
	Try(2);
	printResult();
	/*for (int i = 0; i < BestWay.size(); i++){
        cout << BestWay[i] << "->" << " ";*/
	return 0;
}
