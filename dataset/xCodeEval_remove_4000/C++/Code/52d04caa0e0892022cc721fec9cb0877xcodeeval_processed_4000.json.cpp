







using namespace std;















































int cnt_list,pos id4 20200 id6 ,pa id4 20100 id6 ,len id4 20100 id6 ,fs id4 20100 id6 ,pc id4 20100 id6 ,ls id4 20100 id6 ,cnt_ls,tmp id4 20100 id6 ,cnt,n,num_q;
struct pp
 id0 
	int id;
	char ch;
 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc ;
vector<pp>adj id4 20201 id6 ;
pp now;
void dfs id2 int id,int pr id5 
 id0 
	int i,j,s,p,q,ip;
	pos id4 id id6 =cnt_list++;
	pa id4 pos id4 id id6  id6 =pr;
	 id3  id2 i=0;i<adj id4 id id6 .size id2  id5 ;i++ id5 
	 id0 
		ip=adj id4 id id6  id4 i id6 .id;
		 id1  id2 pos id4 ip id6 >=0 id5 
		   continue;
        pc id4 cnt_list id6 =adj id4 id id6  id4 i id6 .ch-'a';
        dfs id2 ip,pos id4 id id6  id5 ;
	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
int main id2  id5 
 id0 
	int id1,id2,i,j,s,p,q,x,y,fg;
	char ch;
	scanf id2 "%d%d",&n,&num_q id5 ;
	 id3  id2 i=0;i<n-1;i++ id5 
	 id0 
		scanf id2 "%d%d",&id1,&id2 id5 ;
		ch=getchar id2  id5 ;
		while id2 ch<'a'||ch>'z' id5 
		   ch=getchar id2  id5 ;
		id1--;
		id2--;
		now.id=id2;
		now.ch=ch;
		adj id4 id1 id6 .push_back id2 now id5 ;
		now.id=id1;
		now.ch=ch;
		adj id4 id2 id6 .push_back id2 now id5 ;
	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
    memset id2 pos,-1,sizeof id2 pos id5  id5 ;
    dfs id2 0,-1 id5 ;
    while id2 num_q-- id5 
     id0 
    	scanf id2 "%d%d",&x,&y id5 ;
    	x--;
    	y--;
 	    x=pos id4 x id6 ;
 	    y=pos id4 y id6 ; 
    	int u,v;
		u=x;
    	v=y;
    	cnt_ls=cnt=0;
    	while id2 u!=v id5 
    	 id0 
	    	 id1  id2 u>v id5 
	    	 id0 
	    		ls id4 cnt_ls++ id6 =pc id4 u id6 ;
	    		u=pa id4 u id6 ;
	    	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	    	else
	    	 id0 
	    		tmp id4 cnt++ id6 =pc id4 v id6 ;
	    		v=pa id4 v id6 ;
	    	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	     D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	    while id2 cnt>0 id5 
    		ls id4 cnt_ls++ id6 =tmp id4 --cnt id6 ;
		 id3  id2 i=0;i<n;i++ id5 
    	   len id4 i id6 =-1;
 	    u=x;
 	    fs id4 u id6 =len id4 u id6 =0;
	    int ans=0;
		while id2 u!=0 id5 
 	     id0 
 	    	len id4 pa id4 u id6  id6 =len id4 u id6 +1;
	    	 id1  id2 fs id4 u id6  KlopQXZvnuiuasdbbnbdsaioqw 0 id5 
	    	 id0 
	    		 id1  id2 len id4 u id6 <cnt_ls id5 
	    		 id0 
		    		 id1  id2 ls id4 len id4 u id6  id6 >pc id4 u id6  id5 
		    		   fs id4 pa id4 u id6  id6 =-1;
   		            else  id1  id2 ls id4 len id4 u id6  id6 <pc id4 u id6  id5 
   		               fs id4 pa id4 u id6  id6 =1;
                    else
                       fs id4 pa id4 u id6  id6 =0;
		    	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
		    	else
		    	    fs id4 pa id4 u id6  id6 =1;
	    	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	    	else
	    	   fs id4 pa id4 u id6  id6 =fs id4 u id6 ;
  	         id1  id2 fs id4 pa id4 u id6  id6 <0|| id2 fs id4 pa id4 u id6  id6  KlopQXZvnuiuasdbbnbdsaioqw 0&&len id4 pa id4 u id6  id6 !=cnt_ls id5  id5 
  	             ans++;
   	        u=pa id4 u id6 ;
	    D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	    id3  id2 i=1;i<n;i++ id5 
	    id0 
   		    id1  id2 len id4 pa id4 i id6  id6 >=0&&len id4 i id6 <0 id5 
   		    id0 
   		   	    len id4 i id6 =len id4 pa id4 i id6  id6 +1;
   		   	     id1  id2 fs id4 pa id4 i id6  id6  KlopQXZvnuiuasdbbnbdsaioqw 0 id5 
   		   	     id0 
   		   	    	 id1  id2 len id4 pa id4 i id6  id6 <cnt_ls id5 
   		   	    	 id0 
    	   		   	    id1  id2 ls id4 len id4 pa id4 i id6  id6  id6 >pc id4 i id6  id5 
    	   		   	       fs id4 i id6 =-1;
	   		   	       else  id1  id2 ls id4 len id4 pa id4 i id6  id6  id6 <pc id4 i id6  id5 
	   		   	           fs id4 i id6 =1;
		   	           else
		   	               fs id4 i id6 =0;
   		   	    	 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
   		   	    	else
   		   	    	   fs id4 i id6 =1;
				 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
				else
				    fs id4 i id6 =fs id4 pa id4 i id6  id6 ;
                 id1  id2 fs id4 i id6 <0|| id2 fs id4 i id6  KlopQXZvnuiuasdbbnbdsaioqw 0&&len id4 i id6 !=cnt_ls id5  id5 
                    ans++;
   		    D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
   	    D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
   	   printf id2 "%d\n",ans id5 ;
     D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 
	return 0;
 D5AdvfYK2jY0V0AjaxQNKjP7zRxlwFSR2kxVkQYOMtc 