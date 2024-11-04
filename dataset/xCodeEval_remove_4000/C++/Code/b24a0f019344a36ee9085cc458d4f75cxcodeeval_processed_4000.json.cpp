






using namespace std; 
int me;
struct xxx
{
	int x,flag,id;
	bool operator <(const xxx &temp)const
	{
		if(x==temp.x)
			return flag<temp.flag;
		return x<temp.x;
	}
};
xxx x[200000];
int cnt;
struct segment
{
	int l,r;
};
segment sg[110000];
int id1,arr[110000];
struct query
{
	int u,v,k,id;
};
query qy[110000],nw;
unsigned long long ex[110000];
struct pp
{
	int id;
	char ch;
};
vector<pp>adj[110000];
pp now;
string str[110000];
char tmp[110000];
int n,m,num_q,ans[110000],list[110000],cnt_list;
const int base=47,mod=1e9+9;
vector<int>vr[2][110000];
int us[2][110000],times,siz[110000],st[110000],en[110000],pos[110000],ps[110000],pa[20][110000];
bool vis[110000];
int trie[110000][26],num_node[2],vec[110000],num_vec,deep[110000],stk[110000],to[110000];
int tr[110000][26],vc[110000][26],sz[110000],bmw[110000],pw[110000],pf[110000];
int pc[110000],bs[2][110000],max_dist,maa[110000],mii[110000],pmd[110000];
vector<int>vw[3][110000];
unsigned long long ha[110000],hs[110000];
vector<int>ve[110000];
map<string,int>ke;
int per[110000],mi;
const int s_mod=1e5+7;
unsigned long long hash_[s_mod][20];
int vl[s_mod][20];
int nc[s_mod];
bool cmp(int id1,int id2)
{
	return hs[id1]<hs[id2];
}
bool cmp2(int id1,int id2)
{
	return ha[id1]<ha[id2];
}
bool cmp3(int id1,int id2)
{
	return st[id1]<st[id2];
}
unsigned long long qw(int l_id,int r_id)
{
	unsigned long long ret=hs[l_id]-hs[r_id]*ex[deep[l_id]-deep[r_id]]; 
	if(m==6)
		ret=(hs[l_id]+mod-hs[r_id]*ex[deep[l_id]-deep[r_id]]%mod)%mod;
	return ret;
}
void id0(int id,int pr,int pid,int dee)
{
	int i,j,s,p,q,ip,ie; 
	stk[dee]=id;
	to[id]=stk[min(1,dee)];
	for(j=0;j<2;j++)
	{
	    for(i=0;i<vr[j][id].size();i++)
    	{
	    	ip=vr[j][id][i];
			if(us[j][ip]!=times)
			{
	    		us[j][ip]=times;
			    if(j==0)
			       vec[num_vec++]=ip;
			}
		}
	} 
	pos[id]=pid;
	for(i=0;i<adj[id].size();i++)
	{
		ip=adj[id][i].id;
		if(ip==pr||vis[ip])
		    continue;
        int ch=adj[id][i].ch-'a';
        if(trie[pid][ch]==0)
        {
        	pc[num_node[0]]=ch;
        	hs[num_node[0]]=hs[pid]*base+ch+me;
        	if(m==6)
        	   hs[num_node[0]]%=mod;
            memset(trie[num_node[0]],0,sizeof(trie[num_node[0]]));
            pa[0][num_node[0]]=pid;
        	trie[pid][ch]=num_node[0]++;
		}
		ie=trie[pid][ch]; 
        deep[ie]=deep[pid]+1;
        max_dist=max(max_dist,deep[ie]);
        id0(ip,id,ie,dee+1);
	}
}
int lowbit(int x)
{
	return x&-x;
}
void dfs(int id)
{
	int i,j,s,p,q;
	st[id]=cnt_list++;
	for(i=0;i<26;i++)
	{
		if(trie[id][i]>0)
		   dfs(trie[id][i]);
	}
	en[id]=cnt_list-1;
}
void get_size(int id,int pr)
{
	int i,j,s,p,q,ip;
	siz[id]=1;
	for(i=0;i<adj[id].size();i++)
	{
		ip=adj[id][i].id;
		if(!vis[ip]&&ip!=pr)
		{
			get_size(ip,id);
			siz[id]+=siz[ip];
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
		if(ax<siz[ip])
			ax=siz[ip];
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
		choose_root(ip,id,now_sz+siz[id]-siz[ip],ch);	
	}
}
void solve(int id)
{
	int i,j,s,p,q,ip,ie,k;
	times++;
	vis[id]=true;
	num_node[0]=1;
	num_vec=0; 
	deep[0]=0; 
	hs[0]=0; 
	memset(trie[0],0,sizeof(trie[0]));
	pa[0][0]=-1;
	max_dist=0;
	id0(id,-1,0,0);


	for(k=1;(1<<k)<=max_dist;k++)
	{
		for(i=0;i<num_node[0];i++)
		{
			if(pa[k-1][i]>=0)
			   pa[k][i]=pa[k-1][pa[k-1][i]];
            else
               pa[k][i]=-1;
		}
	}
	cnt_list=0;
	dfs(0);
	int nn=0;
	for(i=0;i<num_vec;i++)
	{
		ip=vec[i]; 
		if(us[0][ip]==times&&us[1][ip]==times&&(qy[ip].u==id||qy[ip].v==id||to[qy[ip].u]!=to[qy[ip].v]))
		{
			int u,v;
			u=pos[qy[ip].u];
			v=pos[qy[ip].v];
			if(deep[u]+deep[v]+1>=str[qy[ip].k].size())
    			vec[nn++]=vec[i];
		}
	}
	num_vec=nn;  
 	int mk;
 	for(mk=0;(1<<mk)<=max_dist;mk++);
	mk--;
	for(q=0;q<2;q++)
	{
    	num_node[1]=1;
    	memset(tr[0],0,sizeof(tr[0]));
    	ve[0].clear();
    	ha[0]=0;
    	sz[0]=0;
	    times++;
	    pw[0]=-1;
		for(i=0;i<num_vec;i++)
    	{
    		ip=vec[i];
			if(us[0][qy[ip].k]!=times)
    		{
    			mii[qy[ip].k]=1e9;
    			maa[qy[ip].k]=-1e9;
    			vw[0][qy[ip].k].clear();
                if(q==0)
     	        {
		           vw[1][qy[ip].k].clear();
		           vw[2][qy[ip].k].clear();
    		    }
    		    if(str[qy[ip].k].size()>max_dist+1)
    		        goto orz;
		    	ie=0;
		    	int cs;
		    	if(q==0)
		    	{
		        	for(j=0;j<str[qy[ip].k].size();j++)
		        	{
			        	cs=str[qy[ip].k][j]-'a';
			        	if(vc[ie][str[qy[ip].k][j]-'a']!=times)
			        	{
			        		vc[ie][str[qy[ip].k][j]-'a']=times;
				         	ve[num_node[1]].clear();
				        	ha[num_node[1]]=(ha[ie]+ex[j]*(cs+me));
				        	if(m==6) 
				        	  ha[num_node[1]]%=mod;
				        	sz[num_node[1]]=0;
				        	pf[num_node[1]]=ie;
				        	pw[num_node[1]]=-1;
				        	tr[ie][cs]=num_node[1]++;
			        	} 
			        	ie=tr[ie][cs];
		        	}
		    	}
		    	else
		    	{
	    			for(j=str[qy[ip].k].size()-1;j>=0;j--)
	    			{
			        	cs=str[qy[ip].k][j]-'a';
			        	if(vc[ie][str[qy[ip].k][j]-'a']!=times)
			        	{
			        		vc[ie][str[qy[ip].k][j]-'a']=times;
				         	ve[num_node[1]].clear();
				        	ha[num_node[1]]=(ha[ie]+ex[str[qy[ip].k].size()-1-j]*(cs+me));
				        	if(m==6)
				        	   ha[num_node[1]]%=mod;
				        	sz[num_node[1]]=0;
				        	pf[num_node[1]]=ie;
				        	pw[num_node[1]]=-1;
							tr[ie][cs]=num_node[1]++;
			        	}
			        	ie=tr[ie][cs];
		        	}
	    		}
	    		pw[ie]=ie;
        		sz[ie]++;
	    		ve[ie].push_back(qy[ip].k);
	    		orz:
	    		us[0][qy[ip].k]=times;
    		} 
    		if(q==0)
    		{
    			mii[qy[ip].k]=min(mii[qy[ip].k],st[pos[qy[ip].u]]);
    			maa[qy[ip].k]=max(maa[qy[ip].k],st[pos[qy[ip].u]]);
		    	vw[2][qy[ip].k].push_back(ip);
    		}
    		else
    		{
		    	mii[qy[ip].k]=min(mii[qy[ip].k],st[pos[qy[ip].v]]);
    			maa[qy[ip].k]=max(maa[qy[ip].k],st[pos[qy[ip].v]]);
		    }
		}
    	for(i=1;i<num_node[1];i++)
    	{
    		if(pw[i]<0)
    	 	   pw[i]=pw[pf[i]];
    		sz[i]+=sz[i-1];
    	}
    	unsigned long long now_hash;
		int la;
		cnt_list=0;
		for(i=0;i<num_node[1];i++)
		{
			now_hash=ha[i];
		    la=now_hash%s_mod;
			list[cnt_list++]=la;
			vl[la][nc[la]]=i;
		    hash_[la][nc[la]++]=ha[i];
		}
    	for(i=0;i<num_node[0];i++)
     	{
    		int sc=0;
    		ip=i;
    		for(k=mk;k>=0;k--)
    		{
		    	if(pa[k][ip]>0)
		    	{
	    			now_hash=qw(i,pa[k][ip]);
	    			la=now_hash%s_mod;
	    			for(j=0;j<nc[la];j++)
   			        {
        			   	if(hash_[la][j]==now_hash)
        			   	    break;
        		    }
  			         if(j<nc[la])
					    ie=vl[la][j];
					 else
					    ie=-1;   
	    			if(ie>=0)
	    			   ip=pa[k][ip];
	    		}
    		}
   			now_hash=qw(i,ip);
           	la=now_hash%s_mod;
	    	for(j=0;j<nc[la];j++)
   	        {
       		   	if(hash_[la][j]==now_hash)
        	   	    break;
       	    }
  	        if(j<nc[la])
			    ie=vl[la][j];
	        else
			    ie=-1;   
           	if(ie>=0)
           	{
        		ie=pw[ie]; 
        		while(ie>0)
        		{ 
		        	for(j=0;j<ve[ie].size();j++)
		        	{
		        		if(maa[ve[ie][j]]>=st[i]&&mii[ve[ie][j]]<=en[i])
		            	   vw[0][ve[ie][j]].push_back(i);
		        	}
					ie=pw[pf[ie]];
		        }
           	}
    	}
    	for(i=0;i<cnt_list;i++)
	    	nc[list[i]]=0;
    	times++;

    	for(i=0;i<num_vec;i++)
    	{
    		ip=vec[i];
    		if(us[0][qy[ip].k]!=times)
    		{
               	xxx awp;
                cnt=0;
				for(j=0;j<vw[0][qy[ip].k].size();j++)
                {
                	awp.x=st[vw[0][qy[ip].k][j]];
                	awp.flag=-1;
                	x[cnt++]=awp;
                	awp.x=en[vw[0][qy[ip].k][j]];
                	awp.id=j;
                	awp.flag=1;
                	x[cnt++]=awp;
				}
                for(j=0;j<vw[2][qy[ip].k].size();j++)
                {
                	ie=vw[2][qy[ip].k][j];
                	if(q==0)
                    	awp.x=st[pos[qy[ie].u]];
                    else
                        awp.x=st[pos[qy[ie].v]];
                    awp.id=ie;
                    awp.flag=0;
                    x[cnt++]=awp;
                }
                sort(x,x+cnt);
                int now=0;
				for(j=0;j<cnt;j++)
                {
                	now-=x[j].flag;
                	if(x[j].flag==0)
	                	ans[x[j].id]+=now;
                }
                us[0][qy[ip].k]=times;
    		}
    	}
	}
	int la;
	cnt_list=0;
	for(i=0;i<num_node[0];i++)
	{
		la=hs[i]%s_mod;
        hash_[la][nc[la]]=hs[i];
        vl[la][nc[la]++]=i;
        list[cnt_list++]=la;
	}
	times++; 
    for(i=0;i<num_vec;i++)
	{
		ip=vec[i];
		if(us[0][qy[ip].k]!=times&&str[qy[ip].k].size()<=2*max_dist+1)
		{
			vw[0][qy[ip].k].clear();
			vw[1][qy[ip].k].clear();
			ie=qy[ip].k;
			unsigned long long now_hash=0;
			for(j=0;j<=str[ie].size()&&j<=max_dist+1;j++)
			{
				la=now_hash%s_mod;
				for(s=0;s<nc[la];s++)
				{
					if(hash_[la][s]==now_hash)
					    break;
				} 
				if(s<nc[la])
				   bs[0][j]=vl[la][s];
	            else
	               bs[0][j]=-1;
				if(j==str[ie].size())
				    break;
				now_hash=(now_hash+ex[j]*(str[ie][j]-'a'+me)); 
				if(m==6)
				   now_hash%=mod;
 		    }
 		    now_hash=0; 
 			la=now_hash%s_mod;
			for(s=0;s<nc[la];s++)
			{
				if(hash_[la][s]==now_hash)
				    break;
			}
			if(s<nc[la])
			{
			   bs[1][str[ie].size()]=vl[la][s];
			}
			else
	           bs[1][str[ie].size()]=-1;
			for(j=str[ie].size()-1;j>=0&&j>=((int)str[ie].size())-max_dist-1;j--)
 		    {
 		        now_hash=(now_hash+ex[str[ie].size()-1-j]*(str[ie][j]-'a'+me));
 		        if(m==6)
 		           now_hash%=mod;
 		       	la=now_hash%s_mod;
		    	for(s=0;s<nc[la];s++)
	    		{
	    			if(hash_[la][s]==now_hash)
	    			    break;
	    		}
		    	if(s<nc[la])
		    	   bs[1][j]=vl[la][s];
	            else
	               bs[1][j]=-1;
    	    }
    	    for(j=max(0,((int)str[ie].size())-max_dist-1);j<=str[ie].size()&&j<=max_dist+1;j++)
    	    {
    	    	if(bs[0][j]>=0&&bs[1][j]>=0)
    	    	{
	    	    	vw[0][qy[ip].k].push_back(bs[0][j]);
	    	    	vw[1][qy[ip].k].push_back(bs[1][j]);
	    	    }
    	    }
    	    us[0][qy[ip].k]=times;
		}
	}
	for(i=0;i<cnt_list;i++)
	    nc[list[i]]=0;
	times++;
	for(i=0;i<=num_node[0];i++)
	    arr[i]=0;
	for(i=0;i<num_vec;i++)
	{
		ip=vec[i];
		if(us[0][qy[ip].k]!=times)
		{ 
			cnt=0;
			for(j=0;j<vw[0][qy[ip].k].size();j++)
			{
				x[cnt].x=st[vw[0][qy[ip].k][j]];
				x[cnt].flag=-1;
				x[cnt++].id=j;
				x[cnt].x=en[vw[0][qy[ip].k][j]];
				x[cnt].flag=1;
				x[cnt++].id=j;
			}
			for(j=0;j<vw[2][qy[ip].k].size();j++)
			{
				ie=vw[2][qy[ip].k][j];
				x[cnt].x=st[pos[qy[ie].u]];
				x[cnt].flag=0;
				x[cnt++].id=ie;
			}
			sort(x,x+cnt);
			for(j=0;j<cnt;j++)
			{
				if(x[j].flag!=0)
				{
					ie=x[j].id;
					for(s=st[vw[1][qy[ip].k][ie]]+1;s<=num_node[0];s+=lowbit(s))
					    arr[s]-=x[j].flag;
	                for(s=en[vw[1][qy[ip].k][ie]]+2;s<=num_node[0];s+=lowbit(s))
	                    arr[s]+=x[j].flag;
				}
				else
				{
					ie=x[j].id;
					for(s=st[pos[qy[ie].v]]+1;s>0;s-=lowbit(s))
					     ans[ie]+=arr[s];
				}
			}
			us[0][qy[ip].k]=times;
			for(j=0;j<cnt;j++)
			{
				if(x[j].flag!=0)
				{
					ie=x[j].id;
					for(s=st[vw[1][qy[ip].k][ie]]+1;s<=num_node[0];s+=lowbit(s))
					    arr[s]=0;
	                for(s=en[vw[1][qy[ip].k][ie]]+2;s<=num_node[0];s+=lowbit(s))
	                    arr[s]=0;
				}
			}
		}
	}
	for(i=0;i<adj[id].size();i++)
	{
		ip=adj[id][i].id;
		if(!vis[ip])
		{
			int root;
			cnt_list=0;
			get_size(ip,-1);
			mi=1e9+9;
		    choose_root(ip,-1,0,root);
			solve(root);
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&num_q);
	int i,j,s,p,q,u,v;
	char ch;
	me=rand()%10000+1;
	for(i=0;i<=100000;i++)
	{
		if(i==0)
		   ex[i]=1;
        else
        {
           ex[i]=ex[i-1]*base;
        }
        if(m==6)
           ex[i]%=mod;
	}
	for(i=0;i<n;i++)
	   adj[i].clear();
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		u--;
		v--;
		ch=getchar();
		while(ch<'a'||ch>'z')
		    ch=getchar();
        now.id=v;
        now.ch=ch;
        adj[u].push_back(now);
        now.id=u;
        adj[v].push_back(now);
	}
	ke.clear();
	getchar();
	for(i=0;i<m;i++)
	{
		gets(tmp);
		str[i]=tmp;
		ke[tmp]=i;
	}
    for(i=0;i<m;i++)
        pmd[i]=ke[str[i]];
	for(i=0;i<n;i++)
	{
		vr[0][i].clear();
	    vr[1][i].clear();
	}
	for(i=0;i<num_q;i++)
	{
		scanf("%d%d%d",&qy[i].u,&qy[i].v,&qy[i].k);
		qy[i].u--;
		qy[i].v--;
		qy[i].k--;
		qy[i].k=pmd[qy[i].k];
		qy[i].id=i;
		vr[0][qy[i].u].push_back(i);
		vr[1][qy[i].v].push_back(i);
	}
	cnt_list=0;
	get_size(0,-1);
	memset(ans,0,sizeof(ans));
	int root;
	mi=1e9+9;
	choose_root(0,-1,0,root);
	solve(root);
	for(i=0;i<num_q;i++)
	   printf("%d\n",ans[i]);
	return 0;
}