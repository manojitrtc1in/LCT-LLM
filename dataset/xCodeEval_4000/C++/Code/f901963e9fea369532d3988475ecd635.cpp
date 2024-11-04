#include <bits/stdc++.h>






#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-99

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(str) scanf("%s",str)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define NL printf("\n")
#define Max 100005
#define INF 1e9
#define un(x) x.erase(unique( x.begin() , x.end() ), x.end())

#define FI freopen("in.txt","r",stdin)

#define D(x) cout << #x << " = " << x << endl
#define DD(x,y) cout << #x << " = " << x << "   " << #y << " = " << y << endl
#define DDD(x,y,z) cout << #x << " = " << x << "   " << #y << " = " << y << "   " << #z << " = " << z << endl

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

int setb(int n,int pos) { return n=n | (1 << pos); }
int resb(int n,int pos) { return n=n & ~(1 << pos); }
bool checkb(int n,int pos) { return (bool)(n & (1 << pos)); }

#define MAXN (1 << 19) 

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

using namespace std;




namespace fft{
    int len, last = -1, step = 0, rev[MAXN];
    long long C[MAXN], D[MAXN], P[MAXN], Q[MAXN];

	struct complx{
        long double real, img;

        inline complx(){
            real = img = 0.0;
        }

        inline complx conjugate(){
            return complx(real, -img);
        }

        inline complx(long double x){
            real = x, img = 0.0;
        }

        inline complx(long double x, long double y){
            real = x, img = y;
        }

        inline complx operator + (complx other){
            return complx(real + other.real, img + other.img);
        }

        inline complx operator - (complx other){
            return complx(real - other.real, img - other.img);
        }

        inline complx operator * (complx other){
            return complx((real * other.real) - (img * other.img), (real * other.img) + (img * other.real));
        }
    } u[MAXN], v[MAXN], f[MAXN], g[MAXN], dp[MAXN], inv[MAXN];

    inline long long round_half_even(long double x){
        long long res = abs(x) + 0.5;
        if (x < 0) res = -res;
        return res;
    }

    

