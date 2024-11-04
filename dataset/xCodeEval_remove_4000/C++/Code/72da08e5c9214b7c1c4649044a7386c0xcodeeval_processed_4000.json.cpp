



















using namespace std;
using namespace __gnu_pbds;

const int N = 1e5+7;
const int INF = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += INF; a %= INF; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;






int a, cyclic, b, c, from[N], detected, test, cur, d[N], incycle[N], n, m, vis[N], lvl[N], P[N][19], cn=1, pos, previous, counter, ans;
vector <pii> G[N];
vector <int> E[N], C[N], cycle;
pii p[N];
int ch[N], par[N], ID[N], IDC[N], cycleP[N];
int T[N<<2][2], lz[N<<2], CT[N<<2][2], Clz[N<<2];




void detect_cycle(int x, int y){
	from[x] = y;
	
	if(vis[x])	{detected = x; return; }
	vis[x] = 1;
	
	for(int i : E[x])
		if(i ^ y && !detected)
			detect_cycle(i, x);
}

void dfs(int x, int y){
	lvl[x] = lvl[y] + 1;
	P[x][0] = y;
	d[x] = 1;
	
	for(pii i : G[x])
		if(i.ff ^ y)
			dfs(i.ff, x), d[x] += d[i.ff];
}

void id0(){
	for(int j=1; j<=17; j++)
		for(int i=1; i<=n; i++)
			if(P[i][j-1])
				P[i][j] = P[P[i][j-1]][j-1];
}

int LCA(int x, int y){
	if(lvl[x] < lvl[y])	swap(x, y);
	
	for(int i=17; i>=0; i--)
		if(lvl[x]-(1<<i) >= lvl[y])
			x = P[x][i];
	
	if(x == y)	return x;
	
	for(int i=17; i>=0; i--)
		if(P[x][i] && P[x][i] != P[y][i])
			x = P[x][i], y = P[y][i];
	
	return P[x][0];
}

void id2(int x, int y){
	if(!par[cn])	par[cn] = x;
	
	ID[x] = ++pos;
	ch[x] = cn;
	
	int aa = 0, bb = -1;
	
	for(pii i : G[x])
		if(i.ff ^ y){
			if(umax(aa, d[i.ff]))
				bb = i.ff;
		}
	
	if(~bb)
		id2(bb, x);
	
	for(pii i : G[x])
		if(i.ff ^ y && i.ff ^ bb)
			++cn, id2(i.ff, x);
}

void form_cycle(int x, int y){
	if(vis[x])	return; vis[x] = 1;
	
	IDC[x] = ++counter;
	for(int i : C[x])
		if(i ^ y)
			form_cycle(i, x);
}

void form_tree(int l, int r, int v){
	if(l == r){
		T[v][0] = 1;
		return;
	}
	
	form_tree(l, mid(l, r), v<<1);
	form_tree(mid(l, r)+1, r, v<<1|1);
	
	T[v][0] = T[v<<1][0] + T[v<<1|1][0];
	T[v][1] = T[v<<1][1] + T[v<<1|1][1];
}

void id1(int l, int r, int v){
	if(l == r){
		CT[v][0] = 1;
		return;
	}
	
	id1(l, mid(l, r), v<<1);
	id1(mid(l, r)+1, r, v<<1|1);
	
	CT[v][0] = CT[v<<1][0] + CT[v<<1|1][0];
	CT[v][1] = CT[v<<1][1] + CT[v<<1|1][1];
}

void push(int l, int r, int v){
	if(!lz[v])	return;
	
	swap(T[v<<1][0], T[v<<1][1]);
	swap(T[v<<1|1][0], T[v<<1|1][1]);
	
	lz[v<<1] ^= lz[v];
	lz[v<<1|1] ^= lz[v];
	
	lz[v] = 0;
}

void upd(int x, int y, int l, int r, int v){
	if(y < l || r < x)
		return;
	
	if(x <= l && r <= y){
		swap(T[v][0], T[v][1]);
		lz[v] ^= 1;
		return;
	}
	
	push(l, r, v);
	
	upd(x, y, l, mid(l, r), v<<1);
	upd(x, y, mid(l, r)+1, r, v<<1|1);
	
	T[v][0] = T[v<<1][0] + T[v<<1|1][0];
	T[v][1] = T[v<<1][1] + T[v<<1|1][1];
}

pii get(int x, int y, int l, int r, int v){
	if(y < l || r < x)
		return mp(0, 0);
	
	if(x <= l && r <= y)
		return mp(T[v][0], T[v][1]);
	
	push(l, r, v);
	
	pii t1 = get(x, y, l, mid(l, r), v<<1);
	pii t2 = get(x, y, mid(l, r)+1, r, v<<1|1);
	
	return mp(t1.ff+t2.ff, t1.ss+t2.ss);
}

