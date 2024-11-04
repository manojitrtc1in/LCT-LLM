#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")



#include <ext/pb_ds/assoc_container.hpp> 

#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  




typedef tree<int, null_type, less<int>, rb_tree_tag, 
			 tree_order_statistics_node_update> 
	new_data_set; 
 


typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef std::vector<int> vi;
typedef std::vector<ll> vl;
typedef std::vector<vi> vvi;
typedef std::vector<vl> vvl;
typedef std::pair<int,int> pii;
typedef std::pair<int,ll> pil;
typedef std::pair<ll,int> pli;
typedef std::pair<ll,ll> pll;
typedef std::vector<std::pair<int,int>> vpii;
#define range1(n) for(int (used4range1counter) = 0; (used4range1counter) < (n); (used4range1counter)++)
#define range2(i, n) for(int (i) = 0, used4rangeEndcounter=(n); (i) < used4rangeEndcounter; (i)++)
#define range3(i, b, n) for(int (i) = (b), used4rangeEndcounter = (n); (i) < used4rangeEndcounter; (i)++)
#define range4(i, b, n, d) for(int (i) = (b), used4rangeEndcounter = (n); ((d)>0?(i) < (used4rangeEndcounter):(i)>(used4rangeEndcounter)); (i)+=(d))
#define GET_5TH_ARG(arg1, arg2, arg3, arg4, arg5, ...) arg5
#define RANGE_MACRO_CHOOSER(...) GET_5TH_ARG(__VA_ARGS__, range4, range3, range2, range1)
#define forx(...) RANGE_MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)
#define isz(x) (int)size(x)
#define all(x) std::begin(x), std::end(x)
#define fi first
#define se second
#define debug(x) std::cout << #x << " = " << x << endl
const auto ready = [](){std::ios_base::sync_with_stdio(false);std::cin.tie(0); std::cout.tie(0);
	std::cout << std::fixed << std::setprecision(12);
	return 1;}();
int divCeil(int n, int d) { return d < 0 ? (n + d + 1) / d : (n + d - 1) / d; }
int sgn(int x){return x?x>0?1:-1:0;}
#include <typeinfo> 
class Timer 
{
	std::chrono::time_point<std::chrono::steady_clock> timePoint;
	size_t value;
	public:
		void start() { timePoint = std::chrono::steady_clock::now(); }
		void finish()
		{
			auto curr = std::chrono::steady_clock::now();	
			auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(curr - timePoint);
			value = elapsed.count();
		}
		size_t operator()() const { return value; }
};

class range {
public:
	class iterator {
		public:
			iterator(int ptr=0,int delta=1): ptr(ptr),delta(delta){}
			iterator operator++() { ptr+=delta; return *this; }
			bool operator!=(const iterator & other) const { return ptr != other.ptr; }
			int operator*() const { return ptr; }
		private:
			int ptr,delta;
	};
private:
	int val, len, delta;
public:
	range(int n) : val(0),len(n),delta(1) { }
	range(int a, int b, int d = 1) : val(a), len((abs(b-a)+abs(d)-1)/abs(d)), delta(d) {if ((b-a) * 1LL * d <= 0) val = len = delta = 0;}
	iterator begin() const { return iterator(val,delta); }
	iterator end() const { return iterator(val + len * delta, delta); }
};

