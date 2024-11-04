


























































const double PI = 3.1415926535897932384626433832795;

using namespace std;













































































































































bool id5(char c){return c>='A' && c<='Z';}

bool id3(char c){return c>='a' && c<='z';}

bool isLetter(char c){return (c>='A' && c<='Z') || (c>='a' && c<='z');}

bool isDigit(char c){return c>='0' && c<='9';}

char id8(char c){return (id5(c))?(c+32):c;}

char id1(char c){return (id3(c))?(c-32):c;}



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




struct ppp
{
	int voz;
	int poz;
	int res;
};

bool id2 (const ppp &a1, const ppp &a2) { return (a1.voz < a2.voz || a1.voz == a2.voz && a1.poz < a2.poz); }
bool id7 (const ppp &a1, const ppp &a2) { return (a1.poz < a2.poz); }



int main()
{

    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);




	int n;
	cin >> n;

	vector<ppp> a(n);

	fi(n)
	{
		cin >> a[i].voz;
		a[i].poz = i+1;
		a[i].res = -1;
	}

	sort(a.begin(), a.end(), id2);

	int curmax = a[0].poz;
	int curvoz = a[0].voz;
	int id6 = a[0].poz;
	int id4 = a[0].voz;
	for(int i = 1; i < n; i++)
	{
		if(a[i].voz > curvoz)	

		{
			if(a[i].poz < curmax)
				a[i].res = curmax - a[i].poz - 1;
			else
			{
				if(curvoz != a[i].voz)
				{
					id6 = curmax;
					id4 = curvoz;
				}

				curmax = a[i].poz;
				curvoz = a[i].voz;
			}
		}
		else	

		{
			if(a[i].voz == id4)	

			{
				if(a[i].poz > id6)
					id6 = a[i].poz;
				if(a[i].poz > curmax)
					curmax = a[i].poz;
			}
			else
			

			{
				if(a[i].poz < id6)
					a[i].res = id6 - a[i].poz - 1;
			}

			if(a[i].poz > curmax)
				curmax = a[i].poz;
		}
	}

	sort(a.begin(), a.end(), id7);

	fi(n)
	{
		if(i != 0)
			cout << ' ';
		cout << a[i].res;
	}



	cout << endl;
    return 0;
}
