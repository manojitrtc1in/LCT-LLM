








































































namespace abesse
{
	template<typename T>
	T gcd(T a, T b)
	{
		return b ? gcd(b, a % b) : a;
	}

	template<typename T>
	T lcm(T a, T b)
	{
		return (a * b) / gcd(a, b);
	}

	template<typename T>
	T id5(T x)
	{
		constexpr size_t bit_count = sizeof(T) * CHAR_BIT;

		if constexpr (std::is_same<T, unsigned __int64>::value)
			return bit_count - 1 - __lzcnt64(x);
		else if constexpr (std::is_same<T, unsigned int>::value)
			return bit_count - 1 - __lzcnt(x);
		else if constexpr (std::is_same<T, unsigned short>::value)
			return bit_count - 1 - __lzcnt16(x);
		else
			static_assert(  true == std::is_same<T, unsigned __int64>::value
						 || true == std::is_same<T, unsigned int>::value
						 || true == std::is_same<T, unsigned short>::value
						, "Invalid type has been specified for id5()");

		if constexpr (std::is_same<T, unsigned long long>::value)
			return bit_count - 1 - __builtin_clzll(x);
		else if constexpr (std::is_same<T, unsigned long>::value)
			return bit_count - 1 - __builtin_clzl(x);
		else if constexpr (std::is_same<T, unsigned int>::value)
			return bit_count - 1 - __builtin_clz(x);
		else
			static_assert(true == std::is_same<T, unsigned long long>::value
				|| true == std::is_same<T, unsigned long>::value
				|| true == std::is_same<T, unsigned int>::value
				, "Invalid type has been specified for id5()");

	}

	bool is_prime(unsigned long long a)
	{
		for (size_t i = 2; i * i <= a; i++)
		{
			if (a % i == 0)
				return 0;
		}
		return a != 1;
	}

	
	inline long long id9(long long x, long long y)
	{
		return (1 + ((x + y) / 2) * (((x + y) / 2) + 1) + ((x + y) % 2) * ((x + y + 1) / 2)) + abs(x - y) / 2;
	}

	template<typename T>
	struct ABMin
	{
		static T compute(T const& first, T const& second)
		{
			return std::min(first, second);
		}
		static T DefVal()
		{
			return std::numeric_limits<T>::max();
		}
	};

	template<typename T>
	struct ABMax
	{
		static T compute(T const& first, T const& second)
		{
			return std::max(first, second);
		}
		static T DefVal()
		{
			return std::numeric_limits<T>::min();
		}
	};

	template<typename T>
	struct ABSum
	{
		static T compute(T const& first, T const& second)
		{
			return first + second;
		}

		static T DefVal()
		{
			return T();
		}
	};

	template<size_t MAXN>
	class Erato
	{
		int erato[MAXN];
	public:
		Erato()
		{
			erato[1] = 1;
			for (size_t i = 2; i < MAXN; i++)
			{
				for (size_t j = i; j < MAXN; j += i)
					if (erato[j] == 0)
						erato[j] = i;
			}
		}


		bool is_prime(int x)
		{
			return (x == erato[x]);
		}

		int min_pr_div(int x)
		{
			return erato[x];
		}

		void get_pr_divs(unsigned long long x, std::vector<unsigned long long>& divs) 
		{
			for (size_t i = 2; i * i <= x; i++)
			{
				if (this->is_prime(i))
				{
					if (x % i == 0)
						divs.push_back(i);
					while (x % i == 0)
						x /= i;
				}
			}
			if (x != 1)
				divs.push_back(x);
		}
	};

	template<size_t MAXN>
	class id0
	{
		int mu_[MAXN];
		Erato<MAXN> erato;
	public:
		id0()
		{
			mu[1] = 1;
			for (size_t i = 2; i < MAXN; ++i)
			{
				size_t p = erato[i];
				if (p != erato[i / p])
				{
					mu_[i] = -mu_[i / p];
				}
				else
				{
					mu_[i] = 0;
				}
			}
		}

		int mu(int x)
		{
			return mu_[x];
		}

		bool is_prime(int x)
		{
			return erato.is_prime(x);
		}

		

		int min_pr_div(int x)
		{
			return erato.min_pr_div(x);
		}

		void get_pr_divs(unsigned long long x, std::vector<unsigned long long>& divs)
		{
			return erato.get_pr_divs(x, divs);
		}
	};

