#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
#include <chrono>
#include <random>
using namespace std;

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int STALPH = 26;

struct STNode {
	char *s; int len;
	int childs[STALPH];
	int suffix;
	STNode(char *s, int len) :s(s), len(len) { memset(childs, -1, sizeof(childs)); suffix = -1; }
};
struct SuffixTree {
	int root;
	vector<STNode> nodes;

	int addnode(char *s, int len) { nodes.PB(STNode(s, len)); return SZ(nodes) - 1; }
	vector<int> build(char *s) {
		nodes.clear(); root = addnode(NULL, 0);
		int n = strlen(s), atnode = root, atedge = 0, atlen = 0, pint = -1, pleaf = -1; 

		REPE(i, n) {
			while (true) {
				int tonode = atedge == n ? -1 : nodes[atnode].childs[s[atedge] - 'a'];
				if (tonode != -1 && atlen >= nodes[tonode].len) {
					atedge += nodes[tonode].len;
					atlen -= nodes[tonode].len;
					atnode = tonode;
					continue;
				}
				if (tonode == -1) { 

					if (i != n) {
						int leaf = addnode(s + i, n - i);
						nodes[atnode].childs[nodes[leaf].s[0] - 'a'] = leaf;
						if (pleaf != -1) nodes[pleaf].suffix = leaf; pleaf = leaf;
					} else {
						if (pleaf != -1) nodes[pleaf].suffix = atnode; pleaf = -1;
					}
					if (pint != -1) nodes[pint].suffix = atnode; pint = -1;
				} else if (i == n || nodes[tonode].s[atlen] != s[i]) {
					int branch = addnode(nodes[tonode].s, atlen);
					nodes[tonode].s += atlen, nodes[tonode].len -= atlen;
					nodes[atnode].childs[nodes[branch].s[0] - 'a'] = branch;
					nodes[branch].childs[nodes[tonode].s[0] - 'a'] = tonode;
					if (i != n) {
						int leaf = addnode(s + i, n - i);
						nodes[branch].childs[nodes[leaf].s[0] - 'a'] = leaf;
						if (pleaf != -1) nodes[pleaf].suffix = leaf; pleaf = leaf;
					} else {
						if (pleaf != -1) nodes[pleaf].suffix = branch; pleaf = -1;
					}
					if (pint != -1) nodes[pint].suffix = branch; pint = branch;
				} else {
					if (pint != -1) assert(atlen == 0), nodes[pint].suffix = atnode; pint = -1;
					++atlen;
					break;
				}
				if (atnode == root) {
					atedge++;
					if (atlen == 0) { assert(pint == -1); break; } else --atlen;
				} else {
					atnode = nodes[atnode].suffix;
				}
			}
		}
		vector<int> ret(n+1,-1); for(int at=1,len=n;at!=-1;at=nodes[at].suffix,--len) ret[len]=at; return ret;
	}

	void print(int at, int depth = 0) {
		REP(i, depth) printf("  "); if (nodes[at].s == NULL) printf("<root>"); else printf("'%.*s'", nodes[at].len, nodes[at].s);
		printf(": id=%d",at); if(nodes[at].suffix!=-1) printf(" suffix=%d",nodes[at].suffix); puts("");
		REP(i, STALPH) if (nodes[at].childs[i] != -1) print(nodes[at].childs[i], depth + 1);
	}
};

struct TNode {
	vector<int> ch; int parlen;
	int sz,heavy,par,pathid,pathidx,rootlen;
};
struct Tree {
	int root;
	vector<TNode> nodes;
};

struct HLPath {
	vector<int> nodes;
};
struct HeavyLight {
	Tree *t;
	vector<int> prelst;
	vector<HLPath> paths;
	
