#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 1e6 + 5;
 
int n, k, p[O];
bool f[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; ++ i) cin >> p[i];
 
    sort(p + 1, p + k + 1);
 
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= k && p[j] <= i; ++ j){
            if (!f[i - p[j]]){
                f[i] = true;
                break;
            }
        }
    }
 
    for (int i = 1; i <= n; ++ i) cout << (f[i] ? 'W' : 'L');
}
/**
**/