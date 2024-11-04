


































































































































































































































































































































































































































































































































#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")



#define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>

using namespace std;































using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e18;




inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );

const int MAX = 1e6 + 10;


struct Qelem {
    int next;
    int v;
};
int pos, qhead[MAX]; 

Qelem q[MAX];

struct Edge {
    int to;
    int w;
    int next;
};

Edge edges[101011];
int head[101013];




using pli = pair<ll, int>;
pli dres[102023];

int main() {
    int n, m, queries;
#ifdef DEBUG
    n = 0.5e5, m = 1e5, queries = 2000;
#else
    n = readInt();
    m = readInt();
    queries = readInt();
#endif
    
    memset(head, -1, sizeof(head));
    

    forn(i, m) {
#ifdef DEBUG
        int a = rand() % n, b = rand() % n, c = rand() % 10000;
#else
        int a = readInt();
        int b = readInt();
        int c = readInt();
        a--, b--;
#endif
        edges[i].to = b;
        edges[i].w = c;
        edges[i].next = head[a];
        head[a] = i;
    }
    auto Dijkstra = [&]() {
        set<pii> s;
        fill(dres, dres + n, pli(INF, INF));
        s.insert(pii(dres[0].first = 0, 0));
        while (s.size()) {
            int v = s.begin()->second;
            s.erase(s.begin());
            for (int i = head[v]; i != -1; i = edges[i].next) {
                int to = edges[i].to;
                int w = edges[i].w;
                if (dres[to].first > dres[v].first + w) {
                    s.erase(pii(dres[to].first, to));
                    s.insert(pii(dres[to].first = dres[v].first + w, to));
                }
            }
        }
    };
    

    Dijkstra();
    

    

    
    int k = 0;
    

    auto bfs = [&]() {
        

        memset(qhead, -1, sizeof(qhead[0]) * (k + 1));
        pos = 0;
        for (int i = 0; i < n; ++i) {
            dres[i].second = (int) 1e9;
        }
        dres[0].second = 0;
        auto addq = [&]( int i, int v ) {
            q[pos].next = qhead[i], q[pos].v = v, qhead[i] = pos++;
        };
        addq(0, 0);
        

        

        forn(dist, k + 1)
        while (qhead[dist] != -1) {
            int p = qhead[dist];
            int v = q[p].v;
            qhead[dist] = q[p].next;
            if (dres[v].second != dist)
                continue;
            auto dv = dres[v].first;
            int resv = dres[v].second;
            for (int i = head[v]; i != -1; i = edges[i].next) {
                int to = edges[i].to;
                int w = edges[i].w;
                int tmp = int(dv + resv + w - dres[to].first);
                if (tmp <= k && dres[to].second > tmp) {
                    dres[to].second = tmp, addq(tmp, to);
                }
            }
        }
        

        

        

        forn(i, n)
        if (dres[i].first != INF)
            dres[i].first += dres[i].second;
    };
    
    while (queries--) {
        int type;
#ifdef DEBUG
        type = 2;
#else
        type = readInt();
#endif
        if (type == 1) {
            int v = readInt();
            if (dres[v - 1].first == INF)
                puts("-1");
            else {
                if (k > 0)
                    bfs(), k = 0;
                printf("%lld\n", dres[v - 1].first);
            }
        } else {
            int cnt, i;
#ifdef DEBUG
            cnt = 2000;
#else
            cnt = readInt();
#endif
            forn(_, cnt) {
#ifdef DEBUG
                i = rand() % m;
#else
                i = readInt() - 1;
#endif
                edges[i].w++;
            }
            k += cnt;
            

            





        }
    }
    cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    

    

}



static const int buf_size = 4096;

inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len)
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    if (pos == len)
        return -1;
    return buf[pos++];
}

inline int readChar() {
    int c = getChar();
    while (c <= 32)
        c = getChar();
    return c;
}

template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}



static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}

template <class T> 
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;
    
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}

struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;