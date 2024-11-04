#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;


#define oqCFIdX2BwKcxq3I8cbx6kx0gNmaKItwOY coxZNIqnyE
#define coHDPT6bAY8XSddPgsBzUw cout
#define aSdjjsdfWqeqw yZ3yELizRJiiakReINXgA
#define lkjnasdSDjnmasd PidsfASdujfsad
#define PSDfjnnsdfASDSAd aSdjjsdfWqeqw
#define coxZNIqnyE oHIyGU+xJ0A
#define mPaWZefs3KbtTN1 }
#define XKy4NFEi5GFLiWv5utLpUQ )
#define poosadASDncxvXX asduyyZXCasd
#define oHIyGU+xJ0A main
#define opdifnbqWdsadfasd sdfiuSDFnncsdf
#define asduyyZXCasd mPaWZefs3KbtTN1
#define ESc1vXwfPlGmWPCriQCgIg ==
#define SDFjhnmasdhASDdwq QMdrPbBfCWbF0RI9Q
#define oDsaiucsdfasd djuEqqwdsBpoeW
#define IISDfnmbasdsa SDOfdsjfnmdsf
#define yZ3yELizRJiiakReINXgA if
#define PidsfASdujfsad v7cHyzMXuR2vn5q9T2QXiw
#define DFDSFDS HXpsIvDoJrRWvPTw
#define rNM1bH6pKs (
#define djuEqqwdsBpoeW rDF0kO5nB7zyYKn7g7qS5g
#define asdoiuASDCCXASDWQ rNM1bH6pKs
#define POAsdSACXASXSA asdoiuASDCCXASDWQ
#define PSDIOFcdscdsSDFsdsf DSFkcassDCsax
#define v7cHyzMXuR2vn5q9T2QXiw {
#define pSDfjjqwdSDAFdsfd DFDSFDS
#define CEmTM1iTkyutkXDmYDCzxA [
#define DSFkcassDCsax XKy4NFEi5GFLiWv5utLpUQ
#define sdfiuSDFnncsdf CEmTM1iTkyutkXDmYDCzxA
#define PAsdsannmdwq SDFjhnmasdhASDdwq
#define SDOfdsjfnmdsf ESc1vXwfPlGmWPCriQCgIg
#define KSDfuhnbnsdf coHDPT6bAY8XSddPgsBzUw
#define HXpsIvDoJrRWvPTw int 
#define QMdrPbBfCWbF0RI9Q for
#define ASOIDnmbashdjhsd KSDfuhnbnsdf
#define rDF0kO5nB7zyYKn7g7qS5g ]
int cnt_list,pos sdfiuSDFnncsdf 20200 djuEqqwdsBpoeW ,pa sdfiuSDFnncsdf 20100 djuEqqwdsBpoeW ,len sdfiuSDFnncsdf 20100 djuEqqwdsBpoeW ,fs sdfiuSDFnncsdf 20100 djuEqqwdsBpoeW ,pc sdfiuSDFnncsdf 20100 djuEqqwdsBpoeW ,ls sdfiuSDFnncsdf 20100 djuEqqwdsBpoeW ,cnt_ls,tmp sdfiuSDFnncsdf 20100 djuEqqwdsBpoeW ,cnt,n,num_q;
struct pp
 PidsfASdujfsad 
	int id;
	char ch;
 asduyyZXCasd ;
