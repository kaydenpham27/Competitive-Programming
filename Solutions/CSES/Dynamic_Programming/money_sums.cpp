#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int maxn = 1e5 + 69;
 
ll a[maxn];
bool dp[101][100005];
 
const ll mod = 1e9 + 7;

int main()
{
     int n;
     cin >> n;
     for(int i = 1; i <= n; i ++){
        cin >> a[i];
        dp[i][0] = true;
     }
     for(int i = 1; i <= n; i ++){
        dp[i][a[i]] = 1;
        for(int j = 1; j <= 100000; j ++){
            dp[i][j] |= dp[i - 1][j];
            if(j >= a[i]){
                dp[i][j] |= dp[i - 1][j - a[i]];
            }
        }
     }
     vector<int>ans;
     for(int j = 1; j <= 100000; j ++){
        if(dp[n][j]) ans.push_back(j);
     }
     cout << ans.size() << "\n";
     for(auto j : ans) cout << j << " ";
}