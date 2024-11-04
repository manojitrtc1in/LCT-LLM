#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <fstream>
#include <functional>
#include <numeric>
#include <complex>
#include <climits>
#include <ctime>
#include <array>
#include <chrono>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
typedef vector<vector<vi>> vvvi;
typedef vector<vector<vl>> vvl;
typedef vector<vector<string>> vvss;
typedef vector<vector<double>> vvdd;
typedef vector<vector<vector<int>>> vvvvi;
typedef vector<vector<vector<ll>>> vvvvl;
typedef vector<vector<vector<pii>>> vvvpii;
typedef vector<vector<vector<pll>>> vvvpll;
typedef vector<vector<vector<vi>>> vvvvi;
typedef vector<vector<vector<vl>>> vvvvl;
typedef vector<vector<vector<string>>> vvvss;
typedef vector<vector<vector<double>>> vvvdd;
typedef vector<vector<vector<vector<int>>>> vvvvvi;
typedef vector<vector<vector<vector<ll>>>> vvvvvl;
typedef vector<vector<vector<vector<pii>>>> vvvvpii;
typedef vector<vector<vector<vector<pll>>>> vvvvpll;
typedef vector<vector<vector<vector<vi>>>> vvvvvi;
typedef vector<vector<vector<vector<vl>>>> vvvvvl;
typedef vector<vector<vector<vector<string>>>> vvvvss;
typedef vector<vector<vector<vector<double>>>> vvvvdd;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REPR(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()
#define REPO(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define REPOD(i,a,b) for(int i=(int)(a);i>(int)(b);--i)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define UNIQ(a) sort(ALL(a)),(a).erase(unique(ALL(a)),end(a))
#define FILLCHAR(a,b) memset((a),(b),sizeof(a))
#define TO_STRING(VariableName) (#VariableName)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
template<class T> string to_s(const T& x) { stringstream ss; ss<<x; return ss.str(); }
template<class T> T from_s(const string& s) { stringstream ss(s); T res; ss>>res; return res; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p) { return os<<"("<<p.first<<","<<p.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"{"; for(int i=0;i<(int)v.size();++i) { if(i)os<<","; os<<v[i]; } return os<<"}"; }

template<typename T> void printv(const vector<T>& s) { for(int i=0;i<(int)s.size();++i) cout<<s[i]<<endl; }
template<typename T> void printv(const vector<vector<T>>& s) { for(int i=0;i<(int)s.size();++i) printv(s[i]); }

template<class T> void input(T& t) { cin >> t; }
void input(int& t) { scanf("%d", &t); }
void input(long long& t) { scanf("%lld", &t); }
void input(double& t) { scanf("%lf", &t); }
void input(char& t) { scanf(" %c", &t); }
void input(string& t) { cin >> t; }
template<class T> void inputs(T& t) { input(t); }
template<class T, class... Args> void inputs(T& t, Args&... args) { input(t); inputs(args...); }

template<class T> void output(T t) { cout << t; }
void output(int t) { printf("%d", t); }
void output(long long t) { printf("%lld", t); }
void output(double t) { printf("%.15f", t); }
void output(char t) { printf("%c", t); }
void output(const string& t) { printf("%s", t.c_str()); }
template<class T> void output(const vector<T>& t) {
    if (t.empty()) return;
    output(t[0]);
    for (int i=1; i<t.size(); ++i) {
        putchar(' ');
        output(t[i]);
    }
}
template<class T> void output(const vector<vector<T>>& t) {
    if (t.empty()) return;
    output(t[0]);
    for (int i=1; i<t.size(); ++i) {
        putchar('\n');
        output(t[i]);
    }
}
template<class T> void output(const vector<set<T>>& t) {
    if (t.empty()) return;
    output(t[0]);
    for (int i=1; i<t.size(); ++i) {
        putchar('\n');
        output(t[i]);
    }
}
template<class T> void output(const vector<vector<set<T>>>& t) {
    if (t.empty()) return;
    output(t[0]);
    for (int i=1; i<t.size(); ++i) {
        putchar('\n');
        output(t[i]);
    }
}

template<class T> void output(const vector<T>& t, string delim) {
    for (int i=0; i<t.size(); ++i) {
        if (i) output(delim);
        output(t[i]);
    }
}
template<class T> void output(const vector<vector<T>>& t, string delim) {
    for (int i=0; i<t.size(); ++i) {
        if (i) putchar('\n');
        output(t[i], delim);
    }
}
template<class T> void output(const vector<set<T>>& t, string delim) {
    for (int i=0; i<t.size(); ++i) {
        if (i) putchar('\n');
        output(t[i], delim);
    }
}
template<class T> void output(const vector<vector<set<T>>>& t, string delim) {
    for (int i=0; i<t.size(); ++i) {
        if (i) putchar('\n');
        output(t[i], delim);
    }
}

template<class T> void output(const set<T>& t) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(*it);
        if (it!=last) putchar(' ');
    }
}
template<class T> void output(const set<T>& t, string delim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(*it);
        if (it!=last) output(delim);
    }
}

