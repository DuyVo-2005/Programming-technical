/* Ma so sinh vien: 23110196
 Ho va ten sinh vien: Vo Le Khanh Duy
 Ngay sinh:26/3/2005
 Lop:231101B-PRTE230385_23_2_04
*/
#include<iostream>
#include<fstream>
using namespace std;
void sapMang(int a[], int n){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
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
	ofstream outfile;
	outfile.open("D:\\data4.txt_sapMang");
	sapMang(a,n);
	outfile<<n<<endl;
	for(int i=0;i<n;i++)
		outfile<<a[i]<<"\t";
	infile.close();
	return 0;
}
