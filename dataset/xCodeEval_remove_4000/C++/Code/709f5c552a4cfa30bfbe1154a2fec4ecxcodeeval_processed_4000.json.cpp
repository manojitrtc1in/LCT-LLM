
using namespace std;







void solve(){
int n,m;
cin>>n>>m;

int arr[n][m];


for(int i=0;i<n;i++){
    string s;
    cin>>s;
    for(int j=0;j<m;j++){
       arr[i][j] = (int)s[j]-48;
    }
}

int ops = 0;
vector<int> out;

for(int i=0;i<n-1;i+=2){
    for(int j=0;j<m-1;j+=2){
            int count = 0;
        if(arr[i][j] == 1){
         count++;   
        }
        if(arr[i][j+1] == 1){
         count++;
        }
        if(arr[i+1][j] == 1){
         count++;
        }
        if(arr[i+1][j+1] == 1){
            count++;
        }
        if(count==4){
         ops += 1;
         out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
         
         arr[i][j] = 0;
         arr[i][j+1] = 0;
         arr[i+1][j+1] = 0;
         
         count=1;   
        }
        if(count==2){
            ops += 1;
            if(arr[i][j]==1&&arr[i][j+1]==1){ 

                out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1); out.pb(i); out.pb(j);
                
                arr[i][j] = 0;
                arr[i+1][j+1] = 1;
                arr[i+1][j] = 1;
            }
            else if(arr[i+1][j]==1&&arr[i+1][j+1]==1){ 

               out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); 
               
               arr[i][j] = 1;
               arr[i][j+1] = 1;
               arr[i+1][j+1] = 0;
            }
            else if(arr[i][j]==1&&arr[i+1][j]==1){ 

                 out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); out.pb(i); out.pb(j);
                 
                 arr[i][j] = 0;
                 arr[i][j+1] = 1;
                 arr[i+1][j+1] = 1;
            }
            else if(arr[i][j+1]==1&&arr[i+1][j+1]==1){ 

            out.pb(i); out.pb(j); out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1);
            
                arr[i][j] = 1;
                arr[i+1][j+1] = 0;
                arr[i+1][j] = 1;
            }
            else if(arr[i][j]==1&&arr[i+1][j+1]==1){ 

                out.pb(i); out.pb(j); out.pb(i+1); out.pb(j); out.pb(i); out.pb(j+1); 
                
                arr[i][j] = 0;
                arr[i][j+1] = 1;
                arr[i+1][j] = 1;
            }
            else{ 

               out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
               
               arr[i][j] = 1;
               arr[i][j+1] = 0;
               arr[i+1][j+1] = 1;
            }
            
            count=3;
        }
        if(count==3){
            ops += 1;
            if(arr[i][j]==1 && arr[i][j+1]==1 && arr[i+1][j+1]==1){
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
            }
            else if(arr[i+1][j]==1 && arr[i][j+1]==1 && arr[i+1][j+1]==1){
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
            }
            else if(arr[i+1][j]==1 && arr[i][j]==1 && arr[i+1][j+1]==1){
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i+1); out.pb(j+1);
            }
            else{
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
            }
        }
        if(count==1){
             ops += 3;
             if(arr[i][j]==1){
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
                
                out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j); out.pb(i); out.pb(j);
                
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
             }
             else if(arr[i][j+1]==1){
                out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j);
                 
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
                
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
             }
             else if(arr[i+1][j] == 1){
                out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j);
                 
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
                
                out.pb(i); out.pb(j); out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1);
             }
             else{
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
                
                out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j); out.pb(i); out.pb(j);
                
                out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1); out.pb(i); out.pb(j+1);
             }
        }
        
        arr[i][j] = 0;
        arr[i+1][j+1] = 0;
        arr[i][j+1] = 0;
        arr[i+1][j] = 0;
    }
}

