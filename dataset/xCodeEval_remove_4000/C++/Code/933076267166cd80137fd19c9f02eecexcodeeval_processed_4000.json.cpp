



















































constexpr std::size_t operator"" _zu(unsigned long long value) {
	return static_cast<std::size_t>(value);
}
std::regex operator"" _re(char const *value, std::size_t) {
	return std::regex(value);
}



class IO {
	public:
	IO() {
		


		std::freopen("in.txt", "r", stdin);
		std::freopen("out.txt", "w", stdout);


		

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




id9 id10;






template <typename Integer>
inline std::size_t id12(Integer const x) {


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
inline std::size_t id1(Integer const x) {


	return __builtin_ctzll(x);


	for (std::size_t bit = 0; bit != 8 * sizeof(Integer); bit++) {
		if (x & (static_cast<Integer>(1) << bit)) {
			return bit;
		}
	}
	return std::numeric_limits<std::size_t>::max();
}



template <typename Integer>
inline std::size_t id7(Integer const x) {


	return __builtin_popcountll(x);


	std::size_t count = 0;
	for (std::size_t bit = 0; bit != 8 * sizeof(Integer); bit++) {
		count += !!(x & (static_cast<Integer>(1) << bit));
	}
	return count;
}



template <typename Integer>
inline Integer id14(Integer x, Integer y) {
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
inline Integer id6(Integer const x, Integer const y) {
	return x * y / id14(x, y);
}













template <
	typename Key,
	typename Value,
	typename Hash = std::hash<Key>,
	typename KeyEqual = std::equal_to<Key>>
class id13 {
	private:
	typedef std::list<std::pair<Key const &, Value>> InternalList;
	typedef std::
		unordered_map<Key, typename InternalList::iterator, Hash, KeyEqual>
			InternalHashMap;

	

	

	InternalList lruList;
	InternalHashMap hashMap;

	public:
	

	std::size_t const capacity;

	id13(std::size_t capacity) : capacity(capacity) {}

	

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
	std::pair<typename InternalList::iterator, bool> id0(
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











inline std::vector<std::size_t> id5(
	char const *const cStr,
	std::size_t const id8) {
	std::vector<std::size_t> partialMatch(id8 + 1);

	

	

	partialMatch[0] = SIZE_MAX;

	

	

	std::size_t candidate = 0;

	for (std::size_t a = 1; a < id8; a++) {
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

	partialMatch[id8] = candidate;
	return partialMatch;
}
inline std::vector<std::size_t> id5(std::string const &s) {
	return id5(s.c_str(), s.length());
}











inline std::pair<char *, std::size_t> id2(
	char const *const haystack,
	std::size_t const id3,
	char const *const needle,
	std::size_t const needleLen,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	

	

	std::vector<std::size_t> const &id4 =
		partialMatch.size() == 0 ? id5(needle) : partialMatch;

	char const *searchResult = nullptr;
	for (std::size_t a = 0; a < id3;) {
		if (haystack[a] == needle[candidate]) {
			a++;
			candidate++;
			if (candidate == needleLen) {
				searchResult = haystack + a - candidate;
			}
		} else {
			

			candidate = id4[candidate];
			if (candidate == SIZE_MAX) {
				a++;
				candidate = 0;
			}
		}
	}

	return std::make_pair(const_cast<char *>(searchResult), candidate);
}
inline std::pair<char *, std::size_t> id2(
	char const *const haystack,
	std::size_t id3,
	std::string const &needle,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	return id2(
		haystack,
		id3,
		needle.c_str(),
		needle.length(),
		partialMatch,
		candidate);
}
inline std::pair<std::size_t, std::size_t> id2(
	std::string const &haystack,
	char const *const needle,
	std::size_t const needleLen,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	std::pair<char *, std::size_t> searchRes = id2(
		haystack.c_str(),
		haystack.length(),
		needle,
		needleLen,
		partialMatch,
		candidate);
	return std::make_pair(searchRes.first - haystack.c_str(), searchRes.second);
}
inline std::pair<std::size_t, std::size_t> id2(
	std::string const &haystack,
	std::string const &needle,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	return id2(
		haystack, needle.c_str(), needle.length(), partialMatch, candidate);
}











template <typename Value = long long>
class id11 {
	private:
	std::vector<Value> tree;

	public:
	

	id11(std::size_t const size = 0) : tree(size) {}

	

	Value sum(std::size_t const idx) {
		this->reserve(idx + 1);
		Value aggregate{};
		for (std::size_t i = idx; i != SIZE_MAX; i &= i + 1, i--) {
			aggregate += this->tree[i];
		}
		return aggregate;
	}

	

	Value get(std::size_t const idx) {
		return this->sum(idx) - this->sum(idx - 1);
	}

	

	void modify(std::size_t const idx, Value const &delta) {
		this->reserve(idx + 1);
		for (std::size_t i = idx; i < this->tree.size(); i |= i + 1) {
			this->tree[i] += delta;
		}
	}

	

	void set(std::size_t const idx, Value const &value) {
		this->modify(idx, value - this->get(idx));
	}

	private:
	

	

	void reserve(std::size_t const size) {
		while (this->tree.size() < size) {
			this->tree.push_back({});

			

			std::size_t i = this->tree.size() - 1, k = (i & (i + 1)) - 1;
			for (std::size_t j = i - 1; j != k; j &= j + 1, j--) {
				this->tree.back() += this->tree[j];
			}
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

	public:
	

	SegmentTree(std::size_t const size)
			: values(1_zu << (id12(size - 1) + 2)),
				lazy(values.size(), false),
				updates(values.size()) {}

	protected:
	

	

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




	for (long long x = from, _rfDir = from < to ? 1 : -1; x != to; x += _rfDir)





using namespace std;


char board[2002][2002];
int best[2002][2002];
VR<PR<int, int>> s;

int main(int argc, char const *argv[]) {
	short T;
	cin >> T;
	while (T--) {
		short R, C;
		cin >> R >> C;
		cin.getline(board[1] + 1, 2);
		memset(best[0], 0, (C + 2) * sizeof(int));
		RF(i, 1, R + 1) {
			cin.getline(board[i] + 1, C + 1);
			best[i][0] = best[i][C + 1] = 0;
			memset(best[i] + 1, -1, C * sizeof(int));
		}
		memset(best[R + 1], 0, (C + 2) * sizeof(int));

		PR<int, int> ans;
		RF(i, 1, R + 1) {
			RF(j, 1, C + 1) {
				if (best[i][j] == -1) {
					int prev = -1;
					s.push_back({i, j});
					PR<int, int> retracing;
					while (!s.empty()) {
						auto f = s.back();

						PR<int, int> next;
						switch (board[f.first][f.second]) {
							case 'U':
								next = {f.first - 1, f.second};
								break;
							case 'R':
								next = {f.first, f.second + 1};
								break;
							case 'D':
								next = {f.first + 1, f.second};
								break;
							case 'L':
								next = {f.first, f.second - 1};
								break;
						}

						if (best[next.first][next.second] >= 0) {
							s.pop_back();
							if (retracing.first == 0) {
								best[f.first][f.second] = best[next.first][next.second] + 1;
							} else {
								best[f.first][f.second] = best[next.first][next.second];
							}
						} else if (best[next.first][next.second] == -1) {
							s.push_back(next);
							best[f.first][f.second] = --prev;
						} else {
							s.pop_back();
							best[f.first][f.second] =
								best[next.first][next.second] - prev + 2;
							retracing = next;
						}

						if (f == retracing) {
							retracing = {0, 0};
						}
					}
				}
				if (best[ans.first][ans.second] < best[i][j]) {
					ans = {i, j};
				}
			}
		}
		cout << ans.first << ' ' << ans.second << ' ' << best[ans.first][ans.second]
				 << '\n';
	}

	return 0;
}
