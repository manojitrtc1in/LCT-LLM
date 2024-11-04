
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
 
 
namespace dmDataStructure
{
 
struct dmMin
{
	template<class T>
	T operator()(const T a, const T b) const
	{
		return std::min(a, b);
	}
};
 
struct dmMax
{
	template<class T>
	T operator()(const T a, const T b) const
	{
		return std::max(a, b);
	}
};
 
struct dmMinPaired
{
	template<class T>
	std::pair<T, int> operator()(const std::pair<T, int>& a, const std::pair<T, int>& b) const
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
	std::pair<T, int> operator()(const std::pair<T, int>& a, const std::pair<T, int>& b) const
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
		: m_objectCount(n),
		m_tree(n * 2, zeroValue),
		m_lazyData(),
		m_isSum(false)
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
		: m_objectCount(objects.size()),
		m_tree(objects.size() * 2, MakeType<DataType>(zeroValue)),
		m_lazyData(),
		m_isSum(false)
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
		const DataType value, const std::int64_t elementCount) const
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
 
	void BuildLazy(const std::int64_t left, const std::int64_t right)
	{
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
 
	void PushLazy(const std::int64_t left, const std::int64_t right) const
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
			throw std::exception();
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
			throw std::exception();
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
 
	DataType Query(const std::int64_t left, const std::int64_t right) const
	{
		if (isLazy)
			throw std::exception();
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
 
	DataType QueryLazy(const std::int64_t left, const std::int64_t right) const
	{
		if (!isLazy)
			throw std::exception();
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
	mutable std::vector<DataType> m_tree;
	mutable std::vector<DataType> m_lazyData;
	mutable std::vector<bool> m_modified;
	F m_f;
	bool m_isSum;
	std::int64_t m_height;
	std::int64_t m_objectCount;
};
 
}

const int INF = 1e9 + 5;

template<typename T, bool maximum_mode, T T_INF>
struct monotonic_RMQ {
	vector<pair<T, int>> values;
	int front = 0, current_index = 0;

	int size() const {
		return int(values.size()) - front;
	}

	static bool is_better(T a, T b) {
		return maximum_mode ? b < a : a < b;
	}

	int prev_add_index = -INF, prev_query_index = -INF;

	

	int add(const T& x, int index = -INF) {
		if (index == -INF)
			index = current_index++;

		prev_add_index = index;

		while (size() > 0 && !is_better(values.back().first, x))
			values.pop_back();

		values.emplace_back(x, index);
		return index;
	}

	

	T query_index(int index) {
		prev_query_index = index;

		while (size() > 0 && values[front].second < index)
			front++;

		if (size() == 0)
			return maximum_mode ? (is_signed<T>::value ? -T_INF : 0) : T_INF;

		return values[front].first;
	}

	

	T query_count(int count) {
		return query_index(current_index - count);
	}

	

	bool has_index(int index) const {
		return !values.empty() && values.back().second >= index;
	}

	bool has_count(int count) const {
		return has_index(current_index - count);
	}
};

const int64_t INF64 = int64_t(2e18) + 5;
 
int main()
{
#ifdef HOME
	freopen("input.txt", "r", stdin);
#else
	std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cout.setf(std::ios::fixed); std::cout.precision(20);
#endif
	int64_t k;
	cin >> k;
	std::array<int64_t, 6> F;
	for (auto& v : F)
	{
		cin >> v;
	}
	std::array<std::vector<int64_t>, 7> dp;
	const int64_t SIZE = 1000000;
	constexpr int64_t inf = numeric_limits<int64_t>::min() / 4;
	{
		for (int i = 0; i <= 6; ++i)
		{
			dp[i] = std::vector<int64_t>(1000000, inf);
		}
	}
	dp[0][0] = 0;
	int64_t pow = 100000;
	std::vector<std::vector<int64_t>> maxPd(10, std::vector<int64_t>(1000, 0));
	for (int64_t pos = 1; pos <= 6; ++pos)
	{
		int64_t f = F[5 - pos + 1];
		std::array<vector<int64_t>, 3> groupsVec;
		for (int i = 0; i < dp[pos - 1].size(); i += pow)
		{
			groupsVec[(i / pow) % 3].push_back(3 * dp[pos - 1][i] - f * (i / pow));
		}
		for (int64_t digit = 9; digit >= 0; --digit)
		{
			typedef monotonic_RMQ<int64_t, true, INF64> RMQ;
			RMQ que[3];
			for (int64_t value = digit * pow; value < SIZE; value += pow)
			{
				int64_t maxV = inf;
				int64_t tmp = value - digit * pow;
				int64_t L = max(tmp - 9ll * (k - 1) * pow, tmp - (tmp / (3 * pow)) * 3 * pow);
				int64_t R = tmp;
				int64_t start = max(tmp / pow - 9ll * (k - 1), 0ll);
				if ((L / pow) % 3 == start % 3)
				{
					que[0].add(R / pow / 3 >= groupsVec[0].size() ? inf : groupsVec[0][R / pow / 3], R / pow / 3);
					que[1].add(R / pow / 3 >= groupsVec[1].size() ? inf : groupsVec[1][R / pow / 3], R / pow / 3);
					que[2].add(R / pow / 3 >= groupsVec[2].size() ? inf : groupsVec[2][R / pow / 3], R / pow / 3);
					maxV = que[start % 3].query_index(L / pow / 3);
				}
				maxV += tmp / pow * f;
				maxV /= 3;
				int64_t plus = (digit % 3 != 0) ? 0 : digit / 3ll;
				dp[pos][value] = max(dp[pos][value], maxV + plus * f);
			}
		}
		pow /= 10;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int total;
		cin >> total;
		cout << dp[6][total] << endl;
	}
 
	return 0;
}