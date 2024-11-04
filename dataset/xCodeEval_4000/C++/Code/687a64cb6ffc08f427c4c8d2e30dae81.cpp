#include<bits/stdc++.h>
#include <mutex>
#include <sstream>
#include <unordered_map>
using namespace std;



#define _multitest_ 0
#define _multitestexpr_ re(tests)
#define _interactive_ 0





#define vec vector
#define pb push_back
#define fi first
#define se second
#define all(_v) _v.begin(),_v.end()
#define ll long long
#define fun(ret,x,...) function<ret(__VA_ARGS__)> x;x=[&](__VA_ARGS__)->ret
#define Void(x,...) fun(void,x,__VA_ARGS__)
#define mp make_pair


#define foabc(i,a,b,c) for (int i = (a); i < (b); i+=(c))
#define foab(i,a,b) for (int i = (a); i < (b); i++)
#define fon(i,n) for(int i = 0; i < n; i++)
#define foe(e,a) for(auto& e : a)
#define rep(n) for(int _ = 0; _ < n; _++)


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
#define re(...)_masterread(__VA_ARGS__)


stringstream _effout;
#if (!defined __local__) || defined _interactive_
#define _stdout cout
#else
#define _stdout _effout
#endif
template<typename T>void _print(T t);
template<typename T>void _print(vec<T>&v);
template<typename T1, typename T2>void _print(pair<T1,T2>&p);
template<typename T>void _print(T t){_stdout<<t;}
template<typename T>void _print(vec<T>&v){for(unsigned _i=0;_i<v.size();_i++)_print(v[_i]),_stdout<<(_i==v.size()-1?"":" ");}
template<typename T1, typename T2>void _print(pair<T1,T2>&p){_print(p.first);_stdout<<" ";_print(p.second);}
void _masterprint(){}
template<typename T,typename... V>void _masterprint(T t, V... v){_print(t);if(sizeof...(v))_stdout<<" ";_masterprint(v...);}
#define pr(...)_masterprint(__VA_ARGS__)
#define prl(...) (_masterprint(__VA_ARGS__),_stdout<<endl)


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
#ifdef __local__
#define debug(...)(cerr<<"["<<#__VA_ARGS__<<"] = [",_masterdebug(__VA_ARGS__))
template<typename T> void _debugall(T c, string n){_debug("debugall: ");_debug(n);cerr<<endl;for(auto _e:c){_debug("  ");_debug(_e);cerr<<endl;}} 

#define debugall(c)(_debugall(c,#c)) 

#else
#define debug(...)
#define debugall(c)
#endif


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
#ifndef __local__
    cout<<_effout.str();
#endif
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
        vector<vector<ll>> prefhashes;
        vector<vector<ll>> suffhashes;
        init(prefhashes, {n, len + 1});
        init(suffhashes, {n, len + 1});
        fon(i, n) {
            auto hasher1 = string_hash(sts[i], util1);
            auto hasher2 = string_hash(sts[i], util2);
            auto substr_hash = [&](int l, int r) -> ll {
                return hasher1.substr_hash(l,r) * util2->MOD + hasher2.substr_hash(l,r);
            };
            fon(j, len + 1) {
                auto pref = (j == 0 ? -1 : substr_hash(0, j - 1));
                prefhashes[i][j] = pref;
            }
            fon(j, len + 1) {
                auto suff = (j == 0 ? -1 : substr_hash((len - 1) - j + 1, (len - 1)));
                suffhashes[i][j] = suff;
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
                        auto pref = idx == 0 ? -1 : prefhashes[i][idx];
                        while(idx + 1 < len && sts[i][idx] <= sts[i][idx+1]) idx++;
                        auto suff = idx == len - 1 ? -1 : suffhashes[i][(len-1)-(idx+1)+1];
                        ones[i] += subcnt[pref][suff] - eq;
                        idx++;
                        if(idx == len) break;
                    }
                    auto& prefs = prefhashes[i];
                    auto& suffs = suffhashes[i];
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
        ll totaltwos = 0;
        ll totalones = 0;
        fon(i, n) {
            int o = ones[i];
            int e = equal[i] + 1;
            int tot = total[i];
            int two = tot - o - e;

            totaltwos += two;
            totalones += o;

            debug(o, e, tot, two, sts[i]);

            res -= o;
        }
        res += totaltwos * 2;
        res -= (totaltwos - totalones);
    }
    prl(res);
}
