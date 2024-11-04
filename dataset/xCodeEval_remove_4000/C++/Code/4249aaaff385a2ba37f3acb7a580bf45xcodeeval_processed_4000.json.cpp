


















using namespace std;
 









std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
 
template<typename Item, typename Sum, typename Lazy> struct SplayTree {
	struct Node { int par, ch[2]; Item item; Sum sum; Lazy lazy; Node(Item item, Sum sum, Lazy lazy) :par(-1), item(item), sum(sum), lazy(lazy) { ch[0] = ch[1] = -1; } };
	vector<Node> nodes;
 
	void reset() { nodes.clear(); }
	void apply(int x, Lazy lazy) { nodes[x].item += lazy; nodes[x].sum += lazy; nodes[x].lazy += lazy; }
	void push(int x) { REP(z, 2) if (nodes[x].ch[z] != -1) apply(nodes[x].ch[z], nodes[x].lazy); nodes[x].lazy = Lazy(); }
	void update(int x) { nodes[x].sum = Sum(); if (nodes[x].ch[0] != -1) nodes[x].sum += nodes[nodes[x].ch[0]].sum; nodes[x].sum += Sum(nodes[x].item); if (nodes[x].ch[1] != -1) nodes[x].sum += nodes[nodes[x].ch[1]].sum; }
	void connect(int x, int p, int z) { if (x != -1) nodes[x].par = p; if (p != -1) nodes[p].ch[z] = x; }
	int disconnect(int p, int z) { int x = nodes[p].ch[z]; nodes[p].ch[z] = -1; if (x != -1) nodes[x].par = -1; return x; }
	void rotate(int x) {
		int p = nodes[x].par, g = nodes[p].par, z = nodes[p].ch[0] == x ? 0 : 1, y = nodes[x].ch[1 - z]; push(p), push(x);
		connect(y, p, z), connect(p, x, 1 - z), connect(x, g, g == -1 ? -1 : nodes[g].ch[0] == p ? 0 : 1); update(p);
	}
	void splay(int x, int y = -1) { if (nodes[x].par == y) return; while (nodes[x].par != y) { int p = nodes[x].par, g = nodes[p].par; if (g != y) rotate((nodes[p].ch[0] == x) == (nodes[g].ch[0] == p) ? p : x); rotate(x); } update(x); }
	int first(int x) { if (x == -1) return x; splay(x); while (nodes[x].ch[0] != -1) x = nodes[x].ch[0]; splay(x); return x; }
	int last(int x) { if (x == -1) return x; splay(x); while (nodes[x].ch[1] != -1) x = nodes[x].ch[1]; splay(x); return x; }
 
	int add(Item item) { nodes.PB(Node(item, Sum(item), Lazy())); return SZ(nodes) - 1; };
	int join(int l, int r) { if (l == -1) return r;	l = last(l); push(l); connect(r, l, 1); update(l); return l; }
	void split(int x, int v, int& l, int& r) {
		if (x == -1) { l = r = -1; return; } else splay(x);
		l = r = -1;
		while (x != -1) { push(x); if (nodes[x].item.l() < v) l = x, x = nodes[x].ch[1]; else r = x, x = nodes[x].ch[0]; }
		if (l != -1) splay(l); if (r != -1) splay(r, l);
		if (l == -1) return;
		assert(nodes[l].par == -1 && nodes[l].ch[1] == r && (r == -1 || nodes[r].ch[0] == -1));
		push(l); disconnect(l, 1); update(l);
		if (nodes[l].item.r() < v) return;
		Item splitted = nodes[l].item.split(v);
		if (nodes[l].ch[0] != -1 && nodes[nodes[l].ch[0]].item.r() == nodes[l].item.r()) l = disconnect(l, 0);
		if (r == -1 || splitted.l() != nodes[r].item.l()) r = join(add(splitted), r);
		update(l);
	}
	void gather(int x, vector<Item>& ret) { push(x); if (nodes[x].ch[0] != -1) gather(nodes[x].ch[0], ret); ret.PB(nodes[x].item); if (nodes[x].ch[1] != -1) gather(nodes[x].ch[1], ret); }
	vector<Item> all(int x) { vector<Item> ret; if (x != -1) splay(x), gather(x, ret); return ret; }
};
 
