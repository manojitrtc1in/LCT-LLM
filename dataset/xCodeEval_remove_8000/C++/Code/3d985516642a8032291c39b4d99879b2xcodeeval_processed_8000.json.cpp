











 
using namespace std;
 
int zhs(int n) {
    return n * (n - 1) / 2;
}
 
bool isP(long long n) {
    for (long long i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}
 
bool id13(char c) {
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
        return true;
        break;
    
    default: return false;
        break;
    }
}
 
bool check(const int a[55][55], int n, int x, int y) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[x][i] + a[j][y] == a[x][y])
                return true;
    return false;
}
 
int work(int n, int p, int m) {
    

    long long v = 0;
    long long bs = 1;
    int half = 0;
    long long back = n;
    while (n > 0) {
        bs *= 10;
        v = v * 10 + n % 10;
        n /= 10;
    }
    

    v += back * bs;
    

    return (v + m) % p;
}
 
struct a230{
    int s;
    int b;

    bool operator<(a230 a) {
        return s < a.s;
    }
};

long long gcd(long long a, long long b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

long long data[300005] = {0};
long long data2[1000005] = {0};

void initFib() {
    data[1] = 1;
    for(int i = 2; data[i - 1] < 1000000000; i++)
        data[i] = data[i - 1] + data[i - 2];
} 

void id0() {
    data[0] = 1;
    for (int i = 1; i < 13; i++)
        data[i] = data[i - 1] * 2;
}

bool isI(int i) {
    int a[10] = {0};
    while(i > 0) {
        a[i % 10]++;
        i /= 10;
    }
    for (int i = 0; i < 10; i++)
        if (a[i] > 1)
            return false;
    return true;
}

void init(int num, int len) {
    data[0] = 1;
    for (int i = 1; i < len; ++i) 
        data[i] = num * data[i - 1];
    

    

    

}

void id30() {
    string s;
    cin >> s;
    int a[26] = {0};
    for (int i = 0; i < s.length(); ++i)
        if (i == s.length() - 1 || s[i] != s[i + 1])
            a[s[i] - 'a'] = 1;
        else 
            ++i;
    for (int i = 0; i < 26; ++i)
        if (a[i] == 1)
            cout << (char) ('a' + i);
    cout << endl;
}

void b465() {
    int n;
    cin >> n;
    int p, c;
    cin >> p;
    int sum = 0, seg = 0;
    if (p == 1) {
        sum++;
        seg++;
    }
    for (int i = 1; i < n; ++i) {
        cin >> c;
        if (c == 1) {
            sum++;
            if (p != 1)
                seg++;
        }
        p = c;
    }
    if (sum == 0)
        cout << 0;
    else 
        cout << sum + seg - 1;
}

void a879() {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int s, d;
        cin >> s >> d;
        if (sum < s)
            sum = s;
        else {
            sum = s + ((sum - s) / d + 1) * d;
        }
        

    }
    cout << sum;
}

void id8(int b, int e, int len, int k, int n, string s) {
    for (int i = 0; i < b; ++i)
        cout << "0";
    if (k > 0 && k < len) {
        for (int i = 0; i < len - k; ++i)
            cout << "1";
        if (k > 0)
            cout << "0";
        for (int i = 0; i < k; ++i) 
            cout << "1";
        for (int i = e + 1; i < n; ++i)
            cout << s[i];
    } else {
        for (int i = 0; i < len; ++i)
            cout << "1";
        for (int i = e; i < n; ++i)
            cout << s[i];
    }
    cout << endl;
}

void id28() {
    long long k, n;
    cin >> n >> k;
    string s;
    cin >> s;
    int b, e = n, len = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            b = i;
            break;
        }
    }
    for (int i = b; i < n; ++i) {
        if (s[i] == '0') {
            e = i;
            break;
        }
        len++;
    }
    if (b + len >= n) {
        

        id8(b, n, len, 0, n, s);
        return;
    }
    while(e < n) {
        while (s[e] == '0' && len <= k) {
            k -= len;
            b++;
            e++;
        }
        while (e < n && s[e] == '1') {
            e++;
            len++;
        }
        if (k < len)
            break;
    }
    if (k > len || e >= n)
        k = 0;
    id8(b, e, len, k, n, s);
}

struct sb1256 {
    int p, v;
    bool operator<(sb1256 s) {
        return v < s.v;
    }
};

void id2() {
    int n; 
    cin >> n;
    int a[200];
    int p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1)
            p = i;
    }
    int b = 0;
    int m = 1;
    while(true) {
        if (b != p) {
            for (int i = p; i > b; --i)
                a[i] = a[i - 1];
            a[b] = m;
        } else 
            p++;
        
        b = p;
        m = a[p];
        if (b >= n - 1)
            break;
        for (int i = b + 1; i < n; ++i)
            if (a[i] < m) {
                m = a[i];
                p = i;
            }
    }
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

