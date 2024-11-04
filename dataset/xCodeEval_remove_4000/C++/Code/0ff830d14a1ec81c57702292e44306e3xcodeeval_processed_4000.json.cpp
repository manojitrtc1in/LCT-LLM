



using namespace std;










ifstream fin("input.txt");
ofstream fout("output.txt");

bool isPrime(int x) {
	if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
	for (int i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1;
}

int NumDigits(int x) {
	

	return (x < 10 ? 1 :
		(x < 100 ? 2 :
		(x < 1000 ? 3 :
			(x < 10000 ? 4 :
			(x < 100000 ? 5 :
				(x < 1000000 ? 6 :
				(x < 10000000 ? 7 :
					(x < 100000000 ? 8 :
					(x < 1000000000 ? 9 :
						10)))))))));
}

inline void boostIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
}

typedef long long int ll;
typedef long double ld;
























ll Pow10[19] = { (ll)1,(ll)1e1,(ll)1e2,(ll)1e3,(ll)1e4,(ll)1e5,(ll)1e6,(ll)1e7,(ll)1e8,(ll)1e9,(ll)1e10,
				(ll)1e11,(ll)1e12,(ll)1e13,(ll)1e14,(ll)1e15,(ll)1e16,(ll)1e17,(ll)1e18 };



ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }













template<typename T> inline T getint() {
	T val = 0;
	char c;

	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}

	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));

	return val * (neg ? -1 : 1);
}







int Mod = 1e9 + 7;





int mul(int a, int b, int c = 1) {
	a %= Mod; b %= Mod; c %= Mod;
	return (a * b % Mod * c % Mod);
}

int Pow(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 0) {
		int x = Pow(a, b / 2);
		return mul(x, x);
	}
	else {
		int x = Pow(a, b / 2);
		return  mul(a, x, x);
	}
}
int inf = 2e9;
struct cords {
	int x = 0;
	int y = 0;
};



	

		

	




