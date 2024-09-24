#include <bits/stdc++.h>
#define ll long long
#define st first
#define sc second
#define pb push_back
 
using namespace std;
const int maxn = 2e6 + 69;
const int base = 131;
const ll mod = 1e9 + 7;
 
long long Pow(int n, int k)
{
    if(k == 0) return 1;
    if(k == 1) return n;
    ll x = Pow(n, k/2) % mod;
    if(k % 2 != 0) return (x * x % mod) * n % mod;
    else return x * x % mod;
}
 
string s;
int ans = 0;
 
struct kien
{
    int arrive, leave;
};
kien cus[maxn];
 
bool lf(const kien &p, const kien &q)
{
    if(p.arrive != q.arrive) return p.arrive < q.arrive;
    else return p.leave < q.leave;
}
 
char a[1005][1005];
ll dp[1005][1005];
 
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> a[i][j];
        }
    }
    if(a[1][1] == '*') dp[1][1] = 0;
    else dp[1][1] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(i == 1 && j == 1) continue;
            if(a[i][j] == '*') continue;
            if(a[i - 1][j] != '*') dp[i][j] = (dp[i][j] + dp[i - 1][j])%mod;
            if(a[i][j - 1] != '*') dp[i][j] = (dp[i][j] + dp[i][j - 1])%mod;
        }
    }
    cout << dp[n][n];
 
}