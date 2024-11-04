

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>



#include <iterator>


#include <string>
#include <stdexcept>

#ifndef SPCPPL_ASSERT
	#ifdef SPCPPL_DEBUG
		#define SPCPPL_ASSERT(condition) \
		if(!(condition)) { \
			throw std::runtime_error(std::string() + #condition + " in line " + std::to_string(__LINE__) + " in " + __PRETTY_FUNCTION__); \
		}
	#else
		#define SPCPPL_ASSERT(condition)
	#endif
#endif



template <typename T>
class IntegerIterator {
public:
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using pointer = T*;
	using reference = T;
	using iterator_category = std::input_iterator_tag;

	explicit IntegerIterator(T value): value(value) {

	}

	IntegerIterator& operator++() {
		++value;
		return *this;
	}

	IntegerIterator operator++(int) {
		IntegerIterator copy = *this;
		++value;
		return copy;
	}

	IntegerIterator& operator--() {
		--value;
		return *this;
	}

	IntegerIterator operator--(int) {
		IntegerIterator copy = *this;
		--value;
		return copy;
	}

	T operator*() const {
		return value;
	}

	bool operator==(IntegerIterator rhs) const {
		return value == rhs.value;
	}

	bool operator!=(IntegerIterator rhs) const {
		return !(*this == rhs);
	}

private:
	T value;
};

template <typename T>
class IntegerRange {
public:
	IntegerRange(T begin, T end): begin_(begin), end_(end) {
		SPCPPL_ASSERT(begin <= end);
	}

	IntegerIterator<T> begin() const {
		return IntegerIterator<T>(begin_);
	}

	IntegerIterator<T> end() const {
		return IntegerIterator<T>(end_);
	}

private:
	T begin_;
	T end_;
};

template <typename T>
class ReversedIntegerRange {
	using IteratorType = std::reverse_iterator<IntegerIterator<T>>;
public:
	ReversedIntegerRange(T begin, T end): begin_(begin), end_(end) {
		SPCPPL_ASSERT(begin >= end);
	}

	IteratorType begin() const {
		return IteratorType(IntegerIterator<T>(begin_));
	}

	IteratorType end() const {
		return IteratorType(IntegerIterator<T>(end_));
	}

private:
	T begin_;
	T end_;
};

template <typename T>
IntegerRange<T> range(T to) {
	return IntegerRange<T>(0, to);
}

template <typename T>
IntegerRange<T> range(T from, T to) {
	return IntegerRange<T>(from, to);
}

template <typename T>
IntegerRange<T> inclusiveRange(T to) {
	return IntegerRange<T>(0, to + 1);
}

template <typename T>
IntegerRange<T> inclusiveRange(T from, T to) {
	return IntegerRange<T>(from, to + 1);
}

template <typename T>
ReversedIntegerRange<T> downrange(T from) {
	return ReversedIntegerRange<T>(from, 0);
}

template <typename T>
ReversedIntegerRange<T> downrange(T from, T to) {
	return ReversedIntegerRange<T>(from, to);
}

template <typename T>
ReversedIntegerRange<T> inclusiveDownrange(T from) {
	return ReversedIntegerRange<T>(from + 1, 0);
}

template <typename T>
ReversedIntegerRange<T> inclusiveDownrange(T from, T to) {
	return ReversedIntegerRange<T>(from + 1, to);
}



#include <random>


namespace impl {
using Random = std::mt19937;
}  


inline impl::Random& randomEngine() {
	static std::random_device device;
	static impl::Random engine(device());
	return engine;
}

inline int randomInteger() {
	std::uniform_int_distribution<int> d;
	return d(randomEngine());
}

inline int randomInteger(int to) {
	SPCPPL_ASSERT(to > 0);
	std::uniform_int_distribution<int> d(0, to - 1);
	return d(randomEngine());
}

inline int randomInteger(int from, int to) {
	return from + randomInteger(to - from);
}


using int64 = int64_t;

using std::vector;
using std::set;
using std::map;
using std::string;
using std::pair;
using std::make_pair;
using std::sort;
using std::unique;
using std::swap;
using std::min;
using std::max;
using std::endl;
using std::nullopt;







#include <vector>
#include <functional>

using namespace std;

#define all(v) (v).begin(), (v).end()

using ll = long long;
using ull = unsigned long long;
using li = __int128;
using uli = unsigned __int128;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

#ifdef LOCAL
void signalHandler(int) {
    throw "Abort detected";
}
#endif

void doReplace() {
}

template <typename T, typename U, typename...Vs>
void doReplace(T& t, const U& u, Vs&&...vs) {
    t = u;
    doReplace(vs...);
}

template <typename T, typename...Us>
T minim(T& was, const T& cand, Us&&...us) {
    if (was > cand) {
        was = cand;
        doReplace(us...);
    }
    return was;
}

template <typename T, typename...Us>
T maxim(T& was, const T& cand, Us&&...us) {
    if (was < cand) {
        was = cand;
        doReplace(us...);
    }
    return was;
}


class BiEdge {
private:
    BiEdge* transposedEdge;

public:
    const int from;
    const int to;
    int id;

    BiEdge(int from, int to) : from(from), to(to) {
        transposedEdge = new BiEdge(this);
    }

    BiEdge* transposed() { return transposedEdge; }
    BiEdge* reverse() { return nullptr; }

private:
    BiEdge(BiEdge* transposed) : from(transposed->to), to(transposed->from) {
        transposedEdge = transposed;
    }
};






template <class Edge>
class Graph {
public:
    int vertexCount;
    int edgeCount = 0;
private:
    vector<basic_string<Edge*>> edges;

public:
    Graph(int vertexCount) : vertexCount(vertexCount), edges(vertexCount, basic_string<Edge*>()) {}

    void addEdge(Edge* edge) {
#ifdef LOCAL
        if (edge->from < 0 || edge->to < 0 || edge->from >= vertexCount || edge->to >= vertexCount) {
            throw "Out of bounds";
        }
#endif
        edge->id = edgeCount;
        edges[edge->from].push_back(edge);
        Edge* reverse = edge->reverse();
        if (reverse != nullptr) {
            reverse->id = edgeCount;
            edges[reverse->from].push_back(reverse);
        }
        Edge* transposed = edge->transposed();
        if (transposed != nullptr) {
            edges[transposed->from].push_back(transposed);
            transposed->id = edgeCount;
            Edge* transRev = transposed->reverse();
            if (transRev != nullptr) {
                edges[transRev->from].push_back(transRev);
                transRev->id = edgeCount;
            }
        }
        edgeCount++;
    }

    template <typename...Ts>
    void addEdge(Ts...args) {
        addEdge(new Edge(args...));
    }

    basic_string<Edge*>& operator [](int at) {
        return edges[at];
    }

    void addVertices(int count) {
        vertexCount += count;
        edges.resize(vertexCount);
    }
};












#include <algorithm>


class NumberIterator : iterator<forward_iterator_tag, int> {
public:
    int v;

    NumberIterator(int v) : v(v) {}

    operator int &() { return v; }

    int operator*() { return v; }
};

class range : pii {
public:
    range(int begin, int end) : pii(begin, max(begin, end)) {}

    range(int n) : pii(0, max(0, n)) {}

    NumberIterator begin() {
        return first;
    }

    NumberIterator end() {
        return second;
    }
};


template <typename T>
class arr {
    T* b;
    int n;

    void allocate(int sz) {
#ifdef LOCAL
        if (sz < 0) {
            throw "bad alloc";
        }
#endif
        n = sz;
        if (sz > 0) {
            b = (T*)(::operator new(sz * sizeof(T)));
        } else {
            b = nullptr;
        }
    }

public:
    arr(int n = 0) {
        allocate(n);
#ifdef LOCAL
        view();
#endif
    }

    arr(int n, const T& init) {
        allocate(n);
        for (int i : range(n)) {
            ::new((void*)(b + i)) T(init);
        }
#ifdef LOCAL
        view();
#endif
    }

    arr(initializer_list<T> l) : arr(l.size()) {
        if (n > 0) {
            memcpy(b, l.begin(), n * sizeof(T));
        }
    }

    arr(T* b, int n) : arr(b, b + n) {}
    arr(T* b, T* e) : b(b), n(e - b) {}

    int size() const {
        return n;
    }

    T* begin() {
        return b;
    }

    const T* begin() const {
        return b;
    }

    T* end() {
        return b + n;
    }

    const T* end() const {
        return b + n;
    }

    arr<T> clone() const {
        arr<T> res(n);
        copy(b, b + n, res.begin());
        return res;
    }

    T& operator[](int at) {
#ifdef LOCAL
        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }
#endif
        return b[at];
    }

    const T& operator[](int at) const {
#ifdef LOCAL
        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }
#endif
        return b[at];
    }

    bool operator ==(const arr& other) const {
        if (n != other.n) {
            return false;
        }
        for (int i : range(n)) {
            if (b[i] != other.b[i]) {
                return false;
            }
        }
        return true;
    }

    vector<T> view() {
        return vector<T>(b, b + min(n, 50));
    }
};