	template<typename T>
	class Diffarray
	{
	public:
		std::vector<T> dif;
		Diffarray(std::vector<T> const& v)
		{
			dif.resize(v.size(), 0);
			for (auto i = 0; i != v.size(); i++)
			{
				dif[i] = (i != 0 ? v[i] - v[i - 1] : v[i]);
			}
		}

		std::vector<T> recover()
		{
			std::vector<T> rec(dif.size(), 0);
			for (size_t i = 0; i < rec.size(); i++)
			{
				rec[i] = (i != 0 ? rec[i - 1] + dif[i] : dif[i]);
			}
			return move(rec);
		}

		

		void addval(unsigned int l, unsigned int r, T val)
		{
			dif[l] += val;
			if (r < dif.size())
				dif[r] -= val;
		}
	};

	template<typename T>
	class id3
	{
	public:
		std::vector<T> preffsum;
		id3(std::vector<T> const& v)
		{
			preffsum.resize(v.size(), 0);
			for (auto i = 0; i != v.size(); i++)
			{
				preffsum[i] = (i != 0 ? v[i] + preffsum[i - 1] : v[i]);
			}
		}

		std::vector<T> recover()
		{
			std::vector<T> rec(preffsum.size(), 0);
			for (size_t i = 0; i < rec.size(); i++)
			{
				rec[i] = (i != 0 ? preffsum[i] - preffsum[i - 1] : preffsum[i]);
			}
			return move(rec);
		}
		

		T get_sum(unsigned int l, unsigned int r)
		{
			return preffsum[r - 1] - preffsum[l - 1];
		}
	};

	template<class T, class Operation>
	class SegTree
	{
		std::vector<T> tree;
		int n;
	public:
		SegTree(std::vector<T> const& v)
			: tree(std::vector<T>(count_size(v.size()), Operation::DefVal())), n(tree.size() / 2)
		{
			for (int i = 0; i < v.size(); ++i)
			{
				tree[i + n] = v[i];
			}
			build();
		}

		void build()
		{
			for (std::size_t i = n - 1; i > 0; --i)
			{
				tree[i] = Operation::compute(tree[i << 1], tree[i << 1 | 1]);
			}
		}
		T query(int l, int r)
		{
			T res = Operation::DefVal();
			for (l += n, r += n; l < r; l >>= 1, r >>= 1)
			{
				if (l & 1) res = Operation::compute(res, tree[l++]);
				if (r & 1) res = Operation::compute(res, tree[--r]);
			}

			return res;
		}
		void update(int i, T const& val)
		{
			i += n;
			for (tree[i] = val; i > 1; i >>= 1)
			{
				tree[i >> 1] = Operation::compute(tree[i], tree[i ^ 1]);
			}
		}
	private:
		static unsigned long long count_size(size_t x)
		{
			return 1ull << (id5(x) + 1);
		}

	};

	enum FenwickQueryType{BEGIN_QUERY, END_QUERY};
	template<class T, class Operation, FenwickQueryType QueryType = BEGIN_QUERY>
	class id8 
	{
		std::vector<T> tree;  
		int n;
	public:
		id8(size_t count)
			: tree(count, Operation::DefVal())
			, n(static_cast<int>(count))
		{
		}

		id8(std::vector<T> const & a) : id8(a.size())
		{
			for (size_t i = 0; i < a.size(); i++)
				update(static_cast<int>(i), a[i]);
		}

		

		

		T query(int r) 
		{
			T ret = Operation::DefVal();

			if constexpr (FenwickQueryType::BEGIN_QUERY == QueryType)
			{
				--r;
				for (; r >= 0; r = (r & (r + 1)) - 1) ret = Operation::compute(tree[r], ret);
			}
			else
				for (; r < n; r = r | (r + 1)) ret = Operation::compute(tree[r], ret);
			return ret;
		}
	
		

		void update(int idx, T const& val) 
		{
			if constexpr (FenwickQueryType::BEGIN_QUERY == QueryType)
				for (; idx < n; idx = idx | (idx + 1)) tree[idx] = Operation::compute(tree[idx], val);
			else
				for (; idx >= 0; idx = (idx & (idx + 1)) - 1) tree[idx] = Operation::compute(tree[idx], val);
		}
	};

