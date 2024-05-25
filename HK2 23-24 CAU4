#include <iostream>
#include <string>
using namespace std;
// Hàm kiểm tra xem một chuỗi con có thể trở thành đối xứng nếu thay đổi đúng một ký tự
bool is_special(string sub) {
    int n = sub.size();
    if (n == 1) {
        return true; // Chuỗi một ký tự luôn là đặc biệt
    }
    int mismatches = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (sub[i] != sub[n - 1 - i]) {
            mismatches++;
        }
    }
    if(mismatches==0&&(n%2!=0))//chuỗi lẻ đối xứng
    	return true;
    if (mismatches == 1) {//không lớn hơn 1 và khác rỗng
            return true;
    }
    return false;
}

int count_special_substrings(string s) {
    int n = s.size();
    int special_count = 0;
    for (int start = 0; start < n; ++start){
        for (int  end = start+1; end <=n; ++end) {
            string sub = s.substr(start, end-start);//hàm .substr(vị trí bắt đầu, số từ) trả về 1 xâu ký tự
            if (is_special(sub)) {
                //cout<<sub<<"\n";
                special_count++;
            }
        }
    }
   return special_count;
}
int main() {
    string s;
    cin >> s;
    //count_special_substrings(s);
    cout << count_special_substrings(s);
    return 0;
}
//abaab
