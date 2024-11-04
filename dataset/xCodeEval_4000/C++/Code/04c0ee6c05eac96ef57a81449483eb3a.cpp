

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define f(a) for (int i = 0; i < a; ++i)
#define deb(a) cerr << a << endl;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;
typedef vector<str> vestr;
typedef vector<int> vei;
typedef vector<vector<int>> veve;


void solve() {
    int n, k;
    cin>>n>>k;
    cout<<"? "<<1<<endl;
    int t;
    cin>>t;
    int cur = 0;
    int len = 0;
    for(int i = 0; i < 1000; ++i) {
        cur+=i;
        cur%=n;
        cout<<"? "<<cur + 1<<endl;
        cin>>t;
        len = i;
        if(t>k) break;
    }
    while(1) {
        cout<<"? "<<cur+1<<endl;
        cin>>t;
        if(t<k) {
            cout<<"! "<<(cur+1)%n+1;
            return;
        }
        cur = (cur - 1 + n) % n;
    }
}

signed main() {
    

    





    int tc = 1;
    

    for (int t = 1; t <= tc; t++) {
        

        solve();
    }
}