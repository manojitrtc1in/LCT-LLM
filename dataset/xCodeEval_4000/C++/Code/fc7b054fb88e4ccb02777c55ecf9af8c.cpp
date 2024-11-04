



#pragma comment(linker, "/STACK:36777216")

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <functional>
#include <vector>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <math.h>
#include <bitset>
#include <list>
#include <iomanip>      

#include <random>

typedef std::mt19937 rng_type;
std::uniform_int_distribution<rng_type::result_type> udist(0, 1);

rng_type rng;

using namespace std;

FILE * in, *out;

#define fo(a,b,c) for(int a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )

#define LL long long

int ri() { int a; fscanf(in, "%d", &a); return a; }
double rf() { double a; fscanf(in, "%lf", &a); return a; }
char sbuf[100005];
string rstr()
{
	

	char c;
	char * b = sbuf;
	while (c = fgetc(in))
	{
		if (c == '\n' || c == 255) break;
		*b++ = c;
	}
	*b = 0;
	return sbuf;
}


long long nod(long long a, long long b)
{
	if (a == 1 || b == 1) return 1;
	if (a == 0) return b;
	if (b == 0) return a;

	return nod(b%a, a);
}

vector<int> primes;
void calculatePrimes()
{
	primes.push_back(2);
	for (int i = 3; i < 500000; i += 2)
	{
		bool bFound = false;
		int m = (int)sqrt((float)i);
		for (int j = 1; j < primes.size() && !bFound && primes[j] <= m; j++)
			bFound = ((i%primes[j]) == 0);
		if (!bFound)
			primes.push_back(i);
	}
}








void egcd(int a, int b, int &g, int &x, int &y)
{
	if (a == 0)
	{
		g = b;
		x = 0;
		y = 1;
		return;
	}
	egcd(b%a, a, g, y, x);
	x = x - (b / a)*y;
}

int modinv(int a, int m)
{
	int g = 0, x = 0, y = 0;
	egcd(a,m,g,x,y);
	return (x+m)%m;
}



bool willBeInTime(vector<int> & f, long long v, long long t)
{
	long long mintime = 0;
	fi(f.size())
	{
		if(mintime > t) return false;
		if(f[i] > v)	return false;
		if(2*f[i] <= v) { mintime += f[i]; continue; };

		long long s =  v-f[i];
		if(s > f[i]) s = f[i];
		mintime += 2*(f[i]-s)+s;
	}

	return mintime <= t;
}

bool iterate(map<int, map<int, vector<int>>> & m, map<int, map<int, vector<int>>>::iterator st, int ind)
{
	ind++;
	while(ind <= st->second.rbegin()->first && st->second[ind].size() > 0) ind++;
	if(ind > st->second.rbegin()->first)
	{
		st++;
		if(st == m.end())
			return true;
		ind = 0;
		

		int numatzero = st->first - (st->second[0].size()%st->first);
		if(st->second[0].size() != 0 && (st->second[0].size()%st->first) == 0) numatzero = 0;
		if(m[-1][ind].size() + st->second[-1].size() + m[-1][-1].size() < numatzero) return false;

		int n11 = 0;
		if(m[-1][ind].size() + st->second[-1].size() < numatzero)
		{
			n11 = numatzero - m[-1][0].size() - st->second[-1].size();
			st->second[0].insert(st->second[0].end(), m[-1][-1].end()-n11, m[-1][-1].end());
			m[-1][-1].resize(m[-1][-1].size()-n11);
			numatzero -= n11;
		}

		for(int i = 0; i<= numatzero; i++)
		{
			if(i > m[-1][ind].size() || numatzero-i > st->second[-1].size()) continue;
			st->second[0].insert(st->second[0].end(), m[-1][ind].end()-i, m[-1][ind].end());
			m[-1][ind].resize(m[-1][ind].size()-i);

			st->second[0].insert(st->second[0].end(), st->second[-1].end()-numatzero+i, st->second[-1].end());
			st->second[-1].resize(st->second[-1].size()-numatzero+i);
			if(iterate(m, st, ind)) return true;
			
			st->second[-1].insert(st->second[-1].end(), st->second[0].end()-numatzero+i, st->second[0].end());
			st->second[0].resize(st->second[0].size()-numatzero+i);

			m[-1][ind].insert(m[-1][ind].end(), st->second[0].end()-i, st->second[0].end());
			st->second[0].resize(st->second[0].size()-i);
		}

		if(n11 > 0)
		{
			m[-1][-1].insert(m[-1][-1].end(), st->second[0].end()-n11, st->second[0].end());
			st->second[0].resize(st->second[0].size()-n11);
		}

		return false;
	}
	
	
	if(st->second[-1].size() > 0)
	{
		st->second[ind].push_back(st->second[-1].back());
		st->second[-1].pop_back();
		if(iterate(m, st, ind)) return true;
		st->second[-1].push_back(st->second[ind].back());
		st->second[ind].pop_back();
	}


	if(m[-1][ind].size() > 0)
	{
		st->second[ind].push_back(m[-1][ind].back());
		m[-1][ind].pop_back();

		if(iterate(m, st, ind)) return true;

		m[-1][ind].push_back(st->second[ind].back());
		st->second[ind].pop_back();
	}

	if(m[-1][ind].size() == 0 && st->second[-1].size() == 0 && m[-1][-1].size() > 0)
	{
		st->second[ind].push_back(m[-1][-1].back());
		m[-1][-1].pop_back();
		if(iterate(m, st, ind)) return true;
		m[-1][-1].push_back(st->second[ind].back());
		st->second[ind].pop_back();
	}

	return false;
}



