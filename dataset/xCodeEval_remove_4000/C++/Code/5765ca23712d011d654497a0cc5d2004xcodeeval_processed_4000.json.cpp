

using namespace std;




mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

	
	

	
	


template <typename T> std::ostream& operator<<(std::ostream& stream, const vector<T>& vec){ for(size_t i = 0; i < vec.size(); i++){stream << vec[i];if(i != vec.size() - 1)stream << ' ';}; return stream; }
template <typename T> std::istream& operator>>(std::istream& stream, vector<T>& vec) { for(T &x : vec)stream >> x;return stream; }
template <typename T,typename U> std::ostream& operator<<(std::ostream& stream, const pair<T,U>& pr){ stream << pr.first << ' ' << pr.second; return stream; }
template <typename T,typename U> std::istream& operator>>(std::istream& stream, pair<T,U>& pr){ stream >> pr.first >> pr.second; return stream; }
template <typename T, typename U> void operator+=(vector<T>& vec, const U value) { for(T &x : vec)x += value; }
template <typename T, typename U> void operator-=(vector<T>& vec, const U value) { for(T &x : vec)x -= value; }
template <typename T, typename U> void operator*=(vector<T>& vec, const U value) { for(T &x : vec)x *= value; }
template <typename T, typename U> void operator/=(vector<T>& vec, const U value) { for(T &x : vec)x /= value; }
template <typename T> void operator++(vector<T>& vec) { vec += 1; }
template <typename T> void operator++(vector<T>& vec,int) { vec += 1; }
template <typename T> void operator--(vector<T>& vec) { vec -= 1; }
template <typename T> void operator--(vector<T>& vec,int) { vec -= 1; }
template <typename T,typename U, typename V> void operator+=(pair<T,U>& vec, const V value) { vec.first += value;vec.second += value; }
template <typename T,typename U, typename V> void operator-=(pair<T,U>& vec, const V value) { vec.first -= value;vec.second -= value; }
template <typename T,typename U, typename V> void operator*=(pair<T,U>& vec, const V value) { vec.first *= value;vec.second *= value; }
template <typename T,typename U, typename V> void operator/=(pair<T,U>& vec, const V value) { vec.first /= value;vec.second /= value; }
template <typename T,typename U> void operator++(pair<T,U>& vec) { vec += 1; } 
template <typename T,typename U> void operator++(pair<T,U>& vec,int) { vec += 1; } 
template <typename T,typename U> void operator--(pair<T,U>& vec) { vec -= 1; } 
template <typename T,typename U> void operator--(pair<T,U>& vec,int) { vec -= 1; } 

template <typename A, typename B>string to_string(pair<A, B> p);
template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(char c) {string s;s += c;return s; }
string to_string(const char* s) {return to_string((string) s); }
string to_string(bool b) {return (b ? "1" : "0"); }
string to_string(vector<bool> v) {bool first = true;string res = "{";for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", ";}first = false;res += to_string(v[i]);}res += "}";return res;}
template <size_t N>string to_string(bitset<N> v) {string res = "";for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]);}return res;}
template <typename A>string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void debug_out() { cerr << endl; } template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H);debug_out(T...);}
void bharo(int N_N) { return; }template <typename Head, typename... Tail>void bharo(int N_N, Head &H, Tail & ... T) {H.resize(N_N);bharo(N_N,T...);}
void id1() { return; }template <typename Head, typename... Tail>void id1(Head &H, Tail & ... T) {H.clear();id1(T...);}

template <typename T>
T inverse(T a, T m) {
	T u = 0, v = 1;
	while (a != 0) {
		T t = m / a;
		m -= t * a; swap(a, m);
		u -= t * v; swap(u, v);
	}
	assert(m == 1);
	return u;
}
 
template <typename T>
class Modular {
 public:
	using Type = typename decay<decltype(T::value)>::type;
	constexpr Modular() : value() {}
	template <typename U>
	Modular(const U& x) {
		value = normalize(x);
	}
	template <typename U>
	static Type normalize(const U& x) {
		Type v;
		if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
		else v = static_cast<Type>(x % mod());
		if (v < 0) v += mod();
		return v;
	}
	const Type& operator()() const { return value; }
	template <typename U>
	explicit operator U() const { return static_cast<U>(value); }
	constexpr static Type mod() { return T::value; }
	Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
	Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
	template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
	template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
	Modular& operator++() { return *this += 1; }
	Modular& operator--() { return *this -= 1; }
	Modular operator++(int) { Modular result(*this); *this += 1; return result; }
	Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
	Modular operator-() const { return Modular(-value); }
	template <typename U = T>
	typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {

		uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
		uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
		asm(
			"divl %4; "
			: "=a" (d), "=d" (m)
			: "d" (xh), "a" (xl), "r" (mod())
		);
		value = m;

		value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));

		return *this;
	}
	template <typename U = T>
	typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
		long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template <typename U = T>
	typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
		value = normalize(value * rhs.value);
		return *this;
	}
	Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
	friend const Type& abs(const Modular& x) { return x.value; }
	template <typename U>
	friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
	template <typename U>
	friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
	template <typename V, typename U>
	friend V& operator>>(V& stream, Modular<U>& number);
	private: Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
	assert(b >= 0);
	Modular<T> x = a, res = 1;
	U p = b;
	while (p > 0) {
		if (p & 1) res *= x;
		x *= x;
		p >>= 1;
	}
	return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
	return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
	return to_string(number());
}
 


