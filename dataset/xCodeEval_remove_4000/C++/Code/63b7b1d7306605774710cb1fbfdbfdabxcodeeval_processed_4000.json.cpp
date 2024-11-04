



using namespace std;

const ll N = 1e5 + 10;
const int INF = 1e9 + 10;
const int N1 = 510;
std::vector<pair<int, int>> graph[N];
std::vector<ll> tree[N];
string grid[50];
ll dp[N];
int visited[N];


ll dist[N1][N1], h, w;
ll height[N];
ll depth[N];
int ans = 0, m;
std::vector<int> lis(N);




















































void sortString(string &str)
{
	sort(str.begin(), str.end());
	cout << str;
}

void _print(int a) {
	cerr << a;
}


void _print(long long a) {
	cerr << a;
}


void _print(char a) {
	cerr << a;
}


void _print(string a) {
	cerr << a;
}


void _print(bool a) {
	cerr << a;
}

template<class T> void _print(vector<T> v1) {
	cerr << "[ ";
	for (T i : v1) {
		_print(i);
		cerr << " ";
	}
	cerr << " ]";
}

template<class T> void _print(set<T> s1) {
	cerr << "[ ";
	for (T i : s1) {
		_print(i);
		cerr << " ";
	}
	cerr << " ]";
}
ll pow2(ll val) {
	return 1 << val;
}
ll id0(ll a, ll b, ll c) {
	return __gcd(a, __gcd(b, c));
}
ll id8(ll a, ll b , ll c, ll d) {
	return __gcd(__gcd(a, b), __gcd(c, d));
}
ll id2(ll a, ll b) {return (a * b) / __gcd(a, b);}
ll id6(ll a, ll b, ll c) { return id2(a, id2(b, c));}
ll id5(ll a, ll b, ll c, ll d) { return id2(id2(a, b), id2(c, d));}


bool prime(ll n)
{
	

	if (n <= 1)  return false;
	if (n <= 3)  return true;

	

	

	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}



int id7(ll a) {
	int num = 1, fact = 0;
	while (num * num <= a) {
		if (a % num == 0) {
			fact++;

			if (a / num != num) {
				fact++;
			}
		}
		num++;
	}
	return fact;
}


int id9(ll a, ll b)
{
	return (floor(cbrt(b)) - ceil(cbrt(a)) + 1);
}
int countSquares(ll a, ll b) {
	return (floor(sqrt(b)) - floor(sqrt(a - 1)));
}
int SquareCube(long long int N)
{

	int cnt = 0, i = 1;

	while (int(pow(i, 6)) <= N) {
		++cnt;
		++i;
	}

	return cnt;
}







void dfs(int vertex, int parent, int num_c, int max_c) {
	debug(lis[vertex]);
	if (lis[vertex]) num_c++;
	else num_c = 0;
	max_c = max(num_c, max_c);
	int num_child = 0;
	for (int child : tree[vertex]) {
		if (child != parent) {
			dfs(child, vertex, num_c, max_c);

			num_child++;
		}
	}
	if (num_child == 0 && max_c <= m) ans++;
}





int level[8][8];
bool is_valid(int x, int y) {
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}
int getx(string s) {
	return (s[0] - 'a');
}
int gety(string s) {
	return (s[1] - '1');
}
std::vector<pair<int, int>> movement = {
	{ -1, 2}, {1, 2},
	{ -1, -2}, {1, -2},
	{2, -1}, {2, 1},
	{ -2, -1}, { -2, 1},

};
int bfs(string intial, string destination) {
	debug(intial);
	int dest_x = getx(destination);
	int dest_y = gety(destination);
	int ini_x = getx(intial);
	int ini_y = gety(intial);
	queue <pair<int, int>> q;
	q.push({ini_x, ini_y});
	

	level[ini_x][ini_y] = 0;
	while (!q.empty()) {
		pair<int, int > v = q.front();

		int x = v.first, y = v.second;
		q.pop();
		for (auto movements : movement) {
			int child_x = movements.first + x;
			int child_y = movements.second + y;
			if (!is_valid(child_x, child_y))continue;
			

			{
				q.push({child_x, child_y});
				

				level[child_x][child_y] = level[x][y] + 1;
				debug(level[x][y]);
			}
		}
	}
	debug(level[dest_x][dest_y]);
	


}

void reset() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			level[i][j] = 0;
			

		}
	}
}


void id4(int start, int end, char source, char helper, char desti) {
	if (start > end) return;
	id4(start, end - 1, source, desti, helper);
	cout << "move disk " << end << "from " << source << " to " << desti << endl;
	id4(start, end - 1, helper, source, desti);
	

}














































void id1(int source) {
	std::vector<int> distance(N, INF);
	

	

	set<pair<int, int>> st;
	

	st.insert({0, source});
	distance[source] = 0;
	while (st.size() > 0) {
		

		

		auto node = *st.begin();
		

		int v = node.second;
		int dis = node.first;
		st.erase(st.begin());
		if (visited[v])continue;
		visited[v] = 1;
		for (auto child : graph[v]) {
			

			int child_v = child.first;
			int weight_v = child.second;
			if (distance[v] + weight_v < distance[child_v]) {
				distance[child_v] = distance[v] + weight_v;
				st.insert({distance[child_v], child_v});
				

			}
		}
	}
	for (auto i : distance) {
		if (i != INF) cout << i << " ";

	}
	cout << "\n";
}
bool id3(int num) {
	if (num % 2 == 0) return true;
	return false;
}


void solve() {
	string str; cin >> str;

	int l = str.length();
	if (l == 1 or l == 2) {
		if (l == 1) cout << "NO\n";
		else {
			if (str[1] != str[0]) cout << "NO\n";
			else cout << "YES\n";
		}
	}
	else {
		bool flag = false;
		for (int i = 1; i < l - 1; i++) {
			debug(str[i]);
			debug(str[i - 1]);
			debug(str[i + 1]);
			debug(str[i] != str[i - 1]);
			debug(str[i] != str[i + 1]);
			debug((str[i] != str[i - 1]) && (str[i] != str[i + 1]));
			if ((str[i] != str[i - 1]) && (str[i] != str[i + 1])) {
				flag = true;

			}
		}
		if (l > 1 and str[l - 1] != str[l - 2]) flag = true;
		if (l > 1 and str[0] != str[1]) flag = true;
		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}

}





int main() {

	freopen("input.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
	freopen("error.txt", "w", stderr);

	ios::sync_with_stdio(0);
	cin.tie(0);
	ll sample_test = 1;

	

	while (sample_test--) {
		ll t = 1;
		cin >> t;
		while (t--) {

			solve();
		}
	}
}