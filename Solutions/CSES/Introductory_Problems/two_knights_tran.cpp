#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 1e6 + 50;
const int inf = 1e9;
 
int n, m, f[O];
vector <int> g[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i){
        int x = i * i;
        int res = (x - 1) * x / 2;
 
        res -= 4 * max(0ll, i - 1) * max(0ll, i - 2);
        cout << res << "\n";
    }
}