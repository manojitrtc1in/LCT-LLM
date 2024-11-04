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
const int dx[] = {1,-1,1,-1};
const int dy[] = {-1,1,1,-1};

bool f = NULL, f1 = NULL, flag = NULL, flag_NULL = NULL, flag_true = true, Flag = NULL;
ll II = 0, x, y, xx, yy, ans, ans1, ans2 = 0, mx = -1e9, mn = 1e9;
ll SUM = 0,SUM1 = 0;
ll n, m, k, l;
str s1, s2;
sstr ss, ss1, ss2;
ll Error[10001];
ll Connect[10001];
ll X, Y, X1, Y1, KOL;
ll q1 = 0,q2 = 0;
















ll g;
ll stn = 0,stn1 = 0, stn2 = 0;
pair<int,int> q[101*101];
ll K, L, P[40],Z[40];
ch a[101][101];
ll A[101][101];

ve<ll> b1;
ll st[40 * 40],st1[40 * 40];
ll ralph, lauren;
ve<ch> b(10001);
void add(int y, int x, int k)
{
  if(x <= 0 || x > m || y <= 0 || y > n)return;
  A[y][x] = k;
  fr(i,1,KOL) if(a[y][x] != b[i])return;
  q[q1++] = make_pair(y,x);
}


int main()
{
    ll POL = 0;

    cin.tie(0);cout.tie(0);
    CF
    {
        cin >> n >> m;

        ll j = 1, o = 1;

        fr(i,0,n)
        {
          cout<<ch(96 + j);
          if(j == m){j = 0;}
          ++ j;
        }
        cout<<endl;
    }

    return NULL;
}
