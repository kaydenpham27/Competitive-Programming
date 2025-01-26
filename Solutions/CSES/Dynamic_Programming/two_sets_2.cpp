#include <bits/stdc++.h>
#define int64_t long long
#define double long double
using namespace std;
using type = int64_t;
const long long mod = 1000000007, inf = 1e18;
const int base = 33;
const int N = 3e5 + 10;
const int LG = 20;
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
int64_t f[N], g[N];
int64_t Pow(int64_t x, int e)
{
    int64_t ans = 1;
    while(e){
        if(e & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        e >>= 1;
    }
    return ans;
}
void Solve()
{
    int n; cin >> n;
    int sum = (n + 1) * n/2;
    if(sum % 2 != 0){
        cout << 0;
        return;
    }
    sum /= 2;
    f[0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= sum; j ++){
            g[j] = f[j];
            if(j >= i){
                g[j] = (g[j] + f[j - i]) % mod;
            }
        }
        for(int j = 0; j <= sum; j ++){
            swap(g[j], f[j]);
        }
    }
    cout << f[sum] * Pow(2, mod - 2) % mod;
}
 
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
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