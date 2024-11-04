







using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;










const long long INF = 1e18;
const int INFINT = INT_MAX/2;




















typedef long long ll;
typedef long double ld;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<int> vii;







template<typename T>
void __p(T a) {
	cout<<a;
}
template<typename T, typename F>
void __p(pair<T, F> a) {
	cout<<"{";
	__p(a.first);
	cout<<",";
	__p(a.second);
	cout<<"}";
}
template<typename T>
void __p(std::vector<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it<a.end(); it++)
		__p(*it),cout<<",}"[it+1==a.end()];
}
template<typename T>
void __p(std::set<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it);
		cout<<",}"[++it==a.end()];
	}

}
template<typename T>
void __p(std::multiset<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it);
		cout<<",}"[++it==a.end()];
	}
}
template<typename T, typename F>
void __p(std::map<T,F> a) {
	cout<<"{\n";
	for(auto it=a.begin(); it!=a.end();++it)
	{
		__p(it->first);
		cout << ": ";
		__p(it->second);
		cout<<"\n";
	}
	cout << "}\n";
}

template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
	__p(a1);
	__p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";
	__p(arg1);
	cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(;; i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	const char *comma=names+i;
	cout.write(names,comma-names)<<" : ";
	__p(arg1);
	cout<<" | ";
	__f(comma+1,args...);
}











struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id4 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id4);
    }
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());  


ll mod_exp(ll a, ll b, ll c)
{
	ll res=1;   a=a%c;
	while(b>0)
	{
		if(b%2==1)
			res=(res*a)%c;
		b/=2;
		a=(a*a)%c;
	}
	return res;
}
ll norm(ll a,ll b)
{
	return (((a = a%b) < 0) ? a + b : a);
}
ll id3(ll,ll,ll *,ll *);
ll modInverse(ll a, ll m)
{
		ll x, y;
		ll g = id3(a, m, &x, &y);
		g++; g--;  

		ll res = (x%m + m) % m;
		return res;
}
ll id3(ll a, ll b, ll *x, ll *y)
{
		if (a == 0)
		{
				*x = 0, *y = 1;
				return b;
		}
		ll x1, y1;
		ll gcd = id3(b%a, a, &x1, &y1);
		*x = y1 - (b/a) * x1;
		*y = x1;
		return gcd;
}

ll answer = 0;
vector<int> A;
vector<int> val;
int current_prime;
struct Graph {
	vector<vector<int>> adj;
	Graph(int n) {
		adj.resize(n+1);
	}
	void add_edge(int a, int b, bool directed = false) {
		adj[a].pb(b);
		if(!directed) adj[b].pb(a);
	}
};

int final_ans=0;


struct WeightedGraph {
	vector<vector<pair<int, int>>> adj;
	vector<int> subtree, lvl;
	vector<ll> subtree_sum;
	int N;
	WeightedGraph(int n) {
		N = n;
		adj.resize(n+1);
		subtree.resize(n+1);
		subtree_sum.resize(n+1);
		lvl.resize(n+1);
	}
	void add_edge(int a, int b, int c, bool directed = false) {
		adj[a].push_back({b, c});
		if(!directed) adj[b].push_back({a, c});
	}
	void dfs(int x, int par = -1){
		subtree[x] = (val[x] % current_prime == 0 ? 1 : 0);
		subtree_sum[x] = (val[x] % current_prime == 0 ? lvl[x] : 0);
		for(auto &p: adj[x]) {
			int to = p.first; int wt = p.second;
			if(to != par) {
				lvl[to] = lvl[x] + wt;
				dfs(to, x);
				subtree[x] += subtree[to];
				subtree_sum[x] += subtree_sum[to];
			}
		}
	}


