#include <bits/stdc++.h>
#define ll long long
#define st first
#define sc second
#define pb push_back
 
using namespace std;
const int maxn = 2e6 + 69;
const int base = 131;
const ll mod = 1e9 + 7;
 
ll a[maxn], bits[maxn];
 
long long Pow(int n, int k)
{
    if(k == 0) return 1;
    if(k == 1) return n;
    ll x = Pow(n, k/2) % mod;
    if(k % 2 != 0) return (x * x % mod) * n % mod;
    else return x * x % mod;
}
 
ll minn = 1e9, sum = 0;
int n;
 
void Dequy(int k, int chon)
{
     if(k == n + 1){
        ll s = 0;
        for(int i = 1; i <= n; i ++){
            if(bits[i] == 1){
                s += a[i];
            }
        }
        minn = min(minn, abs((sum - s) - s));
        return;
     }
     bits[k] = chon;
     Dequy(k + 1, 0);
     Dequy(k + 1, 1);
 
}
 
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        sum = sum + a[i];
    }
    Dequy(0, 0);
    cout << minn;
}