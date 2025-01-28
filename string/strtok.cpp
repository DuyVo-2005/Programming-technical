#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char s[]="Ho Chi Minh";
	char *s2;
	s2 = strtok(s," ");
	cout<<s2;
	while(s2!=NULL)
	{
		s2 = strtok(NULL," ");
		if(s2!=NULL)
			cout<<s2;
	}
}
