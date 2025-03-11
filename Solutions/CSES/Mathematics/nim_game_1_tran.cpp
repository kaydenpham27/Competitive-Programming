#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 1e6 + 5;
 
int n, k, p[O];
bool f[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t --){
        cin >> n;
        int cur = 0;
        for (int i = 1; i <= n; ++ i){
            int x; cin >> x;
            cur ^= x;
        }
 
        cout << (cur ? "first" : "second") << "\n";
    }
}
/**
**/