template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
	return stream << number();
}
 


template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
	typename common_type<typename Modular<T>::Type, long long>::type x;
	stream >> x;
	number.value = Modular<T>::normalize(x);
	return stream;
}
 



 








 


constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

Mint power(int x,const long long int y){
	return power(Mint(x),y);
}

namespace fastIO{ 
	
	
	

	bool IOerror=0; 
	inline char nc(){ 
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE; 
		if (p1==pend){ 
			p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin); 
			if (pend==p1){IOerror=1;return -1;} 
			

		} 
		return *p1++; 
	} 
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';} 
	inline void read(int &x){ 
		bool sign=0; char ch=nc(); x=0; 
		for (;blank(ch);ch=nc()); 
		if (IOerror)return; 
		if (ch=='-')sign=1,ch=nc(); 
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
		if (sign)x=-x; 
	} 
	inline void read(ll &x){ 
		bool sign=0; char ch=nc(); x=0; 
		for (;blank(ch);ch=nc()); 
		if (IOerror)return; 
		if (ch=='-')sign=1,ch=nc(); 
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
		if (sign)x=-x; 
	} 
	inline void read(double &x){ 
		bool sign=0; char ch=nc(); x=0; 
		for (;blank(ch);ch=nc()); 
		if (IOerror)return; 
		if (ch=='-')sign=1,ch=nc(); 
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
		if (ch=='.'){ 
			double tmp=1; ch=nc(); 
			for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0'); 
		} 
		if (sign)x=-x; 
	} 
	inline void read(char *s){ 
		char ch=nc(); 
		for (;blank(ch);ch=nc()); 
		if (IOerror)return; 
		for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch; 
		*s=0; 
	} 
	inline void read(char &c){ 
		for (c=nc();blank(c);c=nc()); 
		if (IOerror){c=-1;return;} 
	} 
	

	inline void read1(int &x){ 
		char ch;int bo=0;x=0; 
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
		if (bo)x=-x; 
	} 
	inline void read1(ll &x){ 
		char ch;int bo=0;x=0; 
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
		if (bo)x=-x; 
	} 
	inline void read1(double &x){ 
		char ch;int bo=0;x=0; 
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
		if (ch=='.'){ 
			double tmp=1; 
			for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar()); 
		} 
		if (bo)x=-x; 
	} 
	inline void read1(char *s){ 
		char ch=getchar(); 
		for (;blank(ch);ch=getchar()); 
		for (;!blank(ch);ch=getchar())*s++=ch; 
		*s=0; 
	} 
	inline void read1(char &c){for (c=getchar();blank(c);c=getchar());} 
	

	inline void read2(int &x){scanf("%d",&x);} 
	inline void read2(ll &x){ 
		
			scanf("%I64d",&x); 
		
		
			scanf("%lld",&x); 
		
			puts("error:can't recognize the system!"); 
		
		
	} 
	inline void read2(double &x){scanf("%lf",&x);} 
	inline void read2(char *s){scanf("%s",s);} 
	inline void read2(char &c){scanf(" %c",&c);} 
	

	

	struct id0{ 
		char *buf,*p1,*pend; 
		id0(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;} 
		void out(char ch){ 
			if (p1==pend){ 
				fwrite(buf,1,BUF_SIZE,stdout);p1=buf; 
			} 
			*p1++=ch; 
		} 
		void print(int x){ 
			static char s[15],*s1;s1=s; 
			if (!x)*s1++='0';
			if (x<0)out('-'),x=-x; 
			while(x)*s1++=x%10+'0',x/=10; 
			while(s1--!=s)out(*s1); 
		} 
		void println(int x){ 
			static char s[15],*s1;s1=s; 
			if (!x)*s1++='0';
			if (x<0)out('-'),x=-x; 
			while(x)*s1++=x%10+'0',x/=10; 
			while(s1--!=s)out(*s1);
			out('\n'); 
		} 
		void print(ll x){ 
			static char s[25],*s1;s1=s; 
			if (!x)*s1++='0';
			if (x<0)out('-'),x=-x; 
			while(x)*s1++=x%10+'0',x/=10; 
			while(s1--!=s)out(*s1); 
		} 
		void println(ll x){ 
			static char s[25],*s1;s1=s; 
			if (!x)*s1++='0';
			if (x<0)out('-'),x=-x; 
			while(x)*s1++=x%10+'0',x/=10; 
			while(s1--!=s)out(*s1); 
			out('\n'); 
		} 
		void print(double x,int y){ 
			static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000, 
				1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL, 
				100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL}; 
			if (x<-1e-12)out('-'),x=-x;
			x*=mul[y]; 
			ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1; 
			ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2); 
			if (y>0){out('.'); for (int i=1;i<y&&x3*mul[i]<mul[y];++i) out('0'); print(x3);} 
		} 
		void println(double x,int y){print(x,y);out('\n');} 
		void print(char *s){while (*s)out(*s++);} 
		void println(char *s){while (*s)out(*s++);out('\n');} 
		void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}} 
		~id0(){flush();} 
	}Ostream; 
	inline void print(int x){Ostream.print(x);} 
	inline void println(int x){Ostream.println(x);} 
	inline void print(char x){Ostream.out(x);} 
	inline void println(char x){Ostream.out(x);Ostream.out('\n');} 
	inline void print(ll x){Ostream.print(x);} 
	inline void println(ll x){Ostream.println(x);} 
	inline void print(double x,int y){Ostream.print(x,y);} 
	inline void println(double x,int y){Ostream.println(x,y);} 
	inline void print(char *s){Ostream.print(s);} 
	inline void println(char *s){Ostream.println(s);} 
	inline void println(){Ostream.out('\n');} 
	inline void flush(){Ostream.flush();} 
	

	char Out[OUT_SIZE],*o=Out; 
	inline void print1(int x){ 
		static char buf[15]; 
		char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x; 
		while(x)*p1++=x%10+'0',x/=10; 
		while(p1--!=buf)*o++=*p1; 
	} 
	inline void println1(int x){print1(x);*o++='\n';} 
	inline void print1(ll x){ 
		static char buf[25]; 
		char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x; 
		while(x)*p1++=x%10+'0',x/=10; 
		while(p1--!=buf)*o++=*p1; 
	} 
	inline void println1(ll x){print1(x);*o++='\n';} 
	inline void print1(char c){*o++=c;} 
	inline void println1(char c){*o++=c;*o++='\n';} 
	inline void print1(char *s){while (*s)*o++=*s++;} 
	inline void println1(char *s){print1(s);*o++='\n';} 
	inline void println1(){*o++='\n';} 
	inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}} 
	struct puts_write{ 
		~puts_write(){flush1();} 
	}_puts; 
	inline void print2(int x){printf("%d",x);} 
	inline void println2(int x){printf("%d\n",x);} 
	inline void print2(char x){printf("%c",x);} 
	inline void println2(char x){printf("%c\n",x);} 
	inline void print2(ll x){ 
		
			printf("%I64d",x); 
		
		
			printf("%lld",x); 
		
			puts("error:can't recognize the system!"); 
		
		
	} 
	inline void println2(ll x){print2(x);printf("\n");} 
	inline void println2(){printf("\n");} 
	
	
}; 
using namespace fastIO;

