
#include <iostream>
#include <complex>
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

     
inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
     

     
static const int buf_size = 4096;
     
inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len) {
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    }
    if (pos == len) {
        return -1;
    }
    return buf[pos++];
}
     
inline int readChar() {
    int c = getChar();
    while (c <= 32) {
        c = getChar();
    }
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
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> bads[228];
bool vz[17];
int c[5][5];
int c1[100001][5];


void get(int i, int j) {
    if (j == 5) {
        get(i + 1, 1);
        return;
    }
    if (i == 5 && j == 1) {
        cout << "YES\n";
        for (int i = 1; i <= 4; i++) {
            for (int j = 1;  j <= 4; j++) {
                cout << c[i][j] << ' ';
            }
            cout << endl;
        }
        exit(0);
    }
    for (int it = 1; it <= 16; it++) {
        if (!vz[it]) {
            bool bad = false;
            for (auto x: bads[it]) {
            if (c[i - 1][j] == x || c[i + 1][j] == x || c[i][j - 1] == x || c[i][j + 1] == x) {
                bad = true;
                break;
            }
            }
            if (!bad) {
                vz[it] = true;
                c[i][j] = it;
                get(i, j + 1);
                vz[it] = false;
                c[i][j] = 0;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   

    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << "YES\n";
        cout << 1 << '\n';
        return 0;
    }
    if (n == 1) {
        if (m <= 3)  {
            cout << "NO\n";
            return 0;
        }
        if (m == 4) {
            cout << "YES\n";
            cout << "2 4 1 3" << endl;
            return 0;
        }
        cout << "YES\n";
        for (int i = 1; i <= m; i += 2) {
            cout << i << ' ';
        }
        for (int i = 2; i <= m; i += 2) {
            cout << i << ' ';
        }
        cout << '\n';
        return 0;
    }
    if (m == 1) {
        if (n <= 3)  {
            cout << "NO\n";
            return 0;
        }
        if (n == 4) {
            cout << "YES\n";
            cout << 2 << endl;
            cout << 4 << endl;
            cout << 1 << endl;
            cout << 3 << endl;
            return 0;
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i += 2) {
            cout << i << '\n';
        }
        for (int i = 2; i <= n; i += 2) {
            cout << i << '\n';
        }
        return 0;
    }
    if (n <= 4 && m <= 4) {
        if (n == 2 && m == 2) {
            cout << "NO\n";
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < 4; k++) {
                    int i1 = i + dx[k];
                    int j1 = j + dy[k];
                    if (i1 < 1 || j1 < 1 || i1 > n || j1 > m) {
                        continue;
                    }
                    bads[(i - 1) * m + j].push_back((i1 - 1) * m + j1);
                }
            }
        }
        if (n == 2 && m == 3) {
            cout << "NO\n";
            return 0;
        }
        if (n == 3 && m == 2) {
            cout << "NO\n";
            return 0;
        }
        if (n == 3 && m == 3) {
             cout << "YES\n";
             cout << "1 3 5\n";
             cout << "6 4 9\n";
             cout << "8 2 7\n";
            return 0;
        }
        if (n == 3 && m == 4) {
            cout << "YES\n";
            cout << "1 3 5 2\n";
            cout << "4 6 12 9\n";
            cout << "11 8 10 7\n";
            return 0;
        }
        if (n == 4 && m == 3) {
            cout << "YES\n";
            cout << "1 3 5\n";
            cout << "6 4 9\n";
            cout << "7 12 10\n";
            cout << "11 2 8\n";
            return 0;
        }
        if (n == 2 && m == 4) {
            cout << "YES\n";
            cout << "1 3 5 2\n";
            cout << "8 6 4 7\n";
            return 0;
        }
        if (n == 4 && m == 2) {
            cout << "YES\n";
            cout << "1 4\n";
            cout << "5 8\n";
            cout << "2 3\n";
            cout << "6 7\n";
            return 0;
        }
        get(1, 1);
        cout << "NO\n";
        return 0;
    }
    if (n >= 5 && m < 4) {
        for (int i = 1; i <= m; i++) {
            vector<int> g;
            for (int j = 1; j <= n; j+= 2) {
                g.push_back((j - 1) * m + i);
            }
            for (int j = 2; j <= n; j+= 2) {
                g.push_back((j - 1) * m + i);
            }
            for (int j = 1; j <= n; j++) {
                c1[j][i] = g[(j - 1 + (i - 1) % 2) % sz(g)];
            }
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1;  j <= m; j++) {
                cout << c1[i][j] << ' ';
            }
            cout << endl;
        }
        return 0;
    }
     if (m >= 5 && n < 4) {
        for (int i = 1; i <= n; i++) {
            vector<int> g;
            for (int j = 1; j <= m; j+= 2) {
                g.push_back((i - 1) * m + j);
            }
            for (int j = 2; j <= m; j+= 2) {
                g.push_back((i - 1) * m + j);
            }
            for (int j = 1; j <= m; j++) {
                c1[j][i] = g[(j - 1 + (i - 1) % 2) % sz(g)];
            }
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1;  j <= m; j++) {
                cout << c1[j][i] << ' ';
            }
            cout << endl;
        }
        return 0;
    }
    cout << "YES\n";
    vector<int> order;
    for (int i = 2; i <= n; i+= 2) {
        order.push_back(i);
    }
    for (int i = 1; i <= n; i+= 2) {
        order.push_back(i);
    }
    vector<int> order1;
    for (int i = 2; i <= m; i+= 2) {
        order1.push_back(i);
    }
    for (int i = 1; i <= m; i+= 2) {
        order1.push_back(i);
    }
    for (auto x: order) {
        for (auto y: order1) {
            cout << (x - 1) * m + y << ' ';
        }
        cout << "\n";
    }
}
