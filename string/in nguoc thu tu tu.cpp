#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char s[]="Lap trinh c++";
	char dao[50]="\0";
	char tam[50];
	int i,j;
	for(i=strlen(s)-1;i>=0;i--)
	{
		for(j=0;i>=0&&s[i]!=' ';j++,i--)
			tam[j]=s[i];
		tam[j]='\0';
		strcat(dao,strrev(tam));
		strcat(dao," ");
	}
	cout<<dao;
}
