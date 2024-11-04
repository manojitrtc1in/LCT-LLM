
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <stdint.h>
#include <set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <string>
#include <cmath>
#include <queue>
#include <iterator>
#include <iomanip>
#include <numeric>


 
#include <random>
#include <functional>




 
 
using namespace std;
 
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define forn(i, n) for(int i = 0; i < int(n); i++)
 
template <class T>
vector<T> ReadVec(const int count, const T inc = 0)
{
	vector<T> res(count);
	forn(i, count)
	{
		std::cin >> res[i];
		res[i] += inc;
	}
	return res;
}
 
template <class T>
void PrintVecOneLine(const vector<T>& src)
{
	forn(i, src.size())
	{
		std::cout << src[i];
		if (i + 1 != src.size())
			std::cout << " ";
	}
	std::cout << "\n";
}
 
template <class T>
void PrintVecManyLine(const vector<T>& src)
{
	forn(i, src.size())
	{
		std::cout << src[i] << "\n";
	}
}
 
std::vector<std::vector<int>> BuildGraph(int n,int m, bool oriented, int inc = 1)
{
	std::vector<std::vector<int>> res(n);
	forn(i, m)
	{
		int a, b;
		std::cin >> a >> b;
		res[a - inc].push_back(b - inc);
		if (oriented)
			continue;

		res[b - inc].push_back(a - inc);
	}
	return res;
}
 
std::vector<std::vector<int>> BuildGraph(
	int n,int m, bool oriented, std::vector<int64_t>& weight, int inc = 1)
{
	std::vector<std::vector<int>> res(n);
	weight.resize(m);
	forn(i, m)
	{
		int a, b;
		std::cin >> a >> b >> weight[i];
		res[a - inc].push_back(b - inc);
		if (oriented)
			continue;
		res[b - inc].push_back(a - inc);
	}
	return res;
}


namespace dmDataStructure
{

struct dmMin
{

	template<class T>
	T operator()(const T a, const T b)
	{
		return std::min(a, b);
	}
};

struct dmMax
{
	template<class T>
	T operator()(const T a, const T b)
	{
		return std::max(a, b);
	}
};

struct dmMinPaired
{
	template<class T>
	std::pair<T, int> operator()(const std::pair<T, int>& a, const std::pair<T, int>& b)
	{
		if (a.first < b.first)
			return a;
		if (a.first > b.first)
			return b;
		return std::make_pair(a.first, b.second + a.second);
	}
};

struct dmMaxPaired
{
	template<class T>
	std::pair<T, int> operator()(const std::pair<T, int>& a, const std::pair<T, int>& b)
	{
		if (a.first > b.first)
			return a;
		if (a.first < b.first)
			return b;
		return std::make_pair(a.first, b.second + a.second);
	}
};
 
int GetBitNumber(std::int64_t n)
{
	if (n == 0)
		return 0;

	int msb = 0;
	n = n / 2;
	while (n != 0) {
		n = n / 2;
		msb++;
	}
	return msb;
}

template <class T1, class T2>
T1 GetValue(const std::pair<T1, T2>& pr)
{
	return pr.first;
}

template <class T>
T GetValue(const T& v)
{
	return v;
}

template <class T1, class T2, class T3>
void SetValue(std::pair<T1, T2>& src, const T3 val, const std::int64_t number = 0)
{
	src.first = val;
	if (number == 0)
		return;
	src.second = number;
}

template <class T1, class T2>
void SetValue(T1& src, const T2 value, const std::int64_t number = 0)
{
	number;
	src = value;
}

template <class T, class T1>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type MakeType(const T1& src)
{
	return T(src);
}
template <class T, class T1>
typename std::enable_if<!std::is_arithmetic<T>::value, T>::type MakeType(const T1& src)
{
	return T(src, 1);
}

template <
	class T,
	const T zeroValue,
	class F,
	const bool isLazy = false,
	const bool isIncrement = true,
	const bool usePair = false>
class dmSegmentTree
{
public:
	typedef typename std::conditional<usePair, std::pair<T, int>, T>::type DataType;
	dmSegmentTree(const size_t n)
		: m_objectCount(n), m_tree(n * 2, zeroValue), m_lazyData(), m_isSum(false)
	{
		if (isLazy)
		{
			m_lazyData.resize(n, 0);
			m_modified.resize(n, false);
		}
		m_isSum = GetValue(DataType()) == zeroValue;
		m_height = GetBitNumber(n) + 1;
	}

