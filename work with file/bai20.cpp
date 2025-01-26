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
bool checkChan(int n){
	if(n%2==0)
		return true;
	return false;
}
void nhapMangChan(int a[], int &n){
	cout<<"Nhap so luong so nguyen: ";
	cin>>n;
	srand(time(NULL));
	for(int i=0;i<n;i++){
		int tmp;
		tmp=rand()%101;
		while(checkChan(tmp)==false){
			tmp=rand()%101;
		}
		a[i]=tmp;
	}	
}
void xuatMangRaFile(int a[], int n, ofstream &f){
	f<<a[0];
	for(int i=1;i<n;i++)
		f<<"\t"<<a[i];
	//tranh thua " "
}
int main(){
	int a[max], n;
	nhapMangChan(a,n);
	ofstream f;
	f.open("D:\\SOCHAN.DAT");
	xuatMangRaFile(a,n,f);
	f.close();
	
	ifstream f2;
	f2.open("D:\\SOCHAN.DAT");
	int i=1;
	while(!f2.eof()){
		int x;
		f2>>x;
		cout<<x<<"\t";
		if(i%30==0)
			cout<<"\n";
		i++;
	}
	f2.close();
	return 0;
}
