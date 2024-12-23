#include <iostream>
using namespace std;
const int Max = 31; // Giới hạn tối đa của mảng, t (tổng), x (các phần tử)

int n, x[Max], t[Max];

// Hàm kiểm tra và nhập số nguyên dương
void InputNumber() {
    cout << "Nhập n (số nguyên dương): ";
    while (true) {
        cin >> n;

        // Kiểm tra nếu nhập lỗi (ví dụ: nhập chữ cái hoặc ký tự không hợp lệ)
        if (cin.fail() || n <= 0) {
            cin.clear(); // Xóa trạng thái lỗi của cin
            cin.ignore(1000, '\n'); // Bỏ qua các ký tự còn lại trong dòng nhập
            cout << "Lỗi: Vui lòng nhập một số nguyên dương! Thử lại: ";
        } else {
            cin.ignore(1000, '\n'); // Bỏ qua các ký tự còn lại (nếu có)
            break; // Thoát vòng lặp khi đầu vào hợp lệ
        }
    }
}

// Hàm khởi tạo
void Init() {
    InputNumber(); // Gọi hàm kiểm tra và nhập số
    x[0] = 1;      // Phần tử đầu tiên >= 1
    t[0] = 0;      // Tổng ban đầu = 0
}

// Hàm in kết quả
void PrintResult(int k) {
    cout << n << " = ";
    for (int i = 1; i < k; i++) {
        cout << x[i] << " + ";
    }
    cout << x[k] << endl;
}

// Hàm đệ quy tìm tất cả các cách phân tích
void Try(int i) {
    for (int j = x[i - 1]; j <= (n - t[i - 1]) / 2; j++) {
        x[i] = j;
        t[i] = t[i - 1] + j;
        Try(i + 1); // Gọi đệ quy cho phần tử tiếp theo
    }
    // In ra kết quả cho giá trị cuối cùng
    x[i] = n - t[i - 1];
    if (x[i] >= x[i - 1]) { // Kiểm tra để đảm bảo không giảm dần
        PrintResult(i);
    }
}

// Hàm chính
int main() {
    Init();     // Khởi tạo
    cout << "\nPhân tích số nguyên n thành tổng các số nguyên theo thứ tự tăng dần: \n";
    Try(1);     // Bắt đầu từ phần tử đầu tiên
    return 0;
}
