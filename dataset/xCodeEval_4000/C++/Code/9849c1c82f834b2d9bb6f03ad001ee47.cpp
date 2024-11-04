#include <bits/stdc++.h>



#define inf 0x3f3f3f3f

#define MOD 1000000007

#define pb push_back

#define sq(x) ((x)*(x))

#define x first

#define y second

#define eps 1e-9

#define bpt(x) (__builtin_popcount(x))

#define bptl(x) (__builtin_popcountll(x))

#define bit(x, y) (((x)>>(y))&1)

#define bclz(x) (__builtin_clz(x))

#define bclzl(x) (__builtin_clzll(x))

#define bctz(x) (__builtin_ctz(x))

#define bctzl(x) (__builtin_ctzll(x))

#define sgn(x) (((x)>eps)-((x)<-eps))

#define PQ priority_queue<pii, vector<pii>, greater<pii> >



using namespace std;

typedef long long INT;

typedef vector<int> VI;

typedef pair<int, int> pii;

typedef pair<pii, int> pi3;

typedef double DO;



template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}



template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}

template<class T, class T1>inline void gn(T &x, T1 &y) {gn(x); gn(y);}

template<class T, class T1, class T2>inline void gn(T &x, T1 &y, T2 &z) {gn(x); gn(y); gn(z);}

template<class T>inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}

template<class T>inline void printsp(T x) {print(x); putchar(' ');}

template<class T>inline void println(T x) {print(x); putchar('\n');}

template<class T, class U>inline void print(T x, U y) {printsp(x); println(y);}

template<class T, class U, class V>inline void print(T x, U y, V z) {printsp(x); printsp(y); println(z);}



int power(int a, int b, int m, int ans=1) {

	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;

	return ans;

}



char S[]=" !&()|xyz", s[111];

int can[10][10];

char ss[256][222];

int len[256];



int solve(int st, int ed, int &val) {

	int cnt=0;

	for (int i=ed-1; i>=st; i--) {

		if (s[i]==')') cnt++;

		if (s[i]=='(') cnt--;

		if (cnt==0 && s[i]=='|') return solve(st, i, val)|solve(i+1, ed, val);

	}

	for (int i=ed-1; i>=st; i--) {

		if (s[i]==')') cnt++;

		if (s[i]=='(') cnt--;

		if (cnt==0 && s[i]=='&') return solve(st, i, val)&solve(i+1, ed, val);

	}

	if (s[st]=='!') return !solve(st+1, ed, val);

	if (s[st]=='(') return solve(st+1, ed-1, val);

	if (s[st]=='x') return val>=4;

	if (s[st]=='y') return (val>>1)&1;

	if (s[st]=='z') return val&1;

	assert(0);

}



void update(int u) {

	int v=0;

	s[u]=0;

	for (int i=0; i<8; i++) v+=solve(0, u, i)<<7-i;

	if (!len[v] || len[v]>u) len[v]=u, strcpy(ss[v], s);

}



const int M=17;

void dfs(int u, int cnt=0, int flag=0, int ok=0) {

	if (cnt<0) return ;

	if (cnt+u>=M) return ;

	if (u && cnt==0 && flag && (ok==4 || ok>=6)) update(u);

	for (int i=0; i<u-2; i++) {

		if (s[i]==s[i+2] && (s[i]=='x' || s[i]=='y' || s[i]=='z') && (s[i+1]=='|' || s[i+1]=='&')) return ;

		if (s[i]=='(' && (s[i+1]=='x' || s[i+1]=='y' || s[i+1]=='z') && s[i+2]==')') return ;

	}

	if (u==M) return ;

	for (int i=1; i<=8; i++) if (can[ok][i]) {

		s[u]=S[i];

		dfs(u+1, cnt+(i==3)-(i==4), flag+(i>=6), i);

	}

}



