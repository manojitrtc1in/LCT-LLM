#include <bits/stdc++.h>



#define inf 0x3f3f3f3f

#define INF 0x3f3f3f3f3f3f3f3fLL

#define MOD 1000000007

#define pb push_back

#define sq(x) ((x)*(x))

#define x first

#define y second

#define eps 1e-8

#define bpt(x) (__builtin_popcount(x))

#define bptl(x) (__builtin_popcountll(x))

#define bit(x, y) (((x)>>(y))&1)

#define bclz(x) (__builtin_clz(x))

#define bclzl(x) (__builtin_clzll(x))

#define bctz(x) (__builtin_ctz(x))

#define bctzl(x) (__builtin_ctzll(x))



using namespace std;

typedef long long INT;

typedef vector<int> VI;

typedef pair<int, int> pii;

typedef pair<pii, int> pi3;

typedef double DO;



template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}



template<typename T> inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}

template<class T, class T1>inline void gn(T &x, T1 &y) {gn(x); gn(y);}

template<class T, class T1, class T2>inline void gn(T &x, T1 &y, T2 &z) {gn(x); gn(y); gn(z);}

template<typename T> inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}

template<typename T> inline void println(T x) {print(x), putchar('\n');}

template<typename T> inline void printsp(T x) {print(x), putchar(' ');}

template<class T, class T1> inline void print(T x, T1 y) {printsp(x), println(y);}

template<class T, class T1, class T2> inline void print(T x, T1 y, T2 z) {printsp(x), printsp(y), println(z);}



int power(int a, int b, int m, int ans=1) {

	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;

	return ans;

}



string v[50][256][3];

int p[50], st[50];

string ans[256];



void update(string &a, string b){

	if(a.length()==0 || a>b) a=b;

}



void update1(string &a, string b){

	if(a.length()==0 || a.length()>b.length() || a.length()==b.length() && a>b) a=b;

}



void pre(){

	v[1][15][2]=string("x");

	v[1][51][2]=string("y");

	v[1][85][2]=string("z");

	

	for(int i=2; i<30; i++){

		for(int k=0; k<256; k++){

			if(v[i-1][k][2].length()) update(v[i][255^k][1], string("!")+v[i-1][k][2]);

		}

		if(i>2){

			for(int k=0; k<256; k++){

				if(v[i-2][k][0].length()) update(v[i][k][2], string("(")+v[i-2][k][0]+string(")"));

				if(v[i-2][k][1].length()) update(v[i][k][2], string("(")+v[i-2][k][1]+string(")"));

			}

		}

		for(int j=1; j<i-1; j++){

			for(int k1=0; k1<256; k1++){

				for(int k2=0; k2<256; k2++){

					if(v[j][k1][0].length() && v[i-j-1][k2][0].length()) update(v[i][k1|k2][0], v[j][k1][0]+string("|")+v[i-j-1][k2][0]);

					if(v[j][k1][0].length() && v[i-j-1][k2][1].length()) update(v[i][k1|k2][0], v[j][k1][0]+string("|")+v[i-j-1][k2][1]);

					if(v[j][k1][0].length() && v[i-j-1][k2][2].length()) update(v[i][k1|k2][0], v[j][k1][0]+string("|")+v[i-j-1][k2][2]);

					if(v[j][k1][1].length() && v[i-j-1][k2][0].length()) update(v[i][k1|k2][0], v[j][k1][1]+string("|")+v[i-j-1][k2][0]);

					if(v[j][k1][1].length() && v[i-j-1][k2][1].length()) update(v[i][k1|k2][0], v[j][k1][1]+string("|")+v[i-j-1][k2][1]);

					if(v[j][k1][1].length() && v[i-j-1][k2][2].length()) update(v[i][k1|k2][0], v[j][k1][1]+string("|")+v[i-j-1][k2][2]);

					if(v[j][k1][2].length() && v[i-j-1][k2][0].length()) update(v[i][k1|k2][0], v[j][k1][2]+string("|")+v[i-j-1][k2][0]);

					if(v[j][k1][2].length() && v[i-j-1][k2][1].length()) update(v[i][k1|k2][0], v[j][k1][2]+string("|")+v[i-j-1][k2][1]);

					if(v[j][k1][2].length() && v[i-j-1][k2][2].length()) update(v[i][k1|k2][0], v[j][k1][2]+string("|")+v[i-j-1][k2][2]);

					

					if(v[j][k1][1].length() && v[i-j-1][k2][1].length()) update(v[i][k1&k2][1], v[j][k1][1]+string("&")+v[i-j-1][k2][1]);

					if(v[j][k1][1].length() && v[i-j-1][k2][2].length()) update(v[i][k1&k2][1], v[j][k1][1]+string("&")+v[i-j-1][k2][2]);

					if(v[j][k1][2].length() && v[i-j-1][k2][1].length()) update(v[i][k1&k2][1], v[j][k1][2]+string("&")+v[i-j-1][k2][1]);

					if(v[j][k1][2].length() && v[i-j-1][k2][2].length()) update(v[i][k1&k2][1], v[j][k1][2]+string("&")+v[i-j-1][k2][2]);

				}

			}

		}

	}

	

	for(int i=30; --i; ){

		for(int k=0; k<256; k++){

			if(v[i][k][0].length()) update1(ans[k], v[i][k][0]);

			if(v[i][k][1].length()) update1(ans[k], v[i][k][1]);

			if(v[i][k][2].length()) update1(ans[k], v[i][k][2]);

		}

	}

	










	puts("char S[256][30]={");

	for(int i=0; i<256; i++) cout << "\"" << ans[i] << (i<255 ? "\"," : "\"\n");

	puts("};");

}