bool canBeSolved(map<int, map<int, vector<int>>> m, int lmo, int n)
{


	for(auto & st : m)
	{
		if(st.first == -1) continue;

		int numatzero = st.first-(st.second[0].size()%st.first);
		if(st.second[0].size()%st.first == 0 && st.second[0].size() != 0) numatzero = 0;

		while(m[-1][0].size() < numatzero && st.second[-1].size() > 0)
		{
			st.second[0].push_back(st.second[-1].back());
			st.second[-1].pop_back();
			numatzero--;
		}

		while(m[-1][0].size() > 0 && st.second[-1].size() < numatzero)
		{
			st.second[0].push_back(m[-1][0].back());
			m[-1][0].pop_back();
			numatzero--;
		}

		while(m[-1][-1].size() > 0 && m[-1][0].size() < numatzero && st.second[-1].size() < numatzero)
		{
			st.second[0].push_back(m[-1][-1].back());
			m[-1][-1].pop_back();
			numatzero--;
		}

		if(m[-1][0].size() < numatzero && st.second[-1].size() < numatzero)
			return false;

		for(int i = 1; i<st.second.rbegin()->first; i++)
		{
			if(st.second[i].size() > 0) continue;
			if(m[-1][i].size() > 0 && st.second[-1].size() > 0) 
			{
				numatzero++;
				continue;
			}

			if(m[-1][i].size() > 0)
			{
				st.second[i].push_back(m[-1][i].back());
				m[-1][i].pop_back();
				continue;
			}

			if(st.second[-1].size() > 0)
			{
				st.second[i].push_back(st.second[-1].back());
				st.second[-1].pop_back();
				continue;
			}

			if(m[-1][-1].size() > 0)
			{
				st.second[i].push_back(m[-1][-1].back());
				m[-1][-1].pop_back();
				continue;
			}

			return false;
		}

		if(numatzero <= st.second[-1].size())
		{
			for(int i = 1; i<st.second.rbegin()->first; i++)
			{
				if(st.second[i].size() > 0) continue;
				if(m[-1][i].size() > 0 && st.second[-1].size() > 0)
				{
					st.second[i].push_back(st.second[-1].back());
					st.second[-1].pop_back();
					numatzero--;
				}
			}
			while(numatzero)
			{
				st.second[0].push_back(st.second[-1].back());
				st.second[-1].pop_back();
				numatzero--;
			}
		}
	}

	for(int i = 1; i<=m[lmo].rbegin()->first; i++)
	{
		int count = 0;
		for(auto & st : m)
		{
			if(st.first == -1) continue;
			if(st.second.rbegin()->first < i) continue;
			if(st.second[i].size() > 0) continue;

			if(m[-1][i].size() > 0 && st.second[-1].size() > 0)
				count++;
		}

		if(count <= m[-1][i].size())
		{
			for(auto & st : m)
			{
				if(st.first == -1) continue;
				if(st.second.rbegin()->first < i) continue;
				if(st.second[i].size() > 0) continue;

				if(m[-1][i].size() > 0 && st.second[-1].size() > 0)
				{
					st.second[i].push_back(m[-1][i].back());
					m[-1][i].pop_back();
				}
			}
		}

	}

	{
		int count = 0;
		for(auto & st : m)
		{
			if(st.first == -1) continue;

			int numatzero = st.first-(st.second[0].size()%st.first);
			if(st.second[0].size()%st.first == 0 && st.second[0].size() != 0) numatzero = 0;
			count += numatzero;
		}

		if(count <= m[-1][0].size())
		{
			for(auto & st : m)
			{
				if(st.first == -1) continue;

				int numatzero = st.first-(st.second[0].size()%st.first);
				if(st.second[0].size()%st.first == 0 && st.second[0].size() != 0) numatzero = 0;

				while(numatzero)
				{
					st.second[0].push_back(m[-1][0].back());
					m[-1][0].pop_back();
					numatzero--;
				}
			}

		}

	}



	if(!iterate(m, m.begin(), 3000)) return false;
	vector<int> par(n);

	while(m[-1][-1].size())
	{
		m[1][0].push_back(m[-1][-1].back());
		m[-1][-1].pop_back();
	}

	while(m[-1][0].size())
	{
		m[1][0].push_back(m[-1][0].back());
		m[-1][0].pop_back();
	}


	for(auto & i : m[-1])
	{
		while(i.second.size())
		{
			m[lmo][i.first].push_back(i.second.back());
			i.second.pop_back();
		}
	}

	m.erase(m.find(-1));

	for(auto & st : m)
	{
		while(st.second[-1].size())
		{
			st.second[1].push_back(st.second[-1].back());
			st.second[-1].pop_back();
		}
		for(int i = 0; i<st.second[0].size(); i++)
		{
			if(i%st.first == 0)
				par[st.second[0][i]] = st.second[0][i+st.first-1];
			else
				par[st.second[0][i]] = st.second[0][i-1];
		}
		for(auto & j : st.second)
		{
			if(j.first < 1) continue;
			for(int i = 0; i<j.second.size(); i++)
				par[j.second[i]] = st.second[j.first-1][0];
		}
	}
	for(auto i : par)
		cout << i + 1 << " ";

	return true;
}


