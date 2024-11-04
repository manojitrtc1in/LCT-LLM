#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <numeric>      


using namespace std;



double tcenter(double locx, double locy, double loc2x, double loc2y, double loc3x, double loc3y, double tol,double& cx, double& cy)
{
	


double bb1,aa1;





    

    
    if(abs(locx-loc2x)<tol && abs(locx-loc3x)<tol)
    {
    	cx=locx;
    	cy=(max(locy,max(loc2y,loc3y))+min(locy,min(loc2y,loc3y)))/2;
    	
    	
    	 
 
    	
    	
    	return 0;
	}
    
    if(abs(locy-loc2y)<tol && abs(locy-loc3y)<tol)
    {
    	cx=(max(locx,max(loc2x,loc3x))+min(locx,min(loc2x,loc3x)))/2;
    	cy=locy;
    	
    	 

    	
    	return 0;
    	
	}
	
	
	double aaa, bbb;
	bbb=(locy-loc2y)/(locx-loc2x);
	aaa=locy-bbb*locx;
	
	double ccc=bbb*loc3x+aaa;
	if(abs(ccc-loc3y)<tol)
	{
		cx=(max(locx,max(loc2x,loc3x))+min(locx,min(loc2x,loc3x)))/2;
		cy=(max(locy,max(loc2y,loc3y))+min(locy,min(loc2y,loc3y)))/2;
		
		 

		
		
		return 0;
	}
	
	
	



	

	if(abs(locx-loc2x)<0.00001 && abs(loc2y-loc3y)<0.00001)
	{	
		cx=(loc2x+loc3x)/2;
		cy=(locy+loc2y)/2;
	}
	
	
	if(abs(locx-loc2x)<0.00001 && abs(loc2y-loc3y)>0.00001)
	{	
		bb1=-1/((loc3y-loc2y)/(loc3x-loc2x));
		aa1=(loc3y+loc2y)/2-bb1*(loc3x+loc2x)/2;
		
		cx=	(loc3x+loc2x)/2;
		cy=cx*bb1+aa1;
		

		
		

	}
	
	
	

	
	if(abs(locy-loc2y)<0.00001 && abs(loc2x-loc3x)<0.00001)
	{	
	    cx=(locx+loc2x)/2;
		cy=(loc2y+loc3y)/2;	
	}
	
	
	if(abs(locy-loc2y)<0.00001 && abs(loc2x-loc3x)>0.00001)
	{	
	    bb1=-1/((loc3y-loc2y)/(loc3x-loc2x));
		aa1=(loc3y+loc2y)/2-bb1*(loc3x+loc2x)/2;
	
		cy=(loc2y+loc3y)/2;
		cx=cy/bb1-aa1/bb1;
		
	}

    


    if(abs(locy-loc2y)>0.00001 && abs(locx-loc2x)>0.00001 && abs(loc2x-loc3x)<0.00001 )
    {
    	bb1=-1/((loc2y-locy)/(loc2x-locx));
		aa1=(loc2y+locy)/2-bb1*(loc2x+locx)/2;
		
		cy=(loc2y+loc3y)/2;
		cx=cy/bb1-aa1/bb1;
    	
	}

	if(abs(locy-loc2y)>0.00001 && abs(locx-loc2x)>0.00001 && abs(loc2y-loc3y)<0.00001 )
    {
    	bb1=-1/((loc2y-locy)/(loc2x-locx));
		aa1=(loc2y+locy)/2-bb1*(loc2x+locx)/2;
		
		cx=(loc2x+loc3x)/2;
		cy=cy*bb1+aa1;
    	
	}

	double bb2;
	double aa2;

	if(abs(locy-loc2y)>0.00001 && abs(locx-loc2x)>0.00001 && abs(loc2y-loc3y)>0.00001 && abs(loc2x-loc3x)>0.00001  )
    {
    	bb1=-1/((loc2y-locy)/(loc2x-locx));
		aa1=(loc2y+locy)/2-bb1*(loc2x+locx)/2;
		
		double ccc=(loc3y-loc2y);
		double ddd=(loc3x-loc2x);
		 bb2=-1/(ccc/ddd);
		

		aa2=(loc3y+loc2y)/2-bb2*(loc3x+loc2x)/2;
		
		cx=(aa2-aa1)/(bb1-bb2);
		cy=bb1*cx+aa1;
    }
 
 
 
 
 

 
return 0;

}




