void id15() {
    int n, m, d;
    cin >> n >> m >> d;
    int a[1005] = {0};
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int empty = n - sum;
    if (empty > (m + 1) * (d - 1))
        cout << "NO";
    else {
        int each = empty / (m + 1);
        int lef = empty % (m + 1);
        cout << "YES" << endl;
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < each; ++i)
                cout << 0 << " ";
            if(lef > 0) {
                cout << 0 << " ";
                lef--;
            }
            for (int i = 0; i < a[j]; ++i)
                cout << j + 1 << " ";
        }
        for (int i = 0; i < each; ++i)
            cout << 0 << " ";
    }
}

struct sb520 {
    int v, n;
};

void b520() {
    long long n, m;
    cin >> n >> m;
    queue<sb520> q;
    sb520 s;
    s.n = 0;
    s.v = n;
    q.push(s);
    long long mm = m * 3;
    if (n >= m) {
        cout << n - m;
        return;
    }
    data[n] = 1;
    while(!q.empty()) {
        sb520 temp = q.front();
        q.pop();
        if (temp.n >= mm) {
            cout << mm;
            return ;
        }
        if (temp.v * 2 == m || temp.v - 1 == m) {
            cout << temp.n + 1;
            return;
        }
        if (temp.v > m)
            mm = min(mm, temp.n + temp.v - m);
        else {
            s.n = temp.n + 1;
            s.v = temp.v * 2;
            if(data[s.v] == 0) {
                data[s.v] = 1;
                q.push(s);
            }
            if (temp.v - 1 > 0) {
                s.v = temp.v - 1;
                if(data[s.v] == 0) {
                    data[s.v] = 1;
                    q.push(s);
                }
            }
        }
    }
    cout << mm;
    return;
}

int a217() {
    int n;
    cin >> n;
    vector<int> hv[1005], lv[1005];
    int h[1005] = {0}, l[1005] = {0};
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        hv[x].push_back(y);
        lv[y].push_back(x);
    }
    int sum = 0;
    for (int i = 1; i <= 1000; ++i) {
        if (h[i] != 0 || hv[i].size() == 0)
            continue;
        sum++;
        h[i] = sum;
        queue<int> hq, lq;
        for (int j = 0; j < hv[i].size(); ++j) {
            if (l[hv[i][j]] == 0) {
                l[hv[i][j]] = sum;
                lq.push(hv[i][j]);
            }
        }
        while(!lq.empty()) {
            while(!lq.empty()) {
                int y = lq.front();
                lq.pop();
                for (int j = 0; j < lv[y].size(); ++j) {
                    if (h[lv[y][j]] == 0) {
                        h[lv[y][j]] = sum;
                        hq.push(lv[y][j]);
                    }
                }
            }
            while(!hq.empty()) {
                int y = hq.front();
                hq.pop();
                for (int j = 0; j < hv[y].size(); ++j) {
                    if (l[hv[y][j]] == 0) {
                        l[hv[y][j]] = sum;
                        lq.push(hv[y][j]);
                    }
                }
            }
        }
    }
    cout << sum - 1;
}

void id29() {
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    if (a > b)
        swap(a, b);
    int mov = min(x, a - 1);
    a -= mov;
    x -= mov;
    mov = min(x, n - b);
    b += mov;
    cout << b - a << endl;
}

void id36() {
    long long a, b, n, s, t1, t2, t3;
    cin >> a >> b >> n >> s;
    t1 = s / n;
    if (t1 > a)
        t1 = a;
    s -= t1 * n;
    if (b >= s)
        cout << "yes";
    else 
        cout << "no";
    cout << endl;
}

void id26() {
    int x, y;
    cin >> x >> y;
    if (x == 1 && y > 1 || x <= 3 && y > 3)
        cout << "no";
    else 
        cout << "yes";
    cout << endl;
}

void id6() {
    long long x, y;
    cin >> x >> y;
    if (gcd(x, y) == 1)
        cout << "Finite";
    else 
        cout << "Infinite";
    cout << endl;
}

void id23() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] < s[i - 1]) {
            cout << "yes" << endl;
            cout << i << " " << i + 1;
            return;
        }
    }
    cout << "no";
}

void a990() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    n %= m;
    cout << min(n * b, (m - n) * a);
    return;
}

void a84() {
    int n;
    cin >> n;
    cout << n + n / 2;
    return;
}

void id40() {
    int n, k;
    cin >> n >> k;
    int arr[100] = {0};
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        arr[i % k] += temp;
        sum += temp;
    }
    

    for (int i = 0; i < k; ++i) {
        

        arr[i] -= sum;
        if (arr[i] < 0)
            arr[i] = -arr[i];
    }
    sort(arr, arr + k);
    cout << arr[k - 1];
}

