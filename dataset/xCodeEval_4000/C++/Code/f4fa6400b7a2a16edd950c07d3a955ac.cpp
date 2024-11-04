#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll=long long; using ld=long double; using vi=vector<int>; using vl=vector<ll>; using vs=vector<string>;
using pii=pair<int, int>;  using vii=vector<pii>; using pll=pair<ll, ll>; using vll=vector<pll>;
using mii=map<int, int>; using mll=map<ll, ll>; using msi=map<string, ll>; using vvi=vector< vi >;
template <typename T> using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define     endl               "\n"
#define     inf                (1<<30)
#define     eps                (1e-9)
#define     mod                (1000000007)
#define     pi                 (acos(-1.0))
#define     fast_io            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     _unique(c)         (c).resize(unique(begin(c), end(c)) - (c).begin())
#define     rep(i, n)          for(__typeof(n) i=0; i<(n); i++)
#define     foab(i, a, b)      for(__typeof(b) i=(a); i<=(b); i++)
#define     foba(i, a, b)      for(__typeof(b) i=(b); i>=(a); i--)
#define     forit(it, l)       for(__typeof((l).begin()) it = begin(l); it != end(l); it++)
#define     file_io            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define     error(args...) {                                                             \
                string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');              \
                stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); \
            }
void err(istream_iterator<string> it) {}                 template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<" = "<<a<<endl; err(++it, args...); }

template<typename T, typename TT>
ostream& operator<<(ostream &os, const pair< T, TT > &t) { return os << "(" << t.first << "," << t.second << ")"; }
template<typename T, typename TT, typename TTT>
ostream& operator<<(ostream &os, const tuple< T, TT, TTT > &t) { return os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &t) { ll n = t.size(); rep(i, n) os << t[i] << " "; return os; }

enum COLOR{ white = 1 , grey = 2 , black = 3, red = 4, green = 5, blue = 6 };



#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) \
for ( \
    auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
    blockTime.second; \
    debug("%s: %.4lf s\n", d, (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count())/1e3), blockTime.second = false \
)



namespace UtilSpace {

    vii dir_4 { {1,0}, {0,1}, {-1,0}, {0,-1} };
    vii dir_8 { {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1} };
    vii dir_knight { {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1} };

    bool checkBit(int n, int pos) { return (n & (1<<pos)) != 0; }
    int setBit(int n, int pos) {return (n | (1<<(pos))); }
    int resetBit(int n, int pos) { return (n & ~(1 << pos)); }
    void printBits(int n){ if(n >= 2)printBits(n/2); cout<<(n&1); }
    int countOnes(int n) { int r=0; while(n && ++r) n -= n & -n; return r; }
    bool isPowerOfTwo(int n) { return n && !(n & (n - 1)); }

    template <typename T>
    string toString(T n) { stringstream ss; ss << n; return ss.str(); }

    ll bigMul(ll a,ll b,ll m) {
        ll result = 0; a %= m;
        while(b) { if(b&1LL) result=(result+a)%m; a=(a+a)%m; b>>=1; }
        return result;
    }

    ll bigMod(ll b, ll e, ll m) {
        if(!e)return 1%m;
        if(!(e&1LL)){ ll y = bigMod(b, e>>1LL, m); return bigMul(y, y, m); }
        ll z = bigMod(b, e-1, m); return (bigMul(b%m, z, m));
    }

    ll bigPow(ll a, ll b) {
        ll res = 1LL; 
        while(b) { res = (b&1LL)? res*a : res, b >>= 1LL, a *= a; }
        return res;
    }

    template< typename T >
    T exEuclid(T a, T b, T& x, T& y) {
        if(!b){ x = 1, y = 0; return a; }
        T x1, y1, temp = exEuclid<T>(b, a%b, x1, y1);
        x = y1, y = x1 - y1*(a/b);
        return temp;
    }

    template< typename T >
    T modInverse(T a, T m){ T x, y; T g = exEuclid<T>(a, m, x, y); if(g != 1){ return -1; } else{ return (x%m + m)%m; } }


