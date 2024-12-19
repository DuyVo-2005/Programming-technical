#include <iostream>
using namespace std;
const int inf = 1005;
int m, n, x_start, y_start, k;
int minute = 1;
int h[inf][inf];

const int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};

const int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};

bool checkBien(int x, int y)
{
	if (x == 1 || x == m || y == 1 || y == n)

		return true;

	return false;
}
void loang(int x_fi, int y_fi)
{
	int min, pos1, pos2;
	min = h[x_fi][y_fi];

	for (int k = 0; k < 8; k++)
	{
		int x = x_fi + dx[k], y = y_fi + dy[k];
		if (x > 0 && x <= m && y > 0 && y <= n)
		{
			if (h[x][y] < min)
			{
				min = h[x][y];
				pos1 = x;
				pos2 = y;
			}
		}
	}
	if (min != h[x_fi][y_fi]){
		if (checkBien(pos1, pos2)){
			cout << "YES"<< "\n"<<minute;
			return;
		}
		else
		{
			if (minute < k){
				minute++;//loang tiếp phút tiếp theo
				loang(pos1, pos2);
			}
			else
			{
				cout << "NO" << "\n";
				cout << pos1 << " " <<pos2;
				return;
			}
		}
	}
	else
	{
		cout << "NO" << "\n";
		cout << pos1 << " " <<pos2;
		return;
	}
}
int main()
{
	cin >> m >> n >> x_start >> y_start >> k;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> h[i][j];
	int min, pos1, pos2;
	min = h[x_start][y_start];

	for (int k = 0; k < 8; k++)
	{
		int x = x_start + dx[k], y=y_start + dy[k];
		if (x > 0 && x <= m && y > 0 && y <= n)
		{
			if (h[x][y] < min)
			{
				min = h[x][y];
				pos1 = x;
				pos2 = y;
			}
		}
	}
	if (min != h[x_start][y_start]){
		if (checkBien(pos1, pos2)){
			cout << "YES"<< "\n"<<minute;
			return 0;
		}
		else
		{
			if (minute < k){
				minute++;//loang phút tiếp theo
				loang(pos1, pos2);
			}
			else
			{
				cout << "NO" << "\n";
				cout << pos1 << " " <<pos2;
				return 0;
			}
		}
	}
	else
	{
		cout << "NO" << "\n";
		cout << pos1 << " " <<pos2;
		return 0;
	}
}
/*
4 4
3 3
4
14 15 4 3
1 2 7 12
13 11 6 10
9 5 8 16

4 4
3 3
1
14 15 4 3
1 2 7 12
13 11 6 10
9 5 8 16
*/
