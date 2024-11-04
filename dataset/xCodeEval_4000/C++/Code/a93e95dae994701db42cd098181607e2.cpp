#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define RFORS(i,s,n) for(int i=(n)-1; i>=s;--i)
#define FOR(i,n) FORS(i,0,(n))
#define RFOR(i,n) RFORS(i,0,(n))
#define FI(n) FOR(i,(n))
#define RFI(n) RFOR(i, (n))
#define MP(x,y) make_pair((x),(y))
#define PB(x) push_back((x))
#define SZ(c) int((c).size())
#define FOR_SETTED_BIT(bit, mask) for (int bit = 0; (mask) >> bit; ++bit) if (1&(mask >> bit))
#define FOR_NONZERO_SUBMASK(submask, mask) for (int submask=(mask); submask; submask=(submask-1)&(mask))

typedef long long ll; typedef unsigned long long ull; typedef long double ld; typedef pair<int, int> pii;  typedef pair<ll, ll> pll; typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vll;  typedef vector<ld> vld; typedef vector<ull> vull;  typedef vector<pii> vpii; typedef list<string> ls; typedef list <pii> lpii; typedef list<pll> lpll; typedef list<ll> lll; typedef set < int > si;
#ifndef __GNUG__
int __builtin_popcount(unsigned int x) { int result = 0; while (x) { result += x & 1; x >>= 1; }return result; } int __builtin_popcountll(unsigned long long x) { int result = 0; while (x) { result += x & 1; x >>= 1; }return result; }
#endif
#define popcount __builtin_popcountll
ll gcd(ll, ll, ll&, ll&); ll gcd(ll, ll); ll lcm(ll, ll);
template<class T>const T sqr(const T x) { return x*x; }
template<class T>const T binpow(const T &a, const ull n, const T &modulo) { return n == 0 ? 1 : sqr(binpow(a, n / 2, modulo)) % modulo * (n % 2 ? a : 1) % modulo; }
const long long binpow(const ll a, const ll n, const ll modulo) { return binpow<ll>(a, n, modulo); }
inline long long readInteger(const int = 10, FILE * = stdin);

template < class T, class Function >
class Fenwick
{
public:
	Fenwick(int size, T value = T()) : tree(vector<T>(size, value)) {}
	T query(int right) { T result = T(); for (; right >= 0; right = f(right) - 1) { result = function(result, tree[right]); } return result; }
	void update(int index, T delta) { for (; index < (int)tree.size(); index = h(index)) { tree[index] = function(tree[index], delta); } }
private:
	static inline int f(int x) { return x & (x + 1); };
	static inline int h(int x) { return x | (x + 1); };
	Function function;
	vector<T> tree;
};

template < class T, class Flag, class ValuePushFunction, class ValueValueFunction, class PushPushFunction >
class SegmentTree
{
public:
	template < class InputIterator >
	SegmentTree(InputIterator first, InputIterator last, Flag defaultFlag = Flag()) : defaultFlag(defaultFlag), length(last - first), tree(vector < Node* >((last - first) << 2)) { build(root, 0, length - 1, first); }

	~SegmentTree() { for (Node *vertex : tree) { delete vertex; } }

	T query(int left, int right) { return query(root, 0, length - 1, left, right); }

	void update(int left, int right, const Flag &delta) { update(root, 0, length - 1, left, right, delta); }

private:
	static const int root = 1;
	const Flag defaultFlag;
	const int length;

	struct Node
	{
		T value;
		Flag push;

		Node(const T &value, const Flag &push) : value(value), push(push) {}
	};

	ValuePushFunction valuePushFunction;
	ValueValueFunction valueValueFunction;
	PushPushFunction pushPushFunction;

	vector<Node*> tree;

	template < class InputIterator >
	void build(int vertex, int vertexLeft, int vertexRight, InputIterator first)
	{
		if (vertexLeft == vertexRight)
		{
			tree[vertex] = new Node(first[vertexLeft], defaultFlag);
		}
		else
		{
			int vertexMiddle = (vertexLeft + vertexRight) >> 1;

			build(vertex << 1, vertexLeft, vertexMiddle, first);
			build((vertex << 1) + 1, vertexMiddle + 1, vertexRight, first);

			tree[vertex] = new Node(valueValueFunction(tree[vertex << 1]->value, tree[(vertex << 1) + 1]->value), defaultFlag);
		}
	}

	void push(int vertex)
	{
		if ((vertex << 1) < (int)tree.size())
		{
			tree[vertex << 1]->push = pushPushFunction(tree[vertex]->push, tree[vertex << 1]->push);
			tree[vertex << 1]->value = valuePushFunction(tree[vertex << 1]->value, tree[vertex]->push);
		}

		if ((vertex << 1) + 1 < (int)tree.size())
		{
			tree[(vertex << 1) + 1]->push = pushPushFunction(tree[vertex]->push, tree[(vertex << 1) + 1]->push);
			tree[(vertex << 1) + 1]->value = valuePushFunction(tree[(vertex << 1) + 1]->value, tree[vertex]->push);
		}

		tree[vertex]->push = defaultFlag;
	}

