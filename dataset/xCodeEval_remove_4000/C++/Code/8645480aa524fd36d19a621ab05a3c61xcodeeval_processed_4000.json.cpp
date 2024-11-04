

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<string> vs;

constexpr int oo = 0x3f3f3f3f;
constexpr ll ooo = 0x3f3f3f3f3f3f3f3fLL;
constexpr double eps = 1e-7;
constexpr double PI = 2.0 * acos(0.0);













template<typename T> T sq(const T& a) { return a*a; }

template<typename...Ts>
tuple<Ts...> rd() {
	tuple<Ts...> res;
	apply([&](Ts &... ta) { ((cin >> ta), ...); }, res);
	return res;
}

template<typename T>
ostream& operator<<(ostream&, const vector<T>&);
template<typename... Ts>
ostream& operator<<(ostream&, tuple<Ts...> const&);
template<typename A, typename B>
ostream& operator<<(ostream&, pair<A,B>const&);

template<typename T>
ostream& operator<<(ostream&out, const vector<T>& v) {
	out << "{";
	for(ll i=0; i<sz(v); i++) out << (i>0 ? ", " : "") << v[i];
	return out << "}";
}
template<typename... Ts>
ostream& operator<<(ostream& os, tuple<Ts...> const& theTuple) {
	apply([&os](Ts const&... ta) {
		size_t n{0};
		((os << (n++ != 0 ? ", " : "(") << ta), ...);
		os << ')';
	}, theTuple);
	return os;
}
template<typename A, typename B>
ostream& operator<<(ostream& out, pair<A,B>const& p) {
	return out << "<" << p.first << "," << p.second << ">";
}

constexpr ll MAXN = 100100;

vll adj[MAXN]; 

ll curpre=0; 

bool articulation[MAXN]; 

ll num[MAXN];
vector<ll> st;

vll newAdj[MAXN];



ll id1(ll i, ll pa){
	ll me = num[i] = ++curpre, top = me, cc = 0;
	bool isan = false;
	for(auto j : adj[i])
		if(pa != j){
			if(num[j]){
				top = min(top,num[j]);
				

				

				

				

			} else {
				cc++;
				

				ll up = id1(j, i);
				isan |= pa != -1 && up >= me;
				top = min(top, up);
				if(up == me){
					

					

				} else if(up < me){
					

					

				} else {
					

					newAdj[i].emplace_back(j);
					newAdj[j].emplace_back(i);
				}
			}
		}
	isan |= pa==-1 && cc>=2;
	articulation[i] = isan;
	return top;
}


void id0(ll n){
	curpre = 0;
	st.clear();
	fill_n(num,n,0);
	for(ll i=0; i<n; i++)
		if(num[i]==0)
			id1(i,-1);
}