	dmSegmentTree(const std::vector<T>& objects)
		: m_objectCount(objects.size()), m_tree(objects.size() * 2, MakeType<DataType>(zeroValue)), m_lazyData(), m_isSum(false)
	{
		if (isLazy)
		{
			m_lazyData.resize(objects.size(), MakeType<DataType>(0));
			m_modified.resize(objects.size(), false);
		}
		m_isSum = GetValue(DataType()) == zeroValue;
		m_height = GetBitNumber(objects.size()) + 1;
		Build(objects);
	}

	void Build(const std::vector<T>& objects)
	{
		for (size_t i = objects.size(); i < m_tree.size(); ++i)
		{
			m_tree[i] = MakeType<DataType>(objects[i - objects.size()]);
		}
		for (std::int64_t i = objects.size() - 1; i > 0; --i)
		{
			m_tree[i] = m_f(m_tree[i * 2], m_tree[i * 2 + 1]);
		}
	}

	void CalcLazy(const std::int64_t idx, const std::int64_t elementCount)
	{
		if (!m_modified[idx])
		{
			m_tree[idx] = m_f(m_tree[idx * 2], m_tree[idx * 2 + 1]);
		}
		else
		{
			if (isIncrement)
			{
				if (m_isSum)
				{

					m_tree[idx] = m_f(m_tree[idx * 2], m_tree[idx * 2 + 1]);
					SetValue(m_tree[idx], GetValue(m_tree[idx]) + GetValue(m_lazyData[idx]) * elementCount);
				}
				else
				{
					m_tree[idx] = m_f(m_tree[idx * 2], m_tree[idx * 2 + 1]);
					SetValue(m_tree[idx], GetValue(m_tree[idx]) + GetValue(m_lazyData[idx]));
				}
			}
			else
			{
				if (m_isSum)
				{
					SetValue(m_tree[idx], GetValue(m_lazyData[idx]) * elementCount, elementCount);
				}
				else
				{
					SetValue(m_tree[idx], GetValue(m_lazyData[idx]), elementCount);
				}
			}
		}
	}

	void ApplyLazy(const std::int64_t idx,
		const DataType value, const std::int64_t elementCount)
	{
		if (isIncrement)
		{
			if (m_isSum)
			{
				SetValue(m_tree[idx], GetValue(m_tree[idx]) + GetValue(value) * elementCount);

			}
			else
			{
				SetValue(m_tree[idx], GetValue(m_tree[idx]) + GetValue(value));
			}
		}
		else
		{
			if (m_isSum)
			{
				SetValue(m_tree[idx], GetValue(value) * elementCount);
			}
			else
			{
				SetValue(m_tree[idx], GetValue(value), elementCount);
			}
		}
		if (idx < m_objectCount)
		{
			if (isIncrement)
			{
				SetValue(m_lazyData[idx], GetValue(m_lazyData[idx]) + GetValue(value));
			}
			else
			{
				SetValue(m_lazyData[idx], GetValue(value), elementCount);
			}
			m_modified[idx] = true;
		}
	}

	void BuildLazy(const std::int64_t left, const std::int64_t right) {
		std::int64_t elementCount = 2;

		std::int64_t l = left + m_objectCount;
		std::int64_t r = right + m_objectCount;
		for (; l > 1; elementCount *= 2)
		{
			l = l / 2;
			r = r / 2;
			for (std::int64_t i = r; i >= l; --i)
			{
				CalcLazy(i, elementCount);
			}
		}
	}


	void PushLazy(const std::int64_t left, const std::int64_t right)
	{
		std::int64_t layer = m_height;
		std::int64_t elementCount = 1 << (m_height - 1);
		std::int64_t l = left + m_objectCount;
		std::int64_t r = right + m_objectCount;
		for (; layer > 0; --layer, elementCount /= 2)
		{
			for (std::int64_t i = l >> layer; i <= r >> layer; ++i)
			{
				if (m_modified[i])
				{
					ApplyLazy(i * 2, m_lazyData[i], elementCount);
					ApplyLazy(i * 2 + 1, m_lazyData[i], elementCount);
					SetValue(m_lazyData[i], 0);
					m_modified[i] = false;
				}
			}
		}
	}

