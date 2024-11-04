







using namespace std;
const int mod=1e9+9,base=27;
struct pp
{
	int id;
	char ch;
};
pp now;
vector<pp>adj[20201],tadj[20201][26];
int tr[2][20100],ex[20100];
int ps[20100],pom[20100],di[20100],ha[2][20100],pd[20100],ls[55],cnt_ls,deep[20010],pw[20100],lm[20100],id0;
int n,num_q,ans[20100],num_node,size[20100],mi,ch,pa[20100],to[20100],cr[401000];
bool vis[20100];
int bs[400100],trie[401000][26],queue[20110],temp1,temp2,temp,dist[400000],tw[401000],list[401000],cnt_list,pos[401000],hs[2][400000],pc[401000],sum[401000];
int pk[401000],pe[401000],sz[401000][27],zz[20100];
int pm[20100];
struct qr
{
	int y,id;
};
vector<qr>vr[20010];
qr nw;
vector<int>vec[20100];
void prp(int id,int pr)
{
	int i,j,s,p,q,ip,ch=-1;
	pa[id]=pr;
	di[id]=0;


	for(i=0;i<adj[id].size();i++)
	{
		ip=adj[id][i].id;
		if(ip==pr)
		    continue;
        deep[ip]=deep[id]+1;
        prp(ip,id);
        if(di[id]<di[ip]+1)
        {
        	di[id]=di[ip]+1;
        	ch=i;
        }
	}
	if(ch>=0)
	{
		swap(adj[id][ch],adj[id][0]);
		ps[adj[id][0].id]=id;
	}
}
void gps(int id)
{
	int i,j,s,p,q,ip;
	lm[id0++]=id;
	pom[id]=id0-1;
	for(i=0;i<adj[id].size();i++)
	{
		ip=adj[id][i].id;
		if(ip==pa[id])
		   continue;
        pd[ip]=adj[id][i].ch-'a';
        gps(ip);
	}
}
void ho(int id)
{
	int i,j,s,p,q,ch=-1;
	dist[id]=0;
	sz[id][0]=bs[id];
	tw[id]=id;
	cr[id]=-1;
	for(i=0;i<26;i++)
	{
		if(trie[id][i]>0)
		{
		   ho(trie[id][i]);
		   pc[trie[id][i]]=i;
		   sz[id][i+1]=sz[trie[id][i]][26];
		   if(dist[id]<dist[trie[id][i]]+1)
  	   	   {
   		 	   dist[id]=dist[trie[id][i]]+1;
   		       cr[id]=ch=trie[id][i];   
  	   	   }
		}
	}
	if(ch>=0)
	{
	   tw[id]=tw[ch];
	   pk[ch]=id;
	}
	for(i=0;i<26;i++)
       sz[id][i+1]+=sz[id][i];
}
void tra(int id)
{
	int i,j,s,p,q;
	list[cnt_list++]=id;
	pos[id]=cnt_list-1;
	if(cr[id]>=0)
	   tra(cr[id]);
    for(i=0;i<26;i++)
    {
    	if(trie[id][i]>0&&trie[id][i]!=cr[id])
    	   tra(trie[id][i]);
    }
}
void get_size(int id,int pr)
{
	int i,j,s,p,q,ip;
	size[id]=vr[id].size()+1;
	for(i=0;i<adj[id].size();i++)
	{
		ip=adj[id][i].id;
		if(!vis[ip]&&ip!=pr)
		{
			get_size(ip,id);
			size[id]+=size[ip];
		}
	}
}
void choose_root(int id,int pr,int now_sz,int &ch)
{
	int i,j,s,p,q,ax=now_sz,ip;
	for(i=0;i<adj[id].size();i++)
	{
		ip=adj[id][i].id;
		if(ip==pr||vis[ip])
		    continue;
		if(ax<size[ip])
			ax=size[ip];
	}
	if(mi>ax)
	{
		mi=ax;
		ch=id; 
	}
	for(i=0;i<adj[id].size();i++)
	{
		ip=adj[id][i].id;
		if(ip==pr||vis[ip])
		    continue;
		choose_root(ip,id,now_sz+size[id]-size[ip],ch);	
	}
}
void construct(int id,bool flag)
{
	int i,j,s,p,q,ch,ip,ro,idd;
	to[id]=num_node;
	queue[0]=id;
	bs[num_node]=1;
	pe[num_node]=-1;
	memset(trie[num_node],0,sizeof(trie[num_node]));
	num_node++;
	temp1=temp2=0;
	temp=1;
	vis[id]=true;
	while(temp1<=temp2)
	{
		for(i=temp1;i<=temp2;i++)
		{
			idd=queue[i];
			for(j=0;j<adj[idd].size();j++)
			{
				ch=adj[idd][j].ch-'a';
				ip=adj[idd][j].id;
				if(!vis[ip])
				{
					if(flag==0)
					{
				       if(idd==id)
				    		pm[ip]=ip;
				    	else
				    	    pm[ip]=pm[idd];
					}
					if(trie[to[idd]][ch]==0)
					{
						bs[num_node]=0;
						pe[num_node]=to[idd];
						memset(trie[num_node],0,sizeof(trie[num_node]));
						trie[to[idd]][ch]=num_node++;  
						if(num_node>=400000)
						   exit(0); 
					}
					to[ip]=trie[to[idd]][ch];
					bs[to[ip]]++;
					vis[ip]=true;
					queue[temp++]=ip;
					if(flag==0&&vr[ip].size()>0)
					    vec[pm[ip]].push_back(ip);
				}
			}
		}
		temp1=temp2+1;
		temp2=temp-1;
	}
	for(i=0;i<temp;i++)
	   vis[queue[i]]=false;
    for(i=to[id];i<num_node;i++)
    {
    	pk[i]=i;
       memset(sz[i],0,sizeof(sz[i]));
    }
    pc[to[id]]=-1;
    ho(to[id]);
    tra(to[id]);
    for(i=to[id];i<num_node;i++)
       pk[list[i]]=pk[pk[list[i]]]; 
	if(pos[to[id]]==0)
    	hs[0][pos[to[id]]]=pw[id]+1;
    else
    {
        hs[0][pos[to[id]]]=(int)((long long)hs[0][pos[to[id]]-1]*(long long)base%mod);
        hs[0][pos[to[id]]]=(hs[0][pos[to[id]]]+pw[id]+1)%mod;
	}
    sum[pos[to[id]]]=0;
  	for(i=pos[to[id]];i<cnt_list-1;i++)
    {
       	hs[0][i+1]=(int)((long long)hs[0][i]*(long long)base%mod);
       	hs[0][i+1]=(hs[0][i+1]+pc[list[i+1]]+1)%mod;
       	if(i+1<cnt_list)
           	sum[i+1]=sum[i]+sz[list[i]][pc[list[i+1]]];
        else
             sum[i+1]=sum[i]+1;
    }
    for(i=cnt_list-1;i>=pos[to[id]];i--)
    {
    	hs[1][i]=(int)((long long)hs[1][i+1]*(long long)base%mod);
    	if(i>pos[to[id]])
		   hs[1][i]=(hs[1][i]+pc[list[i]]+1)%mod;
	   else
	       hs[1][i]=(hs[1][i]+pw[id]+1)%mod;
    }
}
int lca(int x,int y)
{
	while(true)
	{
		if(ps[x]==ps[y])
		{
			if(pom[x]<pom[y])
			   return x;
            return y;
		}
		if(deep[ps[x]]>deep[ps[y]])
			x=pa[ps[x]];
		else
		    y=pa[ps[y]];
	}
}
int query(int flag,int left,int right)
{
	int ret;
	if(flag==0)
		ret=ha[0][right]-(int)((long long)ha[0][left-1]*(long long)ex[right-left+1]%mod);
	else if(flag==1)
	    ret=hs[0][right]-(int)((long long)hs[0][left-1]*(long long)ex[right-left+1]%mod);
    else if(flag==2)
        ret=hs[1][left]-(int)((long long)hs[1][right+1]*(long long)ex[right-left+1]%mod);
    else
        ret=(ha[1][left]-(int)((long long)ha[1][right+1]*(long long)ex[right-left+1]%mod));
	if(ret<0) 
        ret+=mod;
    return ret;
}
int solve(int x1,int lca,int x,int y,bool ju,int u)
{
	int i,j,s,p,q,low,high,mid,ret=0,ch,flag;
	while(!ju||x!=pom[y])
	{
		if(!ju&&x==lca)
		{
		   ju=true;
		   x=pom[x];
		}
		if(ju&&x==pom[y])
		    break;
		if(ju&&x==pom[ls[u-1]])
        {
        	u--;
            x=pom[ps[ls[u-1]]]-1;
        }
        if(ju==0)
        {
        	if(ps[x]!=ps[lca])
        	   high=pom[x]-pom[ps[x]]+1;
			 else
     	       high=pom[x]-pom[lca];
             ch=pd[x];
        }
        else
        {
    	    ch=pd[lm[x+1]];
        	high=pom[ls[u-1]]-x;
        }
		high=min(high,pos[tw[x1]]-pos[x1]);
       	int ll,rr;
		low=0;
		while(low<=high)
        {
        	mid=(low+high)>>1;
			if(ju==0)
        	{
	        	ll=pom[x]-mid+1;
	        	rr=pom[x];
	        	flag=3;
	        }
	        else
	        {
        		ll=x+1;
        		rr=x+mid;
        		flag=0;
        	}
        	if(query(1,pos[x1]+1,pos[x1]+mid)==query(flag,ll,rr))
        	    low=mid+1;
    	    else
    	        high=mid-1;
        }
        if(high==0)
        {
        	ret+=sz[x1][ch];
        	high=1;
        	if(trie[x1][ch]==0)
        	    break;
			x1=trie[x1][ch];
        }
        else
        {
            ret+=sum[pos[x1]+high]-sum[pos[x1]];
            x1=list[pos[x1]+high];
		}
		if(ju==0)
			x=pa[lm[pom[x]-high+1]];
		else
          	x=x+high;
	}
	return ret;
}
int get_path(int from,int to,int &x,int y,int lca,bool &ju,int &u)
{
	int dx,ch,flag;
	while(from!=pe[to]&&(!ju||x!=pom[y]))
	{
		if(!ju&&x==lca)
		{
			ju=true;
			x=pom[x];
		}
		if(ju&&x==pom[y])
		    break;
        if(ju&&x==pom[ls[u-1]])
        {
        	u--;
        	x=pom[ps[ls[u-1]]]-1;
        }
        if(ju==0)
        {
        	if(ps[x]!=ps[lca])
        	   dx=pom[x]-pom[ps[x]]+1;
     	    else
     	       dx=pom[x]-pom[lca];
  	        flag=3;
			ch=pd[x];
        }
        else
        {
        	ch=pd[lm[x+1]];
        	dx=pom[ls[u-1]]-x;
        	flag=0;
        } 
        if(pk[from]==pk[to])
        	dx=min(dx,pos[from]-pos[to]+1);
        else
            dx=min(dx,pos[from]-pos[pk[from]]+1);
		int ll,rr;
        if(ju)
        {
        	ll=x+1;
        	rr=x+dx;
        }
        else
        {
        	ll=pom[x]-dx+1;
        	rr=pom[x];
        }
        if(query(flag,ll,rr)!=query(2,pos[from]-dx+1,pos[from]))
        {
        	int low=0,high=dx,mid;
        	int px=x,pf=from;
        	while(low<=high)
        	{
	        	mid=(low+high)>>1;
        	    if(ju)
        	    {
    	        	ll=x+1;
    	        	rr=x+mid;
    	        }
    	        else
    	        {
    	           ll=pom[x]-mid+1;
    	           rr=pom[x];
        	    }
        	    if(query(flag,ll,rr)==query(2,pos[from]-mid+1,pos[from]))
        	        low=mid+1;
    	        else
    	            high=mid-1; 
	        }
	        if(ju)
	           x+=high;
            else
            {
            	if(high>0)
                	x=pa[lm[pom[x]-high+1]];
            }
            if(high>0)
			     from=pe[list[pos[from]-high+1]];
          	if(!ju&&x==lca)
	     	{
	    		ju=true;
	         	x=pom[x];
	     	}  
	        if(ju&&x==pom[ls[u-1]])
            {
            	u--;
            	x=pom[ps[ls[u-1]]]-1;
            }
			if(ju==0)
			   ch=pd[x];
			else
			   ch=pd[lm[x+1]];
			if(pc[from]<ch)
			   return -1;
			if(pc[from]>ch)
			   return 1;
          

        }
        if(ju)
           x+=dx;
        else
          	x=pa[lm[pom[x]-dx+1]];
        from=pe[list[pos[from]-dx+1]];
	}
	if(!ju&&x==lca)
	{
		ju=true;
		x=pom[x];
	}
	if(!ju||x!=pom[y])
	   return 0;
	return 1;
}
void gwp(int id,int pr)
{
	int i,j,s,p,q,ip;
	zz[id]=1;
	for(i=0;i<adj[id].size();i++)
	{
		ip=adj[id][i].id;
		if(ip==pr||vis[ip])
		   continue;
        gwp(ip,id);
        zz[id]+=zz[ip];
	}
}
void dfs(int id)
{
	int i,j,s,p,q,x,y,ip,ie,u,ch;
	bool ju; 




    for(i=0;i<adj[id].size();i++)
    {
    	ip=adj[id][i].id;
	   	vec[ip].clear();
    }
    

    gwp(id,-1);
    construct(id,0);
    

    for(i=0;i<vr[id].size();i++)
    {
    	x=id;
    	y=vr[id][i].y;
        cnt_ls=0;
       	ip=lca(x,y);
       	

	    while(true)
	    {
		    ls[cnt_ls++]=y;
		    if(ps[y]==ps[ip])
		        break;
			y=pa[ps[y]];
    	}
    	y=vr[id][i].y;
    	ans[vr[id][i].id]+=solve(to[id],ip,x,y,0,cnt_ls)-1;
    

    

	}
    vis[id]=true;
    for(int ii=0;ii<adj[id].size();ii++)
    {
    	ip=adj[id][ii].id;
    	if(vec[ip].size()==0)
    	    continue;
	    pw[ip]=adj[id][ii].ch-'a';
	    construct(ip,1);
	    pc[to[ip]]=pw[ip];
		for(int jj=0;jj<vec[ip].size();jj++)
	    {
	    	int xx=vec[ip][jj];
	    	for(j=0;j<vr[xx].size();j++)
	    	{
	        	x=xx;
	        	y=vr[xx][j].y;
	        	int ipe=lca(x,y);
	        	cnt_ls=0;
	         	while(true)
	        	{
	         		ls[cnt_ls++]=y;
	        		if(ps[y]==ps[ipe])
	        		    break;
 		            y=pa[ps[y]];
 	        	}
 	        	y=vr[xx][j].y;
	        	u=cnt_ls;
	        	ju=false;
		    	int mf=get_path(to[x],to[ip],x,y,ipe,ju,u);
				if(mf==0)
	         	{
	         	

	         		

	    	    	int nx,nch,nu;
	        		bool nju;
	        		nju=ju;
	        		nu=u;
	         		nx=x;
	        		if(!ju||(x!=pom[y]))
	    	    	{
	    	        	if(!nju&&nx==ipe)
	    		        {
		    		       nju=true;
		    		       nx=pom[nx];
		    	        }
		    	        if(nju&&nx==pom[ls[nu-1]])
                        {
                        	nu--;
                        	nx=pom[ps[ls[nu-1]]]-1;
                        }
                        if(nju)
                        {
                        	nch=pd[lm[nx+1]];
                            nx++;
				     	}
				    	else
				    	{
                           nch=pd[nx];
                           nx=pa[nx];
					    }
					    if(nch==pw[ip])
    						ans[vr[xx][j].id]-=solve(to[ip],ipe,nx,y,nju,nu);
    					else if(pw[ip]<nch)
					    	ans[vr[xx][j].id]-=zz[ip];
	    	    	}
	    	    	ans[vr[xx][j].id]+=solve(to[id],ipe,x,y,ju,u);
				}
				else if(mf<0)
				    ans[vr[xx][j].id]+=zz[id]-zz[ip];
			}
	    }
	    cnt_list-=num_node-to[ip];
	    num_node=to[ip];
    }
    for(i=0;i<adj[id].size();i++)
    {
    	ip=adj[id][i].id;
    	if(!vis[ip])
    	{
	        get_size(ip,-1);
            mi=mod;
            choose_root(ip,-1,0,ch);
            if(mi<mod)
	       	    dfs(ch);
		}
    }
}
int main()
{
	int id1,id2,i,j,s,p,q,x,y;
	int ch;
	scanf("%d%d",&n,&num_q);




	for(i=0;i<=n;i++)
	{
		if(i==0)
		   ex[i]=1;
        else
           ex[i]=(int)((long long)ex[i-1]*(long long)base%mod);
	}
	for(i=0;i<400000;i++)
	   pk[i]=i;
	for(i=0;i<n-1;i++)
	{
	

	

	

		scanf("%d%d",&id1,&id2);
		ch=getchar();
		while(ch<'a'||ch>'z')
		   ch=getchar();
		id1--;
		id2--;
		now.id=id2;
		now.ch=ch;
		adj[id1].push_back(now);
		now.id=id1;
		adj[id2].push_back(now);
    }
    for(i=0;i<n;i++)
       ps[i]=i;
    prp(0,-1);
    gps(0);
    ha[0][0]=0;
    for(i=0;i<id0;i++)
    {
    	if(i+1<id0)
    	{
    	    ha[0][i+1]=(int)((long long)ha[0][i]*(long long)base%mod);
        	ha[0][i+1]=(ha[0][i+1]+pd[lm[i+1]]+1)%mod;
    	}
		ps[lm[i]]=ps[ps[lm[i]]];
    }
    ha[1][id0-1]=pd[lm[id0-1]]+1;
    for(i=id0-2;i>=0;i--)
    {
    	ha[1][i]=(int)((long long)ha[1][i+1]*(long long)base%mod);
    	ha[1][i]=(ha[1][i]+pd[lm[i]]+1)%mod;
    }
    

   

    for(i=0;i<num_q;i++)
    {
    

    

    

    

	  

	  

	  

    	scanf("%d%d",&x,&y);
    	x--;
    	y--;
    	nw.y=y;
    	nw.id=i;
    	vr[x].push_back(nw);
    }
    num_node=0;
    get_size(0,-1);
    mi=mod;
    choose_root(0,-1,0,ch);
    

    cnt_list=0;
    pw[ch]=-1;
    memset(ans,0,sizeof(ans));
   

	if(mi<mod)
       dfs(ch);
    for(i=0;i<num_q;i++)
       printf("%d\n",ans[i]);
	return 0;
}
