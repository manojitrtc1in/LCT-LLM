




























using namespace std;






typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll MOD = 1000000007LL;
enum class START_OPTION { NOTHING = 0, FILE_INPUT = 1, FILE_OUTPUT = (1 << 1), FILE_OUTHERE = (1 << 2) };
inline START_OPTION operator| (START_OPTION a, START_OPTION b)
{
	return static_cast<START_OPTION>(static_cast<int>(a) | static_cast<int>(b));
}
inline int operator& (START_OPTION a, START_OPTION b)
{
	return static_cast<int>(a) & static_cast<int>(b);
}
template<typename T1, typename T2> istream& operator>> (istream&i, pair<T1, T2>&p)
{
	i >> p.first >> p.second;
	return i;
}
template<typename T1, typename T2> ostream& operator<< (ostream&i, pair<T1, T2>&p)
{
	i << p.first << " " << p.second;
	return i;
}
template<typename T>istream& operator>> (istream&i, vector<T>&v)
{
	for (auto&e : v)i >> e;
	return i;
}
template<typename T>ostream& operator<< (ostream&i, vector<T>&v)
{
	i << v.size() << endl;
	for (auto&e : v)i << e << " ";
	i << endl;
	return i;
}
void id2(int n, int w, vector<vector<int> >&v)
{
	v = vector<vector<int> >(n + 1LL);
	while (w--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}
bool id3(char x)
{
	return x == 'a' || x == 'e' || x == 'o' || x == 'u' || x == 'i';
}
bool id4(char x)
{
	return !id3(x);
}
void _start(START_OPTION opt = START_OPTION::NOTHING, string fileIn = "input.txt", string fileOut = "output.txt")
{

	if (opt & START_OPTION::FILE_INPUT)  freopen(fileIn.c_str(), "r", stdin);
	if (opt & START_OPTION::FILE_OUTPUT) freopen(fileOut.c_str(), "w", stdout);

	if ((opt & START_OPTION::FILE_OUTHERE) && (opt & START_OPTION::FILE_INPUT))  freopen(fileIn.c_str(), "r", stdin);
	if ((opt & START_OPTION::FILE_OUTHERE) && (opt & START_OPTION::FILE_OUTPUT)) freopen(fileOut.c_str(), "w", stdout);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin.tie(0);
}
template<typename T = string> void _end(T out = "", int returnValue = 0)
{
	cin.sync_with_stdio(1);
	cout.sync_with_stdio(1);
	cout << out;

	cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;

	exit(returnValue);
}


template<typename T>class SegmentTree
{
private:
	vector<T> tree, //Segment tree 
		mem_add,//Data for pushing adding
		mem_change;  //Data for pushing changing
	vector<bool> id6; //Data to find out is there pushing changing
	int n;			//Array size
	string string_f; //String name for binary function(max, min, sum)

					 //Calculate max or min or sum
	T  f(T a, T b)
	{
		if (string_f == "max")
			return a > b ? a : b;
		else if (string_f == "min")
			return a < b ? a : b;
		else if (string_f == "sum")
			return a + b;
		else throw("segment tree has wrong func");
	}
	//Push data of mem_add down
	void push_add(int idx)
	{
		if (mem_add[idx] == 0) return;
		tree[idx] += mem_add[idx];
		if (mem_add.size() > idx << 1) mem_add[idx << 1] += mem_add[idx];
		if (mem_add.size() > (idx << 1) + 1) mem_add[(idx << 1) + 1] += mem_add[idx];
		mem_add[idx] = 0;
	}
	//Push data of mem_change down
	void push_change(int idx)
	{
		if (!id6[idx]) return;
		tree[idx] = mem_change[idx];
		if (mem_change.size() > idx << 1) mem_change[idx << 1] = mem_change[idx];
		if (mem_change.size() > (idx << 1) + 1) mem_add[(idx << 1) + 1] = mem_change[idx];
		id6[idx] = 0;
	}
	//Default vals for every f
	T val_default()
	{
		if (string_f == "sum") return 0;
		if (string_f == "max") return -INT_INFINITY;
		if (string_f == "min") return INT_INFINITY;
	}
public:
	//Query to change element of array
	T changePos(int pos, T val, int tl = 0, int tr = -1, int idx = 1)
	{
		if (tr == -1) tr += n;

		push_add(idx);
		push_change(idx);
		if (tl == tr)
			return tree[idx] = val;
		int m = (tl + tr) >> 1;
		if (pos <= m)
			return tree[idx] = f(changePos(pos, val, tl, m, idx << 1), tree[(idx << 1) + 1]);
		else return tree[idx] = f(changePos(pos, val, m + 1, tr, (idx << 1) + 1), tree[idx << 1]);
	}
	//Query to increase element of array
	T incPos(int pos, T val, int tl = 0, int tr = -1, int idx = 1)
	{
		if (tr == -1) tr += n;

		push_add(idx);
		push_change(idx);
		if (tl == tr)
		{
			tree[idx] += val;
			return tree[idx];
		}
		int m = (tl + tr) >> 1;
		if (pos <= m)
			return tree[idx] = f(incPos(pos, val, tl, m, idx << 1), tree[(idx << 1) + 1]);
		else return tree[idx] = f(incPos(pos, val, m + 1, tr, (idx << 1) + 1), tree[idx << 1]);
	}
	//Query to get f on segment l-r
	T get(int l, int r, int tl = 0, int tr = -1, int idx = 1)
	{
		if (tr == -1) tr += n;

		push_add(idx);
		push_change(idx);
		if (tl > r || tr < l)
			return val_default();
		int m = (tl + tr) >> 1;
		if (tl >= l && tr <= r)
			return tree[idx];
		return f(get(l, r, tl, m, idx << 1), get(l, r, m + 1, tr, (idx << 1) + 1));
	}
	//Query to change all elements on segment l-r
	T changeSegment(int l, int r, T val, int tl = 0, int tr = -1, int idx = 1)
	{
		if (tr == -1) tr += n;

		push_add(idx);
		push_change(idx);
		if (tl > r || tr < l)
			return tree[idx];
		int m = (tl + tr) >> 1;
		if (tl >= l && tr <= r)
		{
			mem_change[idx] = val;
			id6[idx] = true;
			push_change(idx);
			return tree[idx];
		}
		else return tree[idx] = f(incSegment(l, r, val, tl, m, idx << 1), incSegment(l, r, val, m + 1, tr, (idx << 1) + 1));
	}
	//Query to increase all elements on segment l-r
	T incSegment(int l, int r, T val, int tl = 0, int tr = -1, int idx = 1)
	{
		if (tr == -1) tr += n;

		push_add(idx);
		push_change(idx);
		if (tl > r || tr < l)
			return tree[idx];
		int m = (tl + tr) >> 1;
		if (tl >= l && tr <= r)
		{
			mem_add[idx] = val;
			push_add(idx);
			return tree[idx];
		}
		else return tree[idx] = f(incSegment(l, r, val, tl, m, idx << 1), incSegment(l, r, val, m + 1, tr, (idx << 1) + 1));
	}
	//constructor
	SegmentTree(const vector<T> &mas, const string &string_f, bool emptyArr = 0)
	{
		this->string_f = string_f;
		n = mas.size();
		tree = mem_add = mem_change = vector<T>(n << 2);
		id6 = vector<bool>(n << 2);
		if (!emptyArr)
			for (int i = 0; i < n; i++)
				changePos(i, mas[i]);
	}
	SegmentTree() {}
};
class LCA
{
private:
	vector<int> tin, //Time in of vertex
		tout; //Time out of vertex
	vector<vector<int> > ancs; //1, 2, 4, and so on ancestors list for every vertex 
							   //LCA Preprocessing
	int timer = 1;
	void LCA_prep(const vector<vector<int> > &tree, int v, vector<int> &ancestors, int prev = -1)
	{
		tin[v] = timer++;
		int start = 0LL;
		while (start < ancestors.size())
		{
			ancs[v].push_back(ancestors[ancestors.size() - start - 1LL]);
			start = ((start + 1LL) << 1LL) - 1LL;
		}
		ancestors.push_back(v);
		for (auto&i : tree[v])
			if (i != prev)
				LCA_prep(tree, i, ancestors, v);
		ancestors.pop_back();
		tout[v] = timer++;
	}
public:
	bool isParent(int v1, int v2)
	{
		if (tin[v1] > tin[v2] && tout[v1] < tout[v2]) return 1;
		return 0;
	}
	//constructor
	LCA(const vector<vector<int> > &tree, int v) : tin(tree.size()), tout(tree.size()), ancs(tree.size())
	{
		vector<int> trash;
		LCA_prep(tree, v, trash);
	}
	//Query to get LCA for 2 vertices
	int get(int v1, int v2)
	{
		if (v1 == v2) return v1;
		if (isParent(v1, v2)) return v2;
		if (isParent(v2, v1)) return v1;
		int start = -1;
		for (; start < int(ancs[v1].size() - 1LL) && !isParent(ancs[v1][start + 1LL], v2) && !isParent(v2, ancs[v1][start + 1LL]); start++);
		if (start != -1)
			v1 = ancs[v1][start];
		else return ancs[v1][0];

		if (v1 == v2) return v1;
		start = -1LL;
		for (; start < int(ancs[v2].size() - 1LL) && !isParent(ancs[v2][start + 1LL], v1) && !isParent(v1, ancs[v2][start + 1LL]); start++);
		if (start != -1LL)
			v2 = ancs[v2][start];
		else return ancs[v2][0];

		return get(v1, v2);
	}
};
template<typename T>class id5
{
private:
	vector<vector<int> > tree, //tree itself
		ways; //decomposed tree
	vector<int> sizes, //sizes of subtrees
		depth, //depth of vertices
		myWay, //Way number for each vertex
		myPos; //position of vertex in it's way
	map<pair<int, int>, bool> heavy; 

	vector<SegmentTree<T>> seg_trees; 

	LCA lca; 

	string string_f; 


					 

	T  f(T a, T b)
	{
		if (string_f == "max")
			return a > b ? a : b;
		else if (string_f == "min")
			return a < b ? a : b;
		else if (string_f == "sum")
			return a + b;
		else throw("segment tree has wrong func");
	}
	

	int HeavyDfs(int v = 1, int d = 1, int prev = 0)
	{
		depth[v] = d;
		int c = 1;
		for (auto&i : tree[v])
			if (i != prev)
				c += HeavyDfs(i, d + 1LL, v);
		for (auto&i : tree[v])
			if (i != prev && sizes[i] >= (c + 1LL) / 2LL)
				heavy[make_pair(v, i)] = true;
		return sizes[v] = c;
	}
	

	int make_ways(int v = 1, int prev = 0)
	{
		int res = 0;
		for (auto&i : tree[v])
		{
			if (i != prev)
			{
				int w = make_ways(i, v);
				ways[w].push_back(v);
				if (heavy[make_pair(v, i)])
				{
					res = w;
					myWay[v] = w;
					myPos[v] = ways[w].size() - 1LL;
				}
			}
		}
		if (res == 0)
		{
			res = v;
			myWay[v] = v;
			myPos[v] = 0LL;
			ways[v].push_back(res);
		}
		return res;
	}
	

	void createSegs()
	{
		for (ll i = 0LL; i < seg_trees.size(); i++)
			if (ways[i].size())
				seg_trees[i] = SegmentTree<T>(vector<T>(ways[i].size()), string_f, true);
	}

public:
	vector<int> vals; 

					  

	int get(int a, int b, int lca = -1)
	{
		if (lca == -1) lca = this->lca.get(a, b);

		int res = 0LL;
		SegmentTree<T> &aSeg = seg_trees[myWay[a]],
			&bSeg = seg_trees[myWay[b]];
		int  id0 = ways[myWay[a]].size() - 1LL,
			id1 = ways[myWay[b]].size() - 1LL,
			aEnd = ways[myWay[a]].back(),
			bEnd = ways[myWay[b]].back();

		if (depth[a] >= depth[lca])
			if (depth[ways[myWay[a]].back()] >= depth[lca])
			{
				res = f(res, aSeg.get(myPos[a], id0 - 1));
				a = aEnd;
			}
			else
			{
				res = f(res, aSeg.get(myPos[a], myPos[lca] - 1));
				a = lca;
			}

		if (depth[b] >= depth[lca])
			if (depth[ways[myWay[b]].back()] >= depth[lca])
			{
				res = f(res, bSeg.get(myPos[b], id1 - 1));
				b = bEnd;
			}
			else
			{
				res = f(res, bSeg.get(myPos[b], myPos[lca] - 1));
				b = lca;
			}

		if (depth[b] <= depth[lca] && depth[a] <= depth[lca])
			return f(vals[lca], res);
		return f(res, get(a, b, lca));
	}
	

	void changeVertex(int v, T val)
	{
		vals[v] = val;
		seg_trees[myWay[v]].changePos(myPos[v], vals[v]);
	}
	

	void incVertex(int v, T val)
	{
		vals[v] += val;
		seg_trees[myWay[v]].incPos(myPos[v], val);
	}

	

	id5(const vector<vector<int> > &t, string string_f) :
		lca(t, 1), seg_trees(vector<SegmentTree<T>>(t.size() + 1)),
		tree(t), ways(t.size() + 1), string_f(string_f)
	{
		sizes = depth = vals = myWay = myPos = vector<int>(t.size() + 1LL);
		HeavyDfs(); make_ways(); createSegs();
	}
};

ll n, k;
ll cl = 1, cr;
void find(ll l, ll r)
{
	if (cr - cl < 50LL)
	{
		return;
	}
	ll m = (l + r) / 2LL;
	cout << l << " " << m << endl;
	

	string s; cin >> s;
	if (s == "Yes")
	{
		cl = max(1LL, l - k - 1LL);
		cr = min(n, m + k + 1);

		find(cl, cr);
	}
	else if (s == "No")
	{
		cl = max(1LL, m + 1LL - k - 1LL);
		cr = min(n, r + k + 1LL);

		find(cl, cr);
	}
	else _end("", -1);
}
int main()
{
	_start(

		   );
	cin >> n >> k;
	cr = n;
	std::random_device device;
	std::mt19937 generator(0xDEADBEFF + 1208 + 3 << 7 + 0xAAA + 2312321);
	std::uniform_int_distribution<ll> distribution(1, n);

	while (1)
	{
		find(cl, cr);
		ll rm = distribution(generator);
		cout << rm % (cr - cl + 1) + cl << " " << rm % (cr - cl + 1) + cl << endl;
		

		string s; cin >> s;
		if (s == "Yes")
			_end();
		else if (s == "Bad")
			_end("", -1);

		cl = max(1LL, cl - 21LL);
		cr = min(n, cr + 21LL);
	}
	_end();
}