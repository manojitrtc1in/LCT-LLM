#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	int a;
	cin >> a;
	long long *room = new long long[a]; 

	double temp; 

	int temp2; 

	

	

	


	

	

	

	
	for (int i = 0; i < a; i++) {
		cin >> room[i];
		if (room[i] == 1) { 

			cout << "NO" << endl;
		}
		else {
			temp = sqrt(room[i]);
			temp2 = sqrt(room[i]);
			if (temp - temp2 == 0) {

				

				double primetest;
				int primetest2; 

				bool flag = true; 

				for (int j = 2; j <= sqrt(temp); j++) {
					primetest = temp / j; 

					primetest2 = temp / j;
					if (!(primetest - primetest2)) {
						cout << "NO" << endl; 

						flag = false;
						break;
					}
				}
				

				if (flag) {
					cout << "YES" << endl;
					flag = false;
				}
			}
			else
				cout << "NO" << endl;
		}
		
	}
	delete[] room;

}