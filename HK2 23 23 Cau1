#include<iostream>
using namespace std;
#define endl '\n'
#include<math.h>
//tk gpt
// Hàm trả về số lượng ước số của một số nguyên dương n
int countDivisors(long long n) {
    int count = 0;
    long long sqrt_n = sqrt(n);

    for (long long i = 1; i <= sqrt_n; ++i) {
        if (n % i == 0) {
            // Nếu i là ước của n, thì n/i cũng là ước của n
            if (i == n / i) {
                count += 1; // Nếu i và n/i bằng nhau (ví dụ n = 25, i = 5)
            } else {
                count += 2; // Nếu i và n/i khác nhau
            }
        }
    }
    return count;
}
/*long long demUoc(long long n)
{
	if(n==1)
		return 1;
	long long uoc=2;// 1 va chinh no
	for(long long i=2;i<n;i++){
		if(n%i==0){
			uoc++;
			//n/=i;
		}
	}
	return uoc;
}*/
int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	clock_t begin = clock();//ghi lại thời gian lúc đầu
	long long n;
    cout << "Nhập số nguyên dương n: ";
    cin >> n;
    int result = countDivisors(n);
    cout << "Số lượng ước số của " << n << " là: " << result << endl;
	/*cin>>n;
	cout<<demUoc(n);*/
	
	clock_t end = clock(); //ghi lại thời gian lúc sau
   cout<<"\nTime run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
	return 0;
}
