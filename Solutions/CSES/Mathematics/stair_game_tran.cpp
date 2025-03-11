#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 3e6 + 50;
const int inf = 1e9;
 
int n, x, a[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t --){
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> a[i];
 
        a[n + 1] = 0;
 
        int cur = 0;
        for (int i = n; i >= 2; -- i){
            a[i] ^= a[i + 1];
            cur ^= a[i];
        }
 
        cout << (cur ? "first" : "second") << "\n";
    }
}
/***
***/