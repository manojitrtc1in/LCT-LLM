
using namespace std;





template <typename T> inline void read (T &t){t = 0;char c = getchar();int f = 1;while (c < '0' || c > '9'){if (c == '-') f = -f;c = getchar();}while (c >= '0' && c <= '9'){t = (t << 3) + (t << 1) + c - '0';c = getchar();} t *= f;}
template <typename T,typename ... Args> inline void read (T &t,Args&... args){read (t);read (args...);}
template <typename T> inline void write (T x){if (x < 0){x = -x;putchar ('-');}if (x > 9) write (x / 10);putchar (x % 10 + '0');}
template <typename T> inline void chkmax (T &a,T b){a = max (a,b);}
template <typename T> inline void chkmin (T &a,T b){a = min (a,b);}

char str[MAXM];
int n,m,Sum,q,sa[MAXM],rk[MAXM],hei[MAXM],bel[MAXM],pre[MAXM];
namespace getSA{

	int n,m,x[MAXM],y[MAXM],c[MAXM],st[MAXM][21];
	int id2 (int l,int r){
		int k = log2 (r - l + 1);
		return min (st[l][k],st[r - (1 << k) + 1][k]);
	}
	int id1 (int x,int y){
		if (x == y) return n;
		else{
			if (rk[x] > rk[y]) swap (x,y);
			

			return id2 (rk[x] + 1,rk[y]);
		}
	}
	void getSA (){
		m = 256;
		for (Int i = 1;i <= Sum;++ i) x[i] = str[i],c[x[i]] ++;

		for (Int i = 1;i <= m;++ i) c[i] += c[i - 1];
		for (Int i = 1;i <= Sum;++ i) sa[c[x[i]] --] = i;
		for (Int k = 1;k <= Sum;k <<= 1){
			int num = 0;
			for (Int i = Sum - k + 1;i <= Sum;++ i) y[++ num] = i;
			for (Int i = 1;i <= Sum;++ i) if (sa[i] > k) y[++ num] = sa[i] - k;
			for (Int i = 1;i <= m;++ i) c[i] = 0;
			for (Int i = 1;i <= Sum;++ i) c[x[i]] ++;
			for (Int i = 1;i <= m;++ i) c[i] += c[i - 1];
			for (Int i = Sum;i >= 1;-- i) sa[c[x[y[i]]] --] = y[i];
			swap (x,y),num = x[sa[1]] = 1;
			for (Int i = 2;i <= Sum;++ i)
				if (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) x[sa[i]] = num;
				else x[sa[i]] = ++ num;
			m = num;
			if (m == Sum) break;
		}
		for (Int i = 1;i <= Sum;++ i) rk[sa[i]] = i;
		for (Int i = 1,k = 0;i <= Sum;++ i){
			if (rk[i] == 1) k = 0;
			else{
				if (k) -- k;
				int j = sa[rk[i] - 1];
				while (i + k <= Sum && j + k <= Sum && str[i + k] == str[j + k]) ++ k;
			} 
			hei[rk[i]] = k;
		}
		for (Int x = 1;x <= Sum;++ x) st[x][0] = hei[x];
		for (Int j = 1;(1 << j) <= Sum;++ j)
			for (Int i = 1;i + (1 << j) - 1 <= Sum;++ i) st[i][j] = min (st[i][j - 1],st[i + (1 << j - 1)][j - 1]);
	}
}

int IND,siz[MAXN],dfn[MAXN],wht[MAXN],tur[MAXN],son[MAXN],top[MAXN],dep[MAXN],par[MAXN];




vector <pii> g[MAXN];

void dfs1 (int u,int fa){
	siz[u] = 1,par[u] = fa,dep[u] = dep[fa] + 1;
	for (pii it : g[u]) if (it.fi ^ fa){
		int v = it.fi;
		wht[v] = it.se,dfs1 (v,u),siz[u] += siz[v],son[u] = siz[v] > siz[son[u]] ? v : son[u];
	}
}

void dfs2 (int u,int Top){
	top[u] = Top,dfn[u] = ++ IND,tur[IND] = u;
	if (son[u]) dfs2 (son[u],Top);
	for (pii it : g[u]) if (it.fi != son[u] && it.fi != par[u]) dfs2 (it.fi,it.fi);
}

