


using namespace std;
































Tt_ T, typename U> bool in(T x, U y) {return x == y;}
Tt_ T, typename U, typename ...V> bool in(T x, U y, V... z) {return x == y || in(x, z...);}
Tt_ T> bool diff(T _) {return true;}
Tt_ T, typename ...U> bool diff(T x, U... y) {return !in(x, y...) && diff(y...);}
Tt_ T, typename U> bool equal(T x, U y) {return x == y;}
Tt_ T, typename U, typename ...V> bool equal(T x, U y, V...z) {return x == y && equal(x, z...);}
Tt_ T, typename U> bool in_order(T x, U y) {return x <= y;}
Tt_ T, typename U, typename ...V> bool in_order(T x, U y, V...z) {return x <= y && in_order(y, z...);}
Tt_ T, typename U> bool id0(T x, U y) {return x < y;}
Tt_ T, typename U, typename ...V> bool id0(T x, U y, V...z) {return x < y && id0(y, z...);}
Tt_ T> void swap3(T &x, T&y, T&z) {swap(x, y); swap(x, z);}










Tt_ T, typename U> auto my_min(const T & x, const U & y) -> decltype(true?x:y) {if (x < y) return x; return y;}
Tt_ T, typename U> auto my_max(const T & x, const U & y) -> decltype(true?x:y) {if (x > y) return x; return y;}

(a, my_
const U& b, const V& c, const W&d)->decltype(true?a:(true?b:(true?c:d))){return my_
Tt_ T,typename U,typename V>auto med(const T&a,const U&b,const V&c)->decltype(true?a:(true?b:c)){return my_min(my_max(a,b),my_max(my_min(a
,b),c));}namespace std{Tt_ T,typename U>struct hash<pair<T,U>>{size_t operator()(const pair<T,U>&a)const{return(hash<T>()(a.first)*
1420343LL ^ hash<U>()(a.second) * 923275LL) % 1463984161;}};}make_mins(min) make_mins(max)int CON_BOUND = 10;








const bool deb = true;



const bool deb = false;







Tt_ T, typename C>ostream & operator<<(ostream &os, pair<T, C> x) {return os << "<" << x.f << ", " << x.s << ">";}
Tt_ T> auto operator<<(ostream&os,T x)->typename enable_if<is_same<decltype(x.begin()),decltype(x.end())>::value&&
	!is_same<T,string>::value,ostream &>::type{os<<"{";int i=0;for(auto c:x){if(i++==siz(x)-1||siz(x)<CON_BOUND+2||i<CON_BOUND){if
	(i-1&&(i!=siz(x)||siz(x)<CON_BOUND+2))os<<", ";os<<c;}if(i==CON_BOUND&&siz(x)>CON_BOUND+1)os<<" ... ";}return os<<"}_"<<x.size();}
string br(string x){int dep=0;for(char c:x){for(char d:"([{")if(c==d)dep++;for(char d:"}])")if(c==d)dep--;for(char d:
"+-*/%^<>=&|?~,")if(c==d&&!dep)return"("+x+")";}return x;}























	h(__VA_ARGS__)<<")) = "<<







		k<<


		g(__VA_ARGS__)<<" = "<<(f(x) op g(__VA_ARGS__))ao


		g(__VA_ARGS__)<<" = "<<(a[i] op g(__VA_ARGS__))ao

	),decltype(x.s op y.s)>{return MP(x.f op y.f,x.s op y.s);}Tt_ A,typename B,typename C>auto operator op(pair<A,B>x, C y)->\
	pair<decltype(x.f op y),decltype(x.s op y)>{return MP(x.f op y, x.s op y);}Tt_ A,typename C,typename D>auto operator\
	op(A x,pair<C, D>y)->pair<decltype(x op y.f),decltype(x op y.s)>{return MP(x op y.f,x op y.s);}

	x.s op y.s;return x;}Tt_ A,typename B,typename C>pair<A,B>&operator op(pair<A,B>&x,C y){x.f op y;x.s op y;return x;}

	Tt_ A, typename B> pair <A, B> operator op(pair <A, B> &x, int _){return MP(x.f op, x.s op);}

	typename remove_reference<decltype(op x.s)>::type>{return MP(fs(op x));}
