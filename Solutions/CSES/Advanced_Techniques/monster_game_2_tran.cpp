#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, x, s[O], f[O];
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
} q;
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++ i) cin >> s[i];
    for (int i = 1; i <= n; ++ i) cin >> f[i];
 
    q.Add(x, 0);
    for (int i = 1; i <= n; ++ i){
        int X = q.Get(s[i]);
        if (i == n) return cout << X, 0;
        q.Add(f[i], X);
    }
 
}