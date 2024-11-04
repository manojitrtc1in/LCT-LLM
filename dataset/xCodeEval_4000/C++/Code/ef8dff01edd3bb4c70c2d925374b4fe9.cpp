#include <bits/stdc++.h>






using namespace std;



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



void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}


































#define fastio ios_base::sync_with_stdio(false)
#define read(x) scan("%d", &x);


















































int a[501];
int q[1001];
vi vec;
int main()
{
	ios_base::sync_with_stdio(false);
	

	int n, m;
	cin >> n >> m;
	vi u;
	for(int i = 0; i < n; i++) cin >> a[i];
	int x;
	bool found = false;
	for(int i = 0; i < m; i++)
	{
		cin >> x;
		q[i] = x;
		found = false;
		for(int j = 0; j < vec.size(); j++)
		{
			if(vec[j] == x)
			{
				found = true;
				break;
			}
		}
		if(!found)
		{
			vec.pb(x);
			u.pb(x);
		}
	}
	

	ll ans = 0;
	


	for(int i = 0; i < m; i++)
	{
		vi v;
		for(int j = 0; j < vec.size(); j++)
		{
			if(u[j] == q[i])
			{
				v.pb(q[i]);
				for(int k = 0; k < j; k++)
				{
					v.pb(u[k]);
				}
				for(int k = j + 1; k < vec.size(); k++)
				{
					v.pb(u[k]);
				}
				break;
			}
			else
			{
				ans += a[u[j]-1];
			}
		}
		for(int j = 0; j < vec.size(); j++)
		{
			u[j] = v[j];
		}
	}
	cout << ans;
	return 0;
}














