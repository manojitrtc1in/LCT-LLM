


















using namespace std;










typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int id15 = 26;

struct STNode {
	char *s; int len;
	int childs[id15];
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
		REP(i, id15) if (nodes[at].childs[i] != -1) print(nodes[at].childs[i], depth + 1);
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
		id13(i,t->nodes[at].ch) dfspre(t->nodes[at].ch[i]);
	}
	void build(Tree *_t) {
		t=_t; prelst.clear(); dfspre(t->root);
		for(int i=SZ(prelst)-1;i>=0;--i) {
			int at=prelst[i]; t->nodes[at].sz=1,t->nodes[at].heavy=-1,t->nodes[at].par=-1;
			id13(j,t->nodes[at].ch) { int to=t->nodes[at].ch[j]; t->nodes[to].par=at; t->nodes[at].sz+=t->nodes[to].sz; if(t->nodes[at].heavy==-1||t->nodes[to].sz>t->nodes[t->nodes[at].heavy].sz) t->nodes[at].heavy=to; }
		}
		paths.clear();
		id13(i,prelst) {
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
		id13(i,paths) { printf("path%d:",i); id13(j,paths[i].nodes) printf(" %d",paths[i].nodes[j]); puts(""); }
	}
};



const int MAXLEN=200000;
const int MAXQ=200000;
const int MAXLG=20;







char s[MAXLEN+1]; int slen;
int nq;
int ql[MAXQ],qr[MAXQ]; ll qans[MAXQ];

SuffixTree id2;
vector<int> suffixids;
Tree t;
HeavyLight id5;

struct BIT {
	int n; pair<int,ll> all; vector<pair<int,ll>> bit;
	BIT() {} BIT(int _n) { n=_n; all=MP(0,0LL); bit=vector<pair<int,ll>>(n+1,MP(0,0LL)); }
	void mod(int idx,int a,ll b) {  all.first+=a; all.second+=b; ++idx; while(idx<=n) { bit[idx].first+=a; bit[idx].second+=b; idx+=idx&-idx; } }
	pair<int,ll> get(int idx) { pair<int,ll> ret=MP(0,0LL); ++idx; while(idx>0) { ret.first+=bit[idx].first; ret.second+=bit[idx].second; idx-=idx&-idx; } return ret; }
	void reset(int _n) { n=_n; all=MP(0,0LL); FORE(i,1,n) bit[i]=MP(0,0LL); }
};

struct P { int id,pathidx,len; P(int id,int pathidx,int len):id(id),pathidx(pathidx),len(len) {} P() {} };
struct Q { int id,pathidx,len; Q(int id,int pathidx,int len):id(id),pathidx(pathidx),len(len) {} Q() {} };
struct E { int kind,id,pathidx,key,val; E(int kind,int id,int pathidx,int key,int val):kind(kind),id(id),pathidx(pathidx),key(key),val(val) {}  E() {} };
bool operator<(const E &a,const E &b) { if(2*a.key+a.kind!=2*b.key+b.kind) return 2*a.key+a.kind<2*b.key+b.kind; return a.id<b.id; }







BIT bit(2*MAXLEN);

vector<vector<P>> id4;
vector<vector<P>> id14;
vector<vector<Q>> id1;
vector<vector<Q>> id0;
vector<vector<Q>> id9;

void precalc() {
	auto tstart = std::chrono::system_clock::now();
	

	

	

	

	

	id4=vector<vector<P>>(SZ(id5.paths));
	id14=vector<vector<P>>(SZ(id5.paths)); vector<vector<pair<int,P>>> id11(2*slen);
	REP(id,slen) {
		int at=suffixids[slen-id];
		while(at!=-1) {
			int pathid=t.nodes[at].pathid,pathidx=t.nodes[at].pathidx,len=t.nodes[at].rootlen;
			id4[pathid].PB(P(id,pathidx,len));
			id11[id+len].PB(MP(pathid,P(id,pathidx,len)));
			at=t.nodes[id5.paths[pathid].nodes[0]].par;
		}
	}
	id13(i,id11) id13(j,id11[i]) { auto cur=id11[i][j]; id14[cur.first].PB(cur.second); }
	fprintf(stderr,"\t%lld\n",(ll)((std::chrono::system_clock::now()-tstart).count()));
	id1=vector<vector<Q>>(SZ(id5.paths)); vector<vector<pair<int,Q>>> id17(slen);
	id0=vector<vector<Q>>(SZ(id5.paths)); vector<vector<pair<int,Q>>> id16(slen);
	id9=vector<vector<Q>>(SZ(id5.paths)); vector<vector<pair<int,Q>>> id8(2*slen);
	REP(id,nq) {
		int at=suffixids[slen-ql[id]];
		while(at!=-1) {
			int pathid=t.nodes[at].pathid,pathidx=t.nodes[at].pathidx,len=t.nodes[at].rootlen,firstnode=id5.paths[pathid].nodes[0],h=t.nodes[firstnode].rootlen-t.nodes[firstnode].parlen;
			if(h<qr[id]-ql[id]+1) {
				{ int lo=0,hi=pathidx+1; while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(t.nodes[id5.paths[pathid].nodes[mi-1]].rootlen>=qr[id]-ql[id]+1) hi=mi; else lo=mi; } pathidx=lo; }
				len=min(t.nodes[id5.paths[pathid].nodes[pathidx]].rootlen,qr[id]-ql[id]+1);
				id17[ql[id]].PB(MP(pathid,Q(id,pathidx,len)));
				id16[qr[id]].PB(MP(pathid,Q(id,pathidx,len)));
				id8[qr[id]-len+slen].PB(MP(pathid,Q(id,pathidx,len)));
			}
			at=t.nodes[firstnode].par;
		}
	}
	id13(i,id17) id13(j,id17[i]) { auto cur=id17[i][j]; id1[cur.first].PB(cur.second); }
	id13(i,id16) id13(j,id16[i]) { auto cur=id16[i][j]; id0[cur.first].PB(cur.second); }
	id13(i,id8) id13(j,id8[i]) { auto cur=id8[i][j]; id9[cur.first].PB(cur.second); }
	fprintf(stderr,"\t%lld\n",(ll)((std::chrono::system_clock::now()-tstart).count()));
}



