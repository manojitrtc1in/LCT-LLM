#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void print(vector <int> arr) {
	cout << "arr consisits off: ";

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void printMatrix(vector <vector<int>> matrix) {
	cout << "---" << endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---" << endl;
}


int main() {


	
	
	

	

	

	
	


	

	

	

	

	

	

	

	

	


	
	

	

	

	

	

	

	


	
	
	

	

	

	

	

	
		
	

	
	
	
	
	

	

	
	
	
	
	string str;
	vector <int> arr;
	int m, l, r;

	cin >> str >> m;

	arr.resize(str.length());

	int sum = 0;

	for (int i = 0; i < str.length(); i++) {
		if (i == 0 || str[i] != str[i - 1]) {
			arr[i] = sum;
		}
		else if (str[i] == str[i - 1]) {
			sum++;
			arr[i] = sum;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		cout << abs(arr[l - 1] - arr[r - 1]) << endl;
	}




	return 0;
}