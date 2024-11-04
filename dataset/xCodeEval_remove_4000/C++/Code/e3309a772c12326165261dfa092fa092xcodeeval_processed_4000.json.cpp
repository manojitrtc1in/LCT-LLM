







using namespace std;
const double inf=1e18,eps=1e-9;
int n,m;
vector<int>adj[110000];
int pa[110000],ps[110000],dist[110000],cnt_list,pos[110000],deep[110000],cnt,list[110000];
double ans;
int lca(int id1,int id2)
{
	while(true)
	{
		if(deep[ps[id1]]>deep[ps[id2]])
			id1=pa[ps[id1]];
		else if(ps[id1]!=ps[id2])
		    id2=pa[ps[id2]];
        else
        {
        	if(pos[id1]<pos[id2])
        	   return id1;
     	    return id2;
        }
	}
}
struct query
{
	int v,u,id,ip;
	double c,t;
	bool operator <(const query &temp)const
    {
	    int i,j,s,p,q,ip,id1;
	    double t1=t,t2=temp.t;
	    if((pos[v]>pos[u]&&pos[temp.u]>pos[temp.v])||(pos[v]<pos[u]&&pos[temp.u]<pos[temp.v]))
    		return pos[v]>pos[u];
       	ip=lca(v,temp.v);
        id1=v;
        while(true)
        {
          	if(ps[id1]!=ps[ip])
           	{
	           	t1+=(pos[id1]-pos[ps[id1]]+1)/c;
	           	id1=pa[ps[id1]];
	        }
	        else
	        {
          		t1+=(pos[id1]-pos[ip])/c;
            	break;
           	}
         }
         id1=temp.v;
         while(true)
         {
           	if(ps[id1]!=ps[ip])
           	{
	           	t2+=(pos[id1]-pos[ps[id1]]+1)/temp.c;
	           	id1=pa[ps[id1]];
	        }
	        else
	        {
             	t2+=(pos[id1]-pos[ip])/temp.c;
           		break;
           	}
         }
        

        

         

         

         if(pos[v]>=pos[u])
            return t1>t2;
         return t1<t2;
	}
};
bool cmp(query a,query b)
{
	return a.t<b.t;
}
query qy[210000],nw,now,ls[210000];
int cnt_ls;
set<query>hs;
set<query>::iterator it,ht,lt,rt;
void dfs(int id1,int id2)
{
	int i,j,s,p,q,ip,ch;
	dist[id1]=0;
	pa[id1]=id2;
	for(i=0;i<adj[id1].size();i++)
	{
		ip=adj[id1][i];
		if(ip==id2)
		   continue;
        deep[ip]=deep[id1]+1;
        dfs(ip,id1);
        if(dist[id1]<dist[ip]+1)
        {
        	ch=i;
        	dist[id1]=dist[ip]+1;
        }
	}
	if(dist[id1]!=0)
	{
		

		  

    	ps[adj[id1][ch]]=id1;
		swap(adj[id1][ch],adj[id1][0]);
	}
}
void tdfs(int id1,int id2)
{
	int i,j,s,p,q,ip;
	list[cnt_list]=id1;
	pos[id1]=cnt_list++;
	for(i=0;i<adj[id1].size();i++)
	{
		ip=adj[id1][i];
		if(ip==id2)
		    continue;
        tdfs(ip,id1);
	}
}
double compute(int id1,int id2)
{
	int i,j,s,p,q,ip1,ip2,ip,im1,im2,u,v,dx;
	double t1,t2,nt1,nt2,A,B,rt,x;
	int ll[33],rr[33],cs;
	if(pos[qy[id2].v]>=pos[qy[id2].u])
	   swap(id1,id2);
    t1=qy[id1].t;
    t2=qy[id2].t;
    if(pos[qy[id2].v]<pos[qy[id2].u]&&pos[qy[id1].v]>=pos[qy[id1].u])
    {
    	ip=lca(qy[id1].v,qy[id2].u);
    	if(pos[ip]<max(pos[qy[id1].u],pos[qy[id2].v]))
    	   return -1;
 	    im1=qy[id1].v;
 	    im2=qy[id2].v;
 	    if(pos[qy[id1].u]>pos[qy[id2].v])
 	    {
    	 	im2=qy[id1].u;
    	 	while(true)
    	 	{
	 	    	if(ps[im2]!=ps[qy[id2].v])
	    	 	{
				 	t2+=(pos[im2]-pos[ps[im2]]+1)/qy[id2].c;
	    	 	    im2=pa[ps[im2]];
			    }
			    else
			    {
	    	 	    t2+=(pos[im2]-pos[qy[id2].v])/qy[id2].c;
				    break;
			    }
	 	    }
	 	    im2=qy[id1].u;
    	 }
    	 while(true)
    	 {
 	    	if(ps[im1]!=ps[ip])
   	        {
        	   	t1+=(pos[im1]-pos[ps[im1]]+1)/qy[id1].c;
        	   	im1=pa[ps[im1]];
            }
            else
            {
            	t1+=(pos[im1]-pos[ip])/qy[id1].c;
            	break;
            }
 	    }
 	    im1=ip;
 	    cs=0;
	    while(true)
 	    {
 	    	ll[cs]=im1;
	     	rr[cs++]=ps[im1];
    	 	if(ps[im1]!=ps[im2])
    	 	   im1=pa[ps[im1]];
 	 	    else
 	 	    {
    	 	 	rr[cs-1]=im2;
    	 	 	break;
    	    }
        }
        u=0;
        v=cs-1;
		while(u<v)
        {
        	nt1=t1+(pos[ll[u]]-pos[rr[u]]+1)/qy[id1].c;
        	nt2=t2+(pos[ll[v]]-pos[rr[v]]+1)/qy[id2].c;
        	if(u==v-1)
        	{
	        	if(nt1>=nt2-1.0/qy[id2].c)
	        	{
	        		if(nt1-1.0/qy[id1].c<=nt2)
	        		{
		        		t1=nt1-1./qy[id1].c;
		        		t2=nt2-1./qy[id2].c;
		        		dx=1;
		        		A=1.0/qy[id1].c+1.0/qy[id2].c;
                        B=t2-t1+dx/qy[id2].c;
                        x=B/A;
                        return t1+x/qy[id1].c;
		        	}
	        	}
	        }
            if(nt1<nt2)
            {
            	u++;
            	t1=nt1;	
            }
            else
            {
            	v--;
            	t2=nt2;
            }
        }
        nt1=t1+(pos[ll[u]]-pos[rr[u]])/qy[id1].c;
        nt2=t2+(pos[ll[u]]-pos[rr[u]])/qy[id1].c;
        dx=pos[ll[u]]-pos[rr[u]];
        A=1.0/qy[id1].c+1.0/qy[id2].c;
        B=t2-t1+dx/qy[id2].c;
        x=B/A;
        if(x>-eps&&x<dx+eps)
        {
        	rt=t1+x/qy[id1].c;
  	        return rt;
        }
        else
           return -1;
    }
    else if(pos[qy[id1].v]<=pos[qy[id1].u]&&pos[qy[id2].v]<=pos[qy[id2].u])
    {
    	

    	 

    	  

    	  ip=lca(qy[id1].u,qy[id2].u);
    	  if(pos[ip]<max(pos[qy[id1].v],pos[qy[id2].v]))
    	      return -1;
		  if(pos[qy[id1].v]>pos[qy[id2].v])
	      {
  		       im1=im2=qy[id1].v;
  		       while(true)
  		       {
       		  	  if(ps[im2]!=ps[qy[id2].v])
       		  	  {
  	  		       	  t2+=(pos[im2]-pos[ps[im2]]+1)/qy[id2].c;
  	  		          im2=pa[ps[im2]];
				  }
			      else
			      {
   				     t2+=(pos[im2]-pos[qy[id2].v])/qy[id2].c;
					 break;	  
   				  }
       		   }
      	  }
      	  else
      	  {
  	      	  im2=im1=qy[id2].v;
		      while(true)
  	      	  {
  	      	  	  if(ps[im1]!=ps[qy[id1].v])
  	      	  	  {
  	  	      	  	t1+=(pos[im1]-pos[ps[im1]]+1)/qy[id1].c;
  	  	      	  	im1=pa[ps[im1]];
  	  	      	  }
  	  	      	  else
  	  	      	  {
  	      	  	    	t1+=(pos[im1]-pos[qy[id1].v])/qy[id1].c;
  	      	  	     	break;
  	      	  	  }
  	      	  }
  	      	  im1=qy[id2].v;
  	      }
  	    

  	      

  	      cs=0;
  	      while(true)
  	      {
  	  	      	  ll[cs]=ip;
  	  	      	  rr[cs++]=ps[ip];
  	  	      	  if(ps[ip]!=ps[im1])
  	      	  	  	ip=pa[ps[ip]];
  	      	  	  else
  	      	  	  {
  	  	      	   	  rr[cs-1]=im1;
  	  	      	      break;
				  }
      	  }
      	  for(i=cs-1;i>=0;i--)
      	  {
  	      	  nt1=t1+(pos[ll[i]]-pos[rr[i]]+1)/qy[id1].c;
  	      	  nt2=t2+(pos[ll[i]]-pos[rr[i]]+1)/qy[id2].c;
  	      	  if(i==0)
  	      	  {
  	      	     nt1-=1.0/qy[id1].c;
  	      	     nt2-=1.0/qy[id2].c;
			  }
			  if((t1<=t2&&nt1>=nt2)||(t1>=t2&&nt1<=nt2))
  	      	  {
  	      	  	 

  	      	  	   

   	  	      	  	 

   	  	      	 

  	      	  	   A=(1.0/qy[id1].c-1.0/qy[id2].c);
  	      	  	   B=t2-t1;
     	  	       if(qy[id1].c==qy[id2].c)
     	  	          x=0;
  	  	           else
  	  	              x=B/A;
					  return t1+x/qy[id1].c;
  	      	  }
  	      	  t1=nt1;
  	      	  t2=nt2;
  	      }
  	      return -1;
    }
    else
    {
    	ip=lca(qy[id1].v,qy[id2].v);
    	if(pos[ip]<max(pos[qy[id1].u],pos[qy[id2].u]))
    	    return -1;
	    im1=qy[id1].v;
	    while(true)
	    {
    		if(ps[im1]!=ps[ip])
    		{
		    	t1+=(pos[im1]-pos[ps[im1]]+1)/qy[id1].c;
		    	im1=pa[ps[im1]];
		    }
		    else
		    {
    			t1+=(pos[im1]-pos[ip])/qy[id1].c;
    			break;
    		}
    	}
    	im2=qy[id2].v;
    	while(true)
    	{
	    	if(ps[im2]!=ps[ip])
	    	{
	    		t2+=(pos[im2]-pos[ps[im2]]+1)/qy[id2].c;
	    		im2=pa[ps[im2]];
	    	}
	    	else
	    	{
	    		t2+=(pos[im2]-pos[ip])/qy[id2].c;
	    		break;
	    	}
	    }
	    if(pos[qy[id1].u]>pos[qy[id2].u])
	        ip1=qy[id1].u;
        else
            ip1=qy[id2].u;
	    cs=0;
		while(true)
	    {
    		 ll[cs]=ip;
    		 rr[cs++]=ps[ip];
    		 if(ps[ip]!=ps[ip1])
 		    	ip=pa[ps[ip]];
 		     else
 		     {
     		 	rr[cs-1]=ip1;
     		 	break;
     		 }
    	}
    	for(i=0;i<cs;i++)
    	{
	    	nt1=t1+(pos[ll[i]]-pos[rr[i]]+1)/qy[id1].c;
	    	nt2=t2+(pos[ll[i]]-pos[rr[i]]+1)/qy[id2].c;
	    	if(i==cs-1)
	    	{
	    		nt1-=1./qy[id1].c;
	    		nt2-=1./qy[id2].c;
	    	}
	    	if((t1<=t2&&nt1>=nt2)||(t1>=t2&&nt1<=nt2))
	    	{
	    		   A=(1.0/qy[id1].c-1.0/qy[id2].c);
  	      	  	   B=t2-t1;
  	      	  	   if(qy[id1].c==qy[id2].c)
  	      	  	      x=0;
      	  	      else
				 	 x=B/A;
     	  	       return t1+x/qy[id1].c;
	    	}
	    	t1=nt1;
	    	t2=nt2;
	    }
	    return -1;
    }
}
int main()
{
	int i,j,s,p,q,id1,id2,id,u[2];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	   adj[i].clear();
    int vl;
    for(i=0;i<n-1;i++)
    {
    	scanf("%d%d",&id1,&id2);
    	if(i==0)
    	  vl=id1;
		id1--;
    	id2--;
    	adj[id1].push_back(id2);
    	adj[id2].push_back(id1);
    }
    for(i=0;i<m;i++)
    {
    	scanf("%lf%lf%d%d",&qy[i].t,&qy[i].c,&qy[i].v,&qy[i].u);
        qy[i].v--;
        qy[i].u--;
	}










	cnt_list=0;
    for(i=0;i<n;i++)
       ps[i]=i;
    deep[0]=0;
	dfs(0,-1);
	tdfs(0,-1);
	for(i=0;i<n;i++)
		ps[list[i]]=ps[ps[list[i]]];
	cnt=m;
	for(i=0;i<m;i++)
	{
		id=lca(qy[i].v,qy[i].u);
		qy[i].ip=i;
		if(qy[i].u!=id&&qy[i].v!=id)
		{
			id1=qy[i].v;
		    qy[cnt]=qy[i];
			qy[cnt].v=id;
		    qy[i].u=id;
		    qy[cnt].id=i;
		    while(true)
		    {
    			if(ps[id1]!=ps[id])
    			{
			    	qy[cnt].t+=(pos[id1]-pos[ps[id1]]+1)/qy[i].c;
			        id1=pa[ps[id1]];
				}
				else
				{
					qy[cnt].t+=(pos[id1]-pos[id])/qy[i].c;
				    break;
				}
    		}
    		cnt++;
		}
	}
	sort(qy,qy+cnt,cmp);
	for(i=0;i<cnt;i++)
	   qy[i].id=i;
	hs.clear();
	double ans=inf;
	double tmp;
	int times=0;
	for(i=0;i<cnt&&times<1e7;i++)
	{
		if(qy[i].t>=ans)
		    break;
		it=hs.upper_bound(qy[i]);
		cnt_ls=0;
		bool ok=false;
		for(ht=it;ht!=hs.end();ht++)
		{
			times++;
			tmp=compute(i,ht->id);
			if(tmp>=0&&ht->ip!=qy[i].ip)
			{
				if(ans>tmp)
				   ans=tmp;
				break;
			}
		}
		if(!ok)
		   cnt_ls=0;
		ht=it;
		ok=false;
		int rs=cnt_ls;
		if(ht!=hs.begin())
		{
		   ht--;
           for(;;ht--)
           {
           	times++;
          	  tmp=compute(i,ht->id);
        	  if(tmp>=0&&ht->ip!=qy[i].ip)
        	  {
	          	  if(ans>tmp)
	        	    ans=tmp;
					break;
	          }
	          if(ht==hs.begin())
	             break;
           }  
        }
        hs.insert(qy[i]);
	}
	if(ans<inf)
       printf("%.20f\n",ans);
	else
	   puts("-1");
	return 0;
}