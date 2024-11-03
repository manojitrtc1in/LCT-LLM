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






















ll d[200001];
ll h[200001];
ll treel[800001];
ll treer[800001];
ll range[100001][2];
ll l[200001];
ll r[200001];
int n, m;

void initialize(int node, int b, int e, int mode)
{
	if (b == e)
	{
		if(mode == 1)
		{
			treel[node] = b;
		}
		else
		{
			treer[node] = b;
		}
	}
	else
	{
		

		initialize(2 * node, b, (b + e) / 2, mode);
		initialize(2 * node + 1, (b + e) / 2 + 1, e, mode);
		if(mode == 1)
		{
			if (l[treel[2*node]] >= l[treel[2 * node + 1]])
			{
				treel[node] = treel[2 * node];
			}
			else
			{
				treel[node] = treel[2 * node + 1]; 
			}
		}
		else
		{
			if (r[treer[2*node]] >= r[treer[2 * node + 1]])
			{
				treer[node] = treer[2 * node];
			}
			else
			{
				treer[node] = treer[2 * node + 1]; 
			}
		}
	}
} 

int query(int node, int b, int e, int i, int j, int mode)
{
	int p1, p2;
   
	if (i > e || j < b)
	{
		return -1;
	}
   
	if (b >= i && e <= j)
	{
		if(mode == 1)
		{
			return treel[node];
		}
		else
		{
			return treer[node];
		}
	}
   
	p1 = query(2 * node, b, (b + e) / 2, i, j, mode);
	p2 = query(2 * node + 1, (b + e) / 2 + 1, e, i, j, mode);
   
	if (p1 == -1)
	{
		return p2;
	}
	if (p2 == -1)
	{
		return p1;
	}
	if(mode == 1)
	{
		if (l[p1] >= l[p2])
		{
			return p1;
		}
		return p2;
	}
	else
	{
		if (r[p1] >= r[p2])
		{
			return p1;
		}
		return p2;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	

	cin >> n >> m;
	l[0] = 0;
	r[0] = 0;
	d[0] = 0;
	h[0] = 0;
	for(int i = 1; i <= n; i++) 
	{
		cin >> d[i];
		d[n + i] = d[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> h[i];
		h[n + i] = h[i];
	}
	for(int i = 0; i < m; i++)
	{
		cin >> range[i][0] >> range[i][1];
	}
	for(int i = 1; i <= 2*n; i++)
	{
		l[i] = 2*h[i];
		r[i] = 2*h[i];
		r[i] += (r[i-1]-2*h[i-1]+d[i-1]);
		l[i] -= (2*h[i-1]-l[i-1]+d[i-1]);
		

	}
	
	initialize(1, 1, 2*n, 1);
	initialize(1, 1, 2*n, 2);
	
	int left, right;
	int idxl, idxr, idx2l, idx2l2, idx2r, idx2r2;
	for(int i = 0; i < m; i++)
	{
		if(range[i][0] <= range[i][1])
		{
			left = range[i][1] + 1;
			right = range[i][0] + n - 1;
		}
		else
		{
			left = range[i][1] + 1;
			right = range[i][0] - 1;
		}
		

		idxl = query(1, 1, 2*n, left, right, 1);
		idxr = query(1, 1, 2*n, left, right, 2);
		

		if(idxl != idxr)
		{
			cout << l[idxl] + r[idxr] << endl;
		}
		else
		{
			idx2l = query(1, 1, 2*n, left, idxl - 1, 1);
			idx2l2 = query(1, 1, 2*n, idxl + 1, right, 1);
			idx2r = query(1, 1, 2*n, left, idxr - 1, 2);
			idx2r2 = query(1, 1, 2*n, idxr + 1, right, 2);
			if(idx2l == -1) idx2l = idx2l2;
			if(idx2l2 == -1) idx2l2 = idx2l;
			if(idx2r == -1) idx2r = idx2r2;
			if(idx2r2 == -1) idx2r2 = idx2r;
			

			cout << max(l[idxl] + max(r[idx2r], r[idx2r2]), r[idxr] + max(l[idx2l], l[idx2l2])) << endl;
		}
	}
	return 0;
}

















