





			
using namespace std;
using pii = pair<int, int>;
using ppi = pair<pii, int>;
using INT = long long;
using VI = vector<int>;
inline void smax(int &u, int v) {if(u<v) u = v;}
inline void smin(int &u, int v) {if(u>v) u = v;}

const int NN = 200111;
vector<pii> adj[NN/2];
int n, m, Q;
int bg[NN/2], en[NN/2];
int ind;
char tot[2][NN];
INT ans[NN/2];
int col[NN/2];
int wh[NN];
int N;

struct query{
	int u, v, k, id;
	void input(int _id) {
		scanf("%d %d %d", &u, &v, &k);
		id = _id;
		k--;
	}
	bool operator < (const query tmp) const {
		return col[u] == col[tmp.u] ? col[v] < col[tmp.v] : col[u] < col[tmp.u];
	}
};

int nn, qf, qb, q[NN], sz[NN], fa[NN], vst[NN];
int mx[2][NN];

int find_root(int u){
	qf=qb=0;
	q[qb++]=u; fa[u]=0;
	while(qf<qb){
		u=q[qf++];
		for(auto p : adj[u]) {
			int v = p.x;
			if(v==fa[u] || vst[v]) continue;
			fa[v]=u;
			q[qb++]=v;
		}
	}
	nn=qb;
	for(int i=nn; i--; ){
		sz[u=q[i]]=1;
		int mx=0;
		for(auto p : adj[u]) {
			int v = p.x;
			if(v==fa[u] || vst[v]) continue;
			smax(mx, sz[v]);
			sz[u]+=sz[v];
		}
		if(mx*2<=nn && sz[u]*2>=nn) {
			return u;
		}
	}
}


void ser(int u, int c, int fa=0) {
	col[u] = c;
	for(auto p : adj[u]) {
		int v = p.x;
		if(vst[v]) continue;
		if(v == fa) continue;
		ser(v, c, u);
	}
}
int nod[2][NN];
int L[2][NN/2];
int R[2][NN/2];

struct AC_automaton {
	int used;

	struct node{
		int nxt[26], fail;
		void clear() {
			memset(nxt, -1, sizeof nxt);
			fail=-1; 
		}
	} mem[NN];
	VI adj[NN/2];
	
	int newnode() {
		int ans = ++used;
		mem[ans].clear();
		return ans;
	}

	void init(){
		used=-1;
		newnode();
	}

	void insert(char *s, int t, int id) {
		int now=0;
		for(int i=0; s[i]; i++) {
			if(mem[now].nxt[s[i]-'a'] == -1) mem[now].nxt[s[i]-'a'] = newnode();
			now = mem[now].nxt[s[i] - 'a'];
		}
		nod[id][t] = now;
		return ;
	}

	void build() {
	    qf = qb = 0;
		mem[0].fail = 0;
		for(int i=0; i<26; i++) {
			if(mem[0].nxt[i] == -1) {
				mem[0].nxt[i] = 0;
			}
			else {
				mem[mem[0].nxt[i]].fail=0;
				q[qb++] = mem[0].nxt[i];
			}
		}

		while(qb > qf) {
			int u = q[qf++];
			for(int i=0; i<26; i++) {
				if(mem[u].nxt[i] == -1) {
					mem[u].nxt[i] = mem[mem[u].fail].nxt[i];
				}
				else {
					mem[mem[u].nxt[i]].fail = mem[mem[u].fail].nxt[i];
					q[qb++] = mem[u].nxt[i];
				}
			}
		}
		for(int i=1; i<=used; i++) adj[mem[i].fail].pb(i);
	}

} ac[2];

void pre(int u, int f) {
	L[f][u] = ++ind;
	for(int v : ac[f].adj[u]) {
		pre(v, f);
	}
	R[f][u] = ind;
}

struct SegmentTree{
	INT sum[NN<<2];
	INT flag[NN<<2];
	
	
	
	
	
	inline void push_up(int u) {
		sum[u] = sum[ls] + sum[rs];
	}
	
	inline void up(int u, int d) {
		sum[u] += d;
		flag[u] += d;
	}
	
	inline void push_down(int u) {
		if(flag[u] == 0) return ;
		up(ls, flag[u]);
		up(rs, flag[u]);
		flag[u] = 0;
	}
	void update(int u, int st, int ed, int l, int r, int d) {
		if(st>=r or ed<=l) return ;
		if(st>=l and ed<=r) {
			up(u, d);
			return ;
		}
		push_down(u);
		update(ls, st, mid, l, r, d);
		update(rs, mid, ed, l, r, d);
		push_up(u);
	}
	
