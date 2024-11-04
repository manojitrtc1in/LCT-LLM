






using namespace std;

struct pravila
{
    string p;
    int L;
    int R;
};

int Contains(const string& s, const string& t)
{
    int qanak = 0;
    const int p = 31;
    vector<long long> p_pow (max (s.length(), t.length()));
    p_pow[0] = 1;
    for (size_t i=1; i<p_pow.size(); ++i)
        p_pow[i] = p_pow[i-1] * p;

    vector<long long> h (t.length());
    for (size_t i=0; i<t.length(); ++i)
    {
        h[i] = (t[i] - 'a' + 1) * p_pow[i];
        if (i)  h[i] += h[i-1];
    }

    long long h_s = 0;
    for (size_t i=0; i<s.length(); ++i)
        h_s += (s[i] - 'a' + 1) * p_pow[i];

    for (size_t i = 0; i + s.length() - 1 < t.length(); ++i)
    {
        long long cur_h = h[i+s.length()-1];
        if (i)  cur_h -= h[i-1];        
        if (cur_h == h_s * p_pow[i])
            qanak++;
    }
    

    return qanak;
}

bool Good(const string& s, const pravila& v)
{
    int number = Contains(s, v.p);
    if (number >= v.L && number <= v.R)
        return true;
    return false;
}

bool Good(const string& s, const vector <pravila>& v)
{
    for (int i = 0; i < v.size(); ++i)
        if (!Good(s, v[i]))
            return false;
    return true;
}

int main()
{
    string s;
    int n;  
    cin >> s >> n;
    vector <pravila> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].p >> v[i].L >> v[i].R;
    set <string> setS;
    int answer = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        string st = "";
        for (int j = i; j < s.size(); ++j)
        {
            st = st + s[j];
            if (setS.find(st) == setS.end())
            {
                setS.insert(st);
                if (Good(st, v))
                    answer++;
            }
        }
    }
    cout << answer << endl;
}