	template<typename T, class Operation>
	class SparseTable
	{
		std::vector<std::vector<T> > st;
	public:
		SparseTable(std::vector<T> const& v) 
			: st(ceil(log2(v.size())) + 1, std::vector<T>(v.size(), Operation::DefVal()))
		{
			int h = floor(log2(v.size()));

			for (int j = 0; j < v.size(); j++)
				st[0][j] = v[j];

			for (int i = 1; i <= h; i++)
				for (int j = 0; j + (1 << i) <= v.size(); j++)
					st[i][j] = Operation::compute(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}

		

		T query(int l, int r)
		{
			if (l == r)
				return Operation::DefVal();

			auto const p = id5<unsigned int>(r - l);
			return Operation::compute(st[p][l], st[p][r - (1 << p)]);
		}

	};

	template <typename T, class Operation>
	class id1
	{
	public:
		explicit id1(std::vector<T> arr) 
		{
			

			size_t const cnt = id5(arr.size()) + 1;
			size_t const pow2 = 1ull << cnt;

			arr.resize(pow2, Operation::DefVal());
			st.resize(cnt, std::vector<T>(pow2));

			for (int level = 0; level < st.size(); ++level)
			{
				for (int block = 0; block < 1 << level; ++block)
				{
					const auto start = block << (st.size() - level);
					const auto end = (block + 1) << (st.size() - level);
					const auto middle = (end + start) / 2;

					auto val = arr[middle];
					st[level][middle] = val;
					for (int x = middle + 1; x < end; ++x)
					{
						val = Operation::compute(val, arr[x]);
						st[level][x] = val;
					}

					val = arr[middle - 1];
					st[level][middle - 1] = val;
					for (int x = middle - 2; x >= start; --x)
					{
						val = Operation::compute(val, arr[x]);
						st[level][x] = val;
					}
				}
			}
		}
		

		T query(int l, int r) const
		{
			

			if (--r == l - 1) return Operation::DefVal();
			if (l == r) return st.back()[l];

			

			auto const pos_diff = id5<unsigned int>(l ^ r);
			const auto level = st.size() - 1 - pos_diff;
			return Operation::compute(st[level][l], st[level][r]);
		}
	private:
		std::vector<std::vector<T> > st;
	};

	class DSU
	{
	public:
		DSU(size_t n)
		{
			parent = new size_t[n];
			sz = new size_t[n];
			for (size_t i = 0; i < n; ++i)
			{
				parent[i] = i;
				sz[i] = 1;
			}
		}

		~DSU()
		{
			delete[] parent;
			delete[] sz;
		}

		void union_sets(size_t u, size_t v)
		{
			u = find_parent(u);
			v = find_parent(v);
			if (sz[u] > sz[v]) std::swap(u, v);
			parent[u] = v;
			sz[v] += sz[u];
		}

		bool same_set(size_t u, size_t v)
		{
			return find_parent(u) == find_parent(v);
		}

		size_t find_parent(size_t u)
		{
			if (parent[u] == u)  return u;
			return parent[u] = find_parent(parent[u]);
		}
	private:
		size_t* parent;
		size_t* sz;
	};

	class BigInteger
	{
	private:
		std::string number;
		bool sign;
	public:

		BigInteger() 

		{
			number = "0";
			sign = false;
		}
		

		BigInteger(std::string s) 

		{
			if (isdigit(s[0])) 

			{
				setNumber(s);
				sign = false; 

			}
			else
			{
				setNumber(s.substr(1));
				sign = (s[0] == '-');
			}
		}
		

		BigInteger(std::string s, bool sin) 

		{
			setNumber(s);
			setSign(sin);
		}
		

		BigInteger(int n) 

		{
			std::stringstream ss;
			std::string s;
			ss << n;
			ss >> s;


			if (isdigit(s[0])) 

			{
				setNumber(s);
				setSign(false); 

			}
			else
			{
				setNumber(s.substr(1));
				setSign(s[0] == '-');
			}
		}
		

		void setNumber(std::string s)
		{
			number = s;
		}
		

		const std::string& getNumber() 

		{
			return number;
		}
		

		void setSign(bool s)
		{
			sign = s;
		}
		

		const bool& getSign()
		{
			return sign;
		}
		

		

		BigInteger absolute()
		{
			return BigInteger(getNumber()); 

		}
		

		void operator = (BigInteger b)
		{
			setNumber(b.getNumber());
			setSign(b.getSign());
		}
		

		bool operator == (BigInteger b)
		{
			return equals((*this), b);
		}
		

		bool operator != (BigInteger b)
		{
			return !equals((*this), b);
		}
		

