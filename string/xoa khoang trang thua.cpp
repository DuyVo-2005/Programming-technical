#include<iostream>
#include<string.h>
using namespace std;
bool KTThuong(char s)
{
	if(s>='a'&&s<='z')
		return true;
	return false;
}
bool laChu(char s)
{
	if((s>='a'&&s<='z')||(s>='A'&&s<='Z'))
	return true;
return false;
}
void xoa(char s[], int pos)
{	
	int n=strlen(s);//gan n bang do dai chuoi
	for(int i=pos;i<n;i++)// duyet tu vi tri xoa
	{
		s[i]=s[i+1];
	}
	s[n-1]='\0';
}
void xoaKhoangTrangThua(char s[])
{
	int i;// i la vi tri khoang trang thua
	int n=strlen(s);

	for(i=0;i<n;i++)
	{
		if(s[i]==' '&&s[i+1]==' '){
			xoa(s,i);
			i--;
		}
	}
	if(s[0]==' ')
		xoa(s,0);
	if(s[n-1]==' ')
		xoa(s,n-1);
}
int main(int argc, char *argv[])
{
	char s[50];
	cin.getline(s,50);
	/*if(KTThuong(s[1]))
		s[1]-=32;
	for(int i=0;i<strlen(s)-2;i++)
		if(s[i]==' '&&laChu(s[i+1])&&KTThuong(s[i+2]))
			s[i+2]-=32;*/
	/*xoaKhoangTrangThua(s);
	cout<<s;*/
	/*char a[100];
	for(int i=0;i<strlen(s);i++)
		a[i]=s[i];
	cout<<a;*/
	/*std::string a[100];
	a[0]="Hello";
	cout<<a[0];*/
	char t[48];
	cin.getline(t,48);
	/*if(strstr(s,t)!=NULL)
		cout<<"Tim thay t trong s tai "<<s-(strstr(s,t));
	else
		cout<<"Khong co t trong s";*/
	int dem=0;
	for(int i=0;i<strlen(s);i++)
		if(strstr(s,t)!=NULL)
		{
			dem++;
			i=s-(strstr(s,t))+strlen(t);
		}
	cout<<dem;
}
