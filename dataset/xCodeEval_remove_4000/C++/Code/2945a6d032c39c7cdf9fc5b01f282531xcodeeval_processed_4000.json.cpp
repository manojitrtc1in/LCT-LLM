
























using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef long int li;

typedef pair<int, int> pii;

typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<string, string> mss;

typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long int>> vvlli;
typedef vector<vector<bool>> vvb;





































template<typename T>
vector<T> inpv(int sz=-1){
    if(sz==-1){
        

        cin>>sz;
    }
    vector<T> res(sz);
    for(T& i : res){
        cin>>i;
    }
    return res;
}

template <typename T> void outv      (const vector<T> &vec) { 
    for(int i=0; i<vec.size(); i++) cout << vec[i] << " " ;
    cout << endl ;
}

template <typename T> inline lli sumv      (const vector<T> &vec) { 
    lli res=0;
    for(int i=0; i<vec.size(); i++) res +=vec[i] ;
    return res;
    
}

template <typename T> inline int id0      (const vector<T> &vec) { 
    return max_element(vec.begin(), vec.end()) - vec.begin();
}


template <typename T> inline int id3      (const vector<T> &vec) { 
    return min_element(vec.begin(), vec.end()) - vec.begin();
}

template <typename T> inline void sortv        (vector<T> &vec)            { sort(vec.begin(), vec.end() ) ; }
template <typename T> inline void id4       (vector<T> &vec)            { sort(vec.begin(), vec.end(), greater<T>()) ; }





template <typename T> inline int id1      (vector<T> &vec, T key)     
{
    auto itr = lower_bound(vec.begin(), vec.end(), key);
    if(itr == vec.end() || *itr != key){
        return -1;
    }
    else{
        return (itr - vec.begin()) ;
    }
}

template<class T>
vector<lli> id2(const vector<T>& vec){
    int n = vec.size();
    vector<lli> presum(n+1,0);
    presum[0] = 0;
    for(int i=1; i<=n; i++){
        presum[i] = presum[i-1] + vec[i-1] ;
    }
    return presum;

}




    


    









void fastio(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    INT64_MAX;
}

void fileio() {
	
	
		freopen("input.txt", "r", stdin);
		

    
	
}




template <typename T, typename Q>
class SegTreeMin{
private :  
    

    int n=0; 

    vector<Q> tree;
    


private:
    

    void init_rec(int tree_idx, int l, int r, const vector<T>& vals){
        if(l>r){
            error("init_rec() - l>r ");
            return;
        }

        if(l==r){
            this->tree[tree_idx] = single_item_val(l, vals);
        }
        else{
            

            int mid = (l+r)/2 ;
            int l_idx = 2*tree_idx+1;
            int r_idx = 2*tree_idx+2;

            init_rec(l_idx, l, mid, vals);
            init_rec(r_idx, mid+1, r, vals);

            

            

            this->tree[tree_idx] = merge_nodes(this->tree[l_idx],this->tree[r_idx]) ;
        }
    }

    Q query_rec(int l, int r, int tl, int tr, int tree_idx){
        
        if(!(tl<=l && tr>=r)){
            error("query_rec error : Limits.");
            Q dummy;
            return dummy;
        }
        
        if(tl==l && tr==r){
            return tree[tree_idx] ;
        }

        int tm = (tl+tr)/2 ;
        int l_idx = tree_idx*2+1;
        int r_idx = tree_idx*2+2;

        if(r<=tm){
            

            return query_rec(l, r, tl, tm, l_idx) ;
        }
        else if(l>=tm+1){
            return query_rec(l, r, tm+1, tr, r_idx) ;
        }
        else{
            

            return merge_nodes(   
                            query_rec(l, tm, tl, tm, l_idx),
                            query_rec(tm+1, r, tm+1, tr, r_idx)
                        ) ;
        }
        
    }

    void update_rec(int targ, T new_val, int tl, int tr, int tree_idx){
        

        


        

        if(!(targ>=tl && targ<=tr)){
            error("update_rec : range error") ;
        }
        
        if(tl == tr){
            

            tree[tree_idx] = single_item_val(new_val) ;
        }
        else
        {
            int tm = (tl+tr)/2 ;
            int l_idx = tree_idx*2+1;
            int r_idx = tree_idx*2+2;
            
            if(targ<=tm){
                

                update_rec(targ, new_val, tl, tm, l_idx) ;
            }
            else{
                

                update_rec(targ, new_val, tm+1, tr, r_idx);
            }

            

            this->tree[tree_idx] = merge_nodes(this->tree[l_idx], this->tree[r_idx]) ;

        }

    }


    

    void error(string msg){
        

    }

protected:
    


    inline virtual Q single_item_val(int idx, const vector<T>& vals){
        

        

        return vals[idx] ;
    }
    inline virtual Q single_item_val(T array_val){
        

        

        return array_val ;
    }


    virtual Q merge_nodes(const Q& val1, const Q& val2){
        

        

        return min(val1,val2) ;
    }

public:
    



    void init(const vector<T>& vals){
        this->n = vals.size();
        this->tree.resize(4*n) ;
        this->init_rec(0, 0, n-1, vals) ;
    }

    void update(int idx, T new_val){
        update_rec(idx, new_val, 0, n-1, 0);
    }

    Q query(int l, int r){
        return query_rec(l, r, 0, n-1, 0) ;
    }
};

template <typename T, typename Q>
class SegTreeMax{
private :  
    

    int n=0; 

