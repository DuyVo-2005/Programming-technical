#include<iostream>
#include<fstream>
using namespace std;
#define max 20
int main(){
	int a[max],bestWay[max];
	ifstream f;
	f.open("D:\\bai16in.txt");
	for(int i=0;i<20;i++)
		f>>a[i];
	for(int i=0;i<20;i++)
		bestWay[i]=a[i];
	for(int i=0;i<20;i++)
		cout<<bestWay[i]<<" ";
}
