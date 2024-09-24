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
 
int n, x, c[N];
int64_t f[N * 10];
void Solve()
{
    cin >> n >> x;
    for(int i = 1; i <= n; i ++) cin >> c[i];
    sort(c + 1, c + n + 1);
    f[0] = 1;
    for(int j = 1; j <= n; j ++){
        for(int i = 1; i <= x; i ++){
            if(i >= c[j]){
                f[i] = (f[i] + f[i - c[j]]) % mod;
            }
        }
    }
    cout << f[x];
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