class residue
{
public:
	static const int Mod;
	long long val;
	residue(long long Value){val = Value<0?(-Value)%Mod: Value%Mod;if(Value<0)*(this)=*(this)*residue(Mod-1);}
	residue(){val=0;}
	residue operator+(const residue A)const{return residue(val+A.val);}
	residue operator+(residue A){return residue(val+A.val);}
	residue operator-(const residue A)const{return residue(val-A.val);}
	residue operator-(residue A){return residue(val-A.val);}
	residue operator*(const residue A)const{return residue((val*A.val) % Mod);}
	residue operator*(residue A){return residue((val*A.val) % Mod);}
	residue operator/(const residue A)const{return *(this)*(A^-1);}
	residue operator/(residue A){return *(this)*(A^-1);}
	residue operator-(){return residue(val)*residue(-1);}
	residue operator-()const{return residue(val)*residue(-1);}
	residue operator+(ll A){return residue(val+A);}
	residue operator-(ll A){return residue(val-A);}
	residue operator*(ll A){return residue(val*A);}
	residue operator/(ll A){return (residue(A)^(-1))*(*this);}
	residue operator+=(residue A){return val = (*this+A).val,*this;}
	residue operator*=(residue A){return val = (*this*A).val,*this;}
	residue operator-=(residue A){return val = (*this-A).val,*this;}
	residue operator/=(residue A){return val = (*this/A).val,*this;}
	bool operator==(residue A){return val == A.val;}
	const bool operator==(const residue A)const{return val == A.val;}
	residue operator^(int n){return n==-1?(*this)^ui(Mod-2):n<0?(*this^-1)^ui(-n):*this^ui(n);}
	const residue operator^(const int n)const{return n==-1?(*this)^ui(Mod-2):n<0?(*this^-1)^ui(-n):*this^ui(n);}

	residue operator^(ui n){return n?n&1?((*this**this)^(n/2))**this:(*this**this)^(n/2):residue(1);}
	const residue operator^(const ui n)const{return n?n&1?((*this**this)^(n/2))**this:(*this**this)^(n/2):residue(1);}
	residue operator^(ull n){return n?n&1?((*this**this)^(n/2))**this:(*this**this)^(n/2):residue(1);}
	const residue operator^(const ull n) const {return n?n&1?((*this**this)^(n/2))**this:(*this**this)^(n/2):residue(1);}
	
	residue operator^(ll n){return n==-1?(*this)^ull(Mod-2):n<0?(*this^-1)^ull(-n):*this^ull(n);}
	const residue operator^(const ll n) const {return n==-1?(*this)^ull(Mod-2):n<0?(*this^-1)^ull(-n):*this^ull(n);}
	operator int(){return val;}
	operator const int() const{return val;}
	
};
const int residue::Mod = 998244353;
std::vector<residue> fact(2, 1);
std::vector<residue> obrfact(2, 1);
residue residueC(int n, int k)
{
	if(k>n) return 0;
	int i;
	if(fact.size()<=n+1)for(((i = fact.size()), fact.resize(n+1), obrfact.resize(n+1)); i <= n; i++)fact[i] =(fact[i-1]*ll(i)), obrfact[i] = (fact[i]^(-1));
	return fact[n]*obrfact[k]*obrfact[n-k];
}
long long Cnk(int n, int k)
{
	long long Ans = 1;
	for(int i = 0; i < k; i++) Ans = Ans * (n-i)/(i+1);
	return Ans;
}
template<typename T>
class Matrix
{
	public:
		std::vector<std::vector<T>> val;
		Matrix(std::vector<std::vector<T>> &v){val=v;}
		Matrix<T> operator+(Matrix<T>& A)
		{
			std::vector<std::vector<T>> Ans(val.size(), vector<T>(val[0].size()));
			range2(i, val.size())range2(j, val[0].size()) Ans[i][j]=val[i][j]+A.val[i][j];
			return Matrix(A);
		}
		Matrix<T> operator*(Matrix<T>& A)
		{
			vector<vector<T>> Ans(A.val.size(), vector<T>(val.size(), 0));
			range2(i, A.val.size())range2(j, val.size())range2(k, val.size())Ans[i][j]=Ans[i][j]+A.val[i][k]*val[k][j];
			return Matrix(Ans);
		}
		Matrix<T> operator^(long long n) {return n>1?n&1?pow(*this**this, n/2)**this:pow(*this**this, n/2):*this;}
};



namespace SegmentTreeLazy {
	
	
	
	
	template<typename Value, typename Extra> struct TraitsMinAdd;
	template<typename Value, typename Extra> struct TraitsMaxAdd;
	template<typename Value, typename Extra> struct TraitsSumSet;
	
	
	template<typename Value, typename Extra>
	struct TraitsMinAdd {
		

