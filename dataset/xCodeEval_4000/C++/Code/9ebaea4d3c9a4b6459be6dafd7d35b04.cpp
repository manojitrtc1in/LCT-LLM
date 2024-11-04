#include"bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> 

#include <ext/pb_ds/tree_policy.hpp>




using namespace __gnu_pbds;
using namespace std;
#define ff                first
#define ss                second
#define int               long long
#define pb                push_back
#define pf                push_front
#define ps(x,y)           fixed<<setprecision(y)<<x
#define w(x)              int x; cin>>x; while(x--)
#define FOR(i,a,b)        for(int i=(a);i<(b);i++)
#define ROF(i,a,b)        for(int i=(a);i>=(b);i--)
#define so(a,n)           sort(a,a+n)
#define rso(a,n)          sort(a,a+n),reverse(a,a+n)
#define all(v)            (v).begin(),(v).end()
#define ps(x,y)           fixed<<setprecision(y)<<x
const int                 maxn = 1e3 + 5;
const int                 modulo = 1000000007;
#define mod               1000000009;
const double              pi = 3.14159;
#define vv vector<vector<int>>
#define vi vector<int>
typedef pair<int, int>pp;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>multi_pbds;


typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update>pair_pbds;



















































int power(int x, unsigned int y)
{
    int res = 1;
    

    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res ;
}



































































































































































































int mceil(int a, int b)
{
    if (a % b == 0)return a / b;
    else return a / b + 1;
}

























































int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};



























































































































































































































































































































int dx[] = { -1, 0, 0, 1};
int dy[] = { 0, -1, 1, 0};




























































































































































struct Node {
    int A;
    int B;
    int C;
};
const int M = 200010;
set<int>s[M];
void solve()
{
    int n, m; cin >> n >> m;
    set<int>s1;
    map<int, int>mp;
    FOR(i, 0, m)
    {
        int x, y; cin >> x >> y;
        s[x].insert(y);
        s[y].insert(x);
        int p = min(x, y);
        s1.insert(p);
        mp[p]++;
    }
    int q; cin >> q;
    FOR(i, 0, q)
    {
        int x; cin >> x;
        if (x == 1)
        {
            int a, b; cin >> a >> b;
            s[a].insert(b);
            s[b].insert(a);
            int p = min(a, b);
            mp[p]++;
            s1.insert(p);
        }
        else if (x == 2)
        {
            int a, b; cin >> a >> b;
            s[a].erase(s[a].find(b));
            s[b].erase(s[b].find(a));
            int p = min(a, b);
            mp[p]--;
            int y = mp[p];
            if (y <= 0)mp.erase(p), s1.erase(p);
        }
        else
        {
            cout << n - s1.size() << '\n';
        }
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    

    

    

    solve();
}