

























































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





class id7 {
	private:
	std::chrono::steady_clock::time_point executionBegin;

	public:
	id7() : executionBegin(std::chrono::steady_clock::now()) {}
	~id7() {
		std::cout << "\n\n-------- Wall time: "
							<< std::chrono::duration_cast<std::chrono::milliseconds>(
									 std::chrono::steady_clock::now() - this->executionBegin)
									 .count()
							<< "ms. --------" << std::endl;
	}
};




id7 id10;






template <typename Integer>
inline std::size_t id8(Integer const x) {


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
inline std::size_t id6(Integer const x) {


	return __builtin_popcountll(x);


	std::size_t count = 0;
	for (std::size_t bit = 0; bit != 8 * sizeof(Integer); bit++) {
		count += !!(x & (static_cast<Integer>(1) << bit));
	}
	return count;
}



template <typename Integer>
inline Integer id3(Integer x, Integer y) {
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
inline Integer id11(Integer const x, Integer const y) {
	return x * y / id3(x, y);
}













template <
	typename Key,
	typename Value,
	typename Hash = std::hash<Key>,
	typename KeyEqual = std::equal_to<Key>>
class id14 {
	private:
	typedef std::list<std::pair<Key const &, Value>> InternalList;
	typedef std::
		unordered_map<Key, typename InternalList::iterator, Hash, KeyEqual>
			InternalHashMap;

	

	

	InternalList lruList;
	InternalHashMap hashMap;

	public:
	

	std::size_t const capacity;

	id14(std::size_t capacity) : capacity(capacity) {}

	

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
	std::pair<typename InternalList::iterator, bool> id9(
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
	std::size_t const id12) {
	std::vector<std::size_t> partialMatch(id12 + 1);

	

	

	partialMatch[0] = SIZE_MAX;

	

	

	std::size_t candidate = 0;

	for (std::size_t a = 1; a < id12; a++) {
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

	partialMatch[id12] = candidate;
	return partialMatch;
}
inline std::vector<std::size_t> id2(std::string const &s) {
	return id2(s.c_str(), s.length());
}











inline std::pair<char *, std::size_t> id4(
	char const *const haystack,
	std::size_t const id5,
	char const *const needle,
	std::size_t const needleLen,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	

	

	std::vector<std::size_t> const &id1 =
		partialMatch.size() == 0 ? id2(needle) : partialMatch;

	char const *searchResult = nullptr;
	for (std::size_t a = 0; a < id5;) {
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
inline std::pair<char *, std::size_t> id4(
	char const *const haystack,
	std::size_t id5,
	std::string const &needle,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	return id4(
		haystack,
		id5,
		needle.c_str(),
		needle.length(),
		partialMatch,
		candidate);
}
inline std::pair<std::size_t, std::size_t> id4(
	std::string const &haystack,
	char const *const needle,
	std::size_t const needleLen,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	std::pair<char *, std::size_t> searchRes = id4(
		haystack.c_str(),
		haystack.length(),
		needle,
		needleLen,
		partialMatch,
		candidate);
	return std::make_pair(searchRes.first - haystack.c_str(), searchRes.second);
}
inline std::pair<std::size_t, std::size_t> id4(
	std::string const &haystack,
	std::string const &needle,
	std::vector<std::size_t> const &partialMatch = {},
	std::size_t candidate = 0) {
	return id4(
		haystack, needle.c_str(), needle.length(), partialMatch, candidate);
}











template <typename Value = long long>
class id13 {
	private:
	std::vector<Value> tree;

	public:
	

	id13(std::size_t const size = 0) : tree(size) {}

	

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
			: values(1_zu << (id8(size - 1) + 2)),
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



LL MOD = 1000000007;

LL modPow(LL b, LL p) {
	b %= MOD;
	if (p == 0) {
		return 1;
	}
	LL ans = modPow(b, p / 2);
	if (p % 2 == 0) {
		return ans * ans % MOD;
	}
	return ans * ans % MOD * b % MOD;
}

int main(int argc, char const *argv[]) {
	LL T;
	cin >> T;
	while (T--) {
		LL N, M, RB, CB, RD, CD, P;
		cin >> N >> M >> RB >> CB >> RD >> CD >> P;

		LL L0 = 0, H0 = 0, r = RB, c = CB, ans = 0,
			 p = P * modPow(100, MOD - 2) % MOD,
			 q = (100 - P) * modPow(100, MOD - 2) % MOD;
		AR<LL, 2> Ts;
		if (r != N && c != M) {
			LL delr = N - r, delc = M - c, del = min(delr, delc), nextr = r + del,
				 nextc = c + del;
			LL cTs = 0;
			if (r <= RD && nextr > RD) {
				Ts[cTs++] = RD - r;
			}
			if (c <= CD && nextc > CD) {
				Ts[cTs++] = CD - c;
			}
			if (cTs == 2 && Ts[0] == Ts[1]) {
				cTs--;
			}
			if (cTs == 2 && Ts[0] > Ts[1]) {
				swap(Ts[0], Ts[1]);
			}
			RF(i, 0, cTs) {
				ans = (ans + p * modPow(q, H0) % MOD * Ts[i] % MOD) % MOD;
				H0++;
			}
			L0 = del;
			r = nextr;
			c = nextc;
		}

		LL H1 = 0, L1 = 0, cans = 0, cr = r, cc = c, ir = 1, ic = 1,
			 pmq = modPow(q, H0);
		if (r == 1) {
			ir = 1;
		}
		if (r == N) {
			ir = -1;
		}
		if (c == 1) {
			ic = 1;
		}
		if (c == M) {
			ic = -1;
		}
		LL iir = ir, iic = ic;

		do {
			LL delr = ir == 1 ? N - r : r - 1, delc = ic == 1 ? M - c : c - 1,
				 del = min(delr, delc), nextr = r + ir * del, nextc = c + ic * del;
			LL cTs = 0;
			if (ir == 1 && r <= RD && nextr > RD) {
				Ts[cTs++] = RD - r;
			}
			if (ir == -1 && r >= RD && nextr < RD) {
				Ts[cTs++] = r - RD;
			}
			if (ic == 1 && c <= CD && nextc > CD) {
				Ts[cTs++] = CD - c;
			}
			if (ic == -1 && c >= CD && nextc < CD) {
				Ts[cTs++] = c - CD;
			}
			if (cTs == 2 && Ts[0] == Ts[1]) {
				cTs--;
			}
			if (cTs == 2 && Ts[0] > Ts[1]) {
				swap(Ts[0], Ts[1]);
			}
			RF(i, 0, cTs) {
				cans = (cans + p * pmq % MOD * (L0 + L1 + Ts[i]) % MOD) % MOD;
				pmq = (pmq * q) % MOD;
				H1++;
			}
			L1 += del;
			r = nextr;
			c = nextc;
			if (r == 1) {
				ir = 1;
			}
			if (r == N) {
				ir = -1;
			}
			if (c == 1) {
				ic = 1;
			}
			if (c == M) {
				ic = -1;
			}
		} while (r != cr || c != cc || ir != iir || ic != iic);

		LL G = modPow((1 + MOD - modPow(q, H1)) % MOD, MOD - 2);
		LL X = (1 + MOD - modPow(q, H1)) % MOD *
			modPow((1 + MOD - q) % MOD, MOD - 2) % MOD;

		

		

		

		

		

		

		


		LL G2 = G * G % MOD;
		LL fans = ans + cans * G % MOD +
			p * modPow(q, H0 + H1) % MOD * L1 % MOD * X % MOD * G2 % MOD;
		cout << fans % MOD << '\n';
	}

	return 0;
}