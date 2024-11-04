








using namespace std;

int main()
{
	int t;
	int i, j;
	cin >> t;
	while (t--)
	{
		int l, r, x;
		int a, b;
		cin >> l >> r >> x;
		cin >> a >> b;
		if (a == b)
			cout << 0 << endl;
		else if (r-x<b &&l+x>b)
			cout << -1 << endl;
		else if (a + x > r&&a - x < l)
			cout << -1 << endl;
		else if (abs(b - a) >= x)
			cout << 1 << endl;
		else if (r - a >= x&&r - b >= x || a - l >= x&&b - l >= x)
			cout << 2 << endl;
		else
			cout << 3 << endl;
	}
	return 0;
}