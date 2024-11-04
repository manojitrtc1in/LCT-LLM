#include <iostream>
using namespace std;
int main() {
	int t, m, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		char l[5], field[5][5] = { {'E','E','E','E','E'},{'E','E','E','E','E'},{'E','E','E','E','E'},{'E','E','E','E','E'},{'E','E','E','E','E'} };
		for (int j = 0; j < n; j++) {
			cin >> l;
			for (int k = 0; k < strlen(l); k++) {
				field[j][k] = l[k];
			}
		}
		if (field[0][0] == 'R') {
			cout << "YES" << '\n';
		}
		else if (field[0][1] == 'R') {
			if (field[1][0] == 'E' && field[2][0] == 'E' && field[3][0] == 'E' && field[4][0] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[0][2] == 'R') {
			if (field[1][0] == 'E' && field[2][0] == 'E' && field[3][0] == 'E' && field[4][0] == 'E' && field[0][1] == 'E' && field[1][1] == 'E' && field[2][1] == 'E' && field[3][1] == 'E' && field[4][1] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[0][3] == 'R') {
			if (field[1][0] == 'E' && field[2][0] == 'E' && field[3][0] == 'E' && field[4][0] == 'E' && field[0][1] == 'E' && field[1][1] == 'E' && field[2][1] == 'E' && field[3][1] == 'E' && field[4][1] == 'E'&& field[0][2] == 'E'&& field[1][2] == 'E' && field[2][2] == 'E' && field[3][2] == 'E' && field[4][2] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[0][4] == 'R') {
			if (field[1][0] == 'E' && field[2][0] == 'E' && field[3][0] == 'E' && field[4][0] == 'E' && field[1][1] == 'E' && field[2][1] == 'E' && field[3][1] == 'E' && field[4][1] == 'E' && field[1][2] == 'E' && field[2][2] == 'E' && field[3][2] == 'E' && field[4][2] == 'E' && field[1][3] == 'E' && field[2][3] == 'E' && field[3][3] == 'E' && field[4][3] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[1][0] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[1][1] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E'&&field[1][0] == 'E'&&field[2][0] == 'E'&&field[3][0] == 'E'&&field[4][0] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[1][2] == 'R') {
			if (field[0][1] == 'E'&& field[0][2] == 'E'&& field[0][3] == 'E'&& field[0][4] == 'E'&& field[1][0] == 'E'&& field[1][1] == 'E'&& field[2][0] == 'E'&& field[2][1] == 'E'&& field[3][0] == 'E'&& field[3][1] == 'E'&& field[4][0] == 'E'&& field[4][1] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[1][3] == 'R') {
			if (field[0][1] == 'E'&& field[0][2] == 'E'&& field[0][3] == 'E'&& field[0][4] == 'E'&& field[1][0] == 'E'&& field[1][1] == 'E'&& field[1][2] == 'E'&& field[2][0] == 'E'&& field[2][1] == 'E' && field[2][2] == 'E' && field[3][0] == 'E'&& field[3][1] == 'E' && field[3][2] == 'E' && field[4][0] == 'E'&& field[4][1] == 'E' && field[4][2] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}		
		}
		else if (field[1][4] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E' && field[1][0] == 'E' && field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[2][0] == 'E' && field[2][1] == 'E' && field[2][2] == 'E' && field[2][3] == 'E' && field[3][0] == 'E' && field[3][1] == 'E' && field[3][2] == 'E' && field[3][3] == 'E' && field[4][0] == 'E' && field[4][1] == 'E' && field[4][2] == 'E' && field[4][3] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[2][0] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E'&& field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[1][4] == 'E'&& field[1][0] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[2][1] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E' && field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[1][4] == 'E' && field[1][0] == 'E' && field[2][0] == 'E' && field[3][0] == 'E' && field[4][0] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[2][2] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E' && field[1][0] == 'E' && field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[1][4] == 'E'  && field[2][0] == 'E' && field[3][0] == 'E' && field[4][0] == 'E' && field[2][1] == 'E' && field[3][1] == 'E' && field[4][1] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[2][3] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E' && field[1][0] == 'E' && field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[1][4] == 'E' && field[2][0] == 'E' && field[3][0] == 'E' && field[4][0] == 'E' && field[2][1] == 'E' && field[3][1] == 'E' && field[4][1] == 'E' && field[2][2] == 'E' && field[3][2] == 'E' && field[4][2] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[2][4] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E' && field[1][0] == 'E' && field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[1][4] == 'E' && field[2][0] == 'E' && field[3][0] == 'E' && field[4][0] == 'E' && field[2][1] == 'E' && field[3][1] == 'E' && field[4][1] == 'E' && field[2][2] == 'E' && field[3][2] == 'E' && field[4][2] == 'E' && field[2][3] == 'E' && field[3][3] == 'E' && field[4][3] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[3][0] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E' && field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[1][4] == 'E' && field[1][0] == 'E'&&field[2][0] == 'E' && field[2][4] == 'E' && field[2][1] == 'E' && field[2][2] == 'E' && field[2][3] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[3][1] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E' && field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[1][4] == 'E' && field[1][0] == 'E' && field[2][0] == 'E' && field[3][0] == 'E' && field[4][0] == 'E' && field[2][4] == 'E' && field[2][1] == 'E' && field[2][2] == 'E' && field[2][3] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[3][2] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E' && field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[1][4] == 'E' && field[1][0] == 'E' && field[2][0] == 'E' && field[3][0] == 'E' && field[4][0] == 'E' && field[2][4] == 'E' && field[2][1] == 'E' && field[3][1] == 'E' && field[4][1] == 'E' && field[2][2] == 'E' && field[2][3] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[3][3] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E' && field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[1][4] == 'E' && field[1][0] == 'E' && field[2][0] == 'E' && field[3][0] == 'E' && field[4][0] == 'E' && field[2][4] == 'E' && field[2][1] == 'E' && field[3][1] == 'E' && field[4][1] == 'E' && field[2][2] == 'E' && field[3][2] == 'E' && field[4][2] == 'E' && field[2][3] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[3][4] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E' && field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[1][4] == 'E' && field[1][0] == 'E' && field[2][0] == 'E' && field[3][0] == 'E' && field[4][0] == 'E' && field[2][4] == 'E' && field[2][1] == 'E' && field[3][1] == 'E' && field[4][1] == 'E' && field[2][2] == 'E' && field[3][2] == 'E' && field[4][2] == 'E' && field[2][3] == 'E' && field[3][3] == 'E' && field[4][3] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[4][0] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E'&& field[0][4] == 'E' && field[1][0] == 'E' && field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[1][4] == 'E' && field[2][0] == 'E' && field[2][1] == 'E' && field[2][2] == 'E' && field[2][3] == 'E' && field[2][4] == 'E' && field[3][0] == 'E' && field[3][1] == 'E' && field[3][2] == 'E' && field[3][3] == 'E' && field[3][4] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[4][1] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E' && field[1][0] == 'E' && field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[1][4] == 'E' && field[2][0] == 'E' && field[2][1] == 'E' && field[2][2] == 'E' && field[2][3] == 'E' && field[2][4] == 'E' && field[3][0] == 'E' && field[3][1] == 'E' && field[3][2] == 'E' && field[3][3] == 'E' && field[3][4] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[4][2] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E' && field[1][0] == 'E' && field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[1][4] == 'E' && field[2][0] == 'E' && field[2][1] == 'E' && field[2][2] == 'E' && field[2][3] == 'E' && field[2][4] == 'E' && field[3][0] == 'E' && field[3][1] == 'E' && field[3][2] == 'E' && field[3][3] == 'E' && field[3][4] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else if (field[4][3] == 'R') {
			if (field[0][1] == 'E' && field[0][2] == 'E' && field[0][3] == 'E' && field[0][4] == 'E' && field[1][0] == 'E' && field[1][1] == 'E' && field[1][2] == 'E' && field[1][3] == 'E' && field[1][4] == 'E' && field[2][0] == 'E' && field[2][1] == 'E' && field[2][2] == 'E' && field[2][3] == 'E' && field[2][4] == 'E' && field[3][0] == 'E' && field[3][1] == 'E' && field[3][2] == 'E' && field[3][3] == 'E' && field[3][4] == 'E') {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else {
			cout << "YES" << '\n';
		}
	}
}