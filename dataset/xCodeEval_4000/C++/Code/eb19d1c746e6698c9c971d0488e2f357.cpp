#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ul unsigned long long
#define shady ios_base::sync_with_stdio(false);cin.tie(NULL);
void solve2()
{

    string name;
    cin>>name;
    if(name.size()==1)
    {
        if(name[0]=='0') {cout<<1<<"\n";return;}
        if(name[0]=='2') {cout<<0<<"\n";return;}
        if(name[0]=='1') {cout<<0<<"\n";return;}

    }
    
    int mn=INT_MAX;
    int c=0,sum=0;
    for(int i=0;i<name.size();i++)
    {
        if(name[i]=='0')
            sum+=1;
        else if(name[i]=='1'||name[i]=='2')
            sum+=0;
    }
    mn=min(mn,sum);
    bool f1=false,f2=false,f0=false;
    for(int i=0;i<name.size();i++)
    {
        if(name[i]=='0')f0=true;
        if(name[i]=='1') f1=true;
        if(name[i]=='2') f2=true;
    }
    if(f1&&f0==false)
       mn=min(mn,0);
    else if(f0&&f1==false)
        mn=min(mn,1);
    else if(f1&&f0&&f2==false)
        mn=min(mn,2);
    int s=0,c1=0,c2=0;

    for(int i=0;i<name.size();i++)
    {
        if(name[i]!=name[i+1])
        {
             if(name[i]=='0')
                s+=1;

           

              

            

             

        }
        

        

        
        

    }
    mn=min(mn,s);
    cout<<mn<<"\n";
}
void solve3()
{
    string n1,n2;
    cin>>n1>>n2;
    

    

    

    int i1=0,i2=0,c1=0,c2=0;
    if(n1.size()==n2.size())
    {
    while(i1<n1.size()&&i2<n2.size())
    {
        

       

           if(n1.substr(1)==n2)
           {
               c1++;
               n1.erase(n1.begin());
           }
           else if(n1==n2.substr(1))
           {
               c2++;
               n2.erase(n2.begin());
           }
           else if(n1.substr(1)==n2.substr(1))
           {
               c1++;
               c2++;
               n1.erase(n1.begin());
               n2.erase(n2.begin());
           }
           i1++;
           i2++;
       

        

    }
    }
    else
    {
        string mx;
        if(n1.size()>n2.size())mx=n1;
        else mx=n2;
        while(i1<n1.size()&&i2<n2.size())
        {

        }
    }
    

}
void solve4()
{
    string n1,n2;
    cin>>n1>>n2;
    sort(n1.begin(),n1.end());
    sort(n2.begin(),n2.end());
    if(n1==n2) cout<<"YES";
    else cout<<"NO";
}
void solve5()
{
    string n1,n2,n3;
    cin>>n1>>n2>>n3;
    string temp="";
    if(n1[1]=='<') temp+=n1[0];
    if(n2[1]=='<') temp+=n2[0];
    if(n3[1]=='<') temp+=n3[0];

}
void solve6()
{
    string name;
    cin>>name;
    int c0=0,c1=0;
    for(int i=0;i<name.size();i++)
    {
        if(name[i]=='1')
            c1++;
        else if(name[i]=='0')
            c0++;
    }
    if(c1==name.size()){cout<<0<<"\n";return;}
    if(c0==name.size()){cout<<1<<"\n";return;}
    if(c0>c1){cout<<2<<"\n";return;}
    else if(c1>=c0) {cout<<1<<"\n";return;}
}
int main()
{
     

     

    shady
    

    ll t;
    cin>>t;
    while(t--)
    solve2();
    return 0;
}



    
    

    

                

                

                

                


                

                

                
                

                
       
    

  



    
        
      
    
    
    

    

    

    

    

    

    
               

  
 































   

  

