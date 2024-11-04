







































struct id6
{
	id6(): counter(0) {}
	~id6() { std::cerr << std::endl << "DIAG: " << (counter == 0 ? "OK" : "FAIL!!!") << " Asserts count: " << counter << std::endl; }
	void Increment() { counter++; }
	uint32_t counter;
};
id6 id9;



volatile bool id13 = 0;




bool id1 = (bool)(LOCAL_TEST);



typedef std::string string8_t;
typedef long double ld_t;

typedef std::vector<size_t> vector_size_t;
typedef std::vector<uint8_t> vector_uint8_t;
typedef std::vector<int32_t> vector_int32_t;
typedef std::vector<uint32_t> vector_uint32_t;
typedef std::vector<int64_t> vector_int64_t;
typedef std::vector<uint64_t> vector_uint64_t;
typedef std::vector<string8_t> vector_string8_t;

typedef std::vector<vector_size_t> vector_2d_size_t;
typedef std::vector<vector_int32_t> vector_2d_int32_t;
typedef std::vector<vector_uint32_t> vector_2d_uint32_t;
typedef std::vector<vector_int64_t> vector_2d_int64_t;
typedef std::vector<vector_uint64_t> vector_2d_uint64_t;

typedef std::set<size_t> set_size_t;
typedef std::set<int32_t> set_int32_t;
typedef std::set<uint32_t> set_uint32_t;
typedef std::set<int64_t> set_int64_t;
typedef std::set<uint64_t> set_uint64_t;
typedef std::set<string8_t> set_string8_t;

typedef std::multiset<size_t> multiset_size_t;
typedef std::multiset<string8_t> multiset_string8_t;





template<typename T> void UpdateMin(T& a, const T b) {a = std::min(a, b);}
template<typename T> void UpdateMax(T& a, const T b) {a = std::max(a, b);}

const ld_t Pi = std::atan(1.0L) * 4.0L;
static const ld_t Eps = 1.0e-09;
template<typename T> bool IsEqual(const T a, const T b) { return std::abs(a - b) < Eps; }
template<typename T> bool IsGreater(const T a, const T b) { return a > b + Eps; }
template<typename T> bool IsLess(const T a, const T b) { return a + Eps < b; }
template<typename T> bool id11(const T a, const T b) { return !IsLess(a, b); }
template<typename T> bool id10(const T a, const T b) { return !IsGreater(a, b); }

template<typename T> string8_t ToStr(const T& val) { std::ostringstream ostr; ostr << val; return ostr.str(); }
template<typename T> bool FromStr(const string8_t& str, T& val) {std::istringstream istr(str); istr >> val; return !!istr; }

template<typename T> std::istream& operator>>(std::istream& ist, std::vector<T>& data)
{
	LOCAL_ASSERT(!!ist);
	for (size_t i = 0; i < data.size(); i++) { ist >> data[i]; }
	return ist;
}

template<typename T> T Read(std::istream& ist)
{
	LOCAL_ASSERT(!!ist);
	T val; ist >> val; return val;
}

template<typename T> std::ostream& operator<<(std::ostream& ost, const std::vector<T>& data)
{
	for (size_t i = 0; i < data.size(); i++) { if (i != 0) { ost << ' '; } ost << data[i]; }
	return ost;
}


template<size_t id> class StopWatch { };



library::random::Rand id7;


const size_t Inf = 99999;

vector_size_t ToVector(const size_t v1, const size_t v2, const size_t v3, const size_t v4)
{
	vector_size_t v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	return v;
}

vector_2d_size_t ToLinks(const vector_2d_size_t& isLinked)
{
	const size_t n = isLinked.size();

	vector_2d_size_t links(n);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (!isLinked[i][j])
				continue;
			links[i].push_back(j);
		}
	}

	return links;
}


vector_2d_size_t id5(const vector_2d_size_t& links)
{
	const size_t n = links.size();
	vector_2d_size_t isLinked(n, vector_size_t(n, 0));

	for (size_t i = 0; i < links.size(); i++)
	{
		for (size_t j = 0; j < links[i].size(); j++)
		{
			const size_t next = links[i][j];
			isLinked[i][next] = 1;
		}
	}
	return isLinked;
}

vector_2d_size_t Floyd(const vector_2d_size_t& isLinked)
{
	const size_t n = isLinked.size();

	vector_2d_size_t m(n, vector_size_t(n, Inf));

	for (size_t i = 0; i < n; i++)
	{
		m[i][i] = 0;
		for (size_t j = 0; j < n; j++)
		{
			if (isLinked[i][j])
				m[i][j] = 1;
		}
	}

	for (size_t k = 0; k < n; k++)
	{
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				m[i][j] = std::min(m[i][j], m[i][k] + m[k][j]);
			}
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			LOCAL_ASSERT(m[i][j] <= Inf);
		}
	}

	return m;
}

