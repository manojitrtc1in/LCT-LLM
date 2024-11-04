#include <bits/stdc++.h>

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAX_NUM = 301;
const ll MAX_N = 4e5 + 7;
const ll MAX_Q = 2e5 + 7;

ll do_add(const ll& a, const ll& b) {
	return (a+b) % MOD;
}

ll do_mul(const ll& a, const ll& b) {
	return (a*b) % MOD;
}

static ll fastpow(const ll& base, const ll& pow, const ll& MOD = 1e9 + 7) {
	ll res = 1;
	for (ll exp = pow, n = base; exp; ) {
		if ( exp & 1 ) {
			res = (res * n) % MOD;
			--exp;
		} else {
			n = (n * n) % MOD;
			exp >>= 1;
		}
	}
	return res;
}

struct st {
	const ll n;
	ll del[4 * MAX_N + 1], sum[4 * MAX_N + 1];

	st(void) : st(MAX_N) {}

	st(const ll& _n) : n(_n) {
		clr();
	}

	void clr(void) {
		memset(del, 0, sizeof(del));
		memset(sum, 0, sizeof(sum));
	}

	void set(const ll& i, const ll& v) {
		del[i] = do_add(del[i], v);
	}

	void pro(const ll& i) {
		set(2 * i, del[i]);
		set(2*i+1, del[i]);
		del[i] = 0;
	}

	void add(const ll& i, const ll& lr, const ll& rr, const ll& le, const ll& ri, const ll& v) {
		if (lr == le && rr == ri) {
			set(i, v);
			return;
		}
		pro(i);
		const ll mi = (lr + rr) / 2;
		if (le <= mi)
			add(2 * i, lr, mi, le, std::min(mi, ri), v);
		if (mi < ri)
			add(2*i+1, mi+1, rr, std::max(mi+1, le), ri, v);
		sum[i] = do_add(do_add(sum[2*i], sum[2*i+1]), do_add(do_mul((mi - lr + 1) , del[2*i]), do_mul((rr - mi), del[2*i+1])));
	}

	ll query(const ll& i, const ll& lr, const ll& rr, const ll& le, const ll& ri) {
		if (lr == le && rr == ri) {
			return sum[i] + (rr - lr + 1) * del[i];
		}
		pro(i);
		const ll mi = (lr + rr) / 2;
		ll ret = 0;
		if (le <= mi)
			ret = do_add(ret, query(2 * i, lr, mi, le, std::min(mi, ri)));
		if (mi < ri)
			ret = do_add(ret, query(2*i+1, mi+1, rr, std::max(le,mi+1), ri));
		sum[i] = do_add(do_add(sum[2*i], sum[2*i+1]), do_add(do_mul((mi - lr + 1), del[2*i]), do_mul((rr - mi), del[2*i+1])));
		return ret;
	}

	void add(const ll& l, const ll& r, const ll& v) {add(1, 0, n-1, l, r, v);}
	ll query(const ll& l, const ll& r) {return query(1, 0, n-1, l, r);}
};

struct st2 {
	const ll n;
	ll del[4 * MAX_N + 1], sum[4 * MAX_N + 1];

	st2(void) : st2(MAX_N) {}

	st2(const ll& _n) : n(_n) {
		clr();
	}

	void clr(void) {
		memset(del, 0, sizeof(del));
		memset(sum, 0, sizeof(sum));
	}

	void set(const ll& i, const ll& v) {
		del[i] |= v;
	}

	void pro(const ll& i) {
		set(2 * i, del[i]);
		set(2*i+1, del[i]);
		del[i] = 0;
	}

	void add(const ll& i, const ll& lr, const ll& rr, const ll& le, const ll& ri, const ll& v) {
		if (lr == le && rr == ri) {
			set(i, v);
			return;
		}
		pro(i);
		const ll mi = (lr + rr) / 2;
		if (le <= mi)
			add(2 * i, lr, mi, le, std::min(mi, ri), v);
		if (mi < ri)
			add(2*i+1, mi+1, rr, std::max(mi+1, le), ri, v);
		sum[i] = sum[2*i] | sum[2*i+1] | del[2*i] | del[2*i+1];
	}

	ll query(const ll& i, const ll& lr, const ll& rr, const ll& le, const ll& ri) {
		if (lr == le && rr == ri) {
			return sum[i] | del[i];
		}
		pro(i);
		const ll mi = (lr + rr) / 2;
		ll ret = 0;
		if (le <= mi)
			ret |= query(2 * i, lr, mi, le, std::min(mi, ri));
		if (mi < ri)
			ret |= query(2*i+1, mi+1, rr, std::max(le,mi+1), ri);
		sum[i] = sum[2*i] | sum[2*i+1] | del[2*i] | del[2*i+1];
		return ret;
	}

	void add(const ll& l, const ll& r, const ll& v) {add(1, 0, n-1, l, r, v);}
	ll query(const ll& l, const ll& r) {return query(1, 0, n-1, l, r);}
};

struct st3 {
	const ll n;
	ll del[4 * MAX_N + 1], sum[4 * MAX_N + 1];

