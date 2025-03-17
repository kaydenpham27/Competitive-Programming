#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 5e5 + 5;
const int inf = 1e19;
const int mod = 1e9 + 7;
 
int n, m, cur, f[2][2][20][20];
string s;
 
void Add(int &x, int y){
    x += y;
    x = min(x, inf);
}
 
int dp(int ok, int sta, int dem, int pos){
    if (pos == m) return dem;
    int &res = f[ok][sta][dem][pos];
    if (res != -1) return res;
 
    res = 0;
    int lim = ok ? 9 : s[pos] - '0';
    for (int i = 0; i <= lim; ++ i){
        Add(res, dp(ok | (i < s[pos] - '0'), sta | (i > 0), dem + (i == cur && (i || sta)), pos + 1));
    }
 
    return res;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    cin >> n;
 
    int l = 1, r = 1e18;
    while (l <= r){
        int mid = (l + r) / 2;
        s = to_string(mid);
        m = s.size();
 
        bool flag = true;
        for (int i = 0; i <= 9; ++ i){
            cur = i;
            memset(f, -1, sizeof(f));
            if (dp(0, 0, 0, 0) > n){
                flag = false;
                break;
            }
        }
 
        if (flag) l = mid + 1;
        else r = mid - 1;
    }
 
    cout << r;
}
/**
aybabtu
**/