	INT calc(int u, int st, int ed, int l, int r) {
		if(st>=r or ed<=l) return 0;
		if(st>=l and ed<=r) return sum[u];
		push_down(u);
		return calc(ls, st, mid, l, r) + calc(rs, mid, ed, l, r);
	}
	
	
	
	
} st[2];

vector<ppi> save[NN];
vector<ppi> baoguan[NN];

inline int get_len(int u) {
	return en[wh[u]] - u;
}

namespace SA{
	int I[NN*2], H[NN*2], rk[NN*2], sa[NN*2];
	int head[NN*2], buf[NN*2], nxt[NN*2];
	pii pos[NN*2];

	void bucket_sort(int d, int n) {
		int E=0, m=max(n+10, 256);
		for (int i=0; i<=m; i++) head[i]=0;
		for (int i=0, u; i<n; i++) {
			if (d==1) u=pos[I[i]].x;
			else u=pos[I[i]].y;
			buf[++E]=I[i]; nxt[E]=head[u]; head[u]=E;
		}
		int st=m, ed=-1;
		if (d==1) st=0, ed=m+1;
		for (int i=st, K=0; i!=ed; i+=d) {
			for (int j=head[i]; j; j=nxt[j]) I[K++]=buf[j];
		}
	}

	void buildSA(char *s, int n) {
		for (int i=0; i<n; i++) rk[i]=s[i]; rk[n]=0;
		for (int i=0; i<20; i++) {
			for (int j=0; j<n; j++) pos[j]=pii(rk[j], rk[min(n, j+(1<<i))]), I[j]=j;
			bucket_sort(-1, n); bucket_sort(1, n);
			int cnt=0; pos[n]=pii(-1, -1); I[n]=n;
			for (int j=0; j<n; j++) {
				rk[I[j]]=cnt+1;
				cnt+=pos[I[j]]!=pos[I[j+1]];
			}
			if (cnt==n) break;
		}
		for (int i=0; i<n; i++) sa[rk[i]]=i;
		for (int i=0, h=0; i<n; i++) {
			if (rk[i]==1) continue;
			h=max(h-1, 0);
			for (int j=sa[rk[i]-1]; s[i+h]==s[j+h]; h++);
			H[rk[i]]=h;
		}
		for(int i=1; i<=n; i++) {
			if(wh[sa[i]] != -1) smin(H[i], get_len(sa[i]));
			if(i>1 and wh[sa[i-1]] != -1) smin(H[i], get_len(sa[i-1]));
		}
	}
		
};

struct Suffix_Tree{
	int fa[NN];
	int st[NN];
	int deep[NN];
	int flag[NN];
	int head[NN], to[NN], nxt[NN];
	int ss[NN], ee[NN];
	int E;
	int top;
	int nn;
	int n;
	VI id[NN];
	int re[NN];
	int L[NN], R[NN];
	int ind;
	int hou[NN][26];
	
	inline void up(int u, int p) {
		id[u].pb(p);
		re[p] = u;
	}
	
	int dfs(int u, char *tot) {
		L[u] = ++ind;
		R[u] = ind;
		if(head[u] == -1) {
			return id[u][0];
		}
		int ans = 0;
		for(int e = head[u]; ~e; e=nxt[e]) {
			int v = to[e];
			ans = dfs(v, tot);
			ss[e] = ans + deep[u];
			hou[u][tot[ss[e]]-'a'] = e;
			ee[e] = ans+deep[v]-1;


		}
		R[u] = ind;
		return ans;
	}
	
	void build(char *s, int n) {
		memset(head, -1, sizeof head);
		E=0;
		SA::buildSA(s, n);
		top = nn = 0;
		st[++top] = ++nn;
		for(int i=1; i<=n; i++) {
			int p = SA::sa[i];
			if(wh[p] == -1) continue;
			int d = SA::H[i];
			if(d == deep[st[top]] and deep[st[top]] == get_len(p)) {
				up(st[top], p);
				continue;
			}
			while(top > 1 and deep[st[top-1]] >= d) top--;
			int t = st[top];
			int now = ++nn;
			if(deep[t] <= d) {
				fa[now] = t;
			}
			else {
				top--;
				int u = st[top];
				int mid = ++nn;
				fa[t] = mid;
				fa[mid] = u;
				fa[now] = mid;
				deep[mid] = d;
				st[++top] = mid;
			}
			st[++top] = now;
			flag[now] = 1;
			deep[now] = get_len(p);
			up(now, p);
		}
		E=1;
		for(int i=2; i<=nn; i++) {


			nxt[E] = head[fa[i]]; to[E] = i; head[fa[i]] = E++;
		}
		dfs(1, s);
	}
	
} S[2];
int gen;

