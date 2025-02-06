#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, k;
vector<int>a;
void chenSoKhongThieu() {
	while (a.size()<32) {
		a.push_back(0);
	}
}
void chuyenThapPhanSangNhiPhan(int n) {
	while (n > 0) {
		a.push_back(n % 2);
		n = n / 2;
	}
}
void dichBit(int k) {
	//k so lan dich
	int i = 1;
	while (i <= k) {
		a.push_back(a[0]);
		a.erase(a.begin());
		i++;
	}
}
void xoaSoKhongThua() {
	for (int i = a.size() - 1; i >= 0; i--)
		if (a[i] == 1)
			break;
		else
			a.erase(a.begin() + i);
}
long long chuyenNhiPhanSangThapPhan() {
	long long kq = 0;
	for (int i = 0; i < a.size(); i++)
	{
		kq += a[i] * pow(2, i);
	}
	return kq;
}
int main(int argc, char* argv[])
{
	cin >> n >> k;
	chuyenThapPhanSangNhiPhan(n);
	chenSoKhongThieu();
	reverse(a.begin(), a.end());
	dichBit(k);
	reverse(a.begin(), a.end());
	xoaSoKhongThua();
	cout << chuyenNhiPhanSangThapPhan();
	return 0;
}
