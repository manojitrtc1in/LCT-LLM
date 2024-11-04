

using namespace std;







ll pow_mod(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
int ar[1005][1005];
int cnt[8][1005][1005];
double log_val_sm[8][1005][1005];

int main() {
	int n;
	cin >> n;
	char ch;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> ch;
			ar[i][j] = ch - '0';
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(ar[i][j] != 0) {
				if(i - 1 >= 0 && j - 1 >= 0) {
					cnt[0][i][j] = cnt[0][i - 1][j - 1] + 1;
				} else {
					cnt[0][i][j] = 1;
				}
				if(i - 1 >= 0 && j - 1 >= 0) {
					log_val_sm[0][i][j] = log_val_sm[0][i - 1][j - 1] + log(ar[i][j]);
				} else {
					log_val_sm[0][i][j] = log(ar[i][j]);
				}
			} else {
				if(i - 1 >= 0 && j - 1 >= 0) {
					log_val_sm[0][i][j] = log_val_sm[0][i - 1][j - 1];
				} else {
					log_val_sm[0][i][j] = 0;
				}
				cnt[0][i][j] = 0;
			}
		}
	}
	for(int i = n - 1; i >= 0; --i) {
		for(int j = n - 1; j >= 0; --j) {
			if(ar[i][j] != 0) {
				if(i + 1 < n && j + 1 < n) {
					cnt[1][i][j] = cnt[1][i + 1][j + 1] + 1;
				} else {
					cnt[1][i][j] = 1;
				}
				if(i + 1 < n && j + 1 < n) {
					log_val_sm[1][i][j] = log_val_sm[1][i + 1][j + 1] + log(ar[i][j]);
				} else {
					log_val_sm[1][i][j] = log(ar[i][j]);
				}
			} else {
				if(i + 1 < n && j + 1 < n) {
					log_val_sm[1][i][j] = log_val_sm[1][i + 1][j + 1];
				} else {
					log_val_sm[1][i][j] = 0;
				}
				cnt[1][i][j] = 0;
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = n - 1; j >= 0; --j) {
			if(ar[i][j] != 0) {
				if(i - 1 >= 0 && j + 1 < n) {
					cnt[2][i][j] = cnt[2][i - 1][j + 1] + 1;
				} else {
					cnt[2][i][j] = 1;
				}
				if(i - 1 >= 0 && j + 1 < n) {
					log_val_sm[2][i][j] = log_val_sm[2][i - 1][j + 1] + log(ar[i][j]);
				} else {
					log_val_sm[2][i][j] = log(ar[i][j]);
				}
			} else {
				if(i - 1 >= 0 && j + 1 < n) {
					log_val_sm[2][i][j] = log_val_sm[2][i - 1][j + 1];
				} else {
					log_val_sm[2][i][j] = 0;
				}
				cnt[2][i][j] = 0;
			}
		}
	}
	for(int i = n - 1; i >= 0; --i) {
		for(int j = 0; j < n; ++j) {
			if(ar[i][j] != 0) {
				if(i + 1 < n && j - 1 >= 0) {
					cnt[3][i][j] = cnt[3][i + 1][j - 1] + 1;
				} else {
					cnt[3][i][j] = 1;
				}
				if(i + 1 < n && j - 1 >= 0) {
					log_val_sm[3][i][j] = log_val_sm[3][i + 1][j - 1] + log(ar[i][j]);
				} else {
					log_val_sm[3][i][j] = log(ar[i][j]);
				}
			} else {
				if(i + 1 < n && j - 1 >= 0) {
					log_val_sm[3][i][j] = log_val_sm[3][i + 1][j - 1] + 0;
				} else {
					log_val_sm[3][i][j] = 0;
				}
				cnt[3][i][j] = 0;
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(ar[i][j] != 0) {
				if(i - 1 >= 0) {
					cnt[4][i][j] = cnt[4][i - 1][j] + 1;
				} else {
					cnt[4][i][j] = 1;
				}
				if(i - 1 >= 0) {
					log_val_sm[4][i][j] = log_val_sm[4][i - 1][j] + log(ar[i][j]);
				} else {
					log_val_sm[4][i][j] = log(ar[i][j]);
				}
			} else {
				if(i - 1 >= 0) {
					log_val_sm[4][i][j] = log_val_sm[4][i - 1][j] + 0;
				} else {
					log_val_sm[4][i][j] = 0;
				}
				cnt[4][i][j] = 0;
			}
		}
	}
	for(int i = n - 1; i >= 0; --i) {
		for(int j = 0; j < n; ++j) {
			if(ar[i][j] != 0) {
				if(i + 1 < n) {
					cnt[5][i][j] = cnt[5][i + 1][j] + 1;
				} else {
					cnt[5][i][j] = 1;
				}
				if(i + 1 < n) {
					log_val_sm[5][i][j] = log_val_sm[5][i + 1][j] + log(ar[i][j]);
				} else {
					log_val_sm[5][i][j] = log(ar[i][j]);
				}
			} else {
				if(i + 1 < n) {
					log_val_sm[5][i][j] = log_val_sm[5][i + 1][j];
				} else {
					log_val_sm[5][i][j] = 0;
				}
				cnt[5][i][j] = 0;
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(ar[i][j] != 0) {
				if(j - 1 >= 0) {
					cnt[6][i][j] = cnt[6][i][j - 1] + 1;
				} else {
					cnt[6][i][j] = 1;
				}
				if(j - 1 >= 0) {
					log_val_sm[6][i][j] = log_val_sm[6][i][j - 1] + log(ar[i][j]);
				} else {
					log_val_sm[6][i][j] = log(ar[i][j]);
				}
			} else {
				if(j - 1 >= 0) {
					log_val_sm[6][i][j] = log_val_sm[6][i][j - 1] + 0;
				} else {
					log_val_sm[6][i][j] = 0;
				}
				cnt[6][i][j] = 0;
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = n - 1; j >= 0; --j) {
			if(ar[i][j] != 0) {
				if(j + 1 < n) {
					cnt[7][i][j] = cnt[7][i][j + 1] + 1;
				} else {
					cnt[7][i][j] = 1;
				}
				if(j + 1 < n) {
					log_val_sm[7][i][j] = log_val_sm[7][i][j + 1] + log(ar[i][j]);
				} else {
					log_val_sm[7][i][j] = log(ar[i][j]);
				}
			} else {
				if(j + 1 < n) {
					log_val_sm[7][i][j] = log_val_sm[7][i][j + 1];
				} else {
					log_val_sm[7][i][j] = 0;
				}
				cnt[7][i][j] = 0;
			}
		}
	}
	double maxx = 0;
	int x = -1, y = -1;
	int dir, rad;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(ar[i][j] != 0) {
				int res1 = min(cnt[0][i][j], min(cnt[1][i][j], min(cnt[2][i][j], cnt[3][i][j])));
				int res2 = min(cnt[4][i][j], min(cnt[5][i][j], min(cnt[6][i][j], cnt[7][i][j])));

				double cnt1 = 0;
				if(i - res1 >= 0 && j - res1 >= 0) {
					cnt1 += (log_val_sm[0][i][j] - log_val_sm[0][i - res1][j - res1]);
				} else {
					cnt1 += (log_val_sm[0][i][j]);
				}
				if(i + res1 < n && j + res1 < n) {
					cnt1 += (log_val_sm[1][i][j] - log_val_sm[1][i + res1][j + res1]);
				} else {
					cnt1 += (log_val_sm[1][i][j]);
				}
				if(i - res1 >= 0 && j + res1 < n) {
					cnt1 += (log_val_sm[2][i][j] - log_val_sm[2][i - res1][j + res1]);
				} else {
					cnt1 += (log_val_sm[2][i][j]);
				}
				if(i + res1 < n && j - res1 >= 0) {
					cnt1 += (log_val_sm[3][i][j] - log_val_sm[3][i + res1][j - res1]);
				} else {
					cnt1 += (log_val_sm[3][i][j]);
				}
				cnt1 -= 3 * log(ar[i][j]);

				double cnt2 = 0;
				if(i - res2 >= 0) {
					cnt2 += (log_val_sm[4][i][j] - log_val_sm[4][i - res2][j]);
				} else {
					cnt2 += (log_val_sm[4][i][j]);
				}
				if(i + res2 < n) {
					cnt2 += (log_val_sm[5][i][j] - log_val_sm[5][i + res2][j]);
				} else {
					cnt2 += (log_val_sm[5][i][j]);
				}
				if(j - res2 >= 0) {
					cnt2 += (log_val_sm[6][i][j] - log_val_sm[6][i][j - res2]);
				} else {
					cnt2 += (log_val_sm[6][i][j]);
				}
				if(j + res2 < n) {
					cnt2 += (log_val_sm[7][i][j] - log_val_sm[7][i][j + res2]);
				} else {
					cnt2 += (log_val_sm[7][i][j]);
				}
				cnt2 -= 3 * log(ar[i][j]);

				if(cnt1 > cnt2) {
					if(maxx < cnt1) {
						maxx = cnt1;
						dir = 0;
						x = i;
						y = j;
						rad = res1;
					}
				} else {
					if(maxx < cnt2) {
						maxx = cnt2;
						dir = 1;
						x = i;
						y = j;
						rad = res2;
					}
				}
			}
		}
	}
	if(x == -1) {
		ll res = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(ar[i][j]) {
					res = 1;
				}
			}
		}
		cout << res << endl;
	} else {
		if(dir == 0) {
			ll res = 1;
			int stx = x, sty = y;
			int tmp_cnt = rad;
			while(tmp_cnt) {
				res = (res * ar[stx][sty]) % MOD;
				stx -= 1;
				sty -= 1;
				tmp_cnt -= 1;
			}
			stx = x, sty = y;
			tmp_cnt = rad;
			while(tmp_cnt) {
				res = (res * ar[stx][sty]) % MOD;
				stx += 1;
				sty += 1;
				tmp_cnt -= 1;
			}
			stx = x, sty = y;
			tmp_cnt = rad;
			while(tmp_cnt) {
				res = (res * ar[stx][sty]) % MOD;
				stx -= 1;
				sty += 1;
				tmp_cnt -= 1;
			}
			stx = x, sty = y;
			tmp_cnt = rad;
			while(tmp_cnt) {
				res = (res * ar[stx][sty]) % MOD;
				stx += 1;
				sty -= 1;
				tmp_cnt -= 1;
			}
			res = (res * pow_mod(ar[x][y], MOD - 2)) % MOD;
			res = (res * pow_mod(ar[x][y], MOD - 2)) % MOD;
			res = (res * pow_mod(ar[x][y], MOD - 2)) % MOD;
			cout << res << endl;
		} else {
			ll res = 1;
			int stx = x, sty = y;
			int tmp_cnt = rad;
			while(tmp_cnt) {
				res = (res * ar[stx][sty]) % MOD;
				stx -= 1;
				tmp_cnt -= 1;
			}
			stx = x, sty = y;
			tmp_cnt = rad;
			while(tmp_cnt) {
				res = (res * ar[stx][sty]) % MOD;
				stx += 1;
				tmp_cnt -= 1;
			}
			stx = x, sty = y;
			tmp_cnt = rad;
			while(tmp_cnt) {
				res = (res * ar[stx][sty]) % MOD;
				sty -= 1;
				tmp_cnt -= 1;
			}
			stx = x, sty = y;
			tmp_cnt = rad;
			while(tmp_cnt) {
				res = (res * ar[stx][sty]) % MOD;
				sty += 1;
				tmp_cnt -= 1;
			}
			res = (res * pow_mod(ar[x][y], MOD - 2)) % MOD;
			res = (res * pow_mod(ar[x][y], MOD - 2)) % MOD;
			res = (res * pow_mod(ar[x][y], MOD - 2)) % MOD;
			cout << res << endl;
		}
	}
	return 0;
}