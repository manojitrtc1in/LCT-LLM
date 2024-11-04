

#include<bits/stdc++.h>
using namespace std;
int main()
{
    char input[100005];
    int n[100005];
    cin>>input;
    int len=strlen(input);

    for(int i=0;i<len;i++)n[i]=input[i]-'0';

    

    

    

    

    

    

    int sum[len];
    memset(sum,0,sizeof(sum));
    int flag=0;
    

    

    

    

    if(n[0]==1 && n[len-1]!=1)
    {
        

        


        flag=2;
    }
    else if(n[0]==1 && n[len-1]==1)
        flag=3; 

    else
        flag=1;

    

    


    if(flag==3)
    {
        

        

        

        int carryL=0; 

        int carryR=0; 

        int L=0,R=len-1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
        sum[R+1]=1;
        while(L<=R)
        {
            if(n[L]==n[R])
            {
                if(carryL==0)
                {
                   if(carryR==0)
                    {
                        sum[R]=n[R];

                        carryL=0;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }


                        R--;
                    }
                   else
                    {
                        sum[R]=n[R]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }
                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                }
                else
                {

                    if(carryR==0)
                    {
                        if(n[R]==0)
                        {
                        cout<<0<<endl;
                        return 0;
                        }
                        sum[R]=n[R]-1;
                        carryR=1;
                        carryL=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                   else
                    {
                        sum[R]=n[R]+9;
                        carryL=1;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                }
            }
            else if(n[L]<n[R] )
            {
                if(n[R]-n[L]>1 && !(n[R]-n[L]==9 && carryR==1))
                {
                    cout<<"0"<<endl;
                    return 0;
                }
                else if(carryL==1)
                {
                    if(carryR==0)
                    {
                        sum[R]=n[L];

                        carryL=0;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                    else if(carryR==1)
                    {
                        sum[R]=n[L]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }

                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                }
                else
                {

                    if(n[R]-n[L]==9 && carryR==1)
                    {
                        sum[R]=9;

                        carryL=0;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;

                    }
                    else
                    {
                    

                    flag=2;
                    carryR=0;
                    carryL=1;
                    memset(sum,0,sizeof(sum));
                    break;
                    }

                }
            }
            else 

            {
                if(n[L]-n[R]>1 && !(n[L]-n[R]==9 && carryL==1))
                {
                    cout<<0<<endl;
                    return 0;
                }
                else if(carryL==0)
                {
                   if(carryR==0)
                   {
                        sum[R]=n[R];

                        carryL=0;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                   }
                   else
                   {
                        sum[R]=n[R]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }

                        carryL=1;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                   }
                }
                else if(carryL==1)
                {
                     if(n[L]-n[R]==9 )
                    {
                        sum[R]=9;

                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;

                    }
                    else
                    {
                    

                    flag=2;
                    carryR=0;
                    carryL=1;
                    memset(sum,0,sizeof(sum));
                    break;
                    }

                }

            }
        }
    }

    

    

    if(flag==2)
    {
        

        int L=1;
        int R=len-1;

        int carryL=1;
        int carryR;
        if(n[L]==n[R])
            {
                carryR=0;
                sum[R]=10+n[L];
            }
        else if (n[L]>n[R])
            {
                if(n[L]-n[R]>1 && !(n[L]-n[R]==9 && carryL==1))
                {
                    cout<<0<<endl;
                    return 0;
                }
                else
                {
                    carryR=1;
                    sum[R]=10+n[R];
                    if(n[L]-n[R]>1)
                {
                    cout<<"0";
                    return 0;
                }
                }
            }
        else
        {
            cout<<0<<endl;
            return 0;
        }
        if(++L == R)
        {
            if(carryL==carryR)
                L--;
            else
            {
                cout<<0<<endl;
                return 0;
            }
        }

        R--;
        while(L<=R)
        {
            if(n[L]==n[R])
            {
                if(carryL==0)
                {
                   if(carryR==0)
                    {

                        sum[R]=n[R];
                        carryL=0;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                   else
                    {
                        sum[R]=n[R]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }
                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                }
                else
                {
                    if(carryR==0)
                    {
                        if(n[R]==0)
                        {
                        cout<<0<<endl;
                        return 0;
                        }
                        sum[R]=n[R]-1;
                        carryR=1;
                        carryL=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                   else
                    {
                        sum[R]=n[R]+9;
                        carryL=1;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                }
            }
            else if(n[L]<n[R])
            {
                if(n[R]-n[L]>1 && !(n[R]-n[L]==9 && carryR==1))
                {
                    cout<<0<<endl;
                }
                else if(carryL==1)
                {
                    if(carryR==0)
                    {
                        sum[R]=n[L];

                        carryL=0;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                    else if(carryR==1)
                    {
                        sum[R]=n[L]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }

                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                }
                else
                {
                    if(n[R]-n[L]==9 && carryR==1)
                    {
                        sum[R]=9;

                        carryL=0;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;

                    }
                    else
                    {
                        cout<<'0'<<endl;
                        return 0;
                    }
                }
            }
            else 

            {
                if(n[L]-n[R]>1 && !(n[L]-n[R]==9 && carryL==1))
                {
                    cout<<0<<endl;
                    return 0;
                }
                if(carryL==0)
                {
                   if(carryR==0)
                   {
                        sum[R]=n[R];

                        carryL=0;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                   }
                   else
                   {
                        sum[R]=n[R]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }

                        carryL=1;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                   }
                }
                else if(carryL==1)
                {
                     if(n[L]-n[R]==9 )
                    {
                        sum[R]=9;

                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;

                    }
                    else
                    {
                        cout<<'0'<<endl;
                        return 0;
                    }
                }

            }
        }


    }
    else if(flag==1)
    {
      

      int carryL=0;
      int carryR;
      int L=0;
      int R=len-1;
      if(n[L]==n[R])
      {
        carryR=0;
        sum[R]=n[L];
      }
      else if(n[L]>n[R])
      {
        if(n[L]-n[R]>1 && !(n[L]-n[R]==9 && carryL==1))
            {
                cout<<"0"<<endl;
                return 0;
            }
        carryR=1;
        sum[R]=n[R];

      }
      else
      {
        cout<<'0'<<endl;
        return 0;
      }
        if(++L == R)
        {
            if(carryL==carryR)
                L--;
            else
            {
                cout<<0<<endl;
                return 0;
            }
        }

      R--;
        while(L<=R)
        {
            if(n[L]==n[R])
            {
                if(carryL==0)
                {
                   if(carryR==0)
                    {
                        sum[R]=n[R];

                        carryL=0;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                   else
                    {
                        sum[R]=n[R]+10;

                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }

                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                }
                else
                {

                    if(carryR==0)
                    {
                        if(n[R]==0)
                        {
                        cout<<0<<endl;
                        return 0;
                        }
                        sum[R]=n[R]-1;
                        carryR=1;
                        carryL=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                   else
                    {
                        sum[R]=n[R]+9;
                        carryL=1;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                }
            }
            else if(n[L]<n[R])
            {

                if(n[R]-n[L]>1 && !(n[R]-n[L]==9 && carryR==1))
                {
                    cout<<0<<endl;
                    return 0;
                }
                else if(carryL==1)
                {
                    if(carryR==0)
                    {
                        sum[R]=n[L];

                        carryL=0;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                    else if(carryR==1)
                    {
                        sum[R]=n[L]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }
                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;

                    }
                }
                else
                {
                    

                    

                    

                    

                    

                    if(n[R]-n[L]==9 && carryR==1)
                    {
                        sum[R]=9;

                        carryL=0;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;

                    }
                    else
                    {
                        cout<<'0'<<endl;
                        return 0;
                    }
                }
            }
            else 

            {
                if(n[L]-n[R]>1 && !(n[L]-n[R]==9 && carryL==1))
                {
                    cout<<0<<endl;
                    return 0;
                }
                else if(carryL==0)
                {
                   if(carryR==0)
                   {
                        sum[R]=n[R];

                        carryL=0;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                   }
                   else
                   {
                        sum[R]=n[R]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }

                        carryL=1;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                   }
                }
                else if(carryL==1)
                {
                   if(n[L]-n[R]==9 )
                    {
                        sum[R]=9;

                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;

                    }
                    else
                    {
                        cout<<'0'<<endl;
                        return 0;
                    }
                }

            }
        }
    }


    

    

    


    if(flag==1 || flag==3)
    {
        int aLength=len;
        int L=0;
        int R=len-1;
        

        

        

        

        if(aLength%2!=0 && sum[int(aLength/2)]%2!=0)
            {
                cout<<'0'<<endl;
                return 0;
            }

        int answer[len];
        while(L<=R)
        {
            sum[L]=sum[R];
            if(sum[L]%2==0)
                answer[L]=answer[R]=sum[L]/2;
            else
            {
                answer[R]=sum[L]/2;
                answer[L]=answer[R]+1;
            }
            L++;
            R--;
        }
        for(int i=0;i<len;i++)
            cout<<answer[i];



    }
    else
    {
        int aLength=len-1;
        int L=1;
        int R=aLength;
        if(aLength%2!=0 && sum[(aLength+1)/2]%2!=0)
           {
            cout<<'0'<<endl;
            return 0;
           }

        int answer[len];
        while(L<=R)
        {
            sum[L]=sum[R];
            if(sum[L]%2==0)
                answer[L]=answer[R]=sum[L]/2;
            else
            {
                answer[R]=sum[L]/2;
                answer[L]=answer[R]+1;
            }
            L++;
            R--;
        }

        for(int i=1;i<len;i++)
            cout<<answer[i];



    }




}