void id38() {
    int n;
    string s;
    cin >> n >> s;
    int m = 55;
    for (int i = 0; i < n - 3; ++i) {
        int temp = 0, t2;
        t2 = abs(s[i] - 'A');
        temp += min(t2, 26 - t2);
        t2 = abs(s[i + 1] - 'C');
        temp += min(t2, 26 - t2);
        t2 = abs(s[i + 2] - 'T');
        temp += min(t2, 26 - t2);
        t2 = abs(s[i + 3] - 'G');
        temp += min(t2, 26 - t2);
        if (temp < m)
            m = temp;
    }
    cout << m;
    return;
}

void id9() {
    long long n, m, k, sum, s1 = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> data[i];
    sort(data, data + n);
    sum = 0;
    if (data[n - 1] == data[n - 2])
        cout << m * data[n - 1];
    else {
        s1 = k * data[n - 1] + data[n - 2];
        sum = (m / (k + 1)) * s1 + (m % (k + 1)) * data[n - 1];
        cout << sum;
    }
    return ;
}

void id17() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> data[i];
    for (int i = 0; i < n; ++i)
        cin >> data2[i];
    bool b = true, f = false;
    int gap = 0;
    for (int i = 0; i < n; ++i) {
        if (data2[i] < data[i]) {
            b = false;
            break;
        } else if (data2[i] > data[i]) {
            if (f || gap != 0 && gap != data2[i] - data[i]) {
                b = false;
                break;
            }
            gap = data2[i] - data[i];
        } else if (gap > 0)
            f = true;
    }
    if (b)
        cout << "YES";
    else 
        cout << "NO";
    cout << endl;
}

void id33() {
    int n, k, d;
    cin >> n >> k >> d;
    for (int i = 1; i <= n; ++i)
        cin >> data[i];
    if (d == 1 || n == 1) {
        cout << 1 << endl;
        return ;
    }
    memset(data2, 0, 8 * (k + 1));
    

    int sum = 0, temp = 0;
    for (int i = 1; i <= d; ++i) {
        data2[data[i]]++;
        if (data2[data[i]] == 1)
            temp++;
    }
    

    

    

    

    

    

    sum = temp;
    for (int i = 2; i <= n - d + 1; ++i) {
        data2[data[i - 1]]--;
        if (data2[data[i - 1]] == 0)
            temp--;
        data2[data[i + d - 1]]++;
        

        

        

        if (data2[data[i + d - 1]] == 1)
            temp++;
        

        

        

        

        if (temp < sum)
            sum = temp;
    }
    cout << sum << endl;
}

void id1() {
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    int d = b - a;
    int sum = d / 5;
    d %= 5;
    if (d > 2)
        sum += 2;
    else if (d > 0)
        sum += 1;
    cout << sum << endl;
}

void id39() {
    int n;
    cin >> n;
    int temp[1005] = {0};
    for (int i = 0; i < n; ++i) {
        int it;
        cin >> it;
        temp[it]++;
    }
    int sum = 0;
    for (int i = 1000; i > 0; --i) {
        sum += temp[i];
        if (sum >= i) {
            cout << i << endl;;
            return;
        }
    }
}

void id34() {
    int a1, a2, k1, k2, m;
    cin >> a1 >> a2 >> k1 >> k2 >> m;
    cout << max(m - (k1 - 1) * a1 - (k2 -1) * a2, 0) << " ";
    if (k1 > k2) {
        int sum = min (a2, m / k2);
        m -= sum * k2;
        if (m > 0)
            sum += m / k1;
        cout << sum;
    } else {
        int sum = min(a1, m / k1);
        m -= sum * k1;
        if (m > 0)
            sum += m / k2;
        cout << sum;
    }
}

void c546() {
    int n;
    queue<int> q1, q2;
    int k1, k2;
    cin >> n;
    cin >> k1;
    for (int i = 0; i < k1; ++i) {
        int temp;
        cin >> temp;
        q1.push(temp);
    }
    cin >> k2;
    for (int i = 0; i < k2; ++i) {
        int temp;
        cin >> temp;
        q2.push(temp);
    }
    

    int sum = 0;
    while (!q1.empty() && !q2.empty()) {
        k1 = q1.front();
        k2 = q2.front();
        q1.pop();
        q2.pop();
        if (k1 > k2) {
            q1.push(k2);
            q1.push(k1);
        } else {
            q2.push(k1);
            q2.push(k2);
        }
        sum++;
        if (sum > 100000)
            break;
    }
    if (sum > 100000)
        cout << -1;
    else {
        cout << sum << " " << (q1.empty() ? 2 : 1);
    }
}