typedef arr<int> arri;

void decreaseByOne() {}

template <typename T, class...Vs>
void decreaseByOne(arr<T>& array, Vs&...vs) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        array[i]--;
    }
    decreaseByOne(vs...);
}

template <typename T, typename U>
void decreaseByOne(arr<pair<T, U>>& v) {
    for (auto& p : v) {
        p.first--;
        p.second--;
    }
}


template<typename Value, typename Delta>
class SegmentTree {
    const int size;
public:
    Value defaultValue;
private:
    const Delta defaultDelta;
    function<Value(Value, Value)> joinValue;
    function<Delta(Delta, Delta)> joinDelta;
    function<Value(Value, Delta, int, int)> accumulate;
    arr<Value> value;
    arr<Delta> delta;

    void init(int root, int left, int right) {
        if (left + 1 == right) {
            value[root] = defaultValue;
        } else {
            int mid = (left + right) >> 1;
            init(2 * root + 1, left, mid);
            init(2 * root + 2, mid, right);
            value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
        }
    }

    void apply(int root, Delta dlt, int left, int right) {
        value[root] = accumulate(value[root], dlt, left, right);
        delta[root] = joinDelta(delta[root], dlt);
    }

    void pushDown(int root, int left, int mid, int right) {
        apply(2 * root + 1, delta[root], left, mid);
        apply(2 * root + 2, delta[root], mid, right);
        delta[root] = defaultDelta;
    }