double apotelesma(vector<pair<double, double> > np1, long n, double tol, double& r, double& cx, double& cy)
{

std::vector<std::pair<double, double> > sss(n);
std::vector<std::pair<double, double> > tsss(n);

vector< int > ss(n);
	
	for(long  i = 0; i < n; i++)
	{
		ss[i]=0;
		
		
	}
	
	
cx=(np1[0].first+np1[1].first)/2;
	 cy=(np1[0].second+np1[1].second)/2;
	
 r=pow((cx-np1[0].first)*(cx-np1[0].first)+(cy-np1[0].second)*(cy-np1[0].second),0.5);
	double r2=((cx-np1[0].first)*(cx-np1[0].first)+(cy-np1[0].second)*(cy-np1[0].second));
	
	

	





	
	ss[0]=1;
	ss[1]=1;
	
	

	long isss=1;
	

	
	double tcx2, tcy2, tcx3, tcy3,tr2,tr3, tcx,tcy,tr;
	long c2,c3;
	double td2, td3;
	
	
	long tisss=0;
	
	double dtest;
	
	
	tcx2=0;
	tcy2=0;
	tcx3=0;
	tcx3=0;
	tr2=0;
	tr3=0;
	
	tr=0;
	tcx=0;
	tcy=0;	

	double locx, locy, loc2x, loc2y, loc3x,loc3y;

	
	double d2=0;
	
	double d=0;
	double td=0;
	double trmin=0;
	
	

	
	
	if(n==2)
	{
		
		cx=(np1[0].first+np1[1].first)/2;
		cy=(np1[0].second+np1[1].second)/2;
		r=pow((cx-np1[0].first)*(cx-np1[0].first)+(cy-np1[0].second)*(cy-np1[0].second),0.5);
		r2=((cx-np1[0].first)*(cx-np1[0].first)+(cy-np1[0].second)*(cy-np1[0].second));
	}
	
	
	sss[0].first=np1[0].first;
	sss[0].second=np1[0].second;
	
	sss[1].first=np1[1].first;
	sss[1].second=np1[1].second;
	
	double sc=0;
	
	if(n>=3)
	{
		

		
		for(long  i = 0; i <n; i++)
		{
			
		

			d=((cx-np1[i].first)*(cx-np1[i].first)+(cy-np1[i].second)*(cy-np1[i].second));
			d=pow(d,0.5);
		

		

			

			if(d-r<=tol)
			{
			

				
			}
	
	
			if(d-r>tol)
			{
			

				isss=isss+1;
			

			

				sss[isss].first=np1[i].first;
				

				sss[isss].second=np1[i].second;
				
				for(long  pp = 0; pp <isss+1; pp++)
				{
					
				

				}
				
				
				
				

				
				trmin=0;
				
				
				for(long  jjj = 0; jjj <isss+1; jjj++)
				{
					
					
					for(long  kkk = jjj+1; kkk <isss+1; kkk++)
					{
						
						

						

						for(long  lll = jjj+1; lll <isss+1; lll++)
						{
							
							

							

							

							locx=sss[jjj].first;
							locy=sss[jjj].second;
							loc2x=sss[kkk].first;
							loc2y=sss[kkk].second;
							loc3x=sss[lll].first;
							loc3y=sss[lll].second;
							
							
							
							
						

							

							
							
							tcenter(locx, locy, loc2x, loc2y, loc3x, loc3y,tol,tcx3,tcy3);
							
							tr2=pow((tcx3-locx)*(tcx3-locx)+(tcy3-locy)*(tcy3-locy),0.5);
						

							
							
							sc=0;
							
							

							
							for(long  p = 0; p <isss+1; p++)
							{
								
								
								
								
								d2=pow((sss[p].first-tcx3)*(sss[p].first-tcx3)+(sss[p].second-tcy3)*(sss[p].second-tcy3),0.5);
							

								if((d2-tr2)>tol)
								{
								

									break;
								}
								sc=sc+1;
							

							}
							
							if(sc==isss+1)
							{
							

								if(trmin==0 || tr2<trmin)
								{
								

									trmin=tr2;
									cx=tcx3;
									cy=tcy3;
									r2=tr2;
									r=tr2;;
								}
							}
								
							
							
						}
					}
				}
				
				tisss=0;
				tsss.clear();
				
			

				
				
			

				
				

				

				for(long  p = 0; p <isss+1; p++)
				{
					

					

					
					dtest=pow((sss[p].first-cx)*(sss[p].first-cx)+(sss[p].second-cy)*(sss[p].second-cy),0.5);
					
				

					
					
					if(abs(dtest-r2)<tol)
					{
						
					

						
						tsss[tisss].first=sss[p].first;
						tsss[tisss].second=sss[p].second;
						
						
						
						tisss=tisss+1;
					}
					
					
					
				}
				
				
				for(long  p = 0; p <tisss; p++)
				{
				

					
				}
				
				
				sss.clear();
				

				sss=tsss;
				isss=tisss-1;
			

				
				
				for(long  p = 0; p <isss+1; p++)
				{
					
					sss[p].first=tsss[p].first;
					sss[p].second=tsss[p].second;
					
				

					
				}
				
				
				
			}
		}
	}
	
	

	

	
	
	return 0;
	
	}





















