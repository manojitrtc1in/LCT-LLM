






#include <vector>
#include <list>
#include <map>
#include <set>

#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))
#define RESET(Z,Y) memset(Z,Y,sizeof(Z))

#define SZ(Z) ((int)Z.size())
#define ALL(W) W.begin(), W.end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define INF 1023123123
#define EPS 1e-11

#define MX(Z,Y) Z = max((Z),(Y))
#define MN(X,Y) X = min((X),(Y))

#define FORIT(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

#define DEBUGV(x) \
		{ \
		cout << '>' << #x << ':'; \
		FORN(i,SZ((x))) cout << ' ' << x[i]; \
		cout << '\n'; }

#define DEBUGVV(x) \
		{ \
		cout << '>' << #x << ':' << '\n'; \
		FORN(i,SZ((x))) {\
			printf("%3d:",i); \
			FORN(j,SZ(x[i])) cout << ' ' << x[i][j]; \
			cout << '\n';}}

#define DEBUGVVI(x) \
		{ \
		cout << '>' << #x << ':' << '\n'; \
		int maxnumberofelement=0;\
		FORN(i,SZ(x)) MX(maxnumberofelement,SZ(x[i]));\
		cout << "        ";\
		FORN(i,maxnumberofelement) printf(" %7d",i);\
		cout << endl;\
		FORN(i,SZ((x))) { \
			printf("%7d:",i); \
			FORN(j,SZ(x[i])) printf(" %7d",x[i][j]); \
			cout << '\n';}}

#define DEBUGVS(x) \
		{ \
		cout << '>' << #x << ':' << '\n'; \
		FORN(i,SZ((x))) {\
			printf("%3d:",i); \
			cout << ' ' << x[i]; \
			cout << '\n';}}

#define DEBUGP(x) {cout << '>' << #x << ':' << x.first << ',' << x.second << '\n';}

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;
typedef vector<ll> vll;

class DisjointSet {
  public:
  	explicit DisjointSet(int n) {
  		whichset_ = vector<int>(n);
  		height_ = vector<int>(n, 1);
  		for (int i = 0; i < n; ++i) whichset_[i] = i;
  	}

  	int Find(int node) {
  		if (whichset_[node] == node) return node;
  		return (whichset_[node] = Find(whichset_[node]));
  	}

  	void Merge(int first_node, int second_node) {
  		

  		int h1 = height_[Find(first_node)];
  		int h2 = height_[Find(second_node)];
  		if (h1 < h2) {
	  		whichset_[Find(first_node)] = Find(second_node);
	  		return;
	  	}
	  	whichset_[Find(second_node)] = Find(first_node);
	  	if (h2 < h1) return;
	  	++height_[Find(second_node)];
  	}

  private:
  	vector<int> whichset_;
  	vector<int> height_;
};

class Graph {
  public:
  	virtual ~Graph() {};
  	virtual void Simplify() {};
};

class UnweightedGraph : public Graph {
  public:
  	UnweightedGraph(int number_of_nodes) : adj_(number_of_nodes) {}
  	UnweightedGraph& operator=(const UnweightedGraph& input_graph) {
  		adj_ = vector<vint>(SZ(input_graph.adj_));
  		FORN(i, SZ(input_graph.adj_)) FORIT(j, input_graph.adj_[i]) this->AddEdge(i, *j);
  		return *this;
  	}
  	virtual void AddEdge(int from, int to) {
  		adj_[from].PB(to);
  	}
  	virtual int Size() {
  		return adj_.size();
  	}
  	vector< vint > adj_;
};

class UndirectedUnweightedGraph : public UnweightedGraph {
  public:
  	UndirectedUnweightedGraph(int number_of_nodes) : UnweightedGraph(number_of_nodes) {}
  	virtual void AddEdge(int from, int to) {
  		UnweightedGraph::AddEdge(from, to);
  		UnweightedGraph::AddEdge(to, from);
  	}
};

class GraphOptimizedDisjointSet {
  public:
  	explicit GraphOptimizedDisjointSet(int n) {
  		whichset_ = vector<int>(n);
  		node_count_ = vector<int>(n, 1);
  		for (int i = 0; i < n; ++i) whichset_[i] = i;
  	}

  	int Find(int node) {
  		if (whichset_[node] == node) return node;
  		return (whichset_[node] = Find(whichset_[node]));
  	}

  	

