




#pragma GCC target("avx2", "bmi", "bmi2", "popcnt", "lzcnt")
#pragma GCC optimize("Ofast", "unroll-loops")



#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#if defined(__APPLE__) || defined(__MACH__)
#define RAIN_PLATFORM_MACOS
#endif



#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <system_error>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>



class IO {
	public:
	IO() {
		

		

		

#ifndef ONLINEJUDGE
#ifdef RAIN_PLATFORM_MACOS
		std::freopen("../build/i.default.txt", "r", stdin);
		std::freopen("../build/o.default.txt", "w", stdout);
#endif
#endif

		

		std::ios_base::sync_with_stdio(false);

		

		

		std::cin.tie(nullptr);
	}
};
IO io;





class WallTimeGuard {
	private:
	std::chrono::steady_clock::time_point executionBegin;

	public:
	WallTimeGuard() : executionBegin(std::chrono::steady_clock::now()) {}
	~WallTimeGuard() {
		std::cout << "\n\n-------- Wall time: "
							<< std::chrono::duration_cast<std::chrono::milliseconds>(
									 std::chrono::steady_clock::now() - this->executionBegin)
									 .count()
							<< "ms. --------" << std::endl;
	}
};



#ifndef ONLINE_JUDGE
WallTimeGuard wallTimeGuard;
#endif



inline constexpr std::size_t operator"" _zu(unsigned long long value) {
	return static_cast<std::size_t>(value);
}
inline std::regex operator"" _re(char const *value, std::size_t) {
	return std::regex(value);
}





template <typename Integer>
inline std::size_t mostSignificant1BitIdx(Integer const x) {
#ifdef __has_builtin
#if __has_builtin(__builtin_clzll)
	return 8 * sizeof(unsigned long long) - __builtin_clzll(x);
#endif
#endif
	for (std::size_t bit = 8 * sizeof(Integer) - 1;
			 bit != std::numeric_limits<std::size_t>::max();
			 bit--) {
		if (x & (static_cast<Integer>(1) << bit)) {
			return bit;
		}
	}
	return std::numeric_limits<std::size_t>::max();
}





template <typename Integer>
inline std::size_t leastSignificant1BitIdx(Integer const x) {
#ifdef __has_builtin
#if __has_builtin(__builtin_ctzll)
	return __builtin_ctzll(x);
#endif
#endif
	for (std::size_t bit = 0; bit != 8 * sizeof(Integer); bit++) {
		if (x & (static_cast<Integer>(1) << bit)) {
			return bit;
		}
	}
	return std::numeric_limits<std::size_t>::max();
}



template <typename Integer>
inline std::size_t bitPopcount(Integer const x) {
#ifdef __has_builtin
#if __has_builtin(__builtin_popcountll)
	return __builtin_popcountll(x);
#endif
#endif
	std::size_t count = 0;
	for (std::size_t bit = 0; bit != 8 * sizeof(Integer); bit++) {
		count += !!(x & (static_cast<Integer>(1) << bit));
	}
	return count;
}



template <typename Integer>
inline Integer greatestCommonDivisor(Integer x, Integer y) {
	if (x > y) {
		std::swap(x, y);
	}
	while (x != 0) {
		y %= x;
		std::swap(x, y);
	}
	return y;
}



template <typename Integer>
inline Integer leastCommonMultiple(Integer const x, Integer const y) {
	return x * y / greatestCommonDivisor(x, y);
}













template <
	typename Key,
	typename Value,
	typename Hash = std::hash<Key>,
	typename KeyEqual = std::equal_to<Key>>
class LruCache {
	private:
	typedef std::list<std::pair<Key const &, Value>> InternalList;
	typedef std::
		unordered_map<Key, typename InternalList::iterator, Hash, KeyEqual>
			InternalHashMap;

	

	

	InternalList lruList;
	InternalHashMap hashMap;

	public:
	

	std::size_t const capacity;

	LruCache(std::size_t capacity) : capacity(capacity) {}

	

	std::size_t size() const noexcept { return this->lruList.size(); }
	bool empty() const noexcept { return this->lruList.empty(); }
	auto begin() const noexcept { return this->lruList.begin(); }
	auto end() const noexcept { return this->lruList.end(); }
	auto begin() noexcept { return this->lruList.begin(); }
	auto end() noexcept { return this->lruList.end(); }

	

	

