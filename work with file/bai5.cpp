/* Ma so sinh vien: 23110196
 Ho va ten sinh vien: Vo Le Khanh Duy
 Ngay sinh:26/3/2005
 Lop:231101B-PRTE230385_23_2_04
*/
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
bool checkNT(int n){
	if(n<2)
		return false;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
			return false;
	return true;
}
int main()
{
	int n, a[100];
	ifstream infile;
	infile.open("D:\\data3.txt");
	infile>>n;
	for(int i=0;i<n;i++)
		infile>>a[i];
	infile.close();

	int dem=0;
	for(int i=0;i<n;i++)
		if(checkNT(a[i]))
			dem++;
	cout<<"So luong so nguyen to da doc tu file: "<<dem;
	return 0;
}