	void dfspre(int at) {
		prelst.PB(at);
		REPSZ(i,t->nodes[at].ch) dfspre(t->nodes[at].ch[i]);
	}
	void build(Tree *_t) {
		t=_t; prelst.clear(); dfspre(t->root);
		for(int i=SZ(prelst)-1;i>=0;--i) {
			int at=prelst[i]; t->nodes[at].sz=1,t->nodes[at].heavy=-1,t->nodes[at].par=-1;
			REPSZ(j,t->nodes[at].ch) { int to=t->nodes[at].ch[j]; t->nodes[to].par=at; t->nodes[at].sz+=t->nodes[to].sz; if(t->nodes[at].heavy==-1||t->nodes[to].sz>t->nodes[t->nodes[at].heavy].sz) t->nodes[at].heavy=to; }
		}
		paths.clear();
		REPSZ(i,prelst) {
			int at=prelst[i]; t->nodes[at].rootlen=t->nodes[at].par==-1?0:t->nodes[t->nodes[at].par].rootlen+t->nodes[at].parlen;
			if(t->nodes[at].par!=-1&&t->nodes[t->nodes[at].par].heavy==at) continue;
			HLPath path; for(int x=at;x!=-1;x=t->nodes[x].heavy) t->nodes[x].pathid=SZ(paths),t->nodes[x].pathidx=SZ(path.nodes),path.nodes.PB(x); paths.PB(path);
		}
	}
	vector<pair<int,int>> decomposepathtoroot(int at) {
		vector<pair<int,int>> ret;
		while(at!=-1) { ret.PB(MP(t->nodes[at].pathid,t->nodes[at].pathidx)); at=t->nodes[paths[t->nodes[at].pathid].nodes[0]].par; }
		reverse(ret.begin(),ret.end()); return ret;
	}
	void print() {
		REPSZ(i,paths) { printf("path%d:",i); REPSZ(j,paths[i].nodes) printf(" %d",paths[i].nodes[j]); puts(""); }
	}
};



const int MAXLEN=200000;
const int MAXQ=200000;

char s[MAXLEN+1]; int slen;
int nq;
int ql[MAXQ],qr[MAXQ]; ll qans[MAXQ];

SuffixTree sufftree;
vector<int> suffixids;
Tree t;
HeavyLight heavylight;

struct BIT {
	int n; pair<int,ll> all; vector<pair<int,ll>> bit;
	BIT(int _n) { n=_n; all=MP(0,0LL); bit=vector<pair<int,ll>>(n+1,MP(0,0LL)); }
	void mod(int idx,int a,ll b) {  all.first+=a; all.second+=b; ++idx; while(idx<=n) { bit[idx].first+=a; bit[idx].second+=b; idx+=idx&-idx; } }
	pair<int,ll> get(int idx) { pair<int,ll> ret=MP(0,0LL); ++idx; while(idx>0) { ret.first+=bit[idx].first; ret.second+=bit[idx].second; idx-=idx&-idx; } return ret; }
};

struct P { int id,pathidx,len; P(int id,int pathidx,int len):id(id),pathidx(pathidx),len(len) {} };
struct Q { int id,pathidx,len; Q(int id,int pathidx,int len):id(id),pathidx(pathidx),len(len) {} };
struct E { int kind,id,pathidx,key,val; E(int kind,int id,int pathidx,int key,int val):kind(kind),id(id),pathidx(pathidx),key(key),val(val) {} };
bool operator<(const E &a,const E &b) { if(a.key!=b.key) return a.key<b.key; return a.kind<b.kind; }

