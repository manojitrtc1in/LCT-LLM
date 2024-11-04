
using namespace std;

























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
