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
 
ll dp[100010], g[100010];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll x;
    cin >> n >> x;
    for(int i = 1; i <= n; i ++){
        cin >> cus[i].arrive;
    }
    for(int i = 1; i <= n; i ++){
        cin >> cus[i].leave;
    }
    for(int i = 1; i <= n; i ++){
        for(int money = 1; money <= x; money ++){
            if(money >= cus[i].arrive){
                g[money] = max(g[money], dp[money - cus[i].arrive] + cus[i].leave);
            }
        }
        for(int money = 1; money <= x; money ++){
            dp[money] = g[money];
        }
    }
    cout << dp[x];
 
}