


































































































































































































































































































































































































































































































































































































using namespace std;







typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> edge;
const int MAXN = 5010;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

void setmin (ll &a, ll b) {
	if (a > b) {
		a = b;
	}
}

int N;
int A[MAXN], B[MAXN];
ll W[MAXN];
int subsize[MAXN], depth[MAXN];
ll sumdist[MAXN];
vector<edge> adj[MAXN];
bool bel[MAXN];

int dfs1 (int x, int p, int dh, ll &sumd, ll d) {
	

	sumd += d;
	depth[x] = dh++;
	int &ref = subsize[x];
	ref = 1;
	for (edge e : adj[x]) {
		int t = e.first;
		if (t != p) {
			ref += dfs1(t, x, dh, sumd, d + e.second);	

		}
	}
	return ref;
}

void dfs2 (int n, int x, int p, ll d, bool cmp) {
	sumdist[x] = d;
	bel[x] = cmp;
	for (edge e : adj[x]) {
		int t = e.first;
		if (t != p) {
			dfs2(n, t, x, d + e.second * (n - 2 * subsize[t]), cmp);
		}
	}
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
	}
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> A[i] >> B[i] >> W[i];
		adj[A[i]].push_back(edge(B[i], W[i]));
		adj[B[i]].push_back(edge(A[i], W[i]));
	}
	ll ans = INF;
	for (int i = 1; i < N; i++) {
		

		int x = A[i], y = B[i];
		ll sx = 0, sy = 0;
		dfs1(x, y, 0, sx, 0);
		dfs1(y, x, 0, sy, 0);
		int sub[2] = {subsize[x], subsize[y]};
		dfs2(sub[0], x, y, sx, false);
		dfs2(sub[1], y, x, sy, true);
		assert(sub[0] + sub[1] == N);
		ll sum[2] = {0, 0};
		for (int j = 1; j <= N; j++) {
			sum[bel[j]] += sumdist[j];
		}
		sum[0] /= 2;
		sum[1] /= 2;
		ll smin[2] = {INF, INF};
		for (int j = 1; j <= N; j++) {
			setmin(smin[bel[j]], sumdist[j]);
		}
		setmin(ans, sum[0] + sum[1] + sub[0] * sub[1] * W[i] + smin[0] * sub[1] + smin[1] * sub[0]);
	}
	cout << ans << endl;
}