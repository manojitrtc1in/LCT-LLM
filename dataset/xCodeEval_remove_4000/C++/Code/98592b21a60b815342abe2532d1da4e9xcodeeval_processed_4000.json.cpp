        
        
        

        

        using namespace std;
        ll gcd (ll a, ll b) {
            while (b) {
                a %= b;
                swap(a, b);
            }
            return a;
        }

        void solve(int t)
        {
            int n,m;

            cin>>n>>m;


          char a[n][m];

          pair<int ,int> r;
          pair<int ,int> w;
          int x=1,y=1;


          for(int i=0;i<n;i++)
          {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];

                if(a[i][j]=='R' && x)
                {
                    r=make_pair(i,j);
                    x=0;
                }

                if(a[i][j]=='W' && y)
                {
                    w=make_pair(i,j);
                    y=0;
                }


            }

          }

          if(n==1 && m==1)
          {
            if(a[n-1][m-1]=='R')
            {
                cout<<"YES"<<"\n";
                cout<<'R'<<"\n";
                return;
            }

            if(a[n-1][m-1]=='W')
            {
                cout<<"YES"<<"\n";
                cout<<'W'<<"\n";

                return;
            }

            cout<<"YES"<<"\n"<<"R"<<"\n";
            return;
          }

          if(x==1 && y==1)
          {
            int turn=1;


            for(int i=0;i<n;i++)
            {

                for(int j=0;j<m;j++)
                {
                    if(turn)
                    {
                        a[i][j]='R';
                        turn^=1;

                    }

                    else
                    {
                        a[i][j]='W';
                        turn^=1;

                    }
                }
                if(m%2 == 0)
                turn^=1;
            }
          }

      


      if(x==0 && y==1)
      {
        if(r.ff & 1)
        {
            if(r.ss & 1)
            {

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j%2 ==0)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }


            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j%2 ==0)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }
            }
        }

        else
        {



             if(r.ss & 1)
            {

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j%2 == 0)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }


            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j%2 ==0)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }
            }

        }



        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='.')a[i][j]='W';
            }
        }
      }








      if(y==0 && x==1)
      {
        if(w.ff & 1)
        {
            if(w.ss & 1)
            {

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j%2 ==0)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }


            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j%2 ==0)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }
            }
        }

        else
        {



             if(w.ss & 1)
            {

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j%2 == 0)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }


            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j%2 ==0)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }




                            }

                        }

                        else
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }
            }

        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='.')a[i][j]='R';
            }
        }
      }




      if(x==0  && y==0)
      {
        if(r.ff & 1)
        {
            if(r.ss & 1)
            {

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j%2 ==0)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }


            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j%2 ==0)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }
            }
        }

        else
        {



             if(r.ss & 1)
            {

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j%2 == 0)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }


            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j%2 ==0)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='R';
                                if(a[i][j]=='W')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }
            }

        }



        



        if(w.ff & 1)
        {
            if(w.ss & 1)
            {

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j%2 ==0)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }


            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j%2 ==0)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }
            }
        }

        else
        {



             if(w.ss & 1)
            {

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j%2 == 0)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }


            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(i%2 == 0)
                        {
                            if(j%2 ==0)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }


                            }

                        }

                        else
                        {
                            if(j&1)
                            {
                                if(a[i][j]=='.')a[i][j]='W';
                                if(a[i][j]=='R')
                                {
                                    cout<<"NO"<<"\n";return;
                                }

                            }
                        }
                    }
                }
            }

        }
      }


 


      

      

      


      





      

      

      

      


      

      

      

      

      

      

      

      

      

      

      

      

      



      


      


      

      

      

      

      

      

      

      

      


      

      

      

      



      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      



      


      


      

      

      

      

      

      

      

      

      


      

      

      

      

      

      


      

      




      

      


      

      

      

      

      

      

      

      

      

      

      

      

      



      


      


      

      

      

      

      

      

      

      

      


      

      

      

      



      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      



      


      


      

      

      

      

      

      

      

      

      


      

      

      

      

      


      




      



      

      

      

      


      

      

      

      

      

      

      

      

      

      

      

      

      



      


      


      

      

      

      

      

      

      

      

      


      

      

      

      



      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      



      


      


      

      

      

      

      

      

      

      

      


      

      

      

      

      

      


      

      




      

      


      

      

      

      

      

      

      

      

      

      

      

      

      



      


      


      

      

      

      

      

      

      

      

      


      

      

      

      



      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      



      


      


      

      

      

      

      

      

      

      

      


      

      

      

      

      


      


      


      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='W')
            {
                if(j-1>=0){if(a[i][j-1]=='W'){cout<<"NO"<<"\n";return;}}
                if(j+1<m){if(a[i][j+1]=='W'){cout<<"NO"<<"\n";return;}}
                if(i+1<n){if(a[i+1][j]=='W'){cout<<"NO"<<"\n";return;}}
                if(i-1>=0){if(a[i-1][j]=='W'){cout<<"NO"<<"\n";return;}}
            }

            if(a[i][j]=='R')
            {
                if(j-1>=0){if(a[i][j-1]=='R'){cout<<"NO"<<"\n";return;}}
                if(j+1<m){if(a[i][j+1]=='R'){cout<<"NO"<<"\n";return;}}
                if(i+1<n){if(a[i+1][j]=='R'){cout<<"NO"<<"\n";return;}}
                if(i-1>=0){if(a[i-1][j]=='R'){cout<<"NO"<<"\n";return;}}
            }
        }
      }
        cout<<"YES"<<"\n";

      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j];
        }

        cout<<"\n";
      }




            

        	
        }
           


        



        int main()
        {

            

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    


        	 ios_base::sync_with_stdio(false);
            cin.tie(NULL);

            int t;
        cin>>t;
             


            while(t--)
            {
            	solve(t);
            }

        }