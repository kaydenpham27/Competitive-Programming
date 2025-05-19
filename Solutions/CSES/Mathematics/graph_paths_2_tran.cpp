#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
 
using namespace std;
 
const long long INF = LLONG_MAX;
const int MAXN = 105;
 
int n, m, k;
vector<vector<long long>> W(MAXN, vector<long long>(MAXN, INF));
 
// Hàm nhân ma trận để tìm đường đi ngắn nhất với số cạnh xác định
vector<vector<long long>> multiply(const vector<vector<long long>> &A, const vector<vector<long long>> &B) {
    vector<vector<long long>> C(n + 1, vector<long long>(n + 1, INF));
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int t = 1; t <= n; t++) {
                if (A[i][t] < INF && B[t][j] < INF) {
                    C[i][j] = min(C[i][j], A[i][t] + B[t][j]);
                }
            }
        }
    }
    return C;
}
 
// Hàm lũy thừa ma trận bằng phương pháp chia để trị
vector<vector<long long>> matrixExpo(vector<vector<long long>> base, int exp) {
    vector<vector<long long>> result(n + 1, vector<long long>(n + 1, INF));
 
    // Khởi tạo ma trận đơn vị
    for (int i = 1; i <= n; i++) {
        result[i][i] = 0;
    }
 
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp /= 2;
    }
 
    return result;
}
 
int main() {
    cin >> n >> m >> k;
 
    // Khởi tạo ma trận trọng số ban đầu
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        W[a][b] = min(W[a][b], c);  // Lưu trọng số cạnh từ a đến b
    }
 
    // Tính lũy thừa ma trận W^k để tìm đường đi với đúng k cạnh
    vector<vector<long long>> result = matrixExpo(W, k);
 
    long long answer = result[1][n];
 
    if (answer == INF) {
        cout << -1 << endl;  // Không có đường đi nào thỏa mãn điều kiện
    } else {
        cout << answer << endl;  // Độ dài đường đi ngắn nhất
    }
 
    return 0;
}