if(n%2!=0){
    int i = n-2;
for(int j=0;j<m-1;j++){
                int count = 0;
        if(arr[i][j] == 1){
         count++;   
        }
        if(arr[i][j+1] == 1){
         count++;
        }
        if(arr[i+1][j] == 1){
         count++;
        }
        if(arr[i+1][j+1] == 1){
            count++;
        }
        if(count==4){
         ops += 1;
         out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
         
         arr[i][j] = 0;
         arr[i][j+1] = 0;
         arr[i+1][j+1] = 0;
         
         count=1;   
        }
        if(count==2){
            ops += 1;
            if(arr[i][j]==1&&arr[i][j+1]==1){ 

                out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1); out.pb(i); out.pb(j);
                
                arr[i][j] = 0;
                arr[i+1][j+1] = 1;
                arr[i+1][j] = 1;
            }
            else if(arr[i+1][j]==1&&arr[i+1][j+1]==1){ 

               out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); 
               
               arr[i][j] = 1;
               arr[i][j+1] = 1;
               arr[i+1][j+1] = 0;
            }
            else if(arr[i][j]==1&&arr[i+1][j]==1){ 

                 out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); out.pb(i); out.pb(j);
                 
                 arr[i][j] = 0;
                 arr[i][j+1] = 1;
                 arr[i+1][j+1] = 1;
            }
            else if(arr[i][j+1]==1&&arr[i+1][j+1]==1){ 

            out.pb(i); out.pb(j); out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1);
            
                arr[i][j] = 1;
                arr[i+1][j+1] = 0;
                arr[i+1][j] = 1;
            }
            else if(arr[i][j]==1&&arr[i+1][j+1]==1){ 

                out.pb(i); out.pb(j); out.pb(i+1); out.pb(j); out.pb(i); out.pb(j+1); 
                
                arr[i][j] = 0;
                arr[i][j+1] = 1;
                arr[i+1][j] = 1;
            }
            else{ 

               out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
               
               arr[i][j] = 1;
               arr[i][j+1] = 0;
               arr[i+1][j+1] = 1;
            }
            
            count=3;
        }
        if(count==3){
            ops += 1;
            if(arr[i][j]==1 && arr[i][j+1]==1 && arr[i+1][j+1]==1){
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
            }
            else if(arr[i+1][j]==1 && arr[i][j+1]==1 && arr[i+1][j+1]==1){
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
            }
            else if(arr[i+1][j]==1 && arr[i][j]==1 && arr[i+1][j+1]==1){
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i+1); out.pb(j+1);
            }
            else{
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
            }
        }
        if(count==1){
             ops += 3;
             if(arr[i][j]==1){
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
                
                out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j); out.pb(i); out.pb(j);
                
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
             }
             else if(arr[i][j+1]==1){
                out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j);
                 
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
                
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
             }
             else if(arr[i+1][j] == 1){
                out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j);
                 
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
                
                out.pb(i); out.pb(j); out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1);
             }
             else{
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
                
                out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j); out.pb(i); out.pb(j);
                
                out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1); out.pb(i); out.pb(j+1);
             }
        }
        
        arr[i][j] = 0;
        arr[i+1][j+1] = 0;
        arr[i][j+1] = 0;
        arr[i+1][j] = 0;
}
}

if(m%2!=0){
    int j = m-2;
for(int i=0;i<n-1;i++){
        int count = 0;
        if(arr[i][j] == 1){
         count++;   
        }
        if(arr[i][j+1] == 1){
         count++;
        }
        if(arr[i+1][j] == 1){
         count++;
        }
        if(arr[i+1][j+1] == 1){
            count++;
        }
        if(count==4){
         ops += 1;
         out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
         
         arr[i][j] = 0;
         arr[i][j+1] = 0;
         arr[i+1][j+1] = 0;
         
         count=1;   
        }
        if(count==2){
            ops += 1;
            if(arr[i][j]==1&&arr[i][j+1]==1){ 

                out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1); out.pb(i); out.pb(j);
                
                arr[i][j] = 0;
                arr[i+1][j+1] = 1;
                arr[i+1][j] = 1;
            }
            else if(arr[i+1][j]==1&&arr[i+1][j+1]==1){ 

               out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); 
               
               arr[i][j] = 1;
               arr[i][j+1] = 1;
               arr[i+1][j+1] = 0;
            }
            else if(arr[i][j]==1&&arr[i+1][j]==1){ 

                 out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); out.pb(i); out.pb(j);
                 
                 arr[i][j] = 0;
                 arr[i][j+1] = 1;
                 arr[i+1][j+1] = 1;
            }
            else if(arr[i][j+1]==1&&arr[i+1][j+1]==1){ 

            out.pb(i); out.pb(j); out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1);
            
                arr[i][j] = 1;
                arr[i+1][j+1] = 0;
                arr[i+1][j] = 1;
            }
            else if(arr[i][j]==1&&arr[i+1][j+1]==1){ 

                out.pb(i); out.pb(j); out.pb(i+1); out.pb(j); out.pb(i); out.pb(j+1); 
                
                arr[i][j] = 0;
                arr[i][j+1] = 1;
                arr[i+1][j] = 1;
            }
            else{ 

               out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
               
               arr[i][j] = 1;
               arr[i][j+1] = 0;
               arr[i+1][j+1] = 1;
            }
            
            count=3;
        }
        if(count==3){
            ops += 1;
            if(arr[i][j]==1 && arr[i][j+1]==1 && arr[i+1][j+1]==1){
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
            }
            else if(arr[i+1][j]==1 && arr[i][j+1]==1 && arr[i+1][j+1]==1){
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
            }
            else if(arr[i+1][j]==1 && arr[i][j]==1 && arr[i+1][j+1]==1){
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i+1); out.pb(j+1);
            }
            else{
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
            }
        }
        if(count==1){
             ops += 3;
             if(arr[i][j]==1){
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
                
                out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j); out.pb(i); out.pb(j);
                
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
             }
             else if(arr[i][j+1]==1){
                out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j);
                 
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
                
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
             }
             else if(arr[i+1][j] == 1){
                out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j);
                 
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
                
                out.pb(i); out.pb(j); out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1);
             }
             else{
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
                
                out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j); out.pb(i); out.pb(j);
                
                out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1); out.pb(i); out.pb(j+1);
             }
        }
        
        arr[i][j] = 0;
        arr[i+1][j+1] = 0;
        arr[i][j+1] = 0;
        arr[i+1][j] = 0;
}
}

