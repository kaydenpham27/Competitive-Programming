#include <bits/stdc++.h>
#define ll long long
#define st first
#define sc second
#define pb push_back
 
using namespace std;
const int maxn = 2e6 + 69;
const int base = 131;
const ll mod = 1e9 + 7;
 
ll dp[maxn];
 
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
 
ll a[maxn];
 
int main()
{
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    dp[0] = 1;
    for(int i = 1; i<= x; i ++){
        for(int j = 1; j <= n; j ++){
            if(i >= a[j]){
                dp[i] = (dp[i] + dp[i - a[j]]) % mod;
            }
        }
    }
    if(dp[x] == 1e18){
        cout << -1 << "\n";
        return 0;
    }
    cout << dp[x];
 
}