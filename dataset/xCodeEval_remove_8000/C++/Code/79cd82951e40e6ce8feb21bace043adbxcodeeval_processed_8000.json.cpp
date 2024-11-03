






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





























































ll n, m, q;
ll a[100001];
ll SQRT = 350;
vector<ll> s[100001];
int id[100001];
bool found[400][100001];
int intersect[400][100001];
ll original[400];
ll add[400];
vector<ll> large;
ll k, el;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(found, false, sizeof(found));
	

	

	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
	{
		

		cin >> a[i];
	}
	for(int i = 1; i <= m; i++)
	{
		

		cin >> k;
		if(k > SQRT)
		{
			id[i] = int(large.size());
			large.pb(i);
		}
		for(int j = 0; j < k; j++)
		{
			

			cin >> el;
			s[i].pb(el);
			if(k > SQRT)
			{
				found[id[i]][el] = true;
				original[id[i]] += a[el];
			}
		}
		sort(s[i].begin(), s[i].end());
	}
	for(int i = 0; i < large.size(); i++)
	{
		for(int j = 1; j <= m; j++)
		{
			for (int a = 0; a < s[j].size(); a++)
			{
                

				if(found[i][s[j][a]])
				{
                    intersect[i][j]++;
				}
            }
		}
	}

	char mode; ll u, v, ans;
	for(int i = 0; i < q; i++)
	{
		

		cin >> mode;
		if(mode == '?')
		{
			ans = 0;
			

			cin >> u;
			if(s[u].size() > SQRT)
			{
				ans += original[id[u]];
			}
			else
			{
				for(int j = 0; j < s[u].size(); j++)
				{
					ans += a[s[u][j]];
				}
			}
			for(int j = 0; j < large.size(); j++)
			{
				ans += ll(add[j]) * ll(intersect[j][u]);
			}
			cout << ans << endl;
		}
		else
		{
			

			cin >> u >> v;
			if(s[u].size() > SQRT)
			{
				add[id[u]] += ll(v);
			}
			else
			{
				for(int j = 0; j < s[u].size(); j++)
				{
					a[s[u][j]] += ll(v);
				}
				for(int j = 0; j < large.size(); j++)
				{
					original[j] += ll(v) * ll(intersect[j][u]);
				}
			}
		}
	}
	return 0;
}
