if(n%2!=0 && m%2!=0){
    int i = n-2;
    int j = m-2;
        int count = 0;
        if(arr[i][j] == 1){
         count++;   
        }
        if(arr[i][j+1] == 1){
         count++;
        }
        if(arr[i+1][j] == 1){
         count++;
        }
        if(arr[i+1][j+1] == 1){
            count++;
        }
        if(count==4){
         ops += 1;
         out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
         
         arr[i][j] = 0;
         arr[i][j+1] = 0;
         arr[i+1][j+1] = 0;
         
         count=1;   
        }
        if(count==2){
            ops += 1;
            if(arr[i][j]==1&&arr[i][j+1]==1){ 

                out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1); out.pb(i); out.pb(j);
                
                arr[i][j] = 0;
                arr[i+1][j+1] = 1;
                arr[i+1][j] = 1;
            }
            else if(arr[i+1][j]==1&&arr[i+1][j+1]==1){ 

               out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); 
               
               arr[i][j] = 1;
               arr[i][j+1] = 1;
               arr[i+1][j+1] = 0;
            }
            else if(arr[i][j]==1&&arr[i+1][j]==1){ 

                 out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); out.pb(i); out.pb(j);
                 
                 arr[i][j] = 0;
                 arr[i][j+1] = 1;
                 arr[i+1][j+1] = 1;
            }
            else if(arr[i][j+1]==1&&arr[i+1][j+1]==1){ 

            out.pb(i); out.pb(j); out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1);
            
                arr[i][j] = 1;
                arr[i+1][j+1] = 0;
                arr[i+1][j] = 1;
            }
            else if(arr[i][j]==1&&arr[i+1][j+1]==1){ 

                out.pb(i); out.pb(j); out.pb(i+1); out.pb(j); out.pb(i); out.pb(j+1); 
                
                arr[i][j] = 0;
                arr[i][j+1] = 1;
                arr[i+1][j] = 1;
            }
            else{ 

               out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
               
               arr[i][j] = 1;
               arr[i][j+1] = 0;
               arr[i+1][j+1] = 1;
            }
            
            count=3;
        }
        if(count==3){
            ops += 1;
            if(arr[i][j]==1 && arr[i][j+1]==1 && arr[i+1][j+1]==1){
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
            }
            else if(arr[i+1][j]==1 && arr[i][j+1]==1 && arr[i+1][j+1]==1){
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
            }
            else if(arr[i+1][j]==1 && arr[i][j]==1 && arr[i+1][j+1]==1){
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i+1); out.pb(j+1);
            }
            else{
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
            }
        }
        if(count==1){
             ops += 3;
             if(arr[i][j]==1){
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
                
                out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j); out.pb(i); out.pb(j);
                
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
             }
             else if(arr[i][j+1]==1){
                out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j);
                 
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
                
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
             }
             else if(arr[i+1][j] == 1){
                out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j);
                 
                out.pb(i+1); out.pb(j); out.pb(i); out.pb(j); out.pb(i); out.pb(j+1);
                
                out.pb(i); out.pb(j); out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1);
             }
             else{
                out.pb(i); out.pb(j); out.pb(i); out.pb(j+1); out.pb(i+1); out.pb(j+1);
                
                out.pb(i+1); out.pb(j+1); out.pb(i+1); out.pb(j); out.pb(i); out.pb(j);
                
                out.pb(i+1); out.pb(j); out.pb(i+1); out.pb(j+1); out.pb(i); out.pb(j+1);
             }
        }
        
        arr[i][j] = 0;
        arr[i+1][j+1] = 0;
        arr[i][j+1] = 0;
        arr[i+1][j] = 0;
}

cout<<ops<<"\n";
for(int i=0;i<out.size();i+=6){
    cout<<out[i]+1<<" "<<out[i+1]+1<<" "<<out[i+2]+1<<" "<<out[i+3]+1<<" "<<out[i+4]+1<<" "<<out[i+5]+1<<"\n";
}
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    solve();
    
    return 0;
}