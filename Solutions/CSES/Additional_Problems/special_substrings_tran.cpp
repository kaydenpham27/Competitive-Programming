#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, ra[26], dem[26];
map <char, bool> dd;
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s; n = s.size();
    for (char c : s) dd[c] = 1;
 
    int lim = dd.size(), id = 0;
    for (auto [i, j] : dd){
        ra[i - 'a'] = id;
        id += 1;
    }
 
    vector <int> a(lim, 0);
    map <vector <int>, int> cnt; cnt.clear();
    cnt[a] += 1;
 
    long long res = 0;
    for (int i = 1; i <= n; ++ i){
        dem[ra[s[i - 1] - 'a']] += 1;
 
        int Min = *min_element(dem, dem + lim);
        for (int j = 0; j < lim; ++ j){
            a[j] = dem[j] - Min;
            //if (i == 3) cout << a[j] << " ";
        }
 
        res += cnt[a];
        cnt[a] += 1;
    }
 
    cout << res;
}
/**
9 1
9 9 8 2 4 4 3 5 3
**/