





















    
     
     
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













const string FILENAME = "input";
const int MAXN = 200001;


string best[256] = {
    "!x&x",
    "!(x|y|z)",
    "!x&!y&z",
    "!x&!y",
    "!x&!z&y",
    "!x&!z",
    "!(!y&!z|x|y&z)",
    "!(x|y&z)",
    "!x&y&z",
    "!(!y&z|!z&y|x)",
    "!x&z",
    "!(!z&y|x)",
    "!x&y",
    "!(!y&z|x)",
    "!x&(y|z)",
    "!x",
    "!y&!z&x",
    "!y&!z",
    "!(!x&!z|x&z|y)",
    "!(x&z|y)",
    "!(!x&!y|x&y|z)",
    "!(x&y|z)",
    "!(!x&!y|x&y|z)|!x&!y&z",
    "!((x|y)&z|x&y)",
    "!x&y&z|!y&!z&x",
    "!x&y&z|!y&!z",
    "!x&z|!y&!z&x",
    "!x&z|!y&!z",
    "!x&y|!y&!z&x",
    "!x&y|!y&!z",
    "!x&(y|z)|!y&!z&x",
    "!x|!y&!z",
    "!y&x&z",
    "!(!x&z|!z&x|y)",
    "!y&z",
    "!(!z&x|y)",
    "!x&!z&y|!y&x&z",
    "!x&!z|!y&x&z",
    "!x&!z&y|!y&z",
    "!x&!z|!y&z",
    "!x&y&z|!y&x&z",
    "!(!x&z|!z&x|y)|!x&y&z",
    "!(x&y)&z",
    "!(!z&x|y)|!x&z",
    "!x&y|!y&x&z",
    "!(!y&z|x)|!y&x&z",
    "!x&y|!y&z",
    "!x|!y&z",
    "!y&x",
    "!(!x&z|y)",
    "!y&(x|z)",
    "!y",
    "!x&!z&y|!y&x",
    "!x&!z|!y&x",
    "!x&!z&y|!y&(x|z)",
    "!x&!z|!y",
    "!x&y&z|!y&x",
    "!(!x&z|y)|!x&y&z",
    "!x&z|!y&x",
    "!x&z|!y",
    "!x&y|!y&x",
    "!(!x&!y&z|x&y)",
    "!x&(y|z)|!y&x",
    "!x|!y",
    "!z&x&y",
    "!(!x&y|!y&x|z)",
    "!x&!y&z|!z&x&y",
    "!x&!y|!z&x&y",
    "!z&y",
    "!(!y&x|z)",
    "!x&!y&z|!z&y",
    "!x&!y|!z&y",
    "!x&y&z|!z&x&y",
    "!(!x&y|!y&x|z)|!x&y&z",
    "!x&z|!z&x&y",
    "!(!z&y|x)|!z&x&y",
    "!(x&z)&y",
    "!(!y&x|z)|!x&y",
    "!x&z|!z&y",
    "!x|!z&y",
    "!z&x",
    "!(!x&y|z)",
    "!x&!y&z|!z&x",
    "!x&!y|!z&x",
    "!z&(x|y)",
    "!z",
    "!x&!y&z|!z&(x|y)",
    "!x&!y|!z",
    "!x&y&z|!z&x",
    "!(!x&y|z)|!x&y&z",
    "!x&z|!z&x",
    "!(!x&!z&y|x&z)",
    "!x&y|!z&x",
    "!x&y|!z",
    "!x&(y|z)|!z&x",
    "!x|!z",
    "!y&x&z|!z&x&y",
    "!(!x&y|!y&x|z)|!y&x&z",
    "!y&z|!z&x&y",
    "!(!z&x|y)|!z&x&y",
    "!y&x&z|!z&y",
    "!(!y&x|z)|!y&x&z",
    "!y&z|!z&y",
    "!(!y&!z&x|y&z)",
    "!x&y&z|!y&x&z|!z&x&y",
    "!(!x&y|!y&x|z)|!x&y&z|!y&x&z",
    "!(x&y)&z|!z&x&y",
    "!(!z&x|y)|!x&z|!z&x&y",
    "!(x&z)&y|!y&x&z",
    "!(!y&x|z)|!x&y|!y&x&z",
    "!(x&y)&z|!z&y",
    "!x|!y&z|!z&y",
    "!(y&z)&x",
    "!(!x&y|z)|!y&x",
    "!y&z|!z&x",
    "!y|!z&x",
    "!y&x|!z&y",
    "!y&x|!z",
    "!y&(x|z)|!z&y",
    "!y|!z",
    "!(y&z)&x|!x&y&z",
    "!(!x&y|z)|!x&y&z|!y&x",
    "!(x&y)&z|!z&x",
    "!x&z|!y|!z&x",
    "!(x&z)&y|!y&x",
    "!x&y|!y&x|!z",
    "!x&y|!y&z|!z&x",
    "!(x&y&z)",
    "x&y&z",
    "!(x|y|z)|x&y&z",
    "!x&!y&z|x&y&z",
    "!x&!y|x&y&z",
    "!x&!z&y|x&y&z",
    "!x&!z|x&y&z",
    "!(!y&!z|x|y&z)|x&y&z",
    "!(x|y&z)|x&y&z",
    "y&z",
    "!(x|y|z)|y&z",
    "!x&z|y&z",
    "!x&!y|y&z",
    "!x&y|y&z",
    "!x&!z|y&z",
    "!x&(y|z)|y&z",
    "!x|y&z",
    "!y&!z&x|x&y&z",
    "!y&!z|x&y&z",
    "!(!x&!z|x&z|y)|x&y&z",
    "!(x&z|y)|x&y&z",
    "!(!x&!y|x&y|z)|x&y&z",
    "!(x&y|z)|x&y&z",
    "!(!x&!y|x&y|z)|!x&!y&z|x&y&z",
    "!((x|y)&z|x&y)|x&y&z",
    "!y&!z&x|y&z",
    "!y&!z|y&z",
    "!x&z|!y&!z&x|y&z",
    "!(x&z|y)|y&z",
    "!x&y|!y&!z&x|y&z",
    "!(x&y|z)|y&z",
    "!x&(y|z)|!y&!z&x|y&z",
    "!x|!y&!z|y&z",
    "x&z",
    "!(x|y|z)|x&z",
    "!y&z|x&z",
    "!x&!y|x&z",
    "!x&!z&y|x&z",
    "!x&!z|x&z",
    "!x&!z&y|!y&z|x&z",
    "!(x|y&z)|x&z",
    "(x|y)&z",
    "!(x|y|z)|(x|y)&z",
    "z",
    "!x&!y|z",
    "!x&y|x&z",
    "!(!y&z|x)|x&z",
    "!x&y|z",
    "!x|z",
    "!y&x|x&z",
    "!y&!z|x&z",
    "!y&(x|z)|x&z",
    "!y|x&z",
    "!x&!z&y|!y&x|x&z",
    "!(x&y|z)|x&z",
    "!x&!z&y|!y&(x|z)|x&z",
    "!x&!z|!y|x&z",
    "!y&x|y&z",
    "!(!x&z|y)|y&z",
    "!y&x|z",
    "!y|z",
    "!x&y|!y&x|x&z",
    "!x&!z|!y&x|y&z",
    "!x&y|!y&x|z",
    "!x|!y|z",
    "x&y",
    "!(x|y|z)|x&y",
    "!x&!y&z|x&y",
    "!x&!y|x&y",
    "!z&y|x&y",
    "!x&!z|x&y",
    "!x&!y&z|!z&y|x&y",
    "!(x|y&z)|x&y",
    "(x|z)&y",
    "!(x|y|z)|(x|z)&y",
    "!x&z|x&y",
    "!(!z&y|x)|x&y",
    "y",
    "!x&!z|y",
    "!x&z|y",
    "!x|y",
    "!z&x|x&y",
    "!y&!z|x&y",
    "!x&!y&z|!z&x|x&y",
    "!(x&z|y)|x&y",
    "!z&(x|y)|x&y",
    "!z|x&y",
    "!x&!y&z|!z&(x|y)|x&y",
    "!x&!y|!z|x&y",
    "!z&x|y&z",
    "!(!x&y|z)|y&z",
    "!x&z|!z&x|x&y",
    "!x&!y|!z&x|y&z",
    "!z&x|y",
    "!z|y",
    "!x&z|!z&x|y",
    "!x|!z|y",
    "(y|z)&x",
    "!(x|y|z)|(y|z)&x",
    "!y&z|x&y",
    "!(!z&x|y)|x&y",
    "!z&y|x&z",
    "!(!y&x|z)|x&z",
    "!y&z|!z&y|x&y",
    "!x&!y|!z&y|x&z",
    "(x|y)&z|x&y",
    "!(x|y|z)|(x|y)&z|x&y",
    "x&y|z",
    "!x&!y|x&y|z",
    "x&z|y",
    "!x&!z|x&z|y",
    "y|z",
    "!x|y|z",
    "x",
    "!y&!z|x",
    "!y&z|x",
    "!y|x",
    "!z&y|x",
    "!z|x",
    "!y&z|!z&y|x",
    "!y|!z|x",
    "x|y&z",
    "!y&!z|x|y&z",
    "x|z",
    "!y|x|z",
    "x|y",
    "!z|x|y",
    "x|y|z",
    "!x|x"
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   

    int n;
    cin >> n;
    for (int it = 0; it < n; it++) {
        string s;
        cin >> s;
        reverse(all(s));
        int t = 0;
        for (auto x: s) {
            t *= 2; 
            t += x - '0';
        }
        cout << best[t] << '\n';
    }
}
