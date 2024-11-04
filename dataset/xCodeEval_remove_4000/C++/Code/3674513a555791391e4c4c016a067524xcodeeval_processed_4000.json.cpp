


using namespace std;


const ll MAXAI =(ll) 1e12;
const int INF = (int) 1e9;




ll merge(vector<ll>& a, vector<ll>& temp, ll left, ll mid, ll right)
{
    ll cnt = 0, i = left, j = mid, k = left;
    while(i <= mid - 1 && j <= right)
    {
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else { cnt += mid - i; temp[k++] = a[j++];}
    }
    
    while(i <= mid - 1) temp[k++] = a[i++];
    while(j <= right) temp[k++] = a[j++];
    
    for(ll i = left; i <= right; i++) a[i] = temp[i];
    return cnt;
}




ll id1(vector<ll>& a, vector<ll>& temp, ll left, ll right)
{
    ll mid, cnt = 0;
    if(right - left > 0)
    {
        mid = (right + left) / 2;
        cnt += id1(a, temp, left, mid);
        cnt += id1(a, temp, mid + 1, right);
        cnt += merge(a, temp, left, mid + 1, right);
    }
    return cnt;
    
}


ll id0(vector<ll>&a, ll n)
{
    ll cnt = 0;
    vector<ll> temp(n);
    cnt = id1(a, temp, 0, n - 1);
    return cnt;
}

bool check(ll mid, vector<ll>& a, ll k)
{
    for(ll i = 0; i < a.size(); i++)
    {
        ll sum = 0;
        for(ll j = i; j < i + mid; j++)
        {
            sum += a[j];
        }
        if(sum <= k) return true;
    }
    return false;
}

void solve5()
{
}



vector<vector<int>>g;
vector<pair<int, int>> color;

void dfs(int v, int par = -1)
{
    

    for(auto child : g[v])
    {
        

        if(child == par || child == v) continue;
        dfs(child, v);

        color[v].first += color[child].first;
        color[v].second += color[child].second;
    }
}


void solve6()
{
    int n;
    cin >> n;
    g.clear();
    g.assign(n + 1, {});
    color.clear();
    color.assign(n + 1, {0 , 0});
    for(int i = 2; i <= n ; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }












    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'W') color[i + 1].first = 1;
        else color[i + 1].second = 1;
    }

    


    dfs(1);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(color[i].first == color[i].second) cnt++;
    }
    cout << cnt << endl;
}


bool isequal(string& other, string& s)
{
    if(other.size() == s.size())
    {
        if(other[1] > s[1]) return true;
        else return false;
    }
    else
    {
        for(int i = 0; i < min((int)s.size(), (int)other.size()); i++)
        {
            if(other[i] > s[i]) return true;
        }
        return false;
    }
}

void solve8()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mark = 0;
    for(int i = 0; i < s.size() - 1; i++)
    {
        if(s[i] >= s[i + 1]) mark = i + 1;
        else break;
    }
    string other = s.substr(0, 1); 
    other += s.substr(0, 1);
    string out = s.substr(0, mark + 1);
    string out2 = s.substr(0, mark + 1);
    reverse(out2.begin(), out2.end());
    out += out2;
    

    

    if(isequal(other, s)) cout << out << endl;
    else cout << other << endl;
    
    
}



int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve8(); 
    
}
    
    
    
    

