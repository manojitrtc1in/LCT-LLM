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
#define ll = long long;
#define vi = vector<int>;
#define vvi = vector<vi>;
#define vll = vector<ll>;
#define vvll = vector<vll>;
#define vb = vector<bool>;
#define vd = vector<double>;
#define vs = vector<string>;
#define pii = pair<int, int>;
#define pll = pair<ll, ll>;
#define pdd = pair<double, double>;
#define vpii = vector<pii>;
#define vvpii = vector<vpii>;
#define vpll = vector<pll>;
#define vvpll = vector<vpll>;
#define vpdd = vector<pdd>;
#define vvpdd = vector<vpdd>;

 
 






























































































 
 
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