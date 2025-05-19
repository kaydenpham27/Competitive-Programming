#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 2e4 + 50;
const int inf = 1e9;
 
int n, k, a[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < k; ++ j){
            char c; cin >> c;
            if (c == '1') a[i] |= (1 << j);
        }
    }
 
    int res = k + 1;
    for (int i = 1; i < n; ++ i){
        for (int j = i + 1; j <= n; ++ j){
            res = min(res, __builtin_popcount(a[i] ^ a[j]));
        }
    }
 
    cout << res;
}
/***
***/