



















using namespace std;
























































































































































































































































































void id21() {
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	string haystack = s1 + s1;
	string needle = s2;

	

	auto it4 = std::search(haystack.begin(), haystack.end(),
		needle.begin(), needle.end());

	if (it4 == haystack.end())
	{
		cout << "-1" << endl;
	}
	else {
		if (it4 == haystack.begin()) {
			cout << 0 << endl;
		}
		else {
			cout << n - (it4 - haystack.begin()) << endl;
		}
	}
}
void id15() {
	int n, m, p;
	cin >> n >> m >> p;

	string s;
	map<char, int> counts;

	for (char c = 'A'; c <= 'Z'; c++)
		counts.insert(make_pair(c, 0));

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
			counts[s[j]]++;
	}

	for (int i = 0; i < p; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
			counts[s[j]]--;
	}

	for (auto par : counts) {
		for (int i = 0; i < par.second; i++)
			cout << par.first;
	}
	cout << endl;
}


void id7() {
	int n, m, k;
	cin >> n >> m >> k;

	map<int, int> counts;

	int a;
	for (int i = 0; i < n * m; ++i) {
		cin >> a;
	}

}

void id3() {
	int n;
	cin >> n;
	string s;

	


	vector<int> lang_arr;



	int unknown_cnt = 0;
	bool have_unknown = false;

	map<string, int> lang_nums;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		


		if (s == "unknown") {
			have_unknown = true;
			unknown_cnt++;
			lang_arr.push_back(0);
		}
		else {
			

			if (lang_nums.find(s) == lang_nums.end())
				lang_nums.insert(make_pair(s, lang_nums.size() + 1));

			lang_arr.push_back(lang_nums[s]);


		}
	}

	int id6 = lang_nums.size();

	map<int, int> counts;
	for (int i = 1; i <= id6; i++)
		counts.insert(make_pair(i, 0));

	for (int i = 0; i < n; i++)
	{
		if (lang_arr[i] != 0)
			counts[lang_arr[i]]++;
	}

	int id8 = 0;
	for (auto par : counts) {
		id8 = max(id8, par.second);
	}

	int id16 = 0;
	for (auto par : counts) {
		id16 += par.second - id8;
	}

	int id20 = id6 + (unknown_cnt - id16) / id8;


	bool id13 = false;
	for (int lang_cnt = id6; lang_cnt <= id20; lang_cnt++) {

		if (n % lang_cnt != 0)
			continue;

		int id1 = n / lang_cnt;

		bool cnt_possible = true;

		set<int> used;
		for (int j = 0; j < lang_cnt; j++) {
			int now = 0;
			for (int k = 0; k < id1; k++)
			{
				int tmp = lang_arr[j * id1 + k];
				if (tmp == 0)
					continue;
				if (tmp == now)
					continue;
				if (now == 0)
				{
					now = tmp;
					if (used.find(now) != used.end())
					{
						cnt_possible = false;
						break;
					}
					used.insert(now);
				}
				if (now > 0 && tmp != now)
				{
					cnt_possible = false;
					break;
				}
			}
			if (!cnt_possible)
				break;
		}

		if (cnt_possible) {
			cout << lang_cnt << " ";
			id13 = true;
		}
	}

	if (!id13)
	{
		cout << "Igor is wrong." << endl;
	}
	else {
		cout << endl;
	}


	


	

	

	

	

	

	

	

	

	

	

	

	

	


	


	



	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	


	


	

	


	


	


	

	

	


	

	

	

	


	


	


	


	


	

	


	

	

	

	

	

	

	


	

	

	

	

	

	


}

struct udar {
	int d;
	int h;
	int pol;
};

void id2() {
	int n, x;
	cin >> n >> x;

	int max_pol = -10000000000;
	int max_d = 0;
	int d, h;
	for (int i = 0; i < n; ++i) {
		cin >> d >> h;
		max_pol = max(max_pol, d - h);
		max_d = max(max_d, d);
	}
	if (x <= max_d) {
		cout << 1 << endl;
		return;
	}
	if (max_pol <= 0) {
		cout << -1 << endl;
	}
	else {
		x -= max_d;
		if (x < 0)
		{
			cout << 1 << endl;
		}
		else {
			int need = x / max_pol + 1;
			if (x % max_pol != 0)
				need += 1;
			cout << need << endl;
		}

	}
}

void id18() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		id2();
	}
}

int gcd(int a, int b) {
	if (b == 1)
		return 1;
	if (a == b)
		return a;
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

void id10() {
	int a, b;
	cin >> a >> b;

	int tmp = gcd(max(a, b), min(a, b));
	cout << a * b / tmp << endl;
}

void id11() {
	string s;
	int n;
	map<string, int> names;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (names.find(s) == names.end()) {
			names.insert({ s, 0 });
			cout << "OK" << endl;
		}
		else {
			names[s]++;
			cout << s << names[s] << endl;
		}
	}
}


