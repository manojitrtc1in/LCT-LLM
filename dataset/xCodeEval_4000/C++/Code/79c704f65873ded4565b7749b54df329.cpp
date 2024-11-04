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



#define NN 101010



int max_health[NN], start_health[NN], regen[NN];

vector<pii> change[NN];



struct Bigint2 {

	static const int LEN = 4;

	static const int BLEN = 30;

	static const int BIGMOD = 1<<BLEN;

	static const INT BIGMOD1 = 1LL<<(BLEN<<1);

	static const int bmod=BIGMOD-1;

	static const INT bmod1=BIGMOD1-1;



	int s, vl, v[LEN];

	void pb(int x) {v[vl ++] = x;}

	int len() const {return vl;}

	bool empty() const { return len() == 0 ; }

	void pop_back() {vl --;}

	int back() const {return v[vl - 1];}

	void n() {while (!empty() && !back()) pop_back(); if (empty()) s=1;}

	void resize(int nl) {vl = nl;memset(v, 0, sizeof(int) * (nl + 1));}



	Bigint2() : s(1) {vl = 0;}

	Bigint2(long long a) {

		s = 1; vl = 0;

		if (a < 0) {s = -1; a = -a;}

		while (a) {

			pb(a & bmod);

			a >>= BLEN;

		}

		n();

	}



	Bigint2(string str) {

		s = 1; vl = 0;

		int stPos = 0, num = 0;

		if (!str.empty() && str[0] == '-') {

			s = -1; stPos=1;

		}

		vector<int> vp;

		int tmod=(int)1e8;

		for (int i = str.size() - 1, q = 1; i >= stPos; i --) {

			num += (str[i] - '0') * q;

			if ((q*=10) >= tmod) {

				vp.pb(num);

				num = 0; q = 1;

			}

		}

		if (num) vp.pb(num);

		while (!vp.empty()) {

			INT r=0;

			for (int i=vp.size()-1; i>=0; i--) {

				r=r*tmod+vp[i];

				vp[i]=r>>BLEN; r&=bmod;

			}

			while (!vp.empty() && !vp.back()) vp.pop_back();

			pb(r);

		}

		n();

	}



	void print() const {

		if (empty()) {puts("0");return ;}

		int c=back(), la=1;

		printf("%o", c);

		for (int i = len() - 2; i >= 0; i --) printf("%.10o", v[i]); putchar('\n');

	}



	void print10() const {

		if (empty()) {puts("0");return ;}

		VI vp(1, 0), tp;

		if (s==-1) putchar('-');

		int tmod=(int)1e9;

		for (int i=len()-1; i>=0; i--) {

			INT r=0;

			tp=vp; vp.clear(); vp.resize(tp.size(), 0);

			for (int j=0; j<tp.size(); j++) {

				r=(INT)tp[j]*BIGMOD+vp[j];

				vp[j]=r%tmod; r/=tmod;

				for (int k=j+1; r; k++) {

					if (k==vp.size()) vp.pb(0);

					r+=vp[k];

					vp[k]=r%tmod; r/=tmod;

				}

			}

			r=v[i];

			for (int j=0; j<vp.size() && r; j++) {

				r+=vp[j]; vp[j]=r%tmod; r/=tmod;

			}

			if (r) vp.pb(r);

		}

		int c=vp.back();

		printf("%d", c);

		for (int i=vp.size()-2; i>=0; i--) printf("%.9d", vp[i]);puts("");

	}



	int cp3(const Bigint2 &b) const {

		if (s != b.s) return s - b.s;

		if (s == -1) return -(-*this).cp3(-b);

		if (len() != b.len()) return len() - b.len();

		for (int i = len() - 1; i >= 0; i --)

			if (v[i] != b.v[i]) return v[i] - b.v[i];

		return 0;

	}



	bool operator < (const Bigint2 &b) const { return cp3(b) < 0; }

	bool operator <= (const Bigint2 &b) const { return cp3(b) <= 0; }

	bool operator == (const Bigint2 &b) const { return cp3(b) == 0; }

	bool operator != (const Bigint2 &b) const { return cp3(b) != 0; }