	st3(void) : st3(MAX_N) {}

	st3(const ll& _n) : n(_n) {
		clr();
	}

	void clr(void) {
		std::fill(del, del + 4 * n + 1, 1);
		std::fill(sum, sum + 4 * n + 1, 1);
	}

	void set(const ll& i, const ll& v) {
		del[i] = do_mul(del[i], v);
	}

	void pro(const ll& i) {
		set(2 * i, del[i]);
		set(2*i+1, del[i]);
		del[i] = 1;
	}

	void add(const ll& i, const ll& lr, const ll& rr, const ll& le, const ll& ri, const ll& v) {
		if (lr == le && rr == ri) {
			set(i, v);
			return;
		}
		pro(i);
		const ll mi = (lr + rr) / 2;
		if (le <= mi)
			add(2 * i, lr, mi, le, std::min(mi, ri), v);
		if (mi < ri)
			add(2*i+1, mi+1, rr, std::max(mi+1, le), ri, v);
		sum[i] = do_mul(do_mul(sum[2*i], sum[2*i+1]), do_mul(fastpow(del[2*i], (mi - lr + 1)), fastpow(del[2*i+1], (rr - mi))));
	}

	ll query(const ll& i, const ll& lr, const ll& rr, const ll& le, const ll& ri) {
		if (lr == le && rr == ri) {
			return do_mul(sum[i], fastpow(del[i], rr - lr + 1));
		}
		pro(i);
		const ll mi = (lr + rr) / 2;
		ll ret = 1;
		if (le <= mi)
			ret = do_mul(ret, query(2 * i, lr, mi, le, std::min(mi, ri)));
		if (mi < ri)
			ret = do_mul(ret, query(2*i+1, mi+1, rr, std::max(le,mi+1), ri));
		sum[i] = do_mul(do_mul(sum[2*i], sum[2*i+1]), do_mul(fastpow(del[2*i], (mi - lr + 1)), fastpow(del[2*i+1], (rr - mi))));
		return ret;
	}

	void add(const ll& l, const ll& r, const ll& v) {add(1, 0, n-1, l, r, v);}
	ll query(const ll& l, const ll& r) {return query(1, 0, n-1, l, r);}
};

struct bg_q {
	std::string type;
	ll l, r, x, ans;
} qs[MAX_Q];
























ll a[MAX_N], factor[MAX_NUM][MAX_NUM], rank[MAX_NUM], minvs[MAX_NUM];
char sieve[MAX_NUM];
std::vector<ll> primes;

