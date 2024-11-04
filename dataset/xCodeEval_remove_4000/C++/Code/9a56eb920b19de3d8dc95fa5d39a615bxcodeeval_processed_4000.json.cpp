













using namespace std;
int n;
string ans="",anse="";
int main(){
    cin>>n;
    if(n%2){
            int ted=0;
            for(int j=0 ; j<n-1 ; j+=2){
                if(ted==0){
                    ans+="a";
                    ans+="a";
                }
                else if(ted==1){
                    ans+="b";
                    ans+="b";
                }
                ted=ted xor 1;
            }
            ans+="c";
            ted=0;
            anse+="i";
            for(int j=1 ; j<n ; j+=2){
                    if(ted==0){
                        anse+="h";
                        anse+="h";
                    }
                    else if (ted==1){
                        anse+="j";
                        anse+="j";
                    }
                    ted=1 xor ted;
            }

        for(int  i=0 ; i<n ; i++) cout<<ans[i];
        cout<<endl;
        for(int i=0 ; i<n-1 ; i++) cout<<char(ans[i]+3);
        cout<<ans[n-1]<<endl;
        for(int i=0 ; i<n ; i++) cout<<anse[i];
        cout<<endl<<anse[0];
        for(int i=1 ; i<n ; i++) cout<<(char)(anse[i]+3);
        return 0;
    }
    if(n%2==0){
         int ted=0;
            for(int j=0 ; j<n ; j+=2){
                if(ted==0){
                    ans+="a";
                    ans+="a";
                }
                else if(ted==1){
                    ans+="b";
                    ans+="b";
                }
                ted=ted xor 1;
            }
            ted=0,anse+="h";
            for(int i=1 ; i<n-1 ; i+=2){
                if(ted==0){
                    anse+="i";
                    anse+="i";
                }
                else if(ted==1){
                    anse+="j";
                    anse+="j";
                }
                ted=ted xor 1;
            }
            anse+="k";
        for(int  i=0 ; i<n ; i++) cout<<ans[i];
        cout<<endl;
        for(int i=0 ; i<n ; i++) cout<<char(ans[i]+3);
        cout<<endl;
        for(int i=0 ; i<n ; i++) cout<<anse[i];
        cout<<endl<<anse[0];
        for(int i=1 ; i<n-1 ; i++) cout<<(char)(anse[i]+4);
        cout<<anse[n-1];
        return 0;
            }

    }
