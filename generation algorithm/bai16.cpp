#include<iostream>
#include<vector>
using namespace std;
struct phanSo{
	int tuSo;
	int mauSo;
};
void xuatPhanSo(phanSo a){
	cout<<a.tuSo<<"/"<<a.mauSo<<endl;
}
int soSanhPhanSo(phanSo a, phanSo b){
	if(float(a.tuSo)/a.mauSo>float(b.tuSo)/b.mauSo)
		return 1;
	else
		if(float(a.tuSo)/a.mauSo<float(b.tuSo)/b.mauSo)	
			return -1;
		else
			return 0;
}
int ucln(int a, int b){
	while(a%b!=0){
		int tmp=a%b;
		a=b;
		b=tmp;
	}
	return b;
}
bool checkPhanSoToiGian(phanSo &a){
	int UCLN=ucln(a.tuSo,a.mauSo);
	if(UCLN==1)
		return true;
	return false;
}
void sapMangTangDan(vector <phanSo> &v){//luu y &v
	for(int i=0;i<v.size()-1;i++)
		for(int j=i+1;j<v.size();j++)
			if(soSanhPhanSo(v[i],v[j])==1)
			{
				phanSo tmp=v[i];
				v[i]=v[j];
				v[j]=tmp;
			}
}
void sinhCacPhanSoToiGian(){
	vector <phanSo> v;
	phanSo a;
	for(int i=1; i<=10;i++)
		for(int j=i+1;j<=10;j++){
			a.tuSo=i;
			a.mauSo=j;
			if(checkPhanSoToiGian(a))
				if(float(a.tuSo)/a.mauSo>0&&float(a.tuSo)/a.mauSo<1)
				v.push_back(a);
		}
	sapMangTangDan(v);
	for(int i=0;i<v.size();i++)
		xuatPhanSo(v[i]);
}
int main(){
	sinhCacPhanSoToiGian();
	return 0;
}
