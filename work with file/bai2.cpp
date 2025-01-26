/* Ma so sinh vien: 23110196
 Ho va ten sinh vien: Vo Le Khanh Duy
 Ngay sinh:26/3/2005
 Lop:231101B-PRTE230385_23_2_04
*/
#include<iostream>
#include<fstream>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
	int a, b, c;
	fstream outfile, infile;
	infile.open("D:\\data1.txt",ios::in);
	infile>>a>>b>>c;
	infile.close();
	outfile.open("D:data2_NghiemPTBac2.txt",ios::out);
	string vn="Phuong trinh vo nghiem";
	string vsn="Phuong trinh co vo so nghiem";
	if(a==0)
		if(b==0)
			if(c==0)
				outfile<<vsn;
			else
				outfile<<vn;
		else
			outfile<<-c/b;
	else
	{
		int delta=b*b-4*a*c;
		if(delta<0)
			outfile<<vn;
		else
			if(delta==0)
				outfile<<-b/(2*a);
			else
				outfile<<(-b+sqrt(delta))/(2*a)<<"\t"<<(-b-sqrt(delta))/(2*a);
	}
	outfile.close();
	return 0;
}
