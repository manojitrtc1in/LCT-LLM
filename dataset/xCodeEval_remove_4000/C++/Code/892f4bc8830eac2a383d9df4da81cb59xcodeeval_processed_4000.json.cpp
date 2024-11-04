



using namespace std;














typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e16 + 7;
const int maxn = 1e5 + 5;
const int logn = 51;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, q, col;
int g[maxn], wgh[maxn], deg[maxn], c[maxn],
	bel[maxn], qx[maxn], qy[maxn], qdir[maxn];
int par[maxn][logn];
bool vis[maxn];
ll b;
ll t[maxn], len[maxn];
ll st[maxn][logn];
map<int, int> mp;

inline void qwrite(ll x, ll y){
	int tmp[10], tp = 0;
	if(!x)
		putchar('0');
	for(; x; x /= 10)
		tmp[++tp] = x - x / 10 * 10;
	for(; tp; --tp)
		putchar(tmp[tp] + 48);
	putchar(' ');
	tp = 0;
	if(!y)
		putchar('0');
	for(; y; y /= 10)
		tmp[++tp] = y - y / 10 * 10;
	for(; tp; --tp)
		putchar(tmp[tp] + 48);
	putchar('\n');
	return;
}

class Arrow{
public:
	ll x0, y0, x1, y1;
	int	dir;
	void calcDir(){
		if(x0 > x1)
			dir = 0;
		else if(x0 < x1)
			dir = 1;
		else if(y0 > y1)
			dir = 2;
		else
			dir = 3;
		return;
	}
}a[maxn];

class Point{
public:
	int tp, id,
		x, y;
	Point(int _tp, int _id, int _x, int _y): tp(_tp), id(_id), x(_x), y(_y){}
};

class Event{
public:
	int id,
		t, l, r;
	Event(int _id, int _t, int _l, int _r): id(_id), t(_t), l(_l), r(_r){}
	bool operator < (const Event &e)const{
		return t < e.t;
	}
};

vector<Point> pnt[4];
vector<Event> all[4];

class SegmentTree{
private:
	int siz;
	int tag[maxn << 2];
	void pushDown(int u){
		if(~tag[u])
			tag[u << 1] = tag[u << 1 | 1] = tag[u];
		tag[u] = -1;
		return;
	}
public:
	int size(){return siz;}
	void init(){
		for(siz = 1; siz < b; siz <<= 1);
		FOR(i, 0, maxn << 2) tag[i] = n;
		return;
	}
	void update(int x, int l, int r, int s, int t, int k){
		if(s > t) swap(s, t);
		if(l >= s && r <= t){
			tag[x] = k;
			return;
		}
		int md = l + r >> 1;
		pushDown(x);
		if(s <= md) update(x << 1, l, md, s, t, k);
		if(t > md) update(x << 1 | 1, md + 1, r, s, t, k);
		return;
	}
	int query(int x, int l, int r, int y){
		if(l == r)
			return tag[x];
		int md = l + r >> 1;
		pushDown(x);
		if(y <= md)
			return query(x << 1, l, md, y);
		else
			return query(x << 1 | 1, md + 1, r, y);
	}
}seg;

inline bool cmpx(const Point &e, const Point &f){return (MP(e.x, e.tp) < MP(f.x, f.tp));}
inline bool cmpy(const Point &e, const Point &f){return (MP(e.y, e.tp) < MP(f.y, f.tp));}
inline bool cmp(const Point &e, const Event &f, int d){
	if(!d)
		return MP(e.x, e.tp) >= MP(f.t, 1);
	if(d == 1)
		return MP(e.x, -e.tp) <= MP(f.t, -1);
	if(d == 2)
		return MP(e.y, e.tp) >= MP(f.t, 1);
	return MP(e.y, -e.tp) <= MP(f.t, -1);
}

inline bool inRange(int x, int l, int r){
	return (x >= min(l, r) && x <= max(l, r));
}

inline int dis(int x, int y, int z, int d){


	if(z == n){
		if(!d)
			return x;
		else if(d == 1)
			return b - x;
		else if(d == 2)
			return y;
		else
			return b - y;
	}
	if(inRange(x, a[z].x0, a[z].x1) && inRange(y, a[z].y0, a[z].y1))
		return 0;
	if(d < 2){
		return min(abs(a[z].x0 - x), abs(a[z].x1 - x));
	}
	else{
		return min(abs(a[z].y0 - y), abs(a[z].y1 - y));
	}
}

