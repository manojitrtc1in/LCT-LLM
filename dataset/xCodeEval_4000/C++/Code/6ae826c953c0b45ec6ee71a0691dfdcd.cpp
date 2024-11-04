#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<unordered_map>
#include<assert.h>
#include<time.h>
#include<stdlib.h>
#include<random>
using namespace std;
using lld = long long int;
using pll = pair<lld, lld>;
using lf = double;
using pff = pair<lf, lf>;
using pii = pair<int, int>;
using pli = pair<lld, int>;
int n, m, p;
pli a[4][200009];
int al[4];
int main() {
	int i, j, k;
	int t = 1, tv = 0;
	

	t = 1;
	while (t--) {
		scanf("%d %d %d", &n, &m, &p);
		for (i = 0; i < n; i++) {
			lld x;
			int y, z;
			scanf("%lld %d %d", &x, &y, &z);
			a[y * 2 + z][al[y * 2 + z]++] = pli(x, i);
		}
		for (i = 0; i < 4; i++) {
			sort(a[i], a[i] + al[i]);
		}
		int i0, i1;
		if (al[3] > p) {
			i0 = 0;
			i1 = p;
		}
		else {
			i0 = p - al[3];
			i1 = al[3];
		}
		if (i0 * 2 + i1 > m || i0 > al[1] || i0 > al[2]) {
			printf("-1\n");
			continue;
		}
		int j0, j1, j2, j3;
		lld res = 0;
		for (i = 0; i < i0; i++) {
			res += a[1][i].first;
			res += a[2][i].first;
		}
		for (i = 0; i < i1; i++) {
			res += a[3][i].first;
		}
		j0 = 0;
		j1 = i0;
		j2 = i0;
		j3 = i1;
		int cnt = i0 * 2 + i1;
		for (; cnt < m;) {
			if (j3 < al[3]) {
				if (j0 < al[0]) {
					if (j1 < al[1]) {
						if (j2 < al[2]) {
							if (a[0][j0] < a[1][j1]) {
								if (a[0][j0] < a[2][j2]) {
									if (a[0][j0] < a[3][j3]) {
										res += a[0][j0].first;
										j0++;
									}
									else {
										res += a[3][j3].first;
										j3++;
									}
								}
								else {
									if (a[2][j2] < a[3][j3]) {
										res += a[2][j2].first;
										j2++;
									}
									else {
										res += a[3][j3].first;
										j3++;
									}
								}
							}
							else if (a[2][j2] < a[1][j1]) {
								if (a[2][j2] < a[3][j3]) {
									res += a[2][j2].first;
									j2++;
								}
								else {
									res += a[3][j3].first;
									j3++;
								}
							}
							else {
								if (a[1][j1] < a[3][j3]) {
									res += a[1][j1].first;
									j1++;
								}
								else {
									res += a[3][j3].first;
									j3++;
								}
							}
						}
						else {
							if (a[0][j0] < a[1][j1]) {
								if (a[0][j0] < a[3][j3]) {
									res += a[0][j0].first;
									j0++;
								}
								else {
									res += a[3][j3].first;
									j3++;
								}
							}
							else {
								if (a[1][j1] < a[3][j3]) {
									res += a[1][j1].first;
									j1++;
								}
								else {
									res += a[3][j3].first;
									j3++;
								}
							}
						}
					}
					else if (j2 < al[2]) {
						if (a[0][j0] < a[2][j2]) {
							if (a[0][j0] < a[3][j3]) {
								res += a[0][j0].first;
								j0++;
							}
							else {
								res += a[3][j3].first;
								j3++;
							}
						}
						else {
							if (a[2][j2] < a[3][j3]) {
								res += a[2][j2].first;
								j2++;
							}
							else {
								res += a[3][j3].first;
								j3++;
							}
						}
					}
					else {
						if (a[0][j0] < a[3][j3]) {
							res += a[0][j0].first;
							j0++;
						}
						else {
							res += a[3][j3].first;
							j3++;
						}
					}
				}
				else {
					if (j1 < al[1]) {
						if (j2 < al[2]) {
							if (a[1][j1] < a[2][j2]) {
								if (a[1][j1] < a[3][j3]) {
									res += a[1][j1].first;
									j1++;
								}
								else {
									res += a[3][j3].first;
									j3++;
								}
							}
							else {
								if (a[2][j2] < a[3][j3]) {
									res += a[2][j2].first;
									j2++;
								}
								else {
									res += a[3][j3].first;
									j3++;
								}
							}
						}
						else {
							if (a[1][j1] < a[3][j3]) {
								res += a[1][j1].first;
								j1++;
							}
							else {
								res += a[3][j3].first;
								j3++;
							}
						}
					}
					else if (j2 < al[2]) {
						if (a[2][j2] < a[3][j3]) {
							res += a[2][j2].first;
							j2++;
						}
						else {
							res += a[3][j3].first;
							j3++;
						}
					}
					else {
						res += a[3][j3].first;
						j3++;
					}
				}
			}
			else {
				if (j0 < al[0]) {
					if (j1 < al[1]) {
						if (j2 < al[2]) {
							if (a[0][j0] < a[1][j1]) {
								if (a[0][j0] < a[2][j2]) {
									res += a[0][j0].first;
									j0++;
								}
								else {
									res += a[2][j2].first;
									j2++;
								}
							}
							else if (a[2][j2] < a[1][j1]) {
								res += a[2][j2].first;
								j2++;
							}
							else {
								res += a[1][j1].first;
								j1++;
							}
						}
						else {
							if (a[0][j0] < a[1][j1]) {
								res += a[0][j0].first;
								j0++;
							}
							else {
								res += a[1][j1].first;
								j1++;
							}
						}
					}
					else if (j2 < al[2]) {
						if (a[0][j0] < a[2][j2]) {
							res += a[0][j0].first;
							j0++;
						}
						else {
							res += a[2][j2].first;
							j2++;
						}
					}
					else {
						res += a[0][j0].first;
						j0++;
					}
				}
				else {
					if (j1 < al[1]) {
						if (j2 < al[2]) {
							if (a[1][j1] < a[2][j2]) {
								res += a[1][j1].first;
								j1++;
							}
							else {
								res += a[2][j2].first;
								j2++;
							}
						}
						else {
							res += a[1][j1].first;
							j1++;
						}
					}
					else if (j2 < al[2]) {
						res += a[2][j2].first;
						j2++;
					}
					else {
						printf("-1\n");
						return 0;
					}
				}
			}
			cnt++;
		}

		lld cur = res;
		int ri0 = i0;
		int ri1 = i1;
		int rj0 = j0;
		int rj1 = j1;
		int rj2 = j2;
		int rj3 = j3;
		while (i1 > 0 && i0 < al[1] && i0 < al[2] ) {
			int need = 0;
			i1--;
			j3--;
			cur -= a[3][j3].first;
			need++;
			if (i0 == j1) {
				cur += a[1][i0].first;
				j1++;
				need--;
			}
			if (i0 == j2) {
				cur += a[2][i0].first;
				j2++;
				need--;
			}
			i0++;

			if (need == -1) {
				if (j0 == 0)break;
				j0--;
				cur -= a[0][j0].first;
			}
			else if (need == 1) {
				int pres = res;
				res = cur;
				if (j3 < al[3]) {
					if (j0 < al[0]) {
						if (j1 < al[1]) {
							if (j2 < al[2]) {
								if (a[0][j0] < a[1][j1]) {
									if (a[0][j0] < a[2][j2]) {
										if (a[0][j0] < a[3][j3]) {
											res += a[0][j0].first;
											j0++;
										}
										else {
											res += a[3][j3].first;
											j3++;
										}
									}
									else {
										if (a[2][j2] < a[3][j3]) {
											res += a[2][j2].first;
											j2++;
										}
										else {
											res += a[3][j3].first;
											j3++;
										}
									}
								}
								else if (a[2][j2] < a[1][j1]) {
									if (a[2][j2] < a[3][j3]) {
										res += a[2][j2].first;
										j2++;
									}
									else {
										res += a[3][j3].first;
										j3++;
									}
								}
								else {
									if (a[1][j1] < a[3][j3]) {
										res += a[1][j1].first;
										j1++;
									}
									else {
										res += a[3][j3].first;
										j3++;
									}
								}
							}
							else {
								if (a[0][j0] < a[1][j1]) {
									if (a[0][j0] < a[3][j3]) {
										res += a[0][j0].first;
										j0++;
									}
									else {
										res += a[3][j3].first;
										j3++;
									}
								}
								else {
									if (a[1][j1] < a[3][j3]) {
										res += a[1][j1].first;
										j1++;
									}
									else {
										res += a[3][j3].first;
										j3++;
									}
								}
							}
						}
						else if (j2 < al[2]) {
							if (a[0][j0] < a[2][j2]) {
								if (a[0][j0] < a[3][j3]) {
									res += a[0][j0].first;
									j0++;
								}
								else {
									res += a[3][j3].first;
									j3++;
								}
							}
							else {
								if (a[2][j2] < a[3][j3]) {
									res += a[2][j2].first;
									j2++;
								}
								else {
									res += a[3][j3].first;
									j3++;
								}
							}
						}
						else {
							if (a[0][j0] < a[3][j3]) {
								res += a[0][j0].first;
								j0++;
							}
							else {
								res += a[3][j3].first;
								j3++;
							}
						}
					}
					else {
						if (j1 < al[1]) {
							if (j2 < al[2]) {
								if (a[1][j1] < a[2][j2]) {
									if (a[1][j1] < a[3][j3]) {
										res += a[1][j1].first;
										j1++;
									}
									else {
										res += a[3][j3].first;
										j3++;
									}
								}
								else {
									if (a[2][j2] < a[3][j3]) {
										res += a[2][j2].first;
										j2++;
									}
									else {
										res += a[3][j3].first;
										j3++;
									}
								}
							}
							else {
								if (a[1][j1] < a[3][j3]) {
									res += a[1][j1].first;
									j1++;
								}
								else {
									res += a[3][j3].first;
									j3++;
								}
							}
						}
						else if (j2 < al[2]) {
							if (a[2][j2] < a[3][j3]) {
								res += a[2][j2].first;
								j2++;
							}
							else {
								res += a[3][j3].first;
								j3++;
							}
						}
						else {
							res += a[3][j3].first;
							j3++;
						}
					}
				}
				else {
					if (j0 < al[0]) {
						if (j1 < al[1]) {
							if (j2 < al[2]) {
								if (a[0][j0] < a[1][j1]) {
									if (a[0][j0] < a[2][j2]) {
										res += a[0][j0].first;
										j0++;
									}
									else {
										res += a[2][j2].first;
										j2++;
									}
								}
								else if (a[2][j2] < a[1][j1]) {
									res += a[2][j2].first;
									j2++;
								}
								else {
									res += a[1][j1].first;
									j1++;
								}
							}
							else {
								if (a[0][j0] < a[1][j1]) {
									res += a[0][j0].first;
									j0++;
								}
								else {
									res += a[1][j1].first;
									j1++;
								}
							}
						}
						else if (j2 < al[2]) {
							if (a[0][j0] < a[2][j2]) {
								res += a[0][j0].first;
								j0++;
							}
							else {
								res += a[2][j2].first;
								j2++;
							}
						}
						else {
							res += a[0][j0].first;
							j0++;
						}
					}
					else {
						if (j1 < al[1]) {
							if (j2 < al[2]) {
								if (a[1][j1] < a[2][j2]) {
									res += a[1][j1].first;
									j1++;
								}
								else {
									res += a[2][j2].first;
									j2++;
								}
							}
							else {
								res += a[1][j1].first;
								j1++;
							}
						}
						else if (j2 < al[2]) {
							res += a[2][j2].first;
							j2++;
						}
						else {
							res = pres;
							break;
						}
					}
				}
				cur = res;
				res = pres;
			}
			if (j0 + j1 + j2 + j3 != m)break;
			if (res > cur) {
				res = cur;
				ri0 = i0;
				ri1 = i1;
				rj0 = j0;
				rj1 = j1;
				rj2 = j2;
				rj3 = j3;
			}
		}
		printf("%lld\n", res);
		for (i = 0; i < ri1; i++) {
			printf("%d ", a[3][i].second + 1);
		}
		for (i = ri1; i < rj3; i++) {
			printf("%d ", a[3][i].second + 1);
		}
		for (i = 0; i < ri0; i++) {
			printf("%d ", a[1][i].second + 1);
		}
		for (i = 0; i < ri0; i++) {
			printf("%d ", a[2][i].second + 1);
		}
		for (i = 0; i < rj0; i++) {
			printf("%d ", a[0][i].second + 1);
		}
		for (i = ri0; i < rj1; i++) {
			printf("%d ", a[1][i].second + 1);
		}
		for (i = ri0; i < rj2; i++) {
			printf("%d ", a[2][i].second + 1);
		}
	}
	return 0;
}