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
 
int n, k;
int64_t a[N], f[5010][5010][2];
void Solve()
{
    cin >> n;
    int64_t sum = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        sum = (sum + a[i]);
    }
    for(int i = n; i >= 1; i --){
        for(int j = i; j <= n; j ++){
            f[i][j][0] = max(f[i + 1][j][1] + a[i], f[i][j - 1][1] + a[j]);
            f[i][j][1] = min(f[i + 1][j][0] - a[i], f[i][j - 1][0] - a[j]);
        }
    }
    cout << (f[1][n][0] + sum)/2;
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