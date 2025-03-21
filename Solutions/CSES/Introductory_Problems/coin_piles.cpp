#include <bits/stdc++.h>
#define ll long long
#define st first
#define sc second
#define pb push_back
 
using namespace std;
const int maxn = 2e6 + 69;
const int base = 131;
const ll mod = 1e9 + 7;
 
ll a[maxn];
 
long long Pow(int n, int k)
{
    if(k == 0) return 1;
    if(k == 1) return n;
    ll x = Pow(n, k/2) % mod;
    if(k % 2 != 0) return (x * x % mod) * n % mod;
    else return x * x % mod;
}
 
int main()
{
    int t;
    cin >> t;
    while(t --){
        ll a, b;
        cin >> a >> b;
        if(min(a, b) * 2 < max(a, b)){
            cout << "NO" << "\n";
        }
        else{
            if((a + b) % 3 == 0 || a == 0 && b == 0){
                cout << "YES" << "\n";
            }
            else{
                cout << "NO" << "\n";
            }
        }
    }
}