ll mask_pc[MAX_NUM];

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	const std::vector<ll> dlogs = {0LL, 0LL, 381838282LL, 884237698LL, 763676564LL, 1LL, 266075974LL, 936544532LL, 145514840LL, 768475390LL, 381838283LL, 649233168LL, 647914256LL, 144547565LL, 318382808LL, 884237699LL, 527353122LL, 895459693LL, 150313666LL, 701153241LL, 763676565LL, 820782224LL, 31071444LL, 82047235LL, 29752532LL, 2LL, 526385847LL, 652713082LL, 700221090LL, 347375814LL, 266075975LL, 198670980LL, 909191404LL, 533470860LL, 277297969LL, 936544533LL, 532151948LL, 289190395LL, 82991517LL, 28785257LL, 145514841LL, 802264261LL, 202620500LL, 24616936LL, 412909726LL, 768475391LL, 463885517LL, 730741137LL, 411590814LL, 873089058LL, 381838284LL, 779697385LL, 908224129LL, 616590335LL, 34551358LL, 649233169LL, 82059366LL, 585390933LL, 729214096LL, 178404868LL, 647914257LL, 234516540LL, 580509262LL, 705019916LL, 291029680LL, 144547566LL, 915309142LL, 351358075LL, 659136251LL, 966284933LL, 318382809LL, 557546595LL, 913990230LL, 559624399LL, 671028677LL, 884237700LL, 464829799LL, 585777694LL, 410623539LL, 414776906LL, 527353123LL, 536950774LL, 184102537LL, 809672376LL, 584458782LL, 895459694LL, 406455218LL, 231613506LL, 794748008LL, 689565125LL, 150313667LL, 81092091LL, 845723799LL, 82908672LL, 112579413LL, 701153242LL, 793429096LL, 993378125LL, 254927334LL, 417708552LL, 763676566LL, 495914368LL, 161535661LL, 991051336LL, 290062405LL, 820782225LL, 998428617LL, 326036185LL, 416389640LL, 525353314LL, 31071445LL, 173428087LL, 463897648LL, 429750477LL, 967229215LL, 82047236LL, 111052372LL, 913022955LL, 560243150LL, 832004219LL, 29752533LL, 298466330LL, 616354822LL, 686501953LL, 962347544LL, 3LL, 86858192LL, 155622902LL, 672867962LL, 908854634LL, 526385848LL, 26958408LL, 297147418LL, 637697767LL, 733196357LL, 652713083LL, 40974527LL, 540374100LL, 348123209LL, 293399235LL, 700221091LL, 614978829LL, 939384877LL, 793780733LL, 295828506LL, 347375815LL, 941462681LL, 757326750LL, 52866953LL, 109607515LL, 266075976LL, 468364065LL, 846668081LL, 663935077LL, 967615976LL, 198670981LL, 792461821LL, 967234449LL, 796615188LL, 500828027LL, 909191405LL, 18591761LL, 918789056LL, 238291131LL, 565940819LL, 533470861LL, 191510652LL, 98758628LL, 966297064LL, 289095130LL, 277297970LL, 469628625LL, 788293500LL, 328851128LL, 613451788LL, 936544534LL, 176586284LL, 62642560LL, 71403401LL, 492996069LL, 532151949LL, 546888614LL, 462930373LL, 118754232LL, 227562075LL, 289190396LL, 464746954LL, 544692855LL, 494417695LL, 589257608LL, 82991518LL, 366164793LL, 175267372LL, 23539458LL, 375216401LL, 28785258LL, 636765616LL, 829772542LL, 799546834LL, 912024915LL, 145514842LL, 235595767LL, 877752650LL, 283920340LL, 543373943LL, 802264262LL, 372889612LL, 850522625LL, 671900687LL, 350386403LL, 202620501LL, 437098732LL, 380266893LL, 441784287LL, 707874467LL, 24616937LL, 798227922LL, 135215506LL, 907191596LL, 443862091LL, 412909727LL, 40007252LL, 555266369LL, 768794522LL, 845735930LL, 768475392LL, 811588759LL, 342799273LL, 349067491LL, 566661897LL, 463885518LL, 470015386LL, 492890654LL, 924677391LL, 294861231LL, 730741138LL, 942081432LL, 299014598LL, 213842495LL, 732754158LL, 411590815LL, 733768720LL, 680304612LL, 421188466LL, 998193104LL, 873089059LL, 68340229LL, 845700806LL, 344185820LL, 693910068LL, 381838285LL, 241119035LL, 468696474LL, 731280403LL, 537461184LL, 779697386LL, 54706238LL, 17661842LL, 290692910LL, 225734921LL, 908224130LL, 115851198LL, 408796690LL, 872301485LL, 678985700LL, 616590336LL, 19536043LL, 573802817LL, 115034633LL, 298959763LL, 34551359LL, 462560014LL, 422812809LL, 965329789LL, 922212382LL, 649233170LL, 729961491LL, 31035300LL, 675237517LL, 967146370LL, 82059367LL, 345578910LL, 996817111LL, 82704431LL, 321223153LL, 585390934LL, 175619009LL, 738808787LL, 677666788LL, 790919380LL, 729214097LL, 877615817LL, 323300957LL, 912101836LL, 139165026LL, 178404869LL, 434705235LL, 301946244LL, 491445797LL, 226594800LL, 647914258LL};

	memset(sieve, 1, sizeof(sieve));
	sieve[0] = sieve[1] = false;
	for (ll i = 2; i < MAX_NUM; ++i) {
		ll num = i;
		for (ll s = 2; s * s <= num; ++s)
			while (num % s == 0) {
				num /= s; factor[i][s]++;
			}
		if (num > 1) factor[i][num]++;

		if (!sieve[i]) continue;

		rank[i] = primes.size();
		primes.push_back(i);

		for (ll j = i+i; j < MAX_NUM; j += i)
			sieve[j] = false;
	}

	

	for (ll i = 1; i < MAX_NUM; ++i) {
		

		

		minvs[i] = fastpow(i, MOD-2, MOD);
	}
	


	const ll NUM_PRIMES = primes.size();

	for (ll i = 1; i < MAX_NUM; ++i)
		for (ll p = 0; p < NUM_PRIMES; ++p)
			mask_pc[i] |= static_cast<ll>(i % primes[p] == 0) << p;

	ll n, q; std::cin >> n >> q;

	st3 seg(n);
	st2 occ(n);

	for (ll i = 0; i < n; ++i) {
		std::cin >> a[i];
		seg.add(i, i, a[i]);
		occ.add(i, i, mask_pc[a[i]]);
	}

	

	

	


	for (ll i = 0; i < q; ++i) {
		std::cin >> qs[i].type >> qs[i].l >> qs[i].r;
		--qs[i].l; --qs[i].r;
		if (qs[i].type.front() == 'M') {
			std::cin >> qs[i].x;
			seg.add(qs[i].l, qs[i].r, qs[i].x);
			occ.add(qs[i].l, qs[i].r, mask_pc[qs[i].x]);
		} else {
			ll prod = seg.query(qs[i].l, qs[i].r);

			const ll in_range = occ.query(qs[i].l, qs[i].r);
			for (ll p = 0; p < NUM_PRIMES; ++p)
				if (in_range & (1LL << p)) {
					prod = (prod * (primes[p] - 1)) % MOD;
					prod = (prod * (minvs[primes[p]])) % MOD;
				}

			std::cout << prod << "\n";
		}
	}

	return 0;
}