	typename InternalList::iterator find(Key const &key) {
		typename InternalHashMap::iterator const findIt = this->hashMap.find(key);

		if (findIt == this->hashMap.end()) {
			return this->end();
		}

		this->lruList.splice(this->lruList.begin(), this->lruList, findIt->second);
		return this->lruList.begin();
	}

	

	Value &at(Key const &key) {
		auto findIt = this->find(key);
		if (findIt == this->end()) {
			throw std::out_of_range("Key does not exist in cache.");
		}
		return findIt->second;
	}

	

	

	

	

	

	

	template <typename KeyType, typename ValueType>
	std::pair<typename InternalList::iterator, bool> insertOrAssign(
		KeyType &&key,
		ValueType &&value) {
		typename InternalHashMap::iterator const findIt = this->hashMap.find(key);

		if (findIt != this->hashMap.end()) {
			

			this->lruList.splice(
				this->lruList.begin(), this->lruList, findIt->second);

			

			this->lruList.begin()->second = std::move(value);
			return {this->lruList.begin(), false};
		}

		

		if (this->hashMap.size() >= this->capacity) {
			this->hashMap.erase(this->lruList.back().first);
			this->lruList.pop_back();
		}

		

		typename InternalHashMap::iterator mapIt;
		std::tie(mapIt, std::ignore) =
			this->hashMap.emplace(std::forward<KeyType>(key), this->lruList.end());

		

		this->lruList.emplace_front(mapIt->first, std::forward<ValueType>(value));

		

		mapIt->second = this->lruList.begin();
		return {this->lruList.begin(), true};
	}
};











inline std::vector<std::size_t> computeKmpPartialMatch(
	char const *const cStr,
	std::size_t const cStrLen) {
	std::vector<std::size_t> partialMatch(cStrLen + 1);

	

	

	partialMatch[0] = SIZE_MAX;

	

	

	std::size_t candidate = 0;

	for (std::size_t a = 1; a < cStrLen; a++) {
		if (cStr[a] == cStr[candidate]) {
			partialMatch[a] = partialMatch[candidate];
		} else {
			partialMatch[a] = candidate;
			while (candidate != SIZE_MAX && cStr[a] != cStr[candidate]) {
				candidate = partialMatch[candidate];
			}
		}
		candidate++;
	}

	partialMatch[cStrLen] = candidate;
	return partialMatch;
}
inline std::vector<std::size_t> computeKmpPartialMatch(std::string const &s) {
	return computeKmpPartialMatch(s.c_str(), s.length());
}











inline std::pair<char *, std::size_t> kmpSearch(
	char const *const haystack,
	std::size_t const haystackLen,
	char const *const needle,
	std::size_t const needleLen,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	

	

	std::vector<std::size_t> const &partialMatchProxy =
		partialMatch.size() == 0 ? computeKmpPartialMatch(needle) : partialMatch;

	char const *searchResult = nullptr;
	for (std::size_t a = 0; a < haystackLen;) {
		if (haystack[a] == needle[candidate]) {
			a++;
			candidate++;
			if (candidate == needleLen) {
				searchResult = haystack + a - candidate;
			}
		} else {
			

			candidate = partialMatchProxy[candidate];
			if (candidate == SIZE_MAX) {
				a++;
				candidate = 0;
			}
		}
	}

	return std::make_pair(const_cast<char *>(searchResult), candidate);
}
inline std::pair<char *, std::size_t> kmpSearch(
	char const *const haystack,
	std::size_t haystackLen,
	std::string const &needle,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	return kmpSearch(
		haystack,
		haystackLen,
		needle.c_str(),
		needle.length(),
		partialMatch,
		candidate);
}
inline std::pair<std::size_t, std::size_t> kmpSearch(
	std::string const &haystack,
	char const *const needle,
	std::size_t const needleLen,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	std::pair<char *, std::size_t> searchRes = kmpSearch(
		haystack.c_str(),
		haystack.length(),
		needle,
		needleLen,
		partialMatch,
		candidate);
	return std::make_pair(searchRes.first - haystack.c_str(), searchRes.second);
}
inline std::pair<std::size_t, std::size_t> kmpSearch(
	std::string const &haystack,
	std::string const &needle,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	return kmpSearch(
		haystack, needle.c_str(), needle.length(), partialMatch, candidate);
}











