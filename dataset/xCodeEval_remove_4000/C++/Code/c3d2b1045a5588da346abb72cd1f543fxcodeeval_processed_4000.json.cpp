













using namespace std;


using namespace __gnu_pbds;

int t,n,k,idx;
string s;
vector<pair<int,int> >ans;
deque<int>o;
void calc1()
{
 for(int i=0;i<n;i++)
  { o.clear(); deque<int>c;
    for(int y=0;y<n;y++)
    { if(s[y]=='(')
         o.push_back(y);
      else
      { if(o.empty())
         c.push_back(y);
        else
         o.pop_back();
      }
    }
    if(c.empty())break;
    else
    {ans.push_back({c.back()+1,o.front()+1});
     reverse(s.begin()+c.back(),s.begin()+o.front()+1);
    }
  }

}
void calc3()
{o.clear(); int open=0,ok=0;
 for(int i=0; i<n; i++)
  {
    if(s[i]=='(')
     open++,o.push_back(i);
    else
     { open--;
       if(open>0)
        { swap(s[o.back()],s[i]);
          ans.push_back({o.back()+1,i+1});
          o.pop_back();
        }
     }
  }
}

void calc2()
{  int have=n/2,target=k,a=2;
   for(int i=1;i<=have-target;i++)
    ans.push_back({a,a+1}),a+=2;
}


int main()
{
    yalla;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>s;
        ans.clear();
        

        calc1();
        calc3();
        

        calc2();
        

        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i].F<<" "<<ans[i].S<<endl;
     }

    re 0;
}
































