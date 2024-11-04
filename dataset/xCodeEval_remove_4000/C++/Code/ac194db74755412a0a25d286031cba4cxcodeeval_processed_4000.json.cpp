

using namespace std;
using namespace __gnu_pbds;

using ll=long long; using ld=long double; using vi=vector<int>; using vl=vector<ll>; using vs=vector<string>;
using pii=pair<int, int>;  using vii=vector<pii>; using pll=pair<ll, ll>; using vll=vector<pll>;
using mii=map<int, int>; using mll=map<ll, ll>; using msi=map<string, ll>; using vvi=vector< vi >;
template <typename T> using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;















                string _s = 
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





for ( \
    auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
    blockTime.second; \
    debug("%s: %.4lf s\n", d, (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count())/1e3), blockTime.second = false \
)



namespace UtilSpace {

    vii dir_4 { {1,0}, {0,1}, {-1,0}, {0,-1} };
    vii id7 { {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1} };
    vii id11 { {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1} };

    bool checkBit(int n, int pos) { return (n & (1<<pos)) != 0; }
    int setBit(int n, int pos) {return (n | (1<<(pos))); }
    int resetBit(int n, int pos) { return (n & ~(1 << pos)); }
    void printBits(int n){ if(n >= 2)printBits(n/2); cout<<(n&1); }
    int id8(int n) { int r=0; while(n && ++r) n -= n & -n; return r; }
    bool id2(int n) { return n && !(n & (n - 1)); }

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
    T id4(T a, T b, T& x, T& y) {
        if(!b){ x = 1, y = 0; return a; }
        T x1, y1, temp = id4<T>(b, a%b, x1, y1);
        x = y1, y = x1 - y1*(a/b);
        return temp;
    }

    template< typename T >
    T modInverse(T a, T m){ T x, y; T g = id4<T>(a, m, x, y); if(g != 1){ return -1; } else{ return (x%m + m)%m; } }


    const unsigned int M = 2e8+2;

    int status[(M>>6) + 7] = {0};
    bitset<500000002> id1;
    
    

    

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

    

    vector<ll> id3(const ll& a, const ll& b) {
        int x = floor(sqrt(b*1.0)) + 1;
        vector<int> id9 = sieve(x);
        const int range(b - a + 1);
        id1.reset();

        for (int& curPrime : id9) {
            if(curPrime == 2) continue; 

            

            ll start = max((curPrime * curPrime * 1LL), (((a + curPrime - 1LL) / curPrime) * curPrime));
            start = (start & 1LL)? start : start + curPrime; 

            for (int i = start - a; i < range; i += curPrime<<1LL) {
                id1.set(i>>1);
            }
        }
        vl id6;
        if (a <= 2 && b >= 2) { id6.push_back(2LL); }
        for (int k = (a & 1) ? 0 : 1; k < range; k += 2) {
            if (!id1.test(k>>1) && a+k != 1) {
                id6.push_back((ll)a+k);
            }
        }
        return id6;
    }

    bool id13(const ll& n, const ll& l, const ll& r) {
        return n>=l && n<=r && (n==2 || (n>2 && (n&1LL) && !id1.test((n-l)>>1LL)));
    }

    

    

    vector<int> id3(const int& n) {
        int x = floor(sqrt(n))+1;
        vector<int> id9 = sieve(x), primes;
        for(auto & p : id9) if(p*p<=n)primes.push_back(p);
        int a = x, b = 2*x; 

        bitset<16000> ps;
        while(a < n) {
            ps.reset();
            b = b >= n ? n : b; 

            const int range(b - a + 1);
            for (int& curPrime : id9) {
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


    

    

    tuple<vll, ll, ll> id0(const ll& num, const vi& id9) {
        ll n = num, factorSum = 1, factorCount = 1;;
        vll id10;
        for(const int& smallPrime : id9) {
            if(smallPrime * smallPrime * 1LL <= n && !(n % smallPrime)) {
                ll pc = 0;
                while(!(n % smallPrime)) { n /= smallPrime, ++pc; }
                id10.emplace_back(smallPrime, pc);
                factorSum *= (bigPow(smallPrime, pc+1) - 1) / (smallPrime - 1LL); 

                factorCount *= (pc+1);  

            }
        }
        

        if(n > 1) {
           id10.emplace_back(n, 1LL);
           factorSum *= (bigPow(n, 2) - 1) / (n - 1LL); 

           factorCount *= 2LL; 

        }
        return make_tuple(id10, factorSum, factorCount);
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

	

    vvi id5(vs const& strings) {
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

	

	

    int id12(string const& str) {
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

    file_io

    fast_io
    time__("whole code") {
    



    	int n, k; string str; cin >> n >> k >> str;
    	int a[n+1], b[n+1];
    	foab(i, 0, n) if(!i) a[i] = b[i] = 0; else a[i] = str[i-1]=='a'? a[i-1]+1: a[i-1], b[i] = str[i-1]=='b'? b[i-1]+1: b[i-1];
    	int ans = 0, lo = 0, hi = 0;
    	
    	
    	while(lo <= hi && hi < n) {
    		int ac = a[hi+1] - a[lo], bc = b[hi+1] - b[lo];
    		if(min(ac, bc) <= k) {
    			ans = max(ans, hi-lo+1);
    			hi++;
    		} else {
    			lo++;
    		}

    	}
    
	   	cout << ans << endl;


    

	} 
    return 0;
}