const int MAXRECT = 200000;
const int INF = 1000000000;
struct Rect { int lt, rt, lx, rx; };
 
int nrect, sx;
Rect rect[MAXRECT];
 
struct Line {
	int ly, ry, lcost, slope;
	Line() {}
	Line(int ly, int ry, int lcost, int slope) :ly(ly), ry(ry), lcost(lcost), slope(ly == ry ? 0 : slope) {}
	int rcost() { return lcost + slope * (ry - ly); }
	int len() { return ry - ly; }
	void setly(int nly) { lcost += (nly - ly) * slope; ly = nly; if (ly == ry) slope = 0; }
	void setry(int nry) { ry = nry; if (ly == ry) slope = 0; }
	int l() { return ly; }
	int r() { return ry; }
	Line split(int y) {
		assert(ly < y && y <= ry);
		auto ret = Line(y, ry, lcost + (y - ly) * slope, slope);
		setry(y - 1);
		return ret;
	}
};
struct SumLine { SumLine() {} SumLine(Line line) {} };
SumLine& operator+=(SumLine& a, const SumLine& b) { return a; }
struct LazyLine {};
Line& operator+=(Line& a, const LazyLine& b) { return a; }
SumLine& operator+=(SumLine& a, const LazyLine& b) { return a; }
LazyLine& operator+=(LazyLine& a, const LazyLine& b) { return a; }
 
SplayTree<Line, SumLine, LazyLine> id7;
 
void printfunc(int lineroot,int tline) {
	if (lineroot == -1) {
		printf(" BLOCKED");
	} else {
		auto alllines = id7.all(lineroot);
		for (auto line : alllines) printf(" (%d,%d)..(%d,%d)", line.ly == -INF ? -INF : line.ly + tline, line.ly == -INF ? INF : line.lcost, line.ry == +INF ? +INF : line.ry + tline, line.ry == +INF ? INF : line.rcost());
	}
	puts("");
}
 
int t;
 
