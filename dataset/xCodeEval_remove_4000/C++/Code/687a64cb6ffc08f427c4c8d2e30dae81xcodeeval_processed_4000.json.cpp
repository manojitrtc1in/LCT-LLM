



using namespace std;





























template<typename T> inline void init(vec<T>& v, deque<int> sizes) {
    assert(sizes.size() == 1);
    v = vec<T> (sizes[0]);
}
template<typename T, typename C> inline void init(vec<T>& v, deque<int> sizes, C content) {
    assert(sizes.size() == 1);
    v = vec<T> (sizes[0], content);
}
template<typename T> inline void init(vec<vec<T>>& v, deque<int> sizes) {
    v = vec<vec<T>> (sizes[0]);
    sizes.pop_front();
    if(sizes.size() == 0) return;
    for(auto& subv : v) init(subv, sizes);
}
template<typename T, typename C> inline void init(vec<vec<T>>& v, deque<int> sizes, C content) {
    v = vec<vec<T>> (sizes[0]);
    sizes.pop_front();
    if(sizes.size() == 0) return;
    for(auto& subv : v) init(subv, sizes, content);
}


template<typename T>void _read(T& t);
template<typename T>void _read(vec<T>&v);
template<typename T1, typename T2>void _read(pair<T1,T2>&p);
template<typename T>void _read(T& t){cin >> t;}
template<typename T>void _read(vec<T>&v){for(unsigned _i=0;_i<v.size();_i++)_read(v[_i]);}
template<typename T1, typename T2>void _read(pair<T1,T2>&p){_read(p.first);_read(p.second);}
void _masterread(){}
template<typename T,typename... V>void _masterread(T& t, V&... v){_read(t);_masterread(v...);}



stringstream _effout;





template<typename T>void _print(T t);
template<typename T>void _print(vec<T>&v);
template<typename T1, typename T2>void _print(pair<T1,T2>&p);
template<typename T>void _print(T t){_stdout<<t;}
template<typename T>void _print(vec<T>&v){for(unsigned _i=0;_i<v.size();_i++)_print(v[_i]),_stdout<<(_i==v.size()-1?"":" ");}
template<typename T1, typename T2>void _print(pair<T1,T2>&p){_print(p.first);_stdout<<" ";_print(p.second);}
void _masterprint(){}
template<typename T,typename... V>void _masterprint(T t, V... v){_print(t);if(sizeof...(v))_stdout<<" ";_masterprint(v...);}




template <typename T> void _debug(T t); 

template<typename T1,typename T2> void _debug(pair<T1,T2> p);
template<typename T> void _debug(vec<T> v);
template<typename T> void _debug(set<T>s);
template<typename T> void _debug(unordered_set<T>s);
template<typename T> void _debug(multiset<T>s);
template<typename T> void _debug(unordered_multiset<T>s);
template<typename T1,typename T2> void _debug(map<T1,T2>mp);
template<typename T1,typename T2> void _debug(unordered_map<T1,T2>mp);
template<typename T1,typename T2> void _debug(multimap<T1,T2>mp);
template<typename T1,typename T2> void _debug(unordered_multimap<T1,T2>mp); 

template <typename T> void _debug(T t){cerr<<t;}
template<typename T1,typename T2> void _debug(pair<T1,T2> p){cerr<<"{";_debug(p.first);cerr<<", ";_debug(p.second);cerr<<"}";}
template<typename T> void _debug(vec<T>v){cerr<<"(";for(unsigned _i=0;_i<v.size();_i++)_debug(v[_i]),cerr<<(_i==v.size()-1?"":", ");cerr << ")";}
template<typename T> void _debug(set<T>s){cerr<<"(";for(auto e=s.begin();e!=s.end();)_debug(*e),cerr<<((++e)==s.end()?"":", ");cerr << ")";}
template<typename T> void _debug(unordered_set<T>s){cerr<<"(";for(auto e=s.begin();e!=s.end();)_debug(*e),cerr<<((++e)==s.end()?"":", ");cerr << ")";}
template<typename T> void _debug(multiset<T>s){cerr<<"(";for(auto e=s.begin();e!=s.end();)_debug(*e),cerr<<((++e)==s.end()?"":", ");cerr << ")";}
template<typename T> void _debug(unordered_multiset<T>s){cerr<<"(";for(auto e=s.begin();e!=s.end();)_debug(*e),cerr<<((++e)==s.end()?"":", ");cerr << ")";}
template<typename T1,typename T2> void _debug(map<T1,T2>mp){cerr<<"(";for(auto e=mp.begin();e!=mp.end();)_debug(*e),cerr<<((++e)==mp.end()?"":", ");cerr << ")";}
template<typename T1,typename T2> void _debug(unordered_map<T1,T2>mp){cerr<<"(";for(auto e=mp.begin();e!=mp.end();)_debug(*e),cerr<<((++e)==mp.end()?"":", ");cerr << ")";}
template<typename T1,typename T2> void _debug(multimap<T1,T2>mp){cerr<<"(";for(auto e=mp.begin();e!=mp.end();)_debug(*e),cerr<<((++e)==mp.end()?"":", ");cerr << ")";}
template<typename T1,typename T2> void _debug(unordered_multimap<T1,T2>mp){cerr<<"(";for(auto e=mp.begin();e!=mp.end();)_debug(*e),cerr<<((++e)==mp.end()?"":", ");cerr << ")";}
void _masterdebug(){cerr<<"]"<<endl;}
template<typename T,typename... V> void _masterdebug(T t,V... v){_debug(t);if(sizeof...(v))cerr<<", ";_masterdebug(v...);}


