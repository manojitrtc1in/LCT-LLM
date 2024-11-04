#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define umap unordered_map
#define INF INT_MAX
#define MOD 1e9 + 7
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (a) : (b))
#define lb lower_bound
#define ub upper_bound
#define resz resize
#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
#define beginning ios_base::sync_with_stdio(0),cin.tie(0),out.tie(0);
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;

 
 






























































































 
 
int n, m;
map <vector<int>, int> seen;
int query (int x1, int y1, int x2, int y2) {
    vector <int> cur;
    cur.pb(x1);
    cur.pb(y1);
    cur.pb(x2);
    cur.pb(y2);
    if (seen.find(cur) != seen.end()) return seen[cur];
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    cin >> m;
    return seen[cur] = m;
}
signed main () {
    
    cin >> n;
    set <vector <int> > ans;
    
    

    if (true) {
        vector <int> tmp;
        int x1 = 1, x2 = n, y1 = 1, y2 = n;
        int st = 1, end = n;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end) / 2;
            m = query(x1, y1, mid, y2);
            

            

            if (mid == st && m == 1) break;
            if (m == 0) {
                if (st == mid) st++;
                else st = mid;
            } else {    
                end = mid;
            }
        }
        x2 = st;
        st = 1, end = x2;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end + 1) / 2;
            m = query(mid, y1, x2, y2);
            

            

            if (mid == end && m == 1) break;
            if (m == 0) {
                if (mid == end) end--;
                else end = mid;
            } else {    
                st = mid;
            }
        }
        x1 = end;
        st = 1, end = n;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end) / 2;
            m = query(x1, y1, x2, mid);
            

            

            if (mid == st && m == 1) break;
            if (m == 0) {
                if (st == mid) st++;
                else st = mid;
            } else {    
                end = mid;
            }
        }
        y2 = st;
        st = 1, end = y2;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end + 1) / 2;
            m = query(x1, mid, x2, y2);
            

            

            if (mid == end && m == 1) break;
            if (m == 0) {
                if (mid == end) end--;
                else end = mid;
            } else {    
                st = mid;
            }
        }
        y1 = end;
        tmp.pb(x1);
        tmp.pb(y1);
        tmp.pb(x2);
        tmp.pb(y2);
        ans.insert(tmp);
    }
    

    if (true) {
        vector <int> tmp;
        int x1 = 1, x2 = n, y1 = 1, y2 = n;
        int st = 1, end = n;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end + 1) / 2;
            m = query(mid, y1, x2, y2);
            if (mid == end && m >= 1) break;
            if (m == 0) {
                if (mid == end) end--;
                else end = mid;
            } else {    
                st = mid;
            }
        }
        x1 = end;
        st = x1, end = n;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end) / 2;
            m = query(x1, y1, mid, y2);
            if (mid == st && m >= 1) break;
            if (m == 0) {
                if (st == mid) st++;
                else st = mid;
            } else {    
                end = mid;
            }
        }
        x2 = st;
        st = 1, end = n;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end + 1) / 2;
            m = query(x1, mid, x2, y2);
            if (mid == end && m >= 1) break;
            if (m == 0) {
                if (mid == end) end--;
                else end = mid;
            } else {    
                st = mid;
            }
        }
        y1 = end;
        st = y1, end = n;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end) / 2;
            m = query(x1, y1, x2, mid);
            if (mid == st && m >= 1) break;
            if (m == 0) {
                if (st == mid) st++;
                else st = mid;
            } else {    
                end = mid;
            }
        }
        y2 = st;
        tmp.pb(x1);
        tmp.pb(y1);
        tmp.pb(x2);
        tmp.pb(y2);
        ans.insert(tmp);
    }
    

    if (ans.size() == 1) {
        vector <int> tmp;
        int x1 = 1, x2 = n, y1 = 1, y2 = n;
        int st = 1, end = n;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end) / 2;
            m = query(x1, y1, x2, mid);
            if (mid == st && m == 1) break;
            if (m == 0) {
                if (st == mid) st++;
                else st = mid;
            } else {    
                end = mid;
            }
        }
        y2 = st;
        st = 1, end = y2;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end + 1) / 2;
            m = query(x1, mid, x2, y2);
            if (mid == end && m == 1) break;
            if (m == 0) {
                if (mid == end) end--;
                else end = mid;
            } else {    
                st = mid;
            }
        }
        y1 = end;
        st = 1, end = n;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end) / 2;
            m = query(x1, y1, mid, y2);
            if (mid == st && m == 1) break;
            if (m == 0) {
                if (st == mid) st++;
                else st = mid;
            } else {    
                end = mid;
            }
        }
        x2 = st;
        st = 1, end = x2;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end + 1) / 2;
            m = query(mid, y1, x2, y2);
            if (mid == end && m == 1) break;
            if (m == 0) {
                if (mid == end) end--;
                else end = mid;
            } else {    
                st = mid;
            }
        }
        x1 = end;
        tmp.pb(x1);
        tmp.pb(y1);
        tmp.pb(x2);
        tmp.pb(y2);
        ans.insert(tmp);
    }
    

    if (ans.size() == 1) {
        vector <int> tmp;
        int x1 = 1, x2 = n, y1 = 1, y2 = n;
        int st = 1, end = n;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end + 1) / 2;
            m = query(x1, mid, x2, y2);
            

            

            if (mid == end && m == 1) break;
            if (m == 0) {
                if (mid == end) end--;
                else end = mid;
            } else {    
                st = mid;
            }
        }
        y1 = end;
        st = y1, end = n;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end) / 2;
            m = query(x1, y1, x2, mid);
            

            

            if (mid == st && m == 1) break;
            if (m == 0) {
                if (st == mid) st++;
                else st = mid;
            } else {    
                end = mid;
            }
        }
        y2 = st;
        st = 1, end = n;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end + 1) / 2;
            m = query(mid, y1, x2, y2);
            

            

            if (mid == end && m == 1) break;
            if (m == 0) {
                if (mid == end) end--;
                else end = mid;
            } else {    
                st = mid;
            }
        }
        x1 = end;
        st = x1, end = n;
        

        while (true) {
            if (st == end) break;
            int mid = (st + end) / 2;
            m = query(x1, y1, mid, y2);
            

            

            if (mid == st && m == 1) break;
            if (m == 0) {
                if (st == mid) st++;
                else st = mid;
            } else {    
                end = mid;
            }
        }
        x2 = st;
        tmp.pb(x1);
        tmp.pb(y1);
        tmp.pb(x2);
        tmp.pb(y2);
        ans.insert(tmp);
    }
    cout << "! ";
    for (auto el: ans) 
    for (auto num: el) 
        cout << num << ' ';
    
    cout << '\n';
	return 0;
}