int main()
{

	rng.seed(time(NULL));
	srand(time(NULL));
	
	long long n;
	cin >> n;
	vector<pair<int,int>> cl(n);
	vector<int>			  ch(n);
	
	map<int, map<int,vector<int>>> m;


	pair<int,int> maxp(-1,-1);
	fi(n)
	{
		int c,p;
		string s;
		cin >> s;
		if(s[0] == '?') p = -1; else p = atoi(s.c_str());
		
		cin >> s;
		if(s[0] == '?') c = -1; else c = atoi(s.c_str());

		cl[i] = mp(p,c);
		ch[i] = -1;
		m[c][p].push_back(i);

		if(maxp < cl[i]) maxp = cl[i];
	}


	if(m.size() == 1 && m.begin()->first == -1)
	{
		m[1] = m[-1];
		m.erase(m.begin());
		maxp.second = 1;
	}

	for(auto & st : m)
	{
		if(st.first == -1) continue;

		int numatzero = st.first-(st.second[0].size()%st.first);
		if(st.second[0].size()%st.first == 0 && st.second[0].size() != 0) numatzero = 0;
		
		while(m[-1][0].size() < numatzero && st.second[-1].size() > 0)
		{
			st.second[0].push_back(st.second[-1].back());
			st.second[-1].pop_back();
			numatzero--;
		}
			
		while(m[-1][0].size() > 0 && st.second[-1].size() < numatzero)
		{
			st.second[0].push_back(m[-1][0].back());
			m[-1][0].pop_back();
			numatzero--;
		}
		
		while(m[-1][-1].size() > 0 && m[-1][0].size() < numatzero && st.second[-1].size() < numatzero)
		{
			st.second[0].push_back(m[-1][-1].back());
			m[-1][-1].pop_back();
			numatzero--;
		}

		if(m[-1][0].size() < numatzero && st.second[-1].size() < numatzero)
		{
			cout << -1;
			return 0;
		}

		for(int i = 1; i<st.second.rbegin()->first; i++)
		{
			if(st.second[i].size() > 0) continue;
			if(m[-1][i].size() > 0 && st.second[-1].size() > 0) continue;

			if(m[-1][i].size() > 0)
			{
				st.second[i].push_back(m[-1][i].back());
				m[-1][i].pop_back();
				continue;
			}
			
			if(st.second[-1].size() > 0)
			{
				st.second[i].push_back(st.second[-1].back());
				st.second[-1].pop_back();
				continue;
			}
			
			if(m[-1][-1].size() > 0)
			{
				st.second[i].push_back(m[-1][-1].back());
				m[-1][-1].pop_back();
				continue;
			}

			cout << -1;
			return 0;
		}
	}


	if(maxp.second == -1)
	{
		int maxe = m[-1][maxp.first].back();
		m[-1][maxp.first].pop_back();
		for(auto & st : m)
		{
			if(st.first == -1) continue;
			int save = st.second.rbegin()->first;
			st.second[maxp.first].push_back(maxe);
			if(canBeSolved(m, st.first,n))
				return 0;
			st.second.erase(++st.second.find(save), st.second.end());
		}
	}
	else if(canBeSolved(m, maxp.second, n))
			return 0;

	cout << -1;
	return 0;
}