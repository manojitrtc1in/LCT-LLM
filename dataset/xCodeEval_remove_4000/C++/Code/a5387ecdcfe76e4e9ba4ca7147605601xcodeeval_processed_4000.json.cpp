

using namespace std;
typedef long long ll;
typedef double dd;






ll mx=INT_MAX;
ll mi=INT_MIN;
const ll mod=1e9+7;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,j,s=0,o=0,e=0,p,n,q;
        string ss,so="",se="";
        vector<char> ve,vo;
        cin>>ss;
        for(i=0;i<ss.size();i++)
        {
            if(ss[i]=='1'||ss[i]=='3'||ss[i]=='5'||ss[i]=='7'||ss[i]=='9') vo.pb(ss[i]);
            else ve.pb(ss[i]);
        }
        if(vo.size()==0){
            for(i=0;i<ve.size();i++) cout<<ve[i];
            cout<<endl;continue;
        }
        if(ve.size()==0){
            for(i=0;i<vo.size();i++) cout<<vo[i];
            cout<<endl;continue;
        }
        i=0;j=0;
        for(i=0;i<vo.size();i++)
        {

            if(j<ve.size()&&ve[j]<vo[i])
            {
                cout<<ve[j];j++;i--;
            }
            else {
                cout<<vo[i];
            }
        }

        for(i=j;i<ve.size();i++) cout<<ve[i];
        cout<<endl;
    }
}