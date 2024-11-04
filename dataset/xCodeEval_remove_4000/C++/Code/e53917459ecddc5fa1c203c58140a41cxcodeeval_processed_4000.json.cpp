










typedef unsigned int index;

namespace temp
{
	template<class Element> class RangeTree
	{
		private:
			Element *elements;
			std::pair<index, index> *childrens;
			size_t my_size;
			std::function<Element (const Element&, const Element&)> func;

			index build(index tl, size_t tr, index &last)
			{
				if (tr - tl == 1)
				{
					return my_size + tl - 1;
				}
				index v = last;
				last++;
				size_t tm = (tl + tr) / 2;
				childrens[v] = {build(tl, tm, last), build(tm, tr, last)};
				elements[v] = func(elements[childrens[v].first], elements[childrens[v].second]); 
				return v;
			}

			Element get(index v, index tl, size_t tr, index l, size_t r)
			{
				if (l <= tl and tr <= r)
				{
					return elements[v];
				}
				size_t tm = (tl + tr) / 2;
				if (tm <= l)
				{
					return get(childrens[v].second, (index)tm, tr, l, r);
				}
				else if (tm >= r)
				{
					return get(childrens[v].first, tl, tm, l, r);
				}
				else
				{
					return func(get(childrens[v].first, tl, tm, l, r), get(childrens[v].second, (index)tm, tr, l, r));
				}
			}

			void set(index v, index tl, size_t tr, index pos, const Element &el)
			{
				if (pos < tl or pos >= tr)
					return;
				if (tr - tl == 1)
				{
					elements[v] = el;
					return;
				}
				size_t tm = (tl + tr) / 2;
				set(childrens[v].first, tl, tm, pos, el);
				set(childrens[v].second, (index)tm, tr, pos, el);
				elements[v] = func(elements[childrens[v].first], elements[childrens[v].second]); 
			}

		public:
			template<class T> RangeTree(const T &begin, const T &end, const std::function<Element (const Element&, const Element&)> &new_func): my_size(0), func(new_func)
			{
				for (T i = begin; i != end; i++)
					my_size++;
				assert(my_size > 0);
				elements = new Element[my_size * 2 - 1];
				childrens = new std::pair<index, index>[my_size - 1];
				index j = 0;
				for (T i = begin; i != end; i++, j++)
				{
					elements[j + my_size - 1] = *i;
				}
				index last = 0;
				build(0, my_size, last);
			}

			Element get(index l, size_t r)
			{
				return get(0, 0, my_size, l, r);
			}

			size_t size()
			{
				return my_size;
			}
			
			void set(index pos, const Element &el)
			{
				set(0, 0, my_size, pos, el);
			}

	};

	template<class Element> class PrefixSum
	{
	private:
		Element *all;
		size_t my_size;
		std::function<Element (Element, Element)> &func, &obr_func;
	public:
		template<class Iterator>
		inline PrefixSum(Iterator begin, Iterator end,
				std::function<Element (Element, Element)> new_func,
				std::function<Element (Element, Element)> id0): my_size(0), func(new_func), obr_func(id0)
		{
			my_size = end - begin;
			all = new Element[my_size];
			for (index i = 0; i < my_size; i++)
				all[i] = *begin, begin++;
			for (index i = 1; i < my_size; i++)
				all[i] = func(all[i - 1], all[i]);
		}

		inline Element get(index l, size_t r) const
		{
			if (l == 0)
				return all[r - 1];
			else
				return obr_func(all[r - 1], all[l - 1]);
		}

		inline size_t size() const
		{
			return my_size;
		}
	};