template<typename T> void _debugall(T c, string n){_debug("debugall: ");_debug(n);cerr<<endl;for(auto _e:c){_debug("  ");_debug(_e);cerr<<endl;}} 









void prep();
void testcase(signed tc);
signed main(){
    if(!_interactive_) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    pr(setprecision(10));
    pr(fixed);
    prep();
    if(_multitest_) {
        signed tests; _multitestexpr_;
        for(signed tc = 1; tc <= tests; tc++) {
            testcase(tc);
        }
    } else {
        testcase(1);
    }

    cout<<_effout.str();

}
void prep(){
}
ll mx = 500000000ll;












pair<ll,ll> egcd(ll a, ll b){ 

	if(b == 0) return {1, 0};
	auto t = egcd(b, a % b);
	return {
		t.second,
		t.first - a / b * t.second
	};
}



ll mpow(ll a, ll b, ll m){ 

	ll res = 1;
	while(b){
		if(b & 1) res = res * a % m;
		b >>= 1;
		a = a * a % m;
	}
	return res;
}
ll mdiv(ll a, ll b, ll m, bool isPrime){ 

	if(isPrime) return a * mpow(b, m - 2, m) % m;
	return ((a * egcd(b, m).first % m) + m) % m;
}
ll mmul(ll a, ll b, ll m){
	return a * b % m;
}
ll madd(ll a, ll b, ll m){
	return (((a + b) % m) + m) % m;
}
ll msub(ll a, ll b, ll m){ 

	return (((a - b) % m) + m) % m;
}


struct hash_util {
    ll P, MOD;
	vector<ll> pw, inv;
	int range;
	hash_util() {};
	hash_util(int max_length, ll P, ll MOD) {
        this->P = P;
        this->MOD = MOD;
		range = max_length;
		pw = vector<ll>(max_length);
		pw[0] = 1;
		for (int i = 1; i < max_length; i++)
			pw[i] = mmul(pw[i - 1], P, MOD);
		inv = vector<ll>(max_length);
		for (int i = 0; i < max_length; i++)
			inv[i] = mpow(pw[i], MOD - 2, MOD); 

	}
	ll ppow(int e) { 

		

		return pw[e];
	}
	ll pinv(int e) { 

		

		return inv[e];
	}
	ll replace(ll hash, int index, char old, char now) {
		hash = msub(hash, mmul(old, pw[index], MOD), MOD);
		hash = madd(hash, mmul(now, pw[index], MOD), MOD);
		return hash;
	}
};

struct string_hash {
	vector<ll> hashes;
	hash_util* util;
	int m;
	string_hash(string s, hash_util* _util) {
		util = _util;
		m = util->MOD;
		int n = s.size();
		hashes = vector<ll>(n);
		hashes[0] = s[0];
		for (int i = 1; i < n; i++)
			hashes[i] = madd(hashes[i - 1], mmul(s[i], util->ppow(i), m), m);
	}
	int substr_hash(int l, int r) {
		ll range = msub(hashes[r], (l == 0 ? 0 : hashes[l - 1]), m);
		return mmul(range, util->pinv(l), m);
	}
};


