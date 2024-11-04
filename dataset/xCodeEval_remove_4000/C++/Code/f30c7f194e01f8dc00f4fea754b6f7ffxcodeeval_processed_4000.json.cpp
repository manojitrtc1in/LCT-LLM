





















































using namespace std;
const int mod=1e9+9,base=27;
struct pp
 id1 
	int id;
	char ch;
 id5 ;
pp now;
vector<pp>adj id3 20201 id4 ,tadj id3 20201 id4  id3 26 id4 ;
int tr id3 2 id4  id3 20100 id4 ,ex id3 20100 id4 ;
int ps id3 20100 id4 ,pom id3 20100 id4 ,di id3 20100 id4 ,ha id3 2 id4  id3 20100 id4 ,pd id3 20100 id4 ,ls id3 55 id4 ,cnt_ls,deep id3 20010 id4 ,pw id3 20100 id4 ,lm id3 20100 id4 ,id0;
int n,num_q,ans id3 20100 id4 ,num_node,size id3 20100 id4 ,mi,ch,pa id3 20100 id4 ,to id3 20100 id4 ,cr id3 401000 id4 ;
bool vis id3 20100 id4 ;
int bs id3 400100 id4 ,trie id3 401000 id4  id3 26 id4 ,queue id3 20110 id4 ,temp1,temp2,temp,dist id3 400000 id4 ,tw id3 401000 id4 ,list id3 401000 id4 ,cnt_list,pos id3 401000 id4 ,hs id3 2 id4  id3 400000 id4 ,pc id3 401000 id4 ,sum id3 401000 id4 ;
int pk id3 401000 id4 ,pe id3 401000 id4 ,sz id3 401000 id4  id3 27 id4 ,zz id3 20100 id4 ;
int pm id3 20100 id4 ;
struct qr
 id1 
	int y,id;
 id5 ;
vector<qr>vr id3 20010 id4 ;
qr nw;
vector<int>vec id3 20100 id4 ;
void prp id2 int id,int pr id7 
 id1 
	int i,j,s,p,q,ip,ch=-1;
	pa id3 id id4 =pr;
	di id3 id id4 =0;
	 id6  id2 i=0;i<adj id3 id id4 .size id2  id7 ;i++ id7 
	 id1 
		ip=adj id3 id id4  id3 i id4 .id;
		 jmsdfkWQEr22FSD234SDFFwasd  id2 ip KlopQXZvnuiuasdbbnbdsaioqw pr id7 
		    continue;
        deep id3 ip id4 =deep id3 id id4 +1;
        prp id2 ip,id id7 ;
         jmsdfkWQEr22FSD234SDFFwasd  id2 di id3 id id4 <di id3 ip id4 +1 id7 
         id1 
        	di id3 id id4 =di id3 ip id4 +1;
        	ch=i;
         id5 
	 id5 
	 jmsdfkWQEr22FSD234SDFFwasd  id2 ch>=0 id7 
	 id1 
		swap id2 adj id3 id id4  id3 ch id4 ,adj id3 id id4  id3 0 id4  id7 ;
		ps id3 adj id3 id id4  id3 0 id4 .id id4 =id;
	 id5 
 id5 
void gps id2 int id id7 
 id1 
	int i,j,s,p,q,ip;
	lm id3 id0++ id4 =id;
	pom id3 id id4 =id0-1;
	 id6  id2 i=0;i<adj id3 id id4 .size id2  id7 ;i++ id7 
	 id1 
		ip=adj id3 id id4  id3 i id4 .id;
		 jmsdfkWQEr22FSD234SDFFwasd  id2 ip KlopQXZvnuiuasdbbnbdsaioqw pa id3 id id4  id7 
		   continue;
        pd id3 ip id4 =adj id3 id id4  id3 i id4 .ch-'a';
        gps id2 ip id7 ;
	 id5 
 id5 
