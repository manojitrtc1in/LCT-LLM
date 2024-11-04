








using namespace std;
struct segment_tree
{
	int l,r,cnt,max_id;
};
vector<segment_tree>vec[510010];
vector<int>ll[510010],rr[510010];
int num_node[510010],list[510000],cnt_list;
segment_tree nw;
struct query
{
	int l,r,pl,pr;
};
query qy[510000];
bool cmp(int id1,int id2)
{
	return qy[id1].pl<qy[id2].pl;
}
struct pp
{
	int id,x;
	bool operator <(const pp &temp)const
	{
		if(x==temp.x)
		{
			if(qy[id].pr-qy[id].pl==qy[temp.id].pr-qy[temp.id].pl)
		       return id<temp.id;
		    return qy[id].pr-qy[id].pl>qy[temp.id].pr-qy[temp.id].pl;
		}
		return x<temp.x;
	}
};
set<pp>hs;
set<pp>::iterator it;
pp now;
struct xx
{
	int x,flag,id;
	bool operator <(const xx &temp)const
	{
		if(x==temp.x)
		{
		   if(flag==temp.flag)
		   {
		   	   if(qy[id].pr-qy[id].pl==qy[temp.id].pr-qy[temp.id].pl)
		          return id<temp.id;
		       return qy[id].pr-qy[id].pl>qy[temp.id].pr-qy[temp.id].pl;
		   }
		   return flag<temp.flag;
		}
		return x<temp.x;
	}
};
xx x[1100000];
int num_q,cnt;
const int maxn=600001;
char str[555555],tr[55555];
int m,len,n,lg[600001],pa[5010000];
int sa[maxn],rnk[maxn],lcp[maxn],fk[20][maxn];
int num[maxn],sum[55555],pos[600001],nxt[600001],ix[510000],ans[2][510000],pre[600001];
vector<int>adj[510000];
inline bool leq(int a1, int a2, int b1, int b2)
{
    return (a1 < b1 || a1 == b1 && a2 <= b2);
}

inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3)
{
    return(a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3));
}

static void id0(int* a, int* b, int* r, int n, int K)
{
    int* c = new int[K + 1];
    int i,sum;
    for(i = 0; i <= K; i++) 
        c[i] = 0;
    for(i = 0; i < n; i++) 
        c[r[a[i]]]++;
    for(i = 0, sum = 0; i <= K; i++)
    {
        int t = c[i]; 
        c[i] = sum; 
        sum += t;
    }
    for(i = 0; i < n; i++) 
        b[c[r[a[i]]]++] = a[i];
    delete [] c;
}

void suffixArray(int* T, int* SA, int n, int K)
{
    int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
    int* R = new int[n02 + 3]; R[n02] = R[n02+1] = R[n02 + 2] = 0;
    int* SA12 = new int[n02 + 3]; SA12[n02] = SA12[n02 + 1] = SA12[n02 + 2] = 0;
    int* R0 = new int[n0];
    int* SA0 = new int[n0];
    int i,j;
    for(i = 0, j = 0; i < n + (n0 - n1); i++) if(i % 3 != 0) R[j++] = i;
    id0(R , SA12, T + 2, n02, K);
    id0(SA12, R , T + 1, n02, K);
    id0(R , SA12, T , n02, K);
    int name = 0, c0 = -1, c1 = -1, c2 = -1;
    
    for( i = 0; i < n02; i++)
    {
        if(T[SA12[i]] != c0 || T[SA12[i] + 1] != c1 || T[SA12[i] + 2] != c2)
        {
            name++; c0 = T[SA12[i]]; c1 = T[SA12[i] + 1]; c2 = T[SA12[i] + 2];
        }
        if(SA12[i] % 3 == 1) { R[SA12[i] / 3] = name; }
        else{ R[SA12[i] / 3 + n0] = name; }
    }
    if(name < n02)
    {
        suffixArray(R, SA12, n02, name);
        for(int i = 0; i < n02; i++) R[SA12[i]] = i + 1;
    }
    else
        for(int i = 0; i < n02; i++) SA12[R[i] - 1] = i;
    for(i = 0, j = 0; i < n02; i++) if(SA12[i] < n0) R0[j++] = 3 * SA12[i];
    id0(R0, SA0, T, n0, K);
    for(int p = 0, t = n0 - n1, k = 0; k < n; k++)
    {
        
        int i = GetI();
        int j = SA0[p];
        if(SA12[t] < n0 ?
        leq(T[i], R[SA12[t] + n0], T[j], R[j / 3]) : leq(T[i],T[i + 1],R[SA12[t] - n0 + 1], T[j],T[j + 1],R[j / 3 + n0]))
        {
            SA[k] = i; t++;
            if(t == n02)
                for(k++; p < n0; p++, k++) SA[k] = SA0[p];
        }
        else{
            SA[k] = j;
            if(++p == n0)for(k++; t < n02; t++, k++) SA[k] = GetI();
        }
    }
    delete [] R; delete [] SA12; delete [] SA0; delete [] R0;
}