  	int Merge(int first_node, int second_node) {
  		

  		if (node_count_[Find(first_node)] < node_count_[Find(second_node)]) {
  			whichset_[Find(first_node)] = Find(second_node);
  			node_count_[Find(second_node)] += node_count_[Find(first_node)];
  			return 1;
  		}
  		whichset_[Find(second_node)] = Find(first_node);
	  	node_count_[Find(first_node)] += node_count_[Find(second_node)];
	  	return 0;
  	}

  private:
  	mutable vector<int> whichset_;
  	vector<int> node_count_;
};



vector<int> SequenceSimplify(vector<int> seq) {
	int lowest = 0;
	vector<int> disort = seq;
	sort(ALL(disort));
	disort.erase(unique(ALL(disort)),disort.end());
	FORN(i,SZ(seq)) {
		seq[i] = (lower_bound(ALL(disort),seq[i]) - disort.begin()) + lowest;
		}
	return seq;
	}













class MergeableUnweightedGraph : public UnweightedGraph {
  public:
  	explicit MergeableUnweightedGraph(int number_of_nodes) : UnweightedGraph(number_of_nodes), disjoint_set_(number_of_nodes), deleted_edges_count_(0), is_simplified_(0), is_n_changed_(1) {}
  	virtual void AddEdge(int from, int to) {
  		is_simplified_ = 0;
  		UnweightedGraph::AddEdge(from, to);
  	}
  	void Merge(int first_node, int second_node);
  	int Find(int node) {
  		if (!is_simplified_) Simplify();
  		return second_map_[node];
  	}
  	int Size() {
  		if (!is_n_changed_) return n_;
  		is_n_changed_ = 0;
  		n_ = 0;
  		FORN(i,SZ(adj_)) if (disjoint_set_.Find(i) == i) ++n_;
  		return n_;
	}
	template <class cInType>
  	void MoveData(cInType* input_graph);
  	virtual void Simplify();
  	int DeletedEdgesCount() {
  		if (!is_simplified_) Simplify();
  		return deleted_edges_count_;
  	}

  private:
  	GraphOptimizedDisjointSet disjoint_set_;
  	vector<int> second_map_;
  	int deleted_edges_count_;
  	int is_simplified_;
  	int is_n_changed_;
  	int n_;
};



void MergeableUnweightedGraph::Merge(int first_node, int second_node) {
  	is_simplified_ = 0;
  	is_n_changed_ = 1;
  	int real_first = disjoint_set_.Find(first_node);
  	int real_second = disjoint_set_.Find(second_node);
  	if (real_first == real_second) return;
  	if (!disjoint_set_.Merge(real_first, real_second)) swap(real_first, real_second);
  	

  	FORIT(i, adj_[real_first]) {
  		if (disjoint_set_.Find((*i)) == disjoint_set_.Find(real_first)) {
  			++deleted_edges_count_;
  			continue;
  		}
  		adj_[real_second].PB(disjoint_set_.Find(*i));
  	}
  	adj_[real_first].clear();
  	return;
}

template <class cInType>
void MergeableUnweightedGraph::MoveData(cInType* input_graph) {
  	if (!is_simplified_) Simplify();
  	

  	(*input_graph) = cInType(Size());
  	FORN(i,SZ(adj_)) FORIT(j, adj_[i]) input_graph->AddEdge(second_map_[i], second_map_[*j]);
}

void MergeableUnweightedGraph::Simplify() {
	is_simplified_ = 1;

  	

  	FORN(i,SZ(adj_)) FORIT(j, adj_[i]) *j = disjoint_set_.Find(*j);

  	

  	FORN(i,SZ(adj_)) {
  		int org = SZ(adj_[i]);
  		adj_[i].erase(remove_if(ALL(adj_[i]), bind1st(equal_to<int>(), i)), adj_[i].end());
  		deleted_edges_count_ += org - SZ(adj_[i]);
  	}

  	

  	vector<int> active_nodes;
  	FORN(i,SZ(adj_)) if (disjoint_set_.Find(i) == i) active_nodes.PB(i);
  	vector<int> tmp_map = SequenceSimplify(active_nodes);
  	second_map_ = vector<int>(SZ(adj_));
  	FORN(i,SZ(active_nodes)) second_map_[active_nodes[i]] = tmp_map[i];
  	FORN(i,SZ(adj_)) second_map_[i] = second_map_[disjoint_set_.Find(i)];
}




















