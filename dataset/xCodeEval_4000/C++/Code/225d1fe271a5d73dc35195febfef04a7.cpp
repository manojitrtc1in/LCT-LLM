
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long unsigned long ull;

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int pos = 0, last = 0, cnt = 0;
    string ss = a;
    reverse(ss.begin(), ss.end());
    while(pos + 1 < n) {
        if(a[pos] == ')' && a[pos + 1] == ')' || a[pos] == '(') {
            pos += 2;
            cnt++;
            last = pos;
        } else {
            while(a[++pos] == '(');
            if(a[pos] == ')'){
                cnt++;
                last = ++pos;
            }
        }
    }
    cout << cnt << " " << n - last << "\n";
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