void solve() {
	

	suffixids=id2.build(s);
	

	
	

	t.nodes.clear(); t.root=id2.root; id13(i,id2.nodes) { TNode tnode; tnode.parlen=id2.nodes[i].len; REP(j,id15) if(id2.nodes[i].childs[j]!=-1) tnode.ch.PB(id2.nodes[i].childs[j]); t.nodes.PB(tnode); }
	id5.build(&t);
	

	
	precalc();
	
	id13(pathid,id5.paths) {
		

		int firstnode=id5.paths[pathid].nodes[0],h=t.nodes[firstnode].rootlen-t.nodes[firstnode].parlen,pathlen=SZ(id5.paths[pathid].nodes);
		vector<P> &id7=id4[pathid]; vector<P> &id12=id14[pathid]; vector<Q> &id3=id1[pathid]; vector<Q> &id10=id0[pathid]; vector<Q> &id6=id9[pathid];
		

		

		

		

		{ 

			int pidx=0;
			pair<int,ll> all=MP(0,0LL);
			id13(qidx,id10) {
				while(pidx<SZ(id7)&&id7[pidx].id+h<=qr[id10[qidx].id]+1) all.first+=1,all.second-=id7[pidx].id+h,++pidx;
				qans[id10[qidx].id]+=(ll)(qr[id10[qidx].id]+1)*all.first+all.second;
			}
		}
		{ 

			int pidx=0;
			bit.reset(pathlen);
			id13(qidx,id10) {
				while(pidx<SZ(id12)&&id12[pidx].id+id12[pidx].len<=qr[id10[qidx].id]+1) bit.mod(id12[pidx].pathidx,+1,id12[pidx].id+id12[pidx].len),++pidx;
				pair<int,ll> pref=bit.get(id10[qidx].pathidx-1),all=bit.all; qans[id10[qidx].id]+=(ll)-(qr[id10[qidx].id]+1)*pref.first+pref.second;
			}
		}
		{ 

			int pidx=0;
			bit.reset(pathlen);
			id13(qidx,id6) {
				while(pidx<SZ(id7)&&id7[pidx].id<=qr[id6[qidx].id]+1-id6[qidx].len) bit.mod(id7[pidx].pathidx,+1,id7[pidx].id),++pidx;
				pair<int,ll> pref=bit.get(id6[qidx].pathidx-1),all=bit.all; qans[id6[qidx].id]+=(ll)-(qr[id6[qidx].id]+1-id6[qidx].len)*(all.first-pref.first)+(all.second-pref.second);
			}
		}
		{ 

			int pidx=0;
			bit.reset(pathlen);
			id13(qidx,id3) {
				while(pidx<SZ(id7)&&id7[pidx].id<=ql[id3[qidx].id]-1) bit.mod(id7[pidx].pathidx,+1,id7[pidx].len),++pidx;
				pair<int,ll> pref=bit.get(id3[qidx].pathidx-1),all=bit.all; qans[id3[qidx].id]-=(ll)-(id3[qidx].len)*pref.first+pref.second+(ll)(id3[qidx].len-h)*all.first;
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
	

	std::mt19937 rng(231789);
	REP(rep,10) {
		slen=MAXLEN; REP(i,slen) s[i]='a'+rng()%2; s[slen]='\0';
		nq=MAXQ; REP(i,nq) { ql[i]=rng()%slen,qr[i]=rng()%slen; if(ql[i]>qr[i]) swap(ql[i],qr[i]); }
		auto tstart = std::chrono::system_clock::now();
		solve();
		ll chk=0; REP(i,nq) chk^=qans[i];
		auto tend = std::chrono::system_clock::now();
		auto duration = (ll)((tend-tstart).count());
		printf("duration: %lld (chk=%lld)\n",duration,chk);
	}
}

int main() {
	run();
	

	return 0;
}