vector<pp>adj sdfiuSDFnncsdf 20201 djuEqqwdsBpoeW ;
pp now;
void dfs asdoiuASDCCXASDWQ int id,int pr DSFkcassDCsax 
 PidsfASdujfsad 
	int i,j,s,p,q,ip;
	pos sdfiuSDFnncsdf id djuEqqwdsBpoeW =cnt_list++;
	pa sdfiuSDFnncsdf pos sdfiuSDFnncsdf id djuEqqwdsBpoeW  djuEqqwdsBpoeW =pr;
	 SDFjhnmasdhASDdwq  asdoiuASDCCXASDWQ i=0;i<adj sdfiuSDFnncsdf id djuEqqwdsBpoeW .size asdoiuASDCCXASDWQ  DSFkcassDCsax ;i++ DSFkcassDCsax 
	 PidsfASdujfsad 
		ip=adj sdfiuSDFnncsdf id djuEqqwdsBpoeW  sdfiuSDFnncsdf i djuEqqwdsBpoeW .id;
		 aSdjjsdfWqeqw  asdoiuASDCCXASDWQ pos sdfiuSDFnncsdf ip djuEqqwdsBpoeW >=0 DSFkcassDCsax 
		   continue;
        pc sdfiuSDFnncsdf cnt_list djuEqqwdsBpoeW =adj sdfiuSDFnncsdf id djuEqqwdsBpoeW  sdfiuSDFnncsdf i djuEqqwdsBpoeW .ch-'a';
        dfs asdoiuASDCCXASDWQ ip,pos sdfiuSDFnncsdf id djuEqqwdsBpoeW  DSFkcassDCsax ;
	 asduyyZXCasd 
 asduyyZXCasd 
