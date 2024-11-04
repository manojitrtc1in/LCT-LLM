

#include <bits/stdc++.h>

using namespace std;




#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 100 * 1000 + 13;
const int P = 350;

int n, m;
int p[N];
int t[N];
pt q[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n){
		scanf("%d", &p[i]);
		--p[i];
	}
	forn(i, m){
		scanf("%d%d%d", &t[i], &q[i].x, &q[i].y);
		--q[i].x;
		if (t[i] == 1) --q[i].y;
	}
	return true;
}

bool bad[N];
bool used[N];
vector<int> ord;

void ts(int v){
	used[v] = true;
	if (!used[p[v]]) ts(p[v]);
	ord.pb(v);
}

int pos[N];
int r[N];
bool ok[N];
int nxt[N];

void recalc(int l, int r){
	memset(used, 0, sizeof(used));
	memset(bad, 0, sizeof(bad));
	fore(i, l, r) if (t[i] == 1){
		used[q[i].x] = used[q[i].y] = true;
		bad[q[i].x] = bad[q[i].y] = true;
	}
	ord.clear();
	forn(i, n) if (bad[i] && !bad[p[i]]) ts(p[i]);
	forn(i, n) if (!used[i]) ts(i);
	reverse(all(ord));
	memset(pos, -1, sizeof(pos));
	forn(i, sz(ord)) pos[ord[i]] = i;
	memset(ok, 0, sizeof(ok));
	int tot = 0;
	memset(nxt, -1, sizeof(nxt));
	forn(i, sz(ord)) if (!bad[p[ord[i]]] && pos[p[ord[i]]] <= i){
		fore(j, pos[p[ord[i]]], i + 1){
			ok[ord[j]] = true;
			nxt[ord[j]] = ord[i];
			++tot;
		}
	}
	assert(tot <= n);
	for (int i = sz(ord) - 1; i >= 0; --i){
		if (bad[p[ord[i]]])
			nxt[ord[i]] = ord[i];
		else if (nxt[ord[i]] == -1 && nxt[p[ord[i]]] != -1)
			nxt[ord[i]] = nxt[p[ord[i]]];
	}
	
}

void solve() {
	forn(i, m){
		if (i % P == 0)
			recalc(i, min(m, i + P));
		if (t[i] == 1){
			swap(p[q[i].x], p[q[i].y]);
			continue;
		}
		int v = q[i].x, k = q[i].y;
		int len = 0;
		if (ok[v]){
			len = pos[nxt[v]] - pos[p[nxt[v]]] + 1;
		}
		else{
			int u = v;
			while (true){
				

				if (bad[u]){
					++len;
					u = p[u];
				}
				else{
					

					len += pos[nxt[u]] - pos[u] + 1;
					u = p[nxt[u]];
				}
				if (u == v) break;
				if (!bad[u] && !bad[v] && nxt[u] == nxt[v]){
					

					assert(pos[u] < pos[v]);
					len += pos[v] - pos[u];
					break;
				}
			}
		}
		

		k %= len;
		int u = v;
		while (k > 0){
			if (bad[u]){
				--k;
				u = p[u];
			}
			else if (k >= pos[nxt[u]] - pos[u] + 1){
				k -= pos[nxt[u]] - pos[u] + 1;
				u = p[nxt[u]];
			}
			else{
				u = ord[pos[u] + k];
				k = 0;
			}
		}
		printf("%d\n", u + 1);
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

#ifdef MULTITEST
	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();
#else
	while(read()) {	
#endif
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}