	T query(int vertex, int vertexLeft, int vertexRight, int left, int right)
	{
		if (vertexLeft == vertexRight)
		{
			return tree[vertex]->value;
		}

		int vertexMiddle = (vertexLeft + vertexRight) >> 1;

		push(vertex);

		if (right <= vertexMiddle)
		{
			return query(vertex << 1, vertexLeft, vertexMiddle, left, right);
		}

		if (left > vertexMiddle)
		{
			return query((vertex << 1) + 1, vertexMiddle + 1, vertexRight, left, right);
		}

		return
			valueValueFunction(
				query(vertex << 1, vertexLeft, vertexMiddle, left, vertexMiddle),
				query((vertex << 1) + 1, vertexMiddle + 1, vertexRight, vertexMiddle + 1, right)
				);
	}

	void update(int vertex, int vertexLeft, int vertexRight, int left, int right, const Flag &delta)
	{
		if (vertexLeft == vertexRight)
		{
			tree[vertex]->push = pushPushFunction(tree[vertex]->push, delta);
			tree[vertex]->value = valuePushFunction(tree[vertex]->value, delta);
		}
		else
		{
			push(vertex);

			int vertexMiddle = (vertexLeft + vertexRight) >> 1;

			if (right <= vertexMiddle)
			{
				update(vertex << 1, vertexLeft, vertexMiddle, left, right, delta);
			}
			else if (left > vertexMiddle)
			{
				update((vertex << 1) + 1, vertexMiddle + 1, vertexRight, left, right, delta);
			}
			else
			{
				update(vertex << 1, vertexLeft, vertexMiddle, left, vertexMiddle, delta);
				update((vertex << 1) + 1, vertexMiddle + 1, vertexRight, vertexMiddle + 1, right, delta);
			}

			tree[vertex]->value = valueValueFunction(tree[vertex << 1]->value, tree[(vertex << 1) + 1]->value);
		}
	}
};



template < class T >
class Treap
{
public:
	Treap() : root(NULL) {}

	template < class InputIterator >
	Treap(InputIterator first, InputIterator last) : Treap()
	{
		const size_t length = last - first;
		size_t* priorities = new size_t[length];
		for (size_t i = 0; i < length; ++i)
		{
			priorities[i] = i;
		}
		random_shuffle(priorities, priorities + length);
		for (size_t i = 0; i < length; ++i, ++first)
		{
			insert(i + 1, *first, priorities[i]);
		}
		delete[] priorities;
	}
	~Treap()
	{
		destroy(root);
	}

	
	void insert(size_t key, const T &value) { insert(key, value, rand()); }
	void erase(size_t key)
	{
		Node *left, *right, *middle;
		split(root, key, left, right);
		split(right, 2, middle, right);
		root = merge(left, right);
	}
	T& operator[](size_t key)
	{
		Node *left, *right, *middle;
		split(root, key, left, right);
		split(right, 2, middle, right);
		T &returnValue = middle->value;
		right = merge(middle, right);
		root = merge(left, right);
		return returnValue;
	}
	size_t size() const { return root ? root->size : 0; }

private:
	struct Node
	{
		T value;
		size_t priority;

		size_t size;
		Node *left, *right;

		Node(T value, size_t priority) : value(value), priority(priority), size(1), left(NULL), right(NULL) {}
	} *root;

	void insert(size_t key, const T &value, size_t priority)
	{
		Node *left, *right;
		split(root, key, left, right);

		Node *middle = new Node(value, priority);

		left = merge(left, middle);
		root = merge(left, right);
	}

	
	void split(Node* vertex, size_t key, Node* &left, Node* &right)
	{
		if (vertex)
		{
			size_t vertexKey = 1 + (vertex->left ? vertex->left->size : 0);
			if (vertexKey < key)
			{
				split(vertex->right, key - vertexKey, vertex->right, right);
				updateSize(vertex);
				left = vertex;
			}
			else
			{
				split(vertex->left, key, left, vertex->left);
				updateSize(vertex);
				right = vertex;
			}
		}
		else
		{
			left = right = NULL;
		}
	}

	Node* merge(Node *left, Node *right)
	{
		if (!left)
		{
			return right;
		}
		if (!right)
		{
			return left;
		}
		if (left->priority < right->priority)
		{
			left->right = merge(left->right, right);
			updateSize(left);
			return left;
		}
		else
		{
			right->left = merge(left, right->left);
			updateSize(right);
			return right;
		}
	}

	void updateSize(Node *vertex)
	{
		vertex->size = 1;
		if (vertex->left)
		{
			vertex->size += vertex->left->size;
		}
		if (vertex->right)
		{
			vertex->size += vertex->right->size;
		}
	}

	void destroy(Node *vertex)
	{
		if (vertex)
		{
			destroy(vertex->left);
			destroy(vertex->right);
			delete vertex;
		}
	}
};


