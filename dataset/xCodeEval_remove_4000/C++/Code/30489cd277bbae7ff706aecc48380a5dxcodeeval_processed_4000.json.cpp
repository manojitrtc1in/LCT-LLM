



using namespace std;
const int maxn=5e5;
string s;
int n,d[5],res;
vector<int> chot[2*maxn+2];

int main()
{
    IOS;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        int minm=maxn,dem=0;
        for (auto&x:s)
        {
            if (x=='(') dem++;else dem--;
            minm=min(minm,dem);
        }
        if (minm<0 && minm!=dem) continue;
        chot[maxn+dem].push_back(i);
    }
    for (int i=1;i<=maxn;i++)
         res+=min(chot[maxn+i].size(),chot[maxn-i].size());
         int k=chot[maxn].size();
    cout<<res+k/2;
}