void id12(const vector_2d_size_t& isLinked, vector_size_t& id2, size_t& maxPath)
{
	const size_t n = isLinked.size();
	const vector_2d_size_t m = Floyd(isLinked);

	bool isFound = false;
	maxPath = 0;
	id2.clear();
	for (size_t v1 = 0; v1 < n; v1++)
	{
		for (size_t v2 = 0; v2 < n; v2++)
		{
			for (size_t v3 = 0; v3 < n; v3++)
			{
				for (size_t v4 = 0; v4 < n; v4++)
				{
					set_size_t v;
					v.insert(v1);
					v.insert(v2);
					v.insert(v3);
					v.insert(v4);
					if (v.size() < 4)
						continue;

					const size_t path = m[v1][v2] + m[v2][v3] + m[v3][v4];
					if (path >= Inf)
						continue;

					if (!isFound || (path > maxPath))
					{
						isFound = true;
						maxPath = path;
						id2 = ToVector(v1, v2, v3, v4);
					}
				}
			}
		}
	}
}


struct stat_t
{
	size_t dist;
	size_t index;

	stat_t(size_t dist, size_t index): dist(dist), index(index) {}

	bool operator<(const stat_t& rval) const
	{
		if (dist != rval.dist)
			return dist < rval.dist;
		return index < rval.index;
	}
};

typedef std::set<stat_t> stats_t;

void id0(const vector_2d_size_t& links, const size_t start, vector_size_t& ds)
{
	ds[start] = 0;

	stats_t stats;
	stats.insert(stat_t(0, start));

	while (!stats.empty())
	{
		const stat_t next = *stats.begin();
		stats.erase(stats.begin());

		const size_t d = next.dist;
		const size_t v = next.index;

		const size_t nn = links[v].size();
		for (size_t i = 0; i < nn; i++)
		{
			const size_t vnext = links[v][i];
			const size_t w = 1;
			if (d + w < ds[vnext])
			{
				stats.erase(stat_t(ds[vnext], vnext));
				stats.insert(stat_t(d + w, vnext));
				ds[vnext] = d + w;
			}
		}
	}
}

vector_2d_size_t id0(const vector_2d_size_t& links)
{
	const size_t n = links.size();

	vector_2d_size_t m(n, vector_size_t(n, Inf));

	for (size_t i = 0; i < n; i++)
	{
		id0(links, i, m[i]);
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			LOCAL_ASSERT(m[i][j] <= Inf);
		}
	}


	const vector_2d_size_t ref = Floyd(id5(links));
	LOCAL_ASSERT(ref == m);


	return m;
}

void GetAns(const vector_2d_size_t& isLinked, vector_size_t& id2, size_t& maxPath)
{
	const vector_2d_size_t links = ToLinks(isLinked);

	const size_t n = links.size();
	const vector_2d_size_t m = id0(links);

	const size_t TrimSize = 2;

	maxPath = 0;
	id2.clear();

	vector_2d_size_t maxTo(n);
	vector_2d_size_t maxFrom(n);
	for (size_t i = 0; i < n; i++)
	{
		vector_size_t& mt = maxTo[i];
		vector_size_t& mf = maxFrom[i];

		for (size_t j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (m[i][j] < Inf)
				mf.push_back(j);
			if (m[j][i] < Inf)
				mt.push_back(j);
		}

		std::sort(mt.begin(), mt.end(), [&](const size_t a, const size_t b) -> bool
		{
			return m[a][i] > m[b][i];
		});

		std::sort(mf.begin(), mf.end(), [&](const size_t a, const size_t b) -> bool
		{
			return m[i][a] > m[i][b];
		});

		if (mt.size() > TrimSize)
			mt.resize(TrimSize);
		if (mf.size() > TrimSize)
			mf.resize(TrimSize);
	}

	for (size_t v2 = 0; v2 < n; v2++)
	{
		for (size_t v3 = 0; v3 < n; v3++)
		{
			if (v3 == v2)
				continue;
			if (m[v2][v3] >= Inf)
				continue;

			const vector_size_t& mt = maxTo[v2];
			const vector_size_t& mf = maxFrom[v3];
			for (size_t tc = 0; tc < mt.size(); tc++)
			{
				const size_t v1 = mt[tc];
				if (v1 == v2 || v1 == v3)
					continue;

				for (size_t fc = 0; fc < mf.size(); fc++)
				{					
					const size_t v4 = mf[fc];
					if (v1 == v4)
						continue;
					if (v4 == v2 || v4 == v3)
						continue;

					const size_t path = m[v1][v2] + m[v2][v3] + m[v3][v4];
					LOCAL_ASSERT(path < Inf);
					if (path > maxPath)
					{
						maxPath = path;
						id2 = ToVector(v1, v2, v3, v4);
					}
				}
			}
		}
	}
}

