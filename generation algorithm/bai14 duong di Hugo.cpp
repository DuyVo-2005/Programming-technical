// bai14 duong di Hugo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<vector>
using namespace std;
#define max 100
int a[max][max], m, n, x, y;
vector<int>v;//chua so nhi phan cua o Hugo dang dung
int c = INT_MAX;//luu do dai hinh trinh
vector<pair<int, int> >kq;//luu duong di tot nhat Hugo di chuyen
vector<pair<int, int> >tmp;//chua duong di thu
bool mark[max][max];//danh dau o da di cua hanh trinh
int duongDi = 0;
int dx[] = { 1,0,-1,-1,-1,0,1,1 };
int dy[] = { 1,1,1,0,-1,-1,-1,0 };
void nhapMeCung() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
}
void chuyenThapPhanSangNhiPhan(int n) {
	v.clear();//lam moi day nhi phan cua o dang xet
	while (n > 0) {
		v.push_back(n % 2);
		n /= 2;
	}
}
void thu(int x, int y) {


	if (x == 1 || y == 1 || x == m  || y == n )
	{
		duongDi++;
		if (duongDi < c)
			c = duongDi;
		kq.clear();
		for (int i = 0; i < tmp.size(); i++)
			kq.push_back({ tmp[i].first,tmp[i].second });//cap nhat duong di tot nhat cua Hugo
	}
	else
	{
		//ko phai o bien
		chuyenThapPhanSangNhiPhan(a[x][y]);
		for (int k = 0; k < 8; k++) {
			int x_moi = x + dx[k];
			int y_moi = y + dy[k];
			if (x_moi >= 1 && y_moi >= 1 && x_moi <= m  && y_moi <= n)
				if (v[k] == 1) {
					duongDi++;
					tmp.push_back({ x_moi,y_moi });
					mark[x_moi][y_moi] = true;
					thu(x_moi, y_moi);
					mark[x_moi][y_moi] = false;
					duongDi--;
					tmp.pop_back();
				}
		}
	}
}
void xuatKq() {
	for (int i = 0; i < kq.size(); i++) {
		cout << "\n" << kq[i].first << " " << kq[i].second;
	}
}
int main(int argc, char* argv[])
{
	nhapMeCung();
	cin >> x >> y;//vi tri Hugo hien tai
	tmp.push_back({ x,y });
	mark[x][y] = true;//da xet
	thu(x, y);
	if (c == INT_MAX)
	{
		c = 0;
		cout << c;
	}
	else
	{
		cout << c;
		xuatKq();
	}
	return 0;
}
/*input
5 6
1 2 3 4 5 6
7 8 9 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 30
3 4
*/
/*output
3
3 4
4 4
5 4
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
