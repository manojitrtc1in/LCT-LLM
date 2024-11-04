#include <bits/stdc++.h>
#define ll long long
using namespace std;


bool is[3100][3100*2];
ll p[3100*3100*2];
ll r,n,c,x,y;

ll fnd(ll v)
{
          

          if(v == p[v])
                    return v;
          return p[v] = fnd(p[v]);
}

void un(ll a , ll b)
{
          ll u=fnd(a);
          ll v=fnd(b);
          if(v != u)
          {
                    if(rand() % 2)
                              swap(u , v);
                    p[u] = v;
          }
}







int main()
{
          

          cin>>r>>c>>n;
          if(r==1)
          {
                    if(n>=c)
                              cout<<n-1<<endl;
                    else
                              cout<<n<<endl;
                    return 0;
          }
          if(c==1)
          {
                    cout<<0<<endl;
                    return 0;
          }
          for(ll i=0;i<3010*3010*2;i++)
          {
                    p[i]=i;
          }
          

          ll kilk=n;
          for(ll i=0;i<n;i++)
          {
                    

                    cin>>x>>y;
                    ll f1(-1),f2(-2),f3(-3),f4(-4),f5(-5),f6(-6),f7(-7),f8(-8);
                    ll s1(-11),s2(-12),s3(-13),s4(-14),s5(-15),s6(-16),s7(-17),s8(-18);
                    bool isf1(0),isf2(0),isf3(0),isf4(0),isf5(0),isf6(0),isf7(0),isf8(0);
                    bool iss1(0),iss2(0),iss3(0),iss4(0),iss5(0),iss6(0),iss7(0),iss8(0);
                    
                   

                    if(is[x+1][y]) f1=fnd((x+1)*(2*c+2)+y+1), isf1=1 ;
                    

                    if(is[x-1][y]) f2=fnd((x-1)*(2*c+2)+y+1), isf2=1 ;
                    


                    if(is[x][(y-1 < 1) ? 2*c : (y-1>2*c) ? 1 : y-1]) f3=fnd((x)*(2*c+2)+((y-1 < 1) ? 2*c : (y-1>2*c) ? 1 : y-1)+1), isf3=1 ;
                    

                    if(is[x+1][((y-1 < 1) ? 2*c : (y-1>2*c) ? 1 : y-1)]) f4=fnd((x+1)*(2*c+2)+((y-1 < 1) ? 2*c : (y-1>2*c) ? 1 : y-1)+1), isf4=1 ;
                    

                    if(is[x-1][((y-1 < 1) ? 2*c : (y-1>2*c) ? 1 : y-1)]) f5=fnd((x-1)*(2*c+2)+((y-1 < 1) ? 2*c : (y-1>2*c) ? 1 : y-1)+1), isf5=1 ;
                    


                    if(is[x][((y+1 < 1) ? 2*c : (y+1>2*c) ? 1 : y+1)]) f6=fnd((x)*(2*c+2)+((y+1 < 1) ? 2*c : (y+1>2*c) ? 1 : y+1)+1), isf6=1 ;
                      

                    if(is[x+1][((y+1 < 1) ? 2*c : (y+1>2*c) ? 1 : y+1)]) f7=fnd((x+1)*(2*c+2)+((y+1 < 1) ? 2*c : (y+1>2*c) ? 1 : y+1)+1), isf7=1 ;
                     

                     if(is[x-1][((y+1 < 1) ? 2*c : (y+1>2*c) ? 1 : y+1)]) f8=fnd((x-1)*(2*c+2)+((y+1 < 1) ? 2*c : (y+1>2*c) ? 1 : y+1)+1), isf8=1 ;
                    

                    

		

                    
                    if(is[x+1][(y+c < 1) ? 2*c : (y+c>2*c) ? 1 : y+c]) s1=fnd((x+1)*(2*c+2)+((y+c < 1) ? 2*c : (y+c>2*c) ? 1 : y+c)+1), iss1=1 ;
                    

                    if(is[x-1][(y+c < 1) ? 2*c : (y+c>2*c) ? 1 : y+c]) s2=fnd((x-1)*(2*c+2)+((y+c < 1) ? 2*c : (y+c>2*c) ? 1 : y+c)+1), iss2=1 ;
                    


                    if(is[x][(y+c-1 < 1) ? 2*c : (y+c-1>2*c) ? 1 : y+c-1]) s3=fnd((x)*(2*c+2)+((y+c-1 < 1) ? 2*c : (y+c-1>2*c) ? 1 : y+c-1)+1), iss3=1 ;
                    

                    if(is[x+1][(y+c-1 < 1) ? 2*c : (y+c-1>2*c) ? 1 : y+c-1]) s4=fnd((x+1)*(2*c+2)+((y+c-1 < 1) ? 2*c : (y+c-1>2*c) ? 1 : y+c-1)+1), iss4=1 ;
                    

                    if(is[x-1][(y+c-1 < 1) ? 2*c : (y+c-1>2*c) ? 1 : y+c-1]) s5=fnd((x-1)*(2*c+2)+((y+c-1 < 1) ? 2*c : (y+c-1>2*c) ? 1 : y+c-1)+1) , iss5=1 ;

                    if(is[x][(y+c+1 < 1) ? 2*c : (y+c+1>2*c) ? 1 : y+c+1]) s6=fnd((x)*(2*c+2)+((y+c+1 < 1) ? 2*c : (y+c+1>2*c) ? 1 : y+c+1)+1), iss6=1 ;
                    

                    if(is[x+1][(y+c+1 < 1) ? 2*c : (y+c+1>2*c) ? 1 : y+c+1]) s7=fnd((x+1)*(2*c+2)+((y+c+1 < 1) ? 2*c : (y+c+1>2*c) ? 1 : y+c+1)+1), iss7=1 ;
                    

                    if(is[x-1][(y+c+1 < 1) ? 2*c : (y+c+1>2*c) ? 1 : y+c+1]) s8=fnd((x-1)*(2*c+2)+((y+c+1 < 1) ? 2*c : (y+c+1>2*c) ? 1 : y+c+1)+1), iss8=1 ;
                    


                    bool lzia=1;
                    

                    

                    if(isf1 && iss1 && f1==s1)
                              lzia=0;
                    if(isf1 && iss2 && f1==s2)
                              lzia=0;
                    if(isf1 && iss3 && f1==s3)
                              lzia=0;
                    if(isf1 && iss4 && f1==s4)
                              lzia=0;
                    if(isf1 && iss5 && f1==s5)
                              lzia=0;
                    if(isf1 && iss6 && f1==s6)
                              lzia=0;
                    if(isf1 && iss7 && f1==s7)
                              lzia=0;
                    if(isf1 && iss8 && f1==s8)
                              lzia=0;

                    if(isf2 && iss1 && f2==s1)
                              lzia=0;
                    if(isf2 && iss2 && f2==s2)
                              lzia=0;
                    if(isf2 && iss3 && f2==s3)
                              lzia=0;
                    if(isf2 && iss4 && f2==s4)
                              lzia=0;
                    if(isf2 && iss5 && f2==s5)
                              lzia=0;
                    if(isf2 && iss6 && f2==s6)
                              lzia=0;
                    if(isf2 && iss7 && f2==s7)
                              lzia=0;
                    if(isf2 && iss8 && f2==s8)
                              lzia=0;

                    if(isf3 && iss1 && f3==s1)
                              lzia=0;
                    if(isf3 && iss2 && f3==s2)
                              lzia=0;
                    if(isf3 && iss3 && f3==s3)
                              lzia=0;
                    if(isf3 && iss4 && f3==s4)
                              lzia=0;
                    if(isf3 && iss5 && f3==s5)
                              lzia=0;
                    if(isf3 && iss6 && f3==s6)
                              lzia=0;
                    if(isf3 && iss7 && f3==s7)
                              lzia=0;
                    if(isf3 && iss8 && f3==s8)
                              lzia=0;

                    if(isf4 && iss1 && f4==s1)
                              lzia=0;
                    if(isf4 && iss2 && f4==s2)
                              lzia=0;
                    if(isf4 && iss3 && f4==s3)
                              lzia=0;
                    if(isf4 && iss4 && f4==s4)
                              lzia=0;
                    if(isf4 && iss5 && f4==s5)
                              lzia=0;
                    if(isf4 && iss6 && f4==s6)
                              lzia=0;
                    if(isf4 && iss7 && f4==s7)
                              lzia=0;
                    if(isf4 && iss8 && f4==s8)
                              lzia=0;

                    if(isf5 && iss1 && f5==s1)
                              lzia=0;
                    if(isf5 && iss2 && f5==s2)
                              lzia=0;
                    if(isf5 && iss3 && f5==s3)
                              lzia=0;
                    if(isf5 && iss4 && f5==s4)
                              lzia=0;
                    if(isf5 && iss5 && f5==s5)
                              lzia=0;
                    if(isf5 && iss6 && f5==s6)
                              lzia=0;
                    if(isf5 && iss7 && f5==s7)
                              lzia=0;
                    if(isf5 && iss8 && f5==s8)
                              lzia=0;

                    if(isf6 && iss1 && f6==s1)
                              lzia=0;
                    if(isf6 && iss2 && f6==s2)
                              lzia=0;
                    if(isf6 && iss3 && f6==s3)
                              lzia=0;
                    if(isf6 && iss4 && f6==s4)
                              lzia=0;
                    if(isf6 && iss5 && f6==s5)
                              lzia=0;
                    if(isf6 && iss6 && f6==s6)
                              lzia=0;
                    if(isf6 && iss7 && f6==s7)
                              lzia=0;
                    if(isf6 && iss8 && f6==s8)
                              lzia=0;

                    if(isf7 && iss1 && f7==s1)
                              lzia=0;
                    if(isf7 && iss2 && f7==s2)
                              lzia=0;
                    if(isf7 && iss3 && f7==s3)
                              lzia=0;
                    if(isf7 && iss4 && f7==s4)
                              lzia=0;
                    if(isf7 && iss5 && f7==s5)
                              lzia=0;
                    if(isf7 && iss6 && f7==s6)
                              lzia=0;
                    if(isf7 && iss7 && f7==s7)
                              lzia=0;
                    if(isf7 && iss8 && f7==s8)
                              lzia=0;

                    if(isf8 && iss1 && f8==s1)
                              lzia=0;
                    if(isf8 && iss2 && f8==s2)
                              lzia=0;
                    if(isf8 && iss3 && f8==s3)
                              lzia=0;
                    if(isf8 && iss4 && f8==s4)
                              lzia=0;
                    if(isf8 && iss5 && f8==s5)
                              lzia=0;
                    if(isf8 && iss6 && f8==s6)
                              lzia=0;
                    if(isf8 && iss7 && f8==s7)
                              lzia=0;
                    if(isf8 && iss8 && f8==s8)
                              lzia=0;
                    

                    if(!lzia)
                    {
                              kilk--;
                    }
                    else
                    {
                              

                              is[x][y]=1;
                              is[x][(y+c < 1) ? 2*c : (y+c>2*c) ? 1 : y+c]=1;
                              ll f=fnd(x*(2*c+2)+y+1);
                              ll s=fnd(x*(2*c+2)+((y+c < 1) ? 2*c : (y+c>2*c) ? 1 : y+c)+1);
                              if(isf1)
                                        un(f,f1);
                              if(isf2)
                                        un(f,f2);
                              if(isf3)
                                        un(f,f3);
                              if(isf4)
                                        un(f,f4);
                              if(isf5)
                                        un(f,f5);
                              if(isf6)
                                        un(f,f6);
                              if(isf7)
                                        un(f,f7);
                              if(isf8)
                                        un(f,f8);

                              if(iss1)
                                        un(s,s1);
                              if(iss2)
                                        un(s,s2);
                              if(iss3)
                                        un(s,s3);
                              if(iss4)
                                        un(s,s4);
                              if(iss5)
                                        un(s,s5);
                              if(iss6)
                                        un(s,s6);
                              if(iss7)
                                        un(s,s7);
                              if(iss8)
                                        un(s,s8);
                    }
          }
          cout<<kilk;
          return 0;
}
