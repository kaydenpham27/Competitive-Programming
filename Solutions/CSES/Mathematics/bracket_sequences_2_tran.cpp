#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 3e6 + 5;
const int N = (1 << 20) + 5;
const int mod = 1e9 + 7; //998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
 
int n, k, a[O], f[O], p[O], rp[O];
 
void Add(int &x, int y){
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
    return;
}
 
int exp(int a, int x){
    int res = 1;
    for (; x; x >>= 1){
        if (x & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
 
int C(int k, int n){
    if (k > n) return 0;
    return p[n] * rp[n - k] % mod * rp[k] % mod;
}
 
int chiakeo(int k, int n){
    return C(n - 1, n + k - 1);
}
 
int Catalan(int x){
    return p[2 * x] * rp[x] % mod * rp[x + 1] % mod;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    p[0] = rp[0] = 1;
    for (int i = 1; i < O; ++ i){
        p[i] = p[i - 1] * i % mod;
        rp[i] = exp(p[i], mod - 2);
    }
 
    cin >> n;
    string s; cin >> s;
 
    if (n & 1) return cout << 0, 0;
 
    n /= 2;
 
    int sum = 0;
    for (char c : s){
        if (c == '(') sum += 1, n -= 1;
        if (c == ')') sum -= 1;
        if (sum < 0) return cout << 0, 0;
    }
 
    if (n < 0) return cout << 0, 0;
 
    int res = C(n, 2 * n + sum);
    Add(res, -C(n - 1, 2 * n + sum));
 
    cout << res;
}
/**
100
(()(((
357390580
**/