







using namespace std;
typedef long long ll;




inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();return x*f;}

const int maxn = 100005;

struct node{
    int x, y;
};

vector<node> vec[200];
int n, m, x, y;

int main()
{
    FAST_IO;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        vec[x].push_back((node){x,i});
        vec[y].push_back((node){y,i});
    }
    int stp = m+1;
    for(int i=1;i<=n;i++)
    {
        if(vec[i].empty())
            vec[i].push_back((node){i,stp++});
        int l = vec[i].size();
        cout<<l<<endl;
        for(int j=0;j<l;j++)
			cout<<vec[i][j].x<<" "<<vec[i][j].y<<endl;

    }

    return 0;
}

