#include<iostream>
#include<string.h>
using namespace std;
void xoa(char s[], int vt)
{	
	int i;
	for(i=vt;i<strlen(s)-1;i++)
		s[i]=s[i+1];
	s[strlen(s)-1]='\0';
}
int tims2Trongs1(char s1[], char s2[])
{
	int vt=-1;
	if(strstr(s1,s2)!=NULL)
		vt=strlen(s1)-strlen(strstr(s1,s2));
	return vt;
}
int main()
{
	char s[]="I am a king.";
	char s2[50];
	cout<<"Nhap tu can xoa: ";
	cin.getline(s2,50);
	int i=0;
	int vtXoa=tims2Trongs1(s,s2);
	while(strstr(s,s2)!=NULL)
	{
		int n=strlen(s2);
		int lan=1;
		while(lan<=n)
		{
			xoa(s,vtXoa);
			lan++;
		}
	}
	cout<<s;
}