template <typename Value = long long>
class FenwickTree {
	private:
	std::vector<Value> tree;

	public:
	

	FenwickTree(std::size_t const size) : tree(size) {}

	

	Value sum(std::size_t const idx) const {
		Value aggregate{};
		for (std::size_t i = idx; i != SIZE_MAX; i &= i + 1, i--) {
			aggregate += this->tree[i];
		}
		return aggregate;
	}

	

	void modify(std::size_t const idx, Value const &delta) {
		for (std::size_t i = idx; i < this->tree.size(); i |= i + 1) {
			this->tree[i] += delta;
		}
	}
};





























template <typename _Value, typename _Update, typename _Result = _Value>
class SegmentTree {
	protected:
	using Value = _Value;
	using Update = _Update;
	using Result = _Result;

	

	std::vector<Value> values;

	

	std::vector<bool> lazy;

	

	std::vector<Update> updates;

	

	

	virtual void aggregate(
		std::size_t const node,
		typename std::vector<Value>::reference value,
		Value const &left,
		Value const &right,
		std::pair<std::size_t, std::size_t> const &range) = 0;

	

	

	virtual Result aggregate(
		std::size_t const node,
		Result const &left,
		Result const &right,
		std::pair<std::size_t, std::size_t> const &range) = 0;

	

	

	virtual void split(
		std::size_t const node,
		Update const &update,
		typename std::vector<Update>::reference left,
		typename std::vector<Update>::reference right,
		std::pair<std::size_t, std::size_t> const &range) = 0;

	

	virtual Result convert(std::size_t const node, Value const &value) = 0;

	

	virtual void apply(
		std::size_t const node,
		typename std::vector<Value>::reference value,
		Update const &update,
		std::pair<std::size_t, std::size_t> const &range) = 0;

	public:
	

	SegmentTree(std::size_t const size)
			: values(1_zu << (mostSignificant1BitIdx(size - 1) + 2)),
				lazy(values.size(), false),
				updates(values.size()) {}

	

	Result query(std::size_t const left, std::size_t const right) {
		return this->query(1, left, right, {0, this->values.size() / 2 - 1});
	}

	

	void update(
		std::size_t const left,
		std::size_t const right,
		Update const &update) {
		this->update(1, left, right, update, {0, this->values.size() / 2 - 1});
	}

	private:
	

	

	void propagate(
		std::size_t const node,
		std::pair<std::size_t, std::size_t> const &range) {
		if (!this->lazy[node]) {
			return;
		}

		

		

		if (node < this->values.size() / 2) {
			this->lazy[node * 2] = this->lazy[node * 2 + 1] = true;
			this->split(
				node,
				this->updates[node],
				this->updates[node * 2],
				this->updates[node * 2 + 1],
				range);
		}

		

		

		this->apply(node, this->values[node], this->updates[node], range);
		this->updates[node] = {};
		this->lazy[node] = false;
	}

	

	

	Result query(
		std::size_t const node,
		std::size_t const left,
		std::size_t const right,
		std::pair<std::size_t, std::size_t> const &range) {
		if (right < range.first || left > range.second) {
			return {};
		}
		this->propagate(node, range);

		

		if (range.first >= left && range.second <= right) {
			return this->convert(node, this->values[node]);
		}

		std::size_t mid = (range.first + range.second) / 2;
		return this->aggregate(
			node,
			this->query(node * 2, left, right, {range.first, mid}),
			this->query(node * 2 + 1, left, right, {mid + 1, range.second}),
			range);
	}

	

	void update(
		std::size_t const node,
		std::size_t const left,
		std::size_t const right,
		Update const &update,
		std::pair<std::size_t, std::size_t> const &range) {
		if (right < range.first || left > range.second) {
			return;
		}
		

		

		this->propagate(node, range);

		

		if (range.first >= left && range.second <= right) {
			

			this->updates[node] = update;
			this->lazy[node] = true;
		} else {
			std::size_t mid = (range.first + range.second) / 2;
			this->update(node * 2, left, right, update, {range.first, mid});
			this->update(node * 2 + 1, left, right, update, {mid + 1, range.second});

			

			

			

			this->propagate(node * 2, {range.first, mid});
			this->propagate(node * 2 + 1, {mid + 1, range.second});
			this->aggregate(
				node,
				this->values[node],
				this->values[node * 2],
				this->values[node * 2 + 1],
				range);
		}
	}
};









