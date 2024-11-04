


















































		{ \
		cout << '>' << 
		FORN(i,SZ((x))) cout << ' ' << x[i]; \
		cout << '\n'; }


		{ \
		cout << '>' << 
		FORN(i,SZ((x))) {\
			printf("%3d:",i); \
			FORN(j,SZ(x[i])) cout << ' ' << x[i][j]; \
			cout << '\n';}}


		{ \
		cout << '>' << 
		int id1=0;\
		FORN(i,SZ(x)) MX(id1,SZ(x[i]));\
		cout << "        ";\
		FORN(i,id1) printf(" %7d",i);\
		cout << endl;\
		FORN(i,SZ((x))) { \
			printf("%7d:",i); \
			FORN(j,SZ(x[i])) printf(" %7d",x[i][j]); \
			cout << '\n';}}


		{ \
		cout << '>' << 
		FORN(i,SZ((x))) {\
			printf("%3d:",i); \
			cout << ' ' << x[i]; \
			cout << '\n';}}



using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;
typedef vector<ll> vll;

class id6 {
  public:
  	explicit id6(int n) {
  		id5 = vector<int>(n);
  		height_ = vector<int>(n, 1);
  		for (int i = 0; i < n; ++i) id5[i] = i;
  	}

  	int Find(int node) {
  		if (id5[node] == node) return node;
  		return (id5[node] = Find(id5[node]));
  	}

  	void Merge(int first_node, int second_node) {
  		

  		int h1 = height_[Find(first_node)];
  		int h2 = height_[Find(second_node)];
  		if (h1 < h2) {
	  		id5[Find(first_node)] = Find(second_node);
	  		return;
	  	}
	  	id5[Find(second_node)] = Find(first_node);
	  	if (h2 < h1) return;
	  	++height_[Find(second_node)];
  	}

  private:
  	vector<int> id5;
  	vector<int> height_;
};

class Graph {
  public:
  	virtual ~Graph() {};
  	virtual void Simplify() {};
};

