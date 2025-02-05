#include<bits/stdc++.h>
using namespace std;
#include<string.h>
void tich2SoLon(char s1[], char s2[], char kq[]){
	int n1=strlen(s1), n2=strlen(s2), i1, i2, nho;
	strrev(s1);
	strrev(s2);
	for(int i=0;i<n1+n2;i++)
		kq[i]='0';
	for(i2=0;i2<n2;i2++)
	{
		nho=0;
		for(i1=0;i1<n1;i1++)
		{
			int tmp=(s1[i1]-'0')*(s2[i2]-'0')+nho+(kq[i1+i2]-'0');
			kq[i1+i2]=tmp%10+'0';
			nho=tmp/10;
		}
		if(nho!=0){
			kq[i1+i2]=nho+'0';
		}
	}
	if(nho!=0)
		kq[i1+i2]=nho+'0';
	if(kq[strlen(kq)-1]=='0')
		kq[strlen(kq)-1]='\0';//so 0 thua
	else
		kq[strlen(kq)]='\0';
}
int main(){
	char s1[100], s2[100], kq[200];
	cin>>s1>>s2;
	tich2SoLon(s1,s2, kq);
	for(int i=strlen(kq)-1;i>=0;i--)
		cout<<kq[i];
	return 0;
}
