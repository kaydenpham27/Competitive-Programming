#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 3e3 + 5;
 
int n, k, a[O], f[O], sum[O];
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
    for (int i = 1; i <= n; ++ i) cin >> a[i], sum[i] = sum[i - 1] + a[i];
 
    DNMCVH now, nxt;
    now.Add(0, 0);
 
    for (int i = 1; i <= k; ++ i){
        nxt.clear();
        for (int j = i; j <= n - (k - i); ++ j){
            int x = now.Get(sum[j]) + sum[j] * sum[j];
            if (i == k && j == n){
                cout << x;
                return 0;
            }
            nxt.Add(-2 * sum[j], x + sum[j] * sum[j]);
        }
        now.swap(nxt);
    }
 
}