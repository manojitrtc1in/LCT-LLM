#include <stdio.h>
#include <string.h>

#define MAXN 1000100

int getq()
{
    char buf[50];
    int ret=0;
    scanf("%s",buf);
    for(int i=strlen(buf)-1;i>=0;i--)ret|=1<<(buf[i]-'a');
    return ret;
}

int main()
{
    char S[MAXN];
    int n,m;
    int Q[10010];
    int ans[10010];
    int Qs[10010];
    int Qs_size = 0;
    scanf("%s",S+1);
    n=strlen(S+1);
    for(int i=1;i<=n;i++)S[i]-='a';
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int q = getq();
        int found = 0;
        for(int j=0;j<Qs_size;j++){
            if(Qs[j] == q){
                ans[i] = ans[j];
                found = 1;
                break;
            }
        }
        if(!found){
            Qs[Qs_size] = q;
            ans[i] = 0;
            for(int j=1;j<=n;j++){
                int x=S[j];
                if(!vis[x])stk[++nn]=x,vis[x]=1;
                else
                {
                    int k;
                    for(k=1;;k++)if(stk[k]==x)break;
                    for(;k<nn;k++)stk[k]=stk[k+1];
                    stk[nn]=x;
                }
                int t=0;
                for(int k=nn;k;k--)
                {
                    t|=1<<stk[k];
                    if(j<n&&(t&(1<<S[j+1])))break;
                    if(Qs_size > 0 && Qs[Qs_size-1] == t){
                        ans[i]++;
                    }
                }
            }
            Qs_size++;
        }
    }
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}