char res[256][111]={"!x&x", "x&y&z", "!z&x&y", "x&y", "!y&x&z", "x&z", "!y&x&z|!z&x&y", "(y|z)&x", "!y&!z&x", "!y&!z&x|x&y&z", "!z&x", "!z&x|x&y", "!y&x", "!y&x|x&z", "!(y&z)&x", "x", "!x&y&z", "y&z", "!x&y&z|!z&x&y", "(x|z)&y", "!x&y&z|!y&x&z", "(x|y)&z", "", "(x|y)&z|x&y", "!x&y&z|!y&!z&x", "!y&!z&x|y&z", "!x&y&z|!z&x", "!z&x|y&z", "!x&y&z|!y&x", "!y&x|y&z", "", "x|y&z", "!x&!z&y", "!x&!z&y|x&y&z", "!z&y", "!z&y|x&y", "!x&!z&y|!y&x&z", "!x&!z&y|x&z", "!y&x&z|!z&y", "!z&y|x&z", "!(!x&!y|x&y|z)", "", "!z&(x|y)", "!z&(x|y)|x&y", "!x&!z&y|!y&x", "", "!y&x|!z&y", "!z&y|x", "!x&y", "!x&y|y&z", "!(x&z)&y", "y", "!x&y|!y&x&z", "!x&y|x&z", "", "x&z|y", "!x&y|!y&!z&x", "", "!x&y|!z&x", "!z&x|y", "!x&y|!y&x", "!x&y|!y&x|x&z", "!(x&z)&y|!y&x", "x|y", "!x&!y&z", "!x&!y&z|x&y&z", "!x&!y&z|!z&x&y", "!x&!y&z|x&y", "!y&z", "!y&z|x&z", "!y&z|!z&x&y", "!y&z|x&y", "!(!x&!z|x&z|y)", "", "!x&!y&z|!z&x", "", "!y&(x|z)", "!y&(x|z)|x&z", "!y&z|!z&x", "!y&z|x", "!x&z", "!x&z|y&z", "!x&z|!z&x&y", "!x&z|x&y", "!(x&y)&z", "z", "", "x&y|z", "!x&z|!y&!z&x", "", "!x&z|!z&x", "!x&z|!z&x|x&y", "!x&z|!y&x", "!y&x|z", "!(x&y)&z|!z&x", "x|z", "!(!y&!z|x|y&z)", "", "!x&!y&z|!z&y", "", "!x&!z&y|!y&z", "", "!y&z|!z&y", "!y&z|!z&y|x&y", "", "", "", "", "", "", "!y&(x|z)|!z&y", "!y&z|!z&y|x", "!x&(y|z)", "!x&(y|z)|y&z", "!x&z|!z&y", "!x&z|y", "!x&y|!y&z", "!x&y|z", "!(x&y)&z|!z&y", "y|z", "", "", "!x&(y|z)|!z&x", "!x&z|!z&x|y", "!x&(y|z)|!y&x", "!x&y|!y&x|z", "!x&y|!y&z|!z&x", "x|y|z", "!(x|y|z)", "!(x|y|z)|x&y&z", "!(!x&y|!y&x|z)", "!(x|y|z)|x&y", "!(!x&z|!z&x|y)", "!(x|y|z)|x&z", "", "", "!y&!z", "!y&!z|x&y&z", "!(!x&y|z)", "!y&!z|x&y", "!(!x&z|y)", "!y&!z|x&z", "!(!x&y|z)|!y&x", "!y&!z|x", "!(!y&z|!z&y|x)", "!(x|y|z)|y&z", "", "", "", "", "", "", "!x&y&z|!y&!z", "!y&!z|y&z", "", "!(!x&y|z)|y&z", "", "!(!x&z|y)|y&z", "", "!y&!z|x|y&z", "!x&!z", "!x&!z|x&y&z", "!(!y&x|z)", "!x&!z|x&y", "!x&!z|!y&x&z", "!x&!z|x&z", "", "!(!y&x|z)|x&z", "!(x&y|z)", "!(x&y|z)|x&y&z", "!z", "!z|x&y", "!x&!z|!y&x", "!(x&y|z)|x&z", "!y&x|!z", "!z|x", "!(!y&z|x)", "!x&!z|y&z", "!(!y&x|z)|!x&y", "!x&!z|y", "", "!(!y&z|x)|x&z", "", "!x&!z|x&z|y", "!x&y|!y&!z", "!(x&y|z)|y&z", "!x&y|!z", "!z|y", "!(!x&!y&z|x&y)", "!x&!z|!y&x|y&z", "!x&y|!y&x|!z", "!z|x|y", "!x&!y", "!x&!y|x&y&z", "!x&!y|!z&x&y", "!x&!y|x&y", "!(!z&x|y)", "!x&!y|x&z", "", "!(!z&x|y)|x&y", "!(x&z|y)", "!(x&z|y)|x&y&z", "!x&!y|!z&x", "!(x&z|y)|x&y", "!y", "!y|x&z", "!y|!z&x", "!y|x", "!(!z&y|x)", "!x&!y|y&z", "", "!(!z&y|x)|x&y", "!(!z&x|y)|!x&z", "!x&!y|z", "", "!x&!y|x&y|z", "!x&z|!y&!z", "!(x&z|y)|y&z", "!(!x&!z&y|x&z)", "!x&!y|!z&x|y&z", "!x&z|!y", "!y|z", "!x&z|!y|!z&x", "!y|x|z", "!(x|y&z)", "!(x|y&z)|x&y&z", "!x&!y|!z&y", "!(x|y&z)|x&y", "!x&!z|!y&z", "!(x|y&z)|x&z", "!(!y&!z&x|y&z)", "!x&!y|!z&y|x&z", "!((x|y)&z|x&y)", "", "!x&!y|!z", "!x&!y|!z|x&y", "!x&!z|!y", "!x&!z|!y|x&z", "!y|!z", "!y|!z|x", "!x", "!x|y&z", "!x|!z&y", "!x|y", "!x|!y&z", "!x|z", "!x|!y&z|!z&y", "!x|y|z", "!x|!y&!z", "!x|!y&!z|y&z", "!x|!z", "!x|!z|y", "!x|!y", "!x|!y|z", "!(x&y&z)", "!x|x"};