class DisjointSetUnion {
	private:
	

	

	mutable std::vector<std::pair<bool, std::size_t>> nodes;

	public:
	DisjointSetUnion(std::size_t const size) : nodes(size, {true, 1}) {}

	std::size_t find(std::size_t const i) const {
		if (this->nodes[i].first) {
			return i;
		}
		return this->nodes[i].second = this->find(this->nodes[i].second);
	}
	std::size_t rank(std::size_t const i) const {
		return this->nodes[this->find(i)].second;
	}
	void join(std::size_t const i, std::size_t const j) {
		std::size_t pI = this->find(i), pJ = this->find(j);
		if (pI == pJ) {
			return;
		}
		if (this->nodes[pI].second > this->nodes[pJ].second) {
			std::swap(pI, pJ);
		}
		this->nodes[pJ].second += this->nodes[pI].second;
		this->nodes[pI] = {false, pJ};
	}
};













template <typename Integer, Integer primeModulus>
class ModRing {
	public:
	Integer value;

	

	

	ModRing(Integer const value = 0)
			: value((primeModulus + value) % primeModulus) {}

	

	static ModRing<Integer, primeModulus> power(
		ModRing<Integer, primeModulus> const base,
		Integer const exponent) {
		if (exponent == 0) {
			return {1};
		}
		auto half = power(base, exponent / 2);
		if (exponent % 2 == 0) {
			return half * half;
		} else {
			return half * half * base;
		}
	}

	ModRing<Integer, primeModulus> operator+(Integer const other) const {
		return *this + ModRing<Integer, primeModulus>(other);
	}
	ModRing<Integer, primeModulus> operator+(Integer const other) {
		return *this + ModRing<Integer, primeModulus>(other);
	}
	ModRing<Integer, primeModulus> operator+(
		ModRing<Integer, primeModulus> const other) {
		return {this->value + other.value};
	}
	ModRing<Integer, primeModulus> operator+=(
		ModRing<Integer, primeModulus> const other) {
		return *this = *this + other;
	}
	ModRing<Integer, primeModulus> operator++() { return *this += 1; }
	ModRing<Integer, primeModulus> operator++(int) {
		auto tmp(*this);
		*this += 1;
		return tmp;
	}
	ModRing<Integer, primeModulus> operator-(Integer const other) const {
		return *this - ModRing<Integer, primeModulus>(other);
	}
	ModRing<Integer, primeModulus> operator-(Integer const other) {
		return *this - ModRing<Integer, primeModulus>(other);
	}
	ModRing<Integer, primeModulus> operator-(
		ModRing<Integer, primeModulus> const other) {
		return {this->value - other.value};
	}
	ModRing<Integer, primeModulus> operator-=(
		ModRing<Integer, primeModulus> const other) {
		return *this = *this - other;
	}
	ModRing<Integer, primeModulus> operator--() { return *this -= 1; }
	ModRing<Integer, primeModulus> operator--(int) {
		auto tmp(*this);
		*this -= 1;
		return tmp;
	}
	ModRing<Integer, primeModulus> operator*(Integer const other) const {
		return *this * ModRing<Integer, primeModulus>(other);
	}
	ModRing<Integer, primeModulus> operator*(Integer const other) {
		return *this * ModRing<Integer, primeModulus>(other);
	}
	ModRing<Integer, primeModulus> operator*(
		ModRing<Integer, primeModulus> const other) {
		return {this->value * other.value};
	}
	ModRing<Integer, primeModulus> operator*=(
		ModRing<Integer, primeModulus> const other) {
		return *this = *this * other;
	}
	ModRing<Integer, primeModulus> operator/(Integer const other) const {
		return *this / ModRing<Integer, primeModulus>(other);
	}
	ModRing<Integer, primeModulus> operator/(Integer const other) {
		return *this / ModRing<Integer, primeModulus>(other);
	}
	ModRing<Integer, primeModulus> operator/(
		ModRing<Integer, primeModulus> const other) {
		return *this * power(other, primeModulus - 2);
	}
	ModRing<Integer, primeModulus> operator/=(
		ModRing<Integer, primeModulus> const other) {
		return *this = *this / other;
	}

