#include<iostream>
#include<string.h>
using namespace std;
void strInsert(char s[], char s2[], int pos)
{
	int n=strlen(s2);
	for(int i=strlen(s)-1;i>=pos;i--)
	{
		s[i+n]=s[i];
	}
	for(int i=pos,j=0;j<n&&s2[j]!='\0';i++,j++)
	{
		s[i]=s2[j];
	}
	s[strlen(s)-1]='\0';
	cout<<s;
}
int main()
{
	char s[]="abcde fghij";
	char s2[50];
	int pos;
	cout<<"Nhap vi tri: ";
	cin>>pos;
	cout<<"Nhap chuoi can chen: ";
	cin.ignore();
	cin.getline(s2,50);
	strInsert(s,s2,pos);
}
