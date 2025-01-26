/* Ma so sinh vien: 23110196
 Ho va ten sinh vien: Vo Le Khanh Duy
 Ngay sinh:26/3/2005
 Lop:231101B-PRTE230385_23_2_04
*/
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#define max 10001
#include<string.h>
bool checkTrung(int a[], int n, int x){
	for(int i=0;i<n;i++)
		if(a[i]==x)
			return true;
	return false;
}
using namespace std;
int main(){
	ofstream f;
	f.open("D:\\SONGUYEN.INP");
	int a[max];
	int n=10000;
	srand(time(NULL));
	for(int i=0;i<n;i++){
		int tmp;
		do{
			tmp=rand();
		}
		while((checkTrung(a,n,tmp))||(tmp==0));
		a[i]=tmp;
	}
	for(int i=0;i<n;i++)
	{
		f<<a[i]<<"\n";
	}
	f.close();
	return 0;
}
