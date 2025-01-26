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
using namespace std;
void nhapMang(int a[], int &n){
	cout<<"Nhap so luong so nguyen: ";
	cin>>n;
	srand(time(NULL));
	for(int i=0;i<n;i++)
		a[i]=rand();
}
void xuatMangRaFile(int a[], int n, ofstream &f){
	for(int i=0;i<n;i++)
		f<<a[i]<<" ";
}
bool checkChan(int n){
	if(n%2==0)
		return true;
	return false;
}
int main(){
	ofstream f;
	f.open("D:\\SONGUYEN.INP");
	int a[max], n;
	nhapMang(a,n);
	xuatMangRaFile(a,n,f);
	f.close();
	
	ifstream f2;
	f2.open("D:\\SONGUYEN.INP");
	int b[max];
	int nb=0;
	while(!f2.eof()){
		f2>>b[nb];
		nb++;
	}
	f2.close();
	
	ofstream f3, f4;
	f3.open("D:\\SOLE.OUT");
	f4.open("D:\\SOCHAN.OUT");
	for(int i=0;i<nb-1;i++)
		if(checkChan(b[i]))
			f4<<b[i]<<"\t";
		else
			f3<<b[i]<<"\t";
	f3.close();
	f4.close();
	return 0;
}
