
using namespace std;




















const long double PI = (long double)(3.1415926535897932384626433832795);
void change(int x, int y,string str[]) {
    if(str[x][y]=='0'){
        str[x][y]='1';
    }
    else {
        str[x][y]='0';
    }
}


int main() 
{
    fast;
    int test,n,c0,c1,h,i,j,k,m;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        string str[n];
        for(i=0;i<n;i++)
        {
            cin>>str[i];
        }
        vector<tuple<int,int,int,int,int,int>>res;
        for(i=0;i<n-2;i++)
        {
            for(j=0;j<m;j++)
            {
                if(str[i][j]=='1')
                {
                    if(j==m-1)
                    {
                        change(i,j,str);
                        change(i+1,j-1,str);
                        change(i+1,j,str);
                        res.pb(mt(i,j,i+1,j-1,i+1,j));
                    }
                    else
                    {
                        change(i,j,str);
                        change(i,j+1,str);
                        change(i+1,j,str);
                        res.pb(mt(i,j,i+1,j,i,j+1));
                    }
                }
            }
        }

        for(i=n-2;i<n;i++)
        {
            bool flag=false;
            for(j=0;j<m;j++)
            {
                if(str[i][j]=='1')
                {
                    flag=true;
                }
            }
            if(flag==false)
            {
                continue;
            }
            if(i==n-1)
            {
                for(j=0;j<m;j++)
                {
                    

                    if(j==m-1)
                    {
                        int c=0;
                        if(str[i][j]=='1')
                        {
                            c++;
                        }
                        if(str[i-1][j]=='1')
                        {
                            c++;
                        }
                        if(str[i][j-1]=='1')
                        {
                            c++;
                        }
                        if(str[i-1][j-1]=='1')
                        {
                            c++;
                        }
                        

                        if(c==4)
                        {
                            str[i][j]='0';
                            str[i-1][j]='0';
                            str[i][j-1]='0';
                            res.pb(mt(i,j,i-1,j,i,j-1));
                        }
                        else if(c==3)
                        {
                            if(str[i][j]=='0')
                            {  
                                res.pb(mt(i-1,j,i,j-1,i-1,j-1));
                            }
                            else if(str[i-1][j]=='0')
                            {
                                res.pb(mt(i,j,i,j-1,i-1,j-1));
                            }
                            else if(str[i][j-1]=='0')
                            {
                                res.pb(mt(i,j,i-1,j,i-1,j-1));
                            }
                            else
                            {
                                res.pb(mt(i,j,i-1,j,i,j-1));
                            }
                            str[i][j]='0';
                            str[i-1][j]='0';
                            str[i][j-1]='0';
                            str[i-1][j-1]='0';
 
                        }
                        else if(c==2)
                        {
                            if(str[i][j]=='1')
                            {
                                if(str[i-1][j]=='1')
                                {
                                    res.pb(mt(i,j,i,j-1,i-1,j-1));
                                    res.pb(mt(i-1,j,i,j-1,i-1,j-1));
                                }
                                else if(str[i][j-1]=='1')
                                {
                                    res.pb(mt(i,j,i-1,j,i-1,j-1));
                                    res.pb(mt(i,j-1,i-1,j,i-1,j-1));
                                }
                                else
                                {
                                    res.pb(mt(i,j,i-1,j,i,j-1));
                                    res.pb(mt(i-1,j-1,i,j-1,i-1,j));
                                }
                            }
                            else if(str[i-1][j]=='1')
                            {
                                if(str[i][j-1]=='1')
                                {
                                    res.pb(mt(i-1,j,i,j,i-1,j-1));
                                    res.pb(mt(i,j-1,i,j,i-1,j-1));
                                }
                                else
                                {
                                    res.pb(mt(i-1,j,i,j,i,j-1));
                                    res.pb(mt(i-1,j-1,i,j,i,j-1));
                                }
                            }
                            else
                            {
                                res.pb(mt(i,j-1,i,j,i-1,j));
                                res.pb(mt(i-1,j-1,i,j,i-1,j));
                            }
                            str[i][j]='0';
                            str[i-1][j]='0';
                            str[i][j-1]='0';
                            str[i-1][j-1]='0';
                        }
                        else if(c==1)
                        {
                            if(str[i][j]=='1')
                            {
                                res.pb(mt(i,j,i-1,j,i,j-1));
                                res.pb(mt(i-1,j,i,j,i-1,j-1));
                                res.pb(mt(i,j-1,i,j,i-1,j-1));
 
                            }
                            else if(str[i-1][j]=='1')
                            {
                                res.pb(mt(i-1,j,i,j,i-1,j-1));
                                res.pb(mt(i,j,i-1,j,i,j-1));
                                res.pb(mt(i-1,j-1,i,j-1,i-1,j));
 
                            }
                            else if(str[i][j-1]=='1')
                            {
                                res.pb(mt(i,j-1,i,j,i-1,j-1));
                                res.pb(mt(i,j,i-1,j,i,j-1));
                                res.pb(mt(i-1,j-1,i,j-1,i-1,j));
                            }
                            else
                            {
                                res.pb(mt(i-1,j-1,i,j-1,i-1,j));
                                res.pb(mt(i-1,j,i,j,i-1,j-1));
                                res.pb(mt(i,j-1,i,j,i-1,j-1));
                            }
                            str[i][j]='0';
                            str[i-1][j]='0';
                            str[i][j-1]='0';
                            str[i-1][j-1]='0';
                        }
                    }
                    else
                    {
                        int c=0;
                        if(str[i][j]=='1')
                        {
                            c++;
                        }
                        if(str[i-1][j]=='1')
                        {
                            c++;
                        }
                        if(str[i][j+1]=='1')
                        {
                            c++;
                        }
                        if(str[i-1][j+1]=='1')
                        {
                            c++;
                        }
                        

                        if(c==4)
                        {
                            str[i][j]='0';
                            str[i-1][j]='0';
                            str[i][j+1]='0';
                            res.pb(mt(i,j,i-1,j,i,j+1));
                        }
                        else if(c==3)
                        {
                            if(str[i][j]=='0')
                            {  
                                res.pb(mt(i-1,j,i,j+1,i-1,j+1));
                            }
                            else if(str[i-1][j]=='0')
                            {
                                res.pb(mt(i,j,i,j+1,i-1,j+1));
                            }
                            else if(str[i][j+1]=='0')
                            {
                                res.pb(mt(i,j,i-1,j,i-1,j+1));
                            }
                            else
                            {
                                res.pb(mt(i,j,i-1,j,i,j+1));
                            }
                            str[i][j]='0';
                            str[i-1][j]='0';
                            str[i][j+1]='0';
                            str[i-1][j+1]='0';
 
                        }
                        else if(c==2)
                        {
                            if(str[i][j]=='1')
                            {
                                if(str[i-1][j]=='1')
                                {
                                    res.pb(mt(i,j,i,j+1,i-1,j+1));
                                    res.pb(mt(i-1,j,i,j+1,i-1,j+1));
                                }
                                else if(str[i][j+1]=='1')
                                {
                                    res.pb(mt(i,j,i-1,j,i-1,j+1));
                                    res.pb(mt(i,j+1,i-1,j,i-1,j+1));
                                }
                                else
                                {
                                    res.pb(mt(i,j,i-1,j,i,j+1));
                                    res.pb(mt(i-1,j+1,i,j+1,i-1,j));
                                }
                            }
                            else if(str[i-1][j]=='1')
                            {
                                if(str[i][j+1]=='1')
                                {
                                    res.pb(mt(i-1,j,i,j,i-1,j+1));
                                    res.pb(mt(i,j+1,i,j,i-1,j+1));
                                }
                                else
                                {
                                    res.pb(mt(i-1,j,i,j,i,j+1));
                                    res.pb(mt(i-1,j+1,i,j,i,j+1));
                                }
                            }
                            else
                            {
                                res.pb(mt(i,j+1,i,j,i-1,j));
                                res.pb(mt(i-1,j+1,i,j,i-1,j));
                            }
                            str[i][j]='0';
                            str[i-1][j]='0';
                            str[i][j+1]='0';
                            str[i-1][j+1]='0';
                        }
                        else if(c==1)
                        {
                            if(str[i][j]=='1')
                            {
                                res.pb(mt(i,j,i-1,j,i,j+1));
                                res.pb(mt(i-1,j,i,j,i-1,j+1));
                                res.pb(mt(i,j+1,i,j,i-1,j+1));
 
                            }
                            else if(str[i-1][j]=='1')
                            {
                                res.pb(mt(i-1,j,i,j,i-1,j+1));
                                res.pb(mt(i,j,i-1,j,i,j+1));
                                res.pb(mt(i-1,j+1,i,j+1,i-1,j));
 
                            }
                            else if(str[i][j+1]=='1')
                            {
                                res.pb(mt(i,j+1,i,j,i-1,j+1));
                                res.pb(mt(i,j,i-1,j,i,j+1));
                                res.pb(mt(i-1,j+1,i,j+1,i-1,j));
                            }
                            else
                            {
                                res.pb(mt(i-1,j+1,i,j+1,i-1,j));
                                res.pb(mt(i-1,j,i,j,i-1,j+1));
                                res.pb(mt(i,j+1,i,j,i-1,j+1));
                            }
                            str[i][j]='0';
                            str[i-1][j]='0';
                            str[i][j+1]='0';
                            str[i-1][j+1]='0';
                        }
                    }
                }
            }
            else
            {
                for(j=0;j<m;j++)
                {
                    

                    if(j==m-1)
                    {
                        int c=0;
                        if(str[i][j]=='1')
                        {
                            c++;
                        }
                        if(str[i+1][j]=='1')
                        {
                            c++;
                        }
                        if(str[i][j-1]=='1')
                        {
                            c++;
                        }
                        if(str[i+1][j-1]=='1')
                        {
                            c++;
                        }
                        

                        if(c==4)
                        {
                            str[i][j]='0';
                            str[i+1][j]='0';
                            str[i][j-1]='0';
                            res.pb(mt(i,j,i+1,j,i,j-1));
                        }
                        else if(c==3)
                        {
                            if(str[i][j]=='0')
                            {  
                                res.pb(mt(i+1,j,i,j-1,i+1,j-1));
                            }
                            else if(str[i+1][j]=='0')
                            {
                                res.pb(mt(i,j,i,j-1,i+1,j-1));
                            }
                            else if(str[i][j-1]=='0')
                            {
                                res.pb(mt(i,j,i+1,j,i+1,j-1));
                            }
                            else
                            {
                                res.pb(mt(i,j,i+1,j,i,j-1));
                            }
                            str[i][j]='0';
                            str[i+1][j]='0';
                            str[i][j-1]='0';
                            str[i+1][j-1]='0';
 
                        }
                        else if(c==2)
                        {
                            if(str[i][j]=='1')
                            {
                                if(str[i+1][j]=='1')
                                {
                                    res.pb(mt(i,j,i,j-1,i+1,j-1));
                                    res.pb(mt(i+1,j,i,j-1,i+1,j-1));
                                }
                                else if(str[i][j-1]=='1')
                                {
                                    res.pb(mt(i,j,i+1,j,i+1,j-1));
                                    res.pb(mt(i,j-1,i+1,j,i+1,j-1));
                                }
                                else
                                {
                                    res.pb(mt(i,j,i+1,j,i,j-1));
                                    res.pb(mt(i+1,j-1,i,j-1,i+1,j));
                                }
                            }
                            else if(str[i+1][j]=='1')
                            {
                                if(str[i][j-1]=='1')
                                {
                                    res.pb(mt(i+1,j,i,j,i+1,j-1));
                                    res.pb(mt(i,j-1,i,j,i+1,j-1));
                                }
                                else
                                {
                                    res.pb(mt(i+1,j,i,j,i,j-1));
                                    res.pb(mt(i+1,j-1,i,j,i,j-1));
                                }
                            }
                            else
                            {
                                res.pb(mt(i,j-1,i,j,i+1,j));
                                res.pb(mt(i+1,j-1,i,j,i+1,j));
                            }
                            str[i][j]='0';
                            str[i+1][j]='0';
                            str[i][j-1]='0';
                            str[i+1][j-1]='0';
                        }
                        else if(c==1)
                        {
                            if(str[i][j]=='1')
                            {
                                res.pb(mt(i,j,i+1,j,i,j-1));
                                res.pb(mt(i+1,j,i,j,i+1,j-1));
                                res.pb(mt(i,j-1,i,j,i+1,j-1));
 
                            }
                            else if(str[i+1][j]=='1')
                            {
                                res.pb(mt(i+1,j,i,j,i+1,j-1));
                                res.pb(mt(i,j,i+1,j,i,j-1));
                                res.pb(mt(i+1,j-1,i,j-1,i+1,j));
 
                            }
                            else if(str[i][j-1]=='1')
                            {
                                res.pb(mt(i,j-1,i,j,i+1,j-1));
                                res.pb(mt(i,j,i+1,j,i,j-1));
                                res.pb(mt(i+1,j-1,i,j-1,i+1,j));
                            }
                            else
                            {
                                res.pb(mt(i+1,j-1,i,j-1,i+1,j));
                                res.pb(mt(i+1,j,i,j,i+1,j-1));
                                res.pb(mt(i,j-1,i,j,i+1,j-1));
                            }
                            str[i][j]='0';
                            str[i+1][j]='0';
                            str[i][j-1]='0';
                            str[i+1][j-1]='0';
                        }
                    }
                    else
                    {
                        int c=0;
                        if(str[i][j]=='1')
                        {
                            c++;
                        }
                        if(str[i+1][j]=='1')
                        {
                            c++;
                        }
                        if(str[i][j+1]=='1')
                        {
                            c++;
                        }
                        if(str[i+1][j+1]=='1')
                        {
                            c++;
                        }
                        

                        if(c==4)
                        {
                            str[i][j]='0';
                            str[i+1][j]='0';
                            str[i][j+1]='0';
                            res.pb(mt(i,j,i+1,j,i,j+1));
                        }
                        else if(c==3)
                        {
                            if(str[i][j]=='0')
                            {  
                                res.pb(mt(i+1,j,i,j+1,i+1,j+1));
                            }
                            else if(str[i+1][j]=='0')
                            {
                                res.pb(mt(i,j,i,j+1,i+1,j+1));
                            }
                            else if(str[i][j+1]=='0')
                            {
                                res.pb(mt(i,j,i+1,j,i+1,j+1));
                            }
                            else
                            {
                                res.pb(mt(i,j,i+1,j,i,j+1));
                            }
                            str[i][j]='0';
                            str[i+1][j]='0';
                            str[i][j+1]='0';
                            str[i+1][j+1]='0';
 
                        }
                        else if(c==2)
                        {
                            if(str[i][j]=='1')
                            {
                                if(str[i+1][j]=='1')
                                {
                                    res.pb(mt(i,j,i,j+1,i+1,j+1));
                                    res.pb(mt(i+1,j,i,j+1,i+1,j+1));
                                }
                                else if(str[i][j+1]=='1')
                                {
                                    res.pb(mt(i,j,i+1,j,i+1,j+1));
                                    res.pb(mt(i,j+1,i+1,j,i+1,j+1));
                                }
                                else
                                {
                                    res.pb(mt(i,j,i+1,j,i,j+1));
                                    res.pb(mt(i+1,j+1,i,j+1,i+1,j));
                                }
                                str[i][j]='0';
                                str[i+1][j]='0';
                                str[i][j+1]='0';
                                str[i+1][j+1]='0';
                            }
                            else if(str[i+1][j]=='1')
                            {
                                if(str[i][j+1]=='1')
                                {
                                    res.pb(mt(i+1,j,i,j,i+1,j+1));
                                    res.pb(mt(i,j+1,i,j,i+1,j+1));
                                }
                                else
                                {
                                    res.pb(mt(i+1,j,i,j,i,j+1));
                                    res.pb(mt(i+1,j+1,i,j,i,j+1));
                                }
                                str[i][j]='0';
                                str[i+1][j]='0';
                                str[i][j+1]='0';
                                str[i+1][j+1]='0';
                            }
                            else
                            {
                                res.pb(mt(i,j+1,i,j,i+1,j));
                                res.pb(mt(i+1,j+1,i,j,i+1,j));
                                str[i][j]='0';
                                str[i+1][j]='0';
                                str[i][j+1]='0';
                                str[i+1][j+1]='0';
                            }
                        }
                        else if(c==1)
                        {
                            if(str[i][j]=='1')
                            {
                                res.pb(mt(i,j,i+1,j,i,j+1));
                                res.pb(mt(i+1,j,i,j,i+1,j+1));
                                res.pb(mt(i,j+1,i,j,i+1,j+1));
 
                            }
                            else if(str[i+1][j]=='1')
                            {
                                res.pb(mt(i+1,j,i,j,i+1,j+1));
                                res.pb(mt(i,j,i+1,j,i,j+1));
                                res.pb(mt(i+1,j+1,i,j+1,i+1,j));
 
                            }
                            else if(str[i][j+1]=='1')
                            {
                                res.pb(mt(i,j+1,i,j,i+1,j+1));
                                res.pb(mt(i,j,i+1,j,i,j+1));
                                res.pb(mt(i+1,j+1,i,j+1,i+1,j));
                            }
                            else
                            {
                                res.pb(mt(i+1,j+1,i,j+1,i+1,j));
                                res.pb(mt(i+1,j,i,j,i+1,j+1));
                                res.pb(mt(i,j+1,i,j,i+1,j+1));
                            }
                            str[i][j]='0';
                            str[i+1][j]='0';
                            str[i][j+1]='0';
                            str[i+1][j+1]='0';
                        }
                    }
                }
            }
        }
        cout<<res.size()<<endl;
        for(auto it:res)
        {
            cout<<get<0>(it)+1<<" "<<get<1>(it)+1<<" "<<get<2>(it)+1<<" "<<get<3>(it)+1<<" "<<get<4>(it)+1<<" "<<get<5>(it)+1<<" "<<endl;
        }
    }
    return 0;
}