void ho id2 int id id7 
 id1 
	int i,j,s,p,q,ch=-1;
	dist id3 id id4 =0;
	sz id3 id id4  id3 0 id4 =bs id3 id id4 ;
	tw id3 id id4 =id;
	cr id3 id id4 =-1;
	 id6  id2 i=0;i<26;i++ id7 
	 id1 
		 jmsdfkWQEr22FSD234SDFFwasd  id2 trie id3 id id4  id3 i id4 >0 id7 
		 id1 
		   ho id2 trie id3 id id4  id3 i id4  id7 ;
		   pc id3 trie id3 id id4  id3 i id4  id4 =i;
		   sz id3 id id4  id3 i+1 id4 =sz id3 trie id3 id id4  id3 i id4  id4  id3 26 id4 ;
		    jmsdfkWQEr22FSD234SDFFwasd  id2 dist id3 id id4 <dist id3 trie id3 id id4  id3 i id4  id4 +1 id7 
  	   	    id1 
   		 	   dist id3 id id4 =dist id3 trie id3 id id4  id3 i id4  id4 +1;
   		       cr id3 id id4 =ch=trie id3 id id4  id3 i id4 ;   
  	   	    id5 
		 id5 
	 id5 
	 jmsdfkWQEr22FSD234SDFFwasd  id2 ch>=0 id7 
	 id1 
	   tw id3 id id4 =tw id3 ch id4 ;
	   pk id3 ch id4 =id;
	 id5 
	 id6  id2 i=0;i<26;i++ id7 
       sz id3 id id4  id3 i+1 id4 +=sz id3 id id4  id3 i id4 ;
 id5 
void tra id2 int id id7 
 id1 
	int i,j,s,p,q;
	list id3 cnt_list++ id4 =id;
	pos id3 id id4 =cnt_list-1;
	 jmsdfkWQEr22FSD234SDFFwasd  id2 cr id3 id id4 >=0 id7 
	   tra id2 cr id3 id id4  id7 ;
     id6  id2 i=0;i<26;i++ id7 
     id1 
    	 jmsdfkWQEr22FSD234SDFFwasd  id2 trie id3 id id4  id3 i id4 >0&&trie id3 id id4  id3 i id4 !=cr id3 id id4  id7 
    	   tra id2 trie id3 id id4  id3 i id4  id7 ;
     id5 
 id5 
void get_size id2 int id,int pr id7 
 id1 
	int i,j,s,p,q,ip;
	size id3 id id4 =vr id3 id id4 .size id2  id7 +1;
	 id6  id2 i=0;i<adj id3 id id4 .size id2  id7 ;i++ id7 
	 id1 
		ip=adj id3 id id4  id3 i id4 .id;
		 jmsdfkWQEr22FSD234SDFFwasd  id2 !vis id3 ip id4 &&ip!=pr id7 
		 id1 
			get_size id2 ip,id id7 ;
			size id3 id id4 +=size id3 ip id4 ;
		 id5 
	 id5 
 id5 
void choose_root id2 int id,int pr,int now_sz,int &ch id7 
 id1 
	int i,j,s,p,q,ax=now_sz,ip;
	 id6  id2 i=0;i<adj id3 id id4 .size id2  id7 ;i++ id7 
	 id1 
		ip=adj id3 id id4  id3 i id4 .id;
		 jmsdfkWQEr22FSD234SDFFwasd  id2 ip KlopQXZvnuiuasdbbnbdsaioqw pr||vis id3 ip id4  id7 
		    continue;
		 jmsdfkWQEr22FSD234SDFFwasd  id2 ax<size id3 ip id4  id7 
			ax=size id3 ip id4 ;
	 id5 
	 jmsdfkWQEr22FSD234SDFFwasd  id2 mi>ax id7 
	 id1 
		mi=ax;
		ch=id; 
	 id5 
	 id6  id2 i=0;i<adj id3 id id4 .size id2  id7 ;i++ id7 
	 id1 
		ip=adj id3 id id4  id3 i id4 .id;
		 jmsdfkWQEr22FSD234SDFFwasd  id2 ip KlopQXZvnuiuasdbbnbdsaioqw pr||vis id3 ip id4  id7 
		    continue;
		choose_root id2 ip,id,now_sz+size id3 id id4 -size id3 ip id4 ,ch id7 ;	
	 id5 
 id5 
