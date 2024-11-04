



using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;





















































































































































 






















 










 




























































 
















































 

 vector<int>pn={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179,
181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283,
293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419,
421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547,
557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 
673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 
821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947,
953, 967, 971, 977, 983, 991, 997};

int ib(int num)
{
    

    

    int x = log2(num) + 1;
 
    

    for (int i = 0; i < x; i++)
       num = (num ^ (1 << i));
  
    return num;
}

void solve(){
    int n;cin>>n;
    map<int,int>mp;
   vector<int>v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
    mp[v[i]]++;
   }
   int m = *max_element(v.begin(),v.end());
   vector<int>ans;
   ans.push_back(m);
   mp[m]--;
   for(int j=0;j<=40;j++){
    int last=m;
    int val=-1;
    for(int i=0;i<n;i++){
        if((m|v[i])>last){
            last=m|v[i];
            val=v[i];
        }
    }
    m=last;
    if(val!=-1){
    ans.push_back(val);
    

    mp[val]--;}
   }
   for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
   }
   for(int i=0;i<n;i++){
    if(mp[v[i]]>0){
        cout<<v[i]<<" ";
        mp[v[i]]--;
    }
   }
   cout<<endl;
} 


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    

    while(t--){
        solve();
    }
    

}








