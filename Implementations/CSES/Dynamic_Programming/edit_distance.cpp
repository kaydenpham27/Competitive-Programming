#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int maxn = 1e5 + 69;
 
ll a[maxn];
ll dp[6005][6005];
 
const ll mod = 1e9 + 7;
 
int main()
{
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    int n = s1.size();
    int m = s2.size();
    s1 = " " + s1;
    s2 = " " + s2;
    for(int i = 0; i <= n + 2; i ++){
        for(int j = 0; j <= m + 2; j ++){
            dp[i][j] = 1e18;
        }
    }
    for(int j = 1; j <= m; j ++){
        dp[0][j] = j;
    }
    for(int i = 1; i <= n; i ++){
        dp[i][0] = i;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s1[i] != s2[j]));
 
        }
    }
    cout << dp[n][m];
}