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
     int n, x;
     cin >> n >> x;
     map<int, int>kt;
     for(int i = 1; i <= n; i ++){
        cin >> a[i];
        kt[a[i]] ++;
     }
     for(int i = 1; i <= n; i ++){
        if(x - a[i] == a[i]){
            if(kt[a[i]] >= 2){
                    int cnt = 0;
                for(int j = 1; j <= n; j ++){
                    if(a[j] == a[i]){
                        cout << j << " ";
                        cnt ++;
                        if(cnt == 2) return 0;
                    }
                }
            }
        }
        else{
            int cnt1 = 0, cnt2 = 0;
            if(kt[a[i]] > 0 && kt[x - a[i]] > 0){
                for(int j = 1; j <= n; j ++){
                    if(cnt1 == 0 && a[j] == a[i]){
                        cout << j << " ";
                        cnt1 ++;
                    }
                    if(cnt2 == 0 && a[j] == x - a[i]){
                        cout << j << " ";
                        cnt2 ++;
                    }
                    if(cnt1 == 1 && cnt2 == 1) return 0;
                }
            }
        }
     }
     cout << "IMPOSSIBLE";
}