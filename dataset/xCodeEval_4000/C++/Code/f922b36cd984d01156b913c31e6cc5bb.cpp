#include<iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>


#include<map>
#include <unordered_map>
#include <list>
#include <iomanip>
#include <bitset>
#include <stack>
#include <sstream>
#include <queue>
#include <math.h>
#include <set>
#include<numeric>
#define mod 1000000007
typedef long long  ll;

using namespace std;
long long maxPrimeFactors(long long n)
{
	

	

	long long maxPrime = -1;

	

	while (n % 2 == 0) {
		maxPrime = 2;
		n >>= 1; 

	}

	

	

	

	for (ll i = 3; i <= sqrt(n); i += 2) {
		while (n % i == 0) {
			maxPrime = i;
			n = n / i;
		}
	}

	

	

	if (n > 2)
		maxPrime = n;

	return maxPrime;
}
ll gcd(ll a, ll b)
{
	return (b ? gcd(b, a % b) : a);
}
ll P(ll B, ll power, ll modulo) 

{
	ll ans = 1LL;
	while (power > 0LL)
	{
		if (power % 2LL == 1LL)
		{
			ans = (ans * B) % modulo;
		}
		B = (B * B) % modulo;
		power /= 2LL;
	}
	return ans;
}
bool isPrime(ll n)
{
	if (n <= 1LL)
	{
		return false;
	}
	if (n <= 3LL)
	{
		return true;
	}
	if (n % 2 == 0LL || n % 3 == 0LL)
	{
		return false;
	}
	for (ll i = 5LL; (i * i) <= n; i += 6LL)
	{
		if (n % i == 0LL || n % (i + 2LL) == 0LL)
		{
			return false;
		}
	}
	return true;
}



ll lcm( ll a, ll b)
{
	return (a / gcd(a, b) * b);
}



void combinationUtil(ll arr[], ll n, ll r,
                     ll index, ll data[], ll i);










ll findlcm(ll arr[], ll n) 

{
	

	ll ans = arr[0];

	

	

	for (ll i = 1; i < n; i++)
		ans = (((arr[i] * ans)) /
		       (gcd(arr[i], ans)));

	return ans;
}


ll factmod(ll n, ll p) {
	ll res = 1;
	while (n > 1) {
		res = (res * ((n / p) % 2 ?  p - 1 : 1)) % p;
		for (ll i = 2; i <= n % p; ++i)
			res = (res * i) % p;
		n /= p;
	}
	return res % p;
}




ll arrGCD(std::vector<ll> &v, ll n) {
	if (n == 0) return -1;
	ll ans = v[0];
	for (ll i = 0; i < n; i++) {
		ans = gcd(ans, v[i]);
		if (ans == 1) return 1;
	}
	return ans;
}





