


#if defined(ONLINE_JUDGE)
#define _SECURE_SCL 0
#endif

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <functional>
#include <memory>
#include <cmath>
#include <climits>
#include <numeric>
#include <tuple>
#include <memory.h>
#include <stdint.h>

#if !defined(__GNUC__)
#else 

#define _CrtDbgBreak() __builtin_trap()
#endif 


#if defined(ONLINE_JUDGE)
#define LOCAL_TEST 0
#else 
#define LOCAL_TEST 1
#endif

#if LOCAL_TEST
struct AssertsCounter
{
	AssertsCounter(): counter(0) {}
	~AssertsCounter() { std::cerr << std::endl << "DIAG: " << (counter == 0 ? "OK" : "FAIL!!!") << " Asserts count: " << counter << std::endl; }
	void Increment() { counter++; }
	uint32_t counter;
};
AssertsCounter g_assertsCounter;
#define LOCAL_ASSERT(expr) { if (!(expr)) {std::cerr << "ASSERT FAILED (" << __LINE__ << "): '" << #expr << "'" << std::endl; g_assertsCounter.Increment(); _CrtDbgBreak(); } }
#define LOCAL_ASSERT_EQ(expr1, expr2) { if ((expr1) != (expr2)) {std::cerr << "ASSERT FAILED (" << __LINE__ << "): '" << #expr1 << "' == '" << #expr2 << "' (" << (expr1) << " vs " << (expr2) << "')" << std::endl; g_assertsCounter.Increment(); _CrtDbgBreak(); } }
#else
volatile bool isLocalTestEnabled = 0;
#define LOCAL_ASSERT(expr)
#define LOCAL_ASSERT_EQ(expr1, expr2)
#endif

bool g_isLocalPrintEnabled = (bool)(LOCAL_TEST);
#define LOCAL_PRINT() if (!g_isLocalPrintEnabled) { } else std::cerr << "# " 


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
template<typename T> bool IsGreaterEqual(const T a, const T b) { return !IsLess(a, b); }
template<typename T> bool IsLessEqual(const T a, const T b) { return !IsGreater(a, b); }

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

#if defined(ONLINE_JUDGE)
template<size_t id> class StopWatch { };
#else
#include <library/lib_stopwatch.h>
#include <library/lib_random.h>
library::random::Rand g_rnd;
#endif

const size_t RequestsLimit = 200;

struct Rect
{
	Rect(): x1(0), y1(0), x2(0), y2(0) { }
	Rect(int32_t x1, int32_t y1, int32_t x2, int32_t y2): x1(x1), y1(y1), x2(x2), y2(y2) { }

	int32_t x1;
	int32_t y1;
	int32_t x2;
	int32_t y2;
};

struct ISolutionChecker
{
	virtual size_t OnCountRequest(int32_t x1, int32_t y1, int32_t x2, int32_t y2) = 0;
	virtual void OnFinalDecision(int32_t ax1, int32_t ay1, int32_t ax2, int32_t ay2, int32_t bx1, int32_t by1, int32_t bx2, int32_t by2) = 0;
};

struct SolutionCheckerWithRequestCounter : ISolutionChecker
{
	SolutionCheckerWithRequestCounter(ISolutionChecker& checker): checker(checker), requestsCount(0) { }

	virtual size_t OnCountRequest(int32_t x1, int32_t y1, int32_t x2, int32_t y2)
	{
		requestsCount += 1;
		LOCAL_ASSERT(requestsCount <= RequestsLimit);
		return checker.OnCountRequest(x1, y1, x2, y2);
	}

	virtual void OnFinalDecision(int32_t ax1, int32_t ay1, int32_t ax2, int32_t ay2, int32_t bx1, int32_t by1, int32_t bx2, int32_t by2)
	{
		checker.OnFinalDecision(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
	}

	ISolutionChecker& checker;
	size_t requestsCount;
};

struct StdioSolutionChecker : ISolutionChecker
{
	StdioSolutionChecker(const int32_t n): n(n) { }

	virtual size_t OnCountRequest(int32_t x1, int32_t y1, int32_t x2, int32_t y2)
	{
		LOCAL_ASSERT(IsCoordValid(x1));
		LOCAL_ASSERT(IsCoordValid(y1));
		LOCAL_ASSERT(IsCoordValid(x2));
		LOCAL_ASSERT(IsCoordValid(y2));

		std::cout << "? " 
			<< x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;

		size_t rectCount;
		std::cin >> rectCount;
		return rectCount;
	}

	virtual void OnFinalDecision(int32_t ax1, int32_t ay1, int32_t ax2, int32_t ay2, int32_t bx1, int32_t by1, int32_t bx2, int32_t by2)
	{
		std::cout << "! " 
			<< ax1 << " " << ay1 << " " << ax2 << " " << ay2 << " "
			<< bx1 << " " << by1 << " " << bx2 << " " << by2 << std::endl;
	}