	bool operator==(Integer const other) {
		return *this == ModRing<Integer, primeModulus>(other);
	}
	bool operator==(ModRing<Integer, primeModulus> const other) {
		return this->value == other.value;
	}
};

template <typename LeftInteger, typename Integer, Integer primeModulus>
ModRing<Integer, primeModulus> operator+(
	LeftInteger const left,
	ModRing<Integer, primeModulus> const right) {
	return ModRing<Integer, primeModulus>(left) + right;
}

template <typename LeftInteger, typename Integer, Integer primeModulus>
ModRing<Integer, primeModulus> operator-(
	LeftInteger const left,
	ModRing<Integer, primeModulus> const right) {
	return ModRing<Integer, primeModulus>(left) - right;
}

template <typename LeftInteger, typename Integer, Integer primeModulus>
ModRing<Integer, primeModulus> operator*(
	LeftInteger const left,
	ModRing<Integer, primeModulus> const right) {
	return ModRing<Integer, primeModulus>(left) * right;
}

template <typename LeftInteger, typename Integer, Integer primeModulus>
ModRing<Integer, primeModulus> operator/(
	LeftInteger const left,
	ModRing<Integer, primeModulus> const right) {
	return ModRing<Integer, primeModulus>(left) / right;
}



template <typename Integer, Integer primeModulus>
inline std::ostream &operator<<(
	std::ostream &stream,
	ModRing<Integer, primeModulus> const right) {
	return stream << right.value;
}





template <typename Integer = std::size_t>
inline std::pair<std::pair<Integer, Integer>, std::pair<Integer, Integer>>
fibonacciMatrix(std::size_t const index) {
	if (index == 1) {
		return {{1, 1}, {1, 0}};
	}

	if (index % 2 == 0) {
		auto sub{fibonacciMatrix<Integer>(index / 2)};
		return {
			{sub.first.first * sub.first.first + sub.first.second * sub.second.first,
			 sub.first.first * sub.first.second +
				 sub.first.second * sub.second.second},
			{sub.second.first * sub.first.first +
				 sub.second.second * sub.second.first,
			 sub.second.first * sub.first.second +
				 sub.second.second * sub.second.second}};
	} else {
		auto sub{fibonacciMatrix<Integer>(index - 1)};
		return {
			{sub.first.first + sub.first.second, sub.first.first},
			{sub.second.first + sub.second.second, sub.second.first}};
	}
}







template <typename Integer = std::size_t>
inline Integer fibonacciNumber(std::size_t const index) {
	return fibonacciMatrix<Integer>(index + 1).second.second;
}



using ZU = std::size_t;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
template <typename First, typename Second>
using PR = std::pair<First, Second>;
template <typename Type>
using VR = std::vector<Type>;
template <typename Type, std::size_t Size>
using AR = std::array<Type, Size>;



#define RF(x, from, to) \
	for (long long x = from, rfDir = from < to ? 1 : -1; x != to; x += rfDir)





using namespace std;



VR<ModRing<LL, 1000000007>> fib;

LL cd(LL x) {
	LL ans{0};
	while ((1LL << ans) <= x) {
		ans++;
	}
	return ans;
}

int main(int, char const *[]) {
	fib.push_back({0});
	fib.push_back({1});
	while (fib.size() <= 200002) {
		fib.push_back(fib.back() + fib[fib.size() - 2]);
	}

	LL N, P;
	cin >> N >> P;

	unordered_set<LL> A;
	RF(i, 0, N) {
		LL j;
		cin >> j;
		A.insert(j);
	}
	VR<LL> B;
	for (auto i : A) {
		LL cur = i;
		bool kill{false};
		while (cur != 0 && ((cur & 3) == 0 || (cur & 1) == 1)) {
			if ((cur & 3) == 0) {
				cur >>= 2;
			} else {
				cur >>= 1;
			}
			if (A.find(cur) != A.end()) {
				kill = true;
				break;
			}
		}
		if (!kill) {
			B.push_back(i);
		}
	}

	ModRing<LL, 1000000007> ans{0};
	for (auto i : B) {
		if (i == 1) {
			ans += fib[P + 2] - 1;
		} else {
			auto dig{mostSignificant1BitIdx(i) + 1};
			if (P >= dig) {
				ans += fib[P - dig + 3] - 1;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