	void dfs2(int x, int par ,int upar_sum,int upar_num) {
		bool isvalid = (val[x] % current_prime == 0);

		int id8=0;

		for(auto i:adj[x])
		{
			if(i.first!=par)
			{
				id8+=subtree[i.first]*(subtree[i.first]-1)/2;

				int sum=subtree_sum[x]-subtree_sum[i.first];

				int num=subtree[x]-subtree[i.first];

				if(isvalid)
				{
					sum-=lvl[x];
					num--;
				}

				sum-=lvl[x]*num;
				dfs2(i.first,x,upar_sum+upar_num*i.second+sum+(num+isvalid)*i.second,upar_num+num+isvalid);
			}
		}

		if(isvalid)
		{
			int id2=subtree[x];
			int id1=subtree_sum[x];
			id2--;
			id1-=lvl[x];
			id1-=lvl[x]*id2;

			final_ans+=upar_sum*id2;
			final_ans+=upar_num*id1;

			for(auto i:adj[x])
			{
				if(i.first==par)
					continue;
				int id6=subtree[i.first];
				int id5=subtree_sum[i.first];
				id5-=id6*lvl[x];
				final_ans+=id5*(id2-id6);
			}
		}

		


			


		int tot_num=subtree[x]-isvalid;

		final_ans+=upar_sum*((tot_num*(tot_num-1))/2-id8);




		for(auto i:adj[x])
		{
			if(i.first==par)
				continue;

			int id0=(tot_num-subtree[i.first]);
			id8-=(subtree[i.first]*(subtree[i.first]-1))/2;

			int id6=subtree[i.first];
			int id5=subtree_sum[i.first];
			id5-=id6*lvl[x];

			final_ans+=id5*((id0*(id0-1))/2-id8);

			id8+=(subtree[i.first]*(subtree[i.first]-1))/2;

			final_ans+=(upar_num*(id5)*id0);

		}


	}

};

struct LCA
{
	vll tin, tout, level;
	vector<vll> up;
	ll timer;
	void _dfs(vector<vector<int>> &adj, ll x, ll par=-1)
	{
		up[x][0] = par;
		REP(i, 1, 20)
		{
			if(up[x][i-1] == -1) break;
			up[x][i] = up[up[x][i-1]][i-1];
		}
		tin[x] = ++timer;
		for(auto &p: adj[x])
		{
			if(p != par)
			{
				level[p] = level[x]+1; 	_dfs(adj, p, x);
			}
		}
		tout[x] = ++timer;
	}
	LCA(Graph &G, ll root)
	{
		int n = G.adj.size();
		tin.resize(n); tout.resize(n); up.resize(n, vll(20, -1)); level.resize(n, 0);
		timer = 0;

		

		_dfs(G.adj, root);
	}
	ll find_kth(ll x, ll k)
	{
		ll cur = x;
		REP(i, 0, 20)
		{
			if((k>>i)&1) cur = up[cur][i];
			if(cur == -1) break;
		}
		return cur;
	}
	bool is_ancestor(ll x, ll y)
	{
		return tin[x]<=tin[y]&&tout[x]>=tout[y];
	}
	ll find_lca(ll x, ll y)
	{
		if(is_ancestor(x, y)) return x;
		if(is_ancestor(y, x)) return y;
		ll best = x;
		REPd(i, 19, 0)
		{
			if(up[x][i] == -1) continue;
			else if(is_ancestor(up[x][i], y)) best = up[x][i];
			else x = up[x][i];
		}
		return best;
	}
	ll dist(ll a, ll b)
	{
		return level[a] + level[b] - 2*level[find_lca(a, b)];
	}
};

