#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <list>
#include <string>

typedef char                SINT8;
typedef short               SINT16;
typedef int                 SINT32;
typedef long long           SINT64;
typedef double              DOUBLE;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))
#define rep(i,a,b) for(SINT64 (i)=SINT64(a);(i)<SINT64(b);(i)++)
#define rrep(i,a,b) for(SINT64 (i)=SINT64(a);(i)>=SINT64(b);(i)--)

#define put(a) cout << (a) << endl
#define puts(a) cout << (a) << " "


#define INF 1000000001
#define MOD 1000000007
#define INF64 1000000000000000001

#define F first
#define S second

#define Pii  pair<SINT32,SINT32>
#define Pll  pair<SINT64,SINT64>
#define Piii pair<SINT32,pair<SINT32,SINT32>>
#define Plll pair<SINT64,pair<SINT64,SINT64>>

#define Vll(a,b,c)    vector<vector<SINT64>> (a)((b),vector<SINT64>((c))
#define Vlll(a,b,c,d) vector<vector<vector<SINT64>>> (a)((b),vector<vector<SINT64>>((c),vector<SINT64>((d)))


using namespace std;

int main() {

	SINT64 N;	cin >> N;
	
	vector<Plll> data1;
	vector<Plll> data2;
	vector<Plll> data3;
	vector<Plll> data4;
	
	rep(i,0,N) {
		SINT64 a,b,c,d;
		cin >> a >> b >> c >> d;
		Plll buf;
		buf.F = b;
		buf.S.F = a;
		buf.S.S = i;
		data1.emplace_back(buf);
		buf.F = i;
		buf.S.F = c;
		buf.S.S = d;
		data2.emplace_back(buf);


		buf.F = d;
		buf.S.F = c;
		buf.S.S = i;
		data3.emplace_back(buf);
		buf.F = i;
		buf.S.F = a;
		buf.S.S = b;
		data4.emplace_back(buf);


	}
	sort(data1.begin(),data1.end(),std::greater<Plll>());
	sort(data3.begin(),data3.end(),std::greater<Plll>());
	
	priority_queue<Pll, vector<Pll>> q;
	multiset<SINT64> st1;
	multiset<SINT64> st2;
	multiset<SINT64> st3;
	multiset<SINT64> st4;

	rep(i,0,N) {
		while(1) {
			if (q.size() == 0) break;
			Pll buf = q.top();
			if (buf.F > data1[i].F) {
				q.pop();
				st1.erase(data2[buf.S].S.F);
				st2.erase(data2[buf.S].S.S);
				if (st1.size() != 0) {
				if (*st1.rbegin() > *st2.begin()) {
					put("NO");
					return 0;				
				}
				}

			} else {
				break;
			}
		}
		q.push(Pll(data1[i].S.F, data1[i].S.S));
		st1.insert(data2[data1[i].S.S].S.F);
		st2.insert(data2[data1[i].S.S].S.S);

		if (st1.size() != 0) {
			if (*st1.rbegin() > *st2.begin()) {
				put("NO");
				return 0;				
			}
		}
	}

	while(1) {
		if (q.size() == 0) break;
		Pll buf = q.top();
		q.pop();
		st1.erase(data2[buf.S].S.F);
		st2.erase(data2[buf.S].S.S);
		if (st1.size() != 0) {
			if (*st1.rbegin() > *st2.begin()) {
				put("NO");
				return 0;				
			}
		}
	}


	rep(i,0,N) {
		while(1) {
			if (q.size() == 0) break;
			Pll buf = q.top();
			if (buf.F > data3[i].F) {
				q.pop();
				st3.erase(data4[buf.S].S.F);
				st4.erase(data4[buf.S].S.S);
				if (st3.size() != 0) {
				if (*st3.rbegin() > *st4.begin()) {
					put("NO");
					return 0;				
				}
				}

			} else {
				break;
			}
		}
		q.push(Pll(data3[i].S.F, data3[i].S.S));
		st3.insert(data4[data3[i].S.S].S.F);
		st4.insert(data4[data3[i].S.S].S.S);

		if (st3.size() != 0) {
			if (*st3.rbegin() > *st4.begin()) {
				put("NO");
				return 0;				
			}
		}
	}

	while(1) {
		if (q.size() == 0) break;
		Pll buf = q.top();
		q.pop();
		st3.erase(data4[buf.S].S.F);
		st4.erase(data4[buf.S].S.S);
		if (st3.size() != 0) {
			if (*st3.rbegin() > *st4.begin()) {
				put("NO");
				return 0;				
			}
		}
	}
	put("YES");
	return 0;
}








































































































































