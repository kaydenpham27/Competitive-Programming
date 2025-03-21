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
     int n, m;
     cin >> n >> m;
     multiset<int>ms;
     for(int i = 1; i <= n; i ++){
         int k;
         cin >> k;
         ms.insert(k);
     }
     while(m --){
        int k;
        cin >> k;
        auto j = ms.upper_bound(k);
        if(j == ms.begin()){
            cout << -1 << "\n";
        }
        else{
            if(*j > k || j == ms.end()) j --;
            cout << *j << "\n";
            ms.erase(j);
        }
     }
}