    vector<Q> tree;
    


private:
    

    void init_rec(int tree_idx, int l, int r, const vector<T>& vals){
        if(l>r){
            error("init_rec() - l>r ");
            return;
        }

        if(l==r){
            this->tree[tree_idx] = single_item_val(l, vals);
        }
        else{
            

            int mid = (l+r)/2 ;
            int l_idx = 2*tree_idx+1;
            int r_idx = 2*tree_idx+2;

            init_rec(l_idx, l, mid, vals);
            init_rec(r_idx, mid+1, r, vals);

            

            

            this->tree[tree_idx] = merge_nodes(this->tree[l_idx],this->tree[r_idx]) ;
        }
    }

    Q query_rec(int l, int r, int tl, int tr, int tree_idx){
        
        if(!(tl<=l && tr>=r)){
            error("query_rec error : Limits.");
            Q dummy;
            return dummy;
        }
        
        if(tl==l && tr==r){
            return tree[tree_idx] ;
        }

        int tm = (tl+tr)/2 ;
        int l_idx = tree_idx*2+1;
        int r_idx = tree_idx*2+2;

        if(r<=tm){
            

            return query_rec(l, r, tl, tm, l_idx) ;
        }
        else if(l>=tm+1){
            return query_rec(l, r, tm+1, tr, r_idx) ;
        }
        else{
            

            return merge_nodes(   
                            query_rec(l, tm, tl, tm, l_idx),
                            query_rec(tm+1, r, tm+1, tr, r_idx)
                        ) ;
        }
        
    }

    void update_rec(int targ, T new_val, int tl, int tr, int tree_idx){
        

        


        

        if(!(targ>=tl && targ<=tr)){
            error("update_rec : range error") ;
        }
        
        if(tl == tr){
            

            tree[tree_idx] = single_item_val(new_val) ;
        }
        else
        {
            int tm = (tl+tr)/2 ;
            int l_idx = tree_idx*2+1;
            int r_idx = tree_idx*2+2;
            
            if(targ<=tm){
                

                update_rec(targ, new_val, tl, tm, l_idx) ;
            }
            else{
                

                update_rec(targ, new_val, tm+1, tr, r_idx);
            }

            

            this->tree[tree_idx] = merge_nodes(this->tree[l_idx], this->tree[r_idx]) ;

        }

    }


    

    void error(string msg){
        

    }

protected:
    


    inline virtual Q single_item_val(int idx, const vector<T>& vals){
        

        

        return vals[idx] ;
    }
    inline virtual Q single_item_val(T array_val){
        

        

        return array_val ;
    }


    virtual Q merge_nodes(const Q& val1, const Q& val2){
        

        

        return max(val1,val2) ;
    }

public:
    



    void init(const vector<T>& vals){
        this->n = vals.size();
        this->tree.resize(4*n) ;
        this->init_rec(0, 0, n-1, vals) ;
    }

    void update(int idx, T new_val){
        update_rec(idx, new_val, 0, n-1, 0);
    }

    Q query(int l, int r){
        return query_rec(l, r, 0, n-1, 0) ;
    }
};


int main(){
    
        clock_t clock_begin = clock();
	
    fastio();
    fileio();
        
    


    lli tst;
    lli ans;
        
    cin>>tst ;
    while(tst--){
        

        int n;
        cin>>n;
        vi a = inpv<int>(n);

        if(n==1){
            cout << "0\n";
            continue;
        }
        else if(n==2){
            cout << "1\n";
            continue;
        }

        for(int & i : a) i--; 


        SegTreeMin<int, int> smin;
        SegTreeMax<int, int> smax;
        smin.init(a);
        smax.init(a);


        


        


        ans = 0;

        int cur=0; 


        while(cur<n-1){

            if(cur==n-2){
                

                ans++;
                break;
            }
            
            int next = -1;
            

            
            int mn=-1;
            int mx=-1;
            int dir = 0; 

            int mnidx=-1;
            int mxidx=-1;
            


            

            next = cur+1;
            if(a[cur+1]>a[cur]){
                mn = a[cur];
                mx = a[cur+1];
                mnidx = cur;
                mxidx = cur+1;
                dir = 1;
            }
            else{
                mn = a[cur+1];
                mx = a[cur];
                mnidx = cur+1;
                mxidx = cur;
                dir = -1;
            }

            

            while(next<n-1){
                

                

                

                

                if(dir==1 && smax.query(next+1, n-1) <= mx){
                    
                    break;
                }
                if(dir==-1 && smin.query(next+1, n-1) >= mn){
                    break;
                }

                

                

                

                if(dir==1 && a[next+1]>=mn ){
                    

                    

                    if(a[next+1]>mx){
                        mx = a[next+1];
                        mxidx = next+1;
                    }
                    next++;
                }
                

                else if(dir==-1 && a[next+1]<=mx){
                    if(a[next+1] < mn){
                        mn = a[next+1];
                        mnidx = next+1;
                    }
                    next++;
                }
                else{
                    

                    assert((dir==1 && a[next+1]<mn) || (dir == -1 && a[next+1]>mx) );
                    break;
                }
            }
            

            if(dir==1) next = mxidx;
            else if(dir==-1) next = mnidx;
            trace2(cur, next);
            

            cur = next;
            ans++;
        }

        

        cout << ans << endl ;
    }


    




    
        clock_t clock_end = clock();
        

        

        cout<<"\n-------------------------\n";
	

    return 0 ;

}










































