		bool operator > (BigInteger b)
		{
			return greater((*this), b);
		}
		

		bool operator < (BigInteger b)
		{
			return less((*this), b);
		}
		

		bool operator >= (BigInteger b)
		{
			return equals((*this), b)
				|| greater((*this), b);
		}
		

		bool operator <= (BigInteger b)
		{
			return equals((*this), b)
				|| less((*this), b);
		}
		

		

		BigInteger& operator ++() 

		{
			(*this) = (*this) + 1;
			return (*this);
		}
		

		

		BigInteger operator ++(int) 

		{
			BigInteger before = (*this);

			(*this) = (*this) + 1;

			return before;
		}
		

		

		BigInteger& operator --() 

		{
			(*this) = (*this) - 1;
			return (*this);

		}
		

		

		BigInteger operator --(int) 

		{
			BigInteger before = (*this);

			(*this) = (*this) - 1;

			return before;
		}
		

		BigInteger operator + (BigInteger b)
		{
			BigInteger addition;
			if (getSign() == b.getSign()) 

			{
				addition.setNumber(add(getNumber(), b.getNumber()));
				addition.setSign(getSign());
			}
			else 

			{
				if (absolute() > b.absolute())
				{
					addition.setNumber(subtract(getNumber(), b.getNumber()));
					addition.setSign(getSign());
				}
				else
				{
					addition.setNumber(subtract(b.getNumber(), getNumber()));
					addition.setSign(b.getSign());
				}
			}
			if (addition.getNumber() == "0") 

				addition.setSign(false);

			return addition;
		}
		

		BigInteger operator - (BigInteger b)
		{
			b.setSign(!b.getSign()); 

			return (*this) + b;
		}
		

		BigInteger operator * (BigInteger b)
		{
			BigInteger mul;

			mul.setNumber(multiply(getNumber(), b.getNumber()));
			mul.setSign(getSign() != b.getSign());

			if (mul.getNumber() == "0") 

				mul.setSign(false);

			return mul;
		}
		

		

		BigInteger operator / (BigInteger b)
		{
			long long den = toInt(b.getNumber());
			BigInteger div;

			div.setNumber(divide(getNumber(), den).first);
			div.setSign(getSign() != b.getSign());

			if (div.getNumber() == "0") 

				div.setSign(false);

			return div;
		}
		

		

		BigInteger operator % (BigInteger b)
		{
			long long den = toInt(b.getNumber());

			BigInteger rem;
			long long rem_int = divide(number, den).second;
			rem.setNumber(toString(rem_int));
			rem.setSign(getSign() != b.getSign());

			if (rem.getNumber() == "0") 

				rem.setSign(false);

			return rem;
		}
		

		BigInteger& operator += (BigInteger b)
		{
			(*this) = (*this) + b;
			return (*this);
		}
		

		BigInteger& operator -= (BigInteger b)
		{
			(*this) = (*this) - b;
			return (*this);
		}
		

		BigInteger& operator *= (BigInteger b)
		{
			(*this) = (*this) * b;
			return (*this);
		}
		

		BigInteger& operator /= (BigInteger b)
		{
			(*this) = (*this) / b;
			return (*this);
		}
		

		BigInteger& operator %= (BigInteger b)
		{
			(*this) = (*this) % b;
			return (*this);
		}
		

		BigInteger& operator [] (int n)
		{
			return *(this + (n * sizeof(BigInteger)));
		}
		

		BigInteger operator -() 

		{
			return (*this) * -1;
		}
		

		operator std::string() 

		{
			std::string signedString = (getSign()) ? "-" : ""; 

			signedString += number;
			return signedString;
		}
		

	private:
		bool equals(BigInteger n1, BigInteger n2)
		{
			return n1.getNumber() == n2.getNumber()
				&& n1.getSign() == n2.getSign();
		}

		

		bool less(BigInteger n1, BigInteger n2)
		{
			bool sign1 = n1.getSign();
			bool sign2 = n2.getSign();

			if (sign1 && !sign2) 

				return true;

			else if (!sign1 && sign2)
				return false;

			else if (!sign1) 

			{
				if (n1.getNumber().length() < n2.getNumber().length())
					return true;
				if (n1.getNumber().length() > n2.getNumber().length())
					return false;
				return n1.getNumber() < n2.getNumber();
			}
			else 

			{
				if (n1.getNumber().length() > n2.getNumber().length())
					return true;
				if (n1.getNumber().length() < n2.getNumber().length())
					return false;
				return n1.getNumber().compare(n2.getNumber()) > 0; 

			}
		}
		

