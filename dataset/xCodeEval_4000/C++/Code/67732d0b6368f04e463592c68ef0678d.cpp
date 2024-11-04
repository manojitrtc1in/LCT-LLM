
#define ONLINE_JUDGE 0
#define DEBUG 0
#pragma region Algorithm Templates

#include <fstream>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <ctime>


#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>





using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#if(DEBUG)
#define debug(x) std::cout<<#x<<": "<<x<<std::endl
#else
#define debug(x) 0
#endif
#define C(a) memset((a),0,sizeof(a))
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

#define uint64 unsigned long long
#define ull uint64
#define uint unsigned int
#define pint unsigned int
#define ll long long
#define int64 ll

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))
#define SWAP(a, b)  do { a ^= b; b ^= a; a ^= b; } while ( 0 )
#define MAX(a, b) ((a) < (b) ? (b) : (a))

#define PI 3.1415926535897932385
#define INF 1000111222
#define EPS 1e-7
#define MAXN 20000
#define MOD 1000000007

#define INP "input.txt"
#define OUT "output.txt"


#define DefineArray(Name, Type, x) Type* Name = Array<Type>(x)


#define DefineArray2d(Name,Type,x,y) Type** Name = Array2d<Type>(x,y)
#define Ts(Type) std::vector<Type>
#define TTs(Type) std::vector<std::vector<Type> >
#define DefineMatrix2d(Name, Type, row, col) Matrix<Type>& Name = *(new Matrix<Type>(row,col))

typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<bool, bool> bb;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;


template<typename T>inline T gcd(T a, T b) { if (b == 0)return a; else return gcd(b, a % b); }
template<typename T>inline T lcm(T a, T b) { return (a * b) / gcd(a, b); }
template<typename T>inline T* Array(int Count)
{
	T* ary = new T[Count];
	return ary;
}
template<typename T>inline T** Array2d(int rowCount, int colCount)
{
	T** ary = new T*[rowCount];
	for (int i = 0; i < rowCount; ++i)
		ary[i] = new T[colCount];
	return ary;
}
template<typename T>inline void FillArray(T* Array, T value, int length)
{
	rep(i, length)
	{
		Array[i] = value;
	}
}
template<typename T>inline void FillArray2d(T** Array, T value, int rowCount, int colCount)
{
	rep(i, rowCount)
		rep(j, colCount)
		Array[i][j] = value;

}


template<typename T>
class Matrix
{
private:
	TTs(T) cell;
	int rows;
	int cols;
public:
	Matrix(int row, int col)
	{
		rows = row;
		cols = col;
		cell.resize(rows);
		rep(i, rows)
		{
			cell[i].resize(cols);
		}
	}
	T Get(int i, int j)
	{
		return cell[i - 1][j - 1];
	}
	void Set(int i, int j, T value)
	{
		cell[i - 1][j - 1] = value;
	}
	void Fill(T value)
	{
		rep(i, rows)
		{
			rep(j, cols)
			{
				cell[i][j] = value;
			}
		}
	}
};
#pragma endregion
int theNumberOfMostInnerLoopExecuted = 0;
uint startTime;









inline void resetCountandStopwatch()
{
#if(DEBUG)
	startTime = clock();
	theNumberOfMostInnerLoopExecuted = 0;
#endif
}
inline void increaseCount()
{

#if(DEBUG)
	theNumberOfMostInnerLoopExecuted++;
#endif
}
inline void printCountandElapsedTime()
{
#if(DEBUG)
	std::cout << "�ð� : " << clock() - startTime << std::endl;
	std::cout << "Ƚ�� : " << theNumberOfMostInnerLoopExecuted << std::endl;
#endif
}



class PalindromeSolver
{
	

public:
	

	int solve(std::string s)
	{
		resetCountandStopwatch();
		uint i = s.length();
		for (;; i++)
		{
			bool flag = true;
			for (uint j = 0; j < s.length(); j++)
			{
				increaseCount();
				if ((i - j - 1) < s.size() && s[j] != s[i - j - 1])
				{
					flag = false;
					break;
				}

			}
			if (flag) break;
		}
		printCountandElapsedTime();
		return i;
	}
	

