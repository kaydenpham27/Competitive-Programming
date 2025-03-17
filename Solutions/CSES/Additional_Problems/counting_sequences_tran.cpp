#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 1e6 + 50;
const int mod = 1e9 + 7;
 
int n, k, p[O], rp[O];
 
void Add(int &x, int y){
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}
 
int exp(int a, int x){
    int res = 1;
    for (; x; x >>= 1, a = 1ll * a * a % mod) if (x & 1) res = 1ll * res * a % mod;
    return res;
}
 
int C(int k, int n){
    if (k > n) return 0;
    return 1ll * p[n] * rp[n - k] % mod * rp[k] % mod;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    p[0] = rp[0] = 1;
    for (int i = 1; i < O; ++ i){
        p[i] = 1ll * p[i - 1] * i % mod;
        rp[i] = exp(p[i], mod - 2);
    }
 
    //cout << C(2, 4) << endl;
 
    cin >> n >> k;
 
    int res = 0;
    for (int i = 0; i < k; ++ i){
        int sign = (i & 1 ? -1 : 1);
        Add(res, 1ll * sign * C(i, k) * exp(k - i, n) % mod);
    }
 
    cout << res;
}
/***
***/