void construct id2 int id,bool flag id7 
 id1 
	int i,j,s,p,q,ch,ip,ro,idd;
	to id3 id id4 =num_node;
	queue id3 0 id4 =id;
	bs id3 num_node id4 =1;
	pe id3 num_node id4 =-1;
	memset id2 trie id3 num_node id4 ,0,sizeof id2 trie id3 num_node id4  id7  id7 ;
	num_node++;
	temp1=temp2=0;
	temp=1;
	vis id3 id id4 =true;
	while id2 temp1<=temp2 id7 
	 id1 
		 id6  id2 i=temp1;i<=temp2;i++ id7 
		 id1 
			idd=queue id3 i id4 ;
			 id6  id2 j=0;j<adj id3 idd id4 .size id2  id7 ;j++ id7 
			 id1 
				ch=adj id3 idd id4  id3 j id4 .ch-'a';
				ip=adj id3 idd id4  id3 j id4 .id;
				 jmsdfkWQEr22FSD234SDFFwasd  id2 !vis id3 ip id4  id7 
				 id1 
					 jmsdfkWQEr22FSD234SDFFwasd  id2 flag KlopQXZvnuiuasdbbnbdsaioqw 0 id7 
					 id1 
				        jmsdfkWQEr22FSD234SDFFwasd  id2 idd KlopQXZvnuiuasdbbnbdsaioqw id id7 
				    		pm id3 ip id4 =ip;
				    	else
				    	    pm id3 ip id4 =pm id3 idd id4 ;
					 id5 
					 jmsdfkWQEr22FSD234SDFFwasd  id2 trie id3 to id3 idd id4  id4  id3 ch id4  KlopQXZvnuiuasdbbnbdsaioqw 0 id7 
					 id1 
						bs id3 num_node id4 =0;
						pe id3 num_node id4 =to id3 idd id4 ;
						memset id2 trie id3 num_node id4 ,0,sizeof id2 trie id3 num_node id4  id7  id7 ;
						trie id3 to id3 idd id4  id4  id3 ch id4 =num_node++;  
					 id5 
					to id3 ip id4 =trie id3 to id3 idd id4  id4  id3 ch id4 ;
					bs id3 to id3 ip id4  id4 ++;
					vis id3 ip id4 =true;
					queue id3 temp++ id4 =ip;
					 jmsdfkWQEr22FSD234SDFFwasd  id2 flag KlopQXZvnuiuasdbbnbdsaioqw 0&&vr id3 ip id4 .size id2  id7 >0 id7 
					    vec id3 pm id3 ip id4  id4 .push_back id2 ip id7 ;
				 id5 
			 id5 
		 id5 
		temp1=temp2+1;
		temp2=temp-1;
	 id5 
	 id6  id2 i=0;i<temp;i++ id7 
	   vis id3 queue id3 i id4  id4 =false;
     id6  id2 i=to id3 id id4 ;i<num_node;i++ id7 
     id1 
    	pk id3 i id4 =i;
       memset id2 sz id3 i id4 ,0,sizeof id2 sz id3 i id4  id7  id7 ;
     id5 
    pc id3 to id3 id id4  id4 =-1;
    ho id2 to id3 id id4  id7 ;
    tra id2 to id3 id id4  id7 ;
     id6  id2 i=to id3 id id4 ;i<num_node;i++ id7 
       pk id3 list id3 i id4  id4 =pk id3 pk id3 list id3 i id4  id4  id4 ; 
	 jmsdfkWQEr22FSD234SDFFwasd  id2 pos id3 to id3 id id4  id4  KlopQXZvnuiuasdbbnbdsaioqw 0 id7 
    	hs id3 0 id4  id3 pos id3 to id3 id id4  id4  id4 =pw id3 id id4 +1;
    else
     id1 
        hs id3 0 id4  id3 pos id3 to id3 id id4  id4  id4 = id2 int id7  id2  id2 long long id7 hs id3 0 id4  id3 pos id3 to id3 id id4  id4 -1 id4 * id2 long long id7 base%mod id7 ;
        hs id3 0 id4  id3 pos id3 to id3 id id4  id4  id4 = id2 hs id3 0 id4  id3 pos id3 to id3 id id4  id4  id4 +pw id3 id id4 +1 id7 %mod;
	 id5 
    sum id3 pos id3 to id3 id id4  id4  id4 =0;
  	 id6  id2 i=pos id3 to id3 id id4  id4 ;i<cnt_list-1;i++ id7 
     id1 
       	hs id3 0 id4  id3 i+1 id4 = id2 int id7  id2  id2 long long id7 hs id3 0 id4  id3 i id4 * id2 long long id7 base%mod id7 ;
       	hs id3 0 id4  id3 i+1 id4 = id2 hs id3 0 id4  id3 i+1 id4 +pc id3 list id3 i+1 id4  id4 +1 id7 %mod;
       	 jmsdfkWQEr22FSD234SDFFwasd  id2 i+1<cnt_list id7 
           	sum id3 i+1 id4 =sum id3 i id4 +sz id3 list id3 i id4  id4  id3 pc id3 list id3 i+1 id4  id4  id4 ;
        else
             sum id3 i+1 id4 =sum id3 i id4 +1;
     id5 
     id6  id2 i=cnt_list-1;i>=pos id3 to id3 id id4  id4 ;i-- id7 
     id1 
    	hs id3 1 id4  id3 i id4 = id2 int id7  id2  id2 long long id7 hs id3 1 id4  id3 i+1 id4 * id2 long long id7 base%mod id7 ;
    	 jmsdfkWQEr22FSD234SDFFwasd  id2 i>pos id3 to id3 id id4  id4  id7 
		   hs id3 1 id4  id3 i id4 = id2 hs id3 1 id4  id3 i id4 +pc id3 list id3 i id4  id4 +1 id7 %mod;
	   else
	       hs id3 1 id4  id3 i id4 = id2 hs id3 1 id4  id3 i id4 +pw id3 id id4 +1 id7 %mod;
     id5 
 id5 