		bool greater(BigInteger n1, BigInteger n2)
		{
			return !equals(n1, n2) && !less(n1, n2);
		}

		

		

		std::string add(std::string number1, std::string number2)
		{
			std::string add = (number1.length() > number2.length()) ? number1 : number2;
			char carry = '0';
			int id6 = abs((int)(number1.size() - number2.size()));

			if (number1.size() > number2.size())
				number2.insert(0, id6, '0'); 


			else

				number1.insert(0, id6, '0');

			for (int i = static_cast<int>(number1.size()) - 1; i >= 0; --i)
			{
				add[i] = ((carry - '0') + (number1[i] - '0') + (number2[i] - '0')) + '0';

				if (i != 0)
				{
					if (add[i] > '9')
					{
						add[i] -= 10;
						carry = '1';
					}
					else
					{
						carry = '0';
					}
				}
			}
			if (add[0] > '9')
			{
				add[0] -= 10;
				add.insert(0, 1, '1');
			}
			return add;
		}

		

		

		std::string subtract(std::string number1, std::string number2)
		{
			std::string sub = (number1.length() > number2.length()) ? number1 : number2;
			int id6 = abs((int)(number1.size() - number2.size()));

			if (number1.size() > number2.size())
				number2.insert(0, id6, '0');

			else
				number1.insert(0, id6, '0');

			for (int i = static_cast<int>(number1.length()) - 1; i >= 0; --i)
			{
				if (number1[i] < number2[i])
				{
					number1[i] += 10;
					number1[i - 1]--;
				}
				sub[i] = ((number1[i] - '0') - (number2[i] - '0')) + '0';
			}

			while (sub[0] == '0' && sub.length() != 1) 

				sub.erase(0, 1);

			return sub;
		}

		

		

		std::string multiply(std::string n1, std::string n2)
		{
			if (n1.length() > n2.length())
				n1.swap(n2);

			std::string res = "0";
			for (int i = static_cast<int>(n1.length()) - 1; i >= 0; --i)
			{
				std::string temp = n2;
				int currentDigit = n1[i] - '0';
				int carry = 0;

				for (int j = static_cast<int>(temp.length()) - 1; j >= 0; --j)
				{
					temp[j] = ((temp[j] - '0') * currentDigit) + carry;

					if (temp[j] > 9)
					{
						carry = (temp[j] / 10);
						temp[j] -= (carry * 10);
					}
					else
						carry = 0;

					temp[j] += '0'; 

				}

				if (carry > 0)
					temp.insert(0, 1, (carry + '0'));

				temp.append((n1.length() - i - 1), '0'); 


				res = add(res, temp); 

			}

			while (res[0] == '0' && res.length() != 1) 

				res.erase(0, 1);

			return res;
		}

		

		

		std::pair<std::string, long long> divide(std::string n, long long den)
		{
			long long rem = 0;
			std::string result; result.resize(10000);

			for (int indx = 0, len = static_cast<int>(n.length()); indx < len; ++indx)
			{
				rem = (rem * 10) + (n[indx] - '0');
				result[indx] = static_cast<char>(rem / den) + '0';
				rem %= den;
			}
			result.resize(n.length());

			while (result[0] == '0' && result.length() != 1)
				result.erase(0, 1);

			if (result.length() == 0)
				result = "0";

			return make_pair(result, rem);
		}

		

		

		std::string toString(long long n)
		{
			std::stringstream ss;
			std::string temp;

			ss << n;
			ss >> temp;

			return temp;
		}

		

		

		long long toInt(std::string s)
		{
			long long sum = 0;

			for (int i = 0; i < s.length(); i++)
				sum = (sum * 10) + (s[i] - '0');

			return sum;
		}

	};

	

	class id4
	{
	public:
		std::vector<std::map<char, int>> edges; 

		std::vector<int> link;            

		std::vector<int> length;          

		std::string cur_str;
		int last;                    

		int count;