void a708() {
    string s;
    cin >> s;
    int i = 0;
    while (i < s.length() && s[i] == 'a') i++;
    if (i == s.length())
        s[i - 1] = 'z';
    while (i < s.length() && s[i] != 'a') {
        s[i]--;
        i++;
    }
    cout << s;
}

void a982() {
    string s;
    int n;
    cin >> n >> s;
    bool b = true;
    s = "0" + s + "0";
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '0' && s[i -1] == '0' && s[i + 1] == '0') {
            b = false;
            break;
        }
        if (s[i] == '1' && (s[i -1] == '1' || s[i + 1] == '1')) {
            b = false;
            break;
        }
    }
    if (b) 
        cout << "Yes";
    else 
        cout << "No";
}

void a602() {
    unsigned long long a1 = 0, a2 = 0, base = 1;
    int n, bx, a[15];
    cin >> n >> bx;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = n; i > 0; --i) {
        a1 += base * a[i];
        base *= bx;
    }
    cin >> n >> bx;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    base = 1;
    for (int i = n; i > 0; --i) {
        a2 += base * a[i];
        base *= bx;
    }
    if (a1 < a2) 
        cout << "<";
    else if (a1 == a2)
        cout << "=";
    else 
        cout << ">";
}

void a633() {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (c / b < 100) {
        bool bo = false;

        for (int i = 0; i <= c / b; ++i) {
            if((c - (i * b)) % a == 0) {
                bo = true;
                break;
            }
        }
        if (bo)
            cout << "Yes";
        else 
            cout << "No";
    } else {
        long long mm = gcd(a, b);
        if (c % mm == 0)
            cout << "Yes";
        else 
            cout << "No";
    }
}

void id4() {
    int n, m, h;
    cin >> n >> m >> h;
    int ma[105] = {0};
    int na[105] = {0};
    int ha[105][105] = {0};
    for (int i = 1; i <= m; ++i)
        cin >> ma[i];
    for (int i = 1; i <= n; ++i)
        cin >> na[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> ha[i][j];
            if (ha[i][j] == 1) 
                ha[i][j] = min(ma[j], na[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << ha[i][j] << " ";
        }
        cout << endl;
    }
}

void b705() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        sum += (temp - 1) % 2;
        if (sum % 2 == 0)
            cout << 2;
        else 
            cout << 1;
        cout << endl;
    }
    return;
}

void a574() {
    int n;
    cin >> n;
    int a;
    cin >> a;
    int sum = a;
    int num = 1;
    int eq = 0;
    int ma = a;
    int mbuf[1005] = {0};
    for (int i = 2; i <= n; ++i) {
        int temp;
        cin >> temp;
        mbuf[temp]++;
    }
    for (int i = 1000; i>= a; --i) {
        if (mbuf[i] == 0)
            continue;
        int temp = mbuf[i];
        

        if (a + mbuf[i] <= i) {
            mbuf[i - 1] += mbuf[i];
            a += mbuf[i];
            mbuf[i] = 0;
        } else {
            a = i + 1;
        }
    }
    cout << a - ma;
    return ;
}

void a902() {
    int n, m;
    cin >> n >> m;
    int b = 0, e = 0, t1, t2;
    for (int i = 0; i < n; ++i) {
        cin >> t1 >> t2;
        if (t1 <= e && t2 > e)
            e = t2;
    }
    if (e >= m)
        cout << "YES";
    else 
        cout << "NO";
}

void b911() {
    int n, a, b;
    cin >> n >> a >> b;
    int mi = 0;
    for (int i = 1; i < n; ++i) {
        int temp = min(a / i, b / (n - i));
        mi = max(mi, temp);
    }
    cout << mi;
}

long long buffer[500005] = {0};
long long buf2[500005] = {0};

void b432() {
    int n;
    cin >> n;
    

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp >> buf2[i];
        buffer[temp]++;
    }
    for (int i = 0; i < n; ++i) {
        cout << n - 1 + buffer[buf2[i]] << " " << n - 1 - buffer[buf2[i]] << endl;
    }
}

void b592() {
    long long n;
    cin >> n;
    n -= 2;
    cout << n * n;
}

void b362() {
    int n, m;
    cin >> n >> m;
    int buf[3000] = {0};
    for (int i = 0; i < m; ++i)
        cin >> buf[i];
    sort(buf, buf + m);
    if (buf[0] == 1 || buf[m - 1] == n)
        cout << "NO";
    else {
        bool b = false;
        for (int i = 0; i < m - 2; ++i) 
            if (buf[i] + 1 == buf[i + 1] && buf[i] + 2 == buf[i + 2]) {
                b = true;
                break;
            }
        if (b)
            cout << "NO";
        else 
            cout << "YES";
    }
}