int lca id2 int x,int y id7 
 id1 
	while id2 true id7 
	 id1 
		 jmsdfkWQEr22FSD234SDFFwasd  id2 ps id3 x id4  KlopQXZvnuiuasdbbnbdsaioqw ps id3 y id4  id7 
		 id1 
			 jmsdfkWQEr22FSD234SDFFwasd  id2 pom id3 x id4 <pom id3 y id4  id7 
			   return x;
            return y;
		 id5 
		 jmsdfkWQEr22FSD234SDFFwasd  id2 deep id3 ps id3 x id4  id4 >deep id3 ps id3 y id4  id4  id7 
			x=pa id3 ps id3 x id4  id4 ;
		else
		    y=pa id3 ps id3 y id4  id4 ;
	 id5 
 id5 
int query id2 int flag,int left,int right id7 
 id1 
	int ret;
	 jmsdfkWQEr22FSD234SDFFwasd  id2 flag KlopQXZvnuiuasdbbnbdsaioqw 0 id7 
		ret=ha id3 0 id4  id3 right id4 - id2 int id7  id2  id2 long long id7 ha id3 0 id4  id3 left-1 id4 * id2 long long id7 ex id3 right-left+1 id4 %mod id7 ;
	else  jmsdfkWQEr22FSD234SDFFwasd  id2 flag KlopQXZvnuiuasdbbnbdsaioqw 1 id7 
	    ret=hs id3 0 id4  id3 right id4 - id2 int id7  id2  id2 long long id7 hs id3 0 id4  id3 left-1 id4 * id2 long long id7 ex id3 right-left+1 id4 %mod id7 ;
    else  jmsdfkWQEr22FSD234SDFFwasd  id2 flag KlopQXZvnuiuasdbbnbdsaioqw 2 id7 
        ret=hs id3 1 id4  id3 left id4 - id2 int id7  id2  id2 long long id7 hs id3 1 id4  id3 right+1 id4 * id2 long long id7 ex id3 right-left+1 id4 %mod id7 ;
    else
        ret= id2 ha id3 1 id4  id3 left id4 - id2 int id7  id2  id2 long long id7 ha id3 1 id4  id3 right+1 id4 * id2 long long id7 ex id3 right-left+1 id4 %mod id7  id7 ;
	 jmsdfkWQEr22FSD234SDFFwasd  id2 ret<0 id7  
        ret+=mod;
    return ret;
 id5 