void pushC(int l, int r, int v){
	if(!Clz[v])	return;
	
	swap(CT[v<<1][0], CT[v<<1][1]);
	swap(CT[v<<1|1][0], CT[v<<1|1][1]);
	
	Clz[v<<1] ^= Clz[v];
	Clz[v<<1|1] ^= Clz[v];
	
	Clz[v] = 0;
}

void updC(int x, int y, int l, int r, int v){
	if(y < l || r < x)
		return;
	
	if(x <= l && r <= y){
		swap(CT[v][0], CT[v][1]);
		Clz[v] ^= 1;
		return;
	}
	
	pushC(l, r, v);
	
	updC(x, y, l, mid(l, r), v<<1);
	updC(x, y, mid(l, r)+1, r, v<<1|1);
	
	CT[v][0] = CT[v<<1][0] + CT[v<<1|1][0];
	CT[v][1] = CT[v<<1][1] + CT[v<<1|1][1];
}

pii getC(int x, int y, int l, int r, int v){
	if(y < l || r < x)
		return mp(0, 0);
	
	if(x <= l && r <= y)
		return mp(CT[v][0], CT[v][1]);
	
	pushC(l, r, v);
	
	pii t1 = getC(x, y, l, mid(l, r), v<<1);
	pii t2 = getC(x, y, mid(l, r)+1, r, v<<1|1);

	return mp(t1.ff+t2.ff, t1.ss+t2.ss);
}

int jump(int x, int y){
	for(int i=17; i>=0; i--)
		if(y-(1<<i) >= 0)
			x = P[x][i], y -= (1<<i);
	
	return x;
}

