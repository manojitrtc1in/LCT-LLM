














































using namespace std;



















const string id4 = "1";
int FILEIO (string IN, string OUT) {
    try {
        freopen ((id4 + IN).c_str (), "r", stdin);
        freopen ((id4 + OUT).c_str (), "w", stdout);
        return 0;
    } catch (int) {
        return -1;
    }
}
int id3 = FILEIO (".in", ".out");


inline int rd () {
	int f = 1;
	char ch = getchar ();
	while (!isdigit (ch)) (ch == '-' ? (f = -1) : 0), ch = getchar ();
	int num = 0;
	while (isdigit (ch)) num = num * 10 + ch - '0', ch = getchar ();
	return num * f;
}


inline int rd (const int modp) {
	int f = 1;
	char ch = getchar ();
	while (!isdigit (ch)) (ch == '-' ? (f = -1) : 0), ch = getchar ();
	int num = 0;
	while (isdigit (ch)) num = (num * 10 + ch - '0') % modp, ch = getchar ();
	return (num * f % modp + modp) % modp;
}


struct Edge {
	int v, nxt;

	W_TYPE w;

	Edge () {}

	Edge (int _v, W_TYPE _w, int _nxt) {v = _v, w = _w, nxt = _nxt;}

	Edge (int _v, int _nxt) {v = _v, nxt = _nxt;}

} edge[EDGES];
int head[VERTEXES], ecnt;

void addedge (int u, int v, W_TYPE w) {edge[++ecnt] = Edge (v, w, head[u]); head[u] = ecnt;}
void addEdge (int u, int v, W_TYPE w) {addedge (u, v, w), addedge (v, u, w);}


void addedge (int u, int v) {edge[++ecnt] = Edge (v, head[u]); head[u] = ecnt;}
void addEdge (int u, int v) {addedge (u, v), addedge (v, u);}


void init () {memset (head, 0, sizeof head); ecnt = 0;}


namespace lay::CPX {
    class cpx {
        public:
            double a, b;
            cpx () {a = 0, b = 0;}
            cpx (double _a) {a = _a, b = 0;}
            cpx (double _a, double _b) {a = _a, b = _b;}
            friend cpx operator + (cpx a, cpx b) {return cpx (a.a + b.a, a.b + b.b);}
            friend cpx operator - (cpx a, cpx b) {return cpx (a.a - b.a, a.b - b.b);}
            friend cpx operator * (cpx a, cpx b) {return cpx (a.a * b.a - a.b * b.b, a.b * b.a + a.a * b.b);}
            friend cpx operator / (cpx a, cpx b) {return cpx ((a.a * b.a + a.b * b.b) / (b.b * b.b + b.a * b.a), (a.b * b.a - a.a * b.b) / (b.b * b.b + b.a * b.a));}
            friend cpx& operator += (cpx &a, cpx b) {return a = a + b;}
            friend cpx& operator -= (cpx &a, cpx b) {return a = a - b;}
            friend cpx& operator *= (cpx &a, cpx b) {return a = a * b;}
            friend cpx& operator /= (cpx &a, cpx b) {return a = a / b;}
    };
}

inline void Write (int x) {
	if (x < 0) putchar ('-'), x *= -1;
	if (x >= 10) Write (x / 10);
	putchar (x % 10 + '0');
}
template <typename T> void write (char sep, char end, T x) {Write (x); putchar (end);}
template <typename T, typename... Ts> void write (char sep, char end, T x, Ts... xs) {Write (x); putchar (sep); write (sep, end, xs...);}
template <typename... Ts> void output (Ts... xs) {write (' ', '\n', xs...);}


namespace lay::MATH {
    template <typename T = int>
    class _Math {
    public:
        static T exmax (T x) {return x;}
        template <typename... Ts> static T exmax (T x, Ts... xs) {return max (x, exmax (xs...));}
        static T exmin (T x) {return x;}
        template <typename... Ts> static T exmin (T x, Ts... xs) {return min (x, exmin (xs...));}
        template <typename... Ts> static T id2 (T &x, Ts... xs) {return x = exmax (x, xs...);}
        template <typename... Ts> static T id1 (T &x, Ts... xs) {return x = exmin (x, xs...);}