void b734() {
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    int mi;
    mi = min(k2, k5);
    mi = min(mi, k6);
    long long sum = 0;
    sum += mi * 256L;
    k2 -= mi;
    mi = min(k2, k3);
    sum += mi * 32;
    cout << sum;
}

void c977() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> buffer[i];
    sort(buffer, buffer + n);
    int sum = 0;
    if (k == n)
         cout << buffer[n - 1];
    else if (buffer[k - 1] == buffer[k])
        cout << -1;
    else if (k == 0) {
        if (buffer[0] > 1)
            cout << 1;
        else 
            cout << -1;
    } else
        cout << buffer[k - 1];
}

void id3() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] + a[1] >= a[2])
        cout << (a[0] + a[1] + a[2]) / 2;
    else 
        cout << a[1] + a[0];
    cout << endl;
}

void a799() {
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    int num = (n + k - 1) / k;
    num--;
    if (num * t > d)
        cout << "YES";
    else 
        cout << "NO";
}

void b998() {
    int n, b;
    cin >> n >> b;
    int a[1000] = {0};
    int on = 0, en = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0)
            en++;
        else 
            on++;
        if (en == on && i < n - 1)
            v.push_back(abs(a[i + 1] - a[i]));
    }
    if (en != on || v.size() == 0)
        cout << 0;
    else {
        sort(v.begin(), v.end());
        int sum = 0;
        int i = 0;

        while(sum + v[i] <= b && i < v.size()) {
            sum += v[i];
            i++;
        }
        cout << i;
    }
}

void c903() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> buffer[i];
    sort(buffer, buffer + n);
    int ma = 0;
    int i = 0;
    while(i < n) {
        int num = 1;
        while(i < n - 1 && buffer[i] == buffer[i + 1]) {
            i++;
            num++;
        }
        if (num > ma)
            ma = num;
        i++;
    }
    cout << ma;
}

void b365() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> buffer[i];
    for (int i = 2; i < n; ++i)
        if (buffer[i] == buffer[i - 1] + buffer[i - 2])
            buf2[i] = 1;
    int ma = 0;
    int i = 2;
    while(i < n) {
        int num = 0;
        while (i < n && buf2[i] == 1) {
            i++;
            num++;
        }
        if (num > ma)
            ma = num;
        i++;
    }
    if (n == 1)
        cout << 1;
    else 
        cout << ma + 2;
}

void id21() {
    int n, m;
    cin >> n >> m;
    if (n > m) {
        cout << 0;
        return;
    }
    if (n == m || m / n == 1) {
        cout << 1;
        return;
    }
    int a[105] = {0};
    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        a[temp]++;
    }
    sort(a, a + 101);
    int ma = m / n;
    ma = min(ma, a[100]);
    if (ma == 1)
        cout << 1;
    else {
        for(int i = ma; i > 1; --i) {
            int sum = 0;
            for (int j = 100; a[j] >= i; --j)
                sum += a[j] / i;
            if (sum >= n) {
                cout << i;
                return;
            }
        }
        cout << 1;
    }
}

int b554() {
    int n;
    cin >> n;
    string s[105];
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    sort(s, s + n);
    int ma = 0;
    int i = 0;
    while (i < n) {
        int num = 1;
        while (i < n - 1 && s[i] == s[i + 1]) {
            i++;
            num++;
        }
        if (num > ma)
            ma = num;
        i++;
    }
    cout << ma;
}

void a433() {
    int n;
    int a[2] = {0};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        if (temp == 100)
            a[0]++;
        else 
            a[1]++;
    }
    if (a[0] % 2 == 1 || (a[0] == 0 && a[1] % 2 == 1))
        cout << "NO";
    else 
        cout << "YES";
}

int bs(int v, int begin, int end) {
    if (begin >= end)
        return end;
    int half = (begin + end) / 2;
    if (v > buffer[half])
        return bs(v, half + 1, end);
    else if (v == buffer[half])
        return half;
    else 
        return bs(v, begin, half);
}
void b474() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> buffer[i];
        buffer[i] += buffer[i - 1];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        cout << bs(temp, 1, n) << endl;
    }
}

void a459() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
        int gap = y2 - y1;
        cout << x1 + gap << " " << y1 << " " << x2 + gap << " " << y2;
    } else if (y1 == y2) {
        int gap = x2 - x1;
        cout << x1 << " " << y1 + gap << " " << x2 << " " << y2 + gap;
    } else if (abs(x1 - x2) == abs(y1 - y2)) {
        cout << x1 << " " << y2 << " " << x2 << " " << y1;
    } else 
        cout << -1;
}

void b552() {
    long long n;
    cin >> n;
    long long sum = 0;
    long long base = 9;
    long long bb = 1;
    while (n >= base) {
        sum += base * bb;
        n -= base;
        base *= 10;
        bb++;
    }
    sum += n * bb;
    cout << sum;
}

