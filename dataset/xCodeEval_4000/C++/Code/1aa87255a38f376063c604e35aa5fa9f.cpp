#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <cassert>



using namespace std;
#define fr(i, a, b) for(int i = (a); i < (b); ++i)

#define rf(i, a, b) for(int i = (a); i > (b); --i)

#define fe(x, y) for(auto& x : y)

#define br break
#define cn continue
#define ch char
#define ret return 0
#define fix()  cout<<fixed<<setprecision(2);
#define ve vector
#define F first
#define S second
#define cl(s) (int)(s).clear()
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define CF int t; cin >> t; while(t--)
#define KYF freopen ("input.txt", "r", stdin);freopen ("output.txt", "w", stdout)


typedef long long ll;
typedef long long ll;
typedef long double ld;




typedef string str;
typedef stringstream sstr;

typedef bool bl;

const ll N = 1e3 * 1e3, M = 1e2;





bool f = NULL, f1 = NULL, flag = NULL, flag_NULL = NULL, flag_true = true, Flag = NULL;
ll II = 0, xx, yy, ans, ans1, ans2 = 0, mx = -1e9, mn = 1e9;
ll SUM = 0,SUM1 = 0;
ll n, m, k, l;
str s1, s2;
sstr ss, ss1, ss2;
ll Error[10001];
ll Connect[10001];
ll X[101], Y[101], X1, Y1, KOL;
ll q1 = 0,q2 = 0;
















ll g;
ll stn = 0,stn1 = 0, stn2 = 0;
pair<int,int> q[101*101];
ll K, L, P[40],Z[40];
ll a[1001][1001];
ll A[10001];
ll c[101][101];
ll x[10001];
ll y[10001];


ll b[10001];
ve<ll> b1;
str s;
ll st[40 * 40],st1[40 * 40];
ll ralph, lauren;


ll pyatna;

void add(int x, int y)
{
   

    q[q1++] = make_pair(x,y);
    a[x][y] = 2;
    pyatna--;
}

int main()
{
    cin >> n;
    pyatna = n;
    fr(i,0,n) cin >> X[i] >> Y[i];
    fr(i,0,n)
    {
        if(a[X[i]][Y[i]] == 0)
        {
            q1 = q2 = 0;
            add(X[i], Y[i]);
            pyatna++;
            while(q1 != q2)
            {
                int x = q[q2].first, y = q[q2].second;
                fr(j,1,n)if((x == X[j] || y == Y[j]) && a[X[j]][Y[j]] == 0) add(X[j], Y[j]);
                q2++;
            }
        }
    }
    cout << pyatna - 1 << endl;
    return 0;
}
