#include <bits/stdc++.h>
#define ll long long
#define pb push_back
 
using namespace std;
 
const int maxn = 2e6 + 69;
 
ll a[maxn];
ll dp[5005][5005];
 
const ll mod = 1e9 + 7;

int main()
{
     int n;
     cin >> n;
     for(int i = 1; i <= n; i ++) cin >> a[i];
     vector<ll>ans;
     ans.pb(a[1]);
     for(int i = 2; i <= n; i ++){
        auto j = lower_bound(ans.begin(), ans.end(), a[i]);
        if(j == ans.end()) ans.pb(a[i]);
        else *j = a[i];
 
     }
     cout << ans.size();
}