	bool IsCoordValid(const int32_t x) const
	{
		if (x < 1)
			return false;
		if (x > n)
			return false;
		return true;
	}

	const int32_t n;
};

#if LOCAL_TEST
struct LogicalSolutionChecker : ISolutionChecker
{
	LogicalSolutionChecker(int32_t n, int32_t ax1, int32_t ay1, int32_t ax2, int32_t ay2, int32_t bx1, int32_t by1, int32_t bx2, int32_t by2)
		: n(n), ra(ax1, ay1, ax2, ay2), rb(bx1, by1, bx2, by2), isAnswerSet(false), isAnswerCorrect(false)
	{
	}

	virtual size_t OnCountRequest(int32_t x1, int32_t y1, int32_t x2, int32_t y2)
	{
		LOCAL_ASSERT(IsCoordValid(x1));
		LOCAL_ASSERT(IsCoordValid(y1));
		LOCAL_ASSERT(IsCoordValid(x2));
		LOCAL_ASSERT(IsCoordValid(y2));
		LOCAL_ASSERT(x1 <= x2);
		LOCAL_ASSERT(y1 <= y2);

		size_t ans = 0;
		if (IsRectInside(x1, y1, x2, y2, ra))
			ans++;
		if (IsRectInside(x1, y1, x2, y2, rb))
			ans++;

		LOCAL_PRINT() << "-> " << ans << std::endl;
		return ans;
	}

	virtual void OnFinalDecision(int32_t ax1, int32_t ay1, int32_t ax2, int32_t ay2, int32_t bx1, int32_t by1, int32_t bx2, int32_t by2)
	{
		LOCAL_ASSERT(!isAnswerSet);
		LOCAL_ASSERT(!isAnswerCorrect);
		isAnswerSet = true;

		if (ra.x1 != ax1)
			return;
		if (ra.y1 != ay1)
			return;
		if (ra.x2 != ax2)
			return;
		if (ra.y2 != ay2)
			return;

		if (rb.x1 != bx1)
			return;
		if (rb.y1 != by1)
			return;
		if (rb.x2 != bx2)
			return;
		if (rb.y2 != by2)
			return;

		isAnswerCorrect = true;
	}

	bool IsRectInside(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const Rect& r)
	{
		

		if (x1 > r.x1)
			return false;
		if (y1 > r.y1)
			return false;
		if (x2 < r.x2)
			return false;
		if (y2 < r.y2)
			return false;
		return true;
	}

	bool IsCoordValid(const int32_t x) const
	{
		if (x < 1)
			return false;
		if (x > n)
			return false;
		return true;
	}

