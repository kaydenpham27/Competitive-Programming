#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
const int inf = 2e18;
 
int n, k, a[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; ++ i) cin >> a[i];
 
    int res = 0;
    for (int i = 1; i < 1 << k; ++ i){
        int cur = 1;
        for (int j = 0; j < k; ++ j){
            if (i >> j & 1){
                if (cur >= inf / a[j]) cur = inf;
                else cur *= a[j];
            }
        }
 
        int sign = (__builtin_popcount(i) & 1) ? 1 : -1;
        res += sign * (n / cur);
    }
 
    cout << res;
}