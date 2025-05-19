#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
 
using namespace std;
 
const int O = 1e3 + 5;
const int N = 4e5 + 5;
const int mod = 998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
 
int n, q, sum[O][O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            char c; cin >> c;
            int x = c == '*';
            sum[i][j] = x + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
 
    for (int i = 1; i <= q; ++ i){
        int l, r, x, y; cin >> l >> r >> x >> y;
        cout << sum[x][y] - sum[l - 1][y] - sum[x][r - 1] + sum[l - 1][r - 1] << "\n";
    }
}
/**
9 2
1 3 1 3 2 2 1 1 2
1
1 3
**/