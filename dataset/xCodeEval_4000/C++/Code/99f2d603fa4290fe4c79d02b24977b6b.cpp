
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long unsigned long ull;
 
void solve() {
    ull n, sum = 0;
    cin >> n;
    auto cmp = [](ull a, ull b) { return a > b; };
    multiset<ull, decltype(cmp)> a, b;
    for(int i = 0; i < n; i++) {
        ull tmp;
        cin >> tmp, sum += tmp;
        a.insert(tmp);
    }
    b.insert(sum);
    while(a.size()) {
        ull cur = *b.begin();
        if(cur > *a.begin()) {
            b.erase(b.begin());
            b.insert(cur/2);
            b.insert((cur + 1)/2);
        } else if(cur < *a.begin()) {
            cout << "NO\n";
            return;
        }
        else {
            a.erase(a.begin());
            b.erase(b.begin());
        }
    }
    cout << "YES\n";
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int k = 1;
    cin >> k;
    while(k--) {
        solve();
    }
    return 0;
}