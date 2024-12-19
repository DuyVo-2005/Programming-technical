#include<iostream>
using namespace std;
#define endl '\n'
#include<string.h>
#include<algorithm>
#include<vector>
/*char x[105], y[105];
int lcs(int i, int j){
	if(i==0||j==0)
		return 0;
	if(x[i]==y[j]){
		return 1+lcs(i-1,j-1);
	}
	return max(lcs(i,j-1), lcs(i-1,j));
}
int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin.getline(x,105);
	cin.getline(y,105);
	cout<<lcs(strlen(x)-1,strlen(y)-1);
	return 0;
}*/
/*char x[105], y[105];
vector<vector<int>>memo(1005,vector<int>(1005,-1));
int lcs(int i, int j){
	if(i==0||j==0)
		return 0;
	if(memo[i][j]!=-1)
		return memo[i][j];
	if(x[i]==y[j]){
		return memo[i][j]=1+lcs(i-1,j-1);
	}
	return memo[i][j]=max(lcs(i,j-1), lcs(i-1,j));
}
int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin.getline(x,105);
	cin.getline(y,105);
	cout<<lcs(strlen(x)-1,strlen(y)-1);
	return 0;
}*/
string x, y;
vector<vector<int>>dp(1005,vector<int>(1005,0));
int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>x>>y;
	int n_x=x.size(), n_y=y.size(), i, j;
	x=" "+x, y=" "+y;
	for(i=1;i<=n_x;i++)
		for(j=1;j<=n_y;j++){
			if(x[i]==y[j])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	cout<<dp[n_x][n_y];
	return 0;
}
/*
CEACEEC
AECECA
*/
