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
 
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        long long x, y;
        cin >> x >> y;
        if(x > y){
            if(x % 2 == 0){
                cout << x * x - y + 1;
            }
            else{
                 cout << x * x - (2*x - 2) + y - 1;
            }
        }
        else{
            if(y % 2 == 0){
                cout << y * y - (2*y - 2) + x - 1;
            }
            else{
                cout << y * y - x + 1;
            }
        }
        cout << "\n";
    }
 
}