void scan(int d){
	seg.init();
	for(int i = 0, j = 0; i < pnt[d].size(); ++i){
		for(; j < all[d].size() && cmp(pnt[d][i], all[d][j], d); ++j){
			seg.update(1, 0, seg.size() - 1, all[d][j].l, all[d][j].r, all[d][j].id);
		}
		Point e = pnt[d][i];
		if(!e.tp){
			if(d < 2)
				g[e.id] = seg.query(1, 0, seg.size() - 1, e.y);
			else
				g[e.id] = seg.query(1, 0, seg.size() - 1, e.x);
			if(g[e.id] != n)
				wgh[e.id] = abs(e.x - a[g[e.id]].x1) + abs(e.y - a[g[e.id]].y1);
			else
				wgh[e.id] = dis(e.x, e.y, n, d);
		}
		else{
			if(d < 2){
				bel[e.id] = seg.query(1, 0, seg.size() - 1, e.y);
			}
			else{
				bel[e.id] = seg.query(1, 0, seg.size() - 1, e.x);
			}
			t[e.id] -= dis(e.x, e.y, bel[e.id], d);
		}
	}
	return;
}


void calc(){
	sort(pnt[0].begin(), pnt[0].end(), cmpx);
	sort(pnt[1].begin(), pnt[1].end(), cmpx);
	reverse(pnt[1].begin(), pnt[1].end());
	sort(pnt[2].begin(), pnt[2].end(), cmpy);
	sort(pnt[3].begin(), pnt[3].end(), cmpy);
	reverse(pnt[3].begin(), pnt[3].end());
	FOR(i, 0, 4)
		scan(i);
	return;
}

void calcSt(){
	FOR(i, 0, n)
		if(g[i] == n){
			par[i][0] = -1;
			st[i][0] = 0;
		}
		else{
			par[i][0] = g[i];
			st[i][0] = wgh[i];
		}
	FOR(i, 1, logn) FOR(u, 0, n){
		if(~par[u][i - 1]){
			par[u][i] = par[par[u][i - 1]][i - 1];
			st[u][i] = st[par[u][i - 1]][i - 1] + st[u][i - 1];
		}
		else{
			par[u][i] = -1;
			st[u][i] = st[u][i - 1];
		}
		if(st[u][i] > INF)
			st[u][i] = INF;
	}
	return;
}

ll climb(int u, ll md){
	ll ret = 0;
	int bound = logn;
	for(int i = bound - 1; i >= 0; --i){
		if(~par[u][i] && (1ll << i) <= md){
			ret += st[u][i];
			u = par[u][i];
			md -= 1ll << i;
		}
	}
	return ret;
}

void getAns(int u, ll tt){
	if(g[u] == n){
		ll rx = a[u].x1 + dx[a[u].dir] * tt,
			ry = a[u].y1 + dy[a[u].dir] * tt;
		qwrite(min(b - 1, max(rx, 0ll)), min(b - 1, max(ry, 0ll)));
		return;
	}
	bool f = (par[u][logn - 1] == -1);
	ll rt = 0, d = 0;
	if(!f){
		int v = u;
		for(int i = logn - 1; i >= 0; --i){
			if(~par[v][i] && !deg[par[v][i]]){
				d += st[v][i];
				v = par[v][i];
			}
		}
		rt = 1e5 + 5;
		if(d + wgh[v] <= tt){
			tt -= wgh[v];
			tt -= d;
			u = par[v][0];
			tt %= len[c[u]];
		}
	}
	else{
		int r = u;
		for(int i = logn - 1; i >= 0; --i){
			if(~par[r][i]){
				rt += 1ll << i;
				d += st[r][i];
				r = par[r][i];
			}
		}
		if(d <= tt){
			tt -= d;
			ll rx = a[r].x1 + tt * dx[a[r].dir],
				ry = a[r].y1 + tt * dy[a[r].dir];
			qwrite(max(0ll, min(rx, b - 1)), max(0ll, min(ry, b - 1)));
			return;
		}
	}
	ll lb, rb;
	for(lb = -1, rb = rt; lb + 1 < rb;){
		ll md = lb + rb >> 1ll;
		if(climb(u, md) <= tt)
			lb = md;
		else
			rb = md;
	}
	

	for(int i = logn - 1; i >= 0; --i){
		if(~par[u][i] && (1ll << i) <= lb){
			tt -= st[u][i];
			u = par[u][i];
			lb -= 1ll << i;
		}
	}
	ll nt = dis(a[u].x1, a[u].y1, g[u], a[u].dir);
	if(tt <= nt){
		qwrite(a[u].x1 + dx[a[u].dir] * tt, a[u].y1 + dy[a[u].dir] * tt);
	}
	else{
		tt -= wgh[u];
		qwrite(a[g[u]].x1 + dx[a[g[u]].dir] * tt, a[g[u]].y1 + dy[a[g[u]].dir] * tt);
	}
	return;
}

