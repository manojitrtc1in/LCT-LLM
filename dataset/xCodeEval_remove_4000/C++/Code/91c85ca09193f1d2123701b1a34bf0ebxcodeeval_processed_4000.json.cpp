











using namespace std;

int main() {
	int q;
	long num=0,sum=0,num2=0;
	cin >> q;
	while (q--) {
		sum = 0;
		num2 = 0;
		cin >> num;
		if (num < 4) {
			cout << -1 << endl;
			continue;
		}
		if (num % 2 == 1) {
			sum++;
			num -= 9;
			if (num < 0) {
				cout << -1 << endl;
				continue;
			}
		}
		num2 = num / 2;
		if (num2 % 2 == 0) {
			if (num % 4 == 0) {
				sum += num / 4;
				cout << sum << endl;
				continue;
			}
			else {
				cout << -1 << endl;
			}
			
		}
		else {
			num -= 6;
			if (num < 0) {
				cout << -1 << endl;
				continue;
			}
			sum++;
			if (num % 4 == 0) {
				sum += num / 4;
				cout << sum << endl;
				continue;
			}
			else {
				cout << -1 << endl;
			}
		}
		
	}

	return 0;
}