char S[256][30]={

"!x&x","x&y&z","!z&x&y","x&y","!y&x&z","x&z","!y&x&z|!z&x&y","(y|z)&x","!y&!z&x","!y&!z&x|x&y&z","!z&x","!z&x|x&y","!y&x","!y&x|x&z","!(y&z)&x","x","!x&y&z","y&z","!x&y&z|!z&x&y","(x|z)&y","!x&y&z|!y&x&z","(x|y)&z","!x&y&z|!y&x&z|!z&x&y","(x|y)&z|x&y","!x&y&z|!y&!z&x","!y&!z&x|y&z","!x&y&z|!z&x","!z&x|y&z","!x&y&z|!y&x","!y&x|y&z","!(y&z)&x|!x&y&z","x|y&z","!x&!z&y","!x&!z&y|x&y&z","!z&y","!z&y|x&y","!x&!z&y|!y&x&z","!x&!z&y|x&z","!y&x&z|!z&y","!z&y|x&z","!(!x&!y|x&y|z)","!(!x&!y|x&y|z)|x&y&z","!z&(x|y)","!z&(x|y)|x&y","!x&!z&y|!y&x","!x&!z&y|!y&x|x&z","!y&x|!z&y","!z&y|x","!x&y","!x&y|y&z","!(x&z)&y","y","!x&y|!y&x&z","!x&y|x&z","!(x&z)&y|!y&x&z","x&z|y","!x&y|!y&!z&x","!x&y|!y&!z&x|y&z","!x&y|!z&x","!z&x|y","!x&y|!y&x","!x&y|!y&x|x&z","!(x&z)&y|!y&x","x|y","!x&!y&z","!x&!y&z|x&y&z","!x&!y&z|!z&x&y","!x&!y&z|x&y","!y&z","!y&z|x&z","!y&z|!z&x&y","!y&z|x&y","!(!x&!z|x&z|y)","!(!x&!z|x&z|y)|x&y&z","!x&!y&z|!z&x","!x&!y&z|!z&x|x&y","!y&(x|z)","!y&(x|z)|x&z","!y&z|!z&x","!y&z|x","!x&z","!x&z|y&z","!x&z|!z&x&y","!x&z|x&y","!(x&y)&z","z","!(x&y)&z|!z&x&y","x&y|z","!x&z|!y&!z&x","!x&z|!y&!z&x|y&z","!x&z|!z&x","!x&z|!z&x|x&y","!x&z|!y&x","!y&x|z","!(x&y)&z|!z&x","x|z","!(!y&!z|x|y&z)","!(!y&!z|x|y&z)|x&y&z","!x&!y&z|!z&y","!x&!y&z|!z&y|x&y","!x&!z&y|!y&z","!x&!z&y|!y&z|x&z","!y&z|!z&y","!y&z|!z&y|x&y","!(!x&!y|x&y|z)|!x&!y&z","!(!x&!y|x&y|z)|!x&!y&z|x&y&z","!x&!y&z|!z&(x|y)","!x&!y&z|!z&(x|y)|x&y","!x&!z&y|!y&(x|z)","!x&!z&y|!y&(x|z)|x&z","!y&(x|z)|!z&y","!y&z|!z&y|x","!x&(y|z)","!x&(y|z)|y&z","!x&z|!z&y","!x&z|y","!x&y|!y&z","!x&y|z","!(x&y)&z|!z&y","y|z","!x&(y|z)|!y&!z&x","!x&(y|z)|!y&!z&x|y&z","!x&(y|z)|!z&x","!x&z|!z&x|y","!x&(y|z)|!y&x","!x&y|!y&x|z","!x&y|!y&z|!z&x","x|y|z","!(x|y|z)","!(x|y|z)|x&y&z","!(!x&y|!y&x|z)","!(x|y|z)|x&y","!(!x&z|!z&x|y)","!(x|y|z)|x&z","!(!x&y|!y&x|z)|!y&x&z","!(x|y|z)|(y|z)&x","!y&!z","!y&!z|x&y&z","!(!x&y|z)","!y&!z|x&y","!(!x&z|y)","!y&!z|x&z","!(!x&y|z)|!y&x","!y&!z|x","!(!y&z|!z&y|x)","!(x|y|z)|y&z","!(!x&y|!y&x|z)|!x&y&z","!(x|y|z)|(x|z)&y","!(!x&z|!z&x|y)|!x&y&z","!(x|y|z)|(x|y)&z","!(!x&y|!y&x|z)|!x&y&z|!y&x&z","!(x|y|z)|(x|y)&z|x&y","!x&y&z|!y&!z","!y&!z|y&z","!(!x&y|z)|!x&y&z","!(!x&y|z)|y&z","!(!x&z|y)|!x&y&z","!(!x&z|y)|y&z","!(!x&y|z)|!x&y&z|!y&x","!y&!z|x|y&z","!x&!z","!x&!z|x&y&z","!(!y&x|z)","!x&!z|x&y","!x&!z|!y&x&z","!x&!z|x&z","!(!y&x|z)|!y&x&z","!(!y&x|z)|x&z","!(x&y|z)","!(x&y|z)|x&y&z","!z","!z|x&y","!x&!z|!y&x","!(x&y|z)|x&z","!y&x|!z","!z|x","!(!y&z|x)","!x&!z|y&z","!(!y&x|z)|!x&y","!x&!z|y","!(!y&z|x)|!y&x&z","!(!y&z|x)|x&z","!(!y&x|z)|!x&y|!y&x&z","!x&!z|x&z|y","!x&y|!y&!z","!(x&y|z)|y&z","!x&y|!z","!z|y","!(!x&!y&z|x&y)","!x&!z|!y&x|y&z","!x&y|!y&x|!z","!z|x|y","!x&!y","!x&!y|x&y&z","!x&!y|!z&x&y","!x&!y|x&y","!(!z&x|y)","!x&!y|x&z","!(!z&x|y)|!z&x&y","!(!z&x|y)|x&y","!(x&z|y)","!(x&z|y)|x&y&z","!x&!y|!z&x","!(x&z|y)|x&y","!y","!y|x&z","!y|!z&x","!y|x","!(!z&y|x)","!x&!y|y&z","!(!z&y|x)|!z&x&y","!(!z&y|x)|x&y","!(!z&x|y)|!x&z","!x&!y|z","!(!z&x|y)|!x&z|!z&x&y","!x&!y|x&y|z","!x&z|!y&!z","!(x&z|y)|y&z","!(!x&!z&y|x&z)","!x&!y|!z&x|y&z","!x&z|!y","!y|z","!x&z|!y|!z&x","!y|x|z","!(x|y&z)","!(x|y&z)|x&y&z","!x&!y|!z&y","!(x|y&z)|x&y","!x&!z|!y&z","!(x|y&z)|x&z","!(!y&!z&x|y&z)","!x&!y|!z&y|x&z","!((x|y)&z|x&y)","!((x|y)&z|x&y)|x&y&z","!x&!y|!z","!x&!y|!z|x&y","!x&!z|!y","!x&!z|!y|x&z","!y|!z","!y|!z|x","!x","!x|y&z","!x|!z&y","!x|y","!x|!y&z","!x|z","!x|!y&z|!z&y","!x|y|z","!x|!y&!z","!x|!y&!z|y&z","!x|!z","!x|!z|y","!x|!y","!x|!y|z","!(x&y&z)","!x|x"

};



int main() {

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

	










	

	int n;

	gn(n);

	while(n--){

		int x=0, y;

		for(int i=0; i<8; i++){

			scanf("%1d", &y);

			x<<=1;

			x+=y;

		}

		cout << S[x] << endl;

	}

	

	return 0;

}


         