























































































































































































































































































using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<int> adjU[MAXN*MAXN];
int pairU[MAXN*MAXN], pairV[MAXN*MAXN], dist[MAXN*MAXN];
int m, n;


bool Zu[MAXN*MAXN], Zv[MAXN*MAXN];
vector<int> coverU, coverV;

void getreach(int u) {
	if (u == 0 || Zu[u]) return;
	Zu[u] = true;
	for (int i = 0; i < (int)adjU[u].size(); i++) {
		int v = adjU[u][i];
		if (v == pairU[u]) continue;
		Zv[v] = true;
		getreach(pairV[v]);
	}
}

void minimumcover() {
	memset(&Zu, false, sizeof Zu);
	memset(&Zv, false, sizeof Zv);
	for (int u = 1; u <= m; u++)
		if (pairU[u] == 0) getreach(u);
	coverU.clear(); coverV.clear();
	for (int u = 1; u <= m; u++)
		if (!Zu[u]) coverU.push_back(u);
	for (int v = 1; v <= n; v++)
		if (Zv[v]) coverV.push_back(v);
}

bool bfs() {
    queue<int> q;
    for (int u = 1; u <= m; u++) {
        if (pairU[u] == 0) {
            dist[u] = 0; q.push(u);
        }
        else dist[u] = INF;
    }
    dist[0] = INF;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] >= dist[0]) continue;
        for (int i = 0; i < (int)adjU[u].size(); i++) {
            int v = adjU[u][i];
            if (dist[pairV[v]] == INF) {
                dist[pairV[v]] = dist[u] + 1;
                q.push(pairV[v]);
            }
        }
    }
    return (dist[0] != INF);
}

bool dfs(int u) {
    if (u == 0) return true;
    for (int i = 0; i < (int)adjU[u].size(); i++) {
        int v = adjU[u][i];
        if (dist[pairV[v]] == dist[u]+1) {
            if (dfs(pairV[v])) {
                pairV[v] = u; pairU[u] = v;
                return true;
            }
        }
    }
    dist[u] = INF;
    return false;
}

int id0() {
    memset(&pairU, 0, sizeof pairU);
    memset(&pairV, 0, sizeof pairV);
    int result = 0;
    while (bfs()) {
        for (int u=1; u<=m; u++) {
            if (pairU[u]==0 && dfs(u))
                result++;
        }
    }
    return result;
}

int k, x[MAXN], y[MAXN];
int realx[MAXN];
int minx[MAXN], maxx[MAXN], miny[MAXN], maxy[MAXN];
bool sparkle[MAXN][MAXN];
int bit[MAXN][MAXN];
int nu[MAXN][MAXN], nv[MAXN][MAXN];
vector<ii> wireu[MAXN*MAXN], wirev[MAXN*MAXN];

int main() {
	scanf("%d", &k);
	map<int, int> reduce;
	FOR(i, k) {
		scanf("%d %d", &x[i], &y[i]);
		reduce[x[i]] = 0;
		reduce[y[i]] = 0;
	}
	int cnt = 0;
	for(auto &pp : reduce) {
		pp.se = ++cnt;
		realx[pp.se] = pp.fi;
	}
	mset(sparkle, false);
	mset(maxx, 0);
	mset(maxy, 0);
	mset(minx, INF);
	mset(miny, INF);
	FOR(i, k) {
		x[i] = reduce[x[i]];
		y[i] = reduce[y[i]];
		sparkle[x[i]][y[i]] = true;
		maxx[y[i]] = max(maxx[y[i]], x[i]);
		minx[y[i]] = min(minx[y[i]], x[i]);
		maxy[x[i]] = max(maxy[x[i]], y[i]);
		miny[x[i]] = min(miny[x[i]], y[i]);
	}
	mset(bit, 0);
	FOR1(i, cnt) {
		for(int j = minx[i]; j <= maxx[i]; j++) {
			bit[j][i] |= 2;
		}
		for(int j = miny[i]; j <= maxy[i]; j++) {
			bit[i][j] |= 1;
		}
	}
	m = 1;
	FOR1(i, cnt) FOR1(j, cnt) {
		if (bit[i][j] != 3) continue;
		if (sparkle[i][j]) {
			if (wireu[m].empty()) continue;
			m++;
		}
		else {
			wireu[m].pb({i, j});
			nu[i][j] = m;
		}
	}
	if (wireu[m].empty()) m--;
	n = 1;
	FOR1(j, cnt) FOR1(i, cnt) {
		if (bit[i][j] != 3) continue;
		if (sparkle[i][j]) {
			if (wirev[n].empty()) continue;
			n++;
		}
		else {
			wirev[n].pb({i, j});
			nv[i][j] = n;
		}
	}
	if (wirev[n].empty()) n--;
	FOR1(u, m) adjU[u].clear();
	FOR1(i, cnt) FOR1(j, cnt) {
		if (bit[i][j] == 3 && !sparkle[i][j]) {
			adjU[nu[i][j]].pb(nv[i][j]);
		}
	}
	debugf("initial wire config:\n");
	FOR1(i, cnt) {
		FOR1(j, cnt) {
			debugf("%d ", bit[j][cnt-i+1]);
		}
		debugf("\n");
	}
	id0();
	minimumcover();
	for(int u : coverU) {
		for(ii pp : wireu[u]) {
			int i = pp.fi;
			int j = pp.se;
			bit[i][j] ^= 1;
		}
	}

	for(int v : coverV) {
		for(ii pp : wirev[v]) {
			int i = pp.fi;
			int j = pp.se;
			bit[i][j] ^= 2;
		}
	}
	vector< pair<ii,ii> > wu, wv;
	FOR1(i, cnt) {
		FOR1(j, cnt) {
			if (bit[i][j] & 1) {
				int jt = j;
				int has3 = false;
				while(bit[i][jt] & 1) {
					if (bit[i][jt] == 3) has3 = true;
					jt++;
				}
				jt--;
				if (has3) wu.pb({{i, j}, {i, jt}});
				j = jt;
			}
		}
	}
	FOR1(j, cnt) {
		FOR1(i, cnt) {
			if (bit[i][j] & 2) {
				int it = i;
				int has3 = false;
				while(bit[it][j] & 2) {
					if (bit[it][j] == 3) has3 = true;
					it++;
				}
				it--;
				if (has3) wv.pb({{i, j}, {it, j}});
				i = it;
			}
		}
	}
	FOR1(i, cnt) {
		FOR1(j, cnt) {
			if ((bit[i][j] == 3) != sparkle[i][j]) assert(false);
		}
	}
	debugf("final wire config:\n");
	FOR1(i, cnt) {
		FOR1(j, cnt) {
			debugf("%d ", bit[j][cnt-i+1]);
		}
		debugf("\n");
	}
	printf("%u\n", wv.size());
	for(auto pp : wv) {
		printf("%d %d %d %d\n",
		realx[pp.fi.fi], realx[pp.fi.se],
		realx[pp.se.fi], realx[pp.se.se]);
	}
	printf("%u\n", wu.size());
	for(auto pp : wu) {
		printf("%d %d %d %d\n",
		realx[pp.fi.fi], realx[pp.fi.se],
		realx[pp.se.fi], realx[pp.se.se]);
	}

	return 0;
}