template<class T> void output(const set<T>& t, string delim, string start, string end) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(*it);
        if (it!=last) output(delim);
    }
    output(end);
}

template<class T> void output(const vector<set<T>>& t, string delim, string start, string end) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(*it);
        if (it!=last) output(delim);
    }
    output(end);
}

template<class T> void output(const vector<vector<set<T>>>& t, string delim, string start, string end) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(*it);
        if (it!=last) output(delim);
    }
    output(end);
}

template<class T> void output(const vector<T>& t, string delim, string start, string end) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(*it);
        if (it!=last) output(delim);
    }
    output(end);
}

template<class T> void output(const vector<vector<T>>& t, string delim, string start, string end) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(*it);
        if (it!=last) putchar('\n');
    }
    output(end);
}

template<class T> void output(const vector<set<T>>& t, string delim, string start, string end, string rowStart, string rowEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(*it, delim, rowStart, rowEnd);
        if (it!=last) putchar('\n');
    }
    output(end);
}

template<class T> void output(const vector<vector<set<T>>>& t, string delim, string start, string end, string rowStart, string rowEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(*it, delim, rowStart, rowEnd);
        if (it!=last) putchar('\n');
    }
    output(end);
}

template<class T> void output(const vector<T>& t, string delim, string start, string end, string rowStart, string rowEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(*it);
        if (it!=last) output(delim);
    }
    output(end);
}

template<class T> void output(const vector<vector<T>>& t, string delim, string start, string end, string rowStart, string rowEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(*it, delim);
        if (it!=last) putchar('\n');
    }
    output(end);
}

template<class T> void output(const set<T>& t, string delim, string start, string end, string rowStart, string rowEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(*it);
        if (it!=last) output(delim);
    }
    output(end);
}

template<class T> void output(const set<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(*it);
        output(colEnd);
        if (it!=last) output(delim);
    }
    output(end);
}

template<class T> void output(const vector<set<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(*it);
        output(colEnd);
        if (it!=last) output(delim);
    }
    output(end);
}

template<class T> void output(const vector<vector<set<T>>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(*it);
        output(colEnd);
        if (it!=last) output(delim);
    }
    output(end);
}

template<class T> void output(const vector<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(*it);
        output(colEnd);
        if (it!=last) output(delim);
    }
    output(end);
}

template<class T> void output(const vector<vector<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(*it, delim);
        output(colEnd);
        if (it!=last) putchar('\n');
    }
    output(end);
}

template<class T> void output(const set<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(delim);
    }
    output(end);
}

template<class T> void output(const vector<set<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(delim);
    }
    output(end);
}

template<class T> void output(const vector<vector<set<T>>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(delim);
    }
    output(end);
}

template<class T> void output(const vector<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(delim);
    }
    output(end);
}

template<class T> void output(const vector<vector<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it, delim);
        output(cellEnd);
        output(colEnd);
        if (it!=last) putchar('\n');
    }
    output(end);
}

