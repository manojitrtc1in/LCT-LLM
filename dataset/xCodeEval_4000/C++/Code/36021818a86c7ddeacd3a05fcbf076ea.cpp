

using namespace std;
#include <bits/stdc++.h>
#define ld long double
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#ifdef shivang_ka_laptop
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
	#define booga cerr << "booga" << endl;
#else
	#define debug(...) 42;
	#define booga 9;
#endif

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
void safai() { return; }template <typename Head, typename... Tail>void safai(Head &H, Tail & ... T) {H.clear();safai(T...);}

namespace fastIO{ 
	#define BUF_SIZE 100000 
	#define OUT_SIZE 100000 
	#define ll long long 
	

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
		#ifdef _WIN32 
			scanf("%I64d",&x); 
		#else 
		#ifdef __linux 
			scanf("%lld",&x); 
		#else 
			puts("error:can't recognize the system!"); 
		#endif 
		#endif 
	} 
	inline void read2(double &x){scanf("%lf",&x);} 
	inline void read2(char *s){scanf("%s",s);} 
	inline void read2(char &c){scanf(" %c",&c);} 
	

	

	struct Ostream_fwrite{ 
		char *buf,*p1,*pend; 
		Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;} 
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
		~Ostream_fwrite(){flush();} 
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
		#ifdef _WIN32 
			printf("%I64d",x); 
		#else 
		#ifdef __linux 
			printf("%lld",x); 
		#else 
			puts("error:can't recognize the system!"); 
		#endif 
		#endif 
	} 
	inline void println2(ll x){print2(x);printf("\n");} 
	inline void println2(){printf("\n");} 
	#undef ll 
	#undef OUT_SIZE 
	#undef BUF_SIZE 
}; 
using namespace fastIO;

char yes[] = "Yes";
char no[] = "No";
void testcase(){
	int n,c;
	read(n);
	read(c);
	

	vector<int> a(n),got(2*c+1);
	for(int i = 0; i < n; i++){
		read(a[i]);
		

		got[a[i]] = 1;
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(), a.end()), a.end()); 

	n = a.size();
	for(int i = 1; i < (int)got.size(); i++){
		got[i] += got[i-1];
	}
	auto present = [&](int l,int r){
		return got[r] - got[l-1] > 0;
	};
	for(int i = 0; i < n; i++){
		int cnt = 1;
		for(int j = a[i]; j <= a[n-1]; j+= a[i]){
			

			int l = j,r = j + a[i] - 1;
			

			

			if(present(l,r) && !present(cnt,cnt)){
				println(no);
				

				return;
			}
			cnt++;
		}
	}
	println(yes);
	

}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	

	read(tt);
	while(tt--){
		testcase();
	}
	return (0-0);
}

