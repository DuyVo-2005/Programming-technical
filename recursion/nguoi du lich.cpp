/* Ma so sinh vien: 23110196
Ho va ten sinh vien: Vo Le Khanh Duy
Ngay sinh: 26/3/2005
Lop: 231101B-PRTE230385_23_2_04*/
#include<iostream>
#include<fstream>
using namespace std;
#define max 20
#define maxC 999999
int inputFile[]={4,6,1,2,3,1,3,2,1,4,1,2,3,1,2,4,2,3,4,4};
int a[max][max]; //ma tran chi phi
int x[max+1];//de thu cac kha nang
int bestWay[max+1];//de ghi nhan nghiem
int T[max+1];// luu chi phi tu x[0] den x[i]
bool Free[max];//danh dau true neu chua di qua thanh pho i
int n;// so thanh pho
int m;// so duong di
int minSpending;//chi phi hanh trinh toi uu
/*void enter(){
	int i,j,k;
	n=inputFile[0];
	m=inputFile[1];
	int chayFile=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i==j)
				a[i][j]=0;
			else
				a[i][j]=maxC;
	for(k=1;k<=m;k++)
	{
		i=inputFile[++chayFile];
		j=inputFile[++chayFile];
		a[i][j]=inputFile[++chayFile];
		a[j][i]=a[i][j];
	}
}*/
void enter(){
	int i,j,k;
    ifstream infile;
    infile.open("D:\\bai16in.txt");
    infile >> n >> m;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            if (i == j)  
				a[i][j] = 0;
            else    
                a[i][j] = maxC;
        }
    }
    for (k = 1; k <= m; k++){
        infile>>i>>j>>a[i][j];
        a[j][i] =a[i][j];
    }
    infile.close();
}
void init(){
	for(int i=1;i<=n;i++)
		Free[i]=true;//fillChar
	Free[1]=false;//cac thanh pho khac chua di qua ngoai tru 0
	x[1]=1;//xuat phat tu 0
	T[1]=0;//chi phi tai thanh pho xuat phat la 0
	minSpending=maxC;
}
void ganMang(int a[], int b[]){
	for(int i=1;i<=n;i++)
		b[i]=a[i];
}
/*void Try(int i){//thu chon cac x[i]
	for(int j=2;j<=n;j++)
		if(Free[j]){
			x[i]=j;//thu di
			T[i]=T[i-1]+a[x[i-1]][j];
			if(T[i]<minSpending)
				if(i<n){//neu chua den duoc x[i-1]
					Free[j]=false;
					Try(i+1);
					Free[j]=true;
				}
				else
					if(T[n]+a[x[n]][1]<minSpending){
						minSpending=T[n]+a[x[n]][1];
						ganMang(x,bestWay);
					}
		}
}*/
void Try(int i){
	for(int j=2;j<=n;j++)
		if(Free[j]){
			x[i]=j;
			T[i]=T[i-1]+a[x[i-1]][j];
			if(T[i]<minSpending)
				if(i<n){
					Free[i]=false;
					Try(i+1);
					Free[j]=true;
				}
				else
					if(T[n]+a[x[n]][1]<minSpending){
						ganMang(x,bestWay);
						minSpending=T[n]+a[x[n]][1];
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
	return 0;
}
