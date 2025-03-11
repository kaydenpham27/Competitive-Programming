#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 5e3 + 5;
const int inf = 1e9;
 
int n, cnt[26];
 
int Sum(){
    int res = 0;
    for (int i = 0; i < 26; ++ i) res += cnt[i];
    return res;
}
 
int Max(){
    int res = -inf;
    for (int i = 0; i < 26; ++ i) res = max(res, cnt[i]);
    return res;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s; n = s.size();
    for (char c : s) cnt[c - 'A'] += 1;
 
    if (Max() * 2 > Sum() + 1) return cout << -1, 0;
 
    int pre = -1;
    string res = "";
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < 26; ++ j){
            if (cnt[j] && j != pre){
                cnt[j] -= 1;
                int Mx = Max(), Sm = Sum();
                if (!(Mx * 2 > Sm + 1) || Mx == 1){
                    res += char('A' + j);
                    pre = j;
                    break;
                }
                else cnt[j] += 1;
            }
        }
    }
 
    cout << res;
}
/**
9 1
9 9 8 2 4 4 3 5 3
**/