make_op(+)make_op(-)make_op(/)make_op(*)make_op(%)make_op(&)make_op(|)make_op(^)make_op(&&)make_op(||)make_op3(++)make_op3(--)
make_op2(+=)make_op2(-=)make_op2(*=)make_op2(/=)make_op2(%=)make_op2(^=)make_op2(&=)make_op2(|=)xUk2(*)xUk2(~)xUk2(!)xUk2(-)
string concat(){return"";}Tt_ T>string concat(T x){stringstream os;os<<x;return os.str();}
Tt_ T, typename ...U>string concat(T x, U... y) {return concat(x)+", "+concat(y...);}

Tt_ T>string strmask(T r) {string ans;FORD(i,8*sizeof(T)-1,0){if(i%5==4)ans+='.';ans+='0'+!!(((T)1<<i)&r);}return ans;}





const int inf = 1e9;
const LL llinf = 3e18;
int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,
167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,
367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,
587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,
811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997},big_primes[]={1307533217,
1336158883,1339172111,1367797777,1376837461,1399436671,1426555723,1440115249,1444635091,1489833511,1553111299,1562150983,1587763421,
1610362631,1652547823,1666107349,1700759471,1782116627,1797182767,1810742293,1818275363,1892099449,1904152361,1919218501,1940311097,
1944830939,1968936763,1977976447,1985509517,1990029359},gens[]={1,2,3,5,2,11,3,14,19,11,17,32,30,34,29,19,34,31,63,33,5,63,53,58,40,83,21,
18,99,33,106,40,85,109,40,77,91,120,105,91,79,53,182,10,184,48,48,150,168,72,65,46,31,216,101,134,163,147,93,42,69,7,151,308,112,12,227,
185,214,305,163,234,154,316,3,11,233,390,271,173,82,407,13,135,414,391,177,293,426,432,337,281,385,103,95,152,12,371,390,77,532,34,287,73,
308,493,258,549,528,411,12,283,614,596,622,309,91,511,287,433,585,123,2,170,183,341,459,322,333,337,507,718,82,517,396,315,565,48,362,617,
776,425,584,231,578,395,127,27,506,435,727,659,697,385,290,109,430,422,344,849,513,453,852,920,152,482,653,271},big_gens[]={661761153,
1315209189,235649158,80905954,861543922,677870461,332266749,1192707557,820697698,93737534,1395132003,176849700,1113502216,860516128,
1543755630,328298286,1219407972,1407392293,733053145,400000570,1081174233,847228024,1516266762,83276926,500618997,44975430,47827763,
1411328206,151880843,19696955};
const int MN = deb ? (1 << 6) : (1 << 17);
const int mod = 1e9 + 7;
int mul(int a, int b) {
	return a * 1ll * b % mod;
}
LL __temp[MN * 2];
void xor_kara(LL a[], LL b[], LL res[], LL len = MN, LL *temp = __temp) {
	bool same = (a == b);
	if (len <= 8) {
		REP(i, len)
			REP(j, len)
				res[i ^ j] += a[i] * b[j];
		return;
	}
	
	
	
	

	REP(i, len / 2) {
		a1[i] += a2[i];
	}
	if (!same) REP(i, len / 2)
		b1[i] += b2[i];
	xor_kara(a1, b1, res, len / 2, temp + len / 2);
	REP(i, len / 2) {
		a1[i] -= a2[i];
	}
	if (!same)
		REP(i, len / 2)
			b1[i] -= b2[i];
	memset(temp, 0, len / 2 * sizeof(temp[0]));
	xor_kara(a1, b2, temp, len / 2, temp + len / 2);
	if (same) {
		REP(i, len / 2) {
			res[i] -= 2 * temp[i];
			res[i + len / 2] += 2 * temp[i];
		}
	}
	else {
		REP(i, len / 2) {
			res[i] -= temp[i];
			res[i + len / 2] += temp[i];
		}
		memset(temp, 0, len / 2 * sizeof(temp[0]));
		xor_kara(a2, b1, temp, len / 2, temp + len / 2);
		REP(i, len / 2) {
			res[i] -= temp[i];
			res[i + len / 2] += temp[i];
		}
	}
}
LL cou[MN];
LL d[MN], e[MN], de[MN];
LL ab[MN], c[MN];
LL fib[MN];
const int ALL = MN - 1;
void id1(LL a[MN], LL b[MN], LL res[MN]) {
	debug << range(a, 0, MN - 1) << range(b, 0, MN - 1) << eoln;
	static LL sum[MN];
	REP(mask, MN) {
		LL asum = 0, bsum = 0;
		for (int x = ALL ^ mask;; x = (x - 1) & (ALL ^ mask)) {
			asum += a[mask | x];
			bsum += b[mask | x];
			if (!x) break;
		}
		sum[mask] = (asum % mod) * (bsum % mod) % mod;
	}
	debug << range(sum, 0, MN - 1) << eoln;
	REP(mask, MN) {
		for (int x = ALL ^ mask;; x = (x - 1) & (ALL ^ mask)) {
			int sign = __builtin_popcount(x) % 2 ? -1 : 1; 
			res[mask] += sum[mask | x] * sign;
			if (!x) break;
		}
		res[mask] %= mod;
	}
}
LL abc[MN];
LL abcde[MN];
int main() {
	CON_BOUND = MN;
	debug << name(MN) << fun(log10, MN) << name("CHECK "+to_string(MN)+" times!!!!!!!!!!!!") << eoln;


	int n;
	scanf("%d", &n);
	REP(i, n) {
		int x;
		scanf("%d", &x);
		cou[x]++;
	}
	fib[0] = 0;
	fib[1] = 1;
	FOR(i, 2, MN - 1) {
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	}
	debug << "xor_kara(d, e, de)" << eoln;
	xor_kara(cou, cou, de);
	REP(ii, MN) {
		int i = (MN - 1) ^ ii;
		for (int j = i;; j = i & (j - 1)){
			assert((ii & j) == 0);
			ab[ii|j] += cou[ii] * 1ll * cou[j];

			if (j == 0)
				break;
		}
	}
	debug << range(cou, 0, MN - 1) << eoln;
	debug << range(ab, 0, MN - 1) << eoln;
	debug << range(de, 0, MN - 1) << eoln;
	REP(i, MN) {
		ab[i] = ab[i] % mod * fib[i] % mod;
		de[i] = de[i] % mod * fib[i] % mod;
		cou[i] *= fib[i];
		cou[i] %= mod;
	}
	debug << range(ab, 0, MN - 1) << eoln;
	debug << range(de, 0, MN - 1) << eoln;
	debug << range(fib, 0, MN - 1) << eoln;
	debug << "id1(ab, fib, abc)" << eoln;
	id1(ab, cou, abc);
	debug << "id1(abc, de, abcde)" << eoln;
	id1(abc, de, abcde);
	debug << range(abc, 0, MN - 1) << eoln;
	debug << range(abcde, 0, MN - 1) << eoln;
	LL ans = 0;
	for (int i = 0; (1 << i) < MN; ++i)
		ans += abcde[1 << i];
	ans %= mod;
	if (ans < 0) ans += mod;
	printf("%lld\n", ans);
	debug << name(MN) << "MAKE SURE IT IS RIGHT!!!!!!!!!!!!!!!!!!!  " << range(primes, 6, 9) << fun(med, 66, ~66, 0xd) << eoln;
}