int vst[256], vst1[256];



int main() {

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out1.out", "w", stdout);

#endif



	for (int i=1; i<=8; i++) can[0][i]=1;

	can[0][2]=can[0][5]=0;

	can[1][3]=can[1][6]=can[1][7]=can[1][8]=1;

	can[2][3]=can[2][6]=can[2][7]=can[2][8]=1;

	can[3][6]=can[3][7]=can[3][8]=1;

	can[4][2]=can[4][4]=can[4][5]=1;

	can[5][1]=can[5][3]=can[5][6]=can[5][7]=can[5][8]=1;

	for (int i=6; i<=8; i++) can[i][2]=can[i][4]=can[i][5]=1;






#define NN 256

	for (int i=0; i<NN; i++) len[i]=strlen(res[i]);

	for (int i=0; i<NN; i++) if (len[i]) {

		int cnt=0, cc=0;

		for (int j=0; j<len[i]; j++) {

			if (res[i][j]==')') cnt--;

			if (res[i][j]=='(') cnt++;

			if (cnt==0 && res[i][j]=='|') cnt=1;

			if (cnt==0 && res[i][j]=='&') cc=1;

		}

		vst[i]=cnt; vst1[i]=cc;

	}

	for (int i=0; i<NN; i++) if (!len[i]) {

		len[i]=NN;

		for (int j=0; j<NN; j++) if (len[j] && i!=j) {

			if (j+i==255) {

				if (vst[j]+vst1[j]) {

					if (len[i]>len[j]+3) {

						len[i]=len[j]+3;

						res[i][0]='!';

						res[i][1]='(';

						strcpy(res[i]+2, res[j]);

						res[i][len[i]-1]=')';

					} else if (len[i]==len[j]+3) {

						string a=string("!(")+string(res[j])+")";

						smin(a, string(res[j]));

						strcpy(res[j], a.data());

					}

				} else {

					if (len[i]>len[j]+1) {

						len[i]=len[j]+1;

						res[i][0]='!';

						strcpy(res[i]+1, res[j]);

					} else if (len[i]==len[j]+1) {

						string a=string("!")+string(res[j]);

						smin(a, string(res[j]));

						strcpy(res[j], a.data());

					}

				}

				int cnt=0, cc=0;

				for (int jj=0; jj<len[i]; jj++) {

					if (res[i][jj]==')') cnt--;

					if (res[i][jj]=='(') cnt++;

					if (cnt==0 && res[i][jj]=='|') cnt=1;

					if (cnt==0 && res[i][jj]=='&') cc=1;

				}

				vst[i]=cnt; vst1[i]=cc;

			}

			for (int k=0; k<NN; k++) if (len[k] && i!=k && j!=k) {

				if ((j|k)==i) {

					if (len[i]>len[j]+len[k]+1) {

						len[i]=len[j]+len[k]+1;

						string a=string(res[j])+"|"+string(res[k]);

						smin(a, string(res[k])+"|"+string(res[j]));

						strcpy(res[i], a.data());

					} else if (len[i]==len[j]+len[k]+1) {

						string a=string(res[j])+"|"+string(res[k]);

						smin(a, string(res[k])+"|"+string(res[j]));

						smin(a, string(res[i]));

						strcpy(res[i], a.data());

					}

					int cnt=0, cc=0;

					for (int jj=0; jj<len[i]; jj++) {

						if (res[i][jj]==')') cnt--;

						if (res[i][jj]=='(') cnt++;

						if (cnt==0 && res[i][jj]=='|') cnt=1;

						if (cnt==0 && res[i][jj]=='&') cc=1;

					}

					vst[i]=cnt; vst1[i]=cc;

				}

				if ((j&k)==i) {

					if (len[i]>len[j]+len[k]+1+(vst[j]>0)*2+(vst[k]>0)*2) {

						len[i]=len[j]+len[k]+1+(vst[j]>0)*2+(vst[k]>0)*2;

						string a=(vst[j]?"(":"")+string(res[j])+(vst[j]?")":"")+"&"+(vst[k]?"(":"")+string(res[k])+(vst[k]?")":"");

						smin(a, (vst[k]?"(":"")+string(res[k])+(vst[k]?")":"")+"&"+(vst[j]?"(":"")+string(res[j])+(vst[j]?")":""));

						strcpy(res[i], a.data());

					} else if (len[i]==len[j]+len[k]+1+(vst[j]>0)*2+(vst[k]>0)*2) {

						string a=(vst[j]?"(":"")+string(res[j])+(vst[j]?")":"")+"&"+(vst[k]?"(":"")+string(res[k])+(vst[k]?")":"");

						smin(a, (vst[k]?"(":"")+string(res[k])+(vst[k]?")":"")+"&"+(vst[j]?"(":"")+string(res[j])+(vst[j]?")":""));

						smin(a, string(res[i]));

						strcpy(res[i], a.data());

					}

					int cnt=0, cc=0;

					for (int jj=0; jj<len[i]; jj++) {

						if (res[i][jj]==')') cnt--;

						if (res[i][jj]=='(') cnt++;

						if (cnt==0 && res[i][jj]=='|') cnt=1;

						if (cnt==0 && res[i][jj]=='&') cc=1;

					}

					vst[i]=cnt; vst1[i]=cc;

				}

			}

		}




	}

	int n;

	gn(n);

	for (int i=0; i<n; i++) {

		scanf("%s", S);

		int id=0;

		for (int j=0; j<8; j++) id=(id<<1)+S[j]-'0';

		puts(res[id]);

	}



	return 0;

}


                        