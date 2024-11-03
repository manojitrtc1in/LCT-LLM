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
#include <bitset>
#include <climits>
#include <cassert>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define MOD 1000000007
#define INF 1e18
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    ll x = n;

    vector<ll> list;
    while (x % 2 == 0)
    {
        list.pb(2);
        x /= 2;
    }

    for (ll i = 3; i * i <= x; i += 2)
    {
        while (x % i == 0)
        {
            list.pb(i);
            x /= i;
        }
    }

    if (x > 1)
        list.pb(x);

    if (n == 1)
    {
        cout << 1 << endl;
        cout << 0 << endl;
    }
    else if (list.size() == 2)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << 1 << endl;
        if (list.size() == 1)
            cout << 0 << endl;
        else
        {
            ll ans = list[0] * list[1];
            cout << ans << endl;
        }
    }

    return 0;
}
