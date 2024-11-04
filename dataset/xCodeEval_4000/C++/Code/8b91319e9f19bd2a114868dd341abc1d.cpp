#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
 
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
 
bool yuanyin6(char c) {
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
 
void init2048() {
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
 
void a1251() {
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
 
void d1256out(int b, int e, int len, int k, int n, string s) {
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
 
void d1256() {
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
        

        d1256out(b, n, len, 0, n, s);
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
    d1256out(b, e, len, k, n, s);
}
 
struct sb1256 {
    int p, v;
    bool operator<(sb1256 s) {
        return v < s.v;
    }
};
 
void b1256() {
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
 
void c1256() {
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
 
void a1257() {
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
 
void a1256() {
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
 
void b1257() {
    int x, y;
    cin >> x >> y;
    if (x == 1 && y > 1 || x <= 3 && y > 3)
        cout << "no";
    else 
        cout << "yes";
    cout << endl;
}
 
void a1245() {
    long long x, y;
    cin >> x >> y;
    if (gcd(x, y) == 1)
        cout << "Finite";
    else 
        cout << "Infinite";
    cout << endl;
}
 
void a1155() {
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
 
void a1100() {
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
 
void a1151() {
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
 
void b1117() {
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
 
void a1253() {
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
 
void b1225() {
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
 
void a1255() {
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
 
void a1243() {
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
 
void a1215() {
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
 
void b1153() {
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
 
void a1263() {
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
 
void b1011() {
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
void a1267() {
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
 
long long extend_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    } else {
        long long r = extend_gcd(b, a % b, x, y);
        long long temp = x;
        x = y;
        y = temp - a / b * y;
        return r;
    }
} 
void e1265() {
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
    long long x, y;
    

    

    long long d = extend_gcd(fm, mod, x, y);
    long long k = mul / d;
    

    

    

    d = (x * k) % mod;
    if (d < 0)
        d += mod;
    cout << d;
}
int main() {




    

    

    

    

    

    e1265();
    return 0;
}