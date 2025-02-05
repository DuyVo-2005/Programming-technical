#include<iostream>
using namespace std;
#include<string.h>
char matrix[1000+2][1000+2];
int n,m, ia, ja, ib, jb;
bool visited[1000+2][1000+2];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int count=0;//dem buoc di
void nhapMeCung(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>matrix[i][j];
}
void xuatMeCung(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
}
void timViTri(int &ia, int &ja, char x){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(matrix[i][j]==x)
			{
				ia=i;
				ja=j;
				break;
			}
}
void thu(int x, int y, int &count){
	if(matrix[x][y]!='B'){
		for(int i=0;i<4;i++){
			int x_moi=x+dx[i], y_moi=y+dy[i];
			if(x_moi>=0&&x_moi<n&&y_moi>=0&&y_moi<m)
				if(matrix[x_moi][y_moi]=='.')
					if(visited[x_moi][y_moi]==false){
						count++;
						visited[x_moi][y_moi]=true;
						thu(x_moi,y_moi, count);
						visited[x_moi][y_moi]=false;//quay lui
						count--;
					}
			
		}
	}
	else{
		cout<<count;
		}
}
int main(int argc, char *argv[])
{
	nhapMeCung();
	timViTri(ia,ja,'A');
	thu(ia,ja,count);
	return 0;
}
