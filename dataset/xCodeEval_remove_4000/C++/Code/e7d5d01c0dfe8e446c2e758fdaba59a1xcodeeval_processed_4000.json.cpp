






using namespace std;







int main() {
	

	

	

	

	


	


	


	

	

	

	
	

	


	

	

	

	

	
	long long n, a, sum = 0, count = 0, zeros = 0;
	cin >> n;
	long long *arr = new long long[n];

	cin >> arr[0];
	sum += arr[0];

	if (!arr[0]) zeros++;

	for (long long i = 1; i < n; i++) {
		cin >> a;
		arr[i] = arr[i - 1] + a;
		sum += a;
		if (!arr[i]) zeros++;
	}

	if (sum % 3) {
		cout << 0 << endl;


		return 0;
	}

	if (sum) {
		long long thirds = 0, id0 = 0, minus = 0;

		for (long long i = 0; i < n; i++) {
			if (arr[i] == sum / 3) {
				thirds++;
				if (id0) minus++;
			}
			else if (arr[i] == (sum / 3) * 2 && thirds) {
				id0++;
			}
		}

		cout << thirds * id0 - minus << endl;
	}
	else {
		zeros -= 2;
		for (int i = 0; i < zeros; i++) {
			count += i + 1;
		}

		cout << count << endl;
	}






	return 0;
}
