#include<iostream>
using namespace std;
int n;
void chuyen(int i, char a, char b){
	cout<<"chuyen "<<i<<" tu "<<a<<" sang "<<b<<endl;
}
void thap(int i, char ng, char d, char tg ){
	if(i>0){
		thap(i-1,ng,tg,d);
		chuyen(i,ng,d);
		thap(i-1,tg,d,ng);
	}
}
int main(){
	cin>>n;
	thap(n,'a','c','b');
	return 0;
}
