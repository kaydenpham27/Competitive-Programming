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
int comp[(1 << 10) + 5][(1 << 10) + 5];
int64_t f[1004][(1 << 10) + 5];
void prepare(void)
{
    for(int mask1 = 0; mask1 < (1 << n); mask1 ++){
        for(int mask2 = 0; mask2 < (1 << n); mask2 ++){
            comp[mask1][mask2] = 1;
            vector<int>zeros;
            for(int i = 0; i < n; i ++){
                int sta1 = (mask1 >> i & 1);
                int sta2 = (mask2 >> i & 1);
                if(sta1 == 1 && sta2 == 1 ||
                   sta2 == 1 && sta1 == 1) comp[mask1][mask2] = 0;
                if(sta1 == 0 && sta2 == 0){
                    zeros.push_back(i);
                }
            }
            int l = 0;
            int m = zeros.size();
            if(m & 1) comp[mask1][mask2] = 0;
            for(int i = 0; i < m - 1; i ++){
                if(zeros[i + 1] - zeros[i] == 1) l ++;
                else{
                    if(l % 2 == 0) comp[mask1][mask2] = 0;
                    l = 0;
                }
            }
            if(comp[mask1][mask2] == 1){
            }
        }
    }
}
void Solve(void)
{
    cin >> n >> m;
    prepare();
    f[0][0] = 1;
    for(int j = 1; j <= m; j ++){
        for(int cur = 0; cur < (1 << n); cur ++){
            int revcur = (~cur) & ((1 << n) - 1);
            for(int prev = revcur; prev; prev = (prev - 1) & revcur){
                f[j][cur] = (f[j][cur] + f[j - 1][prev] * comp[prev][cur]) % mod;
            }
            f[j][cur] = (f[j][cur] + f[j - 1][0] * comp[0][cur]) % mod;
        }
    }
    cout << f[m][0];
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