void testcase(__attribute__((unused)) signed tc){
    int n; re(n);
    vector<string> sts (n); re(sts);
    int len = sts[0].length();
    ll res = 0;
    map<vector<int>, vector<int>> cnts;
    fon(i, n) {
        vector<int> cnt (26);
        foe(e, sts[i]) {
            cnt[e-'a']++;
        }
        cnts[cnt].pb(i);
    }
    ll sum = 0;
    foe(e, cnts) {
        res += (ll)e.se.size() * sum * 1337ll;
        sum += (ll)e.se.size();
    }
    debug(res);
    auto util1 = new hash_util(200002, 457385789, 1e9 + 7);
    auto util2 = new hash_util(200002, 956874539, 1e9 + 9);
    if((ll)n * (ll)n * (ll)len / 2ll <= mx) {
        foe(cnt, cnts) {
            fon(ti, cnt.se.size()) {
                foab(tj, ti + 1, cnt.se.size()) {

                    int i = cnt.se[ti];
                    int j = cnt.se[tj];

                    int i1 = -1;
                    while(i1 < len - 1 && sts[i][i1+1] == sts[j][i1+1]) i1++;
                    i1++;
                    if(i1 == len) continue;
                    int i2 = len;
                    while(i2 > 0 && sts[i][i2-1] == sts[j][i2-1]) i2--;
                    i2--;

                    bool sorted = 1;
                    foab(l, i1 + 1, i2 + 1) {
                        if(sts[i][l] < sts[i][l-1]) {
                            sorted = 0;
                            break;
                        }
                    }
                    if(sorted) {
                        res++;
                        continue;
                    }
                    sorted = 1;
                    foab(l, i1 + 1, i2 + 1) {
                        if(sts[j][l] < sts[j][l-1]) {
                            sorted = 0;
                            break;
                        }
                    }
                    if(sorted) {
                        res++;
                        continue;
                    }
                    res += 2;
                }
            }
        }
    } else {
        vector<int> ones (n), equal (n), total (n);
        vector<vector<ll>> id4;
        vector<vector<ll>> id3;
        init(id4, {n, len + 1});
        init(id3, {n, len + 1});
        fon(i, n) {
            auto id0 = string_hash(sts[i], util1);
            auto id2 = string_hash(sts[i], util2);
            auto substr_hash = [&](int l, int r) -> ll {
                return id0.substr_hash(l,r) * util2->MOD + id2.substr_hash(l,r);
            };
            fon(j, len + 1) {
                auto pref = (j == 0 ? -1 : substr_hash(0, j - 1));
                id4[i][j] = pref;
            }
            fon(j, len + 1) {
                auto suff = (j == 0 ? -1 : substr_hash((len - 1) - j + 1, (len - 1)));
                id3[i][j] = suff;
            }
        }
        foe(cnt, cnts) {
            auto solve = [&](vector<int>& cnt) {
                unordered_map<string, int> strcnt;
                unordered_map<ll, unordered_map<ll,int>> subcnt;
                int done = 0;
                foe(i, cnt) {
                    total[i] = cnt.size();
                    int idx = 0;
                    int eq = strcnt[sts[i]];
                    equal[i] += eq;
                    while(1) {
                        auto pref = idx == 0 ? -1 : id4[i][idx];
                        while(idx + 1 < len && sts[i][idx] <= sts[i][idx+1]) idx++;
                        auto suff = idx == len - 1 ? -1 : id3[i][(len-1)-(idx+1)+1];
                        ones[i] += subcnt[pref][suff] - eq;
                        idx++;
                        if(idx == len) break;
                    }
                    auto& prefs = id4[i];
                    auto& suffs = id3[i];
                    fon(j, len + 1) {
                        int maxlen = len - j + 2;
                        fon(k, maxlen) {
                            subcnt[prefs[j]][suffs[k]]++;
                        }
                    }
                    strcnt[sts[i]]++;
                    done++;
                }
            };
            solve(cnt.se);
            reverse(all(cnt.se));
            solve(cnt.se);
        }
        ll id1 = 0;
        ll totalones = 0;
        fon(i, n) {
            int o = ones[i];
            int e = equal[i] + 1;
            int tot = total[i];
            int two = tot - o - e;

            id1 += two;
            totalones += o;

            debug(o, e, tot, two, sts[i]);

            res -= o;
        }
        res += id1 * 2;
        res -= (id1 - totalones);
    }
    prl(res);
}