    void update(int root, int left, int right, int from, int to, Delta dlt) {
        if (left >= from && right <= to) {
            apply(root, dlt, left, right);
            return;
        }
        if (right <= from || left >= to) {
            return;
        }
        int mid = (left + right) >> 1;
        pushDown(root, left, mid, right);
        update(2 * root + 1, left, mid, from, to, dlt);
        update(2 * root + 2, mid, right, from, to, dlt);
        value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
    }

    Value query(int root, int left, int right, int from, int to) {
        if (left >= from && right <= to) {
            return value[root];
        }
        if (right <= from || left >= to) {
            return defaultValue;
        }
        int mid = (left + right) >> 1;
        pushDown(root, left, mid, right);
        return joinValue(query(2 * root + 1, left, mid, from, to), query(2 * root + 2, mid, right, from, to));
    }

public:
    SegmentTree(int size, function<Value(Value, Value)> joinValue,
                function<Delta(Delta, Delta)> joinDelta,
                function<Value(Value, Delta, int, int)> accumulate,
                Value defaultValue = 0, Delta defaultDelta = 0 ) :
                size(size), joinValue(joinValue), joinDelta(joinDelta), accumulate(accumulate),
                defaultValue(defaultValue), defaultDelta(defaultDelta) {
        int vertexSize = size * 4;
        value = arr<Value>(vertexSize);
        delta = arr<Delta>(vertexSize, defaultDelta);
        if (size > 0) {
            init(0, 0, size);
        }
    }