int root[NN/2];

struct Chair_Tree{
	
	
	static const int MM = NN * 60;
	INT sum[MM];
	INT flag[MM];
	int ls[MM], rs[MM];
	int cur;

	void push_up(int u, int st, int ed) {
		sum[u] = sum[ls[u]] + sum[rs[u]];
		sum[u] += 1ll * flag[u] * (ed - st);
	}

	int build(int st, int ed) {
		int u=cur++; flag[u]=0;
		if(ed == st+1) {
			sum[u] = 0;
			return u;
		}
		ls[u] = build(st, mid);
		rs[u] = build(mid, ed);
		push_up(u, st, ed);
		return u;
	}

	int update(int u, int st, int ed, int l, int r, int d) {
		smax(l, st); smin(r, ed);
		if(l >= r) return u;
		int ans=cur++;
		if(cur == MM) while(1);
		sum[ans] = sum[u];
		flag[ans] = flag[u];
		ls[ans] = ls[u];
		rs[ans] = rs[u];
		if(l == st and r == ed) {
			sum[ans] += 1ll*d * (ed-st);
			flag[ans] += d;
			return ans;
		}
		ls[ans] = update(ls[u], st, mid, l, r, d);
		rs[ans] = update(rs[u], mid, ed, l, r, d);
		push_up(ans, st, ed);
		return ans;
	}

	INT calc(int u, int st, int ed, int l, int r, INT f=0) {
		smax(l, st); smin(r, ed);
		if(l >= r) return 0;
		if(l == st and r == ed) {
			return sum[u] + 1ll*f * (ed - st);
		}
		return calc(ls[u], st, mid, l, r, f+flag[u]) + calc(rs[u], mid, ed, l, r, f+flag[u]);
	}
} C;

void dfs_st(int u) {
	for(auto p : S[0].id[u]) {
		int len = get_len(p);
		len = en[wh[p]] - bg[wh[p]] - len;
		int v = S[1].re[(en[wh[p]] - len)];
		int t = wh[p];
		root[t] = C.update(root[t], 1, N+1, S[1].L[v], S[1].R[v]+1, 1);
	}
	
	for(auto p : baoguan[u]) {
		int id = p.y;
		int t = p.x.y;
		int v = p.x.x;
		ans[id] += C.calc(root[t], 1, N+1, S[1].L[v], S[1].L[v]+1);
	}
	for(int e = S[0].head[u]; ~e; e=S[0].nxt[e]) {
		int v = S[0].to[e];
		dfs_st(v);
	}
	
	for(auto p : S[0].id[u]) {
		int len = get_len(p);
		len = en[wh[p]] - bg[wh[p]] - len;
		int v = S[1].re[(en[wh[p]] - len)];
		int t = wh[p];
		root[t] = C.update(root[t], 1, N+1, S[1].L[v], S[1].R[v]+1, -1);
	}
	
	
}

inline void up(query &q) {
	int u = q.u,  v = q.v, k = q.k, id = q.id;
	save[u].pb({{id, k}, 1});
	save[v].pb({{id, k}, 0});
}

inline ppi go(ppi now, int c, int f) {
	if(now.x.x == 0) return now;
	if(now.x.y == 0) {
		int u = now.x.y;
		int n = now.x.x;
		int nxt = S[f].hou[n][c];
		if(nxt == 0) return {{0, 0}, 0};
		int p = S[f].ss[nxt];
		if(p == S[f].ee[nxt]) {
			return ppi{{S[f].to[nxt], 0}, 0};
		}
		now.x.y = nxt;
		now.y   = p;


		return now;
	}
	int p = now.y + 1;
	if(c != tot[f][p]-'a') return {{0, 0}, 0};
	int nxt = now.x.y;
	if(p == S[f].ee[nxt]) return ppi{{S[f].to[nxt], 0}, 0};
	now.y++;
	return now;
}

