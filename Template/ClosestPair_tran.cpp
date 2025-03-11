#include <bits/stdc++.h>
#define int long long
#define double long double
 
using namespace std;
 
const double PI = 2 * acos(0);
 
const int O = 1e6 + 5;
const int mod = 998244353;
const double inf = 1e18;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
 
int n;
 
double sqr(double x){
    return x * x;
}
 
double d(pair <double, double> x, pair <double, double> y){
    return sqrt(sqr(x.first - y.first) + sqr(x.second - y.second));
}
 
pair <int, int> Closest_pair(vector <pair <double, double>> &a){
    int n = a.size() - 1;
    sort(a.begin(), a.end());
    set <pair <pair <double, double>, int>> s;
 
    int j = 0;
    double dist = inf;
    int resx = 0, resy = n;
    for (int i = 0; i <= n; ++ i){
        //cout << fixed << setprecision(2);
        //cout << "debug " << i << " " << a[i].first << " " << a[i].second << " " << dist << endl;
 
        while (j < i && a[j].first + dist <= a[i].first){
            auto z = s.find(make_pair(make_pair(a[j].second, a[j].first), j));
            if (z != s.end()) s.erase(z);
            j += 1;
        }
 
        auto cur = s.lower_bound(make_pair(make_pair(a[i].second - 1, 0), 0));
        auto l = s.upper_bound(make_pair(make_pair(a[i].second - dist - 1, 0), 0));
        auto r = s.upper_bound(make_pair(make_pair(a[i].second + dist + 1, 0), 0));
 
        /*if (i == 2){
            if (cur != s.end()) cout << "cur " << (*cur).second << endl;
            if (l != s.end()) cout << "l " << (*l).second << endl;
            if (r != s.end()) cout << "r " << (*r).second << endl;
        }*/
 
        for (auto z = cur;; -- z){
            if (l == s.end()) break;
            if (z == s.end()) continue;
            if ((*z).first.first + dist <= a[i].second) break;
            swap(a[i].first, a[i].second);
            if (dist >= d((*z).first, a[i])){
                dist = d((*z).first, a[i]);
                resx = (*z).second;
                resy = i;
            }
            swap(a[i].first, a[i].second);
            if (z == s.begin() || z == l) break;
        }
 
        for (auto z = cur;; ++ z){
            if (z == s.end()) break;
            if ((*z).first.first - dist >= a[i].second) break;
            swap(a[i].first, a[i].second);
            if (dist >= d((*z).first, a[i])){
                dist = d((*z).first, a[i]);
                resx = (*z).second;
                resy = i;
            }
            swap(a[i].first, a[i].second);
            if (z == r) break;
        }
 
        s.insert(make_pair(make_pair(a[i].second, a[i].first), i));
    }
 
    //cout << s.size() << endl;
 
    //cout << fixed << setprecision(2) << a[resx].first << " " << a[resx].second << " " << a[resy].first << " " << a[resy].second << "\n";
    return make_pair(resx, resy);//d(a[resx], a[resy]);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    vector <pair <double, double>> a;
    for (int i = 1; i <= n; ++ i){
        double x, y; cin >> x >> y;
        a.push_back({x, y});
    }
 
    auto [x, y] = Closest_pair(a);
 
    int res = sqr(a[x].first - a[y].first) + sqr(a[x].second - a[y].second);
    cout << res;
}