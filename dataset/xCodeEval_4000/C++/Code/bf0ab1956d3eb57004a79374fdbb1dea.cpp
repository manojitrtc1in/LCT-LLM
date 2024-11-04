



#include <bits/stdc++.h>
#define gc getchar
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define rep2(i, a, b) for(int i=a;i>=b;--i)
#define wipe(a, b) memset(a, b, sizeof a);
#define pb push_back
#define ff first
#define ss second



using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int maxn = 1e5 + 10;
piii edges[maxn];
vector<int> grafo[maxn], grafo2[maxn];
int n, m;
int pesos[maxn], grau[maxn], mark[maxn];
int cont=0;
map<pii, vector<int>> mapa;

inline int scan(){
	int n=0, x=gc(), s=1;
	for(;x<'0'||x>'9';x=gc()) if(x=='-') s=-1;
	for(;x>='0'&&x<='9';x=gc()) n = 10*n + x - '0';
	return n*s;
}

int gcd(int a, int b){
	return (b?gcd(b, a%b):a);
}

bool check() {
	for(int i=1;i<=m;i++) {
		int u = edges[i].ff.ff;
		int v = edges[i].ff.ss;

			grafo[u].push_back(v), grau[v]++;
	}

	vector<int> fila;
	int id = 0;
	for(int i=1;i<=n;i++)
		if(grau[i] == 0) fila.push_back(i);

	while(id < fila.size()) {
		int u = fila[id++];

		for(auto v : grafo[u]) {
			grau[v]--;
			if(grau[v] == 0){
				fila.push_back(v);
			}
		}
	}

	return (fila.size() == n);
}

int32_t main(){
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;

	for(int i=1;i<=m;i++){
		int a, b, c;
		cin >> a >> b >> c;
		edges[i] = {{a, b}, c};
		pesos[i] = c;
		mapa[{a, b}].push_back(i);
	}

	if(check()) {
		cout << "0 0\n";
		return 0;
	}
	sort(pesos+1, pesos+m+1);
	int ini=0, fim=m, meio;
	while(fim - ini > 1) {
		meio = (ini + fim) >> 1;
		int k = pesos[meio];

		for(int i=1;i<=n;i++) {
			grafo[i].clear(), grau[i] = 0;
		}

		for(int i=1;i<=m;i++) {
			int u = edges[i].ff.ff;
			int v = edges[i].ff.ss;

			if(edges[i].ss > k){
				grafo[u].push_back(v), grau[v]++;
			}
		}

		vector<int> fila;
		int id = 0;
		for(int i=1;i<=n;i++)
			if(grau[i] == 0) fila.push_back(i);

		while(id < fila.size()) {
			int u = fila[id++];

			for(auto v : grafo[u]) {
				grau[v]--;
				if(grau[v] == 0){
					fila.push_back(v);
				}
			}
		}

		if(fila.size() == n) fim = meio;
		else {
			ini = meio;
		}
	}
	int k = pesos[fim];

	for(int i=1;i<=n;i++) {
		grafo[i].clear(), grau[i] = 0;
	}

	vector<int> rrr;
	for(int i=1;i<=m;i++) {
		int u = edges[i].ff.ff;
		int v = edges[i].ff.ss;

		if(edges[i].ss > k){
			grafo[u].push_back(v), grau[v]++;
		}else {
			grafo2[u].push_back(v);
			grafo2[v].push_back(u);
		}
	}

	vector<int> fila;
	int id = 0;
	for(int i=1;i<=n;i++)
		if(grau[i] == 0) fila.push_back(i);

	while(id < fila.size()) {
		int u = fila[id++];

		for(auto v : grafo[u]) {
			grau[v]--;
			if(grau[v] == 0){
				fila.push_back(v);
			}
		}

		for(auto v : grafo2[u]) {
			auto a_ = mapa[{u, v}], b_ = mapa[{v, u}];
			int a = a_.size(), b = b_.size();

			int c = (a?a_[0]:b_[0]);
			if(mark[c]) continue;

			if(a && b) {
				for(auto b2 : b_)
					if(edges[b2].ss <= k) rrr.push_back(b2);
			}

			else{
				for(auto b2 : b_) {
					if(b2) rrr.push_back(b2);
				}
			}
			if(a){
				for(auto& e : a_)
					mark[e] = true;
			}
			if(b) {
				for(auto& e : b_)
					mark[e] = true;
			}
		}
	}


	cout << k << " " << rrr.size() << "\n";
	for(auto& e : rrr) cout << e << " ";
	cout << "\n";
	


	return 0;
}