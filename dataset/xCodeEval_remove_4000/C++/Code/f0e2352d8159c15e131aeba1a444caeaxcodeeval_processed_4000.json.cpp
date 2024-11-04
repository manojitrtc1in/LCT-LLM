







using namespace std;






































int cnt_list,pos sdfiuSDFnncsdf 20200 id0 ,pa sdfiuSDFnncsdf 20100 id0 ,len sdfiuSDFnncsdf 20100 id0 ,fs sdfiuSDFnncsdf 20100 id0 ,pc sdfiuSDFnncsdf 20100 id0 ,ls sdfiuSDFnncsdf 20100 id0 ,cnt_ls,tmp sdfiuSDFnncsdf 20100 id0 ,cnt,n,num_q;
struct pp
 id3 
	int id;
	char ch;
 asduyyZXCasd ;
vector<pp>adj sdfiuSDFnncsdf 20201 id0 ;
pp now;
void dfs id2 int id,int pr id1 
 id3 
	int i,j,s,p,q,ip;
	pos sdfiuSDFnncsdf id id0 =cnt_list++;
	pa sdfiuSDFnncsdf pos sdfiuSDFnncsdf id id0  id0 =pr;
	 SDFjhnmasdhASDdwq  id2 i=0;i<adj sdfiuSDFnncsdf id id0 .size id2  id1 ;i++ id1 
	 id3 
		ip=adj sdfiuSDFnncsdf id id0  sdfiuSDFnncsdf i id0 .id;
		 aSdjjsdfWqeqw  id2 pos sdfiuSDFnncsdf ip id0 >=0 id1 
		   continue;
        pc sdfiuSDFnncsdf cnt_list id0 =adj sdfiuSDFnncsdf id id0  sdfiuSDFnncsdf i id0 .ch-'a';
        dfs id2 ip,pos sdfiuSDFnncsdf id id0  id1 ;
	 asduyyZXCasd 
 asduyyZXCasd 
