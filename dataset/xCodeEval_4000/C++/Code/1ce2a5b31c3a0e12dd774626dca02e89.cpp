











#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <utility>
#include <set>
using namespace std;
#define ll long long
#define x first
#define y second
#define N 1000005
#define MAXN 999999



int max(int  a, int b) { if (a > b) return a; else return b; }
int min(int  a, int b) { if (a < b) return a; else return b; }


int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
vector <bool> isPrime(N + 1, true);
string tos(int n) { stringstream ss; ss << n; return ss.str(); }
void seive() {
	isPrime[0] = 0, isPrime[1] = 0; for (ll i = 2; i*i <= N; i++) if (isPrime[i]) for (ll j = i * i; j <= N; j += i) isPrime[j] = 0;
}
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const int  val = 100905;
int  nxt,n,src, dist, ans=1, p[val]; bool can;
int main()
{
	cin >> n >> src >> dist;;
	for (int i = 1; i <= n; i++)  cin >> p[i];
	nxt = src;
	if (src == dist) { cout << 0; return 0; }
	while (ans != val)
	{
		nxt = p[nxt];
		if (nxt == dist) { can = 1; break; }
		ans++;
	}
	cout << (can ? ans : -1) << "\n";

	

	return 0;
}