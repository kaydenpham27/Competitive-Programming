#include <bits/stdc++.h>
#define ll long long
#define st first
#define sc second
#define pb push_back
 
using namespace std;
 
const int maxn = 2e5 + 69;
const int base = 131;
const ll mod = 1e9 + 7;
 
ll a[maxn];
 
int main()
{
  long long n;
  cin >> n;
  while(n != 1){
    cout << n << " ";
    if(n % 2 != 0) n = n*3 + 1;
    else n = n/2;
  }
  cout << 1;
}