


using namespace std;






























template<typename H,typename T,typename N>bool diff(const H &h,const T& t,const N&n){return h!=t&&h!=n&&t!=n;}
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







const bool deb = true;


const bool deb = false;






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
ostream&operator<<(ostream & os, __uint128_t x){if(x>=10)os<<x/10;return os<<(int)(x%10);}


const int inf = 1e9;
const LL llinf = 3e18;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109,
113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431,
433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773,
787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971,
977, 983, 991, 997};
int big_primes[] = {1307533217, 1336158883, 1339172111, 1367797777, 1376837461, 1399436671, 1426555723, 1440115249, 1444635091,
	1489833511, 1553111299, 1562150983, 1587763421, 1610362631, 1652547823, 1666107349, 1700759471, 1782116627, 1797182767, 1810742293,
	1818275363, 1892099449, 1904152361, 1919218501, 1940311097, 1944830939, 1968936763, 1977976447, 1985509517, 1990029359, 
};
int gens[]={1,2,3,5,2,11,3,14,19,11,17,32,30,34,29,19,34,31,63,33,5,63,53,58,40,83,21,18,99,33,106,40,85,109,40,77,91,120,105,91,79,53,
182,10,184,48,48,150,168,72,65,46,31,216,101,134,163,147,93,42,69,7,151,308,112,12,227,185,214,305,163,234,154,316,3,11,233,390,271,173,
82,407,13,135,414,391,177,293,426,432,337,281,385,103,95,152,12,371,390,77,532,34,287,73,308,493,258,549,528,411,12,283,614,596,622,309,
91,511,287,433,585,123,2,170,183,341,459,322,333,337,507,718,82,517,396,315,565,48,362,617,776,425,584,231,578,395,127,27,506,435,727,659,
697,385,290,109,430,422,344,849,513,453,852,920,152,482,653,271};
int big_gens[]={661761153,1315209189,235649158,80905954,861543922,677870461,332266749,1192707557,820697698,93737534,1395132003,176849700,
1113502216,860516128,1543755630,328298286,1219407972,1407392293,733053145,400000570,1081174233,847228024,1516266762,83276926,500618997,
44975430,47827763,1411328206,151880843,19696955};
const int MK = deb ? 4 : 12, MN = 1e5 + 44, MQ = 1e5 + 44;
bitset <1 << MK> creature[MQ];
int input[MK][MN];
int main() {
	debug << name(MN) << "MAKE SURE IT IS RIGHT!!!!!!!!!!!!!!!!!!!!!!!!!!!" << clear;

	int n, k, q;
	scanf("%d%d%d", &n, &k, &q);
	REP(i, k)
		FOR(j, 1, n)
			scanf("%d", &input[i][j]);
	REP(i, k)
		REP(mask, (1 << k))
			if (mask & (1 << i))
				creature[i][mask] = 1;
	REP(i, k)
		debug << arr(creature, i) << clear;
	int first_free = k;
	REP(_, q) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1) {
			creature[first_free++] = creature[x - 1] | creature[y - 1];
			debug << name(t) << arr(creature, first_free - 1) << clear;
		}
		else if (t == 2) {
			creature[first_free++] = creature[x - 1] & creature[y - 1];
			debug << name(t) << arr(creature, first_free - 1) << clear;
		}
		else {
			int ans = 0;
			x--;
			REP(i, k) {
				int mask = 0;
				debug << "try " << arr2(input, i, y) << clear;
				REP(j, k)
					if (input[i][y] <= input[j][y])
						mask |= (1 << j);
				debug << nmask((short)mask) << clear;
				debug << arr(creature, x) << clear;
				if (creature[x][mask])
					maxi(ans, input[i][y]);
			}
			printf("%d\n", ans);
		}
	}
	debug << name(MN) << "MAKE SURE IT IS RIGHT!!!!!!!!!!!!!!!!!!!!!!!!!!!" << clear;
}