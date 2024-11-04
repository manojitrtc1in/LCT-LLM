#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <bitset>
#include <cassert>
#include <climits>
#include <ctime>
#include <deque>
#include <functional>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repa(i,a,n) for(int i=a;i<=n;i++)
#define repd(i,a,n) for(int i=a;i>=n;i--)
#define endl "\n"
#define debug(x) cout<<#x<<" "<<x<<endl
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl
#define debug4(w,x,y,z) cout<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl
#define debugp(x) cout<<#x<<" "<<x.ff<<" "<<x.ss<<endl
#define debugpa(x,n) for(int i=0;i<n;i++) cout<<x[i]<<" "; cout<<endl
#define debugpa1(x,n) for(int i=1;i<=n;i++) cout<<x[i]<<" "; cout<<endl
#define debugpa2(x,n,m) for(int i=1;i<=n;i++) {for(int j=1;j<=m;j++) cout<<x[i][j]<<" "; cout<<endl;}
#define debugv(x) for(auto it:x) cout<<it<<" "; cout<<endl
#define debugvp(x) for(auto it:x) cout<<it.ff<<" "<<it.ss<<endl
#define debugmp(x) for(auto it:x) cout<<it.ff<<" "<<it.ss.ff<<" "<<it.ss.ss<<endl
#define debugma(x,n) for(int i=0;i<n;i++) {for(int j=0;j<n;j++) cout<<x[i][j]<<" "; cout<<endl;}
#define debugma1(x,n) for(int i=1;i<=n;i++) {for(int j=1;j<=n;j++) cout<<x[i][j]<<" "; cout<<endl;}
#define debugma2(x,n,m) for(int i=1;i<=n;i++) {for(int j=1;j<=m;j++) cout<<x[i][j]<<" "; cout<<endl;}

const int mod = 998244353;
const int N = 100005;
const int M = 1000005;
const int LOGN = 20;
const int SQN = 320;
const int INT_INFINITY = 1e9;
const ll LL_INFINITY = 1e18;
const ld PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
const ld EPS = 1e-9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k, d;
        cin >> n >> k >> d;
        vi a(n);
        map<int, int> hm;
        vi occ(n + 1, 0);
        int id = 0;
        rep(i, n) {
            cin >> a[i];
            if (hm.find(a[i]) == hm.end()) {
                hm[a[i]] = id++;
            }
        }
        rep(i, n) {
            a[i] = hm[a[i]];
        }
        int ans = 0;
        rep(i, d) {
            occ[a[i]]++;
            if (occ[a[i]] == 1)
                ans++;
        }
        int ansl = ans;
        repa(i, d, n - 1) {
            int ans1 = ansl;
            occ[a[i]]++;
            if (occ[a[i]] == 1)
                ans1++;
            occ[a[i - d]]--;
            if (occ[a[i - d]] == 0)
                ans1--;
            ans = min(ans, ans1);
            ansl = ans1;
        }
        cout << ans << endl;
    }

    return 0;
}
