
using namespace std;

typedef long long ll;
typedef pair<int, int> pairs;


void match()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    int s = -1;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
        {
            s &= a[i];
        }
    cout << s << endl;
}
void id13()
{
    int n, m;
    cin >> n;
    int alice[n];
    for (int i = 0; i < n; i++)
    {
        cin >> alice[i];
    }
    cin >> m;
    int bob[m];
    for (int i = 0; i < m; i++)
    {
        cin >> bob[i];
    }
    sort(alice, alice + n, greater<int>());
    sort(bob, bob + m, greater<int>());
    if (alice[0] > bob[0])
    {
        cout << "Alice" << endl;
        cout << "Alice" << endl;
    }
    else if (alice[0] == bob[0])
    {
        cout << "Alice" << endl;
        cout << "Bob" << endl;
    }
    else
    {
        cout << "Bob" << endl;
        cout << "Bob" << endl;
    }
}
void id18()
{
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if ((double)(sum - arr[i]) / (n - 1) == (double)(arr[i]))
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
void id4()
{
    int n;
    cin >> n;
    int arr[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            count++;
            i++;
        }
    }
    cout << count << endl;
}
void id10()
{
    int n;
    cin >> n;

    int arr[n];
    vector<int> newarr;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool f = true;
    sort(arr, arr + n);

    for (int i = 0; i < n / 2; i++)
    {
        newarr.push_back(arr[i]);
        newarr.push_back(arr[n / 2 + i]);
    }

    if (n & 1)
    {
        f = false;
    }
    for (int i = 1; i < newarr.size() - 1; i++)
    {
        if (newarr[i] > newarr[i + 1] && newarr[i] > newarr[i - 1])
            continue;
        else if (newarr[i] < newarr[i + 1] && newarr[i] < newarr[i - 1])
        {
            continue;
        }
        else
        {
            f = false;
        }
    }
    if (f == false)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << newarr[i] << " ";
    }
    cout << endl;
}
void id2()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c << " " << b + c << " " << c << endl;
}
void id17()
{
    int n;
    cin >> n;
    int arr[n];
    int c = 0, d = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            c++;
        else
            d++;
    }
    cout << min(c, d) << endl;
}
void id3()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool flag = false;
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            cout << "-1" << endl;
            return;
        }
    }
    vector<int> ans;
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1 && arr[i] == arr[i + 1])
            cnt++;
        else
        {
            

            int a = i;
            ans.push_back(i + 1);
            for (int j = 1; j < cnt; j++)
            {
                ans.push_back(a--);
            }
            

            cnt = 1;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
void id15()
{
    ll n;
    cin >> n;
    if (n % 2 == 0)
    {
        if (!(n & (n - 1)))
        {
            cout << n + 1 << endl;
        }
        else
        {
            cout << (n & ~(n - 1)) << endl;
        }
    }
    else
    {
        if (n > 1)
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "3" << endl;
        }
    }
}
void id1()
{
    ll n;
    cin >> n;
    ll arr[n];
    int even = 0, odd = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    bool flag = false;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            flag = true;
        }
    }
    if (flag == false)
    {
        cout << "0" << endl;
        return;
    }
    if (odd > 0)
    {
        cout << even << endl;
        return;
    }

    else
    {
        for (ll i = 0; i < n; i++)
        {
            ll v = 0;
            while (arr[i] % 2 == 0)
            {
                arr[i] /= 2;
                v++;
            }
            arr[i] = v;
        }
        cout << n - 1 + *min_element(arr, arr + n) << '\n';
    }
}
void id5()
{
    int n;
    cin >> n;
    int a = 1, b = 2, c = 3, k;
    k = (n - 6) / 3;
    if (n % 3 == 2)
        b++, c++;
    else if (n % 3 == 1)
        c++;
    b += k, c += k, a += k;
    cout << b << " " << c << " " << a << endl;
}
void id6()
{
    int n;
    cin >> n;
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] < arr2[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    int maxdiff = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxdiff = max(maxdiff, arr1[i] - arr2[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] - arr2[i] != maxdiff)
        {
            if (arr2[i] == 0)
                continue;
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
void id11()
{
    int n;
    cin >> n;
    int si[n], fi[n], di[n];
    for (int i = 0; i < n; i++)
    {
        cin >> si[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> fi[i];
    }
    di[0] = fi[0] - si[0];
    for (int i = 1; i < n; i++)
    {
        di[i] = fi[i] - max(si[i], fi[i - 1]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << di[i] << " ";
    }
    cout << endl;
}
void id14()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll b = 0, w = 0;
    for (ll i = 0; i < k; i++)
    {
        if (s[i] == 'B')
            b++;
        else
            w++;
    }
    ll ans = w;
    for (ll i = k; i < n; i++)
    {
        if (s[i] == 'B')
            b++;
        else
            w++;
        if (s[i - k] == 'B')
            b--;
        else
            w--;
        ans = min(ans, w);
    }
    cout << ans << endl;
}
void LexString()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s1, s2, c = "";
    int i = 0, j = 0;
    cin >> s1 >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int cnt1 = 0, cnt2 = 0;
    while (i < n && j < m)
    {
        if (s1[i] < s2[j] && cnt1 < k)
        {
            c += s1[i];
            i++;
            cnt1++;
            cnt2 = 0;
        }
        else if (s1[i] > s2[j] && cnt2 < k)
        {
            c += s2[j];
            j++;
            cnt2++;
            cnt1 = 0;
        }
        else if (cnt1 < k)
        {
            c += s1[i];
            i++;
            cnt1++;
            cnt2 = 0;
        }
        else if (cnt2 < k)
        {
            c += s2[j];
            j++;
            cnt2++;
            cnt1 = 0;
        }
    }

    cout << c << endl;
}
void id7()
{
    int n;
    cin >> n;

    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << "-1" << endl;
        return;
    }
    int d = 1;
    for (int i = 0; i < n; i++)
    {
        b[i] = d++;
    }
    

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            continue;
        if (i == n - 1)
        {
            swap(b[n - 1], b[n - 2]);
        }
        else
        {
            swap(b[i], b[i + 1]);
        }
    }
    for (auto i : b)
    {
        cout << i << " ";
    }
    cout << endl;
}
void id8()
{
    int n, m;
    cin >> n >> m;
    int sum = 0;
    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        sum += k;
    }
    if (sum - m < 0)
    {
        cout << '0' << endl;
    }
    else
    {
        cout << sum - m << endl;
    }
}
void id12()
{
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;
    if (n == 1 && s != t)
    {
        cout << "NO" << endl;
        return;
    }
    if (s == t)
    {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s == t)
        {
            cout << "YES" << endl;
            return;
        }
        if (s[i] != t[i])
        {
            swap(s[i], s[i + 1]);
        }
    }
}
void Marathon()
{
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long int s = 0;
    if (a < b)
        s++;
    if (a < c)
        s++;
    if (a < d)
        s++;
    cout << s << endl;
}

