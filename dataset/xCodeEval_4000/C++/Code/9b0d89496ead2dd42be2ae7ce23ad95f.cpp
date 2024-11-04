#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>


#include <map>
#include <set>
#include <string>
#include <limits.h>
#include <math.h>
#include <sstream>


#include <memory.h>
#include <functional>











































const double PI = 3.1415926535897932384626433832795;

using namespace std;













































































































































bool isUpperCase(char c){return c>='A' && c<='Z';}

bool isLowerCase(char c){return c>='a' && c<='z';}

bool isLetter(char c){return (c>='A' && c<='Z') || (c>='a' && c<='z');}

bool isDigit(char c){return c>='0' && c<='9';}

char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}

char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}



int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}













































#define fs first
#define sc second














#define SZ size()


#define foe(a,b,c) for(int a = ( b ); a <= ( c ); ++ a )
#define fre(a,b) foe( a, 0, ( b ) )
#define fie(a) fre( i, ( a ) )


#define fo(a,b,c) for(int a = ( b ); a < ( c ); ++ a )
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
void GGGGG(bool b) { while(1) { __b=1; if(b) break; } }

string s;




int AA[26][100005];



int main()
{
#ifdef GGG_GGG_GGG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif



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
