

















const double PI = 3.1415926535897932384626433832795;

using namespace std;













































































































































bool id2(char c){return c>='A' && c<='Z';}

bool id1(char c){return c>='a' && c<='z';}

bool isLetter(char c){return (c>='A' && c<='Z') || (c>='a' && c<='z');}

bool isDigit(char c){return c>='0' && c<='9';}

char id3(char c){return (id2(c))?(c+32):c;}

char id0(char c){return (id1(c))?(c-32):c;}



















































































int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }




template <class T> void out( T a, T b ) { bool first = true; for( T i = a; i != b; ++ i ) { if( !first ) printf( " " ); first = false; cout << * i; } printf( "\n" ); }
template <class T> void outl( T a, T b ) { for( T i = a; i != b; ++ i ) { cout << * i << "\n"; } }
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;
typedef map<int,int> mii;

template <class T> inline T sqr(T xx) { return xx*xx; }
inline istream& ggg(string &s) { return std::getline(cin, s); }
int __b = 1;
void ASS(bool b) { while(1) { __b=1; if(b) break; } }

string s;
int i, j;






int main()
{

    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);




	int n, m, k;
	cin >> n >> m >> k;

	if(0)

	{
		cout << 0 << endl;
		return 0;
	}

	if(n%2 == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	int needMoves = n/2 + 1;
	if(m < needMoves)
	{
		cout << 0 << endl;
		return 0;
	}


	if(n != 1)
		m /= needMoves;

	ULL kk = k;
	kk *= m;

	int iMin = -1;

	fi(n)
	{
		int x;
		cin >> x;

		if(i%2 == 0)
		{
			if(iMin == -1 || x < iMin)
				iMin = x;
		}
	}

	int res = iMin;
	if(kk < iMin && m < iMin && k < iMin)
		res = kk;

	cout << res;



	cout << endl;
    return 0;
}
