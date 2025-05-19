#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 3e2 + 5;
 
int n, x;
unordered_map <int, int> cnt;
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    int sum = 0, flag = 0;
    vector <int> a, b, c;
    for (int i = 1; i <= n; ++ i){
        int z; cin >> z;
        if (z <= x) c.push_back(z);
        sum += z;
        flag |= (sum >= x);
    }
 
    if (!flag) return cout << 0, 0;
 
    sort(c.begin(), c.end());
 
    n = c.size();
    for (int i = 1; i <= n; ++ i){
        int z = c[i - 1];
        (i <= n / 2 ? a : b).push_back(z);
    }
 
    int A = a.size();
    int B = b.size();
 
    for (int i = 0; i < 1 << A; ++ i){
        int cur = 0;
 
        for (int j = 0; j < A; ++ j){
            if (i >> j & 1){
                cur += a[j];
                if (cur > x) goto bree;
            }
        }
 
        cnt[cur] += 1;
 
        bree:;
    }
 
    long long res = 0;
    for (int i = 0; i < 1 << B; ++ i){
        int cur = 0;
 
        for (int j = 0; j < B; ++ j){
            if (i >> j & 1){
                cur += b[j];
                if (cur > x) goto aree;
            }
        }
 
        res += cnt[x - cur];
 
        aree:;
    }
 
    cout << res;
}
/**
**/