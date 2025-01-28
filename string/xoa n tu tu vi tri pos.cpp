#include<iostream>
#include<string.h>
using namespace std;
void erase(char s[], int vt, int n)
{
	strcpy(s+vt,s+vt+n);
	puts(s);
}//tham khao
void xoa(char s[], int vt)
{	
	int i;
	for(i=vt;i<strlen(s)-1;i++)
		s[i]=s[i+1];
	s[strlen(s)-1]='\0';
}
int main()
{
	char s[]="abcde fghij";
	int vt, n;
	cout<<"Nhap vt: ";
	cin>>vt;
	cin>>n;
	/*int lan=1;
	while(lan<=n)
	{
		xoa(s,vt);
		lan++;
	}
	cout<<s;*/
	erase(s,vt,n);
}