    void update(int from, int to, Delta delta) {
        update(0, 0, size, max(0, from), to, delta);
    }

    Value query(int from, int to) {
        return query(0, 0, size, max(0, from), to);
    }
};






const int DX_KNIGHT[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int DY_KNIGHT[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int DX4[] = {1, 0, -1, 0};
const int DY4[] = {0, 1, 0, -1};
const int DX8[] = {1, 1, 1, 0, -1, -1, -1, 0};
const int DY8[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool isValidCell(int r, int c, int n, int m) {
    return r >= 0 && c >= 0 && r < n && c < m;
}






template <typename T>
class arr2d {
    T* b;
    int d1;
    int d2;
    int sz;

    void allocate(int n) {
#ifdef LOCAL
        if (n < 0) {
            throw "bad alloc";
        }
#endif
        if (n > 0) {
            b = (T*)(::operator new(n * sizeof(T)));
        } else {
            b = nullptr;
        }
    }

public:
    arr2d(int d1 = 0, int d2 = 0) : d1(d1), d2(d2), sz(d1 * d2) {
#ifdef LOCAL
        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }
#endif
        allocate(sz);
#ifdef LOCAL
        view();
#endif
    }

    arr2d(int d1, int d2, const T& init) : d1(d1), d2(d2), sz(d1 * d2) {
#ifdef LOCAL
        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }
#endif
        allocate(sz);
        for (int i : range(sz)) {
            ::new((void*)(b + i)) T(init);
        }
#ifdef LOCAL
        view();
#endif
    }

    arr2d(T* b, int d1, int d2) : b(b), d1(d1), d2(d2), sz(d1 * d2) {}

    int size() const {
        return sz;
    }

    int dim1() const {
        return d1;
    }

    int dim2() const {
        return d2;
    }

    T* begin() {
        return b;
    }

    T* end() {
        return b + sz;
    }

    T& operator()(int i1, int i2) {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * d2 + i2];
    }

    const T& operator()(int i1, int i2) const {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * d2 + i2];
    }

    arr<T> operator[](int at) {
#ifdef LOCAL
        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }
#endif
        return arr<T>(b + at * d2, d2);
    }

    vector<vector<T>> view() {
        vector<vector<T>> res(min(d1, 50));
        for (int i = 0; i < res.size(); ++i) {
            res[i] = (*this)[i].view();
        }
        return res;
    }

    arr2d<T> clone() {
        arr2d<T> res(d1, d2);
        copy(b, b + sz, res.b);
        return res;
    }
};






inline bool isSubset(int set, int subSet) {
    return (set & subSet) == subSet;
}

inline int bitCount(int x) {
    return __builtin_popcount(x);
}

inline int bitCount(ll x) {
    return __builtin_popcountll(x);
}

inline int highestOneBit(int x) {
    return 1 << (31 - __builtin_clz(x | 1));
}

inline int binaryDigits(int x) {
    return 32 - __builtin_clz(x | 1);
}

inline ll setBit(ll mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 64) {
        throw "Bad index";
    }
#endif
    mask |= 1ll << bit;
    return mask;
}

inline int setBit(int mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 32) {
        throw "Bad index";
    }
#endif
    mask |= 1 << bit;
    return mask;
}

inline ll unsetBit(ll mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 64) {
        throw "Bad index";
    }
#endif
    mask &= ~(1ll << bit);
    return mask;
}

inline int unsetBit(int mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 32) {
        throw "Bad index";
    }
#endif
    mask &= ~(1 << bit);
    return mask;
}

inline bool isSet(ll mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 64) {
        throw "Bad index";
    }
#endif
    return mask >> bit & 1;
}

inline bool isSet(int mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 32) {
        throw "Bad index";
    }
#endif
    return mask >> bit & 1;
}