struct n1267 {
    int a, b, t;
    bool operator<(n1267 node) {
        return a < node.a;
    }
};
n1267 nds[200000];

bool st(n1267 a, n1267 b) {
    if (a.t == b.t)
        return a.b > b.b;
    return a.t > b.t;
}
void id31() {
    int n;
    cin >> n; 
    long long mb = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nds[i].a >> nds[i].b >> nds[i].t;
        if(nds[i].b > mb) 
            mb = nds[i].b;
    }
    sort(nds, nds + n);
    int p = 1;
    long long beg = nds[0].a, e, sum = 0;
    while (p < n) {

    }
}

void id10() {
    int n;
    cin >> n;
    long long mod = 998244353;
    for (int i = 1; i <= n; ++i)
        cin >> buffer[i];
    long long mul = 100;
    long long fm = buffer[n];
    long long fm2 = 1;
    for (int i = n - 1; i > 0; i--) {
        fm2 *= buffer[n - i];
        fm2 %= mod;
        mul = (mul + fm2) * 100;
        mul %= mod;
        fm *= buffer[i];
        fm %= mod;
    }
    if (mul % fm == 0) {
        cout << mul / fm;
        return;
    }
    

    while(true) {
        if (mul % fm == 0) {
            cout << mul / fm;
            return;
        }
        mul += mod;
    }
}

struct N1227 {
    int l, r;

    bool operator<(N1227 a) {
        return l < a.l;
    }
};

N1227 n1227[100000];

void id35() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> n1227[i].l >> n1227[i].r;
    sort(n1227, n1227 + n);
    int mb = n1227[0].l;
    int me = n1227[0].r;
    for (int i = 1; i < n; ++i) {
        if (n1227[i].l >= me)
            break;
        if (n1227[i].r < me)
            me = n1227[i].r;
    }
    if (me >= n1227[n - 1].l)
        cout << 0;
    else 
        cout << n1227[n - 1].l - me;
    cout << endl;
}