struct edge{int L,R,ind;};
vector <edge> G[MAXN];
int Tmp[MAXN],pos1[MAXN],pos2[MAXN],pos3[MAXN];
namespace getSAM{
	int lst = 1,cnt = 1,rt[MAXN],len[MAXN],fail[MAXN],ch[MAXN][26];
	void extend (int c){
		if (ch[lst][c] && len[ch[lst][c]] == len[lst] + 1){
			lst = ch[lst][c];
			return ;
		}
		int f = lst,p = ++ cnt;len[p] = len[f] + 1,lst = cnt;
		while (f && !ch[f][c]) ch[f][c] = p,f = fail[f];
		if (f == 0) fail[p] = 1;
		else{
			int x = ch[f][c];
			if (len[x] == len[f] + 1) fail[p] = x;
			else{
				int q = ++ cnt;
				memcpy (ch[q],ch[x],sizeof (ch[x])),len[q] = len[f] + 1,fail[q] = fail[x],fail[x] = fail[p] = q;
				while (f && ch[f][c] == x) ch[f][c] = q,f = fail[f];
			}
		}
	}
	struct Segment{
	
	
	
		int Tot,son[MAXN * LOGN][2],sum[MAXN * LOGN];
		void pushup (int x){sum[x] = sum[ls(x)] + sum[rs(x)];}
		void modify (int &x,int l,int r,int pos){
			if (!x) x = ++ Tot;sum[x] ++;
			if (l == r) return ;
			int mid = l + r >> 1;
			if (pos <= mid) modify (ls(x),l,mid,pos);
			else modify (rs(x),mid + 1,r,pos);
		}
		int merge (int x,int y,int l,int r){
			if (!x || !y) return x + y;
			if (l == r) return sum[x] += sum[y],x;
			int mid = l + r >> 1;
			ls(x) = merge (ls(x),ls(y),l,mid),rs(x) = merge (rs(x),rs(y),mid + 1,r),pushup (x);
			return x;
		}
		int query (int x,int l,int r,int ql,int qr){
			if (l >= ql && r <= qr) return sum[x];
			int mid = l + r >> 1,res = 0;
			if (ql <= mid) res += query (ls(x),l,mid,ql,qr);
			if (qr > mid) res += query (rs(x),mid + 1,r,ql,qr);
			return res;
		}
	}tree;
	vector <int> T[MAXN];int cd[MAXN],bak[MAXN],deg[MAXN],ind[MAXN],oud[MAXN],tson[MAXN];bool vis[MAXN],chk[MAXN];
	void getfuck (int u,char c){
		vis[u] = 1,pos1[u] = ++ Sum,str[Sum] = c,bak[Sum] = u;int whi = -1;
		for (Int k = 0;k < 26;++ k) if (ch[u][k] == tson[u]) whi = k;
		if (tson[u]) getfuck (tson[u],(char)(whi + 'a')),cd[u] = cd[tson[u]] + 1;
		for (Int k = 0;k < 26;++ k) if (ch[u][k] && k != whi && !vis[ch[u][k]] && !chk[ch[u][k]]) getfuck (ch[u][k],(char)(k + 'a')); 
	}
	void getshit (int u){
		for (Int v : T[u]) getshit (v),rt[u] = tree.merge (rt[u],rt[v],1,m);
		for (edge it : G[u]) Tmp[it.ind] = tree.query (rt[u],1,m,it.L,it.R);
	}
	void buildTree (){
		for (Int i = 1;i <= m;++ i){
			lst = 1,scanf ("%s",str + 1);
			for (Int k = 1;str[k];++ k) extend (str[k] - 'a'),tree.modify (rt[lst],1,m,i);
		}
		queue <int> q;
		for (Int i = 1;i <= cnt;++ i){
			for (Int k = 0;k < 26;++ k) if (ch[i][k]) deg[i] ++,T[ch[i][k]].push_back (i);
			if (!deg[i]) q.push (i);
		}
		while (!q.empty()){
			int u = q.front();q.pop (),oud[u] ++;
			for (Int v : T[u]){
				oud[v] += oud[u];
				if (!-- deg[v]) q.push (v);
			}
			T[u].clear(),deg[u] = 0;
		}
		for (Int i = 1;i <= cnt;++ i)
			for (Int k = 0;k < 26;++ k) if (ch[i][k]) deg[ch[i][k]] ++;
		for (Int i = 1;i <= cnt;++ i) if (!deg[i]) q.push (i);
		while (!q.empty()){
			int u = q.front();q.pop (),ind[u] ++;
			for (Int k = 0;k < 26;++ k) if (ch[u][k]){
				int v = ch[u][k];
				ind[v] += ind[u];
				if (!-- deg[v]) q.push (v);
			}
		}
		for (Int u = 1;u <= cnt;++ u){
			for (Int i = 0;i < 26;++ i)
				if (ch[u][i]){
					int v = ch[u][i];
					if (ind[u] * 2 > ind[v] && oud[v] * 2 > oud[u]) tson[u] = v,chk[v] = 1;
				}
		}
		for (Int i = 1;i <= cnt;++ i) if (!vis[i]) getfuck (i,0);
		for (Int i = 1;i <= cnt;++ i) T[fail[i]].push_back (i);
	}
}

