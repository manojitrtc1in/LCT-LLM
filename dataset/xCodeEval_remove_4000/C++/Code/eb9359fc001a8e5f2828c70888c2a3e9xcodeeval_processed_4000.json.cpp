

int a[40][40] ,b[40][40] ,ta[40][40];
int ansx[1010000] ,ansy[1010000];
int za[1010] ,zb[1010];
int aaa[40][40] ,bbb[40][40] ,aaaa[40][40] ,bbbb[40][40];
int c[40][40];
int main(void)
{
    int n ,m ,i ,j ,j1 ,j2 ,nm ,j3 ,j4;
    int ans;
    int temp;
    int z;
    int x ,y;
    int aa ,bb;
    int nn ,mm;
        
    while (scanf("%d %d" ,&n ,&m)!=EOF)
    {
        for (i=1 ; i<=900 ; i++)
        {
            za[i]=0;
            zb[i]=0;    
        }
        for (j1=1 ; j1<=n ; j1++)
        {
            for (j2=1 ; j2<=m ; j2++)   
            {
                scanf("%d" ,&a[j1][j2]);
                aaaa[j1][j2]=aaa[j1][j2]=a[j1][j2];
                za[a[j1][j2]]++;
            }
        }
        for (j1=1 ; j1<=n ; j1++)
        {
            for (j2=1 ; j2<=m ; j2++)   
            {
                scanf("%d" ,&b[j1][j2]);
                bbbb[j1][j2]=bbb[j1][j2]=b[j1][j2];
                zb[b[j1][j2]]++;                
            }
        }       
        nm=0;
        if (n==1&&m==1)
        {
            ans=-1;
        }
        else if (n==1||m==1)
        {
            if (m==1)   
            {
                for (i=2 ; i<=n ; i++)  
                {
                    a[1][i]=a[i][1];
                    b[1][i]=b[i][1];                    
                }
                m=n;
                nm=1;
            }
            ans=-1;
            for (j1=1 ; j1<=m ; j1++)
            {
                for (j2=1 ; j2<j1 ; j2++)
                {
                    for (i=1 ; i<=m ; i++)  
                    {
                        ta[1][i]=a[1][i];
                    }
                    for (i=j1 ; i>j2 ; i--)
                    {
                        temp=ta[1][i];
                        ta[1][i]=ta[1][i-1];
                        ta[1][i-1]=temp;
                    }
                    z=1;
                    for (i=1 ; i<=m ; i++)
                    {
                        if (b[1][i]!=ta[1][i])
                        {
                            z=0;
                            break;  
                        }
                    }
                    if (z)
                    {
                        ans=0;
                        ansx[0]=1;
                        ansy[0]=j1;
                        for (i=j1-1 ; i>=j2 ; i--)
                        {
                            ++ans;
                            ansx[ans]=1;
                            ansy[ans]=i;
                        }
                        break;                      
                    }
                }
                if (ans<0)
                {
                    for (j2=j1+1 ; j2<=m ; j2++)
                    {
                        for (i=1 ; i<=m ; i++)  
                        {
                            ta[1][i]=a[1][i];
                        }                   
                        for (i=j1 ; i<j2 ; i++)
                        {
                            temp=ta[1][i];
                            ta[1][i]=ta[1][i+1];
                            ta[1][i+1]=temp;                        
                        }
                        z=1;
                        for (i=1 ; i<=m ; i++)
                        {
                            if (b[1][i]!=ta[1][i])
                            {
                                z=0;
                                break;  
                            }
                        }
                        if (z)
                        {
                            ans=0;
                            ansx[0]=1;
                            ansy[0]=j1;
                            for (i=j1+1 ; i<=j2 ; i++)
                            {
                                ++ans;
                                ansx[ans]=1;
                                ansy[ans]=i;
                            }
                            break;                                                  
                        }                   
                    }
                }
                if (ans>0)
                {
                    break;  
                }
            }
        }
        else
        {
            z=1;
            for (i=1 ; i<=900 ; i++)
            {
                if (za[i]!=zb[i])
                {
                    z=0;
                    break;  
                }
            }
            ans=-1;
            if (z)
            {
                z=0;
                bb=b[n][m];
                for (j1=1 ; j1<=n ; j1++)
                {
                    for (j2=1 ; j2<=m ; j2++)   
                    {
                        if (bb==a[j1][j2])
                        {
                            z=1;
                            break;  
                        }   
                    }
                    if (z)
                    {
                        break;
                    }
                }
                ans=0;          
                ansx[0]=j1;
                ansy[0]=j2;
                for (i=j2-1 ; i ; i--)
                {
                    temp=a[j1][i];
                    a[j1][i]=a[j1][i+1];
                    a[j1][i+1]=temp;
                    ++ans;
                    ansx[ans]=j1;
                    ansy[ans]=i;
                }
                for (i=j1-1 ; i ; i--)
                {
                    temp=a[i][1];
                    a[i][1]=a[i+1][1];
                    a[i+1][1]=temp;
                    ++ans;
                    ansx[ans]=i;
                    ansy[ans]=1;
                }       
                nn=n-2;     
                for (j1=1 ; j1<=nn ; j1++)
                {
                    for (j2=1 ; j2<m ; j2++)    
                    {
                        z=0;
                        bb=b[j1][j2];
                        for (j3=j1 ; j3<=n ; j3++)
                        {
                            if (j3==j1)
                            {
                                j4=j2+1;
                            }
                            else
                            {
                                j4=1;   
                            }
                            for (; j4<=m ; j4++)    
                            {
                                if (bb==a[j3][j4])
                                {
                                    z=1;
                                    break;  
                                }   
                            }
                            if (z)
                            {
                                break;
                            }
                        }   
                        if (!z)while (1);                                           
                        if (j3==j1)
                        {
                            c[j1][j2]=1;
                            for (i=j2+1 ; i<=j4 ; i++)
                            {
                                temp=a[j1][i];
                                a[j1][i]=a[j1][i-1];
                                a[j1][i-1]=temp;
                                ++ans;
                                ansx[ans]=j1;
                                ansy[ans]=i;
                            }                           
                        }
                        else if (j4==m)
                        {
                            c[j1][j2]=2;                            
                            for (i=j2+1 ; i<=m ; i++)
                            {
                                temp=a[j1][i];
                                a[j1][i]=a[j1][i-1];
                                a[j1][i-1]=temp;
                                ++ans;
                                ansx[ans]=j1;
                                ansy[ans]=i;
                            }           
                            for (i=j1+1 ; i<=j3 ; i++)
                            {
                                temp=a[i][m];
                                a[i][m]=a[i-1][m];
                                a[i-1][m]=temp;
                                ++ans;
                                ansx[ans]=i;
                                ansy[ans]=m;
                            }                           
                        }
                        else
                        {
                            c[j1][j2]=3;                            
                            for (i=j2+1 ; i<=m ; i++)
                            {
                                temp=a[j1][i];
                                a[j1][i]=a[j1][i-1];
                                a[j1][i-1]=temp;
                                ++ans;
                                ansx[ans]=j1;
                                ansy[ans]=i;
                            }           
                            for (i=j1+1 ; i<=j3 ; i++)
                            {
                                temp=a[i][m];
                                a[i][m]=a[i-1][m];
                                a[i-1][m]=temp;
                                ++ans;
                                ansx[ans]=i;
                                ansy[ans]=m;
                            }
                            for (i=m-1 ; i>=j4 ; i--)
                            {
                                temp=a[j3][i];
                                a[j3][i]=a[j3][i+1];
                                a[j3][i+1]=temp;
                                ++ans;
                                ansx[ans]=j3;
                                ansy[ans]=i;
                            }               
                            if (j3==n)
                            {
                                for (i=j4+1 ; i<m ; i++)
                                {
                                    temp=a[j3][i-1];
                                    a[j3][i-1]=a[j3-1][i];
                                    a[j3-1][i]=temp;
                                    temp=a[j3][i+1];
                                    a[j3][i+1]=a[j3-1][i];
                                    a[j3-1][i]=temp;                                
                                    temp=a[j3][i+1];
                                    a[j3][i+1]=a[j3][i];
                                    a[j3][i]=temp;                              
                                    ++ans;
                                    ansx[ans]=j3-1;
                                    ansy[ans]=i;
                                    ++ans;
                                    ansx[ans]=j3;
                                    ansy[ans]=i+1;
                                    ++ans;
                                    ansx[ans]=j3;
                                    ansy[ans]=i;
                                }                               
                            }
                            else
                            {
                                for (i=j4+1 ; i<m ; i++)
                                {
                                    temp=a[j3][i-1];
                                    a[j3][i-1]=a[j3+1][i];
                                    a[j3+1][i]=temp;
                                    temp=a[j3][i+1];
                                    a[j3][i+1]=a[j3+1][i];
                                    a[j3+1][i]=temp;                                
                                    temp=a[j3][i+1];
                                    a[j3][i+1]=a[j3][i];
                                    a[j3][i]=temp;                              
                                    ++ans;
                                    ansx[ans]=j3+1;
                                    ansy[ans]=i;
                                    ++ans;
                                    ansx[ans]=j3;
                                    ansy[ans]=i+1;
                                    ++ans;
                                    ansx[ans]=j3;
                                    ansy[ans]=i;
                                }       
                            }                   
                            temp=a[j3][m-1];
                            a[j3][m-1]=a[j3-1][m];
                            a[j3-1][m]=temp;
                            ++ans;
                            ansx[ans]=j3-1;
                            ansy[ans]=m;
                            temp=a[j3][m];
                            a[j3][m]=a[j3-1][m];
                            a[j3-1][m]=temp;
                            ++ans;
                            ansx[ans]=j3;
                            ansy[ans]=m;                            
                        }
                        if (j3!=j1)
                        {
                            for (i=j3-1 ; i>j1 ; i--)
                            {
                                temp=a[i+1][m];
                                a[i+1][m]=a[i][m-1];
                                a[i][m-1]=temp;
                                temp=a[i-1][m];
                                a[i-1][m]=a[i][m-1];
                                a[i][m-1]=temp;                             
                                temp=a[i-1][m];
                                a[i-1][m]=a[i][m];
                                a[i][m]=temp;
                                ++ans;
                                ansx[ans]=i;
                                ansy[ans]=m-1;
                                ++ans;
                                ansx[ans]=i-1;
                                ansy[ans]=m;
                                ++ans;
                                ansx[ans]=i;
                                ansy[ans]=m;
                            }               
                            temp=a[j1][m-1];
                            a[j1][m-1]=a[j1+1][m];
                            a[j1+1][m]=temp;
                            ++ans;
                            ansx[ans]=j1;
                            ansy[ans]=m-1;
                            temp=a[j1][m-1];
                            a[j1][m-1]=a[j1][m];
                            a[j1][m]=temp;
                            ++ans;
                            ansx[ans]=j1;
                            ansy[ans]=m;
                            j4=m;
                        }
                        for (i=j4-1 ; i>j2 ; i--)
                        {
                            temp=a[j1][i+1];
                            a[j1][i+1]=a[j1+1][i];
                            a[j1+1][i]=temp;
                            temp=a[j1][i-1];
                            a[j1][i-1]=a[j1+1][i];
                            a[j1+1][i]=temp;
                            temp=a[j1][i-1];
                            a[j1][i-1]=a[j1][i];
                            a[j1][i]=temp;
                            ++ans;
                            ansx[ans]=j1+1;
                            ansy[ans]=i;                            
                            ++ans;
                            ansx[ans]=j1;
                            ansy[ans]=i-1;                          
                            ++ans;
                            ansx[ans]=j1;
                            ansy[ans]=i;
                        }
                        
                        
                        if (a[j1][j2]!=b[j1][j2])                           
                        {
                            printf("%d %d" ,j1 ,j2);
                            for (j3=1 ; j3<=j1 ; j3++)
                            {
                                for (j4=1 ; j4<=m ; j4++)   
                                {
                                    printf("%d " ,c[j3][j4]);
                                }
                                printf("\n");
                            }
                            
                            
                            
                            return 0;
                        }
                    }
                    z=0;
                    bb=b[j1][j2];
                    for (j3=j1+1 ; j3<=n ; j3++)
                    {
                        for (j4=1 ; j4<=m ; j4++)   
                        {
                            if (bb==a[j3][j4])
                            {
                                z=1;
                                break;  
                            }   
                        }
                        if (z)
                        {
                            break;
                        }
                    }                       
                    if (j4==m)
                    {           
                        for (i=j1+1 ; i<=j3 ; i++)
                        {
                            temp=a[i][m];
                            a[i][m]=a[i-1][m];
                            a[i-1][m]=temp;
                            ++ans;
                            ansx[ans]=i;
                            ansy[ans]=m;
                        }                           
                    }
                    else
                    {           
                        for (i=j1+1 ; i<=j3 ; i++)
                        {
                            temp=a[i][m];
                            a[i][m]=a[i-1][m];
                            a[i-1][m]=temp;
                            ++ans;
                            ansx[ans]=i;
                            ansy[ans]=m;
                        }
                        for (i=m-1 ; i>=j4 ; i--)
                        {
                            temp=a[j3][i];
                            a[j3][i]=a[j3][i+1];
                            a[j3][i+1]=temp;
                            ++ans;
                            ansx[ans]=j3;
                            ansy[ans]=i;
                        }                                   
                        if (j3==n)
                        {
                            for (i=j4+1 ; i<m ; i++)
                            {
                                temp=a[j3][i-1];
                                a[j3][i-1]=a[j3-1][i];
                                a[j3-1][i]=temp;
                                temp=a[j3][i+1];
                                a[j3][i+1]=a[j3-1][i];
                                a[j3-1][i]=temp;                                
                                temp=a[j3][i+1];
                                a[j3][i+1]=a[j3][i];
                                a[j3][i]=temp;                              
                                ++ans;
                                ansx[ans]=j3-1;
                                ansy[ans]=i;
                                ++ans;
                                ansx[ans]=j3;
                                ansy[ans]=i+1;
                                ++ans;
                                ansx[ans]=j3;
                                ansy[ans]=i;
                            }                               
                        }
                        else
                        {
                            for (i=j4+1 ; i<m ; i++)
                            {
                                temp=a[j3][i-1];
                                a[j3][i-1]=a[j3+1][i];
                                a[j3+1][i]=temp;
                                temp=a[j3][i+1];
                                a[j3][i+1]=a[j3+1][i];
                                a[j3+1][i]=temp;                                
                                temp=a[j3][i+1];
                                a[j3][i+1]=a[j3][i];
                                a[j3][i]=temp;                              
                                ++ans;
                                ansx[ans]=j3+1;
                                ansy[ans]=i;
                                ++ans;
                                ansx[ans]=j3;
                                ansy[ans]=i+1;
                                ++ans;
                                ansx[ans]=j3;
                                ansy[ans]=i;
                            }       
                        }                                                                   
                        temp=a[j3][m-1];
                        a[j3][m-1]=a[j3-1][m];
                        a[j3-1][m]=temp;
                        ++ans;
                        ansx[ans]=j3-1;
                        ansy[ans]=m;
                        temp=a[j3][m];
                        a[j3][m]=a[j3-1][m];
                        a[j3-1][m]=temp;
                        ++ans;
                        ansx[ans]=j3;
                        ansy[ans]=m;                            
                    }
                    for (i=j3-1 ; i>j1 ; i--)
                    {
                        temp=a[i+1][m];
                        a[i+1][m]=a[i][m-1];
                        a[i][m-1]=temp;
                        temp=a[i-1][m];
                        a[i-1][m]=a[i][m-1];
                        a[i][m-1]=temp;                             
                        temp=a[i-1][m];
                        a[i-1][m]=a[i][m];
                        a[i][m]=temp;
                        ++ans;
                        ansx[ans]=i;
                        ansy[ans]=m-1;
                        ++ans;
                        ansx[ans]=i-1;
                        ansy[ans]=m;
                        ++ans;
                        ansx[ans]=i;
                        ansy[ans]=m;
                    }               
                    for (i=m-1 ; i ; i--)
                    {
                        temp=a[j1+1][i];
                        a[j1+1][i]=a[j1+1][i+1];
                        a[j1+1][i+1]=temp;
                        ++ans;
                        ansx[ans]=j1+1;
                        ansy[ans]=i;
                    }
                    
                    if (a[j1][j2]!=b[j1][j2])                           
                    {
                        printf("%d %d" ,j1 ,j2);
                        return 0;
                    }                   
                    
                }
                nn=n-1;
                
        j3=ansx[0];
        j4=ansy[0];
        for (i=1 ; i<=ans ; i++)
        {
            x=ansx[i];
            y=ansy[i];
            temp=aaaa[x][y];
            aaaa[x][y]=aaaa[j3][j4];
            aaaa[j3][j4]=temp;
            j3=x;
            j4=y;
        }
        z=0;
        for (j1=1 ; j1<nn ; j1++)
        {
            for (j2=1 ; j2<=m ; j2++)
            {
                if (aaaa[j1][j2]!=bbbb[j1][j2])
                {
                    z=1;
                    break;  
                }
            }
            if (z)
            {
                break;  
            }
        }
        if (z)
        {
            while (1);
        }
 
                

                mm=m-2;
                for (j2=1 ; j2<=mm ; j2++)
                {
                    bb=b[nn][j2];
                    if (bb==a[n][j2])
                    {
                        temp=a[n][j2];
                        a[n][j2]=a[nn][j2];
                        a[nn][j2]=temp;
                        ans++;
                        ansx[ans]=n;
                        ansy[ans]=j2;                       
                    }
                    else
                    {
                        for (j4=j2+1 ; j4<=m ; j4++)    
                        {
                            if (bb==a[nn][j4])
                            {
                                j3=nn;
                                break;  
                            }   
                            if (bb==a[n][j4])
                            {
                                j3=n;
                                break;  
                            }                           
                        }   
                        if (j3==nn)
                        {
                            for (i=j2+1 ; i<=j4 ; i++)
                            {
                                temp=a[nn][i];
                                a[nn][i]=a[nn][i-1];
                                a[nn][i-1]=temp;
                                ans++;
                                ansx[ans]=nn;
                                ansy[ans]=i;
                            }
                        }
                        else
                        {
                            for (i=j2+1 ; i<j4 ; i++)
                            {
                                temp=a[nn][i];
                                a[nn][i]=a[nn][i-1];
                                a[nn][i-1]=temp;
                                ans++;
                                ansx[ans]=nn;
                                ansy[ans]=i;
                            }                           
                            temp=a[n][j4];
                            a[n][j4]=a[nn][j4-1];
                            a[nn][j4-1]=temp;
                            ans++;
                            ansx[ans]=n;
                            ansy[ans]=j4;   
                            temp=a[n][j4];
                            a[n][j4]=a[nn][j4];
                            a[nn][j4]=temp;
                            ans++;
                            ansx[ans]=nn;
                            ansy[ans]=j4;                                                   
                        }
                        for (j4-- ; j4>j2 ; j4--)
                        {
                            temp=a[n][j4];
                            a[n][j4]=a[nn][j4+1];
                            a[nn][j4+1]=temp;
                            ans++;
                            ansx[ans]=n;
                            ansy[ans]=j4;                       
                            temp=a[n][j4];
                            a[n][j4]=a[nn][j4-1];
                            a[nn][j4-1]=temp;
                            ans++;
                            ansx[ans]=nn;
                            ansy[ans]=j4-1;                                                 
                            temp=a[nn][j4];
                            a[nn][j4]=a[nn][j4-1];
                            a[nn][j4-1]=temp;
                            ans++;
                            ansx[ans]=nn;
                            ansy[ans]=j4;                           
                        }
                        temp=a[n][j2];
                        a[n][j2]=a[nn][j2+1];
                        a[nn][j2+1]=temp;
                        ans++;
                        ansx[ans]=n;
                        ansy[ans]=j2;                       
                    }

                    bb=b[n][j2];
                    for (j4=j2+1 ; j4<=m ; j4++)    
                    {
                        if (bb==a[n][j4])
                        {
                            j3=n;
                            break;  
                        }   
                        if (bb==a[nn][j4])
                        {
                            j3=nn;
                            break;  
                        }                           
                    }   
                    if (j3==n)
                    {
                        for (i=j2+1 ; i<=j4 ; i++)
                        {
                            temp=a[n][i];
                            a[n][i]=a[n][i-1];
                            a[n][i-1]=temp;
                            ans++;
                            ansx[ans]=n;
                            ansy[ans]=i;
                        }
                    }
                    else
                    {
                        for (i=j2+1 ; i<j4 ; i++)
                        {
                            temp=a[n][i];
                            a[n][i]=a[n][i-1];
                            a[n][i-1]=temp;
                            ans++;
                            ansx[ans]=n;
                            ansy[ans]=i;
                        }                           
                        temp=a[nn][j4];
                        a[nn][j4]=a[n][j4-1];
                        a[n][j4-1]=temp;
                        ans++;
                        ansx[ans]=nn;
                        ansy[ans]=j4;   
                        temp=a[n][j4];
                        a[n][j4]=a[nn][j4];
                        a[nn][j4]=temp;
                        ans++;
                        ansx[ans]=n;
                        ansy[ans]=j4;                                                   
                    }
                    for (j4-- ; j4>j2 ; j4--)
                    {
                        temp=a[nn][j4];
                        a[nn][j4]=a[n][j4+1];
                        a[n][j4+1]=temp;
                        ans++;
                        ansx[ans]=nn;
                        ansy[ans]=j4;                       
                        temp=a[nn][j4];
                        a[nn][j4]=a[n][j4-1];
                        a[n][j4-1]=temp;
                        ans++;
                        ansx[ans]=n;
                        ansy[ans]=j4-1;                                                 
                        temp=a[n][j4];
                        a[n][j4]=a[n][j4-1];
                        a[n][j4-1]=temp;
                        ans++;
                        ansx[ans]=n;
                        ansy[ans]=j4;                           
                    }
                    temp=a[nn][j2+1];
                    a[nn][j2+1]=a[n][j2+1];
                    a[n][j2+1]=temp;
                    ans++;
                    ansx[ans]=nn;
                    ansy[ans]=j2+1;                                     
                }               
                mm=m-1;
                if (b[nn][mm]==a[nn][m])
                {
                    j1=nn;
                    j2=m;
                }
                else if (b[nn][mm]==a[n][mm])
                {
                    j1=n;
                    j2=mm;                  
                }
                else
                {
                    j1=n;
                    j2=m;                   
                }
                temp=a[nn][mm];
                a[nn][mm]=a[j1][j2];
                a[j1][j2]=temp;
                ans++;
                ansx[ans]=j1;
                ansy[ans]=j2;                   
                z=0;
                if (a[n][m]!=b[n][m])
                {
                    z=1;
                }
                else if (a[nn][m]!=b[nn][m])
                {
                    z=1;
                }
                else if (a[n][mm]!=b[n][mm])
                {
                    z=1;
                }
                while (z)
                {
                    if (j1==n&&j2==m)   
                    {
                        temp=a[n][m];
                        a[n][m]=a[n][mm];
                        a[n][mm]=temp;
                        ans++;
                        ansx[ans]=n;
                        ansy[ans]=mm;
                        j1=n;
                        j2=mm;
                    }
                    else if (j1==n)
                    {
                        temp=a[n][mm];
                        a[n][mm]=a[nn][m];
                        a[nn][m]=temp;
                        ans++;
                        ansx[ans]=nn;
                        ansy[ans]=m;                        
                        j1=nn;
                        j2=m;
                    }
                    else
                    {
                        temp=a[nn][m];
                        a[nn][m]=a[n][m];
                        a[n][m]=temp;
                        ans++;
                        ansx[ans]=n;
                        ansy[ans]=m;                        
                        j1=n;
                        j2=m;
                    }
                    z=0;
                    if (a[n][m]!=b[n][m])
                    {
                        z=1;
                    }
                    else if (a[nn][m]!=b[nn][m])
                    {
                        z=1;
                    }
                    else if (a[n][mm]!=b[n][mm])
                    {
                        z=1;
                    }                   
                }
            }
        }
        if (ans!=-1)
        {
            if (nm)
            {
                j4=ansx[0];
                j3=ansy[0];                 
            }
            else
            {
                j3=ansx[0];
                j4=ansy[0];
            }           
            for (i=1 ; i<=ans ; i++)
            {
                if (nm)
                {
                    y=ansx[i];
                    x=ansy[i];                  
                }
                else
                {
                    x=ansx[i];
                    y=ansy[i];
                }
                temp=aaa[x][y];
                aaa[x][y]=aaa[j3][j4];
                aaa[j3][j4]=temp;
                j3=x;
                j4=y;
            }
            z=0;
            for (j1=1 ; j1<=n ; j1++)
            {
                for (j2=1 ; j2<=m ; j2++)
                {
                    if (aaa[j1][j2]!=bbb[j1][j2])
                    {
                        z=1;
                        break;  
                    }
                }
                if (z)
                {
                    break;  
                }
            }
            if (z)
            {
                printf("%d\n" ,5/0);    
            }
        }
        printf("%d\n" ,ans);
        if (ans>1000000)while (1);
        if (nm)
        {
            for (i=0 ; i<=ans ; i++)
            {
                printf("%d %d\n" ,ansy[i] ,ansx[i]);
            }           
        }
        else
        {   
            for (i=0 ; i<=ans ; i++)
            {
                printf("%d %d\n" ,ansx[i] ,ansy[i]);
            }
        }
        printf("\n");
    }
    
    return 0;   
}