int solve id2 int x1,int lca,int x,int y,bool ju,int u id7 
 id1 
	int i,j,s,p,q,low,high,mid,ret=0,ch,flag;
	while id2 !ju||x!=pom id3 y id4  id7 
	 id1 
		 jmsdfkWQEr22FSD234SDFFwasd  id2 !ju&&x KlopQXZvnuiuasdbbnbdsaioqw lca id7 
		 id1 
		   ju=true;
		   x=pom id3 x id4 ;
		 id5 
		 jmsdfkWQEr22FSD234SDFFwasd  id2 ju&&x KlopQXZvnuiuasdbbnbdsaioqw pom id3 y id4  id7 
		    break;
		 jmsdfkWQEr22FSD234SDFFwasd  id2 ju&&x KlopQXZvnuiuasdbbnbdsaioqw pom id3 ls id3 u-1 id4  id4  id7 
         id1 
        	u--;
            x=pom id3 ps id3 ls id3 u-1 id4  id4  id4 -1;
         id5 
         jmsdfkWQEr22FSD234SDFFwasd  id2 ju KlopQXZvnuiuasdbbnbdsaioqw 0 id7 
         id1 
        	 jmsdfkWQEr22FSD234SDFFwasd  id2 ps id3 x id4 !=ps id3 lca id4  id7 
        	   high=pom id3 x id4 -pom id3 ps id3 x id4  id4 +1;
			 else
     	       high=pom id3 x id4 -pom id3 lca id4 ;
             ch=pd id3 x id4 ;
         id5 
        else
         id1 
    	    ch=pd id3 lm id3 x+1 id4  id4 ;
        	high=pom id3 ls id3 u-1 id4  id4 -x;
         id5 
		high=min id2 high,pos id3 tw id3 x1 id4  id4 -pos id3 x1 id4  id7 ;
       	int ll,rr;
		low=0;
		while id2 low<=high id7 
         id1 
        	mid= id2 low+high id7 >>1;
			 jmsdfkWQEr22FSD234SDFFwasd  id2 ju KlopQXZvnuiuasdbbnbdsaioqw 0 id7 
        	 id1 
	        	ll=pom id3 x id4 -mid+1;
	        	rr=pom id3 x id4 ;
	        	flag=3;
	         id5 
	        else
	         id1 
        		ll=x+1;
        		rr=x+mid;
        		flag=0;
        	 id5 
        	 jmsdfkWQEr22FSD234SDFFwasd  id2 query id2 1,pos id3 x1 id4 +1,pos id3 x1 id4 +mid id7  KlopQXZvnuiuasdbbnbdsaioqw query id2 flag,ll,rr id7  id7 
        	    low=mid+1;
    	    else
    	        high=mid-1;
         id5 
         jmsdfkWQEr22FSD234SDFFwasd  id2 high KlopQXZvnuiuasdbbnbdsaioqw 0 id7 
         id1 
        	ret+=sz id3 x1 id4  id3 ch id4 ;
        	high=1;
        	 jmsdfkWQEr22FSD234SDFFwasd  id2 trie id3 x1 id4  id3 ch id4  KlopQXZvnuiuasdbbnbdsaioqw 0 id7 
        	    break;
			x1=trie id3 x1 id4  id3 ch id4 ;
         id5 
        else
         id1 
            ret+=sum id3 pos id3 x1 id4 +high id4 -sum id3 pos id3 x1 id4  id4 ;
            x1=list id3 pos id3 x1 id4 +high id4 ;
		 id5 
		 jmsdfkWQEr22FSD234SDFFwasd  id2 ju KlopQXZvnuiuasdbbnbdsaioqw 0 id7 
			x=pa id3 lm id3 pom id3 x id4 -high+1 id4  id4 ;
		else
          	x=x+high;
	 id5 
	return ret;
 id5 