ll longestCommonSubsequence(string text1, string text2)
{
	ll m = text1.size();
	ll n = text2.size();

	ll output[m + 1][n + 1];
	output[0][0] = 0;

	for (ll i = 1; i <= n; i++)
		output[0][i] = 0;

	for (ll i = 1; i <= m; i++)
		output[i][0] = 0;

	for (ll i = 1; i <= m; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			if (text1[m - i] == text2[n - j])
				output[i][j] = 1 + output[i - 1][j - 1];
			else
			{
				ll a = output[i - 1][j];
				ll b = output[i][j - 1];
				ll c = output[i - 1][j - 1];

				output[i][j] = max(a, max(b, c));
			}
		}
	}

	return output[m][n];

}
void decToBinary(ll n)
{	if (n == 0) {cout << "0"; return;}
	

	ll binaryNum[32];

	

	ll i = 0;
	while (n > 0) {

		

		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	

	for (ll j = i - 1; j >= 0; j--)
		cout << binaryNum[j];
}


ll fact(ll n)
{
	ll res = 1;
	for (ll i = 2; i <= n; i++)
		res = res * i;
	return res;
}
ll nCr(ll n, ll r)
{
	return fact(n) / (fact(r) * fact(n - r));
}

bool isPal(ll n) {
	ll  reversedN = 0, remainder, originalN;

	originalN = n;

	

	while (n != 0) {
		remainder = n % 10;
		reversedN = reversedN * 10 + remainder;
		n /= 10;
	}

	

	if (originalN == reversedN)
		return 1;
	else
		return 0;

	return 0;
}

int go(int idx, vector<int> &v, int n) {
	if (idx > n - 1) {
		return 0;

	}

	if (v[idx] == 0 and v[idx + 1] == 1 and v[idx - 1] == 1) {
		v[idx - 1] = 0;
		int a = go(idx + 1, v, n);
		v[idx - 1] = 1;
		v[idx + 1] = 0;
		int b = go(idx + 1, v, n);
		return 1 + min(a, b);
	}
	else {
		return go(idx + 1, v, n);
	}
}
int print2largest(std::vector<int>  arr , int arr_size)
{
	int i, first, second;

	

	if (arr_size < 2)
	{
		

		return -1;
	}

	

	for (i = 0; i < arr_size; i++)
	{

		

		

		

		if (arr[i] > first)
		{
			second = first;
			first = arr[i];
		}

		

		

		else if (arr[i] > second &&
		         arr[i] != first)
		{
			second = arr[i];
		}
	}
	if (second == INT_MIN)
		return first;
	else
		return second;
}

int answer(int n, int k)

{

	int sum_of_digits = 0;

	int z = 0;

	for (int i = 0; i <= n; i++)

	{

		sum_of_digits = 0;

		int temp = i;

		while (temp != 0)

		{

			int r = temp % 10;

			sum_of_digits += r;

			temp = temp / 10;

		}

		if (sum_of_digits % k == 0)

		{
			cout << i << endl;
			z++;

		}

	}

	return z;

}


































bool osd(std::vector<int> &A) {
	map<int, int> mp;
	for (auto i : A) {
		mp[i]++;
	}
	bool ok = 1;
	for (auto i : mp) {
		if (i.second % 2 == 1) {
			ok = 0;
			break;
		}
	}
	if (!ok) {
		return 0;
	}
	return 1;
}
int minSwaps(vector<int> A) {

	if (!osd(A)) {
		return -1;

	}

	int N = A.size() / 2;
	int visited[1000000] = {0};
	

	int minimumSwaps = 0;
	for (int i = 0; i < 2 * N; i++) {


		if (visited[A[i]] == false) {
			visited[A[i]] = true;


			int count = 0;

			for (int j = i + 1; j < 2 * N; j++) {


				if (visited[A[j]] == false)
					count++;


				else if (A[i] == A[j])
					minimumSwaps += count;
			}
		}
	}
	return minimumSwaps;


}
bool possible(int n) {
	int s = 0;
	while (n != 0) {
		int r = n % 10;
		s += r;
		n /= 10;
	}
	if (s % 5 == 0) {
		return true;
	}
	return false;
}
void getK(int N, int K) {
	

	while (K > 0) {
		N++;
		if (possible(N)) {
			K--;
		}
	}
	cout << (N + mod) % mod << endl;
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

			

			

			

			if (lps[j] != 0)
				i = ++next_i;
			j = 0;
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
void overpower() {
	string s;
	int j = 0, k = 0;
	vector<int>ki;
	vector<int>st;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s.substr(i, 4) == "KICK") {
			ki.push_back(i);
		}
		if (s.substr(i, 5) == "START") {
			st.push_back(i);
		}
	}
	int res = 0;
	for (int i = 0; i < ki.size(); i++) {
		for (int j = 0; j < st.size(); j++) {
			if (ki[i] < st[j]) {
				res++;
			}
		}
	}
	cout << res << endl;
}
void ss() {
	auto tt = 0;
	cin >> tt;
	for (auto itr = 1; itr <= tt; itr++)
	{
		auto n = 0;
		cin >> n;
		map<long long int, long long int>mp;
		auto t =  vector<vector<long long int > > (n, vector<long long int>(n, 0));
		for (auto i = 0; i < n; i++)
		{
			for (auto j = 0; j < n; j++)
			{
				cin >> t[i][j];
				mp[i - j] += t[i][j];
			}
		}
		auto maxi = 0;

		for (auto it : mp)
			if (it.second > maxi)maxi = it.second;

		cout << "Case #" << itr << ": " << maxi << endl;
		maxi = 0;
		mp.clear();
		t.clear();

	}

}

void aard()
{
	ll t;
	cin >> t;
	ll z = 0;
	while (t--) {
		z++;
		cout << "Case #" << z << ": ";
		ll n, m;
		cin >> n;
		ll a[n + 2][n + 2];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		ll value = 0;
		ll first = n - 1;
		ll second;
		ll ans = -1, sum;
		for (int i = first; i >= 0; i--) {
			sum = 0;
			second = i;
			for (int j = 0; j <= value; j++) {
				sum += a[second++][j];
			}
			ans = max(ans, sum);
			value++;

		}
		for (int i = 1; i < n; i++) {
			second = i;
			first = 0;
			sum = 0;
			while (second < n) {
				sum += a[first++][second++];
			}
			ans = max(ans, sum);
		}
		cout << ans << endl;

	}
}

ll fac(ll n) {
	ll ans = 1;
	for (ll i = 1; i <= n; i++) {
		ans *= i;
	}
	return ans;
}
int dp[1001][1001];
int find_max(int i, int sum, vector<int> &v, int k, int taken, int n)
{

	if (i == n)
		return 0;

	if (dp[i][sum] != -1)
		return dp[i][sum];

	int ans = 0;
	if (taken == n / 2) {
		ans = find_max(i + 1, sum, v, k, taken, n);
		return dp[i][sum] = ans;
	}
	

	

	if ((sum + find_max(i + 1, sum, v, k, taken, n)) % k == 0)
		ans = find_max(i + 1, sum, v, k, taken, n);

	

	

	if ((sum + v[i] + find_max(i + 1, (sum + v[i]) % k,
	                           v, k, taken + 1, n)) % k == 0)
		

		ans = max(ans, v[i] + find_max(i + 1,
		                               (sum + v[i]) % k, v, k, taken + 1, n));


	return dp[i][sum] = ans;
}
vector<int> bi(int n, int x) {
	std::vector<int> ans;
	int left = 0;
	int right = n;
	while (left < right) {
		int mid = (left + right) / 2;
		ans.push_back(mid);
		if (mid > x) {
			right = mid - 1;
		}
		else if (mid < x) {
			left = mid + 1;
		} else {
			return ans;
		}

	}
	return ans;

}
long long power( long long x,
                 int y, int p)
{
	long long res = 1; 


	x = x % p; 

	


	while (y > 0) {
		

		if (y & 1)
			res = (res * x) % p;

		

		y = y >> 1; 

		x = (x * x) % p;
	}
	return res;
}



