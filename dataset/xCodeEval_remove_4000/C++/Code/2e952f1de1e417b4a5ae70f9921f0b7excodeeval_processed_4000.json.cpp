

using namespace std;














































































int main()
{
    int i,j,k,f=0,f2=0,l=0,n,m;
    vector<pair<int,pair<int,int> > >v[100];
    vector<int>vv;
    vector<int>vv2;
    sf1(n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            sf1(k);
            v[i].push_back({k,{i,j}});
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            

            for(k=0; k<n; k++)
            {

                for(l=0; l<n; l++)
                {
                    if(v[i][j].second.first==k && v[i][j].second.second!=l)
                    {
                        if(v[i][j].first>v[k][l].first)vv.push_back(v[k][l].first);
                    }

                    else if(v[i][j].second.second==l && v[i][j].second.first!=k)
                        if(v[i][j].first>v[k][l].first)vv2.push_back(v[k][l].first);
                }
            }
            int mm=vv.size();
            int mm2=vv2.size();
            int f=0;
            for(k=0; k<mm; k++)
            {
                for(l=0; l<mm2; l++)
                {
                    if(v[i][j].first!=1)
                    {
                        

                        if(v[i][j].first==vv[k]+vv2[l])
                        {
                            f=1;
                            break;
                        }
                    }

                }
            }
            if(v[i][j].first!=1 && f==0){No;return 0;}
            vv.clear();
            vv2.clear();
            

        }
    }
    Yes;
    return 0;
}






