#include <bits/stdc++.h>
#define ll long long
using namespace std;











































































































































































































































































































































template<typename T>
std::vector<T> slice_vec(std::vector<T> const &v, int m, int n)
{
	auto first = v.cbegin() + m;
	auto last = v.cbegin() + n + 1;

	std::vector<T> vec(first, last);
	return vec;
}

bool IsSquare(int n) {
	int k = sqrt(n);
	return (k * k == n);
}

bool IsPrime(int n) {
	for (int i{2}; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

bool IsCube(int n) {
	int k = cbrt(n);
	return (k * k * k == n);
}

bool CheckPalindrome(string str1, string str2) {
	reverse(str1.begin(), str1.end());
	if (str1 == str2) {
		return true;
	}
	return false;
}

string decToBinary(ll n, ll l)
{
	string s;
	

	for (int i = l - 1; i >= 0; i--) {
		ll k = n >> i;
		if (k & 1)
			s += '1';
		else
			s += '0';
	}
	return s;
}

int mex(vector <int> &vec, int n) {
	set <int> s;
	for (int i{}; i < n; i++) {
		s.insert(vec[i]);
	}
	int ctr = 0;
	for (auto it = s.begin(); it != s.end(); it++) {
		if (*it != ctr) {
			return ctr;
		}
		ctr++;
	}
	return (ctr);
}

int LIS(vector<int>& arr)
{
	vector<int> ans;
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
		if (it == ans.end()) {
			ans.push_back(arr[i]);
		}
		else {
			*it = arr[i];
		}
	}
	return ans.size();
}
bool isEven(int i)
{
	if (i % 2 == 0)
		return true;
	else
		return false;
}
bool isOdd(int i)
{
	if (i % 2 != 0)
		return true;
	else
		return false;
}

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second != b.second) {
		return b.second < a.second;
	} else {
		return a.first < b.first;
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	int n = nums.size();
	int count_subsets = (1 << n);
	vector <vector <int>> subsets;
	for (int i = 0; i < count_subsets; i++) {
		vector <int> subset;
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j)) != 0)
				subset.push_back(nums[j]); 

		}
		subsets.push_back(subset);
	}
	return subsets;
}

void computeLPSArray(string pat, int M,
                     int lps[])
{

	

	

	int len = 0;
	int i = 1;
	lps[0] = 0; 


	

	

	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else 

		{

			

			

			

			if (len != 0)
			{
				len = lps[len - 1];

				

				

			}
			else 

			{
				lps[i] = len;
				i++;
			}
		}
	}
}

int KMPSearch(string pat, string txt)
{
	int M = pat.length();
	int N = txt.length();

	

	

	int lps[M];
	int j = 0; 


	

	

	computeLPSArray(pat, M, lps);

	int i = 0; 

	int res = 0;
	int next_i = 0;

	while (i < N)
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}
		if (j == M)
		{

			

			

			

			j = lps[j - 1];
			res++;
		}

		

		else if (i < N && pat[j] != txt[i])
		{

			

			

			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
	return res;
}
int GCD(int x, int y) {
	if (y == 0) {
		return x;
	}
	return GCD(y, x % y);
}
int fact(int n) {
	if (n == 1) return 1;
	return (n) * fact(n - 1);
}
int nextPrime(int N)
{

	

	if (N <= 1)
		return 2;

	int prime = N;
	bool found = false;

	

	

	while (!found) {
		prime++;

		if (IsPrime(prime))
			found = true;
	}

	return prime;
}
vector <ll> MaxSum_SubArr(vector <ll> vec) {
	ll n = vec.size();
	vector <ll> ans(n), p(n + 1);
	p[0] = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) p[i + 1] = vec[i];
		else p[i + 1] = p[i] + vec[i];
	}
	for (int i = 0; i < n; i++) {
		ll mx = LONG_LONG_MIN;
		for (int j = 0; j < n - i; j++) {
			mx = max(mx, p[j + i + 1] - p[j]);
		}
		ans[i] = mx;
	}
	return ans;
}

void solve() {
	ll n; cin >> n;
	vector <ll> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	if (!(n & 1)) {
		cout << "YES" << endl;
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		if (vec[i] >= vec[i + 1]) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}