/* Ma so sinh vien: 23110196
 Ho va ten sinh vien: Vo Le Khanh Duy
 Ngay sinh:26/3/2005
 Lop:231101B-PRTE230385_23_2_04
*/
#include<iostream>
using namespace std;
#include<vector>
#define Max 10001
#define infinite 99999999
#include<algorithm>
int n,M;
int F[Max];//F[i] so to it nhat dung tra so tien i dong, i€[1,M], F[i]=infinite neu ko doi duoc
int x[Max];//x[i] loai tien cuoi cung dung de doi so tien i dong (chi luu 1 loai tien)
int main(int argc, char *argv[])
{
	cin>>n>>M;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin()+1,a.end());//ko dung a[0]
	int i, j;
	for(i=1;i<=M;i++)
	{
		F[i]=infinite;
		x[i]=0;
	}
	F[0]=0;
	for(i=1;i<=M;i++){
		int min=F[i];//ko chon
		x[i]=0;
		for(j=1;j<=n;j++)
			if((i>=a[j])&&(F[i-a[j]]+1<min)){// co chon a[j]
				min=F[i-a[j]]+1;//co cap nhat min
				F[i]=min;
				x[i]=j;
			}
	}
	vector<int>count(n+1,0);
	if(F[M]!=infinite){
		cout<<F[M];
	}
	else
		cout<<-1;	
	return 0;
}
/*
in:
3 18
3 10 12
out:
3
2 3
1 12
*/
/*
in:
3 11
1 5 7
out: 3
*/
