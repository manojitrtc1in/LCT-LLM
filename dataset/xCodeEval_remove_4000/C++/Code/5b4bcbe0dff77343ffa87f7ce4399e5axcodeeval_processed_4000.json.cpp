






using namespace std;







int main() {
	

	

	

	

	


	


	


	

	

	

	
	

	


	

	
	int n;
	cin >> n;
	vector <vector<int>> store(n);
	for (int i = 0; i < n; i++) {
		store[i].resize(n);
	}

	int j, step = 0;
	for (int i = 0; i < n; i += 2) { 

		for (j = 0; j < n; j++) {
			store[j][i] = n * n - step - j;
		}
		step += j * 2;
	}

	int step2 = 0;
	int num = 1;

	for (int i = 1; i < n; i += 2) { 

		step2 = 0;
		for (int k = n - 1; k >= 0; k--) {
			store[k][num] = n * n - n * i - step2;
			step2++;
		}
		num += 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << store[i][j] << " ";
		}
		cout << endl;
	}




	return 0;
}