int main id2  id1 
 id3 
	int id1,id2,i,j,s,p,q,x,y,fg;
	char ch;
	scanf id2 "%d%d",&n,&num_q id1 ;
	 SDFjhnmasdhASDdwq  id2 i=0;i<n-1;i++ id1 
	 id3 
		scanf id2 "%d%d",&id1,&id2 id1 ;
		ch=getchar id2  id1 ;
		while id2 ch<'a'||ch>'z' id1 
		   ch=getchar id2  id1 ;
		id1--;
		id2--;
		now.id=id2;
		now.ch=ch;
		adj sdfiuSDFnncsdf id1 id0 .push_back id2 now id1 ;
		now.id=id1;
		now.ch=ch;
		adj sdfiuSDFnncsdf id2 id0 .push_back id2 now id1 ;
	 asduyyZXCasd 
    memset id2 pos,-1,sizeof id2 pos id1  id1 ;
    dfs id2 0,-1 id1 ;
    while id2 num_q-- id1 
     id3 
    	scanf id2 "%d%d",&x,&y id1 ;
    	x--;
    	y--;
 	    x=pos sdfiuSDFnncsdf x id0 ;
 	    y=pos sdfiuSDFnncsdf y id0 ; 
    	int u,v;
		u=x;
    	v=y;
    	cnt_ls=cnt=0;
    	while id2 u!=v id1 
    	 id3 
	    	 aSdjjsdfWqeqw  id2 u>v id1 
	    	 id3 
	    		ls sdfiuSDFnncsdf cnt_ls++ id0 =pc sdfiuSDFnncsdf u id0 ;
	    		u=pa sdfiuSDFnncsdf u id0 ;
	    	 asduyyZXCasd 
	    	else
	    	 id3 
	    		tmp sdfiuSDFnncsdf cnt++ id0 =pc sdfiuSDFnncsdf v id0 ;
	    		v=pa sdfiuSDFnncsdf v id0 ;
	    	 asduyyZXCasd 
	     asduyyZXCasd 
	    while id2 cnt>0 id1 
    		ls sdfiuSDFnncsdf cnt_ls++ id0 =tmp sdfiuSDFnncsdf --cnt id0 ;
		 SDFjhnmasdhASDdwq  id2 i=0;i<n;i++ id1 
    	   len sdfiuSDFnncsdf i id0 =-1;
 	    u=x;
 	    fs sdfiuSDFnncsdf u id0 =len sdfiuSDFnncsdf u id0 =0;
	    int ans=0;
		while id2 u!=0 id1 
 	     id3 
 	    	len sdfiuSDFnncsdf pa sdfiuSDFnncsdf u id0  id0 =len sdfiuSDFnncsdf u id0 +1;
	    	 aSdjjsdfWqeqw  id2 fs sdfiuSDFnncsdf u id0  SDOfdsjfnmdsf 0 id1 
	    	 id3 
	    		 aSdjjsdfWqeqw  id2 len sdfiuSDFnncsdf u id0 <cnt_ls id1 
	    		 id3 
		    		 aSdjjsdfWqeqw  id2 ls sdfiuSDFnncsdf len sdfiuSDFnncsdf u id0  id0 >pc sdfiuSDFnncsdf u id0  id1 
		    		   fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf u id0  id0 =-1;
   		            else  aSdjjsdfWqeqw  id2 ls sdfiuSDFnncsdf len sdfiuSDFnncsdf u id0  id0 <pc sdfiuSDFnncsdf u id0  id1 
   		               fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf u id0  id0 =1;
                    else
                       fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf u id0  id0 =0;
		    	 asduyyZXCasd 
		    	else
		    	    fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf u id0  id0 =1;
	    	 asduyyZXCasd 
	    	else
	    	   fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf u id0  id0 =fs sdfiuSDFnncsdf u id0 ;
  	         aSdjjsdfWqeqw  id2 fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf u id0  id0 <0|| id2 fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf u id0  id0  SDOfdsjfnmdsf 0&&len sdfiuSDFnncsdf pa sdfiuSDFnncsdf u id0  id0 !=cnt_ls id1  id1 
  	             ans++;
   	        u=pa sdfiuSDFnncsdf u id0 ;
	    asduyyZXCasd 
	    SDFjhnmasdhASDdwq  id2 i=1;i<n;i++ id1 
	    id3 
   		    aSdjjsdfWqeqw  id2 len sdfiuSDFnncsdf pa sdfiuSDFnncsdf i id0  id0 >=0&&len sdfiuSDFnncsdf i id0 <0 id1 
   		    id3 
   		   	    len sdfiuSDFnncsdf i id0 =len sdfiuSDFnncsdf pa sdfiuSDFnncsdf i id0  id0 +1;
   		   	     aSdjjsdfWqeqw  id2 fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf i id0  id0  SDOfdsjfnmdsf 0 id1 
   		   	     id3 
   		   	    	 aSdjjsdfWqeqw  id2 len sdfiuSDFnncsdf pa sdfiuSDFnncsdf i id0  id0 <cnt_ls id1 
   		   	    	 id3 
    	   		   	    aSdjjsdfWqeqw  id2 ls sdfiuSDFnncsdf len sdfiuSDFnncsdf pa sdfiuSDFnncsdf i id0  id0  id0 >pc sdfiuSDFnncsdf i id0  id1 
    	   		   	       fs sdfiuSDFnncsdf i id0 =-1;
	   		   	       else  aSdjjsdfWqeqw  id2 ls sdfiuSDFnncsdf len sdfiuSDFnncsdf pa sdfiuSDFnncsdf i id0  id0  id0 <pc sdfiuSDFnncsdf i id0  id1 
	   		   	           fs sdfiuSDFnncsdf i id0 =1;
		   	           else
		   	               fs sdfiuSDFnncsdf i id0 =0;
   		   	    	 asduyyZXCasd 
   		   	    	else
   		   	    	   fs sdfiuSDFnncsdf i id0 =1;
				 asduyyZXCasd 
				else
				    fs sdfiuSDFnncsdf i id0 =fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf i id0  id0 ;
                 aSdjjsdfWqeqw  id2 fs sdfiuSDFnncsdf i id0 <0|| id2 fs sdfiuSDFnncsdf i id0  SDOfdsjfnmdsf 0&&len sdfiuSDFnncsdf i id0 !=cnt_ls id1  id1 
                    ans++;
   		    asduyyZXCasd 
   	    asduyyZXCasd 
   	   printf id2 "%d\n",ans id1 ;
     asduyyZXCasd 
	return 0;
 asduyyZXCasd 