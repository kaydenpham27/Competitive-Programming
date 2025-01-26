#include <bits/stdc++.h>
#define int64_t long long
#define double long double
using namespace std;
using type = int64_t;
const long long mod = 1000000007, inf = 1e18;
const int base = 33;
const int N = 4e6 + 10;
const int LG = 20;
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
int n, X, w[N];
pair<int, int>f[N];
pair<int, int> Add(pair<int, int>p, int add)
{
    if(p.second < add) return make_pair(p.first + 1, X - add);
    return make_pair(p.first, p.second - add);
}
void Minimize(pair<int, int>&p, pair<int, int>q)
{
    if(q.first < p.first) p = q;
    else if(q.first == p.first){
        if(q.second > p.second){
            p.second = q.second;
        }
    }
}
void Solve()
{
    cin >> n >> X;
    for(int i = 1; i <= n; i ++) cin >> w[i];
    f[0] = {0, X};
    for(int mask = 1; mask < (1 << n); mask ++){
        f[mask] = {1e9, 1e9};
        for(int i = 0; i < n; i ++){
            if(mask >> i & 1){
                Minimize(f[mask], Add(f[mask - (1 << i)], w[i + 1]));
            }
        }
    }
    pair<int, int>ans = f[(1 << n) - 1];
    cout << ans.first + (ans.second != X);
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(fopen("guard.in", "r")){
        freopen("guard.in", "r", stdin);
        freopen("guard.out", "w", stdout);
    }
    if(fopen("A.inp", "r")){
        freopen("A.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    int tc = 1;
    //cin >> tc;
    while(tc --){
        Solve();
    }
}