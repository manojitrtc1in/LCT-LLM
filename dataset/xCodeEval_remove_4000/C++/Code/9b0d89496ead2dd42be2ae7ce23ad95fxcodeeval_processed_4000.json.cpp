


























































const double PI = 3.1415926535897932384626433832795;

using namespace std;













































































































































bool id3(char c){return c>='A' && c<='Z';}

bool id2(char c){return c>='a' && c<='z';}

bool isLetter(char c){return (c>='A' && c<='Z') || (c>='a' && c<='z');}

bool isDigit(char c){return c>='0' && c<='9';}

char id4(char c){return (id3(c))?(c+32):c;}

char id1(char c){return (id2(c))?(c-32):c;}



int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}















































































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
void id0(bool b) { while(1) { __b=1; if(b) break; } }

string s;




int AA[26][100005];



int main()
{

    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);




	char s1[10005];
	char s2[1000005];

	scanf("%s", s1);
	scanf("%s", s2);

	int nn[256];
	_(nn, 0);

	_(AA, 0);

	int ii = 0;
	while(s1[ii])
	{
		int ind = (int)(s1[ii]-'a');
		nn[ind]++;
		AA[ind][nn[ind]-1] = ii;
		ii++;
	}

	int res = 1;
	int jj = 0;

	int ccc[256];
	_(ccc, 0);
	int curInd = 0;
	while(s2[jj])
	{
		int cInd = (int)(s2[jj]-'a');
		if(nn[cInd] == 0)
		{
			cout << -1 << endl;
			return 0;
		}

		while(ccc[cInd] < nn[cInd] && AA[cInd][ccc[cInd]] < curInd)
			ccc[cInd]++;
		if(ccc[cInd] >= nn[cInd])
		{
			_(ccc, 0);
			curInd = 0;
			res++;
		}

		curInd = AA[cInd][ccc[cInd]] + 1;

		jj++;
	}


	cout << res;


	cout << endl;
    return 0;
}
