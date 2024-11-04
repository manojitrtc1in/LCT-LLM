
using namespace std;






























template<typename H,typename T,typename N>bool diff(const H &h,const T& t,const N&n){return h!=t&&h!=n&&t!= n;}
template<typename H,typename T,typename N,typename S>bool diff(const H &h,const T &t,const N &n,const S &s)
	{return h!=t&&h!=n&&h!=s&&t!=n&&t!=s&&n!=s;}
template<typename H,typename T,typename N>bool in(const H &h,const T& t,const N& n) {return h==t||h==n;}
template<typename H,typename T,typename N,typename S> bool in(const H &h,const T &t,const N &n,const S &s) {return h==t||h==n||h==s;}








template <typename T, typename U> auto my_min(const T & x, const U & y) -> decltype(true?x:y) {if (x < y) return x; return y;}
template <typename T, typename U> auto my_max(const T & x, const U & y) -> decltype(true?x:y) {if (x > y) return x; return y;}

	decltype(true?a:(true?b:c)) {return my_
	template <typename T, typename U> U & _
	template <typename T, typename U, typename V, typename W> auto my_
	->decltype(true?a:(true?b:(true?c:d))){return my_
make_mins(min) make_mins(max)
template <typename T, typename U, typename V> auto med(const T& a, const U& b, const V& c) -> decltype(true?a:(true?b:c))
	{return my_min(my_max(a, b), my_max(my_min(a, b), c));}






const bool deb = 

true;


false;





int CON_BOUND = 10;
template <typename T, typename C>ostream & operator<<(ostream &os, pair<T, C> x) {return os << "<" << x.f << ", " << x.s << ">";}
template <typename T> auto operator<<(ostream&os,T x)->typename enable_if<is_same<decltype(x.begin()),decltype(x.end())>::value&&
	!is_same<T, string>::value, ostream &>::type{os << "{";int cou=0;for(auto c:x){if(cou++)os<<", ";os<<c;
	if(cou==CON_BOUND&&siz(x)>CON_BOUND+2){os<<" ... "<<*--x.end();break;}}return os << "}_" << x.size();}
























	<< 





	

	

	





	-> pair <decltype(x.f op y.f), decltype(x.s op y.s)> {return MP(x.f op y.f, x.s op y.s);} \
template <typename A, typename B, typename C> auto operator op (pair <A, B> x, C y) \
	-> pair <decltype(x.f op y), decltype(x.s op y)> {return MP(x.f op y, x.s op y);} \
template <typename A, typename C, typename D> auto operator op (A x, pair <C, D> y) \
	-> pair <decltype(x op y.f), decltype(x op y.s)> {return MP(x op y.f, x op y.s);}

	x.f op y.f; x.s op y.s; return x;} \
template <typename A, typename B, typename C> pair <A, B> & operator op(pair <A, B> &x, C y) {x.f op y; x.s op y; return x;}

	template <typename A, typename B> pair <A, B> operator op(pair <A, B> &x, int _){return MP(x.f op, x.s op);}

	{return MP(fs(op x));}
make_op(+) make_op(-) make_op(/) make_op(*) make_op(%) make_op(&) make_op(|) make_op(^) make_op(&&) make_op(||)
make_op2(+=) make_op2(-=) make_op2(*=) make_op2(/=) make_op2(%=) make_op2(^=) make_op2(&=) make_op2(|=)
make_op3(++) make_op3(--)
make_op4(*) make_op4(~) make_op4(!) make_op4(-) make_op4(&)
template <typename T>string concat(T x) {stringstream os;os << x;return os.str();}
template <typename T, typename ...U>string concat(T x, U... y) {stringstream os;os << x << ", ";return os.str() + concat(y...);}

template<typename T>string strmask(T r) {string ans;REP(i,8*(int)sizeof(T)){ans+='0'+!!(((T)1<<i)&r);if(i%5==4)ans+='.';}return ans;}

ostream&operator<<(ostream&os, __int128_t x){if (x<0){os<<'-';x=-x;}if(x>=10)os<<x/10;return os<<(int)(x%10);}
ostream&operator<< (ostream & os, __uint128_t x){if(x>=10)os<<x/10;return os<<(int)(x%10);}


const int MN = 1e5 + 44;
VI obj[4];
LL best[MN * 3];
LL inf = 1e18;
int main() {
	debug << name(MN) << "MAKE SURE IT IS RIGHT!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, n) {
		int w, c;
		scanf("%d%d", &w, &c);
		obj[w].PB(c);
	}
	FOR(i, 1, 3) {
		sort(ALL(obj[i]));
		reverse(ALL(obj[i]));
	}
	int s1 = siz(obj[1]), s2 = siz(obj[2]), i = 0, j = 0;
	REP(_, 5)
		FOR(i, 1, 2)
			obj[i].PB(0);
	debug << name(obj[1]) << name(obj[2]) << endl;
	int total = 0;
	LL sum = 0;
	while (i < s1 || j < s2) {
		LL sum1[4], sum2[4];
		LL sub1[4], sub2[4];

		sum1[0] = sum2[0] = sub1[0] = sub2[0] = 0;
		REP(x, 3) {
			sum1[x + 1] = sum1[x] + obj[1][i + x];
			sum2[x + 1] = sum2[x] + obj[2][j + x];
		}
		FOR(x, 1, 3) {
			sub1[x] = sub1[x - 1] - (i - x >= 0 ? obj[1][i - x] : inf);
			sub2[x] = sub2[x - 1] - (j - x >= 0 ? obj[2][j - x] : inf);
		}
		debug << name(i) << name(j) << name(total) << name(sum) << endl;
		debug << range(sum1, 0, 3) << range(sub1, 0, 3) << range(sum2, 0, 3) << range(sub2, 0, 3) << endl;
		FOR(x, -3, 3)
			FOR(y, -3, 3) {
				if (total + x + 2 * y >= 0) {
					maxi(best[total + x + 2 * y], sum + (x > 0 ? sum1[x] : sub1[-x]) + (y > 0 ? sum2[y] : sub2[-y]));
				}
			}
		if (obj[1][i] * 2 > obj[2][j]) {
			sum += obj[1][i];
			i++;
			total++;
		}
		else {
			sum += obj[2][j];
			j++;
			total += 2;
		}
		debug << range(best, 0, m) << endl;
	}
	REP(i, m)
		maxi(best[i + 1], best[i]);
	CON_BOUND = 30;
	debug << name(obj[1]) << name(obj[2]) << endl;
	debug << range(best, 0, m) << endl;
	sum = 0;
	total = 0;
	LL ans = best[m];
	for (int x : obj[3]) {
		total += 3;
		sum += x;
		if (total > m)
			break;
		maxi(ans, best[m - total] + sum);
	}
	printf("%lld\n", ans);
	debug << name(MN) << "MAKE SURE IT IS RIGHT!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}