class id10 : public Graph {
  public:
  	id10(int id19) : adj_(id19) {}
  	id10& operator=(const id10& input_graph) {
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

class id14 : public id10 {
  public:
  	id14(int id19) : id10(id19) {}
  	virtual void AddEdge(int from, int to) {
  		id10::AddEdge(from, to);
  		id10::AddEdge(to, from);
  	}
};

class id11 {
  public:
  	explicit id11(int n) {
  		id5 = vector<int>(n);
  		id2 = vector<int>(n, 1);
  		for (int i = 0; i < n; ++i) id5[i] = i;
  	}

  	int Find(int node) {
  		if (id5[node] == node) return node;
  		return (id5[node] = Find(id5[node]));
  	}

  	

  	int Merge(int first_node, int second_node) {
  		

  		if (id2[Find(first_node)] < id2[Find(second_node)]) {
  			id5[Find(first_node)] = Find(second_node);
  			id2[Find(second_node)] += id2[Find(first_node)];
  			return 1;
  		}
  		id5[Find(second_node)] = Find(first_node);
	  	id2[Find(first_node)] += id2[Find(second_node)];
	  	return 0;
  	}

  private:
  	mutable vector<int> id5;
  	vector<int> id2;
};



vector<int> id4(vector<int> seq) {
	int lowest = 0;
	vector<int> disort = seq;
	sort(ALL(disort));
	disort.erase(unique(ALL(disort)),disort.end());
	FORN(i,SZ(seq)) {
		seq[i] = (lower_bound(ALL(disort),seq[i]) - disort.begin()) + lowest;
		}
	return seq;
	}













class id13 : public id10 {
  public:
  	explicit id13(int id19) : id10(id19), disjoint_set_(id19), id18(0), id7(0), id15(1) {}
  	virtual void AddEdge(int from, int to) {
  		id7 = 0;
  		id10::AddEdge(from, to);
  	}
  	void Merge(int first_node, int second_node);
  	int Find(int node) {
  		if (!id7) Simplify();
  		return id16[node];
  	}
  	int Size() {
  		if (!id15) return n_;
  		id15 = 0;
  		n_ = 0;
  		FORN(i,SZ(adj_)) if (disjoint_set_.Find(i) == i) ++n_;
  		return n_;
	}
	template <class cInType>
  	void MoveData(cInType* input_graph);
  	virtual void Simplify();
  	int DeletedEdgesCount() {
  		if (!id7) Simplify();
  		return id18;
  	}

  private:
  	id11 disjoint_set_;
  	vector<int> id16;
  	int id18;
  	int id7;
  	int id15;
  	int n_;
};



void id13::Merge(int first_node, int second_node) {
  	id7 = 0;
  	id15 = 1;
  	int real_first = disjoint_set_.Find(first_node);
  	int real_second = disjoint_set_.Find(second_node);
  	if (real_first == real_second) return;
  	if (!disjoint_set_.Merge(real_first, real_second)) swap(real_first, real_second);
  	

  	FORIT(i, adj_[real_first]) {
  		if (disjoint_set_.Find((*i)) == disjoint_set_.Find(real_first)) {
  			++id18;
  			continue;
  		}
  		adj_[real_second].PB(disjoint_set_.Find(*i));
  	}
  	adj_[real_first].clear();
  	return;
}

template <class cInType>
void id13::MoveData(cInType* input_graph) {
  	if (!id7) Simplify();
  	

  	(*input_graph) = cInType(Size());
  	FORN(i,SZ(adj_)) FORIT(j, adj_[i]) input_graph->AddEdge(id16[i], id16[*j]);
}

void id13::Simplify() {
	id7 = 1;

  	

  	FORN(i,SZ(adj_)) FORIT(j, adj_[i]) *j = disjoint_set_.Find(*j);

  	

  	FORN(i,SZ(adj_)) {
  		int org = SZ(adj_[i]);
  		adj_[i].erase(remove_if(ALL(adj_[i]), bind1st(equal_to<int>(), i)), adj_[i].end());
  		id18 += org - SZ(adj_[i]);
  	}

  	

  	vector<int> active_nodes;
  	FORN(i,SZ(adj_)) if (disjoint_set_.Find(i) == i) active_nodes.PB(i);
  	vector<int> tmp_map = id4(active_nodes);
  	id16 = vector<int>(SZ(adj_));
  	FORN(i,SZ(active_nodes)) id16[active_nodes[i]] = tmp_map[i];
  	FORN(i,SZ(adj_)) id16[i] = id16[disjoint_set_.Find(i)];
}




















vector<int> id8(id10* graph, bool should_merge) {

	stack<int> urutan;
	id6 ds(graph->Size());
	stack< pair<int,int> > ngurut;
	vector<int> sudah(graph->Size(), 0);
	vector<int> id0(graph->Size(), 0);
	for (int i = 0;i < graph->Size();i++) {
		if (sudah[i]) continue;
		urutan.push(i);
		ngurut.push(make_pair(i,0));
		id0[i] = 1;
		sudah[i] = 1;
		while (!ngurut.empty()) {
			int id = ngurut.top().first;
			int val = ngurut.top().second;
			ngurut.pop();
			if (val == (int)graph->adj_[id].size()) {
				while (!urutan.empty() && urutan.top() == id) urutan.pop();
				id0[ds.Find(id)] = 0;
				if (!urutan.empty()) id0[ds.Find(urutan.top())] = 1;
				continue;
				}
			ngurut.push(make_pair(id,val + 1));

			int next = graph->adj_[id][val];
			if (sudah[next] && !id0[ds.Find(next)]) continue;
			if (!sudah[next]) {
				sudah[next] = 1;
				urutan.push(next);
				ngurut.push(make_pair(next,0));
				id0[next] = 1;
				continue;
				}
			if (ds.Find(id) == ds.Find(next)) continue;
			while (!urutan.empty() && ds.Find(urutan.top()) != ds.Find(next)) {
				ds.Merge(urutan.top(), next);
				urutan.pop();
				}
			id0[ds.Find(id)] = 1;
			}
		}
	vector<int> ret(graph->Size());
  	FORN(i, graph->Size()) ret[i] = ds.Find(i);

  	if (should_merge) {
   	 	id13* mwg = dynamic_cast<id13* >(graph);
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
  id9,
  id12,
  id3,
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

  id10* ug = new id10(n);

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

  vector<int> components = id8(ug, 0);

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
      int id17 = fri[i];
      while (id17 != i) {
        cyc.PB(id17);
        id17 = fri[id17];
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
          actfrom[j+1][zero][0] = id3;
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
            actfrom[j+1][newzero][0] = id9;
          }

        }

        

        if (j == SZ(cyc)-1 && zero) {
          valtes = val + getCost(cyc[j], cyc[0]) + treeSolve(cyc[j], 1);
          if (valtes > cycdp[j+1][0][0]) {
            cycdp[j+1][0][0] = valtes;
            from[j+1][0][0] = ini;
            actfrom[j+1][0][0] = id12;
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
        if (actfrom[l1][l2][l3] == id3) {
          treeBt(cyc[prev.A], 0);
        } else {
          treeBt(cyc[prev.A], 1);

          if (actfrom[l1][l2][l3] == id9) {
            ret.PB(MP(cyc[prev.A-1]+1, cyc[l1-1]+1));
          } else if (actfrom[l1][l2][l3] == id12) {
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