int get_path id2 int from,int to,int &x,int y,int lca,bool &ju,int &u id7 
 id1 
	int dx,ch,flag;
	while id2 from!=pe id3 to id4 && id2 !ju||x!=pom id3 y id4  id7  id7 
	 id1 
		 jmsdfkWQEr22FSD234SDFFwasd  id2 !ju&&x KlopQXZvnuiuasdbbnbdsaioqw lca id7 
		 id1 
			ju=true;
			x=pom id3 x id4 ;
		 id5 
		 jmsdfkWQEr22FSD234SDFFwasd  id2 ju&&x KlopQXZvnuiuasdbbnbdsaioqw pom id3 y id4  id7 
		    break;
         jmsdfkWQEr22FSD234SDFFwasd  id2 ju&&x KlopQXZvnuiuasdbbnbdsaioqw pom id3 ls id3 u-1 id4  id4  id7 
         id1 
        	u--;
        	x=pom id3 ps id3 ls id3 u-1 id4  id4  id4 -1;
         id5 
         jmsdfkWQEr22FSD234SDFFwasd  id2 ju KlopQXZvnuiuasdbbnbdsaioqw 0 id7 
         id1 
        	 jmsdfkWQEr22FSD234SDFFwasd  id2 ps id3 x id4 !=ps id3 lca id4  id7 
        	   dx=pom id3 x id4 -pom id3 ps id3 x id4  id4 +1;
     	    else
     	       dx=pom id3 x id4 -pom id3 lca id4 ;
  	        flag=3;
			ch=pd id3 x id4 ;
         id5 
        else
         id1 
        	ch=pd id3 lm id3 x+1 id4  id4 ;
        	dx=pom id3 ls id3 u-1 id4  id4 -x;
        	flag=0;
         id5  
         jmsdfkWQEr22FSD234SDFFwasd  id2 pk id3 from id4  KlopQXZvnuiuasdbbnbdsaioqw pk id3 to id4  id7 
        	dx=min id2 dx,pos id3 from id4 -pos id3 to id4 +1 id7 ;
        else
            dx=min id2 dx,pos id3 from id4 -pos id3 pk id3 from id4  id4 +1 id7 ;
		int ll,rr;
         jmsdfkWQEr22FSD234SDFFwasd  id2 ju id7 
         id1 
        	ll=x+1;
        	rr=x+dx;
         id5 
        else
         id1 
        	ll=pom id3 x id4 -dx+1;
        	rr=pom id3 x id4 ;
         id5 
         jmsdfkWQEr22FSD234SDFFwasd  id2 query id2 flag,ll,rr id7 !=query id2 2,pos id3 from id4 -dx+1,pos id3 from id4  id7  id7 
         id1 
        	int low=0,high=dx,mid;
        	int px=x,pf=from;
        	while id2 low<=high id7 
        	 id1 
	        	mid= id2 low+high id7 >>1;
        	     jmsdfkWQEr22FSD234SDFFwasd  id2 ju id7 
        	     id1 
    	        	ll=x+1;
    	        	rr=x+mid;
    	         id5 
    	        else
    	         id1 
    	           ll=pom id3 x id4 -mid+1;
    	           rr=pom id3 x id4 ;
        	     id5 
        	     jmsdfkWQEr22FSD234SDFFwasd  id2 query id2 flag,ll,rr id7  KlopQXZvnuiuasdbbnbdsaioqw query id2 2,pos id3 from id4 -mid+1,pos id3 from id4  id7  id7 
        	        low=mid+1;
    	        else
    	            high=mid-1; 
	         id5 
	         jmsdfkWQEr22FSD234SDFFwasd  id2 ju id7 
	           x+=high;
            else
             id1 
            	 jmsdfkWQEr22FSD234SDFFwasd  id2 high>0 id7 
                	x=pa id3 lm id3 pom id3 x id4 -high+1 id4  id4 ;
             id5 
             jmsdfkWQEr22FSD234SDFFwasd  id2 high>0 id7 
			     from=pe id3 list id3 pos id3 from id4 -high+1 id4  id4 ;
          	 jmsdfkWQEr22FSD234SDFFwasd  id2 !ju&&x KlopQXZvnuiuasdbbnbdsaioqw lca id7 
	     	 id1 
	    		ju=true;
	         	x=pom id3 x id4 ;
	     	 id5   
	         jmsdfkWQEr22FSD234SDFFwasd  id2 ju&&x KlopQXZvnuiuasdbbnbdsaioqw pom id3 ls id3 u-1 id4  id4  id7 
             id1 
            	u--;
            	x=pom id3 ps id3 ls id3 u-1 id4  id4  id4 -1;
             id5 
			 jmsdfkWQEr22FSD234SDFFwasd  id2 ju KlopQXZvnuiuasdbbnbdsaioqw 0 id7 
			   ch=pd id3 x id4 ;
			else
			   ch=pd id3 lm id3 x+1 id4  id4 ;
			 jmsdfkWQEr22FSD234SDFFwasd  id2 pc id3 from id4 <ch id7 
			   return -1;
			 jmsdfkWQEr22FSD234SDFFwasd  id2 pc id3 from id4 >ch id7 
			   return 1;
         id5 
         jmsdfkWQEr22FSD234SDFFwasd  id2 ju id7 
           x+=dx;
        else
          	x=pa id3 lm id3 pom id3 x id4 -dx+1 id4  id4 ;
        from=pe id3 list id3 pos id3 from id4 -dx+1 id4  id4 ;
	 id5 
	 jmsdfkWQEr22FSD234SDFFwasd  id2 !ju&&x KlopQXZvnuiuasdbbnbdsaioqw lca id7 
	 id1 
		ju=true;
		x=pom id3 x id4 ;
	 id5 
	 jmsdfkWQEr22FSD234SDFFwasd  id2 !ju||x!=pom id3 y id4  id7 
	   return 0;
	return 1;
 id5 
void gwp id2 int id,int pr id7 
 id1 
	int i,j,s,p,q,ip;
	zz id3 id id4 =1;
	 id6  id2 i=0;i<adj id3 id id4 .size id2  id7 ;i++ id7 
	 id1 
		ip=adj id3 id id4  id3 i id4 .id;
		 jmsdfkWQEr22FSD234SDFFwasd  id2 ip KlopQXZvnuiuasdbbnbdsaioqw pr||vis id3 ip id4  id7 
		   continue;
        gwp id2 ip,id id7 ;
        zz id3 id id4 +=zz id3 ip id4 ;
	 id5 
 id5 
