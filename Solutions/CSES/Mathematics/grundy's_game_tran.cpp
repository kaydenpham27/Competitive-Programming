#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 3e6 + 50;
const int inf = 1e9;
 
int n, m, f[O];
map <int, int> cnt;
 
int Mex(vector <int> &a){
    cnt.clear();
    for (int i : a) cnt[i] += 1;
 
    int res = 0;
    for (;; ++ res)
        if (!cnt.count(res)) return res;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i = 3; i <= 2000; ++ i){
        vector <int> d;
        for (int j = 1; 2 * j < i; ++ j){
            d.push_back((f[j] ^ f[i - j]));
        }
 
        sort(d.begin(), d.end());
        m = unique(d.begin(), d.end()) - d.begin();
        d.resize(m);
 
        f[i] = Mex(d);
    }
 
    int t; cin >> t;
    while (t --){
        cin >> n;
 
        int cur = (n >= 2000);
        if (n < 2000) cur = f[n];
 
        cout << (cur ? "first" : "second") << "\n";
    }
}
/***
***/