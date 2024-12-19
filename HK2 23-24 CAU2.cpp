#include<iostream>
using namespace std;
#define endl '\n'
#include<vector>
#include<string.h>
vector<string>a;
void printResult(){
	for(long long i=a.size()-1;i>=0;i--)
		cout<<a[i];
}
bool isSmaller(string a, string b)
{
	if (a.size() < b.size())
		return true;
	if (b.size() < a.size())
		return false;
	return a < b;
}
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
void  convertDecimalToBinaryNumber(string n){
	if(n=="0"){
		cout<<0;
		return ;
	}
	while(n!="0"){
		a.push_back(mod(n,"2"));
		n=longDivision(n,2);
	}
	printResult();
}
int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	clock_t begin = clock();//ghi lại thời gian lúc đầu
	
	string n;
	cin>>n;
	convertDecimalToBinaryNumber(n);
	
	clock_t end = clock(); //ghi lại thời gian lúc sau
   cout<<"\nTime run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
	return 0;
}