	bool operator > (const Bigint2 &b) const { return cp3(b) > 0; }

	bool operator >= (const Bigint2 &b) const { return cp3(b) >= 0; }



	Bigint2 operator - () const {

		Bigint2 r = (*this);

		r.s = -r.s;

		if (r.len()==0) r.s=1;

		return r;

	}



	Bigint2 operator + (const Bigint2 &b) const {

		if (s == -1) return -(-(*this) + (-b));

		if (b.s == -1) return (*this) - (-b);

		Bigint2 r;

		int nl = max(len(), b.len());

		r.resize(nl + 1);

		for (int i = 0; i < nl; i ++) {

			if (i < len()) r.v[i] += v[i];

			if (i < b.len()) r.v[i] += b.v[i];

			if (r.v[i] >= BIGMOD) {

				r.v[i+1]++, r.v[i]&=bmod;

			}

		}

		r.n();

		return r;

	}



	Bigint2 operator - (const Bigint2 &b) const {

		if (s == -1) return -(-(*this) - (-b));

		if (b.s == -1) return (*this) + (-b);

		if ((*this) < b) return -(b - (*this));

		Bigint2 r;

		r.resize(len());

		for (int i = 0; i < len(); i ++) {

			r.v[i] += v[i];

			if (i < b.len()) r.v[i] -= b.v[i];

			if (r.v[i] < 0) {

				r.v[i] += BIGMOD ;

				r.v[i + 1] --;

			}

		}

		r.n();

		return r;

	}



	Bigint2 operator * (const Bigint2 &b) {

		Bigint2 r;

		r.resize(len() + b.len() + 1);

		r.s = s * b.s;

		INT c=0, up=0;

		for (int i=0; i<r.len(); i++) {

			c=up; up=0;

			for (int j=max(0, i-b.len()+1); j<len() && j<=i; j++) {

				c+=(INT)v[j]*b.v[i-j];

				if (c>=BIGMOD1) {

					up+=c>>BLEN; c&=bmod;

				}

			}

			up+=c>>BLEN; c&=bmod;

			r.v[i]=c;

		}

		r.n();

		return r;

	}



	Bigint2 operator / (const Bigint2 &b) {

		if (len()<b.len()) return 0;

		Bigint2 r;

		r.resize(max(1, len() - b.len() + 1));

		int oriS = s;

		Bigint2 b2 = b;

		Bigint2 a2 = *this, a3;

		a2.s = b2.s = r.s = 1;

		for (int i = r.len() - 1; i >= 0; i --) {

			INT d = 0, u = bmod;

			a3=a2>>(i*30);

			if (a3.len()>b2.len()) {

				INT r=((INT)a3.back()<<BLEN)+a3.v[a3.len()-2];

				u=r/b2.back()+1;

			} else if (a3.len()==b2.len() && b2.len()>1) {

				INT r=((INT)a3.back()<<BLEN)+a3.v[a3.len()-2];

				u=r/(((INT)b2.back()<<BLEN)+b2.v[b2.len()-2])+1;

			} else if (a3.len()==b2.len() && b2.len()==1) {

				u=a3.back()/b2.back()+1;

			}

			while (d < u) {

				INT m = (d + u + 1) >> 1;

				r.v[i] = m;

				if (((b2 * m)) > a3) u = m - 1;

				else d = m;

			}

			r.v[i] = d;

			a2=a2-((b2*d)<<i*30);

			a2.n();

		}

		s = oriS;

		r.s = s * b.s;

		r.n();

		return r;

	}



	Bigint2 operator % (const Bigint2 &b) {

		return (*this) - (*this) / b * b;

	}



	int len1() {

		return 32-__builtin_clz(back())+(len()-1)*30;

	}



	Bigint2 operator << (const int &u) {

		if (u==0) return *this;

		Bigint2 r;

		r.resize((len1()+u+29)/30);

		for (int V=u%30, i=r.len()-1, t=u/30; i>=t; i--) {

			r.v[i]=((i-t<len()?(INT)v[i-t]<<V:0)|(i-t?v[i-t-1]>>30-V:0))&bmod;

		}

		r.n();

		return r;

	}



