































namespace olymp::utils {

inline clock_t &id2()
{
	static clock_t id4;
	return id4;
}

inline clock_t &id11()
{
	static clock_t id8;
	return id8;
}

inline void id1()
{
	auto &id12 = id2();
	auto &id7 = id11();
	id12 = id7 = clock();
}

inline double id5()
{
	const auto &t0 = id2();
	auto t1 = clock();
	return (t1 - t0) * 1000.0 / CLOCKS_PER_SEC;
}

inline double id10()
{
	auto &t0 = id11();
	auto t1 = clock();
	double result = (t1 - t0) * 1000.0 / CLOCKS_PER_SEC;
	t0 = t1;
	return result;
}

inline void id13([[maybe_unused]] std::string_view step_name = {})
{


	if (step_name.empty()) {
		fprintf(stderr, "Step time = %0.0lf ms\n", id10());
	}
	else {
		fprintf(stderr, "Step '");
		fwrite(step_name.data(), 1, step_name.size(), stderr);
		fprintf(stderr, "' time = %0.0lf ms\n", id10());
	}


}

inline void id3()
{


	fprintf(stderr, "Execution time = %0.0lf ms\n", id5());


}

}  


namespace olymp::utils {

class rnd_t {
public:
	template<typename int_t = int>
	int_t get()
	{
		if constexpr (gen_.max() >= std::numeric_limits<int_t>::max()) {
			return gen_() & std::numeric_limits<int_t>::max();
		}
		else {
			std::uniform_int_distribution<int_t> d(0, std::numeric_limits<int_t>::max());
			return d(gen_);
		}
	}
	
	template<typename int_t = int>
	int_t operator () ()
	{
		return get<int_t>();
	}
	
	template<typename int_t>
	int_t operator () (int_t n)
	{
		std::uniform_int_distribution<int_t> d(0, n - 1);
		return d(gen_);
	}
	
	template<typename int_l_t, typename int_r_t>
	std::common_type_t<int_l_t, int_r_t> operator () (int_l_t l, int_r_t r)
	{
		std::uniform_int_distribution<std::common_type_t<int_l_t, int_r_t>> d(l, r);
		return d(gen_);
	}
	
	template<typename int_t>
	void seed(int_t &&value)
	{
		gen_.seed(std::forward<int_t>(value));
	}
	
	std::mt19937 &gen() { return gen_; }
	
	template<typename it_t>
	void shuffle(it_t b, it_t e)
	{
		std::shuffle(b, e, gen());
	}
	
	template<typename int_t>
	void discard(int_t n)
	{
		gen_.discard(n);
	}

private:
	std::mt19937 gen_{311311311};
};


thread_local

static inline rnd_t rnd;

}  


namespace olymp::utils {

template<typename a_t, typename b_t, typename less_t = std::less<a_t>>
inline constexpr std::enable_if_t<
	std::is_same_v<std::common_type_t<a_t, std::decay_t<b_t>>, a_t>,
	bool
> uin(a_t &a, b_t &&b, less_t &&less = less_t())
{
	return less(b, a) ? a = std::forward<b_t>(b), true : false;
}

template<typename a_t, typename b_t, typename less_t = std::less<a_t>>
inline constexpr std::enable_if_t<
	std::is_same_v<std::common_type_t<a_t, std::decay_t<b_t>>, a_t>,
	bool
> uax(a_t &a, b_t &&b, less_t &&less = less_t())
{
	return less(a, b) ? a = std::forward<b_t>(b), true : false;
}

}  












using olymp::utils::id13;
using olymp::utils::id3;
using olymp::utils::rnd;

template <class _T> inline _T sqr(const _T &x) { return x * x; }

namespace olymp {

__attribute__((constructor)) inline void init_main()
{
	utils::id1();
}

__attribute__((destructor)) inline void id6()
{
	utils::id3();
}

}  


using namespace olymp;
using namespace std;
using utils::uax;
using utils::uin;



using ld = long double;


using i64 = long long;
using u64 = unsigned long long;





const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;








int n;
int a[1024000];
int s[1024000];


int mal[1024000];


int d[1024000][2];
int up[1024000];
int dn[1024000];
bool eu[1024000];
bool ed[1024000];