int32_t main() {
	boostIO();
	

	

	int n, m; cin >> n >> m;
	bool flag = 0;
	if (n > m) {
		flag = 1;
		swap(n, m);
	}

	vector<vector<char>> A(n + 2, vector<char>(m));
	if (flag == 0) {
		fori(n) {
			forj(m) {
				cin >> A[i][j];
				A[i][j] -= '0';
			}
		}
	}
	else {
		fori(m) {
			forj(n) {
				cin >> A[j][i];
				A[j][i] -= '0';
			}
		}
	}


	if (n > 3) {
		cout << -1 << endl;
		return 0;
	}
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}

	if (n == 2) {
		const int size = 500001;
		

		int dp[2][size][2][2][2];
		for (int a = 0; a < 3; ++a) {
			for (int b = 0; b < size; ++b) {
				for (int c = 0; c < 2; ++c) {
					for (int d = 0; d < 2; ++d) {
						for (int e = 0; e < 2; ++e) {
							dp[a][b][c][d][e] = inf;
						}
					}
				}
			}
		}

		for (int i = 0; i < m; ++i) {
			for (int a = 0; a <= 1; ++a) {
				for (int b = 0; b <= 1; ++b) {
					for (int c = 0; c <= 1; ++c) {
						if (i != 0)
							dp[0][i][a][b][c] = (A[0][i] != a) + (A[0][i - 1] != b);
						else
							dp[0][i][a][b][c] = (A[0][i] != a);
					}
				}
			}
		}

		for (int a = 0; a <= 1; ++a) {
			for (int b = 0; b <= 1; ++b) {
				for (int c = 0; c <= 1; ++c) {
					dp[1][0][a][b][c] = (A[1][0] != a) + (A[0][0] != c);
				}
			}
		}

		for (int a = 0; a <= 1; ++a) {
			for (int b = 0; b <= 1; ++b) {
				for (int c = 0; c <= 1; ++c) {
					int g = inf;
					for (int d = 0; d <= 1; ++d) {
						for (int e = 0; e <= 1; ++e) {
							g = min(g, dp[1][0][c][d][e]);
						}
					}
					dp[2][0][a][b][c] = (A[2][0] != a) + g;
				}
			}
		}

		

		for (int j = 1; j <= 2; ++j) {
			for (int i = 1; i < m; ++i) {
				for (int a = 0; a <= 1; ++a) {
					for (int b = 0; b <= 1; ++b) {
						for (int c = 0; c <= 1; ++c) {
							for (int d = 0; d <= 1; ++d) {
								if ((a + b + c + d) % 2 == 0) continue;

								int v = 0;
								v += (A[j][i] != a);
								

								v += min(dp[j][i - 1][b][0][d], dp[j][i - 1][b][1][d]);
								

								v += min(dp[j - 1][i][c][d][0], dp[j - 1][i][c][d][1]);
								

								


								int g = inf;
								for (int e = 0; e <= 1; ++e) {
									for (int f = 0; f <= 1; ++f) {
										g = min(g, dp[j - 1][i - 1][d][e][f]);
									}
								}
								

								dp[j][i][a][b][c] = min(dp[j][i][a][b][c], v - g);
								if (j == 1 && i == m - 1) {
									
								}

							}
						}
					}
				}
			}
		}

		



		int ans = inf;
		for (int a = 0; a <= 1; ++a) {
			for (int b = 0; b <= 1; ++b) {
				for (int c = 0; c <= 1; ++c) {
					ans = min(ans, dp[n - 1][m - 1][a][b][c]);
				}
			}
		}
		cout << ans << " ";



		Return;
	}



	

	

	const int size = 333334;
	

	int dp[3][size][2][2][2][2][2];
	for (int a = 0; a < 3; ++a) {
		for (int b = 0; b < size; ++b) {
			for (int c = 0; c < 2; ++c) {
				for (int d = 0; d < 2; ++d) {
					for (int e = 0; e < 2; ++e) {
						for (int x = 0; x < 2; ++x) {
							for (int y = 0; y < 2; ++y) {
								dp[a][b][c][d][e][x][y] = inf;
							}
						}

					}
				}
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int a = 0; a <= 1; ++a) {
			for (int b = 0; b <= 1; ++b) {
				for (int c = 0; c <= 1; ++c) {
					for (int x = 0; x <= 1; ++x) {
						for (int y = 0; y <= 1; ++y) {
							int d = 0;
							if ((a + c + b) % 2 == 0) d = 1;
							else d = 0;

							int s = 0;
							if ((x + b + d) % 2 == 0) s = 1;
							else s = 0;

							int z = 0;
							if ((d + c + y) % 2 == 0) z = 1;
							else z = 0;

							if (i != 0)
								dp[0][i][a][b][c][x][y] = (A[0][i] != a) + (min(dp[0][i - 1][b][x][d][0][z], dp[0][i - 1][b][x][d][1][z]));
							else
								dp[0][i][a][b][c][x][y] = (A[0][i] != a);
						}
					}
				}
			}
		}
	}

	for (int a = 0; a <= 1; ++a) {
		for (int b = 0; b <= 1; ++b) {
			for (int c = 0; c <= 1; ++c) {
				for (int x = 0; x <= 1; ++x) {
					for (int y = 0; y <= 1; ++y) {
						dp[1][0][a][b][c][x][y] = (A[1][0] != a) + (A[0][0] != c);
					}
				}

			}
		}
	}

	for (int a = 0; a <= 1; ++a) {
		for (int b = 0; b <= 1; ++b) {
			for (int c = 0; c <= 1; ++c) {
				for (int x = 0; x <= 1; ++x) {
					for (int y = 0; y <= 1; ++y) {
						int d = 0;
						if ((a + c + b) % 2 == 0) d = 1;
						else d = 0;

						int s = 0;
						if ((x + b + d) % 2 == 0) s = 1;
						else s = 0;

						int z = 0;
						if ((d + c + y) % 2 == 0) z = 1;
						else z = 0;
						dp[2][0][a][b][c][x][y] = 1;
						dp[2][0][a][b][c][x][y] = (A[2][0] != a) + min(dp[1][0][c][d][y][s][0], dp[1][0][c][d][y][s][1]);
					}
				}
			}
		}
	}

	

	

	

	

	

	

	

	for (int i = 1; i <= 2; ++i) {
		for (int j = 1; j < m; ++j) {
			for (int a = 0; a <= 1; ++a) {
				for (int b = 0; b <= 1; ++b) {
					for (int c = 0; c <= 1; ++c) {
						for (int d = 0; d <= 1; ++d) {
							if ((a + b + c + d) % 2 == 0) continue;
							for (int x = 0; x < 2; ++x) {
								for (int y = 0; y < 2; ++y) {
									int s, z;
									if ((x + b + d) % 2 == 0) s = 1;
									else s = 0;

									if ((d + c + y) % 2 == 0) z = 1;
									else z = 0;

									int v = 0;
									v += (A[i][j] != a);
									v += min(dp[i][j - 1][b][x][d][0][z], dp[i][j - 1][b][x][d][1][z]);
									v += min(dp[i - 1][j][c][d][y][s][0], dp[i - 1][j][c][d][y][s][1]);


									int g = inf;


									for (int x1 = 0; x1 < 2; ++x1) {
										for (int y1 = 0; y1 < 2; ++y1) {
											g = min(g, dp[i - 1][j - 1][d][s][z][x1][y1]);
										}
									}

									dp[i][j][a][b][c][x][y] = min(dp[i][j][a][b][c][x][y], v - g);
								}
							}
						}
					}
				}
			}
		}
	}


	


	int ans = inf;
	for (int a = 0; a <= 1; ++a) {
		for (int b = 0; b <= 1; ++b) {
			for (int c = 0; c <= 1; ++c) {
				for (int x = 0; x <= 1; ++x) {
					for (int y = 0; y <= 1; ++y) {
						ans = min(ans, dp[n - 1][m - 1][a][b][c][x][y]);
					}
				}

			}
		}
	}
	cout << ans;



	Return;
}