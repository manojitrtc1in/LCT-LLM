














using namespace std;
const int maxn = 2e3 + 3;
typedef long long ll;

void read(int &x) {
	char ch; bool flag = 0;
	for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1); ch = getchar());
	for (x = 0; isdigit(ch); x = (x << 1) + (x << 3) + ch - 48, ch = getchar());
	x *= 1 - 2 * flag;
}
int n,m,s,t;
vector <int> vec[maxn];

int dx[maxn],dy[maxn];

int bfs(int s,int ds[])
{
    queue < int >fuck;
    fuck.push(s);
    ds[s]=0;
    while(!fuck.empty())
    {
        int tem = fuck.front();
        fuck.pop();
        int siz=vec[tem].size();
        for(int i=0;i<siz;i++)
        {
            if(ds[tem]+1<ds[vec[tem][i]])
            {
                ds[vec[tem][i]]=ds[tem]+1;
                fuck.push(vec[tem][i]);
            }
        }
    }
    return 1;
}

int main() {
    read(n),read(m),read(s),read(t);
    memset(dx,0x3f,sizeof(dx));
    memset(dy,0x3f,sizeof(dy));
    for(int i=0;i<m;i++){
        int l,r;
        read(l),read(r);
        vec[l].push_back(r);
        vec[r].push_back(l);
    }
    bfs(s,dx);
    bfs(t,dy);
    int ans=0;
   

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(dx[i]+dy[j]+1>=dx[t]&&dy[i]+dx[j]+1>=dx[t])ans++;
        }
    }
    printf("%d\n",ans-m)
;    return 0;
}



    


        

         



            

            
            

            


            
            

            


            

            
