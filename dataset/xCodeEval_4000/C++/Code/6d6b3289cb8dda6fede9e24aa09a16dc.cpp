
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
      
       
       
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

       
inline long long readChar();
template <class T = long long> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( long long x ); 
inline void writeWord( const char *s );
       

       
static const long long buf_size = 4096;
       
inline long long getChar() {
    static char buf[buf_size];
    static long long len = 0, pos = 0;
    if (pos == len) {
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    }
    if (pos == len) {
        return -1;
    }
    return buf[pos++];
}
       
inline long long readChar() {
    long long c = getChar();
    while (c <= 32) {
        c = getChar();
    }
    return c;
}
       
template <class T>
inline T readInt() {
    long long s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}
       

       
static long long write_pos = 0;
static char write_buf[buf_size];
       
inline void writeChar( long long x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}
       
template <class T> 
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;
       
    char s[24];
    long long n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}
       
inline void writeWord( const char *s ) {     while (*s)
writeChar(*s++); }
       
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;   
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
const string FILENAME = "input";
const int MAXN = 100001;
const int Mod = 1000000007;


int powm(int x, int st, int y) {
    if (st == 0) {
        return 1 % y; 
    } else if (st & 1) {
        int f = powm(x, st - 1, y);
        return (1LL * f * x) % y;
    } else {
        int f = powm(x, st >> 1, y);
        return (1LL * f * f) % y;
    }
}


int n, m, seed, vmax;


int rnd() {
    int ret = seed;
    seed = (1LL * seed * 7 + 13) % Mod;
    return ret;
}


struct segs
{
    int l, r;
    long long val;
    segs(){}
    segs(int _l, int _r, long long _val){
        l = _l;
        r = _r;
        val = _val;
    }
};


bool operator <(segs a, segs b) {
    return a.l < b.l;
}


set<segs> st;


inline void add(int l, int r, int xx) {  
     vector<segs> a;
    auto it = st.lower_bound(segs(l, -1, -1));
    if (it != st.begin()) {
        it--;
    }
    while (it != st.end()) {
        if (it->l > r) {
            break;
        }
        if (it->r >= l) {
            a.push_back(*it);
        }
        it++;   
    }
    for (auto x: a) {
        st.erase(x);
    }
  

    for (auto x: a) {
       

        if (x.l >= l && x.r <= r) {
            st.insert(segs(x.l, x.r, x.val + xx));
        } else {
            int fl = max(x.l, l);
            int fr = min(x.r, r);
            st.insert(segs(fl, fr, x.val + xx));
            if (x.l < l && x.r > r) {
                st.insert(segs(r + 1, x.r, x.val));
                st.insert(segs(x.l, l - 1, x.val));
            } else {
            if (x.r > r) {
                st.insert(segs(r + 1, x.r, x.val));
            } else {
                st.insert(segs(x.l, l - 1, x.val));
            }
            }
        }
    }
}


inline void setval(int l, int r, int xx) {
    vector<segs> a;
    auto it = st.lower_bound(segs(l, -1, -1));
    if (it != st.begin()) {
        it--;
    }
    while (it != st.end()) {
        if (it->l > r) {
            break;
        }
        if (it->r >= l) {
            a.push_back(*it);
        }
        it++;   
    }
    for (auto x: a) {
        st.erase(x);
    }
   

    for (auto x: a) {
     

        if (x.l < l || x.r > r) {
            if (x.l < l && x.r > r) {
                st.insert(segs(r + 1, x.r, x.val));
                st.insert(segs(x.l, l - 1, x.val));
            } else {
            if (x.r > r) {
                st.insert(segs(r + 1, x.r, x.val));
            } else {
                st.insert(segs(x.l, l - 1, x.val));
            }
            }
        }
    }
    st.insert(segs(l, r, xx));
}


bool comp(segs a, segs b) {
    return a.val < b.val;
}


inline long long ks(int l, int r, int k) {
    vector<segs> a;
    auto it = st.lower_bound(segs(l, -1, -1));
    if (it != st.begin()) {
        it--;
    }
    while (it != st.end()) {
        if (it->l > r) {
            break;
        }
        if (it->r >= l) {
            a.push_back(*it);
        }
        it++;   
    }
    sort(all(a), comp);
    for (auto x: a) {
        chkmax(x.l, l);
        chkmin(x.r, r);
        if (k <= (x.r - x.l + 1)) {
            

            return x.val;
        }
        k -= (x.r - x.l + 1);
    }
    return 228;
}


inline int getsum(int l, int r, int xx, int y) {
    int ans = 0;
     vector<segs> a;
    auto it = st.lower_bound(segs(l, -1, -1));
    if (it != st.begin()) {
        it--;
    }
    while (it != st.end()) {
        if (it->l > r) {
            break;
        }
        if (it->r >= l) {
            a.push_back(*it);
        }
        it++;   
    }
   

    for (auto x: a) {
        chkmax(x.l, l);
        chkmin(x.r, r);
        int cnt = x.r - x.l + 1;
        int g = powm(x.val % y, xx, y);
      

    

        cnt %= y;      
        ans += (1LL * g * cnt) % y;
        ans %= y;
    }   
  

    return ans;
}


int a[MAXN];


int main() {
    n = readInt(), m = readInt(), seed = readInt(), vmax = readInt();
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = rnd() % vmax + 1;
        if (i == 1 || a[i] != a[i - 1]) {
            if (cnt) {
                segs kek;
                kek.l = i - cnt;
                kek.r = i - 1;
                kek.val = a[i - 1];
                st.insert(kek);
            }
            cnt = 1;
        } else {
            cnt++;
        }
    }
    

    if (cnt) {
        segs kek;
        kek.l = n - cnt + 1;
        kek.r = n;
        kek.val = a[n];
        

        st.insert(kek);
    }
    for (int it = 0; it < m; it++) {
        int op = rnd() % 4 + 1;
        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;
        if (l > r) {
            swap(l, r);
        }
        int x;
        if (op == 3) {
            x = (rnd() % (r - l + 1)) + 1;
        } else {
            x = (rnd() % vmax) + 1;
        }
        if (op == 4) {
            int y = (rnd() % vmax) + 1;
           

            writeInt(getsum(l, r, x, y), '\n');
        } else if (op == 3) {
            

            writeInt(ks(l, r, x), '\n');
        } else if (op == 2) {
            setval(l, r, x);
        } else if (op == 1) {
            add(l, r, x);
        }  
    }
    return 0;
}

