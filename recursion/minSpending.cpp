/* Ma so sinh vien: 23110196
Ho va ten sinh vien: Vo Le Khanh Duy
Ngay sinh: 26/3/2005
Lop: 231101B-PRTE230385_23_2_04*/
#include<iostream>
using namespace std;
#define max 20
const int maxC=INT_MAX;
int inputFile[20]={4,6,
				   1,2,3,
				   1,3,2,
				   1,4,1,
				   2,3,1,
				   2,4,2,
				   3,4,4};
int a[max][max]; //ma tran chi phi
int x[max+1];//de thu cac kha nang
int bestWay[max+1];//de ghi nhan nghiem
int T[max+1];// luu chi phi tu x[0] den x[i]
bool free[max];//danh dau true neu chua di qua thanh pho i
int n;// so thanh pho
int m;// so duong di
int minSpending;//chi phi hanh trinh toi uu
void enter(){
	int i,j,k;
	n=inputFile[0];
	m=inputFile[1];
	int chayFile=2;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i==j)
				a[i][j]=0;
			else
				a[i][j]=maxC;
	for(k=1;k<=m;k++)
	{
		i=inputFile[chayFile];
		j=i=inputFile[++chayFile];
		a[i][j]=++chayFile;
		a[j][i]=a[i][j];
	}
}
/*void enter(){
	int i, j, k;
	ifstream f;
	f.open("")
}*/
void init(){
	for(int i=0;i<n;i++)
		free[i]=true;//fillChar
	free[0]=false;//cac thanh pho khac chua di qua ngoai tru 0
	x[0]=0;//xuat phat tu 0
	T[0]=0;//chi phi tai thanh pho xuat phat la 0
	minSpending=maxC;
}
void ganMang(int a[], int b[]){
	for(int i=0;i<n;i++)
		b[i]=a[i];
}
void Try(int i){//thu chon cac x[i]
	for(int j=1;j<n;j++)
		if(free[j]){
			x[j]=i;//thu di
			T[i]=T[i-1]+a[x[i-1]][j];
			if(T[i]<minSpending)
				if(i<n-1){//neu chua den duoc x[i-1]
					free[j]=false;// danh dau thanh pho vua thu
					Try(i+1);//tim kha nang chon x[i+1]
					free[j]=true;// bo danh dau
				}
				else
					if(T[n-1]+a[x[n-1]][0]<minSpending){
						ganMang(x,bestWay);
						minSpending=T[n-1]+a[x[n-1]][0];
					}
		}
}
void printResult(){
	if(minSpending==maxC)
		cout<<"No solution";
	else{
		for(int i=0;i<n;i++)
			cout<<bestWay[i]<<"->";
		cout<<"0";
		cout<<"\nCost: "<<minSpending;
	}
}
int main(int argc, char *argv[])
{
	enter();
	init();
	Try(1);
	printResult();
	return 0;
}