void id0(){
	queue<int> q;
	memset(deg, 0, sizeof(deg));
	FOR(i, 0, n) ++deg[g[i]];
	REP(i, 0, n) if(!deg[i])
		q.PH(i);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == n)
			continue;
		--deg[g[u]];
		if(!deg[g[u]])
			q.PH(g[u]);
	}
	return;
}

void dfs(int u){
	vis[u] = 1;
	len[col] += wgh[u];
	c[u] = col;
	if(u != n && !vis[g[u]])
		dfs(g[u]);
	return;
}

int main(){
	scanf("%d%lld", &n, &b);
	++b;
	FOR(i, 0, n){
		scanf("%lld%lld%lld%lld", &a[i].x0, &a[i].y0, &a[i].x1, &a[i].y1);
		a[i].calcDir();
		pnt[a[i].dir].PB(Point(0, i, a[i].x1, a[i].y1));
		all[0].PB(Event(i, min(a[i].x0, a[i].x1), a[i].y0, a[i].y1));
		all[1].PB(Event(i, max(a[i].x0, a[i].x1), a[i].y0, a[i].y1));
		all[2].PB(Event(i, min(a[i].y0, a[i].y1), a[i].x0, a[i].x1));
		all[3].PB(Event(i, max(a[i].y0, a[i].y1), a[i].x0, a[i].x1));
	}
	sort(all[0].begin(), all[0].end());
	sort(all[1].begin(), all[1].end());
	reverse(all[1].begin(), all[1].end());
	sort(all[2].begin(), all[2].end());
	sort(all[3].begin(), all[3].end());
	reverse(all[3].begin(), all[3].end());
	calc();
	scanf("%d", &q);
	FOR(i, 0, 4)
		pnt[i].clear();
	FOR(i, 0, q){
		char c;
		scanf("%d%d%*c%c%lld", qx+i, qy+i, &c, t+i);
		if(c == 'L') qdir[i] = 0;
		else if(c == 'R') qdir[i] = 1;
		else if(c == 'D') qdir[i] = 2;
		else if(c == 'U') qdir[i] = 3;
		pnt[qdir[i]].PB(Point(1, i, qx[i], qy[i]));
	}
	calc();
	calcSt();
	id0();
	FOR(i, 0, n) if(deg[i] && !vis[i])
		dfs(i),
		col++;
	FOR(i, 0, q){
		int arr = bel[i];
		if(arr == n || t[i] <= 0){
			t[i] += dis(qx[i], qy[i], bel[i], qdir[i]);
			ll rx = qx[i] + dx[qdir[i]] * t[i],
				ry = qy[i] + dy[qdir[i]] * t[i];
			qwrite(max(0ll, min(rx, 1ll * b - 1)), max(0ll, min(ry, 1ll * b - 1)));
			continue;
		}
		ll nx = qx[i], ny = qy[i];
		if(dis(qx[i], qy[i], bel[i], qdir[i])){
			if(!qdir[i])
				nx = max(a[arr].x0, a[arr].x1);
			else if(qdir[i] == 1)
				nx = min(a[arr].x0, a[arr].x1);
			else if(qdir[i] == 2)
				ny = max(a[arr].y0, a[arr].y1);
			else
				ny = min(a[arr].y0, a[arr].y1);
		}
		ll nt = abs(nx - a[arr].x1) + abs(ny - a[arr].y1);
		if(t[i] <= nt){
			ll rx = a[arr].x1 + dx[a[arr].dir] * (t[i] - nt),
				ry = a[arr].y1 + dy[a[arr].dir] * (t[i] - nt);
			qwrite(max(0ll, min(rx, b - 1)), max(0ll, min(ry, b - 1)));
		}
		else{
			t[i] -= nt;
			getAns(arr, t[i]);
		}
	}
	return 0;
}

