        

        

        
        

        
        
        
        
        
        

        
        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        

        
         

        
        

        
        
        
        
        
        
        

         

        
        

        
        
        
        


        using namespace std;

        

        typedef long long ll;
        typedef long double ld;

        typedef pair<int, int> pi;
        typedef pair<ll,ll> pl;
        typedef pair<ld,ld> pd;

        typedef vector<int> vi;
        typedef vector<ld> vd;
        typedef vector<ll> vl;
        typedef vector<pi> vpi;
        typedef vector<pl> vpl;
        typedef vector<char> vc;

        typedef unordered_map<int,int> mii;
        typedef map<ll,ll> mll;
        typedef map<char,int> mci;
        typedef map<string,int> msi;


        
        
        
        
        
        
        

        const int MOD = 1000000007;
        const int N = 200001;
        set<char> vowel={'A', 'O', 'Y', 'E', 'U', 'I','a','o','y','e','u','i'};
        ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
        bool issquare(ll w ){
            return trunc(sqrt(w))*trunc(sqrt(w))==w;
        }

        int dx[]={1,-1,0,0,1,-1,1,-1};
        int dy[]={0,0,1,-1,1,1,-1,-1};

        bool vis[N],check=true;

        char c,c1;

        string ch,ch1,ch2;
        queue<int> q;
        priority_queue<int> pq;

        map<int,set<int> > adj;
        map<ll,pl> mm;
        map<int,set<int> > edje;
        msi mastring;
        mci machar;
        mii mai;
        set<char> setchar;

        set<int> sx,sy,si;

        vl v,vv,tab[N];
        vpi vvv;
        vector <string> vs;

        int main(){
            ll n,m,k,a,l,ans=0,res=0,posmin,posmax,x,y=0,z=0,xmax=0,ymax=0,som[N];
            cin >> k ;
        
            for(int i=0;i<k;i++){
                cin >> x;

        
                tab[i].pb(x);
                ans=0;

        
                for(int j=0;j<x;j++){
                    cin >> y;
                    ans+=y;
                    tab[i].pb(y);
                }
                som[i]=ans;
            }

        
            for(int i=0;i<k;i++){
                for(int j=0;j<tab[i][0];j++){
                    x=som[i]-tab[i][j+1];
                    

                    if(mm.count(x) && i !=mm[x].f){
                        cout << "YES" << endl;
                         

        
        

        
                        cout << i+1 << " " << j+1<< endl;
                         

        
        

         

        
        

         

        
        

         

        
        

        
                         

        
        

        
                        cout << mm[x].f+1 << " " << mm[x].s+1;
                        return 0;
                    }else if(mm.count(x)==0){
                        mm[x]={i,j};
                    }
                }
            }

        
            cout << "NO" << endl;
          return 0;
        }
