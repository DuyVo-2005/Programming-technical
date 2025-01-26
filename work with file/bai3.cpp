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
int main()
{
	int n, a[100];
	ofstream outfile;
	outfile.open("D:\\data3.txt");
	cin>>n;
	outfile<<n<<endl;
	srand(time(NULL));
	for(int i=0;i<n;i++)
		a[i]=rand()%1001;
	for(int i=0;i<n;i++)
		outfile<<a[i]<<"\t";
	outfile.close();
	return 0;
}
