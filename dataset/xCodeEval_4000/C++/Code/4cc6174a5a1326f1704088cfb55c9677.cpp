#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <limits.h> 

#include <math.h>
#include <set>


#include <memory.h>





const double PI = 3.1415926535897932384626433832795;

using namespace std;













































































































































bool isUpperCase(char c){return c>='A' && c<='Z';}

bool isLowerCase(char c){return c>='a' && c<='z';}

bool isLetter(char c){return (c>='A' && c<='Z') || (c>='a' && c<='z');}

bool isDigit(char c){return c>='0' && c<='9';}

char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}

char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}

















































#define fs first
#define sc second














#define SZ size()


#define foe(a,b,c) for( a = ( b ); a <= ( c ); ++ a )
#define fre(a,b) foe( a, 0, ( b ) )
#define fie(a) fre( i, ( a ) )


#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )


#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )
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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif



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
