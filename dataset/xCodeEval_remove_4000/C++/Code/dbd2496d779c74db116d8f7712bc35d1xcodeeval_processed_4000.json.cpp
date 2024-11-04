






using namespace std;







int main() {
	

	

	

	

	


	


	


	

	

	

	
	

	


	

	

	

	
	string str;
	long long amount = 0, wowEffect = 0, counter = 0;
	cin >> str;

	vector <long long> nums(str.length());

	nums[0] = 0;
	for (long long i = 1; i < str.length() - 1; i++) {
		if (str[i] == 'v' && str[i - 1] == 'v') {
			amount++;
		}

		nums[i] = amount;
	}

	if (str[str.length() - 2] == 'o' || str[str.length() - 1] == 'o') nums[str.length() - 1] = amount;
	else if (str[str.length() - 2] == 'v' && str[str.length() - 1] == 'v') nums[str.length() - 1] = amount + 1;
	
	for (long long i = 0; i < str.length(); i++) {
		if (str[i] == 'o') {
			if (nums[str.length() - 1] - nums[i] > 0) {
				wowEffect += nums[i] * (nums[str.length() - 1] - nums[i]);
			}
		}
	}

	cout << wowEffect << endl;




	return 0;
}
