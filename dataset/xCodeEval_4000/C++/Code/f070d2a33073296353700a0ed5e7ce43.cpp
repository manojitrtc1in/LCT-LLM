#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <limits.h> 

#include <math.h>
#include <set>
#include <sstream>


#include <memory.h>





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
int i, j, k;




class www
{
public:
	int type;	

	vector<string> children;
	LL w, h, bord, space;
	string name;

	LL wCalc, hCalc;

	www() : type(0)
	{
		w = 0;
		h = 0;
		bord =  space = 0;
		wCalc = hCalc = -1;
	}

	void add_child(string ww)
	{
		children.push_back(ww);
	}

	void get_sisez(LL &ww, LL &hh);
};

map<string, www> widgets;


void www::get_sisez(LL &ww, LL &hh)
{
	if(wCalc != -1 && hCalc != -1)
	{
		ww = wCalc;
		hh = hCalc;
		return;
	}

	wCalc = w;
	hCalc = h;
	if(children.empty())
	{
		ww = wCalc;
		hh = hCalc;
		return;
	}

	int wNonZeroCnt = 0;
	int hNonZeroCnt = 0;

	int sz = children.size();
	for(int i = 0; i < sz; i++)
	{
		LL ww2, hh2;
		widgets[children[i]].get_sisez(ww2, hh2);

		if(ww2 > 0)
			wNonZeroCnt++;
		if(hh2 > 0)
			hNonZeroCnt++;

		if(type == 2)	

		{
			hCalc += hh2;
			if(wCalc < ww2)
				wCalc = ww2;
		}
		if(type == 3)	

		{
			wCalc += ww2;
			if(hCalc < hh2)
				hCalc = hh2;
		}
	}

	

		wCalc += bord*2;
	

		hCalc += bord*2;

	hNonZeroCnt = wNonZeroCnt = children.size();

	if(type == 2 && hNonZeroCnt > 0)	

		hCalc += space * (hNonZeroCnt-1);
	if(type == 3 && wNonZeroCnt > 0)	

		wCalc += space * (wNonZeroCnt-1);

	

	ww = wCalc;
	hh = hCalc;
}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif



	int n;
	cin >> n;ggg(s);

	fi(n)
	{
		ggg(s);

		size_t jj = s.find(' ');
		if(jj != string::npos)
		{
			string s2 = s.substr(0, jj);
			www buf;
			if(s2 == "Widget")
			{
				buf.type = 1;
				size_t kk = s.find('(', jj);
				buf.name = s.substr(jj+1, kk-jj-1);
				size_t kk2 = s.find(',', kk);
				size_t kk3 = s.find(')', kk);
				buf.w = toInt(s.substr(kk+1, kk2-kk-1));
				buf.h = toInt(s.substr(kk2+1, kk3-kk2-1));
			}
			else
			if(s2 == "VBox")
			{
				buf.type = 2;
				buf.name = s.substr(jj+1, s.length());
			}
			else
			if(s2 == "HBox")
			{
				buf.type = 3;
				buf.name = s.substr(jj+1, s.length());
			}
			widgets[buf.name] = buf;
		}
		else
		{
			jj = s.find('.');
			if(jj != string::npos)
			{
				string wname = s.substr(0, jj);

				size_t kk = s.find('(', jj);
				string proc = s.substr(jj+1, kk-jj-1);
				size_t kk2 = s.find(')', kk);
				string arg = s.substr(kk+1, kk2-kk-1);
				if(proc == "pack")
				{
					widgets[wname].add_child(arg);
				}
				else
				if(proc == "set_border")
				{
					widgets[wname].bord = toInt(arg);
				}
				else
				if(proc == "set_spacing")
				{
					widgets[wname].space = toInt(arg);
				}
			}
		}
	}

	map<string, www>::iterator it;
	for(it = widgets.begin(); it != widgets.end(); it++)
	{
		LL ww2, hh2;
		it->second.get_sisez(ww2, hh2);
		cout << it->first << ' ' << ww2 << ' ' << hh2;
		

		cout << endl;
	}



	

    return 0;
}
