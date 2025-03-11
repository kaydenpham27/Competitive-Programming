#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 3e3 + 5;
 
int n, k, a[O], f[2], sum[O], Sum[O], rsum[O], rSum[O];
bool Q = false;
 
struct Line{
    mutable int a, b, p;
    bool operator <(const Line &x) const{
        return Q ? p < x.p : a > x.a;
    }
};
 
struct DNMCVH : multiset <Line>{
    const int inf = 1e18;
 
    int div(int x, int y){
        return x / y - ((x ^ y) < 0 && x % y);
    }
 
    bool check(iterator x, iterator y){
        if (y == end()) return x -> p = inf, 0;
        if (x -> a == y -> a) x -> p = x -> b < y -> b ? inf : -inf;
        else x -> p = div(y -> b - x -> b, x -> a - y -> a);
        return x -> p >= y -> p;
    }
 
    void Add(int a, int b){
        auto z = insert({a, b, 0}), x = z ++, y = x;
        while (check(y, z)) z = erase(z);
        if (x != begin() && check(-- x, y)) check(x, erase(y));
        while ((y = x) != begin() && (-- x) -> p >= y -> p) check(x, erase(y));
    }
 
    int Get(int x){
        Q = 1;
        auto z = *lower_bound({0, 0, x});
        Q = 0;
        return z.a * x + z.b;
    }
};
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        Sum[i] = Sum[i - 1] + sum[i];
    }
 
    for (int i = n; i >= 1; -- i){
        rsum[i] = rsum[i + 1] + a[i];
        rSum[i] = rSum[i + 1] + rsum[i];
    }
 
    DNMCVH dp0, dp1, nxt0;
    dp0.Add(rsum[1], -rSum[2] - rsum[1]);
 
    /// dp0 -> dp1
    /// dp1 -> nxt0
    for (int i = 1; i <= k; ++ i){
        dp1.clear(); nxt0.clear();
        for (int j = i; j <= n - (k - i); ++ j){
            int x1 = dp0.Get(j) + rSum[j + 1];
            dp1.Add(-j, x1 + Sum[j - 1]);
            int x0 = dp1.Get(sum[j]) - Sum[j - 1] + sum[j] * j;
            nxt0.Add(rsum[j + 1], (-j - 1) * rsum[j + 1] + x0 - rSum[j + 2]);
 
            if (j <= 2 && i == 1){
                //cout << j << " " << x0 << " " << x1 << endl;
            }
 
            if (j == n) f[0] = x0, f[1] = x1;
        }
        dp0.swap(nxt0);
    }
 
    cout << min(f[0], f[1]);
 
}