void id5() {
    int n;
    cin >> n;
    

    int m;
    cin >> m;
    buffer[0] = m;
    memset(buf2, 0, 8 * (n + 10));
    buf2[m] = 1;
    int p = 1;
    for (int i = 1; i < n; ++i) {
        int temp ;
        cin >> temp;
        

        if (temp <= i || temp > n) {
            ++i;
            while(i < n) {
                cin >> temp;
                i++;
            }
            cout << -1 << endl;
            return;
        }
        if (temp > m) {
            m = temp;
            buffer[i] = m;
            buf2[m] = 1;
        } else {
            for (; ; p++) {
                if (buf2[p] == 0) {
                    buf2[p] = 1;
                    buffer[i] = p;
                    p++;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << buffer[i] << " ";
    cout << endl;
}

long long cal(vector<long long> &vn, vector<long long> &vk, long long k) {
    

    

    

    

    

    

    vector<long long> v1, v2;
    int i = 0, j = 0;
    if (vn[i] % 2 == 1) 
        i++;
    v1.push_back(vn[i] / 2);
    v2.push_back(1 + vk[i]);
    int len = vn.size();
    if (v1[j] % 2 == 0) {
        long long pre;
        int len = vn.size();
        if (vn[len - 1] % 2 == 1)
            pre = vk[len - 1];
        else 
            pre = vk[len - 2];
        v2[j] += pre;
    }
    while(true) {
        if (v2[j] >= k)
            return v1[j];
        if (v1[j] <= v1[0] / 2 || j >= 100 || (j > 2 && v2[j - 2] == v2[j] && v2[j - 1] == v2[j - 3]))
            break;
        i += 2;
        if (i >= len)
            i -= 2;
        v1.push_back(v1[j] - 1);
        v2.push_back(1 + vk[i]);
        if (v1[j] % 2 == 1)
            v2[j + 1] += v2[j];
        j++;
    }
    return cal(v1, v2, k);
}
void id11() {
    long long n, k;
    cin >> n >> k;
    if (k == 1)
        cout << n;
    else if (k == n)
        cout << 1;
    else if (k == 2) {
        if (n % 2 == 0)
            cout << n - 2;
        else 
            cout << n - 1;
    } else if (k == n - 1)
        cout << 2;
    else {
        vector<long long> vn, vk;
        vn.push_back(n);
        vk.push_back(1);
        if (n % 2 == 0) {
            vn.push_back(n - 1);
            vn.push_back(n - 2);
            

            

            vk.push_back(1);
            vk.push_back(2);
        } else {
            vn.push_back(n - 1);
            

            

            vk.push_back(2);
        }
        cout << cal(vn, vk, k);
    }
}

string id7(string s) {
    int len = s.length();
    int i = 0;
    string ret;
    while(i < len && s[i] >= 'A' && s[i] <= 'Z') i++;
    string sr = s.substr(0, i);
    

    int begin = i;
    while(i < len && s[i] >= '0' && s[i] <= '9') i++;
    string n1 = s.substr(begin, i - begin);
    

    if (i == len) {
        ret = "R" + n1 + "C";
        int num = sr[0] - 'A' + 1;
        

        for (int j = 1; j < sr.length(); ++j) {
            num *= 26;
            num += sr[j] - 'A' + 1;
            

        }
        

        

    } else {
        i++;
        int num = s[i] - '0';
        for (++i; i < len; i++) {
            num *= 10;
            num += s[i] - '0';
        }
        

        num--;
        char c = 'A' + num % 26;
        num /= 26;
        ret = c;
        while (num > 0) {
            num--;
            c = 'A' + num % 26;
            ret = c + ret;
            num /= 26;
        }
        ret += n1;
    }
    return ret; 
}

void b1() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cout << id7(s) << endl;
    }
}

void id37() {
    int a;
    cin >> a;
    cout << a / 2 << endl;
}

void id27() {
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int m = max(a[0], max(a[1], a[2]));
    int gap = m - a[0] - a[1] - a[2] + m + m;
    if (a[3] >= gap && (a[3] - gap) % 3 == 0)
        cout << "YES";
    else
    {
        cout << "NO";
    }
    cout << endl;
    return ;    
}

void id32() {
    int a, b;
    cin >> a >> b;
    if (a == b)
        cout << 0 ;
    else if (a % 2 == b % 2) {
        if (a > b)
            cout << 1;
        else 
            cout << 2;
    } else {
        if (a > b)
            cout << 2;
        else 
            cout << 1;
    }
    cout << endl;
}

void id16() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << b << " " << c << " " << c << endl;
    return ;
}

void id14() {
    int a;
    cin >> a;
    if (a % 4 == 0)
        cout << "YES";
    else 
        cout << "NO";
    cout << endl;
}

void id20(long long n) {
    long long temp = n;
    long long times = 0;
    while(n > 0) {
        temp = n;
        long long m = 0;
        while(temp > 0) {
            m = max(m, temp % 10);
            temp /= 10;
            if (m == 9)
                break;
        }
        n -= m;
        times++;
    }
    cout << times << endl;
}

int b932[1000005] = {0};
int b932s[1000005] = {0};
int b932t[10] = {0};
void id18() {
    for (int i = 1; i < 10; ++i) {
        b932[i] = i;
        b932s[i] = b932t[i] = 1;
    }
    for (int i = 10; i < 1000001; ++i) {
        int temp = i;
        int p = 1;
        while(temp > 0) {
            if (temp % 10 != 0) {
                p *= temp % 10;
            }
            temp /= 10;
        }
        b932[i] = b932[p];
        b932t[b932[i]]++;
        b932s[i] = b932t[b932[i]];
    }
    return ;
}
void id19() {
    int l, r, k;
    cin >> l >> r >> k;
    int sum = 0;
    int beg = 0, end = 0;
    for(int i = l; i <= r; ++i) 
        if (b932[i] == k) {
            beg = b932s[i];
            break;
        }
    for(int i = r; i >= l; --i) 
        if (b932[i] == k) {
            end = b932s[i];
            break;
        }
    if (beg > 0)
        cout << end - beg + 1 << endl;
    else 
        cout << 0 << endl;
    return ;
}

int b900ys[100005] = {0};
void b900() {
    int a, b, c;
    cin >> a >> b >> c;
    a *= 10;
    int i = 1;
    while(true) {
        

        if ((a / b) == c) {
            cout << i << endl;
            return;
        }
        a %= b;
        if (b900ys[a] > 0)
            break;
        b900ys[a] = 1;
        a *= 10;
        i++;
    }
    cout << -1 << endl;
    return;
}

void c665() {
    string s;
    cin >> s;
    int i;
    for (i = 1; i < s.length() - 1; ++i) {
        if (s[i] == s[i - 1]) {
            for(int j = 0; j < 26; ++j) {
                if ('a' + j != s[i-1] && 'a' +j != s[i+1]) {
                    s[i] = 'a' + j;
                    i++;
                    break;
                }
            }
        }
    }
    if (i < s.length() && s[i] == s[i - 1]) {
        for(int j = 0; j < 26; ++j) {
            if ('a' + j != s[i-1]) {
                s[i] = 'a' + j;
                i++;
                break;
            }
        }
    }
    cout << s << endl;
}

long long d1_1195ll[100005];
void id12() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> d1_1195ll[i];
    long long magic = 998244353;
    bool esig = false;
    long long base = 11;
    long long sum = 0;
    while(!esig) {
        esig = true;
        int tempsum = 0;
        for (int i = 0; i < n; ++i) {
            tempsum += d1_1195ll[i] % 10;
            d1_1195ll[i] /= 10;
            if (d1_1195ll[i] > 0)
                esig = false;
        }
        tempsum = (tempsum * n) % magic;
        sum = (sum + (tempsum * base) % magic) % magic;
        

        base = (base * 100) % magic;
    }
    cout << sum << endl;
}

