#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int maxn = 1e5 + 69;
 
ll a[maxn];
ll dp[maxn][101];
 
const ll mod = 1e9 + 7;
 
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    if(a[1] != 0){
        dp[1][a[1]] = 1;
    }
    else{
        for(int i = 1; i <= m; i ++){
            dp[1][i] = 1;
        }
    }
    for(int i = 2; i <= n; i ++){
        if(a[i] != 0){
            if(a[i] > 1){
                dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] - 1])%mod;
            }
            if(a[i] < 100){
                dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] + 1])%mod;
            }
            dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i]])%mod;
        }
        else{
            for(int j = 1; j <= m; j ++){
                if(j > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1])%mod;
                if(j < 100) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1])%mod;
                dp[i][j] = (dp[i][j] + dp[i - 1][j])%mod;
            }
        }
    }
    ll ans = 0;
    for(int j = 1; j <= m; j ++) ans = (ans + dp[n][j])%mod;
    cout << ans;
}