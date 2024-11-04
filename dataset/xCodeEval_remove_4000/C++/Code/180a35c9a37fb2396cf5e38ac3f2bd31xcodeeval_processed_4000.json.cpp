






























































class IO {
	public:
	IO() {
		

		

		



		std::freopen("../build/i.default.txt", "r", stdin);
		std::freopen("../build/o.default.txt", "w", stdout);



		

		std::ios_base::sync_with_stdio(false);

		

		

		std::cin.tie(nullptr);
	}
};
IO io;





class id9 {
	private:
	std::chrono::steady_clock::time_point executionBegin;

	public:
	id9() : executionBegin(std::chrono::steady_clock::now()) {}
	~id9() {
		std::cout << "\n\n-------- Wall time: "
							<< std::chrono::duration_cast<std::chrono::milliseconds>(
									 std::chrono::steady_clock::now() - this->executionBegin)
									 .count()
							<< "ms. --------" << std::endl;
	}
};




id9 id13;




inline constexpr std::size_t operator"" _zu(unsigned long long value) {
	return static_cast<std::size_t>(value);
}
inline std::regex operator"" _re(char const *value, std::size_t) {
	return std::regex(value);
}





template <typename Integer>
inline std::size_t id10(Integer const x) {


	return 8 * sizeof(unsigned long long) - __builtin_clzll(x);


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
inline std::size_t id0(Integer const x) {


	return __builtin_ctzll(x);


	for (std::size_t bit = 0; bit != 8 * sizeof(Integer); bit++) {
		if (x & (static_cast<Integer>(1) << bit)) {
			return bit;
		}
	}
	return std::numeric_limits<std::size_t>::max();
}



template <typename Integer>
inline std::size_t id8(Integer const x) {


	return __builtin_popcountll(x);


	std::size_t count = 0;
	for (std::size_t bit = 0; bit != 8 * sizeof(Integer); bit++) {
		count += !!(x & (static_cast<Integer>(1) << bit));
	}
	return count;
}



template <typename Integer>
inline Integer id5(Integer x, Integer y) {
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
inline Integer id14(Integer const x, Integer const y) {
	return x * y / id5(x, y);
}













template <
	typename Key,
	typename Value,
	typename Hash = std::hash<Key>,
	typename KeyEqual = std::equal_to<Key>>
class id18 {
	private:
	typedef std::list<std::pair<Key const &, Value>> InternalList;
	typedef std::
		unordered_map<Key, typename InternalList::iterator, Hash, KeyEqual>
			InternalHashMap;

	

	

	InternalList lruList;
	InternalHashMap hashMap;

	public:
	

	std::size_t const capacity;

	id18(std::size_t capacity) : capacity(capacity) {}

	

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
	std::pair<typename InternalList::iterator, bool> id11(
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











inline std::vector<std::size_t> id2(
	char const *const cStr,
	std::size_t const id15) {
	std::vector<std::size_t> partialMatch(id15 + 1);

	

	

	partialMatch[0] = SIZE_MAX;

	

	

	std::size_t candidate = 0;

	for (std::size_t a = 1; a < id15; a++) {
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

	partialMatch[id15] = candidate;
	return partialMatch;
}
inline std::vector<std::size_t> id2(std::string const &s) {
	return id2(s.c_str(), s.length());
}











inline std::pair<char *, std::size_t> id6(
	char const *const haystack,
	std::size_t const id7,
	char const *const needle,
	std::size_t const needleLen,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	

	

	std::vector<std::size_t> const &id1 =
		partialMatch.size() == 0 ? id2(needle) : partialMatch;

	char const *searchResult = nullptr;
	for (std::size_t a = 0; a < id7;) {
		if (haystack[a] == needle[candidate]) {
			a++;
			candidate++;
			if (candidate == needleLen) {
				searchResult = haystack + a - candidate;
			}
		} else {
			

			candidate = id1[candidate];
			if (candidate == SIZE_MAX) {
				a++;
				candidate = 0;
			}
		}
	}

	return std::make_pair(const_cast<char *>(searchResult), candidate);
}
inline std::pair<char *, std::size_t> id6(
	char const *const haystack,
	std::size_t id7,
	std::string const &needle,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	return id6(
		haystack,
		id7,
		needle.c_str(),
		needle.length(),
		partialMatch,
		candidate);
}
inline std::pair<std::size_t, std::size_t> id6(
	std::string const &haystack,
	char const *const needle,
	std::size_t const needleLen,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	std::pair<char *, std::size_t> searchRes = id6(
		haystack.c_str(),
		haystack.length(),
		needle,
		needleLen,
		partialMatch,
		candidate);
	return std::make_pair(searchRes.first - haystack.c_str(), searchRes.second);
}
inline std::pair<std::size_t, std::size_t> id6(
	std::string const &haystack,
	std::string const &needle,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	return id6(
		haystack, needle.c_str(), needle.length(), partialMatch, candidate);
}











template <typename Value = long long>
class id17 {
	private:
	std::vector<Value> tree;

	public:
	

	id17(std::size_t const size) : tree(size) {}

	

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
			: values(1_zu << (id10(size - 1) + 2)),
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









class id4 {
	private:
	

	

	mutable std::vector<std::pair<bool, std::size_t>> nodes;

	public:
	id4(std::size_t const size) : nodes(size, {true, 1}) {}

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













template <typename Integer, Integer id16>
class ModRing {
	public:
	Integer value;

	

	

	ModRing(Integer const value = 0)
			: value((id16 + value) % id16) {}

	

	static ModRing<Integer, id16> power(
		ModRing<Integer, id16> const base,
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

	ModRing<Integer, id16> operator+(Integer const other) const {
		return *this + ModRing<Integer, id16>(other);
	}
	ModRing<Integer, id16> operator+(Integer const other) {
		return *this + ModRing<Integer, id16>(other);
	}
	ModRing<Integer, id16> operator+(
		ModRing<Integer, id16> const other) {
		return {this->value + other.value};
	}
	ModRing<Integer, id16> operator+=(
		ModRing<Integer, id16> const other) {
		return *this = *this + other;
	}
	ModRing<Integer, id16> operator++() { return *this += 1; }
	ModRing<Integer, id16> operator++(int) {
		auto tmp(*this);
		*this += 1;
		return tmp;
	}
	ModRing<Integer, id16> operator-(Integer const other) const {
		return *this - ModRing<Integer, id16>(other);
	}
	ModRing<Integer, id16> operator-(Integer const other) {
		return *this - ModRing<Integer, id16>(other);
	}
	ModRing<Integer, id16> operator-(
		ModRing<Integer, id16> const other) {
		return {this->value - other.value};
	}
	ModRing<Integer, id16> operator-=(
		ModRing<Integer, id16> const other) {
		return *this = *this - other;
	}
	ModRing<Integer, id16> operator--() { return *this -= 1; }
	ModRing<Integer, id16> operator--(int) {
		auto tmp(*this);
		*this -= 1;
		return tmp;
	}
	ModRing<Integer, id16> operator*(Integer const other) const {
		return *this * ModRing<Integer, id16>(other);
	}
	ModRing<Integer, id16> operator*(Integer const other) {
		return *this * ModRing<Integer, id16>(other);
	}
	ModRing<Integer, id16> operator*(
		ModRing<Integer, id16> const other) {
		return {this->value * other.value};
	}
	ModRing<Integer, id16> operator*=(
		ModRing<Integer, id16> const other) {
		return *this = *this * other;
	}
	ModRing<Integer, id16> operator/(Integer const other) const {
		return *this / ModRing<Integer, id16>(other);
	}
	ModRing<Integer, id16> operator/(Integer const other) {
		return *this / ModRing<Integer, id16>(other);
	}
	ModRing<Integer, id16> operator/(
		ModRing<Integer, id16> const other) {
		return *this * power(other, id16 - 2);
	}
	ModRing<Integer, id16> operator/=(
		ModRing<Integer, id16> const other) {
		return *this = *this / other;
	}

	bool operator==(Integer const other) {
		return *this == ModRing<Integer, id16>(other);
	}
	bool operator==(ModRing<Integer, id16> const other) {
		return this->value == other.value;
	}
};

template <typename LeftInteger, typename Integer, Integer id16>
ModRing<Integer, id16> operator+(
	LeftInteger const left,
	ModRing<Integer, id16> const right) {
	return ModRing<Integer, id16>(left) + right;
}

template <typename LeftInteger, typename Integer, Integer id16>
ModRing<Integer, id16> operator-(
	LeftInteger const left,
	ModRing<Integer, id16> const right) {
	return ModRing<Integer, id16>(left) - right;
}

template <typename LeftInteger, typename Integer, Integer id16>
ModRing<Integer, id16> operator*(
	LeftInteger const left,
	ModRing<Integer, id16> const right) {
	return ModRing<Integer, id16>(left) * right;
}

template <typename LeftInteger, typename Integer, Integer id16>
ModRing<Integer, id16> operator/(
	LeftInteger const left,
	ModRing<Integer, id16> const right) {
	return ModRing<Integer, id16>(left) / right;
}



template <typename Integer, Integer id16>
inline std::ostream &operator<<(
	std::ostream &stream,
	ModRing<Integer, id16> const right) {
	return stream << right.value;
}





template <typename Integer = std::size_t>
inline std::pair<std::pair<Integer, Integer>, std::pair<Integer, Integer>>
id3(std::size_t const index) {
	if (index == 1) {
		return {{1, 1}, {1, 0}};
	}

	if (index % 2 == 0) {
		auto sub{id3<Integer>(index / 2)};
		return {
			{sub.first.first * sub.first.first + sub.first.second * sub.second.first,
			 sub.first.first * sub.first.second +
				 sub.first.second * sub.second.second},
			{sub.second.first * sub.first.first +
				 sub.second.second * sub.second.first,
			 sub.second.first * sub.first.second +
				 sub.second.second * sub.second.second}};
	} else {
		auto sub{id3<Integer>(index - 1)};
		return {
			{sub.first.first + sub.first.second, sub.first.first},
			{sub.second.first + sub.second.second, sub.second.first}};
	}
}







template <typename Integer = std::size_t>
inline Integer id12(std::size_t const index) {
	return id3<Integer>(index + 1).second.second;
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




	for (long long x = from, rfDir = from < to ? 1 : -1; x != to; x += rfDir)





using namespace std;



int main(int, char const *[]) {
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
		auto dig{id10(i) + 1};
		if (P >= dig) {
			ans += id12<ModRing<LL, 1000000007>>(P - dig + 3) - 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
