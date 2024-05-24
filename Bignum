#include <iostream>
using namespace std;
#define endl '\n'
#include <string.h>
bool isSmaller(string a, string b)
{
	if (a.size() < b.size())
		return true;
	if (b.size() < a.size())
		return false;
	return a < b;
}
string ADD(string a, string b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (a.size() != b.size())
	{
		if (a.size() < b.size())
			a.push_back('0');
		else
			b.push_back('0');
	}
	string res;
	int carry = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int temp = (a[i] - '0') + (b[i] - '0') + carry;
		int dv = temp % 10;
		carry = temp / 10;
		res.push_back(dv + '0');
	}
	if (carry != 0)
		res.push_back(carry + '0');
	reverse(res.begin(), res.end());
	return res;
}
// ham tru 2 so lon dang xau
string subtract(string a, string b)
{
	//so sanh
	bool sign = false;
	if (isSmaller(a, b))
	{
		swap(a, b);
		sign = true;
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	//chuan hoa du lieu
	while (a.size() != b.size())
	{
		if (a.size() < b.size())
			a.push_back('0');
		else
			b.push_back('0');
	}
	int carry = 0;
	string res;
	for (int i = 0; i < a.size(); i++)
	{
		int tmp = (a[i] - '0') - (b[i] - '0' + carry);
		if (tmp < 0)
		{
			tmp += 10;
			carry = 1;
		}
		else
			carry = 0;
		res.push_back(tmp + '0');
	}
	//loai 0 thua o dau chuoi
	int n = res.size();
	while (res[n - 1] == '0' && n > 1)
	{
		res.pop_back();
		n--;
	}
	if (sign)
		res.push_back('-');
	reverse(res.begin(), res.end());
	return res;
}
string MULINT(string a, int b)
{
	reverse(a.begin(), a.end());
	string res = "";
	int carry = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int temp = (a[i] - '0') * b + carry;
		int dv = temp % 10;
		carry = temp / 10;
		res.push_back(dv + '0');
	}
	if (carry != 0)
		res.push_back(carry + '0');
	reverse(res.begin(), res.end());
	return res;
}
string MULSTR(string a, string b)
{
	reverse(b.begin(), b.end());
	string res = "0";
	string bonus = "";
	for (int i = 0; i < b.size(); i++)
	{
		string temp = MULINT(a, b[i] - '0') + bonus;
		res = ADD(res, temp);
		reverse(res.begin(), res.end());
		while (res[res.size() - 1] == '0' && res.size() > 1)
		{
			res.pop_back();
		}
		reverse(res.begin(), res.end());
		bonus += "0";
	}
	return res;
}
//hàm chia dư 2 số lớn dạng xâu ký tự
string mod(string num1, string num2)
{
	if (isSmaller(num1, num2))
		return num1;
	string result = num1;
	while (!isSmaller(result, num2))
	{
		string tmp = num2;
		while (!isSmaller(result, tmp + "0"))
			tmp += "0";
		result = subtract(result, tmp);
	}
	return result;
}
string longDivision(string number, int divisor)
{
	//chia bignum cho 1 số nguyên
	string ans;
	int index = 0;
	int temp = number[index] - '0';
	while (index < (number.size() - 1) && temp < divisor)
		temp = temp * 10 + (number[++index] - '0');
	while (number.size() - 1 > index)
	{
		//store result in answer i.e. tmp/divisor
		ans += (temp / divisor) + '0';
		//take the next digit of number
		temp = (temp % divisor) * 10 + (number[++index] - '0');
	}
	ans += (temp / divisor) + '0';
	//If divisor is greater than number
	if (ans.length() == 0)
		return "0";
	//else return ans
	return ans;
}
int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a;
	int b;
	cin >> a >> b;
	cout << longDivision(a, b);
	return 0;
}