struct ResList {
	variant<pair<pll, ResList*>, pair<ResList*,ResList*>> dat;
	ll sz = 0;
};
ResList* concat(ResList* a, ResList* b) {
	if(!a) return b;
	if(!b) return a;
	return new ResList { .dat = MP(a,b), .sz = a->sz + b->sz };
}
ResList* appendEdge(ResList* a, pll b) {
	return new ResList { .dat = MP(b, a), .sz = 1 + (a ? a->sz : 0ll) };
}
ll getSz(const ResList* a) {
	if(a) return a->sz;
	else return 0;
}
bool lt(const ResList* a, const ResList* b) {
	return getSz(a) < getSz(b);
}
ResList* mmin(ResList* a, ResList* b) {
	return lt(a,b) ? a : b;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

	ll n,m;
	while(cin >> n >> m && n > 0) {
		for(ll i=0; i<n; i++) adj[i].clear(), newAdj[i].clear();

		while(m-->0) {
			auto[s]=rd<ll>();
			auto[p]=rd<ll>(); s--, p--;
			while(s-->0) {
				auto[n]=rd<ll>(); n--;
				adj[n].emplace_back(p);
				adj[p].emplace_back(n);
				p = n;
			}
		}

		for(ll i=0; i<n; i++) {
			

		}

		id0(n);
		const ll numNodes = n;

		vector<bool> vis(n, false);
		using T = pair<ll,ResList*>; 

		const auto sizeT = [](const T& a) -> ll {
			return getSz(a.second);
		};
		using TT = array<T,3>;
		const auto id2 = [](const TT& a) -> const T& {
			if(lt(a[0].second, a[1].second))
				return lt(a[0].second, a[2].second) ? a[0] : a[2];
			else
				return lt(a[1].second, a[2].second) ? a[1] : a[2];
		};
		ResList* illegal = new ResList { .dat = MP(nullptr, nullptr), .sz = oo };
		const function<TT(ll,ll)> dp = [&](ll i, ll pa) {
			assert(!vis[i]);
			vis[i] = true;

			vll children;
			children.reserve(sz(newAdj[i]));
			for(ll j : newAdj[i]) if(j != pa) children.emplace_back(j);

			const ll n = sz(children);

			

			

			


			vector<TT> childDat;
			for(ll j : children)
				childDat.emplace_back(dp(j,i));
			
			TT res({MP(-1,illegal), MP(-1,illegal), MP(-1,illegal)});

			sort(all(childDat), [&](const TT& a, const TT& b) {
				return
					((2*min(sizeT(a[2]),sizeT(a[1])) + 2) - (1 + 2*min({sizeT(a[0]),sizeT(a[1]),sizeT(a[2])}))) >
					((2*min(sizeT(b[2]),sizeT(b[1])) + 2) - (1 + 2*min({sizeT(b[0]),sizeT(b[1]),sizeT(b[2])})));
			});

			{ 

				if(n%2 == 0 || sizeT(childDat.back()[2]) <= 2*numNodes) {
					

	
					if(n%2==0) res[0] = MP(i, nullptr);
					else {
						const ll bI = (sizeT(childDat.back()[2]) < sizeT(childDat.back()[1]))
										? 2 : 1;
						res[0] = MP(i, appendEdge(childDat.back()[bI].second,
												  pll(i, childDat.back()[bI].first)));
					}

					for(ll i=0; i+1<n; i+=2) {
						const auto tI = id2(childDat[i]);
						const auto tJ = id2(childDat[i+1]);
						res[0].second = appendEdge(
							concat(res[0].second, concat(tI.second, tJ.second)),
							MP(tI.first, tJ.first));
					}
				}
			}

			{ 

				ll combSize = (n-1)/2;
				for(ll i = 0; i < n; i++)
					combSize += sizeT(id2(childDat[i]));
				
				pll opt(oo, -1);
				for(ll i=0; i<n; i++) {
					ll val = sizeT(childDat[i][0]) - sizeT(id2(childDat[i]));
					if(n%2==0) {
						

						if(i == n-1)	val += 1 + min(sizeT(childDat[n-2][2]), sizeT(childDat[n-2][1])) - sizeT(id2(childDat[n-2]));
						else			val += 1 + min(sizeT(childDat[n-1][2]), sizeT(childDat[n-1][1])) - sizeT(id2(childDat[n-1]));
					}
					opt = min(opt, MP(val, i));
				}

				if(opt.first <= 2*numNodes) {
					

					res[1] = childDat[opt.second][0];
					ll other = -1;
					if(n%2 == 0) {
						other = (opt.second == n-1 ? n-2 : n-1);
						const ll bI = (sizeT(childDat[other][2]) < sizeT(childDat[other][1]))
									? 2 : 1;
						res[1].second = appendEdge(concat(res[1].second, childDat[other][bI].second),
												MP(i, childDat[other][bI].first));
					}
					for(ll i=0; i<n; i++) {
						while(i<n && (i==opt.second || i==other)) i++;
						if(i >= n) break;
						ll j = i+1;
						while(j<n && (j==opt.second || j==other)) j++;
						assert(j < n);

						res[1].second = concat(
									appendEdge(res[1].second, MP(id2(childDat[i]).first, id2(childDat[j]).first)),
									concat(id2(childDat[i]).second, id2(childDat[j]).second));

						i = j;
					}

					assert(opt.first + combSize == sizeT(res[1]));
				}
			}

			{ 

				const auto doubleVal = [&](ll i) { return sizeT(id2(childDat[i])) * 2 + 1; };

				sort(all(childDat), [&](const TT& a, const TT& b) {
					return
						((2*min({sizeT(a[2]),sizeT(a[1]),sizeT(a[0])-1}) + 2) - (1 + 2*min({sizeT(a[0]),sizeT(a[1]),sizeT(a[2])}))) >
						((2*min({sizeT(b[2]),sizeT(b[1]),sizeT(b[0])-1}) + 2) - (1 + 2*min({sizeT(b[0]),sizeT(b[1]),sizeT(b[2])})));
				});

				ll combSize = 0;
				for(ll i = 0; i < n; i++)
					combSize += doubleVal(i);
				
				pll opt(oo, -1);
				for(ll i=0; i<n; i++) {
					ll val = combSize + 
						2*min(sizeT(childDat[i][1]), sizeT(childDat[i][2]))
								 - doubleVal(i);
					if(n%2==0) {
						

						const ll other = (i==n-1) ? n-2 : n-1;
						val += 2 + 2 * min({sizeT(childDat[other][2]), sizeT(childDat[other][1]), sizeT(childDat[other][0])-1}) - doubleVal(other);
					}
					opt = min(opt, MP(val, i));
				}

				if(opt.first <= 4*numNodes) {
					

					const auto& cD = childDat[opt.second];
					ll oI = sizeT(cD[1]) < sizeT(cD[2]) ? 1 : 2;
					res[2] = cD[oI];

					ll other = -1;
					if(n%2 == 0) {
						other = (opt.second == n-1 ? n-2 : n-1);
						ll bI = (sizeT(childDat[other][2]) < sizeT(childDat[other][1]))
									? 2 : 1;
						if(sizeT(childDat[other][0]) < sizeT(childDat[other][bI]) + 1) {
							bI = 0;
							res[2].second = concat(res[2].second, childDat[other][bI].second);
						} else {
							res[2].second = appendEdge(concat(res[2].second, childDat[other][bI].second),
													MP(i, childDat[other][bI].first));
						}
					}
					for(ll i=0; i<n; i++) {
						while(i<n && (i==opt.second || i==other)) i++;
						if(i >= n) break;
						ll j = i+1;
						while(j<n && (j==opt.second || j==other)) j++;
						assert(j < n);

						res[2].second = concat(
									appendEdge(res[2].second, MP(id2(childDat[i]).first, id2(childDat[j]).first)),
									concat(id2(childDat[i]).second, id2(childDat[j]).second));

						i = j;
					}

					

					assert(opt.first % 2 == 0);
					assert(opt.first/2 == sizeT(res[2]));
				}
			}
			if(sizeT(res[2]) + 1 < sizeT(res[0])) {
				res[0] = MP(i, appendEdge(res[2].second, MP(res[2].first, i)));
			}

			if(n%2==0 && n>=2) { 

				sort(all(childDat), [&](const TT& a, const TT& b) {
					return
						((2*sizeT(a[0])) - (1 + 2*min({sizeT(a[0]),sizeT(a[1]),sizeT(a[2])}))) >
						((2*sizeT(b[0])) - (1 + 2*min({sizeT(b[0]),sizeT(b[1]),sizeT(b[2])})));
				});

				ll combSize = (n-2)/2;
				for(ll i = 0; i < n-2; i++)
					combSize += sizeT(id2(childDat[i]));

				ll opt = sizeT(childDat.back()[0]) + sizeT(childDat[n-2][0]);

				if(opt <= 2*numNodes) {
					

					T tmpRes = childDat.back()[0];
					tmpRes.second = concat(tmpRes.second, childDat[n-2][0].second);

					for(ll i=0; i<n-2; i+=2) {
						tmpRes.second = concat(
							appendEdge(tmpRes.second, MP(id2(childDat[i]).first, id2(childDat[i+1]).first)),
							concat(id2(childDat[i]).second, id2(childDat[i+1]).second));
					}

					assert(opt + combSize == sizeT(tmpRes));

					if(sizeT(tmpRes) < sizeT(res[2]))
						res[2] = tmpRes;
					if(sizeT(tmpRes) + 1 < sizeT(res[0]))
						res[0] = MP(i, appendEdge(tmpRes.second, MP(childDat.back()[0].first, childDat[n-2][0].first)));
				}
			}

			

			

			

			

			


			return res;
		};

		ResList* res = nullptr;
		for(ll i=0; i<n; i++)
			if(!vis[i]) {
				const auto v = dp(i,-1);
				res = concat(res, mmin(v[1].second, v[0].second));
			}

		cout << getSz(res) << '\n';
		const function<void(ResList*)> print = [&](ResList* l) {
			if(!l) return;
			if(l->dat.index() == 0) {
				const auto [e,x] = get<0>(l->dat);
				cout << (e.first+1) << ' ' << (e.second+1) << '\n';
				print(x);
			} else {
				const auto[a,b] = get<1>(l->dat);
				print(a);
				print(b);
			}
		};
		print(res);
	}

	return 0;
}
