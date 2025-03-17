#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 3e6 + 50;
const int inf = 1e9;
 
int n, x;
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t --){
        cin >> n;
        int cur = 0;
        for (int i = 1; i <= n; ++ i){
            cin >> x;
            cur ^= (x % 4);
        }
 
        cout << (cur ? "first" : "second") << "\n";
    }
}
/***
4 3
2 7 8 9
35 27 17
***/