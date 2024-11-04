#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<assert.h>
#include<vector>
#include<algorithm>
using namespace std;
const int bound=5;
struct qq
{
	int l,r,id;
};
qq qr[202000],bo[5000002];
int cmft,pos[220000];
vector<int>ve[bound*bound];
int lg[210000],idx[210000],lcp[210000],len,n,fk[19][210000];
int num_q;
long long ans[220000];
struct node
{
	int l,r,cnt;
};
node tree[4200000];
int lf[220000],ce;
int ll[4200000],rr[4200000];
int num_node,list[220000],cnt_list,ch;
const int maxn=210000;
vector<int>vec[220000],vr[1<<19];
int uu[1<<19];
int lz[220000],times;
vector<long long>sum[1<<19];
const int N = 200610;
char str[N];
int sa[N],X[N],Y[N],b[N],a[N],h[N],r[N],rnk[N];
bool cmp(int id1,int id2)
{
	return rnk[id1]<rnk[id2];
}
bool comp(int *r,int a,int b,int le)
{
		return r[a] == r[b] && r[a+le] == r[b+le];
}
void sort(int *Rank,int *Id,int n,int m)
{
		std::fill(b,b+m,0);
		for(int i = n-1; i >= 0; i--) b[Rank[i]]++;
		for(int i = 1; i < m; i++) b[i] += b[i-1];
		for(int i = n-1; i >= 0; i--) sa[--b[Rank[Id[i]]]] = Id[i];
}
void suffix(int n,int m=500)
{
		int *Rank = X, *Id = Y, p = 1;
		for(int i = 0; i < n; i++) Rank[i] = a[i], Id[i] = i;
		sort(Rank,Id,n,m);
		for(int j = 1; p < n; j <<= 1){
				p = 0;
				for(int i = n-j; i < n; i++) Id[p++] = i;
				for(int i = 0; i < n; i++) if(sa[i] >= j) Id[p++] = sa[i] - j;
				sort(Rank,Id,n,p);
				std::swap(Rank,Id);
				Rank[sa[0]] = 0, p = 1;
				for(int i = 1; i < n; i++)
						Rank[sa[i]] = comp(Id,sa[i-1],sa[i],j) ? p-1 : p++;
				m = p;
		}
}
void LCP(char *str) 
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
int build(int left,int right)
{
	int mid=(left+right)>>1,rt=num_node++;
	tree[rt].l=left;
	tree[rt].r=right;


	tree[rt].cnt=0;
	if(left==right)
	   return rt;
    ll[rt]=build(left,mid);
    rr[rt]=build(mid+1,right);
    return rt;
}
int insert(int id,int pos)
{
	int rt=num_node++,l=ll[id],r=rr[id];
	tree[rt]=tree[id];
	tree[rt].cnt++;
	if(tree[id].l==tree[id].r)
	   return rt;
    if(tree[l].r<pos)
    {
    	ll[rt]=ll[id];
    	rr[rt]=insert(rr[id],pos);
    }
    else
    {
    	ll[rt]=insert(ll[id],pos);
    	rr[rt]=rr[id];
    }
    return rt;
}
int find_id(int ly,int ry,int lx,int rx,int flag)
{
	

     if(tree[lx].l>ry||tree[lx].r<ly)
         return -1;
     if(tree[rx].cnt-tree[lx].cnt==0)
         return -1;
     if(tree[lx].l==tree[lx].r)
         return tree[lx].l;
	 int res;
	 if(flag==0)
        res=find_id(ly,ry,ll[lx],ll[rx],flag);
     else 
        res=find_id(ly,ry,rr[lx],rr[rx],flag);
	 if(res<0)
     { 
     	if(flag==0)
          res=find_id(ly,ry,rr[lx],rr[rx],flag);
        else
          res=find_id(ly,ry,ll[lx],ll[rx],flag);
     }
     return res;
}
int rmq(int id1,int id2)
{
	int ip1,ip2,le,ri,id;
	if(id1==id2)
	   return n-id1+1;
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
int fin(int li,int ri,int pe)
{
	int ic,id,p_ak,ip,low,high,mid;
	ic=li+1;
 	id=rnk[li];
    int ans=ri-pe+1;
	int lk=id+1,rk=n-1,lm,rm;
	lm=ic;
	rm=ri-ans;
	int pre=-1,plen;
    p_ak=ri+1;
	while(lk<n&&lm<=rm)
	{
        ip=find_id(lk,n-1,idx[lm],idx[rm+1],0);
	    if(ip<0)
	      break;
	    len=rmq(li,sa[ip]);
	    if(len+sa[ip]>ri)
		{
		   	   int lp;
			   if(p_ak<=ri)
			   {
   				   lp=(p_ak-sa[ip]);
   				   low=0;
				   high=(sa[ip]-lm)/lp;
   				   while(low<=high)
   				   {
   				   	   mid=(low+high)/2;
   				   	   int nip=sa[ip]-mid*lp;
   				   	   len=rmq(li,nip);
   				   	   if(len+nip>ri)
   				   	       low=mid+1;
			   	       else
			   	           high=mid-1;
   				   }
   			   }
   			   else
   			       high=lp=0;
			   ans=max(ans,ri-sa[ip]+high*lp+1);
		       if(p_ak<=ri) 
				 break;
			   len=rmq(li,sa[ip]);
		       lm=max(lm,ri-len+1);
		       rm=min(rm,sa[ip]-high*lp-1);
   			   p_ak=sa[ip]-high*lp;
		   }
		   else
		   {
		   	  int nk,lp;
 	 		  if(pre>=0)
 	    	  {
  	   			   lp=plen-(pre-sa[ip]);
  	   			   if(lp<plen)
			          lm=max(lm,min(sa[ip]+len,pre)-lp+1);
   	   		  }
   	   		  if(pre<sa[ip]+len)
		   	  {
			     pre=sa[ip]+len;
                 plen=len;
			  }
		      lm=max(lm,max(ri-len+1,sa[ip]+1)); 
		   }
		   lk=ip+1;
        }
	   	id=rnk[li];
	   	ic=li+1;
	   	lk=0;
	   	rk=id-1;
	   	lm=ic;
	   	rm=ri-ans;
	    pre=-1;
	    p_ak=ri+1;
	   	while(rk>=0&&lm<=rm)
	   	{
	   		ip=find_id(0,rk,idx[lm],idx[rm+1],1);
	   		if(ip<0)
	   		    break;
	   		len=rmq(li,sa[ip]);
	   		if(len+sa[ip]>ri)
	   		{
		   	    int lp;
			    if(p_ak<=ri)
			    {
   				   lp=(p_ak-sa[ip]);
   				   low=0;
				   high=(sa[ip]-lm)/lp,mid;
   				   while(low<=high)
   				   {
   				   	   mid=(low+high)/2;
   				   	   int nip=sa[ip]-mid*lp;
   				   	   len=rmq(li,nip);
   				   	   if(len+nip>ri)
   				   	       low=mid+1;
			   	       else
			   	           high=mid-1;
   				   }
   			    }
   			    else
   			        high=lp=0;
		        ans=max(ans,ri-sa[ip]+high*lp+1);
		        if(p_ak<=ri)
		        	break;
				len=rmq(li,sa[ip]);
		        lm=max(lm,ri-len+1);
		        rm=min(rm,sa[ip]-high*lp-1);
   			    p_ak=sa[ip]-high*lp;
            } 
		   	else
		   	{
		   		int nk,lp;
 	    	    if(pre>=0)
		   	   	{
  	 			    lp=plen-(pre-sa[ip]);
    	   			if(lp<plen)
			   	         lm=max(lm,min(sa[ip]+len,pre)-lp+1);
    	   		}
 	   		    if(pre<sa[ip]+len)
		   	    {
			        pre=sa[ip]+len;
                    plen=len;
			    }
		      	lm=max(lm,max(ri-len+1,sa[ip]+1));
		        
		    }
			 rk=ip-1;
	   	}
	return ans;
}
void bx(int mf,int left,int right,int id)
{
	int x,i,j,s,p,q,mid=(left+right)>>1,l=2*id+1,r=2*id+2;
	if(mf==0)
	{
		if(id==0)
	        vr[id].clear();
       uu[id]=0;
	}
	if(id==0&&mf==0)
	{
		for(i=left;i<=right;i++)
			vr[id].push_back(i);
		sort(vr[id].begin(),vr[id].end(),cmp);
	}
	if(mf==0)
	{ 
    	sum[id].resize(vr[id].size()+1);
    	sum[id][0]=0;
    	for(i=0;i<vr[id].size();i++)
    	{
    		if(i+1>=vr[id].size())
    		   x=0;
    		else
    		   x=rmq(vr[id][i],vr[id][i+1]);
    		for(j=i-1;j>=0;j=lz[j])
    		{
    			if(rmq(vr[id][j],vr[id][j+1])<x)
    				break;
    		}
    		lz[i]=j;
    		sum[id][i+1]=sum[id][lz[i]+1]+1LL*x*(i-lz[i]); 
    	} 
    	if(left!=right)
    	{
    	    vr[l].clear();
			vr[r].clear();	
    	}
    	for(i=0;i<vr[id].size()&&left!=right;i++)
    	{
   	    	if(vr[id][i]<=mid)  
	    		vr[l].push_back(vr[id][i]);
	    	else
	    	    vr[r].push_back(vr[id][i]);
    	}
    }
    else
    {
    

    	uu[id]=vr[id].size()-1;
    	sum[id][vr[id].size()]=0;
    	for(i=vr[id].size()-2;i>=0;i--)
    	{
     	    x=rmq(vr[id][i],vr[id][i+1]);
    		for(j=i+1;j+1<vr[id].size();j=lz[j])
    		{
    			if(rmq(vr[id][j],vr[id][j+1])<x)
    			   break;
			}
			lz[i]=j;
			sum[id][i+1]=sum[id][lz[i]+1]+1LL*x*(lz[i]-i);		
		}
	}
	if(left==right)
	   return;
	bx(mf,left,mid,l);
	bx(mf,mid+1,right,r);
}
void cx(int mf,int left,int right,int T,int mod,int id)
{
	int x,i,j,s,p,q,mid=(left+right)>>1,l=2*id+1,r=2*id+2;
	if(mf==0) 
	{
		if(id==0)
	       vr[id].clear();
        uu[id]=0;
	}
	if(id==0&&mf==0)
	{
		for(i=left;i<=right;i++)
			vr[id].push_back(lf[i]);
		sort(vr[id].begin(),vr[id].end(),cmp);
	}
	if(mf==0)
	{ 
    	sum[id].resize(vr[id].size()+1);
    	sum[id][0]=0;
    	for(i=0;i<vr[id].size();i++)
    	{
    		if(i+1>=vr[id].size())
    		   x=0;
    		else
    		   x=rmq(vr[id][i],vr[id][i+1]);
    		for(j=i-1;j>=0;j=lz[j])
    		{
    			if(rmq(vr[id][j],vr[id][j+1])<x)
    				break;
    		}
    		lz[i]=j;
    		sum[id][i+1]=sum[id][lz[i]+1]+1LL*x*(i-lz[i]); 
    	} 
    	if(left!=right)
    	{
    		vr[l].clear();
    		vr[r].clear();
    	}
    	for(i=0;i<vr[id].size()&&left!=right;i++)
    	{
   	    	if(pos[vr[id][i]]<=mid)  
	    		vr[l].push_back(vr[id][i]);
	    	else
	    	    vr[r].push_back(vr[id][i]);
    	}
    }
    else
    {
    

    

    	uu[id]=vr[id].size()-1;
    	sum[id][vr[id].size()]=0;
    	for(i=vr[id].size()-2;i>=0;i--)
    	{
     	    x=rmq(vr[id][i],vr[id][i+1]);
    		for(j=i+1;j+1<vr[id].size();j=lz[j])
    		{
    			if(rmq(vr[id][j],vr[id][j+1])<x)
    			   break;
			}
			lz[i]=j;
			sum[id][i+1]=sum[id][lz[i]+1]+1LL*x*(lz[i]-i);		
		}
	}
	if(left==right)
	   return;
	cx(mf,left,mid,T,mod,l);
	cx(mf,mid+1,right,T,mod,r);
}
void vx(int left,int right,int le,int re,int id)
{
	int l=2*id+1,r=2*id+2,mid=(left+right)>>1;
	if(left>=le&&right<=re)
	{
		list[cnt_list++]=id;
		return;
	}
	if(re<left||right<le)
	    return;
	vx(left,mid,le,re,l);
	vx(mid+1,right,le,re,r);
}
int main(){

    int i,j,s,p,q,k,li,ri,id,ip,len,ic,low,high,mid;
    int times,p_ak;
   

 

    scanf("%s%d",str,&num_q);
   

   

   

    

    n=strlen(str);
  

  

   

    

	lg[1]=0;
    for(i=2;i<=n;i++)
       lg[i]=lg[i/2]+1;
    for(i=0;i<n;i++)
    	a[i]=str[i];

   	a[n]=0;
    suffix(n+1);
   

    

    for(i=1;i<=n;i++) 
       sa[i-1]=sa[i];
   

    

    for(i=0;i<n;i++)
       rnk[sa[i]]=i;
    LCP(str);
    for(i=0;i<n;i++)
       fk[0][i]=lcp[i];
    for(k=1;(1<<k)<=n;k++)
       for(i=0;i+(1<<k)<=n;i++)
    	fk[k][i]=min(fk[k-1][i],fk[k-1][i+(1<<(k-1))]);
   	num_node=0;
   	idx[0]=build(0,n-1);
   	for(i=0;i<n;i++)
        idx[i+1]=insert(idx[i],rnk[i]); 
    cmft=0;
	for(q=0;q<num_q;q++)
   	{
   	  

   	

	    scanf("%d%d",&li,&ri);
		li--;
	   	ri--;
	   	qr[q].l=li;
	   	qr[q].r=ri;
	   	

	   	ans[q]=ri-li+1;
	   	bool fir=true;
	   

	    times=0;
	    int up=0,pe=ri+1;
	   	while(li<=ri)
	   	{
		     int T,tu,cnt;


			 if(up==0)
		       up=fin(li,ri,pe);
			 T=ri-li+1-up;
			 

		     if(T==ri-li+1)
		        break;
		     if(T>=bound||fir)
		     {
		       bool have=false;
		       times++;
		       int dt=T;
		       if(!fir)
	   	       {
	   	       	  cnt=max(1,(ri-li+1)/T-1);
	   	       	  for(i=1;i<=cnt;i++)
	   	       	     ans[q]-=rmq(qr[q].l,li+i*T);
	   	       	  up=0;
		       }
		       else
		       {
			       cnt=max(1,(ri-li+1)/T-1);  
	   	           up=0;
			   }
	   	       pe=ri+1;
	   	       if(fir)
	   	       {
		          tu=rmq(qr[q].l,li+T);
	              ans[q]-=(2LL*tu-(cnt-1)*dt)*cnt/2;
		       }
			   ans[q]+=(2LL*(ri-li)-T-cnt*T+2)*cnt/2;
	   	    }
	   	    else
	   	    {
	   	    

	   	    	cnt=max(1,(ri-li+1)/T-1);
	   	        bo[cmft].l=li+T;
	   	        bo[cmft].r=li+cnt*T;
	   	        bo[cmft++].id=q;
	   	      

	   	        ve[T*bound+li%T].push_back(cmft-1);
			    up=0;
		    	ans[q]+=(2LL*(ri-li)-T-cnt*T+2)*cnt/2;
		       

			}
			li+=cnt*T;
	   	    fir=false;
    	}
    

	  

    } 
   

   

    for(i=0;i<bound*bound;i++)
    {
    	if(ve[i].size())
    	{
    		ce=0;
    		int le=1e9,re=-1e9;
    		for(j=0;j<ve[i].size();j++)
    		{
    			id=ve[i][j];
    			le=min(le,bo[id].l);
    			re=max(re,bo[id].r);
    		}
    	

    		for(j=le;j<=re;j+=i/bound)
    		{
    			pos[j]=ce;
    		    lf[ce++]=j;
    	    }
    	    cx(0,0,ce-1,i/bound,i%bound,0);
			for(j=0;j<ve[i].size();j++)
			{
				id=ve[i][j];
				int ie=bo[id].id;
				vec[rnk[qr[ie].l]].push_back(id);
			}
			for(j=0;j<n;j++)
			{
				for(p=0;p<vec[j].size();p++)
				{
					id=vec[j][p];
					cnt_list=0;
					vx(0,ce-1,pos[bo[id].l],pos[bo[id].r],0);
				    for(int ss=0;ss<cnt_list;ss++)
				    {
				    	s=list[ss];
			     	    while(uu[s]<vr[s].size()&&rnk[vr[s][uu[s]]]<j)
    		         	   uu[s]++;
			            int low,high,mid,x;
		          	    low=0;
          			    high=uu[s]-1;
			            if(uu[s])
			                x=rmq(vr[s][uu[s]-1],sa[j]);
			            else
			                x=0;
			            if(x==0)
			               continue;
		         	    while(low<=high)
			            {
			   	           mid=(low+high)>>1;
			   	           if(rmq(vr[s][mid],sa[j])==x)
			   	              high=mid-1;
          			   	    else
			        	       low=mid+1;
			            }
			            ans[bo[id].id]-=sum[s][low]+1LL*(uu[s]-low)*x;	
				    }
				}
			}
			

			cx(1,0,ce-1,i/bound,i%bound,0);
			for(j=n-1;j>=0;j--)
			{
				for(p=0;p<vec[j].size();p++)
				{
					id=vec[j][p];
					cnt_list=0;
					vx(0,ce-1,pos[bo[id].l],pos[bo[id].r],0);
				    for(int ss=0;ss<cnt_list;ss++)
				    {
				    	s=list[ss]; 
				    	

    		            while(uu[s]>=0&&rnk[vr[s][uu[s]]]>j)
    		          	   uu[s]--;
		           	    int low,high,mid,x; 
           			    low=uu[s]+1;
		         	    high=vr[s].size()-1;
			            if(uu[s]+1<vr[s].size())
			               x=rmq(vr[s][uu[s]+1],sa[j]);
			            else
			               x=0;
			            if(x==0)
			                continue;
		        	    while(low<=high)
			            {
			   	            mid=(low+high)>>1;
			   	            if(rmq(vr[s][mid],sa[j])==x)
			   	                low=mid+1;
			   	            else
			   	                high=mid-1;
			             }
		                 ans[bo[id].id]-=sum[s][low]+1LL*(low-uu[s]-1)*x;
				    }
				}
			}
			for(j=0;j<ve[i].size();j++)
			{
				id=ve[i][j];
				int ie=bo[id].id;
				vec[rnk[qr[ie].l]].clear();
			}
		}
    }
  

   

    for(i=0;i<n;i++)
       vec[i].clear();
    for(i=0;i<num_q;i++)
       vec[rnk[qr[i].l]].push_back(i);
    bx(0,0,n-1,0);
    for(i=0;i<n;i++)
      for(j=0;j<vec[i].size();j++)
      {
     	  li=qr[vec[i][j]].l;
    	  ri=qr[vec[i][j]].r;
    	  cnt_list=0;
    	  vx(0,n-1,li,ri,0);
    	  for(int ss=0;ss<cnt_list;ss++)
    	  {
    	 	   s=list[ss];
    		   while(uu[s]<vr[s].size()&&rnk[vr[s][uu[s]]]<i)
    		  	   uu[s]++;
			   int low,high,mid,x;
			   low=0;
			   high=uu[s]-1;
			   if(uu[s])
			      x=rmq(vr[s][uu[s]-1],sa[i]);
			    else
			      x=0;
			    if(x==0)
			       continue;
			   while(low<=high)
			   {
			   	    mid=(low+high)>>1;
			   	    if(rmq(vr[s][mid],sa[i])==x)
			   	        high=mid-1;
			   	    else
			   	       low=mid+1;
			   }
			   ans[vec[i][j]]+=sum[s][low]+1LL*(uu[s]-low)*x;
    	  }
	} 
	bx(1,0,n-1,0);
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<vec[i].size();j++)
		{
		

			li=qr[vec[i][j]].l;
			ri=qr[vec[i][j]].r;
			cnt_list=0;
			vx(0,n-1,li,ri,0);
	        for(int ss=0;ss<cnt_list;ss++)
    	    {
    	 	    s=list[ss];
    	 	   

    	 	   

    		    while(uu[s]>=0&&rnk[vr[s][uu[s]]]>i)
    		  	   uu[s]--;
			   int low,high,mid,x;
			   low=uu[s]+1;
			   high=vr[s].size()-1;
			   if(uu[s]+1<vr[s].size())
			      x=rmq(vr[s][uu[s]+1],sa[i]);
			    else
			      x=0;
			   if(x==0)
			       continue;
			   while(low<=high)
			   {
			   	    mid=(low+high)>>1;
			   	    if(rmq(vr[s][mid],sa[i])==x)
			   	        low=mid+1;
			   	    else
			   	        high=mid-1;
			   }
			 

			  

		       ans[vec[i][j]]+=sum[s][low]+1LL*(low-uu[s]-1)*x;
    	  }	
	   }
	}
	for(i=0;i<num_q;i++)
	   printf("%lld\n",ans[i]);
    return 0;
}