void dfs id2 int id id7 
 id1 
	int i,j,s,p,q,x,y,ip,ie,u,ch;
	bool ju; 
     id6  id2 i=0;i<adj id3 id id4 .size id2  id7 ;i++ id7 
     id1 
    	ip=adj id3 id id4  id3 i id4 .id;
	   	vec id3 ip id4 .clear id2  id7 ;
     id5 
    gwp id2 id,-1 id7 ;
    construct id2 id,0 id7 ;
     id6  id2 i=0;i<vr id3 id id4 .size id2  id7 ;i++ id7 
     id1 
    	x=id;
    	y=vr id3 id id4  id3 i id4 .y;
        cnt_ls=0;
       	ip=lca id2 x,y id7 ;
	    while id2 true id7 
	     id1 
		    ls id3 cnt_ls++ id4 =y;
		     jmsdfkWQEr22FSD234SDFFwasd  id2 ps id3 y id4  KlopQXZvnuiuasdbbnbdsaioqw ps id3 ip id4  id7 
		        break;
			y=pa id3 ps id3 y id4  id4 ;
    	 id5 
    	y=vr id3 id id4  id3 i id4 .y;
    	ans id3 vr id3 id id4  id3 i id4 .id id4 +=solve id2 to id3 id id4 ,ip,x,y,0,cnt_ls id7 -1;
	 id5 
    vis id3 id id4 =true;
     id6  id2 int ii=0;ii<adj id3 id id4 .size id2  id7 ;ii++ id7 
     id1 
    	ip=adj id3 id id4  id3 ii id4 .id;
    	 jmsdfkWQEr22FSD234SDFFwasd  id2 vec id3 ip id4 .size id2  id7  KlopQXZvnuiuasdbbnbdsaioqw 0 id7 
    	    continue;
	    pw id3 ip id4 =adj id3 id id4  id3 ii id4 .ch-'a';
	    construct id2 ip,1 id7 ;
	    pc id3 to id3 ip id4  id4 =pw id3 ip id4 ;
		 id6  id2 int jj=0;jj<vec id3 ip id4 .size id2  id7 ;jj++ id7 
	     id1 
	    	int xx=vec id3 ip id4  id3 jj id4 ;
	    	 id6  id2 j=0;j<vr id3 xx id4 .size id2  id7 ;j++ id7 
	    	 id1 
	        	x=xx;
	        	y=vr id3 xx id4  id3 j id4 .y;
	        	int ipe=lca id2 x,y id7 ;
	        	cnt_ls=0;
	         	while id2 true id7 
	        	 id1 
	         		ls id3 cnt_ls++ id4 =y;
	        		 jmsdfkWQEr22FSD234SDFFwasd  id2 ps id3 y id4  KlopQXZvnuiuasdbbnbdsaioqw ps id3 ipe id4  id7 
	        		    break;
 		            y=pa id3 ps id3 y id4  id4 ;
 	        	 id5 
 	        	y=vr id3 xx id4  id3 j id4 .y;
	        	u=cnt_ls;
	        	ju=false;
		    	int mf=get_path id2 to id3 x id4 ,to id3 ip id4 ,x,y,ipe,ju,u id7 ;
				 jmsdfkWQEr22FSD234SDFFwasd  id2 mf KlopQXZvnuiuasdbbnbdsaioqw 0 id7 
	         	 id1 
	    	    	int nx,nch,nu;
	        		bool nju;
	        		nju=ju;
	        		nu=u;
	         		nx=x;
	        		 jmsdfkWQEr22FSD234SDFFwasd  id2 !ju|| id2 x!=pom id3 y id4  id7  id7 
	    	    	 id1 
	    	        	 jmsdfkWQEr22FSD234SDFFwasd  id2 !nju&&nx KlopQXZvnuiuasdbbnbdsaioqw ipe id7 
	    		         id1 
		    		       nju=true;
		    		       nx=pom id3 nx id4 ;
		    	         id5 
		    	         jmsdfkWQEr22FSD234SDFFwasd  id2 nju&&nx KlopQXZvnuiuasdbbnbdsaioqw pom id3 ls id3 nu-1 id4  id4  id7 
                         id1 
                        	nu--;
                        	nx=pom id3 ps id3 ls id3 nu-1 id4  id4  id4 -1;
                         id5 
                         jmsdfkWQEr22FSD234SDFFwasd  id2 nju id7 
                         id1 
                        	nch=pd id3 lm id3 nx+1 id4  id4 ;
                            nx++;
				     	 id5 
				    	else
				    	 id1 
                           nch=pd id3 nx id4 ;
                           nx=pa id3 nx id4 ;
					     id5 
					     jmsdfkWQEr22FSD234SDFFwasd  id2 nch KlopQXZvnuiuasdbbnbdsaioqw pw id3 ip id4  id7 
    						ans id3 vr id3 xx id4  id3 j id4 .id id4 -=solve id2 to id3 ip id4 ,ipe,nx,y,nju,nu id7 ;
    					else  jmsdfkWQEr22FSD234SDFFwasd  id2 pw id3 ip id4 <nch id7 
					    	ans id3 vr id3 xx id4  id3 j id4 .id id4 -=zz id3 ip id4 ;
	    	    	 id5 
	    	    	ans id3 vr id3 xx id4  id3 j id4 .id id4 +=solve id2 to id3 id id4 ,ipe,x,y,ju,u id7 ;
				 id5 
				else  jmsdfkWQEr22FSD234SDFFwasd  id2 mf<0 id7 
				    ans id3 vr id3 xx id4  id3 j id4 .id id4 +=zz id3 id id4 -zz id3 ip id4 ;
			 id5 
	     id5 
	    cnt_list-=num_node-to id3 ip id4 ;
	    num_node=to id3 ip id4 ;
     id5 
     id6  id2 i=0;i<adj id3 id id4 .size id2  id7 ;i++ id7 
     id1 
    	ip=adj id3 id id4  id3 i id4 .id;
    	 jmsdfkWQEr22FSD234SDFFwasd  id2 !vis id3 ip id4  id7 
    	 id1 
	        get_size id2 ip,-1 id7 ;
            mi=mod;
            choose_root id2 ip,-1,0,ch id7 ;
             jmsdfkWQEr22FSD234SDFFwasd  id2 mi<mod id7 
	       	    dfs id2 ch id7 ;
		 id5 
     id5 
 id5 