void Addto (int u,int fa){
	for (pii it : g[u]) if (it.fi == son[u])
		str[++ Sum] = (char)(it.se + 'a'),pos2[u] = Sum,
		Addto (it.fi,u);
	for (pii it : g[u]) if (it.fi != son[u] && it.fi != fa)
		Addto (it.fi,u);
}
void id0 (int u,int fa,char c){
	for (pii it : g[u]) if (it.fi != son[u] && it.fi != fa) 
		id0 (it.fi,u,(char)(it.se + 'a'));
	for (pii it : g[u]) if (it.fi == son[u])
		id0 (it.fi,u,(char)(it.se + 'a'));
	str[++ Sum] = c,pos3[u] = Sum;
}

struct node{
	int u,To,typ;
	bool operator != (node &p)const{return u != p.u || To != p.To || typ != p.typ;}
};

void Query (int u,int v,int L,int R,int tim){

	

	vector <node> q1,q2;
	while (top[u] ^ top[v]){
		if (dep[top[u]] > dep[top[v]]) q1.push_back (node{u,top[u],0}),u = par[top[u]];
		else q2.push_back (node{v,top[v],1}),v = par[top[v]];
	}
	int lca;
	if (dep[u] < dep[v]) lca = u,q2.push_back (node{v,u,1});
	else lca = v,q1.push_back (node{u,v,0});
	while (!q2.empty()) q1.push_back (q2.back()),q2.pop_back ();
	int Now = 1;

	for (auto IT = q1.begin();IT != q1.end();++ IT){
		node it = *IT;
		int u = it.u,to = it.To,t = it.typ;
		

		if (t == 0){

			int Ned = dep[u] - dep[to];
			while (Ned){
				int fuc = getSA::id1 (pos1[getSAM::tson[Now]],pos3[u]);
				

				chkmin (fuc,dep[u] - dep[to]),chkmin (fuc,getSAM::cd[Now]);
				if (fuc >= Ned){
					Now = getSAM::bak[pos1[Now] + Ned];
					break;
				}
				else{
					u = tur[dfn[u] - fuc],Ned -= fuc + 1,Now = getSAM::bak[pos1[Now] + fuc];
					if (!getSAM::ch[Now][wht[u]]) return ;
					Now = getSAM::ch[Now][wht[u]],u = par[u];
				}
			}
			auto IT1 = IT;++ IT1;
			if (IT1 != q1.end()){
				if (it.To != lca) u = it.To;
				else u = IT1 -> To;
				if (!getSAM::ch[Now][wht[u]]) return ;
				else Now = getSAM::ch[Now][wht[u]];
			}
		}
		else{

			int Ned = dep[u] - dep[to];
			while (Ned){
				int fuc = getSA::id1 (pos1[getSAM::tson[Now]],pos2[to]);chkmin (fuc,dep[u] - dep[to]),chkmin (fuc,getSAM::cd[Now]);
				if (fuc >= Ned){
					Now = getSAM::bak[pos1[Now] + Ned];
					break;
				}
				else{
					to = tur[dfn[to] + fuc],Ned -= fuc + 1,Now = getSAM::bak[pos1[Now] + fuc];
					if (!getSAM::ch[Now][wht[son[to]]]) return ;
					Now = getSAM::ch[Now][wht[son[to]]],to = son[to];
				}
			}
			auto IT1 = IT;++ IT1;
			if (IT1 != q1.end()){
				if (!getSAM::ch[Now][wht[IT1 -> To]]) return ;
				else Now = getSAM::ch[Now][wht[IT1 -> To]];
			}
		}
	}
	G[Now].push_back (edge{L,R,tim});
}

signed main(){
	

	

	read (n,m,q);
	for (Int i = 2,u,v;i <= n;++ i){
		read (u,v);char opt[5]={};scanf("%s",opt+1);
		g[u].push_back ({v,opt[1] - 'a'}),g[v].push_back ({u,opt[1] - 'a'});
	}
	dfs1 (1,0),dfs2 (1,1),getSAM::buildTree(),Addto (1,0),id0 (1,0,0),getSA::getSA();
	

	for (Int k = 1;k <= q;++ k){
		int u,v,L,R;
		read (u,v,L,R),Query (u,v,L,R,k);
	}
	

	getSAM::getshit(1);
	for (Int k = 1;k <= q;++ k) write (Tmp[k]),putchar ('\n');
	return 0;
}