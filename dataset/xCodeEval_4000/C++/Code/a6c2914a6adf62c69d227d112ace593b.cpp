#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define ull unsigned long long
#define loop(n) for(int i = 0; i < n; i++)
#define loop1(n) for(int i = 1; i <= n; i++)
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






int main() {
	faster_IO_stream

	int n, num;
	cin >> n;
	map<int, int> freq;
	loop(n) {
		cin >> num; freq[num]++;
	}

	cout << max(n - (*freq.begin()).second - (*--freq.end()).second, 0) << endl;

	return 0;
}
