/* Ma so sinh vien: 23110196
 Ho va ten sinh vien: Vo Le Khanh Duy
 Ngay sinh:26/3/2005
 Lop:231101B-PRTE230385_23_2_04
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
int main()
{
	char a[10000], kyTu;
	ofstream outfile;
	outfile.open("D:\\data6.txt");
	do{
		cin.getline(a,10000);
		//nhap xong 1 dong nhan phim enter de nhap dong moi
		outfile<<a<<endl;
		kyTu=getch();
	}
	while(kyTu!=27);//nhap ESC de thoat.
	outfile.close();
	
	ifstream f2;
	f2.open("D:\\data6.txt");
	string b;
	while(!f2.eof()){
		getline(f2,b);
		cout<<b<<endl;
	}
	f2.close();
	return 0;
}
