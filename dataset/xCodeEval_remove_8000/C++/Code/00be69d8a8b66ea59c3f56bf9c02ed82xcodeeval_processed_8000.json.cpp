









using namespace std;
int n, m, s, ans[100005];
struct student {
    int b, c, ind;
}ss[100005];

pair<int, int> bug[100005];
bool cmp(student a, student b) {
    return a.b < b.b;
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        cin >> bug[i].first;
        bug[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> ss[i].b;
        ss[i].ind = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> ss[i].c;
    }
    sort(bug, bug + m);
    sort(ss, ss + n, cmp);
    ans[0] = -1;
    int l = 1, r = m + 1;
    while (l < r) {
        bool found = true;
        int mid = (r + l) >> 1;
        int bi = m - 1, si = n - 1;
        int sum = 0, temp[100005];
         priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        while (bi >= 0) {
            while(si >= 0 && ss[si].b >= bug[bi].first) {
                q.push(make_pair(ss[si].c, ss[si].ind));
                si--;
            }
            if(q.empty()) {
                found = false;
                break;
            }
            pair<int, int> p = q.top();
            sum += q.top().first;
            int index = q.top().second + 1;
            q.pop();

            if (sum > s) {
                found = false;
                break;
            }

            for (int i = 0; i < mid && bi - i >= 0; i++) {
                temp[bug[bi - i].second] = index;
            }
            bi -= mid;
        }
        if (found) {
            for (int i = 0; i < m; i++) {
                ans[i] = temp[i];
            }
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (ans[0] == -1) {
        cout << "NO";
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
    }
    return 0;
}



































































