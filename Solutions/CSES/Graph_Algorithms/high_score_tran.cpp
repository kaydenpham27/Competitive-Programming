#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 1e5 + 5;
const int inf = 1e18;
 
int n, m, d[O], U[O], V[O], W[O];
 
bool Minimize(int &x, int y){
    if (x < y){
        x = y;
        return true;
    }
    return false;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        cin >> U[i] >> V[i] >> W[i];
    }
 
    for (int i = 2; i <= n; ++ i) d[i] = -inf;
 
    for (int _ = 1; _  <= n + 1; ++ _){
        for (int i = 1; i <= m; ++ i){
            if (d[U[i]] != -inf){
                bool flag = Minimize(d[V[i]], d[U[i]] + W[i]);
                //cout << U[i] << " " << V[i] << " " << W[i] << " " << d[U[i]] << " " << d[V[i]] << endl;
                if (_ == n + 1 && flag){
                    d[V[i]] = inf;
                }
            }
        }
    }
 
    int res = d[n];
    for (int _ = 1; _  <= n; ++ _){
        for (int i = 1; i <= m; ++ i){
            if (d[U[i]] != -inf){
                Minimize(d[V[i]], d[U[i]] + W[i]);
            }
        }
    }
 
    if (res == d[n] && (res < inf)) return cout << res, 0;
    cout << -1;
}
/***
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4
***/