int main asdoiuASDCCXASDWQ  DSFkcassDCsax 
 PidsfASdujfsad 
	int id1,id2,i,j,s,p,q,x,y,fg;
	char ch;
	scanf asdoiuASDCCXASDWQ "%d%d",&n,&num_q DSFkcassDCsax ;
	 SDFjhnmasdhASDdwq  asdoiuASDCCXASDWQ i=0;i<n-1;i++ DSFkcassDCsax 
	 PidsfASdujfsad 
		scanf asdoiuASDCCXASDWQ "%d%d",&id1,&id2 DSFkcassDCsax ;
		ch=getchar asdoiuASDCCXASDWQ  DSFkcassDCsax ;
		while asdoiuASDCCXASDWQ ch<'a'||ch>'z' DSFkcassDCsax 
		   ch=getchar asdoiuASDCCXASDWQ  DSFkcassDCsax ;
		id1--;
		id2--;
		now.id=id2;
		now.ch=ch;
		adj sdfiuSDFnncsdf id1 djuEqqwdsBpoeW .push_back asdoiuASDCCXASDWQ now DSFkcassDCsax ;
		now.id=id1;
		now.ch=ch;
		adj sdfiuSDFnncsdf id2 djuEqqwdsBpoeW .push_back asdoiuASDCCXASDWQ now DSFkcassDCsax ;
	 asduyyZXCasd 
    memset asdoiuASDCCXASDWQ pos,-1,sizeof asdoiuASDCCXASDWQ pos DSFkcassDCsax  DSFkcassDCsax ;
    dfs asdoiuASDCCXASDWQ 0,-1 DSFkcassDCsax ;
    while asdoiuASDCCXASDWQ num_q-- DSFkcassDCsax 
     PidsfASdujfsad 
    	scanf asdoiuASDCCXASDWQ "%d%d",&x,&y DSFkcassDCsax ;
    	x--;
    	y--;
 	    x=pos sdfiuSDFnncsdf x djuEqqwdsBpoeW ;
 	    y=pos sdfiuSDFnncsdf y djuEqqwdsBpoeW ; 
    	int u,v;
		u=x;
    	v=y;
    	cnt_ls=cnt=0;
    	while asdoiuASDCCXASDWQ u!=v DSFkcassDCsax 
    	 PidsfASdujfsad 
	    	 aSdjjsdfWqeqw  asdoiuASDCCXASDWQ u>v DSFkcassDCsax 
	    	 PidsfASdujfsad 
	    		ls sdfiuSDFnncsdf cnt_ls++ djuEqqwdsBpoeW =pc sdfiuSDFnncsdf u djuEqqwdsBpoeW ;
	    		u=pa sdfiuSDFnncsdf u djuEqqwdsBpoeW ;
	    	 asduyyZXCasd 
	    	else
	    	 PidsfASdujfsad 
	    		tmp sdfiuSDFnncsdf cnt++ djuEqqwdsBpoeW =pc sdfiuSDFnncsdf v djuEqqwdsBpoeW ;
	    		v=pa sdfiuSDFnncsdf v djuEqqwdsBpoeW ;
	    	 asduyyZXCasd 
	     asduyyZXCasd 
	    while asdoiuASDCCXASDWQ cnt>0 DSFkcassDCsax 
    		ls sdfiuSDFnncsdf cnt_ls++ djuEqqwdsBpoeW =tmp sdfiuSDFnncsdf --cnt djuEqqwdsBpoeW ;
		 SDFjhnmasdhASDdwq  asdoiuASDCCXASDWQ i=0;i<n;i++ DSFkcassDCsax 
    	   len sdfiuSDFnncsdf i djuEqqwdsBpoeW =-1;
 	    u=x;
 	    fs sdfiuSDFnncsdf u djuEqqwdsBpoeW =len sdfiuSDFnncsdf u djuEqqwdsBpoeW =0;
	    int ans=0;
		while asdoiuASDCCXASDWQ u!=0 DSFkcassDCsax 
 	     PidsfASdujfsad 
 	    	len sdfiuSDFnncsdf pa sdfiuSDFnncsdf u djuEqqwdsBpoeW  djuEqqwdsBpoeW =len sdfiuSDFnncsdf u djuEqqwdsBpoeW +1;
	    	 aSdjjsdfWqeqw  asdoiuASDCCXASDWQ fs sdfiuSDFnncsdf u djuEqqwdsBpoeW  SDOfdsjfnmdsf 0 DSFkcassDCsax 
	    	 PidsfASdujfsad 
	    		 aSdjjsdfWqeqw  asdoiuASDCCXASDWQ len sdfiuSDFnncsdf u djuEqqwdsBpoeW <cnt_ls DSFkcassDCsax 
	    		 PidsfASdujfsad 
		    		 aSdjjsdfWqeqw  asdoiuASDCCXASDWQ ls sdfiuSDFnncsdf len sdfiuSDFnncsdf u djuEqqwdsBpoeW  djuEqqwdsBpoeW >pc sdfiuSDFnncsdf u djuEqqwdsBpoeW  DSFkcassDCsax 
		    		   fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf u djuEqqwdsBpoeW  djuEqqwdsBpoeW =-1;
   		            else  aSdjjsdfWqeqw  asdoiuASDCCXASDWQ ls sdfiuSDFnncsdf len sdfiuSDFnncsdf u djuEqqwdsBpoeW  djuEqqwdsBpoeW <pc sdfiuSDFnncsdf u djuEqqwdsBpoeW  DSFkcassDCsax 
   		               fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf u djuEqqwdsBpoeW  djuEqqwdsBpoeW =1;
                    else
                       fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf u djuEqqwdsBpoeW  djuEqqwdsBpoeW =0;
		    	 asduyyZXCasd 
		    	else
		    	    fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf u djuEqqwdsBpoeW  djuEqqwdsBpoeW =1;
	    	 asduyyZXCasd 
	    	else
	    	   fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf u djuEqqwdsBpoeW  djuEqqwdsBpoeW =fs sdfiuSDFnncsdf u djuEqqwdsBpoeW ;
  	         aSdjjsdfWqeqw  asdoiuASDCCXASDWQ fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf u djuEqqwdsBpoeW  djuEqqwdsBpoeW <0|| asdoiuASDCCXASDWQ fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf u djuEqqwdsBpoeW  djuEqqwdsBpoeW  SDOfdsjfnmdsf 0&&len sdfiuSDFnncsdf pa sdfiuSDFnncsdf u djuEqqwdsBpoeW  djuEqqwdsBpoeW !=cnt_ls DSFkcassDCsax  DSFkcassDCsax 
  	             ans++;
   	        u=pa sdfiuSDFnncsdf u djuEqqwdsBpoeW ;
	    asduyyZXCasd 
	    SDFjhnmasdhASDdwq  asdoiuASDCCXASDWQ i=1;i<n;i++ DSFkcassDCsax 
	    PidsfASdujfsad 
   		    aSdjjsdfWqeqw  asdoiuASDCCXASDWQ len sdfiuSDFnncsdf pa sdfiuSDFnncsdf i djuEqqwdsBpoeW  djuEqqwdsBpoeW >=0&&len sdfiuSDFnncsdf i djuEqqwdsBpoeW <0 DSFkcassDCsax 
   		    PidsfASdujfsad 
   		   	    len sdfiuSDFnncsdf i djuEqqwdsBpoeW =len sdfiuSDFnncsdf pa sdfiuSDFnncsdf i djuEqqwdsBpoeW  djuEqqwdsBpoeW +1;
   		   	     aSdjjsdfWqeqw  asdoiuASDCCXASDWQ fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf i djuEqqwdsBpoeW  djuEqqwdsBpoeW  SDOfdsjfnmdsf 0 DSFkcassDCsax 
   		   	     PidsfASdujfsad 
   		   	    	 aSdjjsdfWqeqw  asdoiuASDCCXASDWQ len sdfiuSDFnncsdf pa sdfiuSDFnncsdf i djuEqqwdsBpoeW  djuEqqwdsBpoeW <cnt_ls DSFkcassDCsax 
   		   	    	 PidsfASdujfsad 
    	   		   	    aSdjjsdfWqeqw  asdoiuASDCCXASDWQ ls sdfiuSDFnncsdf len sdfiuSDFnncsdf pa sdfiuSDFnncsdf i djuEqqwdsBpoeW  djuEqqwdsBpoeW  djuEqqwdsBpoeW >pc sdfiuSDFnncsdf i djuEqqwdsBpoeW  DSFkcassDCsax 
    	   		   	       fs sdfiuSDFnncsdf i djuEqqwdsBpoeW =-1;
	   		   	       else  aSdjjsdfWqeqw  asdoiuASDCCXASDWQ ls sdfiuSDFnncsdf len sdfiuSDFnncsdf pa sdfiuSDFnncsdf i djuEqqwdsBpoeW  djuEqqwdsBpoeW  djuEqqwdsBpoeW <pc sdfiuSDFnncsdf i djuEqqwdsBpoeW  DSFkcassDCsax 
	   		   	           fs sdfiuSDFnncsdf i djuEqqwdsBpoeW =1;
		   	           else
		   	               fs sdfiuSDFnncsdf i djuEqqwdsBpoeW =0;
   		   	    	 asduyyZXCasd 
   		   	    	else
   		   	    	   fs sdfiuSDFnncsdf i djuEqqwdsBpoeW =1;
				 asduyyZXCasd 
				else
				    fs sdfiuSDFnncsdf i djuEqqwdsBpoeW =fs sdfiuSDFnncsdf pa sdfiuSDFnncsdf i djuEqqwdsBpoeW  djuEqqwdsBpoeW ;
                 aSdjjsdfWqeqw  asdoiuASDCCXASDWQ fs sdfiuSDFnncsdf i djuEqqwdsBpoeW <0|| asdoiuASDCCXASDWQ fs sdfiuSDFnncsdf i djuEqqwdsBpoeW  SDOfdsjfnmdsf 0&&len sdfiuSDFnncsdf i djuEqqwdsBpoeW !=cnt_ls DSFkcassDCsax  DSFkcassDCsax 
                    ans++;
   		    asduyyZXCasd 
   	    asduyyZXCasd 
   	   printf asdoiuASDCCXASDWQ "%d\n",ans DSFkcassDCsax ;
     asduyyZXCasd 
	return 0;
 asduyyZXCasd 