#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#define N 3010
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
struct ww {
    int a,b,l,r;
} e[N];
int i,j,k,n,m,s,an;
int f[N];
int get(int x) {
    return f[x]==x?x:f[x]=get(f[x]);
}
inline bool cc1(const ww &a,const ww &b) {
    return a.l<b.l;
}
int main() {
    scanf("%d%d",&n,&m);
    For(i,1,m) scanf("%d%d%d%d",&e[i].a,&e[i].b,&e[i].l,&e[i].r);
    sort(e+1,e+m+1,cc1);
    For(i,1,m) {
        For(j,1,n) f[j]=j;
        For(j,1,m) if (e[j].r>=e[i].r) {
            if (e[j].l>e[i].r) break;
            f[get(e[j].a)]=get(e[j].b);
            if (get(1)==get(n)) {
                an=max(an,e[i].r-e[j].l+1);
                break;
            }
        }
    }
    if (!an) printf("Nice work, Dima!\n");
    else printf("%d\n",an);
    

    return 0;
}


















































































