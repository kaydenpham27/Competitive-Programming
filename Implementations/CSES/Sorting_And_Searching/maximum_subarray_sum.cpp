#include <bits/stdc++.h>
#define ll long long
#define st first
#define sc second
#define pb push_back
 
using namespace std;
const int maxn = 2e6 + 69;
const int base = 131;
const ll mod = 1e9 + 7;
 
int a[maxn];
 
/// 11/300 (cses)
 
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
 
 
int main()
{
     int n;
     long long maxx = -1e9;
     long long sum = 0;
     cin >> n;
     for(int i = 1; i <= n; i ++){
         long long k;
         cin >> k;
         sum += k;
         sum = max(sum, k);
         maxx = max(maxx, sum);
     }
     cout << maxx;
}