	const int32_t n;
	const Rect ra;
	const Rect rb;
	bool isAnswerSet;
	bool isAnswerCorrect;
};
#endif 


template<typename ArgType, typename ResultType, typename Func>
ArgType LowerBound(const ArgType& firstX, const ArgType& lastX, const ResultType& y, const Func& func)
{
	ArgType l = firstX;
	ArgType r = lastX;

	while (l < r)
	{
		const ArgType m = l + (r - l) / 2;
		if (func(m) < y)
		{
			l = m + 1;
		}
		else
		{
			r = m;
		}
	}

	return l;
}

Rect FindFirstRect(const int32_t x1, const int32_t y1, const int32_t x2, const int32_t y2, ISolutionChecker& checker)
{
	const size_t haveAtLeastOne = checker.OnCountRequest(x1, y1, x2, y2);
	LOCAL_ASSERT(haveAtLeastOne > 0);

	Rect r;

	r.x2 = LowerBound(x1, x2 + 1, 1U, [&](const int32_t x) -> size_t
	{
		const size_t count = checker.OnCountRequest(x1, y1, x, y2);
		return count;
	});

	r.y2 = LowerBound(y1, y2 + 1, 1U, [&](const int32_t y) -> size_t
	{
		const size_t count = checker.OnCountRequest(x1, y1, r.x2, y);
		return count;
	});

	LOCAL_ASSERT(r.x2 - x1 >= 0);
	const int32_t dx1 = LowerBound(0, r.x2 - x1 + 1, 1U, [&](const int32_t dx) -> size_t
	{
		const size_t count = checker.OnCountRequest(r.x2 - dx, y1, r.x2, r.y2);
		return count;
	});
	r.x1 = r.x2 - dx1;
	LOCAL_ASSERT(r.x1 > 0);
	LOCAL_ASSERT(r.x1 >= x1);

	LOCAL_ASSERT(r.y2 - y1 >= 0);
	const int32_t dy1 = LowerBound(0, r.y2 - y1 + 1, 1U, [&](const int32_t dy) -> size_t
	{
		const size_t count = checker.OnCountRequest(r.x1, r.y2 - dy, r.x2, r.y2);
		return count;
	});
	r.y1 = r.y2 - dy1;
	LOCAL_ASSERT(r.y1 > 0);
	LOCAL_ASSERT(r.y1 >= y1);

	return r;
}

Rect FindSecondRect(const int32_t n, const Rect& firstRect, ISolutionChecker& checker)
{
	if (firstRect.x1 > 1)
	{
		const int32_t x1 = 1;
		const int32_t y1 = 1;
		const int32_t x2 = firstRect.x1 - 1;
		const int32_t y2 = n;
		const size_t count = checker.OnCountRequest(x1, y1, x2, y2);
		LOCAL_ASSERT(count <= 1);
		if (count > 0)
		{
			Rect r = FindFirstRect(x1, y1, x2, y2, checker);
			return r;
		}
	}

	if (firstRect.x2 < n)
	{
		const int32_t x1 = firstRect.x2 + 1;
		const int32_t y1 = 1;
		const int32_t x2 = n;
		const int32_t y2 = n;
		const size_t count = checker.OnCountRequest(x1, y1, x2, y2);
		LOCAL_ASSERT(count <= 1);
		if (count > 0)
		{
			Rect r = FindFirstRect(x1, y1, x2, y2, checker);
			return r;
		}
	}

	if (firstRect.y1 > 1)
	{
		const int32_t x1 = 1;
		const int32_t y1 = 1;
		const int32_t x2 = n;
		const int32_t y2 = firstRect.y1 - 1;
		const size_t count = checker.OnCountRequest(x1, y1, x2, y2);
		LOCAL_ASSERT(count <= 1);
		if (count > 0)
		{
			Rect r = FindFirstRect(x1, y1, x2, y2, checker);
			return r;
		}
	}

	if (firstRect.y2 < n)
	{
		const int32_t x1 = 1;
		const int32_t y1 = firstRect.y2 + 1;
		const int32_t x2 = n;
		const int32_t y2 = n;
		const size_t count = checker.OnCountRequest(x1, y1, x2, y2);
		LOCAL_ASSERT(count <= 1);
		if (count > 0)
		{
			Rect r = FindFirstRect(x1, y1, x2, y2, checker);
			return r;
		}
	}

	LOCAL_ASSERT(n == 0);
	return Rect();
}

void RunTest(const int32_t n, ISolutionChecker& checker)
{
	SolutionCheckerWithRequestCounter checkerWithCounter(checker);

	Rect ra = FindFirstRect(1, 1, n, n, checkerWithCounter);
	Rect rb = FindSecondRect(n, ra, checkerWithCounter);

	checkerWithCounter.OnFinalDecision(ra.x1, ra.y1, ra.x2, ra.y2, rb.x1, rb.y1, rb.x2, rb.y2);
	LOCAL_PRINT() << "Requests count: " << checkerWithCounter.requestsCount << std::endl;
}

bool Solve(std::istream& , std::ostream& , const bool multipleTestMode)
{
	StopWatch<1> sw; (void)sw;

	

	int32_t n;
	std::cin >> n;

	if (multipleTestMode && !std::cin)
		return false;

	

	LOCAL_PRINT() << std::endl << "Next test" << std::endl;

	StdioSolutionChecker checker(n);
	RunTest(n, checker);

	return multipleTestMode;
}

#if LOCAL_TEST
void Test()
{
	{
		LogicalSolutionChecker checker(5, 2, 2, 2, 2, 3, 4, 3, 5);
		RunTest(5, checker);

		LOCAL_ASSERT(checker.isAnswerSet);
		LOCAL_ASSERT(checker.isAnswerCorrect);
	}

	{
		LogicalSolutionChecker checker(10, 2, 3, 4, 5, 6, 7, 8, 9);
		RunTest(10, checker);

		LOCAL_ASSERT(checker.isAnswerSet);
		LOCAL_ASSERT(checker.isAnswerCorrect);
	}

	{
		LogicalSolutionChecker checker(10, 1, 2, 3, 4, 5, 6, 7, 8);
		RunTest(10, checker);

		LOCAL_ASSERT(checker.isAnswerSet);
		LOCAL_ASSERT(checker.isAnswerCorrect);
	}

	{
		LogicalSolutionChecker checker(100, 11, 21, 31, 41, 51, 61, 71, 81);
		RunTest(100, checker);

		LOCAL_ASSERT(checker.isAnswerSet);
		LOCAL_ASSERT(checker.isAnswerCorrect);
	}

	{
		LogicalSolutionChecker checker(65536, 11, 21, 31, 41, 51, 61, 71, 81);
		RunTest(100, checker);

		LOCAL_ASSERT(checker.isAnswerSet);
		LOCAL_ASSERT(checker.isAnswerCorrect);
	}
}
#endif

int main(int argc, const char *argv[])
{
#if LOCAL_TEST
	Test();
#endif

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
    
#if defined(ONLINE_JUDGE)
    Solve(*ist, *ost, false);
#else
    while(Solve(*ist, *ost, true)) {};
#endif
}