bool Solve(std::istream& ist, std::ostream& ost, const bool id8)
{
	StopWatch<1> sw; (void)sw;

	

	size_t n, edges;
	ist >> n >> edges;

	if (id8 && !ist)
		return false;

	

	LOCAL_PRINT() << std::endl << "Next test: n = " << n << std::endl;

	vector_2d_size_t isLinked(n, vector_size_t(n));
	for (size_t i = 0; i < edges; i++)
	{
		size_t u, v;
		ist >> u >> v;
		--u; --v;

		if (u != v)
			isLinked[u][v] = 1;
	}

	vector_size_t id2;
	size_t maxPath = 0;
	GetAns(isLinked, id2, maxPath);
	


	{
		vector_size_t id4;
		size_t id3;
		id12(isLinked, id4, id3);
		if (!id4.empty())
		{
			LOCAL_PRINT() << "Found: " << "len = " << id3 << " {" << id4 << "}" << std::endl;
			LOCAL_ASSERT(id3 == maxPath);
		}
		else
		{
			LOCAL_PRINT() << "Not found: " << std::endl;
		}
	}


	LOCAL_ASSERT(id2.size() == 4);
	ost << (id2[0] + 1) << " " << (id2[1] + 1) << " " << (id2[2] + 1) << " " << (id2[3] + 1) << std::endl;

	return id8;
}



vector_2d_size_t id5(const size_t n, const uint32_t mask)
{
	vector_2d_size_t isLinked(n, vector_size_t(n));

	size_t cellId = 0;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			isLinked[i][j] = (mask & (1UL << cellId)) ? 1 : 0;			
			cellId++;
		}
	}

	return isLinked;
}

void PrintTest(const vector_2d_size_t& isLinked, std::ostream& ost)
{
	const size_t n = isLinked.size();
	size_t m = 0;
	for (size_t i = 0; i < n; i++)
	{
		m += std::accumulate(isLinked[i].begin(), isLinked[i].end(), 0U);
	}

	if (m != 6)
		return;

	ost << n << " " << m << std::endl;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (isLinked[i][j])
			{
				ost << (i + 1) << " " << (j + 1) << std::endl;
			}
		}
	}
}

void TestAll(const size_t n)
{
	const size_t edges = n * (n - 1);
	if (edges > 30)
		return;

	const uint32_t MaxMask = 1UL << edges;
	for (uint32_t mask = 1; mask < MaxMask; mask++)
	{
		const vector_2d_size_t isLinked = id5(n, mask);

		vector_size_t id4;
		size_t id3;
		id12(isLinked, id4, id3);
		if (id4.empty())
			continue;

		vector_size_t id2;
		size_t maxPath;
		GetAns(isLinked, id2, maxPath);

		

		


		if ((id2.size() != 4) || (id3 != maxPath))
		{
			std::cout << "FAIL on:" << std::endl;
			std::cout << "mask = " << mask << std::endl;
			PrintTest(isLinked, std::cout);
			std::cout << std::endl;
			

		}
	}
}

void TestRandom()
{
	using namespace library::random;
	const auto genVector = GenFactory::CreateGenVector(GenRange<size_t>(2, 10), GenRange<int32_t>(-100, +200));

	for (size_t t = 0; t < 10; t++)
	{
		const vector_int32_t data = genVector();
		

	}
}



int main(int argc, const char *argv[])
{

	TestAll(4);
	



    std::ios_base::sync_with_stdio(false);
    std::istream* ist = &std::cin;
    std::ostream* ost = &std::cout;
    
    std::unique_ptr<std::istream> fileInput;
    
    if (argc > 1)
    {
        fileInput.reset(new std::ifstream(argv[1]));
        if (!(*fileInput))
        {
            std::cout << "File not found: " << argv[1] << std::endl;
        }
        ist = fileInput.get();
    }    
    

    Solve(*ist, *ost, false);

    while(Solve(*ist, *ost, true)) {};

}