	void Modify(const int idx, const DataType& value)
	{
		if (isLazy)
			throw std::exception("function available only in usual mod");
		std::int64_t cur = m_objectCount + idx;
		if (isIncrement)
		{
			m_tree[cur] += value;
		}
		else
		{
			m_tree[cur] = value;
		}
		
		std::int64_t parent = cur / 2;
		while (parent != 0)
		{
			const std::int64_t nextToCur = cur % 2 == 0 ? cur + 1 : cur - 1;
			m_tree[parent] = m_f(m_tree[cur], m_tree[nextToCur]);
			cur = parent;
			parent = cur / 2;
		}
	}


	void ModifyLazy(
		const std::int64_t left, const std::int64_t right, const T& value)
	{
		if (!isLazy)
			throw std::exception("function available only in lazy mod");
		PushLazy(left, left);
		PushLazy(right, right);
		std::int64_t l0 = left, r0 = right, k = 1;

		std::int64_t l = m_objectCount + left;
		std::int64_t r = m_objectCount + right;

		for (; l <= r; l = (l + 1) / 2, r = (r - 1) / 2)
		{
			if (l % 2 != 0)
			{
				ApplyLazy(l, MakeType<DataType>(value), k);
			}
			if (r % 2 == 0)
			{
				ApplyLazy(r, MakeType<DataType>(value), k);
			}
			k = k * 2;
		}
		BuildLazy(l0, l0);
		BuildLazy(r0, r0);
	}

	DataType Query(const std::int64_t left, const std::int64_t right)
	{
		if (isLazy)
			throw std::exception("function available only in usual mod");
		std::int64_t l = left + m_objectCount;
		std::int64_t r = right + m_objectCount;
		DataType resL = MakeType<DataType>(zeroValue);
		DataType resR = MakeType<DataType>(zeroValue);
		if (left == right)
			return m_tree[l];
		for (; l <= r; l = (l + 1) / 2, r = (r - 1) / 2)
		{
			if (l % 2 != 0)
			{
				resL = m_f(resL, m_tree[l]);
			}
			if (r % 2 == 0)
			{
				resR = m_f(m_tree[r], resR);
			}
		}
		return m_f(resL, resR);
	}

	DataType QueryLazy(const std::int64_t left, const std::int64_t right)
	{
		if (!isLazy)
			throw std::exception("function available only in lazy mod");
		PushLazy(left, left);
		PushLazy(right, right);
		std::int64_t l = left + m_objectCount;
		std::int64_t r = right + m_objectCount;
		DataType resL = MakeType<DataType>(zeroValue);
		DataType resR = MakeType<DataType>(zeroValue);
		if (left == right)
			return m_tree[l];
		for (; l <= r; l = (l + 1) / 2, r = (r - 1) / 2)
		{
			if (l % 2 != 0)
			{
				resL = m_f(resL, m_tree[l]);
			}
			if (r % 2 == 0)
			{
				resR = m_f(m_tree[r], resR);
			}
		}
		return m_f(resL, resR);
	}

private:
	std::vector<DataType> m_tree;
	std::vector<DataType> m_lazyData;
	std::vector<bool> m_modified;
	F m_f;
	bool m_isSum;
	std::int64_t m_height;
	std::int64_t m_objectCount;
};

}
namespace dmDataStructure
{

template <const size_t alphabetSize, class StrType>
class dmAchoCorasic
{

struct Node
{
	Node()
	{
		std::fill(child.begin(), child.end(), -1);
	}
	std::array<int, alphabetSize> child;
	int link = 0;
	int count = 0;
	int wordIdx = -1;
	int endWord = -1;
	bool isLeaf = false;
};

public:
	dmAchoCorasic(
		const std::vector<StrType>& words,
		const std::function<int(const typename StrType::value_type)>& getValue)
		: m_nodes(1, Node()), m_wordCount(0), m_getValue(getValue)
	{
		for (int i = 0; i < words.size(); ++i)
		{
			Add(words[i], i);
		}
		UpdateSuffixLinks();
	}

	dmAchoCorasic(const std::function<int(const typename StrType::value_type)>& getValue)
		: m_nodes(1, Node()), m_wordCount(0), m_getValue(getValue)
	{
	}

	std::vector<std::vector<int>> GetSuffixGraphRepresentation() const
	{
		std::vector<std::vector<int>> result(m_nodes.size());
		for (int i = 1; i < int(m_nodes.size()); i++)
		{
			result[m_nodes[i].link].push_back(i);
		}
		return result;
	}

