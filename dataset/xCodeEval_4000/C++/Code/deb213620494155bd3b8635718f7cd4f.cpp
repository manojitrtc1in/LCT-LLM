





















#include                                         <bits/stdc++.h>
using                                           namespace                                    std;typedef                  long long           ll;typedef               unsigned                            long                            long            ull;typedef                                           vector<int>                                      vi;typedef                                          pair<int,int>              ii;typedef                              vector<ii>                                    vii;typedef                      vector<ll>                                            vll;typedef                      pair<ll,ll>                                     pll;
#define         F                                  first

#define      S                         second

#define    random(x)                    (rand()%x)
const                                      int                            maxn=100005;char                                    s[maxn];struct                                          STRING{
                                             string                            s;                           int   pos;                                        inline                  bool               operator                 <(const     STRING  &q)const{
                                                               returns>q.s;        }
};priority_queue<STRING>    pq;int              main(){
   
                                             int                                              n,k;                          STRING             str;                                  scanf("%s\n%d",s,&k);          n=strlen(s);                                   if((ll)n*(n+1)/2<(ll)k){
                 puts("No such line.");                                                   return                                           0;}
                       for(int                                        i=0;i<n;i++){
                                                           str.pos=i;                                                                str.s=s[i];               pq.push(str);                          }
          for(int                   i=1;i<=k;i++){
                                                                   str=pq.top();                                                                    pq.pop();                                                              if(i==k){
                                                             printf("%s\n",str.s.c_str());                                                                  return               0;                                                                }
                                      str.pos++;                                      if(str.pos>=n)            continue;                        str.s.push_back(s[str.pos]);                                    pq.push(str);           }
                                            return              0;       return           0;}