	Bigint2 operator >> (const int &u) {

		int nn=len1();

		if (nn<=u) return 0;

		Bigint2 r; r.resize((nn-u+29)/30);

		for (int V=u%30, c=(1<<V)-1, i=u/30, j=0; j<r.len(); i++, j++) {

			r.v[j]=(v[i]>>V)|(i<len()-1?(v[i+1]&c)<<30-V:0);

		}

		r.n();

		return r;

	}

};



int main() {

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif



	int n, m;

	gn(n, m);

	int bounty, increase, damage;

	gn(bounty, increase, damage);

	for (int i=1; i<=n; i++) gn(max_health[i], start_health[i], regen[i]);

	int Time, enemy, health;

	for (int i=1; i<=n; i++) change[i].pb(pii(0, start_health[i]));

	for (int i=0; i<m; i++) {

		gn(Time, enemy, health);

		change[enemy].pb(pii(Time, health));

	}

	for (int i=1; i<=n; i++) sort(change[i].begin(), change[i].end());

	vector<pii> schedule;

	for (int i=1; i<=n; i++) {

		if (!regen[i]) {

			if (change[i].back().y<=damage) {

				if (increase) return puts("-1"), 0;

				schedule.pb(pii(change[i].back().x, 1));

				schedule.pb(pii((INT)2e9+10, 0));

			}

			for (int j=1; j<change[i].size(); j++) {

				if (change[i][j-1].y<=damage) {

					schedule.pb(pii(change[i][j-1].x, 1));

					schedule.pb(pii(change[i][j].x, -1));

					schedule.pb(pii(change[i][j].x-1, 0));

				}

			}

			continue;

		}

		if (max_health[i]<=damage && increase) return puts("-1"), 0;

		if (max_health[i]<=damage) {

			schedule.pb(pii(0, 1));

			schedule.pb(pii((int)2e9+10, 0));

			continue;

		}

		for (int j=1; j<change[i].size(); j++) {

			pii st=change[i][j-1], ed=change[i][j];

			int T=(max_health[i]-st.y)/regen[i];

			if (ed.x-st.x>T) {

				if (st.y<=damage) {

					schedule.pb(pii(st.x, 1));

					schedule.pb(pii(st.x+(damage-st.y)/regen[i]+1, -1));

					schedule.pb(pii(schedule.back().x-1, 0));

				}

			} else {

				if (st.y<=damage) {

					schedule.pb(pii(st.x, 1));

					schedule.pb(pii(st.x+min((damage-st.y)/regen[i], ed.x-st.x-1)+1, -1));

					schedule.pb(pii(schedule.back().x-1, 0));

				}

			}

		}

		if (change[i].back().y<=damage) {

			schedule.pb(pii(change[i].back().x, 1));

			schedule.pb(pii(change[i].back().x+(damage-change[i].back().y)/regen[i]+1, -1));

			schedule.pb(pii(schedule.back().x-1, 0));

		}

	}

	sort(schedule.begin(), schedule.end());

	int cnt=0;

	if (increase) {

		INT ans1=0, ans2=0;

		for (int i=0, j; i<schedule.size(); i=j) {

			for (j=i; j<schedule.size(); j++)

				if (schedule[i].x!=schedule[j].x) break;

				else cnt+=schedule[j].y;

			if (!cnt) continue;

			INT mid1=(INT)cnt*schedule[i].x+(INT)cnt*bounty/increase;

			INT mid2=(INT)cnt*bounty%increase;

			if (make_pair(ans1, ans2)<=make_pair(mid1, mid2)) ans1=mid1, ans2=mid2;

		}

		Bigint2 ans=Bigint2(ans1)*increase+ans2;

		ans.print10();

	} else {

		INT ans=0;

		for (int i=0, j; i<schedule.size(); i=j) {

			for (j=i; j<schedule.size(); j++)

				if (schedule[i].x!=schedule[j].x) break;

				else cnt+=schedule[j].y;

			smax(ans, cnt);

		}

		println(ans*bounty);

	}



	return 0;

}


                   