		static Value valueNeutral() { return std::numeric_limits<Value>::max(); }
		

		static Extra extraNeutral() { return Extra(0); }
		

		template<typename Node>
		static Value getValue(const Node& src) {
			return src.value() + src.extra();
		}
		

		template<typename NodeRoot, typename NodeLt, typename NodeRt>
		static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
			root.value() = std::min(getValue(lt), getValue(rt));
		}
		

		template<typename NodeDst, typename NodeSrc>
		static void push(NodeDst dst, const NodeSrc& src) {
			dst.extra() += src.extra();
		}
	};
	
	
	template<typename Value = int64_t, typename Extra = int64_t, typename Traits = TraitsMinAdd<Value, Extra> >
	struct SegmentTree {
		
		
		struct Node {
			Value value;
			
			Extra extra;
			
			Node(Value value_ = Traits::valueNeutral(), Extra extra_ = Traits::extraNeutral())
				: value(value_), extra(extra_) { }
			
			Value getValue(int l, int r) const { return Traits::getValue(NodeWrapper<Node>(l, r, *this)); }
		};
		
		
		template<typename NodeType>
		struct NodeWrapper {
			int l, r;
			NodeType node;
			NodeWrapper(int l_, int r_, NodeType node_)
				: l(l_), r(r_), node(node_) { }
			int  left() const { return l; }
			int right() const { return r; }
			int   mid() const { return (l+r)/2; }
			int   len() const { return r - l + 1; }
			Value& value() { return node.value; }
			Extra& extra() { return node.extra; }
			const Value& value() const { return node.value; }
			const Extra& extra() const { return node.extra; }
		};
		
		
		int n; std::vector<Node> data;
		
		
		
		void resize(int n_) {
			n = n_;
			data.assign(2 * n - 1, Node());
		}
		
		
		void push(int v, int l, int r, int m) {
			if (data[v].extra != Traits::extraNeutral()) {
				Traits::push(
					NodeWrapper<Node&>(l, m, data[v+1]), 
					NodeWrapper<const Node&>(l, r, data[v])
				);
				Traits::push(
					NodeWrapper<Node&>(m+1, r, data[v+2*(m-l+1)]), 
					NodeWrapper<const Node&>(  l, r, data[v])
				);
				data[v].extra = Traits::extraNeutral();
			}
		}
		
		
		void pull(int v, int l, int r, int m) {
			assert(data[v].extra == Traits::extraNeutral());
			Traits::pull(
				NodeWrapper<Node&>(  l, r, data[v]), 
				NodeWrapper<const Node&>(  l, m, data[v+1]), 
				NodeWrapper<const Node&>(m+1, r, data[v+2*(m-l+1)])
			);
		}
		
		
		template<typename T>
		void build(const std::vector<T>& arr, const int v, const int tl, const int tr) {
			if (tl == tr) {
				data[v] = Node(arr[tl]);
			} else {
				const int tm = (tl + tr) / 2;
				build(arr, v+1,   tl, tm);
				build(arr, v+2*(tm-tl+1), tm+1, tr);
				pull(v, tl, tr, tm);
			}
		}
		
		template<typename T>
		void build(const std::vector<T>& arr) { 
			resize((int)arr.size());
			build(arr, 0, 0, n-1);
		}

		
		Node get(int ql, int qr, const int v, const int tl, const int tr) {
			if (ql == tl && qr == tr) {
				return data[v];
			} else {
				int tm = (tl + tr) / 2;
				push(v, tl, tr, tm);
				Node ret;
				if (qr <= tm) {
					ret = get(ql, qr, v+1,   tl, tm);
				} else if (ql > tm) {
					ret = get(ql, qr, v+2*(tm-tl+1), tm+1, tr);
				} else {
					const auto lt = get(  ql, tm, v+1,   tl, tm);
					const auto rt = get(tm+1, qr, v+2*(tm-tl+1), tm+1, tr);
					Traits::pull(
						NodeWrapper<Node&>(  ql, qr, ret), 
						NodeWrapper<const Node&>(  ql, tm, lt), 
						NodeWrapper<const Node&>(tm+1, qr, rt)
					);
				}
				pull(v, tl, tr, tm);
				return ret;
			}
		}
		
		Value get(const int ql, const int qr) { return get(ql, qr, 0, 0, n-1).getValue(ql, qr); }
		
		
		void update(const int ql, const int qr, const Extra& extra, const int v, const int tl, const int tr) {
			if (ql == tl && tr == qr) {
				Traits::push(
					NodeWrapper<Node&>(tl, tr, data[v]),
					NodeWrapper<Node>(ql, qr, Node(Traits::valueNeutral(), extra))
				);
			} else {
				int tm = (tl + tr) / 2;
				push(v, tl, tr, tm);
				if (qr <= tm) {
					update(ql, qr, extra, v+1, tl, tm);
				} else if (ql > tm) {
					update(ql, qr, extra, v+2*(tm-tl+1),tm+1,tr);
				} else {
					update(ql, tm, extra, v+1,   tl, tm);
					update(tm+1, qr, extra, v+2*(tm-tl+1), tm+1, tr);
				}
				pull(v, tl, tr, tm);
			}
		}

		void update(const int ql, const int qr, const Extra& extra) {
			update(ql, qr, extra, 0, 0, n-1); 
		}

	};
	
	
	template<typename Value, typename Extra>
	struct TraitsMaxAdd {
		

		static Value valueNeutral() { return std::numeric_limits<Value>::min(); }
		

		static Extra extraNeutral() { return Extra(0); }
		

		template<typename Node>
		static Value getValue(const Node& src) {
			return src.value() + src.extra();
		}
		

		template<typename NodeRoot, typename NodeLt, typename NodeRt>
		static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
			root.value() = std::max(getValue(lt), getValue(rt));
		}
		

		template<typename NodeDst, typename NodeSrc>
		static void push(NodeDst dst, const NodeSrc& src) {
			dst.extra() += src.extra();
		}
	};   
	
	
	template<typename Value, typename Extra>
	struct TraitsSumSet {
		

		static Value valueNeutral() { return Value(0); }
		

		static Extra extraNeutral() { return Extra(-1); }
		

		template<typename Node>
		static Value getValue(const Node& src) {
			return src.extra() == extraNeutral() ? src.value() : src.len() * src.extra();
		}
		

		template<typename NodeRoot, typename NodeLt, typename NodeRt>
		static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
			root.value() = getValue(lt) + getValue(rt);
		}
		

		template<typename NodeDst, typename NodeSrc>
		static void push(NodeDst dst, const NodeSrc& src) {
			dst.extra() = src.extra();
		}
	};
}