void LCP(int *str) 
{ 
    int i,j,k;
    len=n;
    for(k=i=0;i<len;i++) 
    { 
        if( rnk[i] == len - 1 ) lcp[ rnk[i] ] = k = 0; 
        else 
        { 
            if( k > 0 )    k--; 
            j = sa[ rnk[i] + 1]; 
            for(;str[i+k] == str[j+k];k++); 
            lcp[rnk[i]] = k; 
        } 
    } 
}
int rmq(int id1,int id2)
{
	int ip1,ip2,le,ri,id;
	ip1=rnk[id1];
	ip2=rnk[id2];
	if(ip1<ip2)
	{
		le=ip1;
		ri=ip2-1;
	}
	else
	{
		le=ip2;
		ri=ip1-1;
	}
	id=lg[ri-le+1];
	return min(fk[id][le],fk[id][ri+1-(1<<id)]);
}
void insert(int pos,int idx,int id)
{
	int i,j,s,p,q,mid;
	mid=(vec[idx][id].l+vec[idx][id].r)/2;
	if(vec[idx][id].l==vec[idx][id].r)
	{
		vec[idx][id].max_id=vec[idx][id].l;
		vec[idx][id].cnt++;
	    return;
	}
	if(pos<=mid)
	{
		if(ll[idx][id]<0)
		{
			ll[idx][id]=num_node[idx]++;
			ll[idx].push_back(-1);
			rr[idx].push_back(-1);
			nw.l=vec[idx][id].l;
		    nw.r=mid;
		    nw.cnt=0;
		    vec[idx].push_back(nw);
		}
		insert(pos,idx,ll[idx][id]);
	}
	else
	{
		if(rr[idx][id]<0)
		{
		    rr[idx][id]=num_node[idx]++;
		    ll[idx].push_back(-1);
		    rr[idx].push_back(-1);
		    nw.l=mid+1;
		    nw.r=vec[idx][id].r;
		    nw.cnt=0;
		    vec[idx].push_back(nw);
		}
		insert(pos,idx,rr[idx][id]);
	}
	vec[idx][id].cnt=0;
	vec[idx][id].max_id=-1;
	if(ll[idx][id]>=0)
	{
	   vec[idx][id].cnt=vec[idx][ll[idx][id]].cnt;
	   vec[idx][id].max_id=vec[idx][ll[idx][id]].max_id;
	}
	if(rr[idx][id]>=0)
    {
    	if(vec[idx][id].cnt<vec[idx][rr[idx][id]].cnt)
    	{
	    	vec[idx][id].cnt=vec[idx][rr[idx][id]].cnt;
	    	vec[idx][id].max_id=vec[idx][rr[idx][id]].max_id;
	    }
    }
}
void mrg(int idx1,int idx2,int id1,int id2)
{
	int l1=ll[idx1][id1],r1=rr[idx1][id1],l2=ll[idx2][id2],r2=rr[idx2][id2];
	if(vec[idx1][id1].l==vec[idx1][id1].r)
	{
		vec[idx1][id1].max_id=vec[idx1][id1].l;
		vec[idx1][id1].cnt+=vec[idx2][id2].cnt;
	    return;
	}
	if(l2>=0)
	{
		if(l1<0)
		{
			ll[idx1][id1]=num_node[idx1]++;
			ll[idx1].push_back(-1);
			rr[idx1].push_back(-1);
			nw.l=vec[idx2][l2].l;
			nw.r=vec[idx2][l2].r;
			nw.cnt=0;
			vec[idx1].push_back(nw);
		}
		mrg(idx1,idx2,ll[idx1][id1],l2);
	}
	if(r2>=0)
	{
		if(r1<0)
		{
			rr[idx1][id1]=num_node[idx1]++;
			ll[idx1].push_back(-1);
			rr[idx1].push_back(-1);
		    nw.l=vec[idx2][r2].l;
		    nw.r=vec[idx2][r2].r;
		    nw.cnt=0;
		    vec[idx1].push_back(nw);
		}
		mrg(idx1,idx2,rr[idx1][id1],r2);
	}
	vec[idx1][id1].cnt=0;
	vec[idx1][id1].max_id=-1;
	if(ll[idx1][id1]>=0)
	{
	   vec[idx1][id1].cnt=vec[idx1][ll[idx1][id1]].cnt;
	   vec[idx1][id1].max_id=vec[idx1][ll[idx1][id1]].max_id;
	}
	if(rr[idx1][id1]>=0)
    {
    	if(vec[idx1][id1].cnt<vec[idx1][rr[idx1][id1]].cnt)
    	{
	    	vec[idx1][id1].cnt=vec[idx1][rr[idx1][id1]].cnt;
	    	vec[idx1][id1].max_id=vec[idx1][rr[idx1][id1]].max_id;
	    }
    }
	    
}
segment_tree query(int left,int right,int idx,int id)
{
	int l=ll[idx][id],r=rr[idx][id];
	segment_tree res,rk;
	res.cnt=0;
	if(left>vec[idx][id].r||right<vec[idx][id].l)
	    return res;
    if(left<=vec[idx][id].l&&right>=vec[idx][id].r)
        return vec[idx][id];
    if(l>=0)
    	res=query(left,right,idx,l);
    if(r>=0) 
    {
    	rk=query(left,right,idx,r);
    	if(res.cnt<rk.cnt)
    	  res=rk;
    }
    return res;
}
void solve(int id)
{
	int i,j,s,p,q,ip,ax=0,im,pr;
	im=-1;
	sort(adj[id].begin(),adj[id].end(),cmp);
	for(i=0;i<adj[id].size();i++)
	{
		ip=adj[id][i];
		solve(ip);
		if(ax<num_node[ix[ip]])
		{
			ax=num_node[ix[ip]];
			im=ix[ip];
		}
	}
	if(ax>0)
		ix[id]=im;
	else
	{
		if(cnt_list==0)
	       ix[id]=cnt++;
        else
        {
        	ix[id]=list[cnt_list-1];
        	cnt_list--;
        }
		nw.l=0;
    	nw.r=m-1;
	    nw.cnt=0;
	    nw.max_id=-1;
	    num_node[ix[id]]=1;
	    ll[ix[id]].push_back(-1);
	    rr[ix[id]].push_back(-1);
	    vec[ix[id]].push_back(nw);
	}
	pr=qy[id].pl;
	for(i=0;i<adj[id].size();i++)
    {
    	ip=adj[id][i];
    	for(j=pr;j<qy[ip].pl;j=nxt[j])
	    	insert(pos[j]-1,ix[id],0);
		if(ix[ip]!=ix[id])
    	{
	    

	    

			mrg(ix[id],ix[ip],0,0);
			vec[ix[ip]].clear();
			ll[ix[ip]].clear();
			rr[ix[ip]].clear();
			num_node[ix[ip]]=0;
			list[cnt_list++]=ix[ip];
		}
        pr=nxt[qy[ip].pr];
	}
    for(j=pr;j<=qy[id].pr;j=nxt[j])
        insert(pos[j]-1,ix[id],0);
	segment_tree nx=query(qy[id].l,qy[id].r,ix[id],0);
    if(nx.cnt==0)
       nx.max_id=qy[id].l;
    ans[0][id]=nx.max_id+1;
    ans[1][id]=nx.cnt;
    if(pa[id]<0)
    {
    	vec[ix[id]].clear();
    	ll[ix[id]].clear();
    	rr[ix[id]].clear();
    	num_node[ix[id]]=0;
    	list[cnt_list++]=ix[id];
    }
}
int main()
{
	int i,j,s,p,q,k;
	gets(str);
	n=strlen(str);
	scanf("%d",&m);
	getchar();
	lg[1]=0;
	for(i=2;i<=600000;i++)
		lg[i]=lg[i/2]+1;
	for(i=0;i<n;i++)
	    num[i]=str[i]-'a'+2;
    num[n++]=1;
	for(i=0;i<m;i++)
	{
		gets(tr);
		sum[i]=n;
		len=strlen(tr);
		for(j=0;j<len;j++)
		    num[n++]=tr[j]-'a'+2;
        num[n++]=0;
	}
	sum[i]=n;
	suffixArray(num,sa,n,27);
	for(i=0;i<n;i++)
		rnk[sa[i]]=i;
	for(i=0;i<n;i++)
	   pos[rnk[i]]=0;
    for(i=0;i<m;i++)
    {
    	for(j=sum[i];j<sum[i+1];j++)
    	   pos[rnk[j]]=i+1;
    }
	LCP(num);
	for(i=0;i<n;i++)
	   fk[0][i]=lcp[i];
    for(k=1;(1<<k)<=n;k++)
       for(i=0;i+(1<<k)<=n;i++)
          fk[k][i]=min(fk[k-1][i],fk[k-1][i+(1<<(k-1))]);
    scanf("%d",&num_q);
     nxt[n]=n;
	 for(i=n;i>0;i--)
     {
     	if(i<n&&pos[i]>0)
     	   nxt[i-1]=i;
  	    else
  	       nxt[i-1]=nxt[i];    
     }
     pre[0]=-1;
     for(i=0;i<n-1;i++)
     {
     	if(pos[i]>0)
     	   pre[i+1]=i;
  	    else
  	       pre[i+1]=pre[i];
     }
    for(i=0;i<num_q;i++)
    {
    	scanf("%d%d%d%d",&qy[i].l,&qy[i].r,&qy[i].pl,&qy[i].pr);
    	qy[i].l--;
    	qy[i].r--;
    	qy[i].pl--;
    	qy[i].pr--;
    	int l=rnk[qy[i].pl],low,high,mid;
    	low=l+1;
    	high=n-1;
    	int dx=qy[i].pr-qy[i].pl+1;
		while(low<=high)
    	{
	    	mid=(low+high)>>1;
	    	if(rmq(sa[l],sa[mid])>=dx)
	    	   low=mid+1;
  	        else
  	           high=mid-1;
	    }
	    if(pos[high]>0)
	        qy[i].pr=high;
	    else
	        qy[i].pr=pre[high];
		low=0;
	    high=l-1;
	    while(low<=high)
	    {
    		mid=(low+high)>>1;
    		if(rmq(sa[mid],sa[l])>=dx)
    		   high=mid-1;
 		    else
 		       low=mid+1;
    	}
    	if(pos[low]>0)
        	qy[i].pl=low;
        else
            qy[i].pl=nxt[low];
	}
    cnt=0;
    for(i=0;i<num_q;i++)
    {
    	if(qy[i].pl>qy[i].pr)
    	    continue;
    	x[cnt].flag=-1;
    	x[cnt].id=i;
    	x[cnt++].x=qy[i].pl;
    	x[cnt].flag=1;
    	x[cnt].id=i;
    	x[cnt++].x=qy[i].pr;
    }
    sort(x,x+cnt);
    hs.clear();
    for(i=0;i<num_q;i++)
       pa[i]=-1;
    for(i=0;i<cnt;i++)
    {
   	    now.id=x[i].id;
   	    now.x=qy[now.id].pl;
    	if(x[i].flag<0)
	    {	
 		    it=hs.upper_bound(now);
    		if(it!=hs.begin())
    		{
    			it--;
		    	pa[now.id]=it->id;
		    }
	    	hs.insert(now);
	    }
	    else
    		hs.erase(now);
    }
    for(i=0;i<=num_q;i++)
       adj[i].clear();
	memset(ix,-1,sizeof(ix));
	for(i=0;i<num_q;i++)
    {
    	if(pa[i]>=0)
    	  adj[pa[i]].push_back(i);
    }
    for(i=0;i<=num_q;i++)
    {
   	   ll[i].clear();
   	   rr[i].clear();
       vec[i].clear();
    }
    cnt_list=0;
    cnt=0;
    memset(ans,0,sizeof(ans));
    for(i=0;i<num_q;i++)
        ans[0][i]=qy[i].l+1;
    for(i=0;i<num_q;i++)
    {
    	if(qy[i].pl>qy[i].pr)
    	   continue;
    	if(pa[i]<0)
    	   solve(i);
    }
    for(i=0;i<num_q;i++)
       printf("%d %d\n",ans[0][i],ans[1][i]);
	return 0;
}
