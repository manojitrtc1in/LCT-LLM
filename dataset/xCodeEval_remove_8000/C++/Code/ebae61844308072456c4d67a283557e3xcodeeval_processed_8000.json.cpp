


















typedef long long ll;

ll const INF = 9223372036854775807;
ll const NINF = -9223372036854775807;
using namespace std;
bool id0(string s) {
	for (ll i = 0; i < floor(size(s) / 2.); i++) {
		if (s[i] != s[size(s) - 1 - i]) return 0;
	}
	return 1;
}
int main() {
	RR{
		string s;
	cin >> s;
	if (id0(string('a' + s)) == 0) cout << "YES\n" << 'a' + s << endl;
	else if (id0(string(s + 'a')) == 0) cout << "YES\n" << s + 'a' << endl;
	else cout << "NO\n";
	}
	return 0;
}