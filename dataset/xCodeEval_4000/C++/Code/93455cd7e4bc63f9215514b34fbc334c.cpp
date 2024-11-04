#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include <cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include <sstream>
#include<set>
#include<map>
#include<cstring>
#include<numeric>
#include<bitset>
#include<cassert>
#include<deque>
#include<stack>
#include<queue>
#include <stdio.h>
#include<stdlib.h>


#include<io.h>
#include<fcntl.h>
#include<stdlib.h>
#include<fstream>





#define fr(i, n) for (ll i = 0; i < (n); i++)
#define frs(i, s, n) for(ll i = s; i < n; i++)
#define auto(i, a) for (auto i : (a))
#define rf(i, n) for(int i = (n - 1); i >= 0; i--)
#define rfs(i, n, s) for(int i = n - 1; i >= s; i--)
#define FstPrt ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp(a, b)  make_pair(a, b)
#define pb emplace_back
#define ppb push_back
#define all(a) (a).begin(), (a).end()
#define lb(x) lower_bound((x))
#define re return
#define ub(a) upper_bound((a))
#define MIN -90000000000000001
#define MAX 999999999999999999
#define INF 10000000
#define fi first
#define se second
#define siz(s) ((int)s.size())
#define FILE(name_in, name_out) ifstream fin("input.txt"); ofstream fout("output.txt");
#define cont continue
#define MAX_INT 100000000000
#define MIN_INT -2147483648
#define frso(i, s, n) for(int i = s; (i % n) != (s % n); i++)
#define clear_all(a) memset(a, 0, sizeof(a))











using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;
typedef vector<int> vii;
typedef pair<int, int> pii;
typedef string stirng;






















struct tre {
    ll fi, se, tr;
};


struct way {
    int X, Y;
    int stp, mood, K, D, h, id, mh;
};





ll n, m;

bool in_field(int x, int y) {
    re(x >= 0 && y >= 0 && x < 8 && y < 8);
}


int tpp = 1;

int kol[50][500000];
int w[50][500000];



void solve() {
    FstPrt;

    cin >> n >> m;
    fr(i, 50)
        fr(j, m) {
        w[i][j] = 0;
        kol[i][j] = 0;
    }
    fr(i, n)
        fr(j, m) {
        char a;
        cin >> a;
        kol[a - 'a'][j]++;
    }
    fr(i, n - 1)
        fr(j, m) {
        char a;
        cin >> a;
        w[a - 'a'][j]++;
    }
    string ans;
    fr(j, m) {
        for (char i = 'a'; i <= 'z'; i++) {
            if (kol[i - 'a'][j] != w[i - 'a'][j]) {
                ans.ppb(i);
                break;
            }
        }
    }
    cout << ans << endl;
}




int main() {
    

#ifdef Feed_The_Cats
    freopen("INPUT.txt", "r", stdin);
    freopen("INPUT.txt", "w", stdout);
#endif
    FstPrt;



    cin >> tpp;
    while (tpp--) {
        solve();
    }

}