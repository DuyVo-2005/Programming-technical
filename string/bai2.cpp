#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<string.h>
#include<string>
char s[205];
int main(){
	char kq[205];
	cin.getline(s,205);
	int n=strlen(s), i_tmp=0;
	char tmp[205];
	for(int i=0;i<=n;i++){
		if(s[i]!=' '&&s[i]!='\0')
		{
			tmp[i_tmp++]=s[i];
		}
		else{
			tmp[i_tmp]='\0';
			strrev(tmp);
			strcat(kq,tmp);
			strcat(kq," ");
			i_tmp=0;
		}
	}
	kq[strlen(kq)-1]='\0';
	cout<<kq;
	return 0;
}
//Su Pham Ky Thuat