int id5(int node, int nry) {
	while(true) {
		node = id7.last(node);
		if (id7.nodes[node].item.ry <= nry) break;
		if (id7.nodes[node].item.ly < nry || id7.nodes[node].item.ly == nry && id7.nodes[node].ch[0] == -1) {
			id7.nodes[node].item.setry(nry);
			break;
		}
		node = id7.disconnect(node, 0);
		assert(node != -1);
	}
	return node;
}
int id0(int node, int nly) {
	node = id7.first(node);
	assert(nly <= id7.nodes[node].item.ly);
	if (nly == id7.nodes[node].item.ly) return node;
	if (id7.nodes[node].item.slope == -1 || id7.nodes[node].item.ly == id7.nodes[node].item.ry) {
		id7.nodes[node].item.slope = -1;
		id7.nodes[node].item.setly(nly);
		id7.update(node);
	} else {
		Line line(nly, id7.nodes[node].item.ly, id7.nodes[node].item.lcost + id7.nodes[node].item.ly - nly, -1);
		node = id7.join(id7.add(line), node);
	}
	return node;
}
int id8(int node, int nry) {
	node = id7.last(node);
	assert(nry >= id7.nodes[node].item.ry);
	if (nry == id7.nodes[node].item.ry) return node;
	if (id7.nodes[node].item.slope == +1 || id7.nodes[node].item.ly == id7.nodes[node].item.ry) {
		id7.nodes[node].item.slope = +1;
		id7.nodes[node].item.setry(nry);
		id7.update(node);
	} else {
		Line line(id7.nodes[node].item.ry, nry, id7.nodes[node].item.rcost(), +1);
		node = id7.join(node, id7.add(line));
	}
	return node;
}
int shiftfunc(int node, int dt) {
	if (dt == 0) return node;
	node = id7.first(node);
	int ply = id7.nodes[node].item.ly;
	if (ply != -INF) node = id0(node, ply - dt);
	node = id7.last(node);
	int pry = id7.nodes[node].item.ry;
	if (pry != +INF) node = id5(node, pry - dt);
	return node;
}
int mergefunc(int l, int r) {
	

	

	

	l = id7.last(l);
	r = id7.first(r);
	while (l != -1 && r != -1 && id7.nodes[l].item.rcost() > id7.nodes[r].item.lcost) {
		assert(id7.nodes[l].item.ry == id7.nodes[r].item.ly);
		if (id7.nodes[l].item.slope == -1 || id7.nodes[l].item.ly == id7.nodes[l].item.ry) {
			r = id0(r, id7.nodes[l].item.ly);
			l = id7.disconnect(l, 0);
		} else {
			assert(id7.nodes[l].item.slope == 1);
			if (id7.nodes[r].item.lcost + id7.nodes[l].item.len() <= id7.nodes[l].item.lcost) {
				r = id0(r, id7.nodes[l].item.ly);
				l = id7.disconnect(l, 0);
			} else {
				int y = id7.nodes[r].item.lcost - id7.nodes[l].item.lcost + id7.nodes[l].item.ly + id7.nodes[l].item.ry; assert(y % 2 == 0); y /= 2;
				assert(y > id7.nodes[l].item.ly && y < id7.nodes[l].item.ry);
				r = id0(r, y);
				id7.nodes[l].item.setry(y);
			}
		}
		l = id7.last(l);
		r = id7.first(r);
	}
	while (l != -1 && r != -1 && id7.nodes[l].item.rcost() < id7.nodes[r].item.lcost) {
		assert(id7.nodes[l].item.ry == id7.nodes[r].item.ly);
		if (id7.nodes[r].item.slope == +1 || id7.nodes[r].item.ly == id7.nodes[r].item.ry) {
			l = id8(l, id7.nodes[r].item.ry);
			r = id7.disconnect(r, 1);
		} else {
			assert(id7.nodes[r].item.slope == -1);
			if (id7.nodes[l].item.rcost() + id7.nodes[r].item.len() <= id7.nodes[r].item.rcost()) {
				l = id8(l, id7.nodes[r].item.ry);
				r = id7.disconnect(r, 1);
			} else {
				int y = id7.nodes[r].item.rcost() - id7.nodes[l].item.rcost() + id7.nodes[r].item.ly + id7.nodes[r].item.ry; assert(y % 2 == 0); y /= 2;
				assert(y > id7.nodes[r].item.ly && y < id7.nodes[r].item.ry);
				l = id8(l, y);
				id7.nodes[r].item.setly(y);
			}
		}
		l = id7.last(l);
		r = id7.first(r);
	}
	int ret = id7.join(l, r);
	

	return ret;
}
 
struct Region {
	int lx, rx, blockcnt, lineroot, tline;
	Region(int lx, int rx, int blockcnt, int lineroot, int tline) :lx(lx), rx(rx), blockcnt(blockcnt), lineroot(lineroot), tline(tline) {};
	int l() { return lx; }
	int r() { return rx; }
	void norm() { if (lineroot != -1) { lineroot = shiftfunc(lineroot, t - tline); tline = t; } }
	Region split(int x) {
		assert(lx < x && x <= rx); 
		norm();
		auto ret = Region(x, rx, blockcnt, -1, tline);
		rx = x - 1;
		if (lineroot != -1) id7.split(lineroot, x - t, lineroot, ret.lineroot);
		return ret;
	};
};
struct SumRegion {
	int id3;
	SumRegion() { id3 = INT_MAX; }
	SumRegion(Region region) { id3 = region.lineroot == -1 ? INT_MAX : region.blockcnt; }
};
SumRegion& operator+=(SumRegion& a, const SumRegion& b) { a.id3 = min(a.id3, b.id3); return a; }
struct LazyRegion {
	int id1;
	LazyRegion() { id1 = 0; }
	LazyRegion(int id1) :id1(id1) {}
};
Region& operator+=(Region& a, const LazyRegion& b) { a.blockcnt += b.id1; return a; }
SumRegion& operator+=(SumRegion& a, const LazyRegion& b) { if (a.id3 != INT_MAX) a.id3 += b.id1; return a; }
LazyRegion& operator+=(LazyRegion& a, const LazyRegion& b) { a.id1 += b.id1; return a; }
 
 
SplayTree<Region, SumRegion, LazyRegion> regiontree;
 
