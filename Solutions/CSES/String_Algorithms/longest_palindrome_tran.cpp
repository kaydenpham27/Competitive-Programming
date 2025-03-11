#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// Hàm tiền xử lý chuỗi bằng cách chèn thêm các ký tự đặc biệt
string preprocess(const string &s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    return t;
}
 
string longestPalindrome(const string &s) {
    if (s.empty()) return "";
 
    // Tiền xử lý chuỗi
    string t = preprocess(s);
    int n = t.size();
    vector<int> p(n, 0);  // Mảng lưu bán kính đối xứng
    int center = 0, right = 0; // Tâm và biên phải của chuỗi đối xứng lớn nhất
 
    int maxLen = 0, maxCenter = 0;
 
    // Thuật toán Manacher
    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i; // Vị trí đối xứng của i so với center
 
        if (i < right)
            p[i] = min(right - i, p[mirror]);
 
        // Mở rộng đối xứng quanh vị trí i
        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1])
            p[i]++;
 
        // Nếu mở rộng vượt biên phải, cập nhật lại center và right
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
 
        // Cập nhật chuỗi đối xứng dài nhất
        if (p[i] > maxLen) {
            maxLen = p[i];
            maxCenter = i;
        }
    }
 
    // Lấy ra chuỗi đối xứng dài nhất từ chuỗi đã tiền xử lý
    int start = (maxCenter - maxLen) / 2;  // Tính vị trí bắt đầu của chuỗi con trong chuỗi gốc
    return s.substr(start, maxLen);
}
 
int main() {
    string s;
    cin >> s;
 
    string result = longestPalindrome(s);
    cout << result << endl;
 
    return 0;
}