        static T gcd (T a, T b) {return !b ? a : gcd (b, a % b);}
        static T lcm (T a, T b) {return a / gcd (a, b) * b;}
        static T exgcd (T a, T b, T& x, T& y) {
            if (!b) {x = 1; y = 0; return a;}
            T ans = exgcd (b, a % b, y, x);
            y -= a / b * x;
            return ans;
        }
        static T crt (size_t n, T *a, T *p) {
            T M = 1, ans = 0;
            fq (i, 1, n) M *= p[i];
            fq (i, 1, n) {
                T m = M / p[i];
                T x, y;
                exgcd (m, p[i], x, y);
                ans += (x < 0 ? x + p[i] : x) * a[i] * m;
            } return ans % M;
        }
        static T excrt (size_t n, T *a, T *b) {
            T M = b[1], ans = a[1];
            fq (i, 2, n) {
                T aa = M, c = (a[i] - ans % b[i] + b[i]) % b[i];
                T x, y;
                T gcd = exgcd (aa, b[i], x, y);
                if (c % gcd) return -1;
                T bg = b[i] / gcd;
                x = c / gcd * x % bg;
                ans += x * M;
                M *= bg;
                ans = (ans % M + M) % M;

            }
            return (ans % M + M) % M;
        }
        static T power (T a, T b, T p) {
            T c = 1;
            while (b) {
                if (b & 1) c = c * a % p;
                a = a * a % p;
                b >>= 1;
            } return c;
        }
    private:
        static T C (T n, T m, T p) {
            T ans = 1;
            fq (i, n - m + 1, n) ans = ans * i % p;
            fq (i, 2, m) ans = ans * power (i, p - 2, p) % p;
            return ans;
        }
    public:
        static T lucas (T n, T m, T p) {
            if (!m || !n) return 1;
            return lucas (n / p, m / p, p) * C (n % p, m % p, p) % p;
        }
        static T bsgs (T a, T b, T p) {
            T mul = 1, t = sqrt (p) + 1;
            static map <T, T> mp;
            mp.clear ();
            fq (i, 1, t) {
                mul = mul * a % p;
                mp[b * mul % p] = i;
            }
            T mull = mul;
            fq (i, 1, t) {
                if (mp[mull]) return i * t - mp[mull];
                mull = mull * mul % p;
            } return -1;
        }
    };
    const _Math <> iMath;
    auto Math = iMath;
}

namespace lay::EXMATH {
    template <typename T = int>
    class _ExMath {
    private:
        static void expr_skpop (stack <char> &sk1, stack <T> &sk2, T fun (T, T, char)) {
            T r = sk2.top (); sk2.pop ();
            T l = sk2.top (); sk2.pop ();
            char op = sk1.top (); sk1.pop ();
            sk2.push (fun (l, r, op));
        }
    public:
        static T expr (string s, map <char, short> mp, T fun (T, T, char)) {
            static stack <char> sk1;
            static stack <T> sk2;
            while (!sk1.empty ()) sk1.pop ();
            while (!sk2.empty ()) sk2.pop ();
            s = '(' + s + ')';
            int len = s.size ();
            fnq (i, 0, len) {
                if (isdigit (s[i])) {
                    T num = 0;
                    while (isdigit (s[i])) num = num * 10 + s[i] - '0', ++i;
                    --i;
                    sk2.push (num);
                } elif (s[i] == '(') {
                    sk1.push ('(');
                } elif (s[i] == ')') {
                    while (sk1.top () != '(')
                        expr_skpop (sk1, sk2, fun);
                    sk1.pop ();
                } else {
                    while (!sk1.empty () && sk1.top () != '(' && mp[sk1.top ()] >= mp[s[i]])
                        expr_skpop (sk1, sk2, fun);
                    sk1.push (s[i]);
                }
            }
            return sk2.top ();
        }
    };
    const _ExMath <> id0;
    auto ExMath = id0;
}

namespace lay::MODINT {
    using namespace lay::MATH;
    int Eular (int x) {
        int sqrtx = sqrt (x);
        int ans = x;
        fq (i, 2, sqrtx) if (x % i == 0) {
            ans = ans / i * (i - 1);
            while (x % i == 0) x /= i;
        } if (x > 1) ans = ans / x * (x - 1);
        return ans;
    }
    template <int p>
    class Modint {
        private:
            const static int eular = Eular (p);
            int num;
            static int unsave_constructor (int x) {return (x % p + p) % p;}
        public:
            int toInt () {return num;}
            Modint () {}
            Modint (int x) {num = unsave_constructor (x);}
            friend Modint operator + (Modint a, Modint b) {int c = a.num + b.num; if (c >= p) c -= p; return Modint (c);}
            friend Modint operator - (Modint a, Modint b) {int c = a.num - b.num; if (c < 0) c += p; return Modint (c);}
            friend Modint operator * (Modint a, Modint b) {return Modint <p> :: unsave_constructor (a.num * b.num);}
            friend Modint operator / (Modint a, Modint b) {return Modint <p> :: unsave_constructor (a.num * Math.power (b.num, p - 2, p));}
            friend Modint operator ^ (Modint a, Modint b) {return Math.power (a.num, b.num % Modint <p> :: eular, p);}
            friend Modint& operator += (Modint &a, Modint b) {return a = a + b;}
            friend Modint& operator -= (Modint &a, Modint b) {return a = a - b;}
            friend Modint& operator *= (Modint &a, Modint b) {return a = a * b;}
            friend Modint& operator /= (Modint &a, Modint b) {return a = a / b;}
            friend Modint& operator ^= (Modint &a, Modint b) {return a = a ^ b;}
            Modint& operator ++ () {*this += 1; return *this;}
            Modint operator ++ (int) {Modint cpy = *this; ++(*this); return cpy;}
            Modint& operator -- () {*this -= 1; return *this;}
            Modint operator -- (int) {Modint cpy = *this; --(*this); return cpy;}
            friend istream& operator >> (istream& in, Modint x) {x = rd (p); return in;}
            friend ostream& operator << (ostream&out, Modint x) {out << x.toInt (); return out;}
    };  
}
using namespace lay;
const int maxn = 110;
char mp[110][110];
int n, m;
const int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};

