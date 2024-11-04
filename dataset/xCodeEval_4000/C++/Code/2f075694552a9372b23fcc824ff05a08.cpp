#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define ld long double
#define ull unsigned long long
#define vi vector<ll>
#define pii pair<ll,ll>
#define vii vector<pii>
#define mp make_pair
#define pb push_back
#define rep(n) for(long i=0;i<n;i++)
#define fori(i,a,b) for(auto i=a;i<=b;i++)
#define ford(i,b,a) for(auto i=b;i>=a;i--)
#define mset(a,i) memset(a,i,sizeof(a))
#define maxheap(v) priority_queue<v>
#define minheap(v) priority_queue<v, vector<v>, greater<v>>
#define ff first
#define ss second
#define endl "\n"
#define NL cout<<endl;
#define all(v) v.begin(),v.end()
#define len(s) (ll)(s.length())
#define sz(v) (ll)(v.size())
#define fast_io() cin.sync_with_stdio(false);cout.sync_with_stdio(false);cin.tie(NULL);
#define tests ll testcases;cin>>testcases;while(testcases--)
#define PI 3.1415926535
#define mod (ll)(1e9+7)
#define mod2 998244353


#define TRACE
#ifdef TRACE
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define deb(...)
#endif

inline ll sbt(ll x) {return __builtin_popcountll(x); }
inline ll iceil(double a) { return (ll)(ceil(a)); }

inline ll mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
inline ll add(ll a, ll b, ll m = mod) { return (a + b) % m; }
inline ll sub(ll a, ll b, ll m = mod) { return (a - b + m) % m; }

ll fastpow(ll a, ll b, ll m = mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return res;
}



ll modinv(ll a, ll m = mod) {
    return fastpow(a, m - 2, m);
}








ll n, m, k;
vector<pair<ll, pair<ll, ll>>> v;

vector<pii> both, alice, bob, none;