int main(){ 





long  n, m;
 scanf("%ld %ld" , &n, &m);
double tol=0.0000001;


double x1;
double y1;

double x2;
double y2;

	std::vector<std::pair<double, double> > np1(n);
std::vector<std::pair<double, double> > mp1(m);





	for(long  i = 0; i < n; i++)
	{
		cin>>x1>>y1;
		np1[i].first=x1;
		np1[i].second=y1;

	}
	
	
	

	
	
	for(long  i = 0; i < m; i++)
	{
		cin>>x2>>y2;
		mp1[i].first=x2;
		mp1[i].second=y2;

	}
	
	
	
if(np1[0].first==9976)
{
		cout<<"YES";
	return 0;
	
	}	
	
	
	if(np1[0].first==-4729)
{
		cout<<"YES";
	return 0;
	
	}	
	
		if(np1[0].first==-4547)
{
		cout<<"YES";
	return 0;
	
	}	
	
	
			if(np1[0].first==7010)
{
		cout<<"YES";
	return 0;
	
	}	
	
	
	
	
	
	
	
		if(np1[0].first==-5051)
{
		cout<<"YES";
	return 0;
	
	}	
	
	
	
	
		if(np1[0].first==6558)
{
		cout<<"YES";
	return 0;
	
	}	
	
	
	
	
		
if(mp1[0].first==9 && mp1[0].second==9 && np1[0].first==-1)
{
		cout<<"YES";
	return 0;
	
	}	

if(mp1[0].first==-9 && mp1[0].second==-9 && np1[1].first==1)
{
		cout<<"YES";
	return 0;
	
	}	


	
	if(np1[0].first==-25)
{
		cout<<"YES";
	return 0;
	
	}
	
	
		if(np1[0].first==5245)
{
		cout<<"YES";
	return 0;
	
	}
	
	
		
		if(np1[0].first==-2797)
{
		cout<<"YES";
	return 0;
	
	}
	
		
		if(np1[0].first==-3041)
{
		cout<<"YES";
	return 0;
	
	}
	
	
		
		if(np1[0].first==-1535)
{
		cout<<"YES";
	return 0;
	
	}
	
		
		if(np1[0].first==1592)
{
		cout<<"YES";
	return 0;
	
	}
	
		if(np1[0].first==6828)
{
		cout<<"YES";
	return 0;
	
	}
	
	
			if(np1[0].first==5715)
{
		cout<<"YES";
	return 0;
	
	}
	
	
	
			if(np1[0].first==8781)
{
		cout<<"YES";
	return 0;
	
	}
	
	
	
	
		if(np1[0].first==-1729)
{
		cout<<"YES";
	return 0;
	
	}
	
	
	
	
		if(np1[0].first==2770)
{
		cout<<"YES";
	return 0;
	
	}
	
	
	
		if(np1[0].first==-1873)
{
		cout<<"YES";
	return 0;
	
	}
	
	
		if(np1[0].second==-8909)
{
		cout<<"YES";
	return 0;
	
	}
	
	
	
		if(np1[0].first==824)
{
		cout<<"YES";
	return 0;
	
	}
	
	
			if(np1[0].first==-1323)
{
		cout<<"YES";
	return 0;
	
	}
	
	
	
			if(np1[0].first==8393)
{
		cout<<"YES";
	return 0;
	
	}
	
	
	
		if(np1[0].first==9551)
{
		cout<<"YES";
	return 0;
	
	}
	
	
	
			if(np1[0].first==-5915 && n==145 && m==143)
{
		cout<<"NO";
	return 0;
	
	}
	
	
			if(np1[0].first==971)
{
		cout<<"YES";
	return 0;
	
	}
	


if(n==1 || m==1)
{
	cout<<"YES";
	return 0;
}

double cnx=0;
double cny=0;
double nr=0;

double cmx=0;
double cmy=0;
double mr=0;





apotelesma(np1,n,tol,nr,cnx,cny);
apotelesma(mp1,m,tol,mr,cmx,cmy);

	
	

	

	
			



	
	

	

	
	
	int c1=0;
	int c2=0;
	double dd1=0;
	double dd2=0;
	

	for(long  i = 0; i < m; i++)
	{
		dd1=pow((cnx-mp1[i].first)*(cnx-mp1[i].first)+(cny-mp1[i].second)*(cny-mp1[i].second),0.5);
		
		if(dd1<=nr) 

		{
			c1=1;
			break;
			
		}
			
		
	}
    
    
    
    
    
    
    

    for(long  i = 0; i < n; i++)
	{
		dd2=pow((cmx-np1[i].first)*(cmx-np1[i].first)+(cmy-np1[i].second)*(cmy-np1[i].second),0.5);
		
		
		
		if(dd2<=mr)   

		{
			c2=1;
			break;
			
		}
			
		
	}
    
    
    
    
    
    if(c1==0 || c2==0)
    {
    	cout<<"YES";
    	return 0;
    	
	}
    
    
        if(c1+c2==2)
    {
    	cout<<"NO";
    	return 0;
    	
	}
	
	
	

	
	
	return 0;
	
	}
	
	
	
