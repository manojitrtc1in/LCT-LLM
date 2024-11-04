
using namespace std;




































 
 






























































































 
 
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