void solve() {
	

	suffixids=sufftree.build(s);
	

	
	

	t.nodes.clear(); t.root=sufftree.root; REPSZ(i,sufftree.nodes) { TNode tnode; tnode.parlen=sufftree.nodes[i].len; REP(j,STALPH) if(sufftree.nodes[i].childs[j]!=-1) tnode.ch.PB(sufftree.nodes[i].childs[j]); t.nodes.PB(tnode); }
	heavylight.build(&t);
	

	
	vector<vector<int>> qlst(SZ(t.nodes)); REP(i,nq) qlst[suffixids[slen-ql[i]]].PB(i);
	vector<vector<int>> plst(SZ(t.nodes)); REP(i,slen) plst[suffixids[slen-i]].PB(i);
	queue<int> q;
	

	REPSZ(pathid,heavylight.paths) {
		

		int firstnode=heavylight.paths[pathid].nodes[0],h=t.nodes[firstnode].rootlen-t.nodes[firstnode].parlen,pathlen=SZ(heavylight.paths[pathid].nodes);
		vector<int> dep(pathlen); REP(i,pathlen) dep[i]=t.nodes[heavylight.paths[pathid].nodes[i]].rootlen;
		

		vector<P> curp; vector<Q> curq;
		REP(pathidx,pathlen) {
			q.push(heavylight.paths[pathid].nodes[pathidx]);
			while(!q.empty()) {
				int at=q.front(); q.pop();
				REPSZ(i,qlst[at]) { int id=qlst[at][i]; if(h>=qr[id]-ql[id]+1) continue; int lo=0,hi=pathidx+1; while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(dep[mi-1]>=qr[id]-ql[id]+1) hi=mi; else lo=mi; } curq.PB(Q(id,lo,min(qr[id]-ql[id]+1,dep[lo]))); }
				REPSZ(i,plst[at]) curp.PB(P(plst[at][i],pathidx,dep[pathidx]));
				REPSZ(i,t.nodes[at].ch) { int to=t.nodes[at].ch[i]; if(pathidx+1>=pathlen||to!=heavylight.paths[pathid].nodes[pathidx+1]) q.push(to); }
			}
		}
		

		

		

		

		

		

		

		

		

		{ 

			vector<E> e;
			REPSZ(i,curp) { int id=curp[i].id,pathidx=curp[i].pathidx,len=curp[i].len; e.PB(E(0,id,pathidx,id+h,-(id+h))); }
			REPSZ(i,curq) { int id=curq[i].id,pathidx=curq[i].pathidx,len=curq[i].len; e.PB(E(1,id,pathidx,qr[id]+1,+(qr[id]+1))); }
			sort(e.begin(),e.end());
			BIT bit(pathlen);
			REPSZ(i,e) {
				if(e[i].kind==0) { bit.mod(e[i].pathidx,+1,e[i].val); continue; }
				pair<int,ll> pref=bit.get(e[i].pathidx-1),all=bit.all; qans[e[i].id]+=(ll)e[i].val*all.first+all.second;
			}
		}
		

		{ 

			vector<E> e;
			REPSZ(i,curp) { int id=curp[i].id,pathidx=curp[i].pathidx,len=curp[i].len; e.PB(E(0,id,pathidx,id+len,+(id+len))); }
			REPSZ(i,curq) { int id=curq[i].id,pathidx=curq[i].pathidx,len=curq[i].len; e.PB(E(1,id,pathidx,qr[id]+1,-(qr[id]+1))); }
			sort(e.begin(),e.end());
			BIT bit(pathlen);
			REPSZ(i,e) {
				if(e[i].kind==0) { bit.mod(e[i].pathidx,+1,e[i].val); continue; }
				pair<int,ll> pref=bit.get(e[i].pathidx-1),all=bit.all; qans[e[i].id]+=(ll)e[i].val*pref.first+pref.second;
			}
		}
		

		{ 

			vector<E> e;
			REPSZ(i,curp) { int id=curp[i].id,pathidx=curp[i].pathidx,len=curp[i].len; e.PB(E(0,id,pathidx,id,+(id))); }
			REPSZ(i,curq) { int id=curq[i].id,pathidx=curq[i].pathidx,len=curq[i].len; e.PB(E(1,id,pathidx,qr[id]+1-len,-(qr[id]+1-len))); }
			sort(e.begin(),e.end());
			BIT bit(pathlen);
			REPSZ(i,e) {
				if(e[i].kind==0) { bit.mod(e[i].pathidx,+1,e[i].val); continue; }
				pair<int,ll> pref=bit.get(e[i].pathidx-1),all=bit.all; qans[e[i].id]+=(ll)e[i].val*(all.first-pref.first)+(all.second-pref.second);
			}
		}
		

		{ 

			vector<E> e;
			REPSZ(i,curp) { int id=curp[i].id,pathidx=curp[i].pathidx,len=curp[i].len; e.PB(E(0,id,pathidx,id,+(len))); }
			REPSZ(i,curq) { int id=curq[i].id,pathidx=curq[i].pathidx,len=curq[i].len; e.PB(E(1,id,pathidx,ql[id]-1,-(len))); }
			sort(e.begin(),e.end());
			BIT bit(pathlen);
			REPSZ(i,e) {
				if(e[i].kind==0) { bit.mod(e[i].pathidx,+1,e[i].val); continue; }
				pair<int,ll> pref=bit.get(e[i].pathidx-1),all=bit.all; qans[e[i].id]-=(ll)e[i].val*pref.first+pref.second+(ll)(-e[i].val-h)*all.first;
			}
		}
		

	}
	

}

void run() {
	scanf("%s",s); slen=strlen(s);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d",&ql[i],&qr[i]),--ql[i],--qr[i];
	solve();
	REP(i,nq) printf("%lld\n",qans[i]);
}

void stress() {
	std::mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
	REP(rep,10) {
		slen=MAXLEN; REP(i,slen) s[i]='a'+rng()%2; s[slen]='\0';
		nq=MAXQ; REP(i,nq) { ql[i]=rng()%slen,qr[i]=rng()%slen; if(ql[i]>qr[i]) swap(ql[i],qr[i]); }
		solve();
		printf(".");
	}
}

int main() {
	run();
	

	return 0;
}