void print(int regionroot) {
	auto allregions = regiontree.all(regionroot);
	for (auto region : allregions) {
		

		printf("[%d..%d] = %d:", region.lx, region.rx, region.blockcnt); if (region.lineroot!=-1 && region.tline != t) printf(" (delay %d)", t - region.tline);
		printfunc(region.lineroot, region.tline);
	}
}
 
int id2(int node) {
	regiontree.splay(node);
	while (regiontree.nodes[node].sum.id3 == 0) {
		

		while (regiontree.nodes[node].item.blockcnt != 0 || regiontree.nodes[node].item.lineroot == -1) {
			

			if (regiontree.nodes[node].ch[0] != -1 && regiontree.nodes[regiontree.nodes[node].ch[0]].sum.id3 == 0) {
				node = regiontree.nodes[node].ch[0];
			} else {
				node = regiontree.nodes[node].ch[1];
			}
			assert(node != -1 && regiontree.nodes[node].sum.id3 == 0);
		}
		

		assert(regiontree.nodes[node].item.lineroot != -1);
		regiontree.splay(node);
		regiontree.nodes[node].item.lineroot = -1;
		regiontree.update(node);
	}
	return node;
}
 
int rgrow(int node, int x) {
	int l, r; regiontree.split(node, x + 1, l, r);
	l = regiontree.last(l);
	r = regiontree.first(r);
	

	

	

	if (l == -1 || regiontree.nodes[l].item.lineroot == -1) return regiontree.join(l, r);
	while (r != -1 && regiontree.nodes[r].item.lineroot == -1 && regiontree.nodes[r].item.blockcnt == 0) {
		

		assert(regiontree.nodes[l].item.rx + 1 == regiontree.nodes[r].item.lx);
		regiontree.nodes[l].item.rx = regiontree.nodes[r].item.rx;
		r = regiontree.disconnect(r, 1);
		r = regiontree.first(r);
	}
	if (r != -1 && regiontree.nodes[r].item.lineroot != -1) {
		assert(regiontree.nodes[l].item.rx + 1 == regiontree.nodes[r].item.lx);
		regiontree.nodes[l].item.rx = regiontree.nodes[r].item.lx;
		regiontree.nodes[l].item.norm();
		regiontree.nodes[l].item.lineroot = id8(regiontree.nodes[l].item.lineroot, regiontree.nodes[l].item.rx - t);
		regiontree.nodes[r].item.norm();
		regiontree.nodes[l].item.lineroot = mergefunc(regiontree.nodes[l].item.lineroot, regiontree.nodes[r].item.lineroot);
		regiontree.nodes[l].item.rx = regiontree.nodes[r].item.rx;
		r = regiontree.disconnect(r, 1);
	} else {
		regiontree.nodes[l].item.norm();
		regiontree.nodes[l].item.lineroot = id8(regiontree.nodes[l].item.lineroot, regiontree.nodes[l].item.rx - t);
	}
	int ret = regiontree.join(l, r);
	

	return ret;
}
 
