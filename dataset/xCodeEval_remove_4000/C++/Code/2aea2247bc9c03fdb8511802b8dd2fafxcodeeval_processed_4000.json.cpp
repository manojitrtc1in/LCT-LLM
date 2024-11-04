























using namespace std;


























































































































































template<class T> inline void Qmin(T &a, const T b) {if (b < a) a = b;}
template<class T> inline void Qmax(T &a, const T b) {if (a < b) a = b;} 


const int inf = 0x3f3f3f3f; 

const long long llinf = 0x3f3f3f3f3f3f3f3fLL; 

const double pi = acos(-1.0);















































typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p2;
typedef pair<pair<int, int>, int> p3;
typedef pair<int, pair<int, int> > pi3;
typedef vector<int>::iterator viter;
typedef set<int>::iterator siter;
typedef map<int, int>::iterator miter;
typedef multiset<int>::iterator msiter;
typedef multimap<int, int>::iterator mmter;
typedef priority_queue<int> pq;
typedef priority_queue<int, vector<int>, greater<int> > spq; 

















inline int Qceil(int x, int y) {return x ? (x - 1) / y + 1 : 0;} 

inline double round(double x) {return x > 0.0 ? floor(x + 0.5) : ceil(x - 0.5);}


























int cas;
const int mx = 1e5 + 5;

char s[mx];

struct Trie
{
	int node[mx][26], sz;

	Trie() {mem(node, 0), sz = 0;}

	void read(int n) {int i; For(i, n) SS(s), insert(s);}

	void insert(char *s) {for (int i = 0, u = 0, *v; s[i]; u = *v, ++i) if (!*(v = &node[u][s[i] - 'a'])) *v = ++sz;}

	int dfs(int u = 0)
	{
		bool isleaf = true;
		int ans = 0, i;
		For(i, 26) if (node[u][i]) isleaf = false, ans |= dfs(node[u][i]) ^ 3;
		return isleaf ? 1 : ans;
	}
} trie;

int main()
{
	int n, k, i;
	SII(n, k);
	trie.read(n);
	int ans = trie.dfs();
	puts(ans == 3 || ans == 2 && k & 1 ? "First" : "Second");
	return 0;
}
