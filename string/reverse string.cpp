#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main(int argc, char *argv[])
{
	/*char s[10];
	cin.getline(s,10);
	cout<<s;*/
	char s[]="Bai tap lap trinh ve nha";
	char chDao[100];
	char tam[50];
	char doi[100];
	int i,j;
	for(i=strlen(s);i>=0;i--){
		for(j=0;i>=0&&s[i]!=' ';i--,j++)
			tam[j]=s[i];
		tam[j]='\0';
		/*for(int i=strlen(s);i>=0;i--)
			doi[strlen(s)-i]=s[i];*/
		strrev(tam);
		strcat(chDao,tam);
		strcat(chDao," ");
	}
	cout<<"Chuoi ban dau: "<<s;
	cout<<"\nChuoi dao: "<<chDao;
	return 0;
}
