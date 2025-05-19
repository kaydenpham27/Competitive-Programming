#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 3e3 + 50;
const int inf = 1e9;
 
int n;
bitset <3000> a[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            char c; cin >> c;
            if (c == '1') a[i].set(j);
        }
    }
 
    long long res = 0;
    for (int i = 0; i < n - 1; ++ i){
        for (int j = i + 1; j < n; ++ j){
            int cnt = (a[i] & a[j]).count();
            res += 1ll * (cnt - 1) * cnt / 2;
        }
    }
 
    cout << res;
}
/***
***/