bool check2 (int x, int y) {
	int cnt = 0;
	fq (k, 0, 7) {
		int xx = x + dir[k][0];
		int yy = y + dir[k][1];
		if (mp[xx][yy] == '*') ++cnt;
	} return cnt == 2;
}

bool check () {
	

		

		

			

			

			

				

				

				

			

		

		

	

	

		

		

		

			

			

			

				

		

	

	fq (x, 1, n) fq (y, 1, m) if (mp[x][y] == '*') {
		if (mp[x + 1][y] == '*' && mp[x][y + 1] == '*') {
			if (mp[x - 1][y +-1] == '*') return 0;
			if (mp[x - 1][y + 0] == '*') return 0;
			if (mp[x - 1][y + 1] == '*') return 0;
			if (mp[x - 1][y + 2] == '*') return 0;
			if (mp[x + 0][y - 1] == '*') return 0;
			if (mp[x + 1][y - 1] == '*') return 0;
			if (mp[x + 2][y - 1] == '*') return 0;
			if (mp[x + 2][y + 0] == '*') return 0;
			if (mp[x + 2][y + 1] == '*') return 0;
			if (mp[x + 1][y + 1] == '*') return 0;
			if (mp[x + 1][y + 2] == '*') return 0;
			if (mp[x + 0][y + 2] == '*') return 0;
			mp[x][y] = mp[x + 1][y] = mp[x][y + 1] = '.';
		}
		elif (mp[x + 1][y + 1] == '*' && mp[x][y + 1] == '*') {
			
			if (mp[x - 1][y +-1] == '*') return 0;
			if (mp[x - 1][y + 0] == '*') return 0;
			if (mp[x - 1][y + 1] == '*') return 0;
			if (mp[x - 1][y + 2] == '*') return 0;
			if (mp[x + 0][y + 2] == '*') return 0;
			if (mp[x + 1][y + 2] == '*') return 0;
			if (mp[x + 2][y + 2] == '*') return 0;
			if (mp[x + 2][y + 1] == '*') return 0;
			if (mp[x + 2][y + 0] == '*') return 0;
			if (mp[x + 1][y + 0] == '*') return 0;
			if (mp[x + 1][y +-1] == '*') return 0;
			if (mp[x + 0][y +-1] == '*') return 0;
			mp[x][y] = mp[x + 1][y + 1] = mp[x][y + 1] = '.';
		}
		elif (mp[x + 1][y] == '*' && mp[x + 1][y + 1] == '*') {
			
			if (mp[x - 1][y +-1] == '*') return 0;
			if (mp[x + 2][y + 0] == '*') return 0;
			if (mp[x + 2][y + 1] == '*') return 0;
			if (mp[x + 2][y + 2] == '*') return 0;
			if (mp[x + 0][y - 1] == '*') return 0;
			if (mp[x + 1][y - 1] == '*') return 0;
			if (mp[x + 2][y - 1] == '*') return 0;
			if (mp[x +-1][y + 0] == '*') return 0;
			if (mp[x +-1][y + 1] == '*') return 0;
			if (mp[x + 0][y + 1] == '*') return 0;
			if (mp[x + 0][y + 2] == '*') return 0;
			if (mp[x + 1][y + 2] == '*') return 0;
			mp[x][y] = mp[x + 1][y] = mp[x + 1][y + 1] = '.';
		}
		elif (mp[x + 1][y] == '*' && mp[x + 1][y - 1] == '*') {
			if (y == 1) return 0;
			
			if (mp[x - 1][y + 1] == '*') return 0;
			if (mp[x - 0][y + 1] == '*') return 0;
			if (mp[x + 1][y + 1] == '*') return 0;
			if (mp[x + 2][y + 1] == '*') return 0;
			if (mp[x + 2][y + 0] == '*') return 0;
			if (mp[x + 2][y +-1] == '*') return 0;
			if (mp[x + 2][y +-2] == '*') return 0;
			if (mp[x + 1][y +-2] == '*') return 0;
			if (mp[x + 0][y +-2] == '*') return 0;
			if (mp[x + 0][y +-1] == '*') return 0;
			if (mp[x +-1][y +-1] == '*') return 0;
			if (mp[x +-1][y + 0] == '*') return 0;
			mp[x][y] = mp[x + 1][y] = mp[x + 1][y - 1] = '.';
		} else return 0;
	} return 1;
}

signed main () {
    McasesT {
    	n = d, m = d;
    	memset (mp, 0, sizeof mp);
    	fq (i, 1, n) cin >> mp[i] + 1;
    	puts (check () ? "YES" : "NO");
    }
	return 0;
}