template<typename T>
T input(T& a, std::istream& is = cin)
{
	is >> a;
	return a;
}
template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec)
{
	for (auto &it : vec) is >> it;
	return is;
}
template<typename T1, typename T2>
std::istream& operator>>(std::istream& is, std::pair<T1, T2>& p) {return is >> p.fi >> p.se;}
std::istream& operator>>(std::istream& is,  residue& A) {return is >> A.val;}
template<typename T> queue<T>& operator<<(queue<T>& q, T& x) {q.push(x); return q;}
template<typename T> queue<T>& operator>>(queue<T>& q, T& x) {x = q.front();q.pop(); return q;}



template<typename T> void print(const std::set<T>& S, std::ostream& os=cout, string sep = ", ")
{
	os << "{";
	for (T el:S) os << el << sep;
	os << "}\n";
}
template<typename T> void print(const std::multiset<T>& S, std::ostream& os=cout, string sep = ", ")
{
	os << "{";
	for (T el:S) os << el << sep;
	os << "}\n";
}
template<typename T> void print(const T& t, std::ostream& os=cout)
{
	os << t;
}
template<typename T> void print(const std::vector<T>& vec, std::ostream& os=cout, string sep = ", ")
{
	print("[");
	for (int i = 0; i < vec.size() - 1; i++) print(vec[i]), print(sep);
	print(vec.back());
	print("]\n");
}
template<typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
	forx(i, vec.size()) os << vec[i] << " ";
	return os << "\n";
}
template<typename T> std::ostream& operator<<(std::ostream& os, const std::set<T>& S)
{
	for (T el:S) os << el << " ";
	return os << "\n";
}
template<typename T> std::ostream& operator<<(std::ostream& os, const std::multiset<T>& S)
{
	for (T el:S) os << el << " ";
	return os << "\n";
}
std::ostream& operator<<(std::ostream& os, const residue a) {return os << a.val;}
template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T> a) {return os << a.val;}
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T1, typename T2, typename T3> 
std::ostream& operator<<(ostream& os,const std::tuple<T1,T2,T3>& p){return os<<"("<<p.first<<", "<<p.second<<", "<<p.third<<")";}


