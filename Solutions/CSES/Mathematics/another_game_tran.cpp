#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n;
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t --){
        cin >> n;
        int flag = false;
        for (int i = 1; i <= n; ++ i){
            int x; cin >> x;
            flag |= (x & 1);
        }
 
        cout << (!flag ? "second" : "first") << "\n";
    }
}
/**
 * 6
**/