long long modInverse( long long n, int p)
{
	return power(n, p - 2, p);
}





long long nCrModPFermat( long long n,
                         int r, int p)
{
	

	if (r == 0)
		return 1;

	

	

	

	long long fac[n + 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % p;

	return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
int modFact(int n, int p)
{
	if (n >= p)
		return 0;

	int result = 1;
	for (int i = 1; i <= n; i++)
		result = (result * i) % p;

	return result;
}
ll mulmod(ll a, ll b, int m)
{
	ll res = 0; 

	a = a % m;
	while (b > 0)
	{
		

		if (b % 2 == 1)
			res = (res + a) % m;

		

		a = (a * 2) % m;

		

		b /= 2;
	}
	

	

	return res % m;
}
void sasa() {
	ll n, x, pos;
	cin >> n >> x >> pos;
	set<ll> a, b;
	ll left = 0, right = n;
	while (left < right)
	{
		ll m = (left + right) / 2;
		if (m > pos)
		{
			b.insert(m);
			right = m;
		}
		else
		{
			a.insert(m);
			left = m + 1;
		}
	}
	a.erase(pos);
	ll less = x - 1, greater = n - x;
	ll sz1 = a.size();
	ll sz2 = b.size();
	if (sz1 > less || sz2 > greater)
	{
		cout << 0;
		return;
	}
	ll fact1 = 1, fact2 = 1;
	for (ll i = less; i > less - sz1 && i > 0; --i)
		(fact1 *= i) %= mod;
	for (ll i = greater; i > greater - sz2 && i > 0; --i)
		(fact2 *= i) %= mod;
	ll ans = ((fact1) * (fact2)) % mod;
	ll rem = n - sz1 - sz2 - 1;
	ll fact3 = 1;
	for (ll i = rem; i > 0; --i)
		( fact3 *= i) %= mod;
	(ans *= fact3) %= mod;

	cout << ans;
}
std::vector<int > arr[100001];
std::vector<bool> visited(100001, 0);
vector<int> level(1000001, 0);
int bfs(int node, std::vector<int> &special) {

	visited[node] = true;
	level[node] = 1;

	if (binary_search(special.begin(), special.end(), node)) {
		return 0;
	}
	queue<int> q;
	q.push(node);
	while (!q.empty()) {
		int curr = q.front();
		for (int i = 0; i < arr[curr].size(); i++) {
			if (visited[arr[curr][i]] == 0) {
				visited[arr[curr][i]] = 1;
				q.push(arr[curr][i]);
				level[arr[curr][i]] = level[curr] + 1;
				if (binary_search(special.begin(), special.end(), arr[curr][i])) {
					return level[arr[curr][i]] - 1;
				}
			}

		}
		q.pop();


	}
	return -1;
}
std::vector<int>  getFactors(ll n)
{	std::vector<int> v;
	

	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			

			if (n / i == i)
				v.push_back(i);

			else {v.push_back(i); v.push_back(n / i);} 


		}
	}
	return v;
}

int sdfc() {
	ll q, ans = 1;
	ll p;
	cin >> p >> q;
	vector<int> qF = getFactors(q);
	sort(qF.begin(), qF.end());
	if (p % q != 0) return p;
	for (auto x : qF) {
		if (p % x != 0) {
			continue;
		}
		if (p / x % q != 0)
			ans = max(ans, p / x);
		else {
			if (x == 1) continue;
			ll tP = p;
			while (tP % x == 0) tP /= x;
			if (tP % q != 0)
				ans = max(ans, tP);
		}
	}
	return ans;
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;




	t = 1;


	while (t--) {
		

		int n;
		cin >> n;
		vector<int> small(n), big(n), v(2 * n);
		for (auto &i : v) {
			cin >> i;
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			small[i] = v[i];

		}
		for (int i = n; i < 2 * n; i++) {
			big[i - n] = v[i];
		}
		ll ans = 0;
		reverse(big.begin(), big.end());

		for (int i = 0; i < n; i++) {
			ans +=  abs(big[i] - small[i]);
		}
		ans = mulmod(ans , nCrModPFermat(2 * n, n, 998244353), 998244353);

		cout << ans   << endl;



	}


#ifndef ONLINE_JUDGE
	cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif

}
