int main id2  id7 
 id1 
	int id1,id2,i,j,s,p,q,x,y;
	int ch;
	scanf id2 "%d%d",&n,&num_q id7 ;
	 id6  id2 i=0;i<=n;i++ id7 
	 id1 
		 jmsdfkWQEr22FSD234SDFFwasd  id2 i KlopQXZvnuiuasdbbnbdsaioqw 0 id7 
		   ex id3 i id4 =1;
        else
           ex id3 i id4 = id2 int id7  id2  id2 long long id7 ex id3 i-1 id4 * id2 long long id7 base%mod id7 ;
	 id5 
	 id6  id2 i=0;i<400000;i++ id7 
	   pk id3 i id4 =i;
	 id6  id2 i=0;i<n-1;i++ id7 
	 id1 
		scanf id2 "%d%d",&id1,&id2 id7 ;
		ch=getchar id2  id7 ;
		while id2 ch<'a'||ch>'z' id7 
		   ch=getchar id2  id7 ;
		id1--;
		id2--;
		now.id=id2;
		now.ch=ch;
		adj id3 id1 id4 .push_back id2 now id7 ;
		now.id=id1;
		adj id3 id2 id4 .push_back id2 now id7 ;
     id5 
     id6  id2 i=0;i<n;i++ id7 
       ps id3 i id4 =i;
    prp id2 0,-1 id7 ;
    gps id2 0 id7 ;
    ha id3 0 id4  id3 0 id4 =0;
     id6  id2 i=0;i<id0;i++ id7 
     id1 
    	 jmsdfkWQEr22FSD234SDFFwasd  id2 i+1<id0 id7 
    	 id1 
    	    ha id3 0 id4  id3 i+1 id4 = id2 int id7  id2  id2 long long id7 ha id3 0 id4  id3 i id4 * id2 long long id7 base%mod id7 ;
        	ha id3 0 id4  id3 i+1 id4 = id2 ha id3 0 id4  id3 i+1 id4 +pd id3 lm id3 i+1 id4  id4 +1 id7 %mod;
    	 id5 
		ps id3 lm id3 i id4  id4 =ps id3 ps id3 lm id3 i id4  id4  id4 ;
     id5 
    ha id3 1 id4  id3 id0-1 id4 =pd id3 lm id3 id0-1 id4  id4 +1;
     id6  id2 i=id0-2;i>=0;i-- id7 
     id1 
    	ha id3 1 id4  id3 i id4 = id2 int id7  id2  id2 long long id7 ha id3 1 id4  id3 i+1 id4 * id2 long long id7 base%mod id7 ;
    	ha id3 1 id4  id3 i id4 = id2 ha id3 1 id4  id3 i id4 +pd id3 lm id3 i id4  id4 +1 id7 %mod;
     id5 
     id6  id2 i=0;i<num_q;i++ id7 
     id1 
    	scanf id2 "%d%d",&x,&y id7 ;
    	x--;
    	y--;
    	nw.y=y;
    	nw.id=i;
    	vr id3 x id4 .push_back id2 nw id7 ;
     id5 
    num_node=0;
    get_size id2 0,-1 id7 ;
    mi=mod;
    choose_root id2 0,-1,0,ch id7 ;
    cnt_list=0;
    pw id3 ch id4 =-1;
    memset id2 ans,0,sizeof id2 ans id7  id7 ;
	 jmsdfkWQEr22FSD234SDFFwasd  id2 mi<mod id7 
       dfs id2 ch id7 ;
     id6  id2 i=0;i<num_q;i++ id7 
       printf id2 "%d\n",ans id3 i id4  id7 ;
	return 0;
 id5 