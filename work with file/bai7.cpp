/* Ma so sinh vien: 23110196
 Ho va ten sinh vien: Vo Le Khanh Duy
 Ngay sinh:26/3/2005
 Lop:231101B-PRTE230385_23_2_04
*/
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
	int n, a[100];
	ofstream file;
	file.open("D:\\data7_in15so1dong.txt");
	cin>>n;
	srand(time(NULL));
	for(int i=1;i<=n;i++)
	{
		a[i]=rand();
	}
	for(int i=1;i<=n;i++)
	{
		file<<a[i]<<"\t";
		if(i%15==0)
			file<<"\n";
	}
	file.close();
	ifstream file2;
	file2.open("D:\\data7_in15so1dong.txt");
	int dem=0;
	while(!file2.eof()){
		if(dem%15==0)
			cout<<"\n";
		string tmp;
		file2>>tmp;
		cout<<tmp<<"\t";
		dem++;
	}
	file2.close();
	return 0;
}
