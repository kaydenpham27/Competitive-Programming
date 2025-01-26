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
 
int n, m;
int64_t f[N][2];
void Solve()
{
    int maxN = 1000000;
    // 0: Block width 2, 1: Block width 1
    f[1][1] = f[1][0] = 1;
    for(int i = 2; i <= maxN; i ++){
        f[i][1] = (4 * f[i - 1][1] + f[i - 1][0]) % mod;
        f[i][0] = (f[i - 1][1] + 2 * f[i - 1][0]) % mod;
    }
    int q;
    cin >> q;
    while(q --){
        cin >> n;
        cout << (f[n][0] + f[n][1]) % mod << "\n";
    }
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