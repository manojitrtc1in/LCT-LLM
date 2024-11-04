


















































































































































































































































































using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, m;
typedef vector< vector<string> > matrix;
vector< pair<ii,ii> > ans;
bool invert;

void print(matrix &mat) {
	for(auto vs : mat) {
		for(string s : vs) {
			printf("|%6s| ", s.c_str());
		}
		cout << endl;
	}
}

void move(int si, int sj, int ti, int tj) {
	assert(si != ti || sj != tj);
	if (si != ti && sj != tj) {
		move(si, sj, si, tj);
		move(si, tj, ti, tj);
	}
	else ans.pb({{si+1, sj+1}, {ti+1, tj+1}});
}

void clean(matrix &mat, int i, int j) {
	if (invert) reverse(all(mat[i][j]));
	for(char c : mat[i][j]) {
		if (c == '1') {
			move(i, j, 0, 1);
			mat[0][1].pb(c);
		}
		if (c == '0') {
			move(i, j, 0, 0);
			mat[0][0].pb(c);
		}
	}
	mat[i][j].clear();
}

void simulate(matrix mat) {

	printf("\npart 1:\n");
	print(mat);
	int cnt = 0;
	int n = ans.size();
	assert(!ans.empty());
	for(auto p : ans) {

		int si = p.fi.fi-1;
		int sj = p.fi.se-1;
		int ti = p.se.fi-1;
		int tj = p.se.se-1;
		assert(!mat[si][sj].empty());
		char c = mat[si][sj].back();
		mat[si][sj].pop_back();
		string aux;
		aux.pb(c);
		mat[ti][tj] = aux + mat[ti][tj];

		cnt++;

		printf("step %d:\n", cnt);
		print(mat);
		if (2*cnt == n) printf("\npart 2\n");
	}
}

void go(matrix &mat) {

	

	


	

	string z0, z1, o0, o1;
	if (invert) {
		reverse(all(mat[0][0]));
		reverse(all(mat[0][1]));
	}
	for(char c : mat[0][0]) {
		if (c == '0') z0.pb(c), move(0, 0, 1, 0);
		else o0.pb(c), move(0, 0, 0, 1);
	}
	for(char c : mat[0][1]) {
		if (c == '0') z1.pb(c), move(0, 1, 0, 0);
		else o1.pb(c), move(0, 1, 1, 1);
	}
	if (invert) {
		mat[1][0] = z0 + mat[1][0];
		mat[1][1] = o1 + mat[1][1];
	}
	else {
		mat[1][0] = mat[1][0] + z0;
		mat[1][1] = mat[1][1] + o1;
	}
	mat[0][0] = z1;
	mat[0][1] = o0;

	

	


	

	FOR(i, n) {
		if (i == 0) continue;
		string aux;
		if (invert) reverse(all(mat[i][0]));
		for(char c : mat[i][0]) {
			if (c == '0') {
				move(i, 0, 0, 0);
				mat[0][0].pb(c);
			}
			else {
				aux.pb(c);
				move(i, 0, i, 1);
			}
		}
		if (invert) mat[i][1] = aux + mat[i][1];
		else mat[i][1] = mat[i][1] + aux;
		mat[i][0].clear();
	}

	

	


	

	FOR(i, n) FOR(j, m) {
		if (j == 0) continue;
		if (i == 0 && j == 1) continue;
		clean(mat, i, j);
	}

	

	

}

matrix from, to;

int main() {
	while(cin >> n >> m) {
		from.resize(n);
		FOR(i, n) {
			from[i].resize(m);
			FOR(j, m) cin >> from[i][j];
		}
		to.resize(n);
		FOR(i, n) {
			to[i].resize(m);
			FOR(j, m) cin >> to[i][j];
		}
		matrix aux = from;

		invert = true;
		ans.clear();
		go(from);
		auto p1 = ans;

		invert = false;
		ans.clear();
		go(to);
		auto p2 = ans;
		for(auto &pp : p2) swap(pp.fi, pp.se);
		reverse(all(p2));

		ans = p1;
		ans.insert(ans.end(), all(p2));

		printf("%d\n", sz(ans));
		for(auto pp : ans) {
			printf("%d %d %d %d\n", pp.fi.fi, pp.fi.se, pp.se.fi, pp.se.se);
		}

		

	}
	return 0;
}