	void Add(const StrType& src, const int wordIdx = -1)
	{
		int currentNode = 0;
		for (const auto& symbol : src)
		{
			const int symbolId = m_getValue(symbol);
			if (m_nodes[currentNode].child[symbolId] == -1)
			{
				m_nodes[currentNode].child[symbolId] = int(m_nodes.size());
				m_nodes.push_back(Node());
			}
			currentNode = m_nodes[currentNode].child[symbolId];
		}
		m_nodes[currentNode].count++;
		m_nodes[currentNode].isLeaf = true;
		if (m_nodes[currentNode].wordIdx < 0)
		{
			m_nodes[currentNode].wordIdx = wordIdx < 0 ? m_wordCount : wordIdx;
		}
		++m_wordCount;
	}

	int GetTotalMatchesCount(const StrType& text) const
	{
		int matches = 0;
		int current = 0;
		for (const auto& symbol : text)
		{
			current = GetLink(current, symbol);
			matches += m_nodes[current].count;
		}
		return matches;
	}

	std::vector<int> GetMatchesCountPerWord(const StrType& src) const
	{
		std::vector<int> matches(m_wordCount, 0);
		int current = 0;
		for (const auto& symbol : src) {
			current = GetLink(current, symbol);
			const int nodeEnd = m_nodes[current].isLeaf
				? current : m_nodes[current].endWord;
			if (nodeEnd >= 0)
				matches[m_nodes[nodeEnd].wordIdx]++;
		}
		return matches;
	}

	std::vector<int> GetMatchesCountByPos(const StrType& text) const
	{
		std::vector<int> matches(text.size());
		int current = 0;
		int idx = 0;
		for (auto c : text)
		{
			current = GetLink(current, c);
			matches[idx++] = m_nodes[current].count;
		}
		return matches;
	}

	int GetVertexId(const StrType& src)
	{
		int currentNode = 0;
		for (const auto& symbol : src)
		{
			const int symbolId = m_getValue(symbol);
			currentNode = m_nodes[currentNode].child[symbolId];
		}
		return currentNode;
	}

	int GetLink(int curLink, const typename StrType::value_type symbol) const
	{
		return GetLinkById(curLink, m_getValue(symbol));
	}

private:

	int GetLinkById(int curLink, const int symbolId) const
	{
		int result = 0;
		for (result = m_nodes[curLink].child[symbolId];
			curLink >= 0 && result < 0;
			result = curLink < 0 ? result : m_nodes[curLink].child[symbolId])
		{
			curLink = m_nodes[curLink].link;
		}
		return curLink < 0 ? 0 : result;
	}


	void UpdateSuffixLinks()
	{
		std::queue<int> que;
		que.push(0);
		m_nodes[0].link = -1;
		while (!que.empty())
		{
			const int pos = que.front();
			que.pop();
			for (int i = 0; i < alphabetSize; ++i)
			{
				if (m_nodes[pos].child[i] == -1)
					continue;
				int next = m_nodes[pos].link;
				while (next != -1 && m_nodes[next].child[i] == -1)
				{
					next = m_nodes[next].link;
				}
				if (next == -1)
				{
					m_nodes[m_nodes[pos].child[i]].link = 0;
				}
				else
				{
					const int child = m_nodes[pos].child[i];
					m_nodes[child].link = m_nodes[next].child[i];
					m_nodes[child].count += m_nodes[m_nodes[child].link].count;
				}
				que.push(m_nodes[pos].child[i]);
			}
			Node& cur = m_nodes[pos];
			const Node& link = m_nodes[cur.link < 0 ? 0 : cur.link];
			cur.endWord = link.isLeaf ? cur.link : link.endWord;
		}
	}

	std::vector<Node> m_nodes;
	int m_wordCount;
	std::function<int(const typename StrType::value_type)> m_getValue;
};

}

namespace dmDataStructure
{

template <class T, const T zeroValue, class SegmentTree, class FuncType>
class dmHeavyLightDecomposition
{
public:
	dmHeavyLightDecomposition(const size_t vertexCount)
		: m_graph(vertexCount),
		m_depth(vertexCount, 0),
		m_parent(vertexCount, -1),
		m_top(vertexCount, -1),
		m_weight(vertexCount, 0),
		m_heavyPathValues(vertexCount, SegmentTree(1))
	{
	}

	void AddEdge(const int from, const int to)
	{
		m_graph[from].push_back(to);
	}

	void Dfs(int node, int par)
	{
		m_parent[node] = par;
		m_depth[node] = par < 0 ? 0 : m_depth[par] + 1;
		m_weight[node] = 1;
		for (int child : m_graph[node])
		{
			Dfs(child, node);
			m_weight[node] += m_weight[child];
		}
		sort(m_graph[node].begin(), m_graph[node].end(), [&](int a, int b) {
			return m_weight[a] > m_weight[b];
			});
	}