template<typename T> void operator+=(std::vector<T>& vec, T el) {vec.push_back(el);}
template<typename T> vector<T> operator+(std::vector<T> A, std::vector<T> B) {for(T el:B)A+=el; return A;}
template<typename T> vector<T> operator+(std::vector<T> A, T a) {return A+=a, A;}
template<typename T> void operator+=(std::set<T>& S, T el) {S.insert(el);}
template<typename T> void operator+=(std::multiset<T>& S, T el) {S.insert(el);}
template<typename T> void operator-=(std::set<T>& S, T el) {S.erase(el);}
template<typename T> void operator-=(std::multiset<T>& S, T el) {S.erase(el);}
template<typename T>
void sort(std::vector<T> &v){sort(v.begin(), v.end());}
template<typename T1, typename T2> std::pair<T1, T2> operator+(const pair<T1, T2>& p1, const pair<T1, T2>& p2) 
{return pair<T1, T2>(p1.fi+p2.fi,p1.se+p2.se);}
template<typename T1, typename T2, typename T3> std::pair<T1, T2> operator*(const pair<T1, T2>& p1, const T3 m) {return pair<T1, T2>(p1.fi*m,p1.se*m);}


long long gcd(long long x, long long y){return y?gcd(y, x % y):abs(x);}
long long euler(long long n)

{
	long long ans = n;
	for(int i = 2, t = sqrt(n); i<=t; i++)
	{
		if(n % i == 0) ans = (ans)/i*(i-1);
		while (n % i == 0) n/=i;
	}
	return (n-1)?(ans)/n*(n-1):ans;
}
vpii factorization(long long n)

