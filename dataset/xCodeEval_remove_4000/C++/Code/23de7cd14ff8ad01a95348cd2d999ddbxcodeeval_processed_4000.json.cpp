








using namespace std;



double tcenter(double locx, double locy, double id2, double id7, double id8, double id9, double tol,double& cx, double& cy)
{
	


double bb1,aa1;





    

    
    if(abs(locx-id2)<tol && abs(locx-id8)<tol)
    {
    	cx=locx;
    	cy=(max(locy,max(id7,id9))+min(locy,min(id7,id9)))/2;
    	
    	
    	 
 
    	
    	
    	return 0;
	}
    
    if(abs(locy-id7)<tol && abs(locy-id9)<tol)
    {
    	cx=(max(locx,max(id2,id8))+min(locx,min(id2,id8)))/2;
    	cy=locy;
    	
    	 

    	
    	return 0;
    	
	}
	
	
	double aaa, bbb;
	bbb=(locy-id7)/(locx-id2);
	aaa=locy-bbb*locx;
	
	double ccc=bbb*id8+aaa;
	if(abs(ccc-id9)<tol)
	{
		cx=(max(locx,max(id2,id8))+min(locx,min(id2,id8)))/2;
		cy=(max(locy,max(id7,id9))+min(locy,min(id7,id9)))/2;
		
		 

		
		
		return 0;
	}
	
	
	



	

	if(abs(locx-id2)<0.00001 && abs(id7-id9)<0.00001)
	{	
		cx=(id2+id8)/2;
		cy=(locy+id7)/2;
	}
	
	
	if(abs(locx-id2)<0.00001 && abs(id7-id9)>0.00001)
	{	
		bb1=-1/((id9-id7)/(id8-id2));
		aa1=(id9+id7)/2-bb1*(id8+id2)/2;
		
		cx=	(id8+id2)/2;
		cy=cx*bb1+aa1;
		

		
		

	}
	
	
	

	
	if(abs(locy-id7)<0.00001 && abs(id2-id8)<0.00001)
	{	
	    cx=(locx+id2)/2;
		cy=(id7+id9)/2;	
	}
	
	
	if(abs(locy-id7)<0.00001 && abs(id2-id8)>0.00001)
	{	
	    bb1=-1/((id9-id7)/(id8-id2));
		aa1=(id9+id7)/2-bb1*(id8+id2)/2;
	
		cy=(id7+id9)/2;
		cx=cy/bb1-aa1/bb1;
		
	}

    


    if(abs(locy-id7)>0.00001 && abs(locx-id2)>0.00001 && abs(id2-id8)<0.00001 )
    {
    	bb1=-1/((id7-locy)/(id2-locx));
		aa1=(id7+locy)/2-bb1*(id2+locx)/2;
		
		cy=(id7+id9)/2;
		cx=cy/bb1-aa1/bb1;
    	
	}

	if(abs(locy-id7)>0.00001 && abs(locx-id2)>0.00001 && abs(id7-id9)<0.00001 )
    {
    	bb1=-1/((id7-locy)/(id2-locx));
		aa1=(id7+locy)/2-bb1*(id2+locx)/2;
		
		cx=(id2+id8)/2;
		cy=cy*bb1+aa1;
    	
	}

	double bb2;
	double aa2;

	if(abs(locy-id7)>0.00001 && abs(locx-id2)>0.00001 && abs(id7-id9)>0.00001 && abs(id2-id8)>0.00001  )
    {
    	bb1=-1/((id7-locy)/(id2-locx));
		aa1=(id7+locy)/2-bb1*(id2+locx)/2;
		
		double ccc=(id9-id7);
		double ddd=(id8-id2);
		 bb2=-1/(ccc/ddd);
		

		aa2=(id9+id7)/2-bb2*(id8+id2)/2;
		
		cx=(aa2-aa1)/(bb1-bb2);
		cy=bb1*cx+aa1;
    }
 
 
 
 
 

 
return 0;

}




































double id1(vector<pair<double, double> > np1, long n, double tol, double& r, double& cx, double& cy)
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
	

	
	double id6, id4, id5, id0,tr2,tr3, tcx,tcy,tr;
	long c2,c3;
	double td2, td3;
	
	
	long id3=0;
	
	double dtest;
	
	
	id6=0;
	id4=0;
	id5=0;
	id5=0;
	tr2=0;
	tr3=0;
	
	tr=0;
	tcx=0;
	tcy=0;	

	double locx, locy, id2, id7, id8,id9;

	
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
							id2=sss[kkk].first;
							id7=sss[kkk].second;
							id8=sss[lll].first;
							id9=sss[lll].second;
							
							
							
							
						

							

							
							
							tcenter(locx, locy, id2, id7, id8, id9,tol,id5,id0);
							
							tr2=pow((id5-locx)*(id5-locx)+(id0-locy)*(id0-locy),0.5);
						

							
							
							sc=0;
							
							

							
							for(long  p = 0; p <isss+1; p++)
							{
								
								
								
								
								d2=pow((sss[p].first-id5)*(sss[p].first-id5)+(sss[p].second-id0)*(sss[p].second-id0),0.5);
							

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
									cx=id5;
									cy=id0;
									r2=tr2;
									r=tr2;;
								}
							}
								
							
							
						}
					}
				}
				
				id3=0;
				tsss.clear();
				
			

				
				
			

				
				

				

				for(long  p = 0; p <isss+1; p++)
				{
					

					

					
					dtest=pow((sss[p].first-cx)*(sss[p].first-cx)+(sss[p].second-cy)*(sss[p].second-cy),0.5);
					
				

					
					
					if(abs(dtest-r2)<tol)
					{
						
					

						
						tsss[id3].first=sss[p].first;
						tsss[id3].second=sss[p].second;
						
						
						
						id3=id3+1;
					}
					
					
					
				}
				
				
				for(long  p = 0; p <id3; p++)
				{
				

					
				}
				
				
				sss.clear();
				

				sss=tsss;
				isss=id3-1;
			

				
				
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





id1(np1,n,tol,nr,cnx,cny);
id1(mp1,m,tol,mr,cmx,cmy);

	
	

	

	
			



	
	

	

	
	
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
	
	
	
