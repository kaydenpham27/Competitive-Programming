#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 50 + 5;
const int base = (50 * 51) + 5;
const int mod = 1e9 + 7;
const int inf = 1e9;
 
int n;
 
void Add(int &x, int y){
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}
 
int exp(int a, int x){
    int res = 1;
    for (; x; x >>= 1){
        if (x & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
    }
    return res;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
 
    int num = 1, sum = 1, product = 1, mu = 1, half = 1, ha = 1, z = 1;
    for (int i = 1; i <= n; ++ i){
        int x, k; cin >> x >> k;
        z = 1ll * z * exp(x, k) % mod;
 
        num = 1ll * num * (k + 1) % mod;
        mu = 1ll * mu * (k + 1) % (2 * mod - 2);
 
        ha &= (k % 2 == 0);
        if (k % 2 == 0) half = 1ll * half * exp(x, k / 2) % mod;
 
        sum = 1ll * sum * (exp(x, k + 1) - 1 + mod % mod) % mod * exp(x - 1, mod - 2) % mod;
    }
 
    if (!ha) half = 1;
    product = 1ll * exp(z, mu / 2) * half % mod;
 
    cout << num << " " << sum << " " << product;
}
/// 3
/// ! 2 4 1 5 3