int id9()
{
	int mj = 0;
	int ma = -1;




	forn(i, n)
	{
		if (uax(ma, a[i])) mj = i;
	}
	int fr = n;


	int ss = 0;
	For(i, mj + 1, n - 1)
	{
		if (a[i] > a[i - 1])
		{


			fr = i - 1;
			while (fr > mj && a[fr - 1] < a[i]) --fr;
			break;
		}
	}

	Ford(i, n - 1, mj)
	{
		int t = lower_bound(s, s + ss, a[i], greater<int>()) - s;
		if (t < ss) s[t] = a[i];
		else s[ss++] = a[i];






	}
	if (ss > 2) return 0;


	For(i, 0, mj)
	{








		mal[i] = i;
		if (i > 0 && a[mal[i - 1]] > a[i]) mal[i] = mal[i - 1];
	}
	For(i, 0, mj)
	{
		if (i == 0)
		{
			d[i][0] = a[i];
			d[i][1] = -1;
		}
		else
		{
			d[i][0] = d[i - 1][0];
			d[i][1] = d[i - 1][1];
			if (a[i] > d[i][0])
			{
				d[i][0] = a[i];
			}
			else
			{
				if (a[i] > d[i][1])
				{
					d[i][1] = a[i];
				}
				else
				{
					d[i][1] = 0x7f7f7f7f;
				}
			}
		}
	}








	int uu = 0;
	int dd = 0;
	int ans = 0;
	bool ff = true;
	int mi = -1;
	a[n] = -1;
	if (fr < n)
	{
		dn[dd++] = fr;
		mi = a[fr];
	}
	else
	{
		dn[dd++] = n;
	}
	up[uu++] = mj;
	int mode = 0;
	Ford(i, mj - 1, 0)
	{


		eu[i] = false;
		ed[i] = false;
		if (mode == 0)
		{
			while (uu > 1 && a[up[uu - 1]] < a[i])
			{
				int x = up[uu - 1];
				if (ed[x])
				{
					mode = 1;
					break;
				}
				else
				{
					eu[x] = true;
					--uu;
				}
			}
		}
		if (mode == 0)
		{
			while (dd > 1 && a[dn[dd - 1]] > a[i])
			{
				int x = dn[dd - 1];
				if (eu[x])
				{
					mode = 1;
					break;
				}
				else
				{
					ed[x] = true;
					--dd;
				}
			}
		}
		if (mode == 0 && a[i] < a[dn[dd - 1]])
		{
			mode = 1;
		}


		if (mode == 0)
		{
			up[uu++] = i;
			dn[dd++] = i;
		}
		else
		{
			assert(dd > 0);
			assert(uu > 0);
			if (a[i] > a[dn[dd - 1]]) dn[dd++] = i;
			else if (a[i] < a[up[uu - 1]]) up[uu++] = i;
			else break;
		}


		if (a[i] > a[i + 1]) ff = false;
		if (d[i][1] >= 0x7f7f7f7f) continue;
		if (a[i] < mi) continue;




		if (ff)
		{
			if (d[i][0] > a[i])
			{
				if (d[i][0] > a[i + 1]) continue;
				assert(d[i][1] == a[i]);
			}
			else
			{
				

			}
		}
		else
		{
			if (a[mal[i]] > a[i])
			{
				assert(a[mal[i]] == d[i][0]);
				if (mode == 0)
				{




					if (uu > 1 && a[up[uu - 2]] < d[i][0]) continue;
				}
				else
				{
					continue;
				}






			}
			else
			{
				assert(a[mal[i]] == a[i]);
				int lim = d[i][1];


				if (mode == 0)
				{
					if (uu > 1)
					{
						assert(dd > 0);
						if (a[up[uu - 1]] < a[i])
						{
							if (uu > 1 && a[up[uu - 2]] < lim) continue;
							if (a[dn[0]] < mi) continue;
						}
						else
						{
							if (dd > 1 && a[dn[dd - 2]] > a[i]) continue;
							if (dd > 0 && a[dn[0]] < mi) continue;
						}
					}
					else
					{
						if (dd > 1 && a[dn[0]] < mi) continue;
						

					}
				}
				else
				{
					if (a[dn[dd - 1]] > a[i]) continue;
					if (a[dn[0]] < mi) continue;
					if (a[up[uu - 1]] < lim) continue;
				}
			}
		}


		++ans;
	}
	return ans;
}

int id0()
{
	int ans = 0;
	int ma = -1;
	int mj = 0;
	forn(i, n)
	{
		if (uax(ma, a[i]))
		{
			mj = i;
		}
	}
	forn(i, n)
	{
		if (mj == i) continue;
		bool ok = false;
		forn(mask, 1 << n)
		{
			if (!((mask >> mj) & 1)) continue;
			if ((mask >> i) & 1) continue;
			auto check = [&](int top_idx, int bit) {
				int prev = a[top_idx];
				ford(j, top_idx)
				{
					if (((mask >> j) & 1) != bit) continue;
					if (a[j] > prev) return false;
					prev = a[j];
				}
				prev = a[top_idx];
				For(j, top_idx + 1, n - 1)
				{
					if (((mask >> j) & 1) != bit) continue;
					if (a[j] > prev) return false;
					prev = a[j];
				}
				return true;
			};
			
			if (!check(mj, 1)) continue;
			if (!check(i, 0)) continue;
			ok = true;
			break;
		}
		if (ok) ++ans;
	}
	return ans;
}

int solve()
{
	int ans = id9();


	reverse(a, a + n);
	ans += id9();
	reverse(a, a + n);
	return ans;
}

void stress(int nn)
{
	n = nn;
	forn(i, n)
	{
		a[i] = i + 1;
	}
	int cnt = 0;
	do
	{
		int dull = id0();
		int ans = solve();
		if (ans != dull)
		{
			cout << "Botwa!!!\n";
			cout << n << "\n";
			forn(i, n)
			{
				cout << a[i] << " \n"[i == n - 1];
			}
			return;
		}
		++cnt;
	}
	while (next_permutation(a, a + n));
	cout << cnt << " OK\n";
}

int main()
{

	freopen("input.txt", "rt", stdin);

	


	
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d", &a[i]);
	}
	


	int ans = solve();


	printf("%d\n", ans);
	
	return 0;
}
