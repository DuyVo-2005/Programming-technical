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
using namespace std;
void sapMang(int a[], int n){
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]>a[j]){
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
}
int main(){
	fstream f;
	f.open("D:\\SONGUYEN.INP",ios::out|ios::binary);
	int n=10000;
	int b[max];
	srand(time(NULL));
	for(int i=1;i<=n;i++)
	{
		b[i]=rand();
	}
	for(int i=1;i<=n;i++)
	{
		f.write((char*)&b[i],sizeof(b[i]));
		if(i%10==0)
			f.write((char*)&"\n",sizeof("\n"));
	}
	f.close();
	
	fstream f2;
	int a[max];
	f2.open("D:\\SONGUYEN.INP",ios::in|ios::binary);
	for(int i=1;i<=n;i++)
		f2.read((char*)&a[i],sizeof(a[i]));
	f2.close();
	
	sapMang(a,n);
	ofstream f3;
	f3.open("D:\\SONGUYEN.OUT");
	for(int i=1;i<=n;i++)
	{
		f3<<a[i]<<"\t";
		if(i%10==0)
			f3<<"\n";
	}
	f3.close();
	return 0;
}