vector<int> StronglyConnectedComponents(UnweightedGraph* graph, bool should_merge) {

	stack<int> urutan;
	DisjointSet ds(graph->Size());
	stack< pair<int,int> > ngurut;
	vector<int> sudah(graph->Size(), 0);
	vector<int> adadiurutan(graph->Size(), 0);
	for (int i = 0;i < graph->Size();i++) {
		if (sudah[i]) continue;
		urutan.push(i);
		ngurut.push(make_pair(i,0));
		adadiurutan[i] = 1;
		sudah[i] = 1;
		while (!ngurut.empty()) {
			int id = ngurut.top().first;
			int val = ngurut.top().second;
			ngurut.pop();
			if (val == (int)graph->adj_[id].size()) {
				while (!urutan.empty() && urutan.top() == id) urutan.pop();
				adadiurutan[ds.Find(id)] = 0;
				if (!urutan.empty()) adadiurutan[ds.Find(urutan.top())] = 1;
				continue;
				}
			ngurut.push(make_pair(id,val + 1));

			int next = graph->adj_[id][val];
			if (sudah[next] && !adadiurutan[ds.Find(next)]) continue;
			if (!sudah[next]) {
				sudah[next] = 1;
				urutan.push(next);
				ngurut.push(make_pair(next,0));
				adadiurutan[next] = 1;
				continue;
				}
			if (ds.Find(id) == ds.Find(next)) continue;
			while (!urutan.empty() && ds.Find(urutan.top()) != ds.Find(next)) {
				ds.Merge(urutan.top(), next);
				urutan.pop();
				}
			adadiurutan[ds.Find(id)] = 1;
			}
		}
	vector<int> ret(graph->Size());
  	FORN(i, graph->Size()) ret[i] = ds.Find(i);

  	if (should_merge) {
   	 	MergeableUnweightedGraph* mwg = dynamic_cast<MergeableUnweightedGraph* >(graph);
   	 	int n = graph->Size();
   	 	FORN(i, n) mwg->Merge(i, ret[i]);
  	}
 	 return ret;
}






int sex[125000];
int fri[125000];

ll getCost(int i, int j) {
  return 1000000LL + (ll)(sex[i] != sex[j]);
}

set< pair<int,int> > edges;

vector< int > adj[125000];
vector< ll > cost[125000];
int parent[125000];
int parent2[125000];

ll cycdp[125000][2][2];

enum kAction {
  pairedWithBack,
  pairedWithFirst,
  treeAndThis,
  treeOnly
};

kAction actfrom[125000][2][2];
pair< int, pair<int,int> > from[125000][2][2];

ll treedp[125000][2];

int backtracktree[125000][2];
int ispaired[125000][2];

vector< pair<int,int> > ret;

ll treeSolve(int node, int paired) {
  if (treedp[node][paired] != -1LL) return treedp[node][paired];
  ll best = -1LL;
  ll sumzero = 0LL;
  FORN(i, SZ(adj[node])) {
    int nex = adj[node][i];
    if (nex == parent[node] || nex == parent2[node]) continue;
    parent[nex] = node;
    sumzero += treeSolve(nex, 0);
  }
  if (paired) {
    ispaired[node][paired] = 0;
    return treedp[node][paired] = sumzero;
  }
  best = sumzero;
  FORN(i, SZ(adj[node])) {
    int nex = adj[node][i];
    if (nex == parent[node] || nex == parent2[node]) continue;
    ll val = sumzero - treeSolve(nex, 0) + treeSolve(nex, 1) + cost[node][i];
    if (val > best) {
      best = val;
      ispaired[node][paired] = 1;
      backtracktree[node][paired] = i;
    }
  }
  return treedp[node][paired] = best;
}

void treeBt(int node, int paired) {
  FORN(i, SZ(adj[node])) {
    int nex = adj[node][i];
    if (nex == parent[node] || nex == parent2[node]) continue;
    if (ispaired[node][paired] && backtracktree[node][paired] == i) {
      ret.PB(MP(node+1, nex+1));
      treeBt(nex, 1);
    } else {
      treeBt(nex, 0);
    }
  }
  return;
}