void dfs(int u, int fa=0, int a = 0, int b = 0, ppi A={{1, 0}, 0}, ppi B={{1, 0}, 0}) {
	for(auto p : save[u]) {
		int id = p.x.x;
		int k = p.x.y;
		int f = p.y;
		ans[id] += st[f].calc(1, 1, N+1, L[f][nod[f][k]], R[f][nod[f][k]]+1);
	}
	save[u].clear();
	for(auto p : adj[u]) {
		int v = p.x;
		if(vst[v]) continue;
		if(v == fa) continue;
		int c = p.y;
		int na = ac[0].mem[a].nxt[c];
		int nb = ac[1].mem[b].nxt[c];
		st[0].update(1, 1, N+1, L[0][na], L[0][na]+1, 1);
		st[1].update(1, 1, N+1, L[1][nb], L[1][nb]+1, 1);
		
		ppi nA = go(A, c, 0);
		ppi nB = go(B, c, 1); 
	

		
		mx[0][v] = nA.x.x;
		mx[1][v] = nB.x.x;
		if(mx[0][v]==0) mx[0][v] = mx[0][u];
		if(mx[1][v]==0) mx[1][v] = mx[1][u];
		
		dfs(v, u, na, nb, nA, nB);
		st[0].update(1, 1, N+1, L[0][na], L[0][na]+1, -1);
		st[1].update(1, 1, N+1, L[1][nb], L[1][nb]+1, -1);
	}


}

void solve(int u, vector<query> &vec, int fa=0){
	u=find_root(u);
	gen = u;
	vst[u] = 1;
	int c = 0;
	for(auto p : adj[u]) {
		int v = p.x;
		if(vst[v]) continue;
		c++;
		ser(v, c);
	}
	col[u] = -1;
	sort(vec.begin(), vec.end());
	int now = 0;
	c = 0;
	for(auto p : adj[u]) {
		int v = p.x;
		if(vst[v]) continue;
		c++;
		while(now<sz(vec) and (col[vec[now].u] == c or col[vec[now].u] == -1)) {
			int u = vec[now].u, v = vec[now].v;
			if(col[u] != col[v] or col[u] == -1 or col[v] == -1) {
				up(vec[now]);
			}
			now++;
		}
	}
	c = now = 0;
	mx[0][u] = mx[1][u] = 1;
	dfs(u);
	for(auto p : adj[u]) {
		int v = p.x;
		if(vst[v]) continue;
		c++;
		while(now<sz(vec) and (col[vec[now].u] == c or col[vec[now].u] == -1)) {
			int u = vec[now].u, v = vec[now].v;
			if(col[u] == col[v]);
			else if(~col[u] and ~col[v]) {
				int u = vec[now].u;
				int v = vec[now].v;
				int k = vec[now].k;
				int id = vec[now].id;
				baoguan[mx[0][v]].pb({{mx[1][u], k}, id});
			}
			now++;
		}
	}
	c = now = 0;
	for(auto p : adj[u]) {
		int v = p.x;
		if(vst[v]) continue;
		c++;
		vector<query> tmp;
		while(now<sz(vec) and (col[vec[now].u] == c or col[vec[now].u] == -1)) {
			int u = vec[now].u, v = vec[now].v;
			if(col[u] == col[v]) tmp.pb(vec[now]);
			now++;
		}
		solve(v, tmp, u);
	}
	vec.clear();
	return ;
}

int solve() {
	cin >> n >> m >> Q;
	for(int i=1; i<n; i++) {
		int u, v; char s[2];
		scanf("%d %d %s", &u, &v, s);
		adj[u].pb({v, s[0]-'a'});
		adj[v].pb({u, s[0]-'a'});
	}
	int now = 0;
	ac[0].init(); ac[1].init();
	memset(wh, -1, sizeof wh);
	int LL=0;
	for(int i=0; i<m; i++) {
		scanf("%s", tot[0]+now);
		bg[i] = now;
		now += strlen(tot[0]+now);
		en[i] = now;
		LL += en[i] - bg[i];
		ac[0].insert(tot[0]+bg[i], i, 0);
		reverse(tot[0]+bg[i], tot[0]+en[i]);
		ac[1].insert(tot[0]+bg[i], i, 1);
		reverse(tot[0]+bg[i], tot[0]+en[i]);
		for(int j=bg[i]; j<en[i]; j++) wh[j] = i;
		tot[0][now++] = '$';
	}
	for(int i=0; i<now; i++) tot[1][i] = tot[0][i];
	for(int i=0; i<m; i++) {
		reverse(tot[1]+bg[i], tot[1]+en[i]);
	}
	
	N = LL*2+3;
	ac[0].build(); ac[1].build();
	pre(0, 0); ind = 0; pre(0, 1);
	
	S[0].build(tot[0], now);
	S[1].build(tot[1], now);
	vector<query> vec;
	for(int i=0; i<Q; i++) {
		query q;
		q.input(i);
		vec.pb(q);
	}
	solve(1, vec);
	root[0] = C.build(1, N+1);
	for(int i=1; i<m; i++) root[i] = root[0];
	dfs_st(1);
	cerr<<N<<' '<<C.cur<<endl;
	for(int i=0; i<Q; i++) {
		printf("%I64d\n", ans[i]);
	}
}

int main() {

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);


	solve();
}

  