int main(){
	
		freopen("file.in", "r", stdin);
	
	
	scanf("%d%d", &n, &m);
	
	for(int i=1; i<=n; i++){
		scanf("%d%d", &a, &b);
		
		E[a].pb(b);
		E[b].pb(a);
		p[i] = mp(a, b);
	}
	
	detect_cycle(1, 0);
	
	cur = from[detected]; cycle.pb(detected);
	C[detected].pb(cur); C[cur].pb(detected);
	
	while(cur != detected)
		previous = cur, incycle[cur] = 1, cycle.pb(cur), cur = from[cur], C[previous].pb(cur), C[cur].pb(previous);
	incycle[cur] = 1;
	
	for(int i=1; i<=n; i++){
		a = p[i].ff, b = p[i].ss;
		
		if(!incycle[a] && !incycle[b])	G[a].pb(mp(b, -1)), G[b].pb(mp(a, -1));
		else if(incycle[a] && !incycle[b]) G[detected].pb(mp(b, a)), G[b].pb(mp(detected, a));
		else if(incycle[b] && !incycle[a]) G[detected].pb(mp(a, b)), G[a].pb(mp(detected, b));
	}
	
	for(pii i : G[detected]) 
		cycleP[i.ff] = i.ss;
	
	dfs(detected, 0);
	id0();
	id2(detected, 0);
	memset(vis, 0, sizeof(vis));
	form_cycle(detected, 0);
	form_tree(1, n, 1);
	id1(1, counter, 1);
	
	ans = n;
	cyclic = counter;
	
	while(m--){test++;
		scanf("%d%d", &a, &b);
		int fa = a, fb = b;
		
		if(incycle[a])
			fa = detected;
		if(incycle[b])
			fb = detected;
		
		int tr = LCA(fa, fb);
		int aa = a, bb = b;
		pii t = mp(0, 0), w = mp(0, 0);
		pii justff = mp(0, 0);
		
		if(tr != detected){
			a = aa, b = bb;
			while(ch[a] != ch[tr]){
				t = get(ID[par[ch[a]]], ID[a], 1, n, 1);
				upd(ID[par[ch[a]]], ID[a], 1, n, 1);
				a = P[par[ch[a]]][0];
				w = mp(w.ff+t.ff, w.ss+t.ss);
			}
			if(ID[tr]+1 <= ID[a])
				t = get(ID[tr]+1, ID[a], 1, n, 1), upd(ID[tr]+1, ID[a], 1, n, 1), w = mp(w.ff+t.ff, w.ss+t.ss);
			
			while(ch[b] != ch[tr]){
				t = get(ID[par[ch[b]]], ID[b], 1, n, 1);
				upd(ID[par[ch[b]]], ID[b], 1, n, 1);
				b = P[par[ch[b]]][0];
				w = mp(w.ff+t.ff, w.ss+t.ss);
			}
			if(ID[tr]+1 <= ID[b])
				t = get(ID[tr]+1, ID[b], 1, n, 1), upd(ID[tr]+1, ID[b], 1, n, 1), w = mp(w.ff+t.ff, w.ss+t.ss);
		}
		else{
			

			int ka = 0;
			int kb = 0;
			
			if(incycle[a])
				ka = a;
			else{
				int diffa = lvl[a] - lvl[detected] - 1;
				ka = jump(a, diffa);
				
				while(ch[a] != ch[ka]){
					t = get(ID[par[ch[a]]], ID[a], 1, n, 1);
					upd(ID[par[ch[a]]], ID[a], 1, n, 1);
					a = P[par[ch[a]]][0];
					w = mp(w.ff+t.ff, w.ss+t.ss);
				}
				if(ID[ka] <= ID[a])
					t = get(ID[ka], ID[a], 1, n, 1), upd(ID[ka], ID[a], 1, n, 1), w = mp(w.ff+t.ff, w.ss+t.ss);
				
				ka = cycleP[ka];
			}
			
			if(incycle[b])
				kb = b;
			else{
				int diffb = lvl[b] - lvl[detected] - 1;
				kb = jump(b, diffb);
				
				while(ch[b] != ch[kb]){
					t = get(ID[par[ch[b]]], ID[b], 1, n, 1);
					upd(ID[par[ch[b]]], ID[b], 1, n, 1);
					b = P[par[ch[b]]][0];
					w = mp(w.ff+t.ff, w.ss+t.ss);
				}
				if(ID[kb] <= ID[b])
					t = get(ID[kb], ID[b], 1, n, 1), upd(ID[kb], ID[b], 1, n, 1), w = mp(w.ff+t.ff, w.ss+t.ss);
				
				kb = cycleP[kb];
			}
			
			if(ka == kb){
				ans -= w.ff, ans += w.ss;
				
				if(cyclic < 1)
					printf("%d\n", ans+1);
				else
					printf("%d\n", ans);
				
				continue;
			}
			
			

			int kc = 0;
			int flag = 0;
			
			if(abs(IDC[kb]-IDC[ka]) > counter-(abs(IDC[kb]-IDC[ka]))){
				if(IDC[kb] <= IDC[ka]){
					if(max(IDC[C[ka][0]], IDC[C[ka][1]]) <= IDC[ka])
						kc = (IDC[C[ka][0]] < IDC[C[ka][1]] ? C[ka][0] : C[ka][1]), flag=1;
					else
						kc = (IDC[C[ka][0]] > IDC[C[ka][1]] ? C[ka][0] : C[ka][1]);
				}
				else{
					if(max(IDC[C[kb][0]], IDC[C[kb][1]]) <= IDC[kb])
						kc = (IDC[C[kb][0]] < IDC[C[kb][1]] ? C[kb][0] : C[kb][1]), flag=1;
					else
						kc = (IDC[C[kb][0]] > IDC[C[kb][1]] ? C[kb][0] : C[kb][1]);
				}
			}
			else if(abs(IDC[kb]-IDC[ka]) < counter-(abs(IDC[kb]-IDC[ka]))){
				if(IDC[ka] <= IDC[kb]){
					if(max(IDC[C[ka][0]], IDC[C[ka][1]]) > IDC[kb])
						kc = (IDC[C[ka][0]] <= IDC[C[ka][1]] ? C[ka][0] : C[ka][1]);
					else
						kc = (IDC[C[ka][0]] >= IDC[C[ka][1]] ? C[ka][0] : C[ka][1]);
				}
				else{
					if(max(IDC[C[kb][0]], IDC[C[kb][1]]) > IDC[ka])
						kc = (IDC[C[kb][0]] <= IDC[C[kb][1]] ? C[kb][0] : C[kb][1]);
					else
						kc = (IDC[C[kb][0]] >= IDC[C[kb][1]] ? C[kb][0] : C[kb][1]);
				}
			}
			else
				kc = min(C[ka][0], C[ka][1]);
			
			if(min(IDC[ka], IDC[kb]) <= IDC[kc] && IDC[kc] <= max(IDC[ka], IDC[kb]) && !flag){
				t = getC(min(IDC[ka], IDC[kb]), max(IDC[ka], IDC[kb])-1, 1, counter, 1); 
				updC(min(IDC[ka], IDC[kb]), max(IDC[ka], IDC[kb])-1, 1, counter, 1);
				w = mp(w.ff+t.ff, w.ss+t.ss);
				justff = mp(justff.ff+t.ff, justff.ss+t.ss);
			}
			else{
				t = getC(max(IDC[ka], IDC[kb]), counter, 1, counter, 1);
				updC(max(IDC[ka], IDC[kb]), counter, 1, counter, 1);
				w = mp(w.ff+t.ff, w.ss+t.ss);
				justff = mp(justff.ff+t.ff, justff.ss+t.ss);
				
				if(min(IDC[ka], IDC[kb]) > 1){
					t = getC(1, min(IDC[ka], IDC[kb])-1, 1, counter, 1);
					updC(1, min(IDC[ka], IDC[kb])-1, 1, counter, 1);
					w = mp(w.ff+t.ff, w.ss+t.ss);
					justff = mp(justff.ff+t.ff, justff.ss+t.ss);
				}
			}
		}
		
		cyclic -= justff.ff, cyclic += justff.ss;
		ans -= w.ff, ans += w.ss;
		
		if(cyclic < 1)
			printf("%d\n", ans+1);
		else
			printf("%d\n", ans);
	}
	
	return 0;
}
