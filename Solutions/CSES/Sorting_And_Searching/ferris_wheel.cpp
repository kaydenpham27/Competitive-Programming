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
 
int main()
{
     int n, x;
     cin >> n >> x;
     for(int i = 1; i <= n; i ++){
         cin >> a[i];
     }
     int ans = 0;
     sort(a + 1, a + n + 1);
     int pos1 = 1, pos2 = n;
     while(pos1 <= pos2){
        if(a[pos1] + a[pos2] <= x){
            ans ++;
            pos1 ++;
            pos2 --;
        }
        else{
            ans ++;
            pos2 --;
        }
     }
     cout << ans;
}