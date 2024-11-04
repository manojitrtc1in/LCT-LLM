






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












void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}

ll gcd(ll a, ll b) {
	a = abs(a);
	b = abs(b);
	if(a == 0) return b;
	else if(b == 0) return a;
    return b ? gcd(b, a%b) : a;
}

















































llll tree[800001];
ll arr[200001];
ll k, n, a, b, q;

void modify(ll p,ll x, ll id = 1,ll l = 0,ll r = n)
{
	ll d1 = 0, d2 = 0;
	d1 = min(arr[p] + x, b) - min(arr[p], b);
	d2 = min(arr[p] + x, a) - min(arr[p], a);

	

	tree[id].fi += d1;
	tree[id].se += d2;
	
	if(r - l < 2){	

		arr[p] += x;
		return ;
	}
	int mid = (l + r)/2;
	if(p < mid)
		modify(p, x, id * 2, l, mid);
	else
		modify(p, x, id * 2 + 1, mid, r);
}

ll query(ll x,ll y,ll id = 1, ll l = 0,ll r = n, ll mode = 1)
{
	if(mode == 1) 

	{
		if(x >= r || l >= y)	return 0;
		if(x >= y) return 0;
		if(x <= l && r <= y)	return tree[id].fi;
		int mid = (l+r)/2;
		return query(x, y, id * 2, l, mid, 1) + query(x, y, id * 2 + 1, mid, r, 1);
	}
	else
	{
		if(x >= r || l >= y)	return 0;
		if(x >= y) return 0;
		if(x <= l && r <= y)	return tree[id].se;
		int mid = (l+r)/2;
		return query(x, y, id * 2, l, mid, 2) + query(x, y, id * 2 + 1, mid, r, 2);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	

	cin >> n >> k >> a >> b >> q;
	ll d, e, f;
	ll sum = 0;
	for(int i = 0; i < q; i++)
	{
		sum = 0;
		cin >> d;
		if(d == 1)
		{
			cin >> e >> f;
			e--;
			modify(e, f, 1, 0, n);
		}
		else
		{
			cin >> e;
			e--;
			sum += query(0, e, 1, 0, n, 1);
			sum += query(e + k, n, 1, 0, n, 2);
			cout << sum << endl;
		}
	}
	return 0;
}