void id12() {
	int d, sumTime;
	cin >> d >> sumTime;

	vector<int> minTimes(d), maxTimes(d);
	for (int i = 0; i < d; i++)
	{
		cin >> minTimes[i] >> maxTimes[i];
	}

	int id0 = 0;
	vector<int> time(d);
	for (int i = 0; i < d; i++) {
		time[i] = minTimes[i];
		id0 += time[i];
	}
	if (id0 > sumTime) {
		cout << "NO" << endl;
		return;
	}

	for (int i = 0; i < d; i++) {
		int needed = min(sumTime - id0, maxTimes[i] - time[i]);
		time[i] += needed;
		id0 += needed;
	}

	if (id0 < sumTime) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	for (int i = 0; i < d; i++)
		cout << time[i] << " ";
	cout << endl;

}
















vector<pair<int, int>> neib(pair<int, int> a, int n, int m) {
	vector<pair<int, int>> res;
	if (a.first > 0)
		res.push_back({ a.first - 1, a.second });
	if (a.first + 1 < n)
		res.push_back({ a.first + 1, a.second });

	if (a.second > 0)
		res.push_back({ a.first, a.second - 1 });
	if (a.second + 1 < m)
		res.push_back({ a.first, a.second + 1 });

	return res;
}

void id17() {
	int n, m;
	cin >> n >> m;
	char** color = new char* [n];
	int** used = new int* [m];
	for (int i = 0; i < n; i++) {
		color[i] = new char[m];
		used[i] = new int[m];

		for (int j = 0; j < m; j++) {
			cin >> color[i][j];
			used[i][j] = 0;
		}
	}

	bool loop = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (used[i][j] == 0)
			{
				stack<pair<int, int>> s;
				auto now = make_pair(i, j);
				s.push(now);

				set<pair<int, int>> id5;
				while (!s.empty()) {
					now = s.top();
					s.pop();
					id5.insert(now);
					if (used[now.first][now.second]) {
						loop = true;
						break;
					}
					used[now.first][now.second] = 1;
					auto neibs = neib(now, n, m);
					for (auto ne : neibs)
						if (id5.find(ne) == id5.end() &&
							color[ne.first][ne.second] == color[now.first][now.second])
							s.push(ne);
				}
			}
			if (loop)
				break;
		}
		if (loop)
			break;
	}
	if (loop)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}


void taskA() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<bool> colored(n, false);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int start = 0;
	int colors = 0;
	while (true) {
		colors++;
		int next = -1;
		for (int i = 0; i < n; ++i) {
			if (a[i] % a[start] == 0) {
				colored[i] = true;
			}

			else {
				if (!colored[i] && next == -1)
					next = i;
			}
		}
		if (next == -1)
			break;
		else start = next;
	}
	cout << colors << endl;
}

void id4() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	if (m > n) {
		vector<int> maxes(n);
		set<int> used_cols;

		vector<int> id14(m);
		for (int i = 0; i < m; i++) {
			id14[i] = a[0][i];
			for (int k = 0; k < n; k++)
				id14[i] = max(id14[i], a[k][i]);

		}

		int max_v = 0, max_i = -1;
		for (int i = 0; i < m; i++)
			if (id14[i] > max_v) {
				max_v = id14[i];
				max_i = i;
			}

		maxes[0] = max_v;
		used_cols.insert(max_i);

	}
}

void id9() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		id4();
	}
}

int light_count(string& s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '1')
			++cnt;
	return cnt;
}

void taskB() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	string s;
	cin >> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	int count = light_count(s);

	for (int t = 0; t < 1300; t++) {
		for (int i = 0; i < n; i++) {
			if ((t >= b[i]) && ((t - b[i]) % a[i] == 0)) {
				s[i] = ((s[i] == '0') ? '1' : '0');
			}
		}
		count = max(count, light_count(s));
	}

	cout << count << endl;
}

void id19() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	char cur1, cur2;
	char min1, min2;
	char max1, max2;
	vector<char> res(n);
	bool poss = true;

	cur2 = s[0];
	min2 = s[0];

	cur1 = '0' - 1;

	for (int i = 1; i < n; ++i) {
		if (s[i] >= cur2) {
			cur2 = s[i];
			res[i] = '2';
		}
		else {
			if (s[i] >= cur1) {

				if (cur1 < '0') {
					min1 = s[i];
				}

				cur1 = s[i];
				res[i] = '1';
			}
			else {
				poss = false;
				break;
			}
		}
	}

	if (cur1 > min2) {
		poss = false;
	}

	if (poss) {
		for (int i = 0; i < n; i++)
			cout << res[i];
		cout << endl;
	}
	else {
		cout << "-" << endl;
	}

}

void taskC() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		id19();
	}
}
int main() {

	debug
		taskB();
	

	return 0;
}