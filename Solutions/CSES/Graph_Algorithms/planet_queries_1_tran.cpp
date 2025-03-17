#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 4e5 + 5;
 
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
 
int n, q, a[O], f[62][O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i){
        cin >> f[0][i];
    }
 
    int lim = 32;
    //for (int i = 1; i <= n; ++ i) cin >> a[i];
 
    for (int i = 1; i < lim; ++ i){
        for (int j = 1; j <= n; ++ j){
            f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }
 
    for (int i = 1; i <= q; ++ i){
        int u, k; cin >> u >> k;
        for (int j = lim - 1; j >= 0; -- j){
            if (k >> j & 1) u = f[j][u];
        }
 
        cout << u << "\n";
    }
}
/**
9 1
9 9 8 2 4 4 3 5 3
 
 
**/