	void CreateChainsDfs(int node, const bool heavy)
	{
		m_top[node] = heavy ? m_top[m_parent[node]] : node;
		m_weight[m_top[node]]++;
		for (int i = 0; i < m_graph[node].size(); ++i)
		{
			CreateChainsDfs(m_graph[node][i], i == 0);
		}
	}

	void Build()
	{
		m_parent.resize(m_graph.size(), -1);
		for (int i = 0; i < m_graph.size(); ++i)
		{
			if (m_parent[i] >= 0)
				continue;
			Dfs(i, -1);
			CreateChainsDfs(i, false);
		}
		for (int i = 0; i < m_graph.size(); ++i)
		{
			if (m_top[i] != i)
				continue;
			m_heavyPathValues[i] = SegmentTree(m_weight[i]);
		}
	}

	template<typename Operation>
	void Process(int u, int v, const Operation&& operation) {
		while (m_top[u] != m_top[v]) {
			if (m_depth[m_top[u]] > m_depth[m_top[v]])
			{
				swap(u, v);
			}
			const int root = m_top[v];
			operation(m_heavyPathValues[root], 0, m_depth[v] - m_depth[root]);
			v = m_parent[root];
		}

		if (m_depth[u] > m_depth[v])
			swap(u, v);
		const int root = m_top[v];
		operation(m_heavyPathValues[root],
			m_depth[u] - m_depth[root],
			m_depth[v] - m_depth[root]);
	}

	T Query(const int u, const int v)
	{
		T answer = zeroValue;
		Process(u, v, [&](SegmentTree& tree, const int a, const int b) {
			answer = m_operator(answer, tree.Query(a, b));
			});

		return answer;
	}

	void Modify(const int u, const int v, const T value) {
		Process(u, v, [&](SegmentTree& tree, const int a, const int b) {
			tree.Modify(a, value);
			});
	}

	std::vector< std::vector<int> > m_graph;
	std::vector<SegmentTree> m_heavyPathValues;
	std::vector<int> m_depth;
	std::vector<int> m_parent;
	std::vector<int> m_top;
	std::vector<int> m_weight;
	FuncType m_operator;
};

}

int main()
{
#ifdef HOME
	freopen("input.txt", "r", stdin);
#else
	std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cout.setf(std::ios::fixed); std::cout.precision(20);
#endif
	int64_t n, q;
	cin >> n >> q;
	vector<string> words;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		words.push_back(s);
	}
	dmDataStructure::dmAchoCorasic<26, string > achoc(words, [](const char src) { return int(src - 'a'); });
	auto graph = achoc.GetSuffixGraphRepresentation();
	const int infm = std::numeric_limits<int>::min() / 2;
	typedef dmDataStructure::dmSegmentTree<int, infm, dmDataStructure::dmMax, false, false, false> sTree;
	dmDataStructure::dmHeavyLightDecomposition<int, infm, sTree, dmDataStructure::dmMax> HLD(graph.size());

	for (int i = 0; i < graph.size(); ++i)
		for (int child : graph[i])
			HLD.AddEdge(i, child);
	HLD.Build();
	std::vector<int> wordIdxToVertexMap(words.size());
	std::vector<multiset<int, std::greater<int>>> vertexValue(graph.size());
	for (int i = 0; i < words.size(); ++i)
	{
		const int vertex = achoc.GetVertexId(words[i]);
		wordIdxToVertexMap[i] = vertex;
		HLD.Modify(vertex, vertex, 0);
		vertexValue[vertex].insert(0);
	}
	vector<int> values(words.size(), 0);
	for (int i =0; i < q; ++i)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int idx, value;
			cin >> idx >> value;
			int node = wordIdxToVertexMap[idx - 1];

			auto found = vertexValue[node].find(values[idx - 1]);
			if (found != vertexValue[node].end())
				vertexValue[node].erase(found);
			vertexValue[node].insert(value);
			HLD.Modify(node, node, *vertexValue[node].begin());
			values[idx - 1] = value;
		}
		else
		{
			string query;
			cin >> query;
			int current = 0, answer = -1;
			for (auto& ch : query) {
				current = achoc.GetLink(current, ch);
				answer = max(answer, HLD.Query(current, 0));
			}
			cout << answer << '\n';
		}
	}
	
	return 0;
}