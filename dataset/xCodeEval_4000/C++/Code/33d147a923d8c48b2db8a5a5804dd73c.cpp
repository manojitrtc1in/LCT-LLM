#include<string>
#include<string.h>
#include <chrono>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<set>
#include<stdio.h>
#include<iostream>
#include<functional>

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include<stack>
#include<unordered_set>


using namespace std;

#if _DEBUG
#define debug while(true)
#else
#define debug
#endif


















































































































































































































































































void task1423() {
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
void task1164() {
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


void task1279() {
	int n, m, k;
	cin >> n >> m >> k;

	map<int, int> counts;

	int a;
	for (int i = 0; i < n * m; ++i) {
		cin >> a;
	}

}

void task1889() {
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

	int min_diff_langs = lang_nums.size();

	map<int, int> counts;
	for (int i = 1; i <= min_diff_langs; i++)
		counts.insert(make_pair(i, 0));

	for (int i = 0; i < n; i++)
	{
		if (lang_arr[i] != 0)
			counts[lang_arr[i]]++;
	}

	int one_lang_max_cnt = 0;
	for (auto par : counts) {
		one_lang_max_cnt = max(one_lang_max_cnt, par.second);
	}

	int unknown_needs = 0;
	for (auto par : counts) {
		unknown_needs += par.second - one_lang_max_cnt;
	}

	int max_lng_cnt = min_diff_langs + (unknown_cnt - unknown_needs) / one_lang_max_cnt;


	bool any_one_possible = false;
	for (int lang_cnt = min_diff_langs; lang_cnt <= max_lng_cnt; lang_cnt++) {

		if (n % lang_cnt != 0)
			continue;

		int frases_cnt = n / lang_cnt;

		bool cnt_possible = true;

		set<int> used;
		for (int j = 0; j < lang_cnt; j++) {
			int now = 0;
			for (int k = 0; k < frases_cnt; k++)
			{
				int tmp = lang_arr[j * frases_cnt + k];
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
			any_one_possible = true;
		}
	}

	if (!any_one_possible)
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

void task1217B_part() {
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

void task1217B() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		task1217B_part();
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

void task188C() {
	int a, b;
	cin >> a >> b;

	int tmp = gcd(max(a, b), min(a, b));
	cout << a * b / tmp << endl;
}

void task4C() {
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


void task4B() {
	int d, sumTime;
	cin >> d >> sumTime;

	vector<int> minTimes(d), maxTimes(d);
	for (int i = 0; i < d; i++)
	{
		cin >> minTimes[i] >> maxTimes[i];
	}

	int sumTimeNow = 0;
	vector<int> time(d);
	for (int i = 0; i < d; i++) {
		time[i] = minTimes[i];
		sumTimeNow += time[i];
	}
	if (sumTimeNow > sumTime) {
		cout << "NO" << endl;
		return;
	}

	for (int i = 0; i < d; i++) {
		int needed = min(sumTime - sumTimeNow, maxTimes[i] - time[i]);
		time[i] += needed;
		sumTimeNow += needed;
	}

	if (sumTimeNow < sumTime) {
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

void task510B() {
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

				set<pair<int, int>> used_verts;
				while (!s.empty()) {
					now = s.top();
					s.pop();
					used_verts.insert(now);
					if (used[now.first][now.second]) {
						loop = true;
						break;
					}
					used[now.first][now.second] = 1;
					auto neibs = neib(now, n, m);
					for (auto ne : neibs)
						if (used_verts.find(ne) == used_verts.end() &&
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

void taskE1_part() {
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

		vector<int> max_in_cols(m);
		for (int i = 0; i < m; i++) {
			max_in_cols[i] = a[0][i];
			for (int k = 0; k < n; k++)
				max_in_cols[i] = max(max_in_cols[i], a[k][i]);

		}

		int max_v = 0, max_i = -1;
		for (int i = 0; i < m; i++)
			if (max_in_cols[i] > max_v) {
				max_v = max_in_cols[i];
				max_i = i;
			}

		maxes[0] = max_v;
		used_cols.insert(max_i);

	}
}

void taskE1() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		taskE1_part();
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

void taskC_part() {
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
		taskC_part();
	}
}

void taskD() {
	int n, k;
	cin >> n >> k;
	int x, y;
	vector<set<int>> g(n);

	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		g[x-1].insert(y-1);
		g[y-1].insert(x-1);
	}

	set<int> in_comp;
	for (int i = 0; i < n; i++)
		in_comp.insert(i);

	int comp_cnt = 0;
	while (!in_comp.empty()) {
		stack<int> s;
		int now = *in_comp.begin();
		s.push(now);
		while (!s.empty())
		{
			int now = s.top();
			s.pop();
			in_comp.erase(now);

			for (auto neib : g[now]) {
				if(in_comp.find(neib)!=in_comp.end())
				s.push(neib);
			}
		}

		comp_cnt++;
	}

	cout << k - (n - comp_cnt) << endl;


}
int main() {

	debug
		taskD();
	

	return 0;
}