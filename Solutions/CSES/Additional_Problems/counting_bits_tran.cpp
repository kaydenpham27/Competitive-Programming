#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 1e5 + 5;
 
int n, f[2][62][62];
 
int dp(int ok, int dem, int pos){
    if (pos < 0) return dem;
 
    int &res = f[ok][dem][pos];
    if (res != -1) return res;
 
    res = 0;
    int lim = ok ? 1 : (n >> pos & 1);
    for (int i = 0; i <= lim; ++ i){
        res += dp(ok | (i < (n >> pos & 1)), dem + i, pos - 1);
    }
 
    return res;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    memset(f, -1, sizeof(f));
    cout << dp(0, 0, 61);
}
/**
9 1
9 9 8 2 4 4 3 5 3
**/