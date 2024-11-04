



#include <bits/stdc++.h>

using namespace std;




long long g, f, d;
long long sum, result;

const int MAXX = (int)1e5;

bool was1[MAXX + 100], was2[MAXX + 100], was3[MAXX + 100];
long long  cnt1[MAXX + 100], cnt2[MAXX + 100], cnt3[MAXX + 100];

long long calc1 (long long  num) {
	return ((num * (num - 1)) / 2ll);
}

long long calc2 (long long  num) {
   	return ((num * (num - 1) * (num - 2)) / 6ll );
}

long long getsum (long long  *arr, int l, int r) {
	return arr[r] - arr[l - 1];
}

int main () {
	cin >> g >> d >> f;
	for (int i = 1; i <= g; ++i) {long long w; cin >> w; was1[w] = true;}
	for (int i = 1; i <= d; ++i) {long long w; cin >> w; was2[w] = true;}
	for (int i = 1; i <= f; ++i) {long long w; cin >> w; was3[w] = true;}
	if (1 >= d) return cout << 0, 0;
	if (2 >= f) return cout << 0, 0;
	for (int i = 1; i <= MAXX; ++i){
		cnt1[i] = cnt1[i - 1] + was1[i];
		cnt2[i] = cnt2[i - 1] + was2[i];
		cnt3[i] = cnt3[i - 1] + was3[i];
	}
	for (long long cnt = 5; cnt <= 1ll * 5e4; ++cnt) {
		long long Cnt = (cnt << 1ll);
		long long sum1 = getsum (cnt1, cnt, Cnt);
		long long sum2 = getsum (cnt2, cnt, Cnt);
		long long sum3 = getsum (cnt3, cnt, Cnt);
		if (sum1 > 0 && sum2 > 1 && sum3 > 2) sum += sum1 * calc1(sum2) * calc2 (sum3) - result;	
		long long sum1_1 = getsum (cnt1, cnt + 1, Cnt);
		long long sum2_1 = getsum (cnt2, cnt + 1, Cnt);
		long long sum3_1 = getsum (cnt3, cnt + 1, Cnt);
		if (sum1_1 > 0 && sum2_1 > 1 && sum3_1 > 2) result = sum1_1 * calc1(sum2_1) * calc2 (sum3_1);
		else result -= result; 
	}
	cout << sum;
    return 0;                                      
}