	template<class Element> class id1
	{
		private:
			size_t my_size, *my_log;
			Element **table;
			std::function<Element (Element, Element)> func;
		public:
			template <class Iterator> id1(Iterator begin, Iterator end, std::function<Element (Element, Element)> new_func): func(new_func)
			{
				Iterator copy = begin;
				my_size = 0;
				while (copy != end)
				{
					copy++;
					my_size++;
				}
				my_log = new size_t[my_size + 1];
				size_t cur = 0;
				for (index i = 0; i < my_size + 1; i++)
				{
					if ((1u << (cur + 1)) < i)
						cur++;
					my_log[i] = cur;
				}
				table = new Element*[my_log[my_size] + 1];
				for (index i = 0; i <= my_log[my_size]; i++)
				{
					table[i] = new Element[my_size];
				}
				for (index i = 0; i < my_size; i++)
				{
					table[0][i] = *begin;
					begin++;
				}
				for (index i = 1; i <= my_log[my_size]; i++)
				{
					for (index j = 0; j + (1 << i) - 1 < my_size; j++)
					{
						table[i][j] = func(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
					}
				}
			}

			Element get(index l, size_t r) const 
			{
				return func(table[my_log[r - l]][l], table[my_log[r - l]][r - (1 << my_log[r - l])]);
			}

			size_t size() const
			{
				return my_size;
			}
	};

	template<class Element> class MinQueue
	{
		private:
			std::vector<std::pair<Element, Element>> left;
			std::vector<Element> right;
			std::function<bool (Element, Element)> func;
		public:
			MinQueue(std::function<bool (Element, Element)> new_func): func(new_func){};

			size_t size() const
			{
				return left.size() + right.size();
			}

			Element get_min() const
			{
				assert(size() > 0);
				if (left.size() == 0)
					return right.back();
				else if (right.size() == 0)
					return left.back().second;
				else if(func(left.back().second, right.back()))
					return left.back().second;
				else
					return right.back();
			}

			void pop_front()
			{
				assert(size() > 0);
				if (right.size() == 0)
				{
					while (left.size())
					{
						right.push_back(right.size() ? (func(left.back().first, right.back()) ? left.back().first : right.back()) : left.back().first);
						left.pop_back();
					}
				}
				right.pop_back();
			}

			void push(const Element &a)
			{
				left.push_back({a, (left.size() ? (func(left.back().second, a) ? left.back().second : a) : a)});
			}

	};

	template<unsigned int MOD> class RingElement
	{

	private:
			constexpr static unsigned long long find_phi(unsigned long long p)
			{
				unsigned long long res = p;
				for (unsigned long long i = 2; i * i <= p; i++)
				{
					if (p % i == 0)
					{
						while (p % i == 0)
							p /= i;
						res -= res / i;
					}
				}
				if (p > 1)
				{
					res -= res / p;
				}
				return res;
			}
			unsigned int me;
			const static unsigned int PHI = find_phi(MOD);
			static RingElement<MOD> pow(RingElement<MOD> a, unsigned long long b)
			{
				b = b % PHI;
				RingElement<MOD> res = 1;
				while (b > 0)
				{
					if (b % 2 == 0)
					{
						a = a * a;
						b /= 2;
					}
					else
					{
						res = res * a;
						b--;
					}
				}
				return res;
			}

			static unsigned int gcd(unsigned int a, unsigned int b)
			{
				while (a != 0)
				{
					unsigned int c = a;
					a = a % b;
					b = c;
				}
				return b;
			}

		public:
			RingElement(unsigned long long new_me): me(new_me % MOD){}
			RingElement(): me(0){}

		unsigned long long get_phi() const
		{
			return PHI;
		}

		friend std::istream &operator >>(std::istream &a, RingElement<MOD> &b)
		{
			a >> b.me;
			b.me = b.me % MOD;
			return a;
		}

		friend std::ostream &operator <<(std::ostream &a, const RingElement<MOD> &b)
		{
			a << b.me;
			return a;
		}

		friend RingElement<MOD> operator +(const RingElement<MOD> &a, const RingElement<MOD> &b)
		{
			return {a.me + b.me >= MOD ? a.me + b.me - MOD : a.me + b.me};
		}

		friend RingElement<MOD> operator -(const RingElement<MOD> &a, const RingElement<MOD> &b)
		{
			return {a.me >= b.me ? a.me - b.me : a.me - b.me + MOD};
		}

		friend RingElement<MOD> operator *(const RingElement<MOD> &a, const RingElement<MOD> &b)
		{
			return {(unsigned long long)a.me * b.me};
		}

		friend RingElement<MOD> operator /(const RingElement<MOD> &a, const RingElement<MOD> &b)
		{

			assert(gcd(b.me, MOD) == 1);

			return a.me * pow(b, PHI - 1);
		}

		RingElement<MOD> operator++()
		{
			me++;
			if (me == MOD)
				me = 0;
			return *this;
		}

		RingElement<MOD> &operator++(int)
		{
			RingElement<MOD> cp = *this;
			me++;
			if (me == MOD)
				me = 0;
			return cp;
		}

		RingElement<MOD> operator--()
		{
			me--;
			if (me > MOD)
				me = MOD - 1;
			return *this;
		}

		RingElement<MOD> &operator--(int)
		{
			RingElement<MOD> cp = *this;
			me--;
			if (me > MOD)
				me = MOD - 1;
			return cp;
		}

		RingElement<MOD> &operator +=(const RingElement<MOD> &a)
		{
			me = (*this + a).me;
		}

		RingElement<MOD> &operator -=(const RingElement<MOD> &a)
		{
			me = (*this - a).me;
		}

		RingElement<MOD> &operator *=(const RingElement<MOD> &a)
		{
			me = (*this * a).me;
		}

		RingElement<MOD> &operator /=(const RingElement<MOD> &a)
		{
			me = (*this / a).me;
		}

		friend bool operator ==(const RingElement<MOD> &a, const RingElement<MOD> &b)
		{
			return a.me == b.me;
		}

		friend bool operator !=(const RingElement<MOD> &a, const RingElement<MOD> &b)
		{
			return a.me != b.me;
		}

	};
	

	template<unsigned long MOD>
	RingElement<MOD> pow(RingElement<MOD> a, unsigned long long b)
	{
		b = b % a.get_phi();
		RingElement<MOD> res = 1;
		while (b > 0)
		{
			if (b % 2 == 0)
			{
				a = a * a;
				b /= 2;
			}
			else
			{
				res = res * a;
				b--;
			}
		}
		return res;
	}
}

using namespace std;

void dfs(index v, const vector<set<index>> &g, vector<index> &ans, vector<bool> &used)
{
	if (v == 0)
		return;
	used[v] = true;
	ans.push_back(v);
	for (auto i: g[v])
		if (!used[i])
			dfs(i, g, ans, used);
}

vector<index> tans(index v, const vector<set<index>> &g, vector<bool> &used)
{
	vector<index> fld;
	dfs(v, g, fld, used);
	for (index i = 2; i < fld.size(); i++)
	{
		if (g[fld[i]].count(fld[0]) == 1)
		{
			for (index j = 1; j < i; j++)
			{
				if (g[fld[i]].count(fld[j]) == 0)
				{
					return {fld[i], fld[j - 1], fld[j]};
				}
			}
		}
		else
		{
			for (index j = 1; j < i; j++)
			{
				if (g[fld[i]].count(fld[j]) == 1)
				{
					return {fld[i], fld[j], fld[j - 1]};
				}
			}
		}
	}
	return {};
}

int main()
{

	assert(freopen("a.in", "r", stdin));
	assert(freopen("a.out", "w", stdout));


	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	size_t n, m;
	cin >> n >> m;
	vector<set<index>> g(n);
	for (index i = 0; i < m; i++)
	{
		index l, r;
		cin >> l >> r;
		l--, r--;
		g[l].insert(r);
		g[r].insert(l);
	}
	vector<vector<index>> bfs = {{0}};
	vector<index> p(n, (index)-1);
	vector<size_t> dist(n, ULONG_MAX / 2);
	p[0] = 0;
	dist[0] = 0;
	while (true)
	{
		vector<index> cur;
		for (auto i: bfs.back())
		{
			for (auto j: g[i])
			{
				if (p[j] == (index)-1)
				{
					p[j] = i;
					cur.push_back(j);
					dist[j] = bfs.size();
				}
			}
		}
		if (cur.size() == 0)
			break;
		bfs.push_back(cur);
	}
	size_t ans = dist[n - 1];
	vector<index> anss;
	if (ans != ULONG_MAX / 2)
	{
		index cur = (index)n - 1;
		while (cur != 0)
		{
			anss.push_back(cur);
			cur = p[cur];
		}
		anss.push_back(0);
		reverse(anss.begin(), anss.end());
	}
	if (bfs.size() > 2)
	{
		if (ans > 4)
		{
			ans = 4;
			index cr = bfs[2][0];
			anss = {0, p[cr], cr, 0, (index)n - 1};
		}
	}
	else if (bfs.size() == 2)
	{
		if (ans > 5)
		{
			vector<index> x;
			vector<bool> used(n);
			for (auto i: bfs[1])
			{
				if (!used[i])
				{
					x = tans(i, g, used);
					if (x.size() > 0)
						break;
				}
			}
			if (x.size())
			{
				ans = 5;
				anss = {0, x[0], x[1], x[2], x[0], (index)n - 1};
			}
		}
	}
	if (anss.size() == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << anss.size() - 1 << endl;
		for (auto i: anss)
			cout << i + 1 << " ";
		cout << endl;
	}
}