{
	vector<pair<int, int>> Ans;
	for(int i = 2, t = sqrt(n); i <= t; i++)
	{
		if(n % i == 0) Ans.push_back(pair<int, int>(i, 0));
		while(n % i == 0) n /= i, Ans.back().second++;
	}
	return (n-1)?Ans+pair<int, int>(n, 1):Ans;
}
ll div2(ll p, ll q)
{
	return (p+q-1)/q;
}
bool IsPrime(ll a)
{
	for(ll i = 2; i*i<=a; i++) if(a%i==0) return false;
	return true;
}
vi divisors(int n)
{
	auto F = factorization(n);
	int size = 1;
	for(auto el:F)size*=el.se+1;
	vi Ans(size, 1);
	for(int i = 0; i < size; i++)
	{
		int i1=i;
		for(int j = 0; j < F.size(); j++)((Ans[i]*=std::pow(F[j].fi, i1%(F[j].se+1)))), i1/=F[j].se+1;
	}
	return Ans;
}
ll sgn(ll a)
{
	if(a==0) return 0;
	if(a<0) return -1;
	return 1;
}
ll MyPow(ll a, ll n)
{
	if(n==0) return 1;
	if(n%2==1||n==2) return MyPow(a, n-1) * a;
	return MyPow(MyPow(a, n/2), 2);
}
int main()
{
	int loops = 1;
	cin >> loops;
	while(loops--)
	{
		ll n, sum=0, s, a, m, k, b, c, d, l, r, p, u, v, q, x, y, z, Max=-1e17, h, w, Min=1e17;
		cin >> n >> m;
		std::vector<string> S(n);
		cin >> S;
		std::vector<std::vector<char>> M(n, std::vector<char>(m));
		std::vector<std::vector<ll>> Price(n, std::vector<ll>(m,-1));
		forx(i, n) forx(j, m) M[i][j]=S[i][j];
		forx(i, n) forx(j, m) if(M[i][j]=='#')
		{
			if(i>0) Price[i-1][j]=-2;
			if(i<n-1) Price[i+1][j]=-2;
			if(j>0) Price[i][j-1]=-2;
			if(j<m-1) Price[i][j+1]=-2;
			
		}
		set<pair<ll, pll>> Queue;
		forx(i, n) if(Price[i][0]!=-2)
		{
			if(M[i][0]=='#') Price[i][0]=1;
			else Price[i][0]=1000000;
			Queue.insert(pair<ll, pll>(Price[i][0], pll(i, 0)));
		}
		auto beg=Queue.begin();
		while(!Queue.empty())
		{
			beg=Queue.begin();
			x = beg->se.fi;
			y = beg->se.se;
			Queue.erase(beg);
			if(x>0&&y>0&&Price[x-1][y-1]==-1)
			{
				Price[x-1][y-1]=Price[x][y]+(M[x-1][y-1]=='#'?0:1000000)+1;
				Queue.insert(pair<ll, pll>(Price[x-1][y-1], pll(x-1, y-1)));
			}
			if(x>0&&y<m-1&&Price[x-1][y+1]==-1)
			{
				Price[x-1][y+1]=Price[x][y]+(M[x-1][y+1]=='#'?0:1000000)+1;
				Queue.insert(pair<ll, pll>(Price[x-1][y+1], pll(x-1, y+1)));
			}
			if(x<n-1&&y>0&&Price[x+1][y-1]==-1)
			{
				Price[x+1][y-1]=Price[x][y]+(M[x+1][y-1]=='#'?0:1000000)+1;
				Queue.insert(pair<ll, pll>(Price[x+1][y-1], pll(x+1, y-1)));
			}
			if(x<n-1&&y<m-1&&Price[x+1][y+1]==-1)
			{
				Price[x+1][y+1]=Price[x][y]+(M[x+1][y+1]=='#'?0:1000000)+1;
				Queue.insert(pair<ll, pll>(Price[x+1][y+1], pll(x+1, y+1)));
			}
		}
		x=0;y=m-1;
		forx(i, n) if(Price[i][m-1]>=0&&(Price[x][y]<0||Price[i][m-1]<Price[x][y]))
		{
			x=i;
			y=m-1;
		}
		if(Price[x][y]<0) cout << "NO\n";
		else
		{
			cout << "YES\n";
			while(y)
			{
				S[x][y]='#';
				if(x>0&&y>0&&Price[x-1][y-1]==Price[x][y]-(M[x][y]=='#'?0:1000000)-1)
				{
					x--;
					y--;
				}
				else if(x>0&&y<m-1&&Price[x-1][y+1]==Price[x][y]-(M[x][y]=='#'?0:1000000)-1)
				{
					x--;
					y++;
				}
				else if(x<n-1&&y>0&&Price[x+1][y-1]==Price[x][y]-(M[x][y]=='#'?0:1000000)-1)
				{
					x++;
					y--;
				}
				else if(x<n-1&&y<m-1&&Price[x+1][y+1]==Price[x][y]-(M[x][y]=='#'?0:1000000)-1)
				{
					x++;
					y++;
				}
			}
			S[x][y]='#';
			forx(i, n) cout << S[i] << "\n";
		}
	}
	return 0;
}