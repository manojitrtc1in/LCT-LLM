
















using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;





  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {

~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}

sim dor(const c&) { ris; }

};




using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;
const ll mod=998244353;

int n;

int tab[nax];

vi wek;

int k;
int jed[nax];

void ans(ll v)
{
	v%=mod;
	v+=mod;
	v%=mod;
	printf("%lld\n", v);
	exit(0);
}

ll inv(ll v)
{
	if (v<=1)
		return v;
	return inv(mod%v)*(mod-mod/v)%mod;
}

ll sil[nax];
ll odw[nax];

ll kom(int a, int b)
{
	if (b>a || b<0)
		return 0;
	return sil[a]*odw[b]%mod*odw[a-b]%mod;
}

ll pot(ll a, ll b)
{
	ll ret=1;
	while(b)
	{
		if (b&1)
			ret=(ret*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret;
}

vector<pii> rozne;



typedef double ld; 

struct C { ld re, im;
	C operator * (const C & he) const {
		return C{re * he.re - im * he.im,
				re * he.im + im * he.re};
	}
	void operator += (const C & he) { re += he.re; im += he.im; }
};
void dft(vector<C> & a, bool rev) {
	const int n = a.size();
	for(int i = 1, k = 0; i < n; ++i) {
		for(int bit = n / 2; (k ^= bit) < bit; bit /= 2);;;
		if(i < k) swap(a[i], a[k]);
	}
	for(int len = 1, who = 0; len < n; len *= 2, ++who) {
		static vector<C> t[30];
		vector<C> & om = t[who];
		if(om.empty()) {
			om.resize(len);
			const ld ang = 2 * acosl(0) / len;
			REP(i, len) om[i] = i%2 || !who ?
					C{cos(i*ang), sin(i*ang)} : t[who-1][i/2];
		}
		for(int i = 0; i < n; i += 2 * len)
			REP(k, len) {
				 const C x = a[i+k], y = a[i+k+len]
						* C{om[k].re, om[k].im * (rev ? -1 : 1)};
				a[i+k] += y;
				a[i+k+len] = C{x.re - y.re, x.im - y.im};
			}
	}
	if(rev) REP(i, n) a[i].re /= n;
}
template<typename T>vector<T> multiply(const vector<T> & a, const vector<T> & b,
		bool split = true, bool normalize = false) {
	if(a.empty() || b.empty()) return {};
	T big = 0; if(normalize) { 

		assert(a.size() == b.size()); 

		for(T x : a) big = max(big, x);
		for(T x : b) big = max(big, x);
		big /= 2;
	}
	int n = a.size() + b.size();
	vector<T> ans(n - 1);
	if(min(a.size(),b.size()) < 190) { 

		REP(i, a.size()) REP(j, b.size()) ans[i+j] = (ans[i+j]+a[i]*b[j])%mod;
		return ans; }
	while(n&(n-1)) ++n;
	auto foo = [&](const vector<C> & w, int i, int k) {
		int j = i ? n - i : 0, r = k ? -1 : 1;
		return C{w[i].re + w[j].re * r, w[i].im
				- w[j].im * r} * (k ? C{0, -0.5} : C{0.5, 0});
	};
	if(!split) { 

		vector<C> in(n), done(n);
		REP(i, a.size()) in[i].re = a[i] - big;
		REP(i, b.size()) in[i].im = b[i] - big;
		dft(in, false);
		REP(i, n) done[i] = foo(in, i, 0) * foo(in, i, 1);
		dft(done, true);
		REP(i, ans.size()) ans[i] = is_integral<T>::value ?
				llround(done[i].re) : done[i].re;
	

	}
	else { 

		const T M = 1<<15; 

		vector<C> t[2]; 

		REP(x, 2) {
			t[x].resize(n);
			auto & in = x ? b : a; 

			REP(i, in.size()) t[x][i]=C{ld(in[i]%M), ld(in[i]/M)};
			dft(t[x], false);
		}
		T mul = 1;
		for(int s = 0; s < 3; ++s, mul = (mul * M)%mod) {
			vector<C> prod(n);
			REP(x, 2) REP(y, 2) if(x + y == s) REP(i, n)
				prod[i] += foo(t[0], i, x) * foo(t[1], i, y);
			dft(prod, true); 

			REP(i, ans.size()) ans[i] = (ans[i] + llround(prod[i].re)%mod*mul)%mod;
		}
	}
	if(normalize) {
		T so_far = 0;
		REP(i, ans.size()) {
			if(i < (int) a.size()) so_far += a[i] + b[i];
			else so_far -= a[i-a.size()] + b[i-a.size()];
			ans[i] += big * so_far - big * big * min(i + 1, (int) ans.size() - i);
		}
	}
	return ans;
}

vll add(const vll &a, const vll &b)
{
	int as=a.size();
	int bs=b.size();
	vll ret(max(as, bs));
	for (int i=0; i<as; i++)
		ret[i]=a[i];
	for (int i=0; i<bs; i++)
		ret[i]=(ret[i]+b[i])%mod;
	return ret;
}

struct opcje
{
	vll kk;
	vll kd;
	vll dd;
	vll wsz()
	{
		vll ret(kk.size());
		for (int i=0; i<(int)ret.size(); i++)
			ret[i]=(kk[i]+kd[i]*2+dd[i])%mod;
		return ret;
	}
	void wypisz()
	{
		debug() << imie(kk) << imie(kd) << imie(dd);
	}
};

vll id0(const vll &x, ll jesli)
{
	int xs=x.size();
	vll ret(xs+1);
	for (int i=0; i<xs; i++)
		ret[i]=x[i];
	for (int i=0; i<xs; i++)
		ret[i+1]=(ret[i+1]+x[i]*jesli)%mod;
	return ret;
}

vll id1(const vll &x, ll a, ll b)
{
	return id0(id0(x, a), b);
}

vll t1[2][2];
vll t2[2][2];

opcje lacz(opcje a, opcje b)
{
	opcje ret;
	t1[0][0]=a.kk;
	t1[0][1]=t1[1][0]=a.kd;
	t1[1][1]=a.dd;
	
	t2[0][0]=b.kk;
	t2[0][1]=t2[1][0]=b.kd;
	t2[1][1]=b.dd;
	

	

	for (int i=0; i<2; i++)
	{
		for (int j=0; j<2; j++)
		{
			for (int l=0; l<2; l++)
			{
				for (int p=i; p<2; p++)
				{
					vll wych=multiply(t1[i][j], t2[l][p]);
					

						

					if (j==l && j==0)
						wych=id0(wych, 2);
					if (j==l && j==1)
						wych=id0(wych, inv(2));
					if (j!=l)
						wych=id0(wych, 1);
					

						

					
					if (i==p && i==0)
						ret.kk=add(ret.kk, wych);
					if (i==p && i==1)
						ret.dd=add(ret.dd, wych);
					if (i!=p)
						ret.kd=add(ret.kd, wych);
				}
			}
		}
	}
	

	return ret;
}

opcje daj(int v)
{
	

	if (v==1)
	{
		opcje ret;
		ret.kk={1};
		ret.kd={0};
		ret.dd={0};
		return ret;
	}
	if (v==2)
	{
		opcje ret;
		ret.kk={1, 0};
		ret.kd={0, 0};
		ret.dd={0, 2};
		return ret;
	}
	if (v==3)
	{
		opcje ret;
		ret.kk={1, 0, 0};
		ret.kd={0, 2, 0};
		ret.dd={0, 0, 2};
		return ret;
	}
	if (!(v&1))
	{
		opcje wez=daj(v/2);
		return lacz(wez, wez);
	}
	return lacz(daj(v-3), daj(3));
}

vll czyt(pii para)
{
	int d=para.first;
	if (para.second==0)

	{
		

		return daj(d).wsz();
	}
	if (para.second==1 || para.second==2)

	{
		if (!d)
			return {1};
		opcje wez=daj(d);
		

		vll ret=add(add(id0(wez.kk, 1), id0(wez.kd, inv(2))), add(id0(wez.kd, 1), id0(wez.dd, inv(2))));
		return ret;
	}
	if (para.second==3)

	{
		if (!d)
			return {1, inv(2)};
		if (d==1)
			return {1, 2, inv(2)};
		opcje wez=daj(d);
		

		vll ret=add(add(id1(wez.kk, 1, 1), id1(wez.kd, inv(2), 1)), add(id1(wez.kd, 1, inv(2)), id1(wez.dd, inv(2), inv(2))));
		return ret;
	}
	assert(0);
}

int main()
{
	scanf("%d", &n);
	sil[0]=1;
	for (int i=1; i<=n; i++)
		sil[i]=(sil[i-1]*i)%mod;
	odw[n]=inv(sil[n]);
	for (int i=n; i; i--)
		odw[i-1]=(odw[i]*i)%mod;
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
		

	{
		int v=1;
		while(v<=n)
		{
			int x=tab[v];
			

			for (int i=0; i<x; i++)
				if (v+i>n || tab[v+i]!=x)
					ans(0);
			v+=x;
			wek.push_back(x);
		}
	}
	

	for (int i : wek)
	{
		k++;
		jed[k]=(i==1);
	}
	

	

	vi pozy;
	for (int i=1; i<=k; i++)
		if (!jed[i])
			pozy.push_back(i);
	if (pozy.empty())
	{
		rozne.push_back({k, 0});
	}
	else
	{
		rozne.push_back({pozy[0]-1, 1});
		for (int i=0; i+1<(int)pozy.size(); i++)
			rozne.push_back({pozy[i+1]-pozy[i]-1, 3});
		rozne.push_back({k-pozy.back(), 1});
	}
	vector<vll> wielo;
	for (pii i : rozne)
		wielo.push_back(czyt(i));
	debug() << wielo;
	priority_queue<pii> kol;
	for (int i=0; i<(int)wielo.size(); i++)
		kol.push({-((int)wielo[i].size()), i});
	while(((int)kol.size())>1)
	{
		int a=kol.top().second;
		kol.pop();
		int b=kol.top().second;
		kol.pop();
		vll nowy=multiply(wielo[a], wielo[b]);
		wielo[a]={};
		wielo[b]=nowy;
		kol.push({-((int)nowy.size()), b});
	}
	vll wez=wielo[kol.top().second];
	int grube=0;
	for (int i=1; i<=k; i++)
		if (!jed[i])
			grube++;
	debug() << grube << " " << k << " " << wez;
	ll mno=pot(2, grube);
	ll wyn=0;
	for (int i=0; i<(int)wez.size(); i++)
	{
		if (!wez[i])
			continue;
		ll tu=1;
		if (i&1)
			tu=mod-1;
		tu=(tu*mno)%mod;
		wyn=(wyn+tu*sil[k-i]%mod*wez[i])%mod;
	}
	printf("%lld\n", wyn);
	return 0;
}
