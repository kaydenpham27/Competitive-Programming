#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e2 + 5;
const int O = 1e5 + 50;
const int mod = 1e9 + 7;
const int inf = 1e9;
 
int n, x, h[N], s[N], k[N], f[O];
 
void Maximize(int &x, int y){
    if (x < y) x = y;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++ i) cin >> h[i];
    for (int i = 1; i <= n; ++ i) cin >> s[i];
    for (int i = 1; i <= n; ++ i) cin >> k[i];
 
    f[0] = 0;
    for (int i = 1; i <= n; ++ i){
        //k[i] = min(k[i], x / h[i]);
        for (int j = 1; j <= k[i]; j <<= 1){
            for (int z = x; z >= j * h[i]; -- z){
                Maximize(f[z], f[z - j * h[i]] + s[i] * j);
            }
            k[i] -= j;
        }
 
        if (k[i]){
            for (int j = x; j >= k[i] * h[i]; -- j){
                Maximize(f[j], f[j - k[i] * h[i]] + k[i] * s[i]);
            }
        }
    }
 
    cout << f[x];
 
}
/***
***/