struct VirtualTreeConstructor {
	Graph *tree;
	LCA *L;
	vector<int> tin_to_node, tout_to_node;
	bool all_processed = false;
	int count_processed = 0;
	vector<vector<int>> orders;
	vector<int> mapping;
	void process(Graph &G, int root = 1) {
		tree = &G;
		L = new LCA(G, root);
		int N = G.adj.size()-1;
		mapping.resize(N+5, -1);
		tin_to_node.resize(2*N+5); tout_to_node.resize(2*N+5);
		for(int i=1; i<=N; i++) {
			tin_to_node[L->tin[i]] = i;
			tout_to_node[L->tout[i]] = i;
		}
	}
	void process_all_queries(vector<vector<int>> &queries) {			

		orders.clear();
		all_processed = true;

		int Q = queries.size();
		count_processed = Q;
		orders.resize(Q);
		int N = tree->adj.size()-1;
		vector<vector<int>> appearances(2*N+5);			


		for(int idx = 0; idx < Q; ++idx) {
			for(int i=0; i<queries[idx].size(); i++) {
				appearances[L->tin[queries[idx][i]]].push_back(idx);
				

				

				

			}
		}

		for(int i=0; i<2*N+5; i++) {
			if(appearances[i].size()) {
				for(auto &x: appearances[i]) {
					orders[x].push_back(tin_to_node[i]);
				}
			}
		}

		for(int idx = 0; idx < Q; ++idx) {
			int X = orders[idx].size();
			for(int j=1; j<X; j++) {
				appearances[L->tin[L->find_lca(orders[idx][j], orders[idx][j-1])]].push_back(idx);
			}
			orders[idx].clear();
		}

		vector<int> id7(Q, -1);
		for(int i=0; i<2*N+5; i++) {
			if(appearances[i].size()) {
				for(auto &x: appearances[i]) {
					if(id7[x] != i) {
						orders[x].push_back(tin_to_node[i]);
						id7[x] = i;
					}
				}
			}
		}
	}
	WeightedGraph get(int i) {							

		if(i >= count_processed || !all_processed) {
			

			assert(false);
		}
		int sz = orders[i].size();
		WeightedGraph virtualTree(sz);
		for(int j=1; j<=sz; j++) {
			mapping[orders[i][j-1]] = j;		

			val[j] = A[orders[i][j-1]];
		}
		stack<int> st;
		for(int j=0; j<sz; j++) {
			while(!st.empty() && !L->is_ancestor(st.top(), orders[i][j])) {
				st.pop();
			}
			if(!st.empty()) {
				ll dist = abs(L->level[st.top()] - L->level[orders[i][j]]);
				virtualTree.add_edge(mapping[st.top()], mapping[orders[i][j]], dist);
			}
			st.push(orders[i][j]);
		}
		return virtualTree;
	}
	

	

	

};


const int MAXN = 2e5+5;
vector<vector<int>> facs(MAXN);
void pre() {
	vector<bool> isprime(MAXN,true);
	isprime[1] = false;
	for(int i=2; i<MAXN; i++) {
		if(isprime[i]) {
			for(int j=i; j<MAXN; j+=i) {
				isprime[j]= false;
				facs[j].pb(i);
			}
		}
	}
}

signed main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pre();
	signed N;
	cin >> N;
	A.resize(N+5);
	val.resize(N+5);
	vector<vector<int>> queries(MAXN);
	for(int i = 1; i <= N; i++) {
		signed x;
		cin>>x;
		A[i] = x;
		for(auto &x: facs[A[i]]){
			queries[x].push_back(i);
		}
	}

	Graph G(N);
	for(int i=1; i<N; i++) {
		signed a, b;
		cin >> a >> b;
		G.add_edge(a,b);
	}

	vector<vector<int>> actual_queries;
	vector<int> who;
	int cur = 0;
	for(auto &x: queries) {
		if(x.size()) {
			actual_queries.push_back(x);
			who.push_back(cur);
		}
		++cur;
	}
	VirtualTreeConstructor VTC;
	VTC.process(G,1);
	VTC.process_all_queries(actual_queries);


	for(int i=0; i< actual_queries.size(); i++){
		WeightedGraph virtualTree = VTC.get(i);
		current_prime = who[i];
		

		

		

		

		

		

		

		

		

		

		

		virtualTree.dfs(1);
		virtualTree.dfs2(1,0,0,0);
	}

	const int mod = 998244353;
	cout<<(signed)(final_ans%mod);

    return 0;
}