void id16()
{
    char arr[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            if (arr[i + 1][j - 1] == '
            {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
    }
}

void AllDistinct()
{
    ll n;
    cin >> n;
    set<ll> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    if ((n - s.size()) & 1)
        cout << s.size() - 1 << endl;
    else
        cout << s.size() << endl;
}
bool isPalindrome(string S)
{
    string P = S;
    reverse(P.begin(), P.end());
    if (S == P)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void TheClock()
{
    string s;
    cin >> s;
    int x;
    cin >> x;
    int ans = 0;
    int hour = x / 60;
    int min = x % 60;
    map<string,bool> visited;
    while (!visited[s])
    {
        ans += isPalindrome(s);
        visited[s] = true;
        int hh = (s[0]-'0')*10 + s[1]-'0';
        int mm = (s[3]-'0')*10 + s[4]-'0';
        mm += min;
        if(mm>59){
            hh++;
        }
        mm%=60;
        hh+=hour;
        hh%=24;
        s[0]=('0'+(hh/10));
        s[1]=('0'+(hh%10));
        s[3]=('0'+(mm/10));
        s[4]=('0'+(mm%10));
    }
    cout<<ans<<endl;
}
void BinaryDeque()
{
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

}
bool length3(int n)
{
    string s = to_string(n);
    if (s.length() >= 3)
        return true;
    return false;
}
void id9()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    if (length3(arr[0] + arr[1] + arr[2]))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
void Creep(){
    int a,b;
    cin>>a>>b;
    string s = "";
    int tc = min(a,b);
    for(int i=0;i<tc;i++){
        s += '1';
        s+= '0';
    }
    

    

    

    if(a>b){
        for(int i=0;i<(a-b);i++){
            s+='0';
        }
    }
    else{
        for(int i=0;i<(b-a);i++){
            s+='1';
        }
    }
    cout<<s<<endl;
}
void id0(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll ans = n;
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

        
    

    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]) ans+=i;
    }
    cout<<ans<<endl;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        id0();
    }

    return 0;
}