		id4(std::string const& s)
			: cur_str(s)
			, last(0)
			, count(0)
		{
			

			edges.push_back(std::map<char, int>());
			link.push_back(-1);
			length.push_back(0);
			for (; count < s.size(); count++) {
				

				edges.emplace_back();
				length.push_back(count + 1);
				link.push_back(0);
				int r = static_cast<int>(edges.size()) - 1;

				

				int p = last;
				while (p >= 0 && edges[p].find(s[count]) == edges[p].end()) {
					edges[p][s[count]] = r;
					p = link[p];
				}
				if (p != -1) {
					int q = edges[p][s[count]];
					if (length[p] + 1 == length[q]) {
						

						link[r] = q;
					}
					else {
						

						edges.push_back(edges[q]); 

						length.push_back(length[p] + 1);
						link.push_back(link[q]); 

						int qq = static_cast<int>(edges.size()) - 1;
						

						link[q] = qq;
						link[r] = qq;
						

						while (p >= 0 && edges[p][s[count]] == q) {
							edges[p][s[count]] = qq;
							p = link[p];
						}
					}
				}
				last = r;
			}
		}

		void extend(char c)
		{
			edges.emplace_back();
			length.push_back(++count);
			link.push_back(0);
			int r = static_cast<int>(edges.size()) - 1;

			

			int p = last;
			while (p >= 0 && edges[p].find(c) == edges[p].end()) {
				edges[p][c] = r;
				p = link[p];
			}
			if (p != -1) {
				int q = edges[p][c];
				if (length[p] + 1 == length[q]) {
					

					link[r] = q;
				}
				else {
					

					edges.push_back(edges[q]); 

					length.push_back(length[p] + 1);
					link.push_back(link[q]); 

					int qq = static_cast<int>(edges.size()) - 1;
					

					link[q] = qq;
					link[r] = qq;
					

					while (p >= 0 && edges[p][c] == q) {
						edges[p][c] = qq;
						p = link[p];
					}
				}
			}
			last = r;
			cur_str.push_back(c);
		}

		std::string lcs(std::string const& str)
		{
			int v = 0, l = 0, best = 0, bestpos = 0;
			for (int i = 0; i < str.size(); i++) {
				while (v && !edges[v].count(str[i])) {
					v = link[v];
					l = length[v];
				}
				if (edges[v].count(str[i])) {
					v = edges[v][str[i]];
					l++;
				}
				if (l > best) {
					best = l;
					bestpos = i;
				}
			}
			return str.substr(bestpos - best + 1, best);
		}

		bool is_lcs(std::string const& str)
		{
			bool fail = false;
			int n = 0;
			for (int i = 0; i < str.size(); i++) {
				if (edges[n].find(str[i]) == edges[n].end()) {
					fail = true;
					break;
				}
				n = edges[n][str[i]];
			}
			return !fail;
		}
	};

	class PrefixFunction
	{
	public:
		void operator()(std::string const& s, std::vector<int>& res)
		{
			int n = static_cast<int>(s.length());
			res.assign(n, 0);
			for (int i = 1; i < n; i++) {
				int j = res[i - 1];
				while (j > 0 && s[i] != s[j])
					j = res[j - 1];
				if (s[i] == s[j])
					j++;
				res[i] = j;
			}
		}
	};

	class SuffixFunction
	{
	public:
		void operator()(std::string const& s, std::vector<int>& res)
		{
			int n = static_cast<int>(s.length());
			res.assign(n, 0);
			for (int i = n - 2; i >= 0; i--) {
				int j = res[i + 1];
				while (j > 0 && s[i] != s[n - j - 1])
					j = res[n - j];
				if (s[i] == s[n - j - 1])
					j++;
				res[i] = j;
			}
		}
	};

	class ZFunction
	{
	public:
		void operator()(std::string const& s, std::vector<int>& res)
		{
			int n = static_cast<int>(s.length());
			res.assign(n, 0);
			for (int i = 1, l = 0, r = 0; i < n; ++i) 
			{
				if (i <= r)
					res[i] = std::min(r - i + 1, res[i - l]);
				while (i + res[i] < n && s[res[i]] == s[i + res[i]])
					++res[i];
				if (i + res[i] - 1 > r)
					l = i, r = i + res[i] - 1;
			}
		}
	};

	struct id10 final
	{
		

		

		std::size_t m;
		std::size_t n;

		

		

		

		std::vector<std::list<int> > adj;

		

		id10(int m, int n)
			: m(m)
			, n(n)
			, adj(m + 1)

		{
		}

		

		

		void addEdge(int u, int v)
		{
			adj[u].push_back(v); 

		}
	};

	class id2 final
	{
		

		

		

		std::vector<int> pairU;

		

		

		std::vector<int> pairV;

		

		

		