    const unsigned int M = 2e8+2;

    int status[(M>>6) + 7] = {0};
    bitset<500000002> _primalStatus;
    #define on(x) (status[x>>6] & (1<<((x&63)/2)))
    #define mark(x)  status[x>>6] |= (1<<((x&63)/2))

    

    vector<int> sieve(const int& range) {
        fill(status, status + (range>>6) + 7, 0);

        vector<int> primes;
        if(range >= 2) primes.push_back(2); 

        int i(3);
        for(; i*i <= range; i += 2)  

            if(!on(i)) { 

                primes.push_back(i); 

                for(int j = i*i ; j <= range; j += i + i)  

                    mark(j);   

            }
        for(; i <= range; i += 2) if(!on(i)) primes.push_back(i); 

        return primes;
    }
    

    inline bool isPrime(const int& n) { return n == 2 || (n > 2 && (n&1) && !on(n)); }

    

    vector<ll> segmentedSieve(const ll& a, const ll& b) {
        int x = floor(sqrt(b*1.0)) + 1;
        vector<int> rootedPrimes = sieve(x);
        const int range(b - a + 1);
        _primalStatus.reset();

        for (int& curPrime : rootedPrimes) {
            if(curPrime == 2) continue; 

            

            ll start = max((curPrime * curPrime * 1LL), (((a + curPrime - 1LL) / curPrime) * curPrime));
            start = (start & 1LL)? start : start + curPrime; 

            for (int i = start - a; i < range; i += curPrime<<1LL) {
                _primalStatus.set(i>>1);
            }
        }
        vl segPrimes;
        if (a <= 2 && b >= 2) { segPrimes.push_back(2LL); }
        for (int k = (a & 1) ? 0 : 1; k < range; k += 2) {
            if (!_primalStatus.test(k>>1) && a+k != 1) {
                segPrimes.push_back((ll)a+k);
            }
        }
        return segPrimes;
    }

    bool isSegmentedPrime(const ll& n, const ll& l, const ll& r) {
        return n>=l && n<=r && (n==2 || (n>2 && (n&1LL) && !_primalStatus.test((n-l)>>1LL)));
    }

    

    

    vector<int> segmentedSieve(const int& n) {
        int x = floor(sqrt(n))+1;
        vector<int> rootedPrimes = sieve(x), primes;
        for(auto & p : rootedPrimes) if(p*p<=n)primes.push_back(p);
        int a = x, b = 2*x; 

        bitset<16000> ps;
        while(a < n) {
            ps.reset();
            b = b >= n ? n : b; 

            const int range(b - a + 1);
            for (int& curPrime : rootedPrimes) {
                if(curPrime == 2) continue; 

                

                ll start = max((curPrime * curPrime * 1LL), (((a + curPrime - 1LL) / curPrime) * curPrime));
                start = (start & 1LL)? start : start + curPrime; 

                for (int i = start - a; i < range; i += curPrime<<1LL) {
                    ps.set(i>>1);
                }
            }
            if (a <= 2 && b >= 2) { primes.push_back(2LL); }
            for (int k = (a & 1) ? 0 : 1; k < range; k += 2) {
                if (!ps.test(k>>1) && a+k != 1) {
                    primes.push_back((ll)a+k);
                }
            }
            a += x, b += x;
        }
        return primes;
    }


    

    

    tuple<vll, ll, ll> primeFactorize(const ll& num, const vi& rootedPrimes) {
        ll n = num, factorSum = 1, factorCount = 1;;
        vll factorsWithCount;
        for(const int& smallPrime : rootedPrimes) {
            if(smallPrime * smallPrime * 1LL <= n && !(n % smallPrime)) {
                ll pc = 0;
                while(!(n % smallPrime)) { n /= smallPrime, ++pc; }
                factorsWithCount.emplace_back(smallPrime, pc);
                factorSum *= (bigPow(smallPrime, pc+1) - 1) / (smallPrime - 1LL); 

                factorCount *= (pc+1);  

            }
        }
        

        if(n > 1) {
           factorsWithCount.emplace_back(n, 1LL);
           factorSum *= (bigPow(n, 2) - 1) / (n - 1LL); 

           factorCount *= 2LL; 

        }
        return make_tuple(factorsWithCount, factorSum, factorCount);
    }

    


    

    

