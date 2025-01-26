#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int maxn = 1e5 + 69;
 
ll a[maxn];
ll dp[6005][6005];
 
const ll mod = 1e9 + 7;

int main()
{
     int a, b;
     cin >> a >> b;
     if(a > b) swap(a, b);
     for(int i = 1; i <= a; i ++) for(int j = 1; j <= b; j ++) dp[i][j] = 1e18;
     for(int i = 1; i <= 500; i ++) dp[i][i] = 0;
     for(int i = 1; i <= a; i ++){
        for(int j = 1; j <= b; j ++){
            for(int cut = 1; cut <= min(i, j); cut ++){
                dp[i][j] = min(dp[i][j], dp[i - cut][j] + dp[cut][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j - cut] + dp[i][cut] + 1);
            }
        }
     }
     cout << dp[a][b];
}