	int mysolve(std::string s)
	{
		resetCountandStopwatch();
		string rs = s;
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			rs[i] = s[len - i - 1];
		}
		int maxMatch = 1;
		for (int i = 1; i < len; i++)
		{
			for (int k = 0; k <= i; k++)
			{
				increaseCount();
				if (s[len - i - 1 + k] != rs[k])
				{
					break;
				}
				else if (k == i && i >= maxMatch - 1)
				{
					maxMatch = i + 1;
				}
			}

		}
		printCountandElapsedTime();
		return 2 * len - maxMatch;
	}
};
class FriendScoreSolver
{
public:
	void solve()
	{

	}
};


class PawnChessSolver
{
private:
	char board[8][8];
public:
	

	char solve()
	{
		string line;
		

		int maxPosB = -1;
		int minPosA = 9;
		bool can[8];
		for (int i = 0; i < 8; i++)
		{
			can[i] = true;
		}

		for (int i = 0; i < 8; i++)
		{

			std::cin >> line;
			for (int j = 0; j < 8; j++)
			{
				board[i][j] = line.c_str()[j];
				if (can[j] == true)
				{

					if (board[i][j] == 'B' && i >= maxPosB)
					{
						for (int k = i; k < 8; k++)
						{
							if (board[k][j] == 'W')
							{
								can[j] = false;

							}

						}
						if (can[j] == true)
						{
							maxPosB = i;

						}
					}
					if (board[i][j] == 'W' && i <= minPosA)
					{
						for (int k = i; k >= 0; k--)
						{
							if (board[k][j] == 'B')
							{
								can[j] = false;

							}

						}
						if (can[j] == true)
						{
							minPosA = i;

						}
					}
				}
			}
		}
		

		for (int i = 0; i < 30; i++)
		{
			minPosA--;
			if (minPosA == 0)
			{
				return 'A';
			}
			else
			{
				maxPosB++;
				if (maxPosB == 7)
					return 'B';
			}
		}
		return 'C';	

	}
};
class SquirrelSolver
{
public:
	ll solve()
	{
		ll n = 0;
		std::cin >> n;
		return (n - 2) * (n - 2);

	}
};
class ChessRoadSolver
{
public:
	int solve()
	{
		int n, m, x, y, k, l, TestCase;		


		std::cin >> TestCase;
		ull* ways = Array<ull>(100000);
		rep(num, TestCase)
		{
			std::cout << "Case #" << num + 1 << std::endl;
			std::cin >> n >> m >> k;
			DefineMatrix2d(isBlocked, bool, n, m);

			isBlocked.Fill(false);
			FillArray<ull>(ways, 0, m);

			l = 0;
			rep(i, k)
			{
				std::cin >> x; std::cin >> y;
				if (x > 0 && x <= n && y > 0 && y <= m)
				{
					isBlocked.Set(x, y, true);
					l++;
				}
			}
			ways[0] = 1;
			rep(i, n)
			{
				rep(j, m)
				{

					bool a = isBlocked.Get(i + 1, j + 1);
					if (a)
					{
						ways[j] = 0;
					}
					else if (j != 0)
					{
						ways[j] += ways[j - 1];
						if (ways[j] > MOD)
							ways[j] -= MOD;
					}
				}
			}
			std::cout << ways[m - 1] % MOD << std::endl;

			delete &isBlocked;
		}
		return 0;
	}
};
class TwoCharSolver
{
public:
	bool compareLength(string a, string b)
	{
		bool result = (a.length() < b.length());
		return result;
	}
	map<const char*, int> create_map()
	{
		map<const char*, int> m;
		m["ac"] = 0;
		m["ad"] = 0;
		return m;
	}
	int solve()
	{
		int numWords = 0;
		std::cin >> numWords;
		

		int a = 'a';
		int z = 'z';
		char ch1;
		char ch2;
		char* key;
		char chs[3];
		map<char*, int> maps;
		for (int i = a; i <= z; i++)
		{
			for (int j = i + 1; j <= z; j++)
			{
				key = (new char[3]);
				key[0] = (char)i;
				key[1] = (char)j;
				key[2] = '\0';
				
				maps.insert(std::map<char*, int>::value_type(key, 0));
			}
		}
		Ts(string) words = *(new Ts(string)(numWords));
		string line;
		rep(i, numWords)
		{
			std::cin >> line;
			words[i] = *(new string(line));
		}
		rep(i, numWords)
		{
			key = new char[3];

			debug(words[i]);
			ch1 = words[i][0];
			ch2 = ch1;
			int ch1val = 0;
			int ch2val = 0;
			for (int j = 0; j < (int)words[i].length(); j++)
			{
				if (ch1 == ch2)
				{
					if (words[i][j] != ch1)
					{

						ch2 = words[i][j];
						if (ch2 < ch1)
						{
							ch2 = ch1;
							ch1 = words[i][j];
						}
					}
					ch1val++;
				}
				else
				{
					if (words[i][j] == ch1 || words[i][j] == ch2)
					{
						ch1val++;
						std::cout << ch1 << ch2 << ' ' << words[i][j] << std::endl;
					}
					else
					{
						ch1val = 0;
						ch2val = 0;
						break;
					}
				}
			}
			key[0] = ch1;
			key[1] = ch2;
			key[2] = '\0';
			debug(key);
			debug(ch1val);
			debug(maps[key]);
			int tmp = maps[key];

			maps[key] = (tmp + ch1val + ch2val);
			ch1val = 0;
			debug(maps[key]);
		}
		for (map<char*,int>::const_iterator it = maps.begin(); it != maps.end(); ++it)
		{
			char* key2 = it->first;
			int value = it->second;
			debug(key2);
			debug(value);
		}
		debug(maps["ab"]);
		debug(maps["cd"]);
		auto pr = std::max_element(maps.begin(), maps.end(),
			[](const pair<char*, int>& p1, const pair<char*, int>& p2) {
			return p1.second < p2.second; });
		debug(pr->first[0]);
		debug(pr->first[1]);
		return maps[pr->first];
	}

};
class AntonLinesSolver
{
public:
	string solve()
	{
		int numLines = 0;
		int x1 = 0;
		int x2 = 0;
		std::cin >> numLines;
		DefineArray(coeffs, int, numLines);
		DefineArray(offs, int, numLines);
		TTs(int) ys = *(new TTs(int)[numLines]);
		int rows = 2;
		int cols = numLines;
		ys.resize(rows);
		rep(i, rows)
		{
			ys[i].resize(cols);
		}
		std::cin >> x1 >> x2;
		rep(i, numLines)
		{
			std::cin >> coeffs[i] >> offs[i];
		}
		int y1 = 0;
		int y2 = 0;
		rep(i, numLines)
		{
			

			

			

			

			


			

			y1 = coeffs[i] * x1 + offs[i];
			y2 = coeffs[i] * x2 + offs[i];
			if (y1 > y2)
			{
				ys[0][i] = y1;
				ys[1][i] = y2;
			}
			else
			{
				ys[0][i] = y2;
				ys[1][i] = y1;
			}

		}

		

		std::sort(ys.begin(), ys.end(), [](const std::vector< int >& a, const std::vector< int >& b) { return a[0] > b[0]; });
		


		rep(i, numLines)
		{
			for (int j = i + 1; j < numLines; j++)
			{
				if (ys[0][j] >= ys[1][i])
				{
					float res = (float)(offs[j] - offs[i]) / (float)(coeffs[i] - coeffs[j]);
					if (res > x1 && res < x2)
						return "yes";
				}
				else break;
			}

		}
		return "no";

	}
};
class TestClass 
{
public:
	int solve()
	{

		map<string, int> maps;
		string* key = new string("ab");
		maps[*key] = 20;
		key = new string("ab");
		maps[*key] = 10;
		std::cout << maps["ab"] << std::endl;
		return 0;
	}
		
};


