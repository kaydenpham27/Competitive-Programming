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
    if(n == 1){
        cout << 1;
        return 0;
    }
    if(n <= 3){
        cout << "NO SOLUTION";
    }
    else{
        int cur = n;
        for(int i = 2; i <= n; i +=2){
            a[i] = cur;
            cur --;
        }
 
        for(int i = 1; i <= n; i += 2){
            a[i] = cur;
            cur --;
        }
        for(int i = 1; i <= n; i ++){
            cout << a[i] << " ";
        }
    }
 
}