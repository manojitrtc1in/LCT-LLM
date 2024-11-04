



#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cmath>
#define ll long long
#define ld long double
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define pld pair <int, int>
#define pii pair <int, int>
 
using namespace std;
     
const
    int INF = 1e9 + 1;
const
    int N = 1e5 * 3;
const
    double EPS = 1 / 1e12;

ll a[N], pr[N], ans = 0;
ll n, t;

void q_sort(int l, int r);
 
int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
     
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> t;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if(i)
            pr[i] = pr[i - 1] + a[i];
        else
            pr[i] = a[i];
    }
    q_sort(0, n);

    cout << ans << "\n";
}

void q_sort(int l, int r)
{
    if(l >= r)
        return;
    int m = (l + r) / 2;
        q_sort(l, m);
        q_sort(m + 1, r);
    int j = m;
    for(int i = l; i <= m; i++){
        for(; j < r && pr[j + 1] - pr[i] < t; j++);
        

         

        ans += j - m;
        

    }
    sort(pr + l, pr + r + 1);
}