template<class T> void output(const set<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<set<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<vector<set<T>>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<vector<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it, delim);
        output(cellEnd);
        output(colEnd);
        if (it!=last) putchar('\n');
    }
    output(end);
}

template<class T> void output(const set<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<set<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<vector<set<T>>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<vector<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it, delim);
        output(cellEnd);
        output(colEnd);
        if (it!=last) putchar('\n');
    }
    output(end);
}

template<class T> void output(const set<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<set<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<vector<set<T>>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<vector<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(colStart);
        output(cellStart);
        output(*it, delim);
        output(cellEnd);
        output(colEnd);
        if (it!=last) putchar('\n');
    }
    output(end);
}

template<class T> void output(const set<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        output(rowEnd2);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<set<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        output(rowEnd2);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<vector<set<T>>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        output(rowEnd2);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd);
        output(rowEnd2);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<vector<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart);
        output(cellStart);
        output(*it, delim);
        output(cellEnd);
        output(colEnd);
        output(rowEnd2);
        if (it!=last) putchar('\n');
    }
    output(end);
}

template<class T> void output(const set<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2, string colStart2, string colEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart2);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd2);
        output(rowEnd2);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<set<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2, string colStart2, string colEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart2);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd2);
        output(rowEnd2);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<vector<set<T>>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2, string colStart2, string colEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart2);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd2);
        output(rowEnd2);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2, string colStart2, string colEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart2);
        output(cellStart);
        output(*it);
        output(cellEnd);
        output(colEnd2);
        output(rowEnd2);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<vector<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2, string colStart2, string colEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart2);
        output(cellStart);
        output(*it, delim);
        output(cellEnd);
        output(colEnd2);
        output(rowEnd2);
        if (it!=last) putchar('\n');
    }
    output(end);
}

template<class T> void output(const set<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2, string colStart2, string colEnd2, string cellStart2, string cellEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart2);
        output(cellStart2);
        output(*it);
        output(cellEnd2);
        output(colEnd2);
        output(rowEnd2);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<set<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2, string colStart2, string colEnd2, string cellStart2, string cellEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart2);
        output(cellStart2);
        output(*it);
        output(cellEnd2);
        output(colEnd2);
        output(rowEnd2);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<vector<set<T>>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2, string colStart2, string colEnd2, string cellStart2, string cellEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart2);
        output(cellStart2);
        output(*it);
        output(cellEnd2);
        output(colEnd2);
        output(rowEnd2);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2, string colStart2, string colEnd2, string cellStart2, string cellEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart2);
        output(cellStart2);
        output(*it);
        output(cellEnd2);
        output(colEnd2);
        output(rowEnd2);
        if (it!=last) output(rowDelim);
    }
    output(end);
}

template<class T> void output(const vector<vector<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2, string colStart2, string colEnd2, string cellStart2, string cellEnd2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart2);
        output(cellStart2);
        output(*it, delim);
        output(cellEnd2);
        output(colEnd2);
        output(rowEnd2);
        if (it!=last) putchar('\n');
    }
    output(end);
}

template<class T> void output(const set<T>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2, string colStart2, string colEnd2, string cellStart2, string cellEnd2, string rowDelim2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart2);
        output(cellStart2);
        output(*it);
        output(cellEnd2);
        output(colEnd2);
        output(rowEnd2);
        if (it!=last) output(rowDelim2);
    }
    output(end);
}

template<class T> void output(const vector<set<T>>& t, string delim, string start, string end, string rowStart, string rowEnd, string colStart, string colEnd, string cellStart, string cellEnd, string rowDelim, string colDelim, string cellDelim, string rowStart2, string rowEnd2, string colStart2, string colEnd2, string cellStart2, string cellEnd2, string rowDelim2) {
    if (t.empty()) return;
    auto last = t.end(); --last;
    output(start);
    for (auto it=t.begin(); it!=t.end(); ++it) {
        output(rowStart2);
        output(colStart2);
        output(cellStart2);
        output(*it);
        output(cellEnd2);
        output(colEnd2);
        output(rowEnd2);
        if (it!=last) output(rowDelim2);
    }
    output(end);
}

