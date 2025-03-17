#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 50 + 5;
const int base = (50 * 51) + 5;
const int mod = 1e9 + 7;
const int inf = 1e9;
 
int n, k, d[O], f[O][O][6 * base + 5];
 
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
    for (int i = 1; i <= n; ++ i){
        int a, b; cin >> a >> b;
        cout << exp(a, b) << "\n";
    }
}
/// 3
/// ! 2 4 1 5 3