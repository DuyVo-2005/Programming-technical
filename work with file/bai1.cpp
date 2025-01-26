/* Ma so sinh vien: 23110196
 Ho va ten sinh vien: Vo Le Khanh Duy
 Ngay sinh:26/3/2005
 Lop:231101B-PRTE230385_23_2_04
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int a,b,c;
	ofstream outfile;
	outfile.open("D:\\data1.txt");
	cin>>a>>b>>c;
	outfile<<a<<"\t"<<b<<"\t"<<c;
	outfile.close();
	return 0;
}
