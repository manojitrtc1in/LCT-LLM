#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef pair<ll, ll> llll;
typedef vector<llll> vllll;
typedef long double ld;
const int MOD = 1e9 + 7;
const ll INF = ll(1e18);

#define fi first
#define se second
#define pb push_back
#define debug(x) cerr << #x << " is " << x << endl;
#define gcd __gcd
#define forp(i, begin, end) for (__typeof(end) i = (begin); i < (end); i++)
#define form(i, begin, end) for (__typeof(end) i = (begin); i >= (end); i--)
#define scan scanf
#define print printf
#define mp make_pair

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}


































#define fastio ios_base::sync_with_stdio(false)
#define read(x) scan("%d", &x);




















map<ll, ll> ma;
ll ans[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	

	ll n;
	cin >> n;
	ll x;
	

	for(ll i = 0; i < ll(n)*ll(n); i++)
	{
		cin >> x;
		ma[-1*x]++;
		

	}
	map<ll, ll>::iterator it;
	for(int i = n - 1; i >= 0; i--)
	{
		for(it = ma.begin(); it != ma.end(); ++it)
		{
			x = it->first;
			if(it->second > 0) break;
		}
		

		ma[x]--;
		ans[i] = -1*x;
		for(int j = n - 1; j > i; j--)
		{
			ma[-1*gcd(ans[j], ans[i])] -= 2;
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}


