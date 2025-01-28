/* Ma so sinh vien: 23110196
Ho va ten sinh vien: Vo Le Khanh Duy
Ngay sinh: 26/3/2005
Lop: 231101B-PRTE230385_23_2_04*/
#include<iostream>
using namespace std;
#define n 5
int board[n][n];//tao ban co rong
int di[]={-2,-2,-1,1,2,2,1,-1}, dj[]={1,-1,-2,-2,-1,1,2,2};
int step=0;
int ok=0;//gia su khong co nghiem
bool checkOHopLe(int i, int j){
	if(i>=0&&i<n&&j>=0&&j<n)
		return true;
	return false;
}
void xuatKq(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<board[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;	
}
void Try(int i, int j){
	for(int k=0;k<8;k++){
		if(checkOHopLe(i+di[k],j+dj[k])&&board[i+di[k]][j+dj[k]]==0){
			board[i+di[k]][j+dj[k]]=++step;
			if(step<n*n){//chua di het tat ca o
				Try(i+di[k],j+dj[k]);
				board[i+di[k]][j+dj[k]]=0;
				step--;
			}
			else
			{
				ok=1;//co nghiem
				xuatKq();
				exit(0);
			}
		}
	}
}
int main(int argc, char *argv[])
{
	int x,y;
	cout<<"Nhap toa do o (x,y) muon di: "<<endl;
	cin>>x>>y; //vd (2,0)
	board[x][y]=++step;//thu di tu o(2,0)
	Try(x,y);
	if(ok==0)//vo nghiem
		cout<<"No solution";
	return 0;
}