    void build(int& a, long long* A, int& b, long long* B){
        while (a > 1 && A[a - 1] == 0) a--;
        while (b > 1 && B[b - 1] == 0) b--;

	    len = 1 << (32 - __builtin_clz(a + b) - (__builtin_popcount(a + b) == 1));
        for (int i = a; i < len; i++) A[i] = 0;
        for (int i = b; i < len; i++) B[i] = 0;

		if (!step++){
            dp[1] = inv[1] = complx(1);
            for (int i = 1; (1 << i) < MAXN; i++){
                double theta = (2.0 * acos(0.0)) / (1 << i);
                complx mul = complx(cos(theta), sin(theta));
                complx inv_mul = complx(cos(-theta), sin(-theta));

                int lim = 1 << i;
                for (int j = lim >> 1; j < lim; j++){
                    dp[2 * j] = dp[j], inv[2 * j] = inv[j];
                    inv[2 * j + 1] = inv[j] * inv_mul;
                    dp[2 * j + 1] = dp[j] * mul;
                }
            }
        }

        if (last != len){
            last = len;
            int bit = (32 - __builtin_clz(len) - (__builtin_popcount(len) == 1));
            for (int i = 0; i < len; i++) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (bit - 1));
        }
	}

    

	void transform(complx *in, complx *out, complx* ar){
	    for (int i = 0; i < len; i++) out[i] = in[rev[i]];
	    for (int k = 1; k < len; k <<= 1){
            for (int i = 0; i < len; i += (k << 1)){
                for (int j = 0; j < k; j++){
                    complx z = out[i + j + k] * ar[j + k];
                    out[i + j + k] = out[i + j] - z;
                    out[i + j] = out[i + j] + z;
                }
            }
	    }
	}

    

	void transform_unrolled(complx *in, complx *out, complx* ar){
	    for (int i = 0; i < len; i++) out[i] = in[rev[i]];
	    for (int k = 1; k < len; k <<= 1){
            for (int i = 0; i < len; i += (k << 1)){
                complx z, *a = out + i, *b = out + i + k, *c = ar + k;
                if (k == 1){
                    z = (*b) * (*c);
                    *b = *a - z, *a = *a + z;
                }

                for (int j = 0; j < k && k > 1; j += 2, a++, b++, c++){
                    z = (*b) * (*c);
                    *b = *a - z, *a = *a + z;
                    a++, b++, c++;
                    z = (*b) * (*c);
                    *b = *a - z, *a = *a + z;
                }
            }
	    }
	}

	bool equals(int a, long long* A, int b, long long* B){
        if (a != b) return false;
        for (a = 0; a < b && A[a] == B[a]; a++){}
        return (a == b);
	}

    

	int square(int a, long long* A){
        build(a, A, a, A);
        for (int i = 0; i < len; i++) u[i] = complx(A[i], 0);
        transform_unrolled(u, f, dp);
        for (int i = 0; i < len; i++) u[i] = f[i] * f[i];
        transform_unrolled(u, f, inv);
        for (int i = 0; i < len; i++) A[i] = round_half_even(f[i].real / (long double)len);
        return a + a - 1;
	}

    

    

	int multiply(int a, long long* A, int b, long long* B){
	    if (equals(a, A, b, B)) return square(a, A); 


		build(a, A, b, B);
		for (int i = 0; i < len; i++) u[i] = complx(A[i], B[i]);
		transform_unrolled(u, f, dp);
		for (int i = 0; i < len; i++){
            int j = (len - 1) & (len - i);
            u[i] = (f[j] * f[j] - f[i].conjugate() * f[i].conjugate()) * complx(0, -0.25 / len);
		}
		transform_unrolled(u, f, dp);
		for (int i = 0; i < len; i++) A[i] = round_half_even(f[i].real);
		return a + b - 1;
	}

    

	int mod_multiply(int a, long long* A, int b, long long* B, int mod){
	    build(a, A, b, B);
	    int flag = equals(a, A, b, B);
	    for (int i = 0; i < len; i++) A[i] %= mod, B[i] %= mod;
	    for (int i = 0; i < len; i++) u[i] = complx(A[i] & 32767, A[i] >> 15);
	    for (int i = 0; i < len; i++) v[i] = complx(B[i] & 32767, B[i] >> 15);

		transform_unrolled(u, f, dp);
		for (int i = 0; i < len; i++) g[i] = f[i];
		if (!flag) transform_unrolled(v, g, dp);

		for (int i = 0; i < len; i++){
            int j = (len - 1) & (len - i);
            complx c1 = f[j].conjugate(), c2 = g[j].conjugate();

            complx a1 = (f[i] + c1) * complx(0.5, 0);
			complx a2 = (f[i] - c1) * complx(0, -0.5);
			complx b1 = (g[i] + c2) * complx(0.5 / len, 0);
			complx b2 = (g[i] - c2) * complx(0, -0.5 / len);
			v[j] = a1 * b2 + a2 * b1;
			u[j] = a1 * b1 + a2 * b2 * complx(0, 1);
		}
		transform_unrolled(u, f, dp);
		transform_unrolled(v, g, dp);

        long long x, y, z;
		for (int i = 0; i < len; i++){
            x = f[i].real + 0.5, y = g[i].real + 0.5, z = f[i].img + 0.5;
            A[i] = (x + ((y % mod) << 15) + ((z % mod) << 30)) % mod;
		}
		return a + b - 1;
	}

    

    


	int long_multiply(int a, long long* A, int b, long long* B){
		int mod1 = 1.5e9;
		int mod2 = mod1 + 1;
		for (int i = 0; i < a; i++) C[i] = A[i];
		for (int i = 0; i < b; i++) D[i] = B[i];

		mod_multiply(a, A, b, B, mod1);
		mod_multiply(a, C, b, D, mod2);
		for (int i = 0; i < len; i++){
            A[i] = A[i] + (C[i] - A[i] + (long long)mod2) * (long long)mod1 % mod2 * mod1;
		}
		return a + b - 1;
	}

	int build_convolution(int n, long long* A, long long* B){
        int i, m, d = 0;
        for (i = 0; i < n; i++) Q[i] = Q[i + n] = B[i];
        for (i = 0; i < n; i++) P[i] = A[i], P[i + n] = 0;
        n *= 2, m = 1 << (32 - __builtin_clz(n) - (__builtin_popcount(n) == 1));
        for (i = n; i < m; i++) P[i] = Q[i] = 0;
        return n;
	}

	

    

	void convolution(int n, long long* A, long long* B){
        int len = build_convolution(n, A, B);
        multiply(len, P, len, Q);
        for (int i = 0; i < n; i++) A[i] = P[i + n];
	}

    

	void mod_convolution(int n, long long* A, long long* B, int mod){
        int len = build_convolution(n, A, B);
        mod_multiply(len, P, len, Q, mod);
        for (int i = 0; i < n; i++) A[i] = P[i + n];
	}

    

    


	void long_convolution(int n, long long* A, long long* B){
        int len = build_convolution(n, A, B);
        long_multiply(len, P, len, Q);
        for (int i = 0; i < n; i++) A[i] = P[i + n];
	}

	

    

    

    

    


	vector <int> hamming_distance(const char* str, const char* pattern){
        int n = strlen(str), m = strlen(pattern);
        for (int i = 0; i < n; i++) P[i] = Q[i] = 0;
        for (int i = 0; i < n; i++) P[i] = str[i] == '1' ? 1 : -1;
        for (int i = 0, j = m - 1; j >= 0; i++, j--) Q[i] = pattern[j] == '1' ? 1 : -1;

        vector <int> res;
        fft::multiply(n, P, m, Q);
        for (int i = 0; (i + m) <= n; i++){
            res.push_back(m - ((P[i + m - 1] + m) >> 1));
        }
        return res;
	}
}

int n,m,k;
char str[MAXN],patt[MAXN];
int lol[MAXN];
long long pa[MAXN],pb[MAXN];
int a,b;

void prework(char c)
{
	mem(lol,0);
	for(int i = 0; i < n; i++)
	{
		if( str[i] == c )
		{
			int l = max( 0 , i - k );
			int r = min( n - 1, i + k );
			lol[r]++;
			lol[l-1]--;
		}
	}
	int tot = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		tot += lol[i];
		if( tot ) pa[i] = +1;
		else pa[i] = 0;
	}
	for(int i = 0; i < m; i++)
	{
		if( patt[i] == c ) pb[i] = +1;
		else pb[i] = 0;
	}
	reverse(pb,pb+m);
	

	

}
int ans[MAXN][4];
char lang[] = {'A','G','C','T'};

int main()
{
	

	int d;
	siii(n,m,k);
	ss(str);
	ss(patt);
	for(int j = 0; j < 4; j++)
	{
		prework(lang[j]);
		d = fft::multiply(n,pa,m,pb);
		for(int i = m - 1; i < n; i++) ans[i][j] = pa[i];
	}
	int ret = 0;
	for(int i = 0; i < n; i++)
	{
		int tot = 0;
		for(int j = 0; j < 4; j++) tot += ans[i][j];
		ret += (tot == m);
	}
	pi(ret); NL;
	return 0;
}