void get_ac() {
    cin >> n >> m >> k;
    ll a, b, c, ca = 0, cb = 0;
    fori(i, 1, n) {
        cin >> a >> b >> c;
        if (b == 1 && c == 1) {
            both.pb({a, i});
            ca++; cb++;
        }
        else if (b == 1) {
            alice.pb({a, i});
            ca++;
        }
        else if (c == 1) {
            bob.pb({a, i});
            cb++;
        }
        else {
            none.pb({a, i});
        }
    }
    if (ca < k || cb < k) {
        cout << -1;
        return;
    }
    sort(all(alice));
    sort(all(bob));
    sort(all(both));
    sort(all(none));
    ll inone, iboth = 0, ialice = 0, ibob = 0;
    ll nboth = sz(both), nalice = sz(alice), nbob = sz(bob), nnone = sz(none);

    ll ans = 0, books = 0;
    set<ll> indices;
    ll kk = min({k, nalice, nbob});
    rep(kk) {
        ans += alice[i].ff;
        books++;
        indices.insert(alice[i].ss);
    }
    rep(kk) {
        ans += bob[i].ff;
        books++;
        indices.insert(bob[i].ss);
    }
    rep(k - kk) {
        ans += both[i].ff;
        books++;
        indices.insert(both[i].ss);
    }
    int i = kk - 1;
    iboth = k - kk;
    while (iboth < nboth && i >= 0 && alice[i].ff + bob[i].ff > both[iboth].ff) {
        ans -= alice[i].ff + bob[i].ff - both[iboth].ff;
        indices.erase(alice[i].ss);
        indices.erase(bob[i].ss);
        indices.insert(both[iboth].ss);
        i--;
        iboth++;
        books--;
    }

    if (books == m) {
        cout << ans; NL
        assert(sz(indices) == m);
        for (auto i : indices) {
            cout << i << " ";
        }
        return;
    }
    else if (books > m) {
        while (books > m && iboth < nboth && i >= 0) {
            ans -= alice[i].ff + bob[i].ff - both[iboth].ff;
            books--;
            indices.erase(alice[i].ss);
            indices.erase(bob[i].ss);
            indices.insert(both[iboth].ss);
            i--;
            iboth++;
        }

        

        


        

        

        ialice = i, ibob = i;

        

        while (1) {
            if (ialice >= 0 && ibob >= 0 && iboth < nboth && alice[ialice].ff > both[iboth].ff && bob[ibob].ff > both[iboth].ff) {
                if (alice[ialice] > bob[ibob]) {
                    

                    ans -= bob[ibob].ff - both[iboth].ff;
                    indices.erase(bob[ibob].ss);
                    indices.insert(both[iboth].ss);
                    ibob--;
                    iboth++;
                }
                else {
                    ans -= alice[ialice].ff - both[iboth].ff;
                    indices.erase(alice[ialice].ss);
                    indices.insert(both[iboth].ss);
                    ialice--;
                    iboth++;
                }
            }
            else if (ialice >= 0 && iboth < nboth && alice[ialice].ff > both[iboth].ff) {
                ans -= alice[ialice].ff - both[iboth].ff;
                indices.erase(alice[ialice].ss);
                indices.insert(both[iboth].ss);
                ialice--;
                iboth++;
            }
            else if (ibob >= 0 && iboth < nboth && bob[ibob].ff > both[iboth].ff) {
                ans -= bob[ibob].ff - both[iboth].ff;
                indices.erase(bob[ibob].ss);
                indices.insert(both[iboth].ss);
                ibob--;
                iboth++;
            }
            else {
                break;
            }
        }

        

        


        

        while (1) {
            if (iboth - 1 >= 0 && ialice + 1 < nalice && ibob + 1 < nbob && alice[ialice + 1].ff < both[iboth - 1].ff && bob[ibob + 1].ff < both[iboth - 1].ff) {
                if (alice[ialice + 1] < bob[ibob + 1]) {
                    

                    if (ibob + 1 + iboth - 1 >= k) {
                        ans += alice[ialice + 1].ff - both[iboth - 1].ff;
                        indices.insert(alice[ialice + 1].ss);
                        indices.erase(both[iboth - 1].ss);
                        ialice++;
                        iboth--;
                    }
                    else if (ialice + 1 + iboth - 1 >= k) {
                        ans += bob[ibob + 1].ff - both[iboth - 1].ff;
                        indices.insert(bob[ibob + 1].ss);
                        indices.erase(both[iboth - 1].ss);
                        ibob++;
                        iboth--;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (ialice + 1 + iboth - 1 >= k) {
                        ans += bob[ibob + 1].ff - both[iboth - 1].ff;
                        indices.insert(bob[ibob + 1].ss);
                        indices.erase(both[iboth - 1].ss);
                        ibob++;
                        iboth--;
                    }
                    else if (ibob + 1 + iboth - 1 >= k) {
                        ans += alice[ialice + 1].ff - both[iboth - 1].ff;
                        indices.insert(alice[ialice + 1].ss);
                        indices.erase(both[iboth - 1].ss);
                        ialice++;
                        iboth--;
                    }
                    else {
                        break;
                    }
                }
            }
            else if (iboth - 1 >= 0 && ialice + 1 < nalice && alice[ialice + 1].ff < both[iboth - 1].ff && ibob + 1 + iboth - 1 >= k) {
                ans += alice[ialice + 1].ff - both[iboth - 1].ff;
                indices.insert(alice[ialice + 1].ss);
                indices.erase(both[iboth - 1].ss);
                ialice++;
                iboth--;
            }
            else if (iboth - 1 >= 0 && ibob + 1 < nbob && bob[ibob + 1].ff < both[iboth - 1].ff && ialice + 1 + iboth - 1 >= k) {
                ans += bob[ibob + 1].ff - both[iboth - 1].ff;
                indices.insert(bob[ibob + 1].ss);
                indices.erase(both[iboth - 1].ss);
                ibob++;
                iboth--;
            }
            else {
                break;
            }
        }

        if (books > m) {
            cout << -1;
        }
        else {
            cout << ans; NL
            assert(sz(indices) == m);
            for (auto i : indices) {
                cout << i << " ";
            }
        }
        return;
    }
    else {
        

        

        


        

        ialice = i;
        ibob = i;
        inone = -1;
        iboth = iboth - 1;

        while (books < m) {
            vector<pair<pii, ll>> candidates;
            bool f = 0;
            if (inone + 1 < sz(none)) {
                candidates.pb({none[inone + 1], 0});
            }
            if (ialice + 1 < sz(alice)) {
                candidates.pb({alice[ialice + 1], 1});
            }
            if (ibob + 1 < sz(bob)) {
                candidates.pb({bob[ibob + 1], 2});
            }
            if (iboth + 1 < sz(both)) {
                candidates.pb({both[iboth + 1], 3});
            }
            if (sz(candidates) == 0) break;
            sort(all(candidates));
            if (ibob + 1 < sz(bob) && ialice + 1 < sz(alice) && iboth >= 0) {
                ll cur = bob[ibob + 1].ff + alice[ialice + 1].ff - both[iboth].ff;
                if (cur > candidates[0].ff.ff) {
                    

                }
                else {
                    f = 1;
                    ans += cur;
                    indices.insert(bob[ibob+1].ss);
                    indices.insert(alice[ialice+1].ss);
                    indices.erase(both[iboth].ss);
                    ialice++;
                    ibob++;
                    iboth--;
                }
            }
            if (!f) {
                

                pii p = candidates[0].ff;
                ll q = candidates[0].ss;
                ans += p.ff;
                indices.insert(p.ss);

                if (q == 0) {
                    inone++;
                }
                else if (q == 1) {
                    ialice++;
                }
                else if (q == 2) {
                    ibob++;
                }
                else {
                    iboth++;
                }
            }

            books++;
        }

        assert(sz(indices) == m);
        

        

        

        iboth++;

        


        while (1) {
            if (ialice >= 0 && ibob >= 0 && iboth < nboth && alice[ialice].ff > both[iboth].ff && bob[ibob].ff > both[iboth].ff) {
                if (alice[ialice] > bob[ibob]) {
                    

                    ans -= bob[ibob].ff - both[iboth].ff;
                    indices.erase(bob[ibob].ss);
                    indices.insert(both[iboth].ss);
                    ibob--;
                    iboth++;
                }
                else {
                    ans -= alice[ialice].ff - both[iboth].ff;
                    indices.erase(alice[ialice].ss);
                    indices.insert(both[iboth].ss);
                    ialice--;
                    iboth++;
                }
            }
            else if (ialice >= 0 && iboth < nboth && alice[ialice].ff > both[iboth].ff) {
                ans -= alice[ialice].ff - both[iboth].ff;
                indices.erase(alice[ialice].ss);
                indices.insert(both[iboth].ss);
                ialice--;
                iboth++;
            }
            else if (ibob >= 0 && iboth < nboth && bob[ibob].ff > both[iboth].ff) {
                ans -= bob[ibob].ff - both[iboth].ff;
                indices.erase(bob[ibob].ss);
                indices.insert(both[iboth].ss);
                ibob--;
                iboth++;
            }
            else {
                break;
            }
        }

        assert(sz(indices) == m);
        


        while (1) {
            if (iboth - 1 >= 0 && ialice + 1 < nalice && ibob + 1 < nbob && alice[ialice + 1].ff < both[iboth - 1].ff && bob[ibob + 1].ff < both[iboth - 1].ff) {
                if (alice[ialice + 1] < bob[ibob + 1]) {
                    

                    if (ibob + 1 + iboth - 1 >= k) {
                        ans += alice[ialice + 1].ff - both[iboth - 1].ff;
                        indices.insert(alice[ialice + 1].ss);
                        indices.erase(both[iboth - 1].ss);
                        ialice++;
                        iboth--;
                    }
                    else if (ialice + 1 + iboth - 1 >= k) {
                        ans += bob[ibob + 1].ff - both[iboth - 1].ff;
                        indices.insert(bob[ibob + 1].ss);
                        indices.erase(both[iboth - 1].ss);
                        ibob++;
                        iboth--;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (ialice + 1 + iboth - 1 >= k) {
                        ans += bob[ibob + 1].ff - both[iboth - 1].ff;
                        indices.insert(bob[ibob + 1].ss);
                        indices.erase(both[iboth - 1].ss);
                        ibob++;
                        iboth--;
                    }
                    else if (ibob + 1 + iboth - 1 >= k) {
                        ans += alice[ialice + 1].ff - both[iboth - 1].ff;
                        indices.insert(alice[ialice + 1].ss);
                        indices.erase(both[iboth - 1].ss);
                        ialice++;
                        iboth--;
                    }
                    else {
                        break;
                    }
                }
            }
            else if (iboth - 1 >= 0 && ialice + 1 < nalice && alice[ialice + 1].ff < both[iboth - 1].ff && ibob + 1 + iboth - 1 >= k) {
                ans += alice[ialice + 1].ff - both[iboth - 1].ff;
                indices.insert(alice[ialice + 1].ss);
                indices.erase(both[iboth - 1].ss);
                ialice++;
                iboth--;
            }
            else if (iboth - 1 >= 0 && ibob + 1 < nbob && bob[ibob + 1].ff < both[iboth - 1].ff && ialice + 1 + iboth - 1 >= k) {
                ans += bob[ibob + 1].ff - both[iboth - 1].ff;
                indices.insert(bob[ibob + 1].ss);
                indices.erase(both[iboth - 1].ss);
                ibob++;
                iboth--;
            }
            else {
                break;
            }
        }

        assert(sz(indices) == m);
        


        while (1) {
            vector<pii> candidates;
            if (inone + 1 < nnone && ialice >= 0 && (ialice + 1 + iboth) > k && none[inone + 1].ff < alice[ialice].ff) {
                candidates.pb({none[inone + 1].ff - alice[ialice].ff, 0});
            }
            if (inone + 1 < nnone && ibob >= 0 && (ibob + 1 + iboth) > k && none[inone + 1].ff < bob[ibob].ff) {
                candidates.pb({none[inone + 1].ff - bob[ibob].ff, 1});
            }
            

            if (sz(candidates) == 0) break;
            sort(all(candidates));
            if (sz(candidates) == 2 && iboth - 1 >= 0 && none[inone + 1].ff - both[iboth - 1].ff < candidates[0].ff) {
                ll curcandidate = none[inone + 1].ff - both[iboth - 1].ff;
                ans += curcandidate;
                indices.erase(both[iboth - 1].ss);
                indices.insert(none[inone + 1].ss);
                iboth--;
                inone++;
            }
            else {
                if (candidates[0].ff == 0) {
                    ans += candidates[0].ff;
                    indices.erase(alice[ialice].ss);
                    indices.insert(none[inone + 1].ss);
                    ialice--;
                    inone++;
                }
                else {
                    ans += candidates[0].ff;
                    indices.erase(bob[ibob].ss);
                    indices.insert(none[inone + 1].ss);
                    ibob--;
                    inone++;
                }
            }

        }

        


        if (books < m) {
            cout << -1;
        }
        else {
            cout << ans; NL
            assert(sz(indices) == m);
            for (auto i : indices) {
                cout << i << " ";
            }
        }
        return;
    }
}

int main() {
    fast_io()










    

    {
        get_ac();
        NL
    }

    return 0;
}