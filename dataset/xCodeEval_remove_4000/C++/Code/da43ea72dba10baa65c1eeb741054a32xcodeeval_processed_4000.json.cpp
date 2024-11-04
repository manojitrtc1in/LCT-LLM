


















using namespace std;










typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int id11 = 26;

struct STNode {
	char *s; int len;
	int childs[id11];
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
		REP(i, id11) if (nodes[at].childs[i] != -1) print(nodes[at].childs[i], depth + 1);
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
		id10(i,t->nodes[at].ch) dfspre(t->nodes[at].ch[i]);
	}
	void build(Tree *_t) {
		t=_t; prelst.clear(); dfspre(t->root);
		for(int i=SZ(prelst)-1;i>=0;--i) {
			int at=prelst[i]; t->nodes[at].sz=1,t->nodes[at].heavy=-1,t->nodes[at].par=-1;
			id10(j,t->nodes[at].ch) { int to=t->nodes[at].ch[j]; t->nodes[to].par=at; t->nodes[at].sz+=t->nodes[to].sz; if(t->nodes[at].heavy==-1||t->nodes[to].sz>t->nodes[t->nodes[at].heavy].sz) t->nodes[at].heavy=to; }
		}
		paths.clear();
		id10(i,prelst) {
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
		id10(i,paths) { printf("path%d:",i); id10(j,paths[i].nodes) printf(" %d",paths[i].nodes[j]); puts(""); }
	}
};



const int MAXLEN=200000;
const int MAXQ=200000;

char s[MAXLEN+1]; int slen;
int nq;
int ql[MAXQ],qr[MAXQ]; ll qans[MAXQ];

SuffixTree id2;
vector<int> suffixids;
Tree t;
HeavyLight id3;
vector<vector<int>> desc;
vector<pair<int,int>> qpaths[MAXQ];
vector<vector<pair<int,int>>> pathqs;
vector<int> qqueries[MAXQ];


const int QCNT=0,id14=1,id0=2,id9=3,id8=4;
struct Q { int pathid,kind,lx,hx,hz,mlt; ll ans; Q(int pathid,int kind,int lx,int hx,int hz,int mlt):pathid(pathid),kind(kind),lx(lx),hx(hx),hz(hz),mlt(mlt),ans(0) {} };

vector<Q> allqueries;
int addquery(int pathid,int kind,int lx,int hx,int hz,int mlt) { int ret=SZ(allqueries); allqueries.PB(Q(pathid,kind,lx,hx,hz,mlt)); return ret; }

void id13(int qid,int pathid,int lx,int hx,int val) {
	

	qqueries[qid].PB(addquery(pathid,QCNT,lx,hx,val,+val));
	qqueries[qid].PB(addquery(pathid,id14,lx,hx,val,-1));
	qqueries[qid].PB(addquery(pathid,id9,lx,hx,val,-val));
	qqueries[qid].PB(addquery(pathid,id8,lx,hx,val,+1));
}
void id4(int qid,int pathid,int lx,int hx,int val,int cap) {
	

	qqueries[qid].PB(addquery(pathid,QCNT,lx,hx,val,+val));
	qqueries[qid].PB(addquery(pathid,id14,lx,hx,val,-1));
	qqueries[qid].PB(addquery(pathid,QCNT,lx,hx,val-cap,-(val-cap)));
	qqueries[qid].PB(addquery(pathid,id14,lx,hx,val-cap,+1));
}
void id12(int qid,int pathid,int lx,int hx,int hz) {
	

	qqueries[qid].PB(addquery(pathid,id0,lx,hx,hz,-1));
}
void id1(int qid,int pathid,int lx,int hx,int hz,int val) {
	

	qqueries[qid].PB(addquery(pathid,QCNT,lx,hx,hz,-val));
}
void query_special(int qid,int pathid,int lx,int hx,int val,int lz,int hz) {
	

	qqueries[qid].PB(addquery(pathid,QCNT,lx,hx,hz,+val));
	qqueries[qid].PB(addquery(pathid,id14,lx,hx,hz,-1));
	qqueries[qid].PB(addquery(pathid,QCNT,lx,hx,lz-1,-val));
	qqueries[qid].PB(addquery(pathid,id14,lx,hx,lz-1,+1));
}

vector<ll> bit;
void binit(int n) { bit=vector<ll>(n+1,0); }
void bmod(int idx,int by) { ++idx; while(idx<SZ(bit)) { bit[idx]+=by; idx+=idx&-idx; } }
ll bget(int idx) { ++idx; ll ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }


void id7(int pathid) {
	vector<vector<int>> bykind(5);
	id10(i,allqueries) { assert(allqueries[i].pathid==pathid); int kind=allqueries[i].kind; bykind[kind].PB(i); }
	REP(kind,5) {
		vector<pair<int,pair<int,int>>> e;
		int pathfst=id3.paths[pathid].nodes[0];
		id10(x,id3.paths[pathid].nodes) {
			int at=id3.paths[pathid].nodes[x],atlen=t.nodes[at].rootlen-t.nodes[pathfst].rootlen+t.nodes[pathfst].parlen;
			id10(i,desc[at]) {
				int z=desc[at][i];
				if(kind==QCNT) e.PB(MP(z,MP(x,+1)));
				if(kind==id14) e.PB(MP(z,MP(x,+z)));
				if(kind==id0) e.PB(MP(z,MP(x,+atlen)));
				if(kind==id9) e.PB(MP(z+atlen,MP(x,+1)));
				if(kind==id8) e.PB(MP(z+atlen,MP(x,+z+atlen)));
			}
		}
		id10(i,bykind[kind]) {
			int qid=bykind[kind][i],hz=allqueries[qid].hz;
			e.PB(MP(hz,MP(INT_MAX,qid)));
		}
		sort(e.begin(),e.end());
		binit(SZ(id3.paths[pathid].nodes));
		id10(i,e) {
			if(e[i].second.first!=INT_MAX) {
				bmod(e[i].second.first,e[i].second.second);
			} else {
				int qid=e[i].second.second,lx=allqueries[qid].lx,hx=allqueries[qid].hx,mlt=allqueries[qid].mlt; ll ans=0;
				ans+=mlt*(bget(hx)-bget(lx-1));
				

				allqueries[qid].ans=ans;
			}
		}
	}

	
}

void solve() {
	

	suffixids=id2.build(s);
	

	
	

	t.nodes.clear(); t.root=id2.root; id10(i,id2.nodes) { TNode tnode; tnode.parlen=id2.nodes[i].len; REP(j,id11) if(id2.nodes[i].childs[j]!=-1) tnode.ch.PB(id2.nodes[i].childs[j]); t.nodes.PB(tnode); }
	id3.build(&t);
	

	
	

	desc=vector<vector<int>>(SZ(id2.nodes));
	REP(i,slen) { int at=suffixids[slen-i]; for(int x=at;x!=-1;x=t.nodes[id3.paths[t.nodes[x].pathid].nodes[0]].par) desc[x].PB(i); }
	

	
	

	REP(i,nq) qpaths[i]=id3.decomposepathtoroot(suffixids[slen-ql[i]]);
	

	REP(i,nq) qans[i]=0;
	
	pathqs=vector<vector<pair<int,int>>>(SZ(id3.paths)); REP(i,nq) id10(j,qpaths[i]) { int pathid=qpaths[i][j].first,pathlen=qpaths[i][j].second+1; pathqs[pathid].PB(MP(i,pathlen)); }
	id10(pathid,id3.paths) {
		

		allqueries.clear();
		id10(i,pathqs[pathid]) {
			int qid=pathqs[pathid][i].first,pathlen=pathqs[pathid][i].second;
			int lo=-1,hi=pathlen; while(lo+1<hi) { int mi=lo+(hi-lo)/2; int at=id3.paths[pathid].nodes[mi]; if(t.nodes[at].rootlen<=qr[qid]-ql[qid]+1) lo=mi; else hi=mi; }
			int pathfst=id3.paths[pathid].nodes[0],pathcnt=SZ(id3.paths[pathid].nodes),id6=t.nodes[pathfst].rootlen-t.nodes[pathfst].parlen;
			

			if(lo>=0) { 
				

				int at=id3.paths[pathid].nodes[lo],atlen=t.nodes[at].rootlen-id6;
				id13(qid,pathid,0,lo,qr[qid]+1-id6);
				if(lo+1<pathcnt) id4(qid,pathid,lo+1,pathcnt-1,qr[qid]+1-id6,atlen);
				if(ql[qid]!=0) {
					id12(qid,pathid,0,lo,ql[qid]-1);
					if(lo+1<pathcnt) id1(qid,pathid,lo+1,pathcnt-1,ql[qid]-1,atlen);
				}
			}
			if(lo+1<pathlen) { 
				int at=id3.paths[pathid].nodes[lo+1],id5=t.nodes[at].rootlen-t.nodes[at].parlen; 
				if(t.nodes[at].par!=-1&&t.nodes[t.nodes[at].par].rootlen<=qr[qid]-ql[qid]+1) {
					

					query_special(qid,pathid,lo+1,pathlen-1,qr[qid]+1-id5,ql[qid],qr[qid]-id5);
				}
			}
		}
		

		id7(pathid);	
		

		id10(i,pathqs[pathid]) {
			int qid=pathqs[pathid][i].first;
			id10(i,qqueries[qid]) qans[qid]+=allqueries[qqueries[qid][i]].ans;
			qqueries[qid].clear();
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
	REP(rep,1) {
		slen=MAXLEN/10; REP(i,slen) s[i]='a'+rng()%2; s[slen]='\0';
		nq=MAXQ/10; REP(i,nq) { ql[i]=rng()%slen,qr[i]=rng()%slen; if(ql[i]>qr[i]) swap(ql[i],qr[i]); }
		solve();
		printf(".");
	}
}

int main() {
	run();
	

	return 0;
}