#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define ull unsigned long long
#define loop(n) for(int i = 0; i < n; i++)
#define loop1(n) for(int i = 1; i <= n; i++)
#define all(v) ((v).begin()), ((v).end())
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define vvi vector<vi>
#define vvpii vector<vii>
#define PB push_back

#define fw(fileName) freopen(fileName, "w", stdout)
#define fr(fileName) freopen(fileName, "r", stdin)
#define fc(stream) fclose(stream);

#define faster_IO_stream ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"





const double pi = 3.14159265358979323846;

int main() {
	faster_IO_stream

	int d, h, v, e;
	cin >> d >> h >> v >> e;

	double area = pi * (1.0 * d / 2) * (1.0 * d / 2);
	if(e > v / area) cout << "NO\n";
	else cout << setprecision(12) << "YES\n" << h / (v / area - e) << endl;

	return 0;
}
