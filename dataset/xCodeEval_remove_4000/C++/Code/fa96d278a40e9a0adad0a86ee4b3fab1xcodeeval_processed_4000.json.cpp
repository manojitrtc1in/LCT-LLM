








































using namespace std;

































































































typedef long long int lli;
typedef long long ll;
typedef double db;


























































































int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

struct resul
{
    int team;
    string name;
    int point=0;
    int per=0;
    int pereh=0;
    int pod=0;
};



int main()
{
    set <string> names;
    vector <string> a;
    int n;
    cin >> n;
    string *s=new string[n];
    for(int i=0;i<n;i++)
        cin >> s[i];
    
    for(int i=n-1;i>=0;i--)
    {
        if(names.find(s[i])==names.end())
        {
            names.insert(s[i]);
            a.push_back(s[i]);
        }
    }
    for(int i=0;i<a.size();i++)
        cout << a[i] << endl;
}
