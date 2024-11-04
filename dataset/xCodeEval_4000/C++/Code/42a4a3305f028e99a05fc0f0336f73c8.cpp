
    
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
#define f(a) for(int i = 0; i<a; ++i)
#define deb(a) cerr<<a<<endl;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;
typedef vector<str> vestr;
typedef vector<int> vei;
typedef vector<vector<int>> veve;
    
    
void solve() {
    int n;
    cin>>n;
    vei a(n);
    f(n) cin>>a[i];
    vei ct(101);
    f(n) ct[a[i]]++;
    f(101) if(ct[i]) cout<<i<<' ';
    f(101) for(int j = 0; j<ct[i]-1; ++j) cout<<i<<' ';
    cout<<'\n';
}
    
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        

        solve();
    }
}