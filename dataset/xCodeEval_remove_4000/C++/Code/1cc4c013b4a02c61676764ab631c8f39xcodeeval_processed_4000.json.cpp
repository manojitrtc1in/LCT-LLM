














using namespace std;
int const maxn=4000*100+10;
int n;
bool mark[maxn];
string str;
vector<int> bor,dot;
int main(){
    cin>>str;
    n=str.size();
    for(int i=0 ; i<n ; i++){
        if(str[i]=='.'){
            dot.pb(i);
        }
    }
    if(dot.size()==0){
        cout<<"NO"<<endl;
            return 0;
    }
   

    if(dot.size()==n || str[0]=='.' || str[n-1]=='.'){
            cout<<"NO"<<endl;
            return 0;
    }
    if(n-(dot.back()+1)>3 || dot[0]>=9 || dot.size()==0){
            cout<<"NO"<<endl;
            return 0;
    }
   

    for(int i=0 ; i<dot.size()-1 ; i++){
        

        if((dot[i+1]-dot[i])-1>11 || dot[i+1]-dot[i]<=2){
            cout<<"NO"<<endl;
            return 0;
        }
        if(dot[i+1]-dot[i]==3){
            mark[dot[i]+2]=true;
            continue;
        }
        if(((dot[i+1]-dot[i])-1)==11){
            mark[dot[i]+4]=true;
            continue;
        }
        if((dot[i+1]-dot[i])-1<11){
            int dif=(dot[i+1]-dot[i]);
            mark[(dot[i]+min(3,dif/2))+1]=true;
           

        }
    }
    cout<<"YES"<<endl;
    for(int i=0 ; i<n ; i++){
        if(mark[i]==1) cout<<endl;
        cout<<str[i];
    }
}
