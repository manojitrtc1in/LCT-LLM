

using namespace std;


 







int main()
{
    string s;
    cin>>s;
    stack<char>t;
    for(int i=0;i<s.size();++i)
    {
        if(!t.empty()&&t.top()!=s[i])
        {
            t.pop();
        }
        else
        t.push(s[i]);
    }
    string k;
    ll i=0;
    while(!t.empty())
    {
        k.pb(t.top());
        t.pop();
    }
    reverse(k.begin(),k.end());
    cout<<k;
}