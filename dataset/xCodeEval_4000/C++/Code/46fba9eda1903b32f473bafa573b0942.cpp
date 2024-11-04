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












int main()
{
	ios_base::sync_with_stdio(false);
	

	ll a;
	cin >> a;
	ll n = ll(1e17);
	n *= 18;
	

	n %= a;
	ll k = n;
	

	for(int i = 0; i < 44; i++)
	{
		n = (n + k)%a;
	}
	

	if(n < 0)
	{
		n += a;
	}
	ll c = a - n; ll d = c + ll(1e18) - 1LL;
	cout << c << " " << d;
	return 0;
}