int b279array[100005] = {0};
int binsearch(int be, int end, int value) {
    if (b279array[be] > value)
        return be - 1;
    if (be >= end)
        return be;
    int half = (be + end) / 2;
    if (b279array[half] == value)
        return half;
    else if (b279array[half] > value)
        return binsearch(be, half - 1, value);
    else 
        return binsearch(half + 1, end, value);
}
void b279() {
    int n, t;
    cin >> n >> t;
    cin >> b279array[1];
    for (int i = 1; i < n; ++i) {
        cin >> b279array[i + 1];
        b279array[i + 1] += b279array[i];
    }
    int m = 0;
    for(int i = 0; i < n; ++i) {
        int temp = binsearch(i, n, b279array[i] + t) - i;
        if (temp > m)
            m = temp;
    }
    cout << m << endl;
}

void c489() {
    int m, s;
    cin >> m >> s;
    if (s == 0 && m > 1) {
        cout << -1 << " " << -1 << endl;
        return;
    }
    if (s == 0 && m == 1) {
        cout << 0 << " " << 0 << endl;
        return;
    }
    int shang, yu;
    shang = s / 9;
    yu = s % 9;
    int id22 = shang + ((yu == 0) ? 0 : 1);
    if (m < id22) {
        cout << -1 << " " << -1 << endl;
        return;
    }
    if (m == id22) {
        if (yu > 0) {
            cout << yu;
            for (int i = 0; i < shang; ++i)
                cout << 9;
            cout << " ";
            for (int i = 0; i < shang; ++i)
                cout << 9;
            cout << yu;
        } else {
            for (int i = 0; i < shang; ++i)
                cout << 9;
            cout << " ";
            for (int i = 0; i < shang; ++i)
                cout << 9;
        }
    } else {  

        if (yu > 0) {
            cout << 1;
            for (int i = 0; i < m - 1 - id22; ++i)
                cout << 0;
            cout << yu - 1;
            for (int i = 0; i < shang; ++i)
                cout << 9;
            cout << " ";
            for (int i = 0; i < shang; ++i)
                cout << 9;
            cout << yu;
            for (int i = 0; i < m - id22; ++i)
                cout << 0;
        } else {
            cout << 1;
            for (int i = 0; i < m - 1 - id22; ++i)
                cout << 0;
            cout << 8;
            for (int i = 0; i < shang - 1; ++i)
                cout << 9;
            cout << " ";
            for (int i = 0; i < shang; ++i)
                cout << 9;
            

            for (int i = 0; i < m - id22; ++i)
                cout << 0;
        }
    }
    cout << endl;
}

long long b1215n[200005] = {0};
long long b1215s[200005] = {0};
void id25() {
    int n;
    cin >> n;
    long long x= 0, d = 0;
    int i = 0;
    

    

    

    

    

    for (i = 1; i <= n; ++i) {
        cin >> b1215n[i];
        if (b1215n[i] > 0)
            d++;
        else 
            x++;
        b1215s[i] = b1215s[i - 1] + b1215n[i];
    }
    for (i = 2; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {

        }
    }
}

void debugo(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
        if (i % 10 == 9)
            cout << endl;
    }
    cout << endl;
}
int b1_1282n[200005] = {0};
int b1_1282s[200005] = {0};
void id24() {
    

    int n, p, k;
    cin >> n >> p >> k;
    for (int i = 0; i < n; ++i)
        cin >> b1_1282n[i];
    sort(b1_1282n, b1_1282n + n);
    

    

    int m = 0, ks = 0;
    for (int i = 0; i < k; i++) {
        int temp = 0, ts = 0;
        ks += b1_1282n[i];
        if ( i == k - 1)
            ts = b1_1282n[i];
        else {
            ts = ks;
        }
        if (ts <= p) {
            temp = i + 1;
        } else 
            continue;
        for (int j = i + k; j < n; j += k) {
            if (ts + b1_1282n[j] <= p) {
                ts += b1_1282n[j];
                temp += k;
            } else 
                break;
        }
        if (temp > m)
            m = temp;
    }
    cout << m << endl;
}
int main() {




    long long q;
    cin >> q;
    

    

    for (int i = 0; i < q; ++i) {
        id24();
    }
    

    return 0;
}