class VitalyandNight
{
public:
	int solve()
	{
		int i = 0;
		int n = 0;
		int m = 0;
		int result = 0;
		int leftw = 0;
		int rightw = 0;
		std::cin >> n;
		std::cin >> m;
		while (i < n * m)
		{
			std::cin >> leftw;
			std::cin >> rightw;
			if (leftw + rightw != 0)
			{
				result++;
			}
			i++;
		}
		return result;
	}
};

int main()
{

#if (ONLINE_JUDGE==1)
	

	std::string inputPath = INP;
	std::string outputPath = OUT;
	std::ifstream in(inputPath.c_str());
	std::ofstream out(outputPath.c_str());

	std::streambuf *cinbuf = std::cin.rdbuf(); 

	std::cin.rdbuf(in.rdbuf()); 


	std::streambuf *coutbuf = std::cout.rdbuf(); 

	std::cout.rdbuf(out.rdbuf()); 

#endif
	setbuf(stdout, NULL);
	

	VitalyandNight& solver = *(new VitalyandNight());
	int result = solver.solve();
	std::cout << result << std::endl;

	

	std::cout.setf(std::ios::fixed);

#if(DEBUG == 1)
	debug(theNumberOfMostInnerLoopExecuted);
	std::cin >> theNumberOfMostInnerLoopExecuted;
#endif
	return 0;
}