    ll computeHash(string const& str) {
    	const int p = 31; 

    	const int m = 1e9 + 9; 

    	ll hash_value = 0LL, p_i = 1;
    	for(const char& c : str) {
    		hash_value = (hash_value + (c - 'a' + 1) * p_i) % m, p_i = (p_i * p)%m;
    	}
    	return hash_value;
    }

	

    vvi groupIdenticalStrings(vs const& strings) {
    	int n = strings.size(); 
    	vll hashes(n);
    	rep(i, n) hashes[i] = {computeHash(strings[i]), i}; 

    	sort(hashes.begin(), hashes.end()); 

    	vvi groups;
    	rep(i, n) {
    		if(!i || hashes[i-1].first != hashes[i].first) groups.emplace_back();
    		groups.back().push_back(hashes[i].second);
    	}
    	return groups;
    }

	

	

    int countUniqueSubstrings(string const& str) {
    	int n = str.size();
    	const int p = 31, m = 1e9 + 9;
    	vl pow_p(n,1);
    	for(int i = 1; i < n; i++) pow_p[i] = (p * pow_p[i-1]) % m;
    	vl h(n+1, 0LL); 

    	foab(i, 1, n) h[i] = (h[i-1] + (str[i-1] - 'a' + 1) * pow_p[i-1]) % m; 

    	int cnt(0);
    	foab(len, 1, n) {
    		set<ll> hs;
    		foab(i, 0, n-len) {
    			ll curHash = (h[i+1] + m - h[i]) % m;
    			curHash = (curHash * pow_p[n-1-i]) % m; 

    			hs.insert(curHash);
    		}
    		cnt += hs.size(); 

    	}
    	return cnt;
    }

    

    vi patternMatch(string const& needle, string const& haystack) {
		int l1 = needle.size(), l2 = haystack.size();
		vi indices;
		if(!l1 || l1 > l2) 
			return indices; 
		const int p = 31, m = 1e9+9;
		vl power(l2, 1LL), prefixHash(l2+1, 0LL); 
		for(int i = 1 ; i <= l2; i++) {
			if(i<l2) power[i] = (power[i-1] * p) % m; 

			prefixHash[i] = (prefixHash[i-1] + (haystack[i-1]-'a'+1) * power[i-1]) % m; 

		}
		ll needleHash = UtilSpace::computeHash(needle);
		needleHash = (needleHash * power[l2-1]) % m;
		for(int i = 0; i <= l2-l1; i++) {
			ll curHash = (prefixHash[i+l1] + m - prefixHash[i]) % m;
			curHash = (curHash * power[l2-1 - i]) % m; 

			if(curHash == needleHash) indices.push_back(i);
		}
		return indices;
	}
};









int main(int argc, char** argv) {
#ifdef LOCAL
    file_io
#endif
    fast_io
    time__("whole code") {
    



    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vi a(n+1, 0), b(n+1, 0);
    rep(i, n) {
    	a[i+1] = str[i] == 'a' ? a[i] + 1 : a[i], b[i+1] = str[i] == 'b' ? b[i] + 1 : b[i];
    }
    int lo = 1, hi = n, beauty = INT_MIN;
    while(lo <= hi) {
    	int mid = lo + (hi-lo)/2;
    	bool okay = false;
    	for(int i = 0; i <= n-mid; i++) {
    		int ac = a[i+mid] - a[i], bc = b[i+mid] - b[i];
    		

    		if(min(ac, bc) <= k) {
    			okay = true;
    			break;
    		}
    	}
    	if(okay) {
    		beauty = mid;
    		lo = mid + 1;
    	} else {
    		hi = mid - 1;
    	}
    }
    	
    cout << beauty << endl;
	   
    

	} 
    return 0;
}