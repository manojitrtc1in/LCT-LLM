





using namespace std;
const ll N=5e5;


vector<ll>v;
void rec(ll x=0){
    if(x>1e9)return;
    v.push_back(x);
    rec(x*10+4);
    rec(x*10+7);
}

   bool cmp(string& s1){
        string s2="Hello,World!";
        if(s1!=s2)return 0;
       else return 1;
}

ll a[N];
int main() {
    Covid
    ll n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    ll q;
    cin>>q;
    for(int i=0;i<q;i++){
        ll x,y;
        cin>>x>>y;
        ll summ=sum;
        ll f=0,l=n-1,m,ans1=0,ans2=0,fb=0,sb=0;
        

        while(f<=l){
            m=(f+l)/2;
            if(a[m]>x) {
                fb = a[m];
                l=m-1;
            }
            else if(a[m]==x){
                fb=a[m];
                break;
            }
            else f=m+1;
        }
        if(fb>0){
            summ-=fb;
            if(summ<y)ans1=y-summ;
            else ans1=0;
        }
        else{
            fb=x-a[n-1];
            ans1=fb;
            summ-=a[n-1];
            if(summ<y){
                ans1+=(y-summ);
            }
        }
        ll summ2=sum;
        f=0,l=n-1;
        

        while(f<=l){
            m=(f+l)/2;
            if(a[m]<x){
                sb=a[m];
                f=m+1;
            }
            else l=m-1;

        }
        if(sb>0){
            summ2-=sb;
            ans2=(x-sb);
            if(summ2<y){
                ans2+=(y-summ2);
            }
        }
        else{
            summ2-=a[0];
            if(summ2<y){
                ans2=y-summ2;
            }
        }

        cout<<min(ans1,ans2)<<el;
    }

	return 0;
}

	 		  	     	 				 	  		     	