template < const int ALPHA >
class Trie
{
public:
	void insert(int length, const int *s)
	{
		++_count;
		if (!length)
		{
			return;
		}
		if (!children[*s])
		{
			children[*s] = new Trie;
		}
		children[*s]->insert(length - 1, s + 1);
	}
	void erase(int length, const int *s)
	{
		--_count;
		if (!length)
		{
			return;
		}
		children[*s]->erase(length - 1, s + 1);
		if (!children[*s]->count)
		{
			delete children[*s];
			children[*s] = NULL;
		}
	}
	Trie() : _count(0) { memset(children, NULL, sizeof(children)); }
private:
	Trie *children[ALPHA];
	int _count;
};
template < class T1, class T2 >
inline pair<T1, T2> operator - (const pair<T1, T2> &a, const pair<T1, T2> &b) { return MP(a.first - b.first, a.second - b.second); }

const ll MODULO = (int)1e9 + 7;

vll factorial, reverseFactorial;

void initFactoreal(int n)
{
	factorial.resize(n + 1);
	reverseFactorial.resize(n + 1);

	factorial[0] = reverseFactorial[0] = 1;
	FORS(i, 1, n + 1)
	{
		factorial[i] = factorial[i - 1] * i % MODULO;
		reverseFactorial[i] = binpow(factorial[i], MODULO - 2, MODULO);
	}
}

inline ll choose(ll n, ll k)
{
	return factorial[n] * reverseFactorial[n - k] % MODULO * reverseFactorial[k] % MODULO;
}

inline ll paths(const pii &from, const pii &to)
{
	const pii v = to - from;
	return v.first >= 0 && v.second >= 0 ? choose(v.first + v.second, v.first) : 0;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m, k, s;
	while (~scanf("%d%d%d%d", &n, &m, &k, &s))
	{
		vpii anomalies(k);
		FI(k)
		{
			scanf("%d%d", &anomalies[i].first, &anomalies[i].second);
		}

		initFactoreal(n + m);

		sort(ALL(anomalies), [](const pii &a, const pii &b) { return a.first + a.second < b.first + b.second; });

		anomalies.emplace(anomalies.begin(), 1, 1);

		vvi numberOfWays(SZ(anomalies), vi(SZ(anomalies)));

		ll p = 0, q = paths(MP(1, 1), MP(n, m));
		ll waysGivingOne = q;

		FOR(v, SZ(anomalies))
		{

			RFI(SZ(anomalies))
			{
				numberOfWays[v][i] = paths(anomalies[i], MP(n, m));
				FORS(j, i + 1, SZ(anomalies))
				{
					numberOfWays[v][i] = (numberOfWays[v][i] - paths(anomalies[i], anomalies[j]) * numberOfWays[v][j] % MODULO + MODULO) % MODULO;
				}

				FOR(j, v)
				{
					numberOfWays[v][i] = (numberOfWays[v][i] - numberOfWays[j][i] + MODULO) % MODULO;
				}
			}

			p = (p + (ll)numberOfWays[v][0] * s % MODULO) % MODULO;
			waysGivingOne = (waysGivingOne - numberOfWays[v][0] + MODULO) % MODULO;

			s = (s + 1) >> 1;
			if (1 == s)
			{
				break;
			}
		}

		p = (p + waysGivingOne * 1) % MODULO;

		printf("%d\n", p * binpow(q, MODULO - 2, MODULO) % MODULO);
	}
	return 0;
}


ll gcd(ll a, ll b, ll & x, ll & y)
{
	if (a == 0)
	{
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

ll gcd(ll a, ll b) { return gcd(a, b, a, b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


const int BUFFER_SIZE = 4096;
char buffer[BUFFER_SIZE], *buffer_begin, *buffer_end;

#define SKIP_NOT_DIGIT \
while (buffer_begin < buffer_end && !isdigit(*buffer_begin)) \
{ \
	sign = *buffer_begin == '-' ? -1 : 1; \
	++buffer_begin; \
}

#define REREAD_IF_NEEDED \
if (buffer_begin >= buffer_end) \
{ \
	buffer_begin = buffer; \
	buffer_end = buffer + fread(buffer, 1, BUFFER_SIZE, fh); \
}

#define READ_DIGITS \
while (buffer_begin < buffer_end && isdigit(*buffer_begin)) \
{ \
	x = x * BASE + *buffer_begin - '0'; \
	++buffer_begin; \
}

#define SKIP_WHITESPACES \
while (buffer_begin < buffer_end && iswspace(*buffer_begin)) \
{ \
	++buffer_begin; \
}


inline long long readInteger(const int BASE, FILE *fh)
{
	register long long x = 0;
	register int sign = 1;
	SKIP_NOT_DIGIT
		REREAD_IF_NEEDED
		SKIP_NOT_DIGIT
		READ_DIGITS
		REREAD_IF_NEEDED
		READ_DIGITS
		return sign * x;
}