class LCA {
private:
    arri order;
    arri position;
    arr2d<int> lcaArr;

    int getMin(int a, int b) const {
        if (level[a] < level[b]) {
            return a;
        }
        return b;
    }

public:
    arri level;
    arri parent;

    template <class Edge>
    LCA(Graph<Edge>& graph, int root = 0) {
        int vertexCount = graph.vertexCount;
        order = arri(2 * vertexCount - 1);
        position = arri(vertexCount, -1);
        level = arri(vertexCount);
        level[root] = 0;
        arri index(vertexCount, 0);
        parent = arri(vertexCount);
        arri& last = parent;
        arri stack(vertexCount);
        stack[0] = root;
        int size = 1;
        int j = 0;
        last[root] = -1;
        while (size > 0) {
            int vertex = stack[--size];
            if (position[vertex] == -1) {
                position[vertex] = j;
            }
            order[j++] = vertex;
            if (last[vertex] != -1) {
                level[vertex] = level[last[vertex]] + 1;
            }
            while (index[vertex] < graph[vertex].size() && last[vertex] == graph[vertex][index[vertex]]->to) {
                index[vertex]++;
            }
            if (index[vertex] < graph[vertex].size()) {
                stack[size++] = vertex;
                int to = graph[vertex][index[vertex]]->to;
                stack[size++] = graph[vertex][index[vertex]]->to;
                last[to] = vertex;
                index[vertex]++;
            }
        }
        lcaArr = arr2d<int>(binaryDigits(2 * vertexCount - 1), 2 * vertexCount - 1);
        for (int i : range(2 * vertexCount - 1)) {
            lcaArr(0, i) = order[i];
        }
        for (int i : range(1, lcaArr.dim1())) {
            for (int j : range(2 * vertexCount - 1)) {
                if (j + (1 << (i - 1)) < 2 * vertexCount - 1) {
                    lcaArr(i, j) = getMin(lcaArr(i - 1, j), lcaArr(i - 1, j + (1 << (i - 1))));
                } else {
                    lcaArr(i, j) = lcaArr(i - 1, j);
                }
            }
        }
    }

    int lca(int first, int second) const {
        int from = min(position[first], position[second]);
        int to = max(position[first], position[second]);
        int lv = binaryDigits(to - from) - 1;
        return getMin(lcaArr(lv, from), lcaArr(lv, to + 1 - (1 << lv)));
    }

    int pathLength(int first, int second) const {
        return level[first] + level[second] - 2 * level[lcaArr(first, second)];
    }
};


class ETreeQueries {
public:
	static void solveSlow(std::stringstream& in, std::ostream& out) {
	}
	static constexpr int kStressIterations = 0;
	static void generateTest(std::ostringstream& in, std::ostringstream& ___) {
		auto _____ = std::stringstream(in.str());
		solveSlow(_____, ___);
	}
	static void solve(std::istream& in, std::ostream& out) {
		int n, m; in >> n >> m;
		Graph<BiEdge> graph(n);
		for (int i : range(n - 1)) {
			int u, v; in >> u >> v; u--, v--;
			graph.addEdge(BiEdge(u, v));
		}
		LCA lca(graph);
		for (int query_index : range(m)) {
			int k; in >> k;
			vector<int> a(k); for (auto& val : a) in >> val, val--;
			

			vector<pair<int, int>> parents(k);
			for (int i : range(a.size())) {
				parents[i].first = max(0, lca.parent[a[i]]);
				parents[i].second = lca.level[parents[i].first];
			}
			sort(parents.begin(), parents.end(), [] (const pair<int, int>& left, const pair<int, int>& right) {
				return left.second < right.second;
			});
			bool ok = true;
			for (int i = 0; i + 1 < parents.size(); i++) {
				int top = parents[i].first;
				int bottom = parents[i + 1].first;
				if (lca.lca(top, bottom) != top) ok = false;
			}
			out << (ok ? "YES" : "NO") << endl;
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	ETreeQueries solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	solver.solve(in, out);
	return 0;
}
