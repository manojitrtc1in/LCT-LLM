#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
#define pbk push_back
#define rep(i, a, b) for (int i=a; i<=b; i++) 
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef map<int, int> mii;
typedef set<int> si;
typedef queue<int> qi;
typedef tuple<int, int, int> tiii; 

typedef vector<tiii> vtiii;
int T, N, K, M;



void print(int a, int b) {
	cout << a << " " << b << endl;
}

void print(const string& str) {
	cout << str << endl;
}
void print(pii a) {
	cout << a.first << " " << a.second << endl;
}

void print(int a) {
	cout << a << endl;
}

void print(vi& v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}













































































































vi v;
string answer;
void dfs(int idx, string& str) {
	if(idx==N) {
		answer = str;
		return;
	}
	if(v[idx]==0) return;

	if(idx < v.size()-2) {
		int twoDigit = v[idx]*10 + v[idx+1];
		if(twoDigit<=26 && v[idx+2]==0) {
			str.pbk((char)(twoDigit+'a'-1));
			dfs(idx+3, str);
			str.pop_back();
		}
	}
	str.pbk((char)(v[idx]+'a'-1));
	dfs(idx+1, str);
	str.pop_back();
}

void Solve() {
	v.clear();
	cin >> N;
	for(int i=0;i<N;i++) {
		char c; cin >> c;
		v.pbk(c-'0');
	}
	string str="";
	answer="";
	dfs(0, str);
	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while(T--) Solve();
}