		std::vector<int> dist;

		id10 const& bg;
		int inf;
	public:
		id2(id10 const& id7)
			: pairU(id7.m + 1)
			, pairV(id7.n + 1)
			, dist(id7.m + 1)
			, bg(id7)
			, inf(2147483647)
		{
		}

		

		int run()
		{
			

			int result = 0;

			

			

			while (bfs())
			{
				

				for (int u = 1; u <= bg.m; u++)

					

					

					if (pairU[u] == 0 && dfs(u))
						result++;
			}
			return result;
		}
		
		std::vector<int> const& get_pairU() const
		{
			return pairU;
		}
		std::vector<int> const& get_pairV() const
		{
			return pairV;
		}

	private:
		

		bool bfs()
		{
			std::queue<int> Q; 


			

			for (int u = 1; u <= bg.m; u++)
			{
				

				if (pairU[u] == 0)
				{
					

					dist[u] = 0;
					Q.push(u);
				}

				

				

				else dist[u] = inf;
			}

			

			dist[0] = inf;

			

			while (!Q.empty())
			{
				

				int u = Q.front();
				Q.pop();

				

				if (dist[u] < dist[0])
				{
					

					std::list<int>::const_iterator i;
					for (i = bg.adj[u].begin(); i != bg.adj[u].end(); ++i)
					{
						int v = *i;

						

						

						if (dist[pairV[v]] == inf)
						{
							

							dist[pairV[v]] = dist[u] + 1;
							Q.push(pairV[v]);
						}
					}
				}
			}

			

			

			return (dist[0] != inf);
		}

		

		bool dfs(int u)
		{
			if (u != 0)
			{
				std::list<int>::const_iterator i;
				for (i = bg.adj[u].begin(); i != bg.adj[u].end(); ++i)
				{
					

					int v = *i;

					

					if (dist[pairV[v]] == dist[u] + 1)
					{
						

						

						if (dfs(pairV[v]) == true)
						{
							pairV[v] = u;
							pairU[u] = v;
							return true;
						}
					}
				}

				

				dist[u] = inf;
				return false;
			}
			return true;
		}
	};

	class Kuhn final
	{
		std::vector<int> mt; 

		std::vector<char> used;
		id10 const& bg;
	public:
		Kuhn(id10 const& id7)
			: mt(id7.n + 1, 0)
			, bg(id7)
		{
		}

		std::vector<int> const & run()
		{
			for (size_t i = 1; i <= bg.m; ++i)
			{
				used.assign(bg.m + 1, 0);
				attempt(i);
			}
			return mt;
		}

	private:
		bool attempt(int v)
		{
			if (used[v] == 1)
				return false;
			used[v] = 1;
			for (std::list<int>::const_iterator to = bg.adj[v].begin(); to != bg.adj[v].end(); ++to) {
				if (mt[*to] == 0 || attempt(mt[*to])) {
					mt[*to] = v;
					return true;
				}
			}
			return false;
		}
	};
}

using namespace abesse;
using namespace std;








typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;




void solve()
{
	ll w, l;
	cin >>w>>l;
	ll g1 = gcd(w - 1, l - 1);
	ll g2 = gcd(w, l - 2);
	ll g3 = gcd(w - 2, l);
	set <ll> s;
	for (int i = 1; i * i  <= g1; i++)
	{
		if(g1 % i == 0)
		{
			s.insert(i);
			s.insert(g1 / i);
		}
	}
	for (int i = 1; i * i  <= g2; i++)
	{
		if(g2 % i == 0)
		{
			s.insert(i);
			s.insert(g2 / i);
		}
	}
	for (int i = 1; i * i  <= g3; i++)
	{
		if(g3 % i == 0)
		{
			s.insert(i);
			s.insert(g3 / i);
		}
	}

	ll g4 = gcd(w, w - 2);
	g4 = gcd(l - 1, g4);
	ll g5 = gcd(l, l - 2);
	g5 = gcd(w - 1, g5);
	s.insert(g4);
	s.insert(g5);

	cout <<s.size() << " ";
	for(auto i = s.begin(); i != s.end(); ++i)
	{
		cout << *i << " ";
	}
	cout <<endl;
}


int main(int argc, char const** argv)
{

	freopen("in.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int  mult = 1;
	int x = 1;
	if (mult)
		std::cin >> x;
	while (x --> 0)
	{
		solve();
	}

	return 0;
}