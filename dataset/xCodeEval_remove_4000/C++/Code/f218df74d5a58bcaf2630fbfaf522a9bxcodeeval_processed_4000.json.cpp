







using namespace std;
struct pp
{
   int id,dist;
};
vector<pp>sq_list[330100];
int n,m,bound,nxt[331001],pre[331001],lazy[331001],num_bl,min_dist[331001],max_dist[331001];
vector<int>adj[110000];
pp list[220000],now;
int cnt_list,cnt_ts,dist[110000],st[110000],en[110000],inf=1000000000,i1,i2,vis[110000],cnt_vis;

int num_out,emp_list[110000],cnt_emp;

void dfs(int id)
{
     int ip,i,j,s,p,q,siz=adj[id].size();
     list[cnt_list++].id=id;
     for(i=0;i<siz;i++)
     {
         ip=adj[id][i];
         dist[ip]=dist[id]+1;
         dfs(ip);
         list[cnt_list++].id=id;
     }
}
int get_pos(int bl,int u,bool ff)
{
    int i,siz=sq_list[bl].size();
    if(ff)
    {
        for(i=siz-1;i>=0;i--)
        {
            if(sq_list[bl][i].id==u)
                return i;
        }
    }
    else
    {
        for(i=0;i<siz;i++)
        {
            if(sq_list[bl][i].id==u)
                return i;
        }
    }
}
int get_size(int bl,int u,bool ff)
{
    int res,i,j,s,p,q,siz=sq_list[bl].size();
    i=get_pos(bl,u,ff);
    
  

    

    
    res=i;
    
   

    
    bl=pre[bl];
    while(bl>=0)
    {
       

       

        res+=sq_list[bl].size();
        bl=pre[bl];
    }
   

    return res;
}
int query_dist(int u,int v)
{
    int i,j,s,p,q,id1,id2,id=-1,from,to,res,in_dist=inf,ft=0;
    id1=en[u];

    id2=st[v];

   

  

   

    if(get_size(id1,u,1)>get_size(id2,v,0))
    {
           id1=en[v];
           id2=st[u];
           if(get_size(id1,v,1)>get_size(id2,u,0))
                id=0;
         

         

         ft=1;
    }
    if(id>=0)
    {        
        i=get_pos(en[u],u,1);
        res=lazy[en[u]]+sq_list[en[u]][i].dist;
        i=get_pos(en[v],v,1);
        res-=(lazy[en[v]]+sq_list[en[v]][i].dist);
        return abs(res);
    }
    
    
    if(ft==1)

    {
     

        from=get_pos(id1,v,1);
        to=get_pos(id2,u,0);
        
       

    }
    else
    {
        from=get_pos(id1,u,1);
        to=get_pos(id2,v,0);
    }
    res=lazy[id1]+sq_list[id1][from].dist+lazy[id2]+sq_list[id2][to].dist;
  

    
    if(id1==id2)
    {
        

        for(i=from;i<=to;i++)
        {        
             if(in_dist>lazy[id1]+sq_list[id1][i].dist)
                in_dist=lazy[id1]+sq_list[id1][i].dist;
        }
    }
    else
    {
        for(i=from;i<sq_list[id1].size();i++)
        {
             
            

            

              

               

            

                                             
             if(in_dist>lazy[id1]+sq_list[id1][i].dist) 
             {
                in_dist=lazy[id1]+sq_list[id1][i].dist;
               

             }
        }
        for(i=0;i<=to;i++)
        {
        

         

           

             

             

             
             if(in_dist>lazy[id2]+sq_list[id2][i].dist)
             {
                 in_dist=lazy[id2]+sq_list[id2][i].dist;
                 
                

             }
        }
        id1=nxt[id1];
        
      

        
        while(id1!=id2)
        {
          

            

            
            if(in_dist>lazy[id1]+min_dist[id1])
               in_dist=lazy[id1]+min_dist[id1];
            id1=nxt[id1];
        }
    }
    

    

    return res-2*in_dist;
}
void update(int id)
{
     int i,j,s,p,q,siz=sq_list[id].size();
     max_dist[id]=-1;
     min_dist[id]=inf;
     for(i=0;i<siz;i++)
     {
         if(lazy[id]!=0)
            sq_list[id][i].dist+=lazy[id];
         max_dist[id]=max(max_dist[id],sq_list[id][i].dist);
         min_dist[id]=min(min_dist[id],sq_list[id][i].dist);
     }
     lazy[id]=0;
}
int merge(int id1,int id2)
{
     int res,id,i,j,s,p,q,siz=sq_list[id2].size();
    

     

    

    

    update(id1);
    update(id2);
     for(i=0;i<siz;i++)
     {
         if((sq_list[id1].size()>=bound&&siz-i>=bound)||(sq_list[id1].size()>=bound&&sq_list[id1].size()+siz-i>=2*bound))
              break;
         id=sq_list[id2][i].id;
         if(st[id]==id2)
         {
            st[id]=id1;
          

           

         }
         if(en[id]==id2)
            en[id]=id1;
         sq_list[id1].push_back(sq_list[id2][i]);
     }
     for(j=i;j<siz;j++)
         sq_list[id2][j-i]=sq_list[id2][j];
     while(sq_list[id2].size()>siz-i)
         sq_list[id2].pop_back();
     

     if(sq_list[id2].size()==0)
     {
        pre[id2]=-1;
        id=nxt[id2];
        nxt[id2]=-1;
        nxt[id1]=id;
        if(id>=0)
          pre[id]=id1;
        res=id1;
        
        emp_list[cnt_emp++]=id2;
     }
     else
     {
         siz=sq_list[id2].size();
         for(i=0;i<siz;i++)
         {
             id=sq_list[id2][i].id;
             if(en[id]==id1)
                en[id]=id2;
         }
         nxt[id1]=id2;
         pre[id2]=id1;
         update(id2);
         res=id2;
     }
     update(id1);
     return res;
}
void split(int id1,int ip1,int id2,int ip2)
{
     int up,i,j,s,p,q,id,nsiz,siz=sq_list[id1].size();
         if(id1==id2)
            up=ip2;
         else
            up=siz-1;
         nsiz=ip1;
          if(cnt_emp>0)
          {
             i1=i2=emp_list[cnt_emp-1];
             cnt_emp--;
          }
          else
          {
              i1=i2=num_bl++;
          }
         for(i=ip1;i<=up||up+i-ip1+1<siz;i++)
         {
             if(i<=up)
             {
                sq_list[i1].push_back(sq_list[id1][i]);
                id=sq_list[id1][i].id;
                if(st[id]==id1)
                   st[id]=i1;
                if(en[id]==id1)
                   en[id]=i1;
             }
             if(up+i-ip1+1<siz)
             {
                 sq_list[id1][i]=sq_list[id1][up+i-ip1+1];
                 nsiz++;
             }
         }
         lazy[i1]=lazy[id1];
         pre[i1]=-1;
       

       

         while(sq_list[id1].size()>nsiz)
             sq_list[id1].pop_back();
         update(id1);
         update(i1);
     if(id1!=id2)
     {
          id=nxt[id1];
          nxt[id1]=-1;
          nxt[i1]=id;
          if(id>=0)
            pre[id]=i1;
         siz=sq_list[id2].size();
         nsiz=0;
         if(cnt_emp>0)
         {
            i2=emp_list[cnt_emp-1];
            cnt_emp--;
         }
         else
            i2=num_bl++;
         for(i=0;i<=ip2||ip2+i+1<siz;i++)
         {
              if(i<=ip2)
              {
                  sq_list[i2].push_back(sq_list[id2][i]);
                  id=sq_list[id2][i].id;
                  if(st[id]==id2) 
                      st[id]=i2;
                  if(en[id]==id2)
                      en[id]=i2;
              }
              if(ip2+i+1<siz)
              {
                 sq_list[id2][i]=sq_list[id2][ip2+i+1];
                 nsiz++;
              }
         }
         
         lazy[i2]=lazy[id2];
         nxt[i2]=-1;
         

         while(sq_list[id2].size()>nsiz)
            sq_list[id2].pop_back();
         update(id2);
         update(i2);
         id=pre[id2];
         pre[id2]=-1;
         pre[i2]=id;
         if(id>=0)
            nxt[id]=i2;
         nxt[i2]=-1;
         id=merge(id1,id2);
        
        id2=id;
        id=nxt[id];
         
         
         while(id>=0)
         {
             int siz1=sq_list[id2].size(),siz2=sq_list[id].size();
             if(siz1+siz2<2*bound)
               id=merge(id2,id);
             else
                break;
             id2=id;
             id=nxt[id];
         }
         
     }
     else 
        nxt[i1]=-1;
}
void two(int u,int h)
{
     int i,j,s,p,q,id1,id2,id,ip,di,f1,f2,siz,dt;
     id1=st[u];
     id2=en[u];
     id=id2;
     i=get_pos(id2,u,1);
     
     dt=lazy[id2]+sq_list[id2][i].dist;
     
     di=lazy[id2]+sq_list[id2][i].dist-h;
     
     
   

     
     for(;i<sq_list[id2].size();i++)
     {
         if(lazy[id2]+sq_list[id2][i].dist==di) 
            break;
     }
     if(i>=sq_list[id2].size())
     {
         id=nxt[id2];
         
        

        

         

         
         
         while(id>=0)
         {
             if(lazy[id]+min_dist[id]<=di&&lazy[id]+max_dist[id]>=di) 
                 break;
             id=nxt[id];
         }
         for(ip=0;ip<sq_list[id].size();ip++)
         {
             if(lazy[id]+sq_list[id][ip].dist==di) 
                break;
         }
         
     }
     else
     {
         id=id2;
         ip=i;
     }   
     
    

     id=sq_list[id][ip].id;
     
   

     split(id1,get_pos(id1,u,0),id2,get_pos(id2,u,1));
     
    

     
     f1=i1;
     f2=i2;
     
  

     
     for(j=i1;;j=nxt[j])
     {
        lazy[j]-=dt;
        if(j==i2)
           break;
     }
     

     siz=sq_list[en[id]].size();
     i=get_pos(en[id],id,1);
     dt=sq_list[en[id]][i].dist+lazy[en[id]]+1;
      for(j=i1;;j=nxt[j])
     {
        lazy[j]+=dt;
        if(j==i2)
           break;
     }
         cnt_vis++;
         for(j=0;j<i;j++)
         {
             ip=sq_list[en[id]][j].id;
             vis[ip]=cnt_vis;
         }
         
         int io=en[id];
         
         now.id=id;
         now.dist=lazy[en[id]]+sq_list[en[id]][i].dist;
         
         if(cnt_emp>0)
         {
            i1=emp_list[cnt_emp-1];
            cnt_emp--;
         }
         else
            i1=num_bl++;
         
         for(;i<siz;i++)
         {
            sq_list[i1].push_back(sq_list[io][i]);
            ip=sq_list[io][i].id;
            if(st[ip]==io&&vis[ip]!=cnt_vis)
               st[ip]=i1;
            if(en[ip]==io)
               en[ip]=i1;
         }
         lazy[i1]=lazy[io];
         update(i1);
        

         while(sq_list[io].size()>j)
            sq_list[io].pop_back();
         update(io);
         ip=nxt[io];
         nxt[io]=-1;
         nxt[i1]=ip;
         if(ip>=0)
            pre[ip]=i1;
         
          if(cnt_emp>0)
         {
            i2=emp_list[cnt_emp-1];
            cnt_emp--;
         }
         else
            i2=num_bl++;
         sq_list[i2].push_back(now);
        

         ip=merge(i2,f1);
         ip=merge(io,ip);
         if(f1==f2)
            id=merge(ip,i1);
         else
            id=merge(f2,i1);
        
         id2=id;
        id=nxt[id];
         while(id>=0)
         {
             int siz1=sq_list[id2].size(),siz2=sq_list[id].size();
             if(siz1+siz2<2*bound)
               id=merge(id2,id);
             else
                break;
             id2=id;
             id=nxt[id];
         }
         
}
int main()
{
    int nt,i,j,s,p,q,id,flag,u,v,h,k,ip,siz;
    scanf("%d%d",&n,&m);
    bound=(int)(sqrt(2.0*n)+1);
    for(i=0;i<n;i++)
       adj[i].clear();
    for(i=0;i<n;i++)
    {
        scanf("%d",&nt);
        for(j=0;j<nt;j++)
        {
            scanf("%d",&id);
            id--;
            adj[i].push_back(id);
        }
    }
    cnt_list=dist[0]=0;
    dfs(0);
    memset(nxt,-1,sizeof(nxt));
    memset(pre,-1,sizeof(pre));
    num_bl=0;
    for(i=0;i<330000;i++)
       sq_list[i].clear();
    for(i=0;i<cnt_list;i++)
    {
        list[i].dist=dist[list[i].id];
      

        
        sq_list[num_bl].push_back(list[i]);
        if(sq_list[num_bl].size()==bound)
           num_bl++;
    }
    while(sq_list[num_bl].size()>0)
       num_bl++;
    for(i=0;i<num_bl;i++)
    {
        if(i>0)
           pre[i]=i-1;
        if(i+1<num_bl)
           nxt[i]=i+1;
    }
    memset(st,-1,sizeof(st));
    memset(vis,-1,sizeof(vis));
    cnt_vis=0;
    memset(lazy,0,sizeof(lazy));
    for(i=0;i<num_bl;i++)
    {
        max_dist[i]=-1;
        min_dist[i]=inf;
        for(j=0;j<sq_list[i].size();j++)
        {
             max_dist[i]=max(max_dist[i],sq_list[i][j].dist);
             min_dist[i]=min(min_dist[i],sq_list[i][j].dist);
             if(st[sq_list[i][j].id]<0)
                st[sq_list[i][j].id]=i;
             en[sq_list[i][j].id]=i;
        }
    }
    cnt_emp=0;
  

    



    num_out=0;
    
    for(i=0;i<m;i++)
    {
        scanf("%d",&flag);
        if(flag==1)
        {
          

            

           
             scanf("%d%d",&u,&v);
             u--;
             v--;
            

              

             printf("%d\n",query_dist(u,v));
        
             num_out++;
        }
        else if(flag==2)
        {
           

           

             
             scanf("%d%d",&u,&h);
            

             
             u--;
             two(u,h);
        }
        else
        {
            scanf("%d",&k);
            id=en[n-1];
            ip=-1;
            for(int ii=id;ii>=0;ii=nxt[ii])
            {
                if(lazy[ii]+min_dist[ii]<=k&&lazy[ii]+max_dist[ii]>=k)
                    ip=ii;
            }
            if(ip<0)
            {
                for(ip=pre[id];ip>=0;ip=pre[ip])
                {
                     if(lazy[ip]+min_dist[ip]<=k&&lazy[ip]+max_dist[ip]>=k)
                          break;
                }
            }
            siz=sq_list[ip].size();
            int ii;
            for(ii=siz-1;ii>=0;ii--)
            {
                 if(lazy[ip]+sq_list[ip][ii].dist==k)
                     break;
            }
            printf("%d\n",sq_list[ip][ii].id+1);
            num_out++;
        }
        

          

    }
    

    return 0;
}