const int N = 17;



void testcase(){
	int n;
	char s[1005];
	read(n);
	read(s);
	int qu = 0;
	for(int i = 0; i < n; i++){
		qu += s[i] == '?';
	}
	
	vector<vector<Mint>> dp(1 << N,vector<Mint>(N+1));
	for(int mid = 0;mid < n;mid++){
		

		{
			int i = mid,j = mid;
			int mask = 0,cnt = 0,tmp = qu;
			while(i >= 0 && j < n){
				tmp -= s[i] == '?';
				tmp -= i != j && s[j] == '?';
				if(s[i] != s[j]){
					if(s[i] != '?' && s[j] != '?'){
						break;
					}
					mask |= 1 << (s[i] == '?' ? s[j]-'a' : s[i]-'a');
				}
				else if(s[i] == '?'){
					cnt++;
				}
				for(int k = __builtin_popcount(mask); k <= N; k++){
					dp[mask][k] += power(k,cnt) * power(k,tmp);
				}
				i--;
				j++;
			}
		}
		

		{
			int i = mid,j = mid+1;
			int mask = 0,cnt = 0,tmp = qu;
			while(i >= 0 && j < n){
				tmp -= s[i] == '?';
				tmp -= i != j && s[j] == '?';
				if(s[i] != s[j]){
					if(s[i] != '?' && s[j] != '?'){
						break;
					}
					mask |= 1 << (s[i] == '?' ? s[j]-'a' : s[i]-'a');
				}
				else if(s[i] == '?'){
					cnt++;
				}
				for(int k = __builtin_popcount(mask); k <= N; k++){
					dp[mask][k] += power(k,cnt) * power(k,tmp);
				}
				i--;
				j++;
			}
		}
	}
	

		

		

		

		

			

				

					

					

				

				

			

		

		

		

		

			

				

			

		

		

		

			

		

		
		

			

		

	

	

	for(int j = 1; j <= N; j++){
		for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
			if(mask & (1<<i))
				dp[mask][j] += dp[mask^(1<<i)][j];
		}
	}
	int q;
	read(q);
	while(q--){
		char t[20];
		read(t);
		int m = strlen(t);
		
		int mask = 0;
		for(int i = 0; i < m; i++){
			mask |= 1 << (t[i]-'a');
		}
		println(dp[mask][m]());
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	

	while(tt--){
		testcase();
	}
	return (0-0);
}