int lgrow(int node, int x) {
	

	int l, r; regiontree.split(node, x, l, r);
	l = regiontree.last(l);
	r = regiontree.first(r);
	if (r == -1 || regiontree.nodes[r].item.lineroot == -1) return regiontree.join(l, r);
	while (l != -1 && regiontree.nodes[l].item.lineroot == -1 && regiontree.nodes[l].item.blockcnt == 0) {
		assert(regiontree.nodes[l].item.rx + 1 == regiontree.nodes[r].item.lx);
		regiontree.nodes[r].item.lx = regiontree.nodes[l].item.lx;
		l = regiontree.disconnect(l, 0);
		l = regiontree.last(l);
	}
	if (l != -1 && regiontree.nodes[l].item.lineroot != -1) {
		assert(regiontree.nodes[l].item.rx + 1 == regiontree.nodes[r].item.lx);
		regiontree.nodes[l].item.rx = regiontree.nodes[r].item.lx;
		regiontree.nodes[l].item.norm();
		regiontree.nodes[l].item.lineroot = id8(regiontree.nodes[l].item.lineroot, regiontree.nodes[l].item.rx - t);
		regiontree.nodes[r].item.norm();
		regiontree.nodes[l].item.lineroot = mergefunc(regiontree.nodes[l].item.lineroot, regiontree.nodes[r].item.lineroot);
		regiontree.nodes[l].item.rx = regiontree.nodes[r].item.rx;
		r = regiontree.disconnect(r, 1);
	} else {
		regiontree.nodes[r].item.norm();
		regiontree.nodes[r].item.lineroot = id0(regiontree.nodes[r].item.lineroot, regiontree.nodes[r].item.lx - t);
	}
	return regiontree.join(l, r);
}
 
int solve() {
	

 
	id7.reset();
	regiontree.reset();
	int linedn = id7.add(Line(-INF, sx, abs(-INF - sx), -1));
	int lineup = id7.add(Line(sx, +INF, 0, +1));
	int lineroot = id7.join(linedn, lineup);
	int regionroot = regiontree.add(Region(-INF, +INF, 0, lineroot, 0));
 
	vector<pair<int, int>> e;
	REP(i, nrect) e.PB(MP(2 * rect[i].lt + 1, i)), e.PB(MP(2 * rect[i].rt + 0, i));
	sort(e.begin(), e.end());
	

	id6(i, e) {
		t = e[i].first >> 1; int kind = e[i].first & 1, idx = e[i].second;
		if (kind == 0) { 

			int l, m, r;
			regiontree.split(regionroot, rect[idx].lx + 1, l, m);
			regiontree.split(m, rect[idx].rx, m, r);
			regiontree.apply(m, LazyRegion(-1));
			regionroot = regiontree.join(regiontree.join(l, m), r);
			regionroot = rgrow(regionroot, rect[idx].lx);
			regionroot = lgrow(regionroot, rect[idx].rx);
		}
		if (kind == 1) { 

			int l, m, r;
			regiontree.split(regionroot, rect[idx].lx + 1, l, m);
			

			

			regiontree.split(m, rect[idx].rx, m, r);
			

			

			m = id2(m);
			

			regiontree.apply(m, LazyRegion(1));
			regionroot = regiontree.join(regiontree.join(l, m), r);
		}
		

		

	}
	

 
	auto finalregions = regiontree.all(regionroot);
	assert(SZ(finalregions) == 1);
	auto finalregion = finalregions[0];
	finalregion.norm();
	assert(finalregion.lineroot != -1);
	auto finalfunc = id7.all(finalregion.lineroot);
	int ret = INT_MAX;
	for (auto func : finalfunc) ret = min(ret, min(func.lcost, func.rcost()));
	return ret;
}
 
void run() {
	scanf("%d", &nrect);
	scanf("%d", &sx);
	REP(i, nrect) scanf("%d%d%d%d", &rect[i].lt, &rect[i].rt, &rect[i].lx, &rect[i].rx), --rect[i].lt, ++rect[i].rt, --rect[i].lx, ++rect[i].rx;
	printf("%d\n", solve());
}
 
void stress() {
	int mxrect = 100, id4 = 100;
	REP(rep, 10000) {
		nrect = rnd() % mxrect + 1;
		int tdim = rnd() % id4 + 1;
		int xdim = rnd() % id4 + 1;
		sx = rnd() % (xdim + 1);
		REP(i, nrect) {
			rect[i].lt = rnd() % tdim; rect[i].rt = rnd() % tdim; if (rect[i].lt > rect[i].rt) swap(rect[i].lt, rect[i].rt); rect[i].rt += 2;
			rect[i].lx = rnd() % xdim; rect[i].rx = rnd() % xdim; if (rect[i].lx > rect[i].rx) swap(rect[i].lx, rect[i].rx); rect[i].rx += 2;
		}
		

		solve();
		printf(".");
	}
}
 
int main() {
	run();
	

	return 0;
}