int main() {

  FORN(i, 125000) FORN(j, 2) {
    treedp[i][j] = -1LL;
    parent[i] = parent2[i] = -1;
  }

  int n;
  scanf("%d", &n);

  UnweightedGraph* ug = new UnweightedGraph(n);

  FORN(i, n) {
    scanf("%d%d", fri + i, sex + i);
    fri[i] -= 1;
    sex[i] -= 1;
    if (!edges.count(MP(i, fri[i]))) {
      edges.insert(MP(i, fri[i]));
      ug->AddEdge(i, fri[i]);
      if (!edges.count(MP(fri[i], i))) {
        adj[i].PB(fri[i]);
        adj[fri[i]].PB(i);
      }
    }
  }

  FORN(i, n) FORN(j, SZ(adj[i])) cost[i].PB(getCost(i, adj[i][j]));

  vector<int> components = StronglyConnectedComponents(ug, 0);

  vint count(n+2);
  FORN(i, SZ(components)) count[components[i]]++;

  ll kHuge = (ll)INF * (ll)INF;
  ll valans = 0LL;
  vint done(n+2);
  FORN(i, n) {
    if (count[components[i]] > 1 && !done[components[i]]) {
      

      done[components[i]] = 1;
      vint cyc;
      cyc.PB(i);
      int cyc_el = fri[i];
      while (cyc_el != i) {
        cyc.PB(cyc_el);
        cyc_el = fri[cyc_el];
      }

      FORN(i, SZ(cyc)) {
        parent[cyc[i]] = cyc[(i+1)%SZ(cyc)];
        parent2[cyc[i]] = cyc[(i+SZ(cyc)-1) % SZ(cyc)];
      }

      FORN(i, SZ(cyc)+1) cycdp[i][0][0] = cycdp[i][0][1] = cycdp[i][1][0] = cycdp[i][1][1] = kHuge * -1LL;

      

      cycdp[1][1][1] = treeSolve(cyc[0], 1); 

      cycdp[1][0][0] = treeSolve(cyc[0], 0);
      for (int j = 1; j < SZ(cyc); ++j) FORN(zero, 2) FORN(last, 2) {
        ll val = cycdp[j][zero][last];
        if (val == kHuge * -1LL) continue;
        

        ll valtes = val + treeSolve(cyc[j], 0);
        pair<int, pair<int,int> > ini = MP(j, MP(zero, last));
        if (valtes > cycdp[j+1][zero][0]) {
          cycdp[j+1][zero][0] = valtes;
          from[j+1][zero][0] = ini;
          actfrom[j+1][zero][0] = treeAndThis;
        }

        valtes = val + treeSolve(cyc[j], 1);
        if (valtes > cycdp[j+1][zero][1]) {
          cycdp[j+1][zero][1] = valtes;
          from[j+1][zero][1] = ini;
          actfrom[j+1][zero][1] = treeOnly;
        }
        


        

        if (last) {
          int newzero = zero;
          if (j == 1) newzero = 0;
          


          valtes = val + getCost(cyc[j], cyc[j-1]) + treeSolve(cyc[j], 1);
          if (valtes > cycdp[j+1][newzero][0]) {
            cycdp[j+1][newzero][0] = valtes;
            from[j+1][newzero][0] = ini;
            actfrom[j+1][newzero][0] = pairedWithBack;
          }

        }

        

        if (j == SZ(cyc)-1 && zero) {
          valtes = val + getCost(cyc[j], cyc[0]) + treeSolve(cyc[j], 1);
          if (valtes > cycdp[j+1][0][0]) {
            cycdp[j+1][0][0] = valtes;
            from[j+1][0][0] = ini;
            actfrom[j+1][0][0] = pairedWithFirst;
          }
        }
      }
      ll best = -kHuge;
      int l1, l2, l3;
      l1 = SZ(cyc);
      FORN(j, 2) FORN(k, 2) {
        if (cycdp[SZ(cyc)][j][k] > best) {
          best = cycdp[SZ(cyc)][j][k];
          l2 = j;
          l3 = k;
        }
      }
      valans += best;

      while (l1 > 1) {
        pair<int, pair<int,int> > prev = from[l1][l2][l3];
        if (actfrom[l1][l2][l3] == treeAndThis) {
          treeBt(cyc[prev.A], 0);
        } else {
          treeBt(cyc[prev.A], 1);

          if (actfrom[l1][l2][l3] == pairedWithBack) {
            ret.PB(MP(cyc[prev.A-1]+1, cyc[l1-1]+1));
          } else if (actfrom[l1][l2][l3] == pairedWithFirst) {
            ret.PB(MP(cyc[prev.A]+1, cyc[0]+1));
          }
        }
        l1 = prev.A;
        l2 = prev.B.A;
        l3 = prev.B.B;
      }
      if (l2 == 1) {
        treeBt(cyc[0], 1);
      } else {
        treeBt(cyc[0], 0);
      }
    }
  }

  cout << valans / 1000000LL << " " << valans % 1000000LL << endl;

  FORN(i, SZ(ret)) {
    printf("%d %d\n", ret[i].A, ret[i].B);
  }



  return 0;
}
