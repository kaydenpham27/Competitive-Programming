#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 1e6 + 5;
const int mod = 1e9 + 7;
 
int n, z;
 
int exp(int a, int x){
    int res = 1;
    for (; x; x >>= 1){
        if (x & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
 
int cal(int l, int r){
    return (r + l) * (r - l + 1 + mod) % mod * z % mod;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
 
    z = exp(2, mod - 2);
 
    int i = 1, res = 0;
    while (i <= n){
        int l = i, r = n;
        while (l <= r){
            int mid = (l + r) / 2;
            if (n / i != n / mid) r = mid - 1;
            else l = mid + 1;
        }
 
        res = (res + cal(i % mod, r % mod) * ((n / i) % mod) % mod) % mod;
        i = l;
    }
 
    cout << res;
}