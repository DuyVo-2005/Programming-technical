#include<iostream>
using namespace std;
#define endl '\n'
#include<vector>
#include<math.h>
#include<iomanip>
int n;
int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	vector<float>a(n);
	int i;
	float s;
	for(i=0;i<n;i++)	cin>>a[i];
	for(i=0;i<n;i++)
		if(a[i]>=0)	s+=a[i];
	//cout<<(float)round(s*pow(10,2)/pow(10,2));
	cout<<setprecision(2)<<fixed<<s;
	return 0;
}

/*
9
10 4 -5 7 -45 14 30 -2 50
*/
