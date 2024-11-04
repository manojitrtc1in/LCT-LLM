














using namespace std;
const int maxn = 2e3 + 3;
typedef long long ll;

void read(int &x) {
	char ch; bool flag = 0;
	for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1); ch = getchar());
	for (x = 0; isdigit(ch); x = (x << 1) + (x << 3) + ch - 48, ch = getchar());
	x *= 1 - 2 * flag;
}



int n,m;
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
struct inof{
    int x,y,cnt,dir;
}temp;
char mp[1015][1015];
queue <inof> P;
int vis[1015][1015][4];
int main() {
    read(n),read(m);
    for(int i=0;i<n;i++){
        scanf("%s",mp[i]);
        for(int j=0;j<m;j++){
            if(mp[i][j]=='S'){
                temp.x=i,temp.y=j;
                temp.dir=-1;
                temp.cnt=0;
            }
        }
    }
    P.push(temp);
    memset(vis,0,sizeof(vis));
    while(!P.empty())
    {
        inof fuck = P.front();P.pop();
        for(int i=0;i<4;i++)
        {
            int tx=fuck.x+dx[i],ty=fuck.y+dy[i];
            if(tx>=0&&tx<n&&ty>=0&&ty<m&&mp[tx][ty]!='*')
            {
                if(vis[tx][ty][i]&&vis[tx][ty][i]<fuck.cnt+1)continue;
                if(fuck.dir==-1)
                {
                    temp.dir=i;
                    temp.cnt = 0;
                }
                else if(fuck.dir==i)
                {
                     temp.dir=i;
                     temp.cnt = fuck.cnt;
                }
                else
                {
                     if(fuck.cnt+1>2)continue;
                     temp.cnt=fuck.cnt+1;
                     temp.dir=i;
                }
                vis[tx][ty][i]=temp.cnt;
                temp.x=tx;
                temp.y=ty;
            

                if(mp[tx][ty]=='T')
                {
                    puts("YES");
                    return 0;
                }
                P.push(temp);
            }
        }
    }
    puts("NO");
    return 0;
}



    


        

         



            

            
            

            


            
            

            


            

            
