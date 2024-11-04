




































































template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "[ " << pair.first << " : " << pair.second << " ]\n";
    }
}





using namespace std;




void read_arr(int arr[] , int n){
	for (int i=0 ; i<n ; ++i)
		cin >> arr[i];
}




const int Ntest = 1e5 + 5;




ll gcd(ll a, ll b){ll temp;while (b > 0){temp = a%b;a = b;b = temp;} return a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}




clock_t time_p=clock();
void TimeTaken()
{
    time_p=clock()-time_p;
    cerr<<"Completion time : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}



int Search (VI &arr , int low , int high , int key ){
	

	if (low > high){
		return -1;
	}
	int mid = (low + high) / 2;

	if (arr[mid] == key)
        return mid;

	

	if (arr[low] <= arr[mid]){
		if (key >= arr[low] and key <= arr[mid])
			return Search (arr , low , mid-1 , key);
		else
			return Search (arr , mid+1 , high , key);
	}
	

	

	else{
		if (key >= arr[mid] and key <= arr[high])
			return Search (arr , mid+1 , high , key);
		else
			return Search (arr , low , mid-1 , key);
	}
}

void id20 (VI &arr){
	int n = sz(arr);
	int temp = arr[n-1];
	for (int i=n-1 ; i>=0 ; i--)
		arr[i] = arr[i-1];
	arr[0] = temp;
}


void rev (VI &arr , int start , int end){
	while (start < end){
		swap(arr[start] , arr[end]);
		start++ ; end--;
	}
}

void id19 (VI &arr , int k){
	int n = sz(arr);
	if (k == 0) return ;
	k %= n;
	rev(arr , 0 , n-1);
	rev(arr , 0 , k-1);
	rev(arr , k , n-1);

}

void rotate_left (VI &arr , int d){
	int n = sz(arr);
	for (int i=d ; i<d+n ; i++)
		cout << arr[i % n] << " ";
	cout << "\n";
}

int arr_max (VI &arr){
	int n = sz(arr);
	int Max = arr[0];
	for (int i=1 ; i<n ; i++){
		if (arr[i] > Max)
			Max = arr[i];
	}
	return Max;
}

int cnt_pair (VI &v){
	int n = sz(v); int c = 0;
	for (int i=0 ; i<n ; i++){
		for (int j=i+1 ; j<n ; j++){
			if (v[i] == v[j]){
				if (i < j) c++;
				else continue;
			}
		}
	}
	return c;
}





template<typename x>
void read_stack (stack<x> &s , ll n){
	

	for (ll a=0 ; a<n ; a++){
		x y;
		cin >> y;
		s.push(y);
	}
}



template<typename T>
void id21 (stack<T> &s){
	if (s.empty()) return;
	T x = s.top(); s.pop();
	id21(s);
	cout << x << " ";
	s.push(x);
	

}


int find_element ( int arr[] , int ranges[][2] , int rotations , int idx){
	

	for (int i=rotations-1 ; i>=0 ; i--){
		if (idx >= ranges[i][0] and idx <= ranges[i][1]){
			

			if (idx == ranges[i][0]) idx = ranges[i][1];
			else	idx--;
		}
		else{
			

			idx = idx;
		}
	}
	return arr[idx];
}

int search_int (int arr[] , int n , int key){
	int ans = 0;
	for (int i=0 ; i<n ; i++){
		if (arr[i] == key)
			ans = i;
		else
			continue;
	}
	return ans;
}




int id28 (VI &arr , int k){
	

	

	int n = sz(arr);
	

	if (n < k) return -1;
	int sum = 0;
	

	for (int i=0 ; i<k ; i++){
		sum += arr[i];
	}
	int window_sum = sum , i , j , Max_sum = 0;
	

	

	for (i=0 , j=k ; j<n ; ++i , ++j){
		window_sum += arr[j] - arr[i];
		Max_sum = max(Max_sum , window_sum);
	}

	

	

	

	

	

	return Max_sum;
}

VPI id23 (VI &list , int target){
	

	int n = sz(list); VPI ans;
	for (int i=0 ; i<n ; ++i){
		for (int j=0 ; j<n ; ++j){
			if (i == j) continue;
			

			if (list[i] + list[j] == target)
				ans.PB(MP(list[i] , list[j]));
			if (list[i] + list[j] > target)
				break;
		}
	}
	return ans;
	

}

void id2 (VI &list , int sum){
	VPI ans = id23(list , sum);
	for (auto x : ans)
		cout << "[ " << x.F << " , " << x.S << " ]" << " ";
	cout << "\n";
}

bool id31 (VI &list , int target){
	


	int n = sz(list);
	

	

	int start = 0 , end = n-1;

	while (start < end){
		if (list[start] + list[end] == target) return true;
		

		if (list[start] + list[end] < target) start++;
		if (list[start] + list[end] > target) end--;
	}
	return false;
}




int id4 (int *arr , int n){
	if (n < 2) return 0;
	int second = 0;
	int largest = *max_element(arr , arr+n);
	for (int i=0 ; i<n ; i++){
		if (arr[i] != largest)
			second = max (second , arr[i]);
	}
	return second;
}





void heapify (int *arr, int *index , int i , int n){
	int big = i; 

	int left = 2*i + 1; 

	int right = 2*i + 2; 


	

	

	if (left < n and index[left] > index[big]) big = left;
	if (right < n and index[right] > index[big]) big = right;

	

	

	

	if (big != i){
		

		swap(arr[big] , arr[i]);
		swap(index[big] , index[i]);
		heapify(arr , index , big , n);
	}
}

void heap_sort (int *arr , int *index , int n){
	

	for (int i=(n-1)/2 ; i>=0 ; i--){
		heapify(arr , index , i , n);
	}
	

	for (int i=n-1 ; i>0 ; i--){
		

		swap(index[0] , index[i]);
		swap(arr[0] , arr[i]);
		n--;
		heapify(arr , index , 0 , n);
	}
}



void rev_arr (int arr[] , int n){
	int start = 0 , end = n-1;
	while (start < end){
		swap(arr[start++] , arr[end--]);
	}
}


void power_set (VI &arr){
	set<string> Set ; 
	int n = sz(arr);
	int N = pow(2,n);
	int i , j ; 
	rep(i,0,N){
		string subset;
		rep(j,0,n){
			if (i & (1<<j))
				subset += to_string(arr[j]) + " ";
		}
		Set.insert(subset);
	}

	for (auto subset : Set)
		cout << subset << "\n";
}





VI id1 (int num){
	VI ans ; 
	while (num > 0){
		ans.PB(num % 10);
		num /= 10;
	}
	reverse(all(ans));
	return ans;
}

void id29 (VI &arr){
	int n = sz(arr);
	for (int i=1 ; i<n ; i++){
		if ((i % 2 != 0 and arr[i] > 0 and arr[i-1] < 0) or
			(i % 2 == 0 and arr[i] < 0 and arr[i-1] > 0))
			swap(arr[i] , arr[i-1]);
	}
}


int id16(VI &arr){
	

	int n = sz(arr); int i;
	for (i=0 ; i<n ; i++){
		if (arr[i] != i)
			return i;
		

	}
	

	return i;
}



int id10 (int *arr , int n){
	int best = INT_MIN , sum = 0;
	for (int i=0 ; i<n ; i++){
		sum = max(arr[i] , sum + arr[i]);
		best = max(best , sum);
	}
	return best;
}



void id5 (int *arr , int n){
	int best = INT_MIN , sum = 0 , start = 0 , end = 0 , tracker = 0;
	for (int i=0 ; i<n ; i++){
		sum += arr[i];
		if (best < sum){
			best = sum;
			start = tracker; end = i;
		}
		

		if (sum < 0){
			sum = 0;
			tracker = i+1;
		}
	}
	int Length = 0;
	for (int x=start ; x<=end ; x++){
		

		Length++;
	}
	cout << Length;
	cout << "\n";
}




void id3 (VI &arr , int k){
	int n = sz(arr);
	int sum = 0 , start = 0 , end = 0;
	for(int i=0 ; i<k ; i++){
		sum += arr[i];
	}
	int ans = sum;
	for (int i=0 , j=k ; j<n ; i++,j++){
		sum += ( arr[j] - arr[i]);
		if (ans > sum){
			ans = sum;
			start = i;
			end = j;
		}
	}
	for (int x=start+1 ; x<=end ; x++)
		cout << arr[x] << " ";
	cout << "\n";
	

	

	

}

int min_diff (int *arr , int n){
	

	

	int curr , next;
	sort_arr(arr , n); int diff = INT_MAX;
	for (curr=0 , next=1 ; next<n ; curr++ , next++){
		diff = min(diff , abs(arr[next] - arr[curr]));
	}
	return diff;
}


int id17 (VI &arr , int k){
	int n = sz(arr);
	sortall(arr);
	

	

	int diff = arr[n-1] - arr[0];
	

	int id33 , id32;
	

	

	

	

	

	

	

	

	

	

	


	for (int i=1 ; i<=n-1 ; i++){
		id33 = max(arr[i-1]+k , arr[n-1] - k);
		id32 = min(arr[0]+k , arr[i]-k);
		diff = min(diff , id33 - id32);
		

	}
	return diff;
}


PI give_pair (VI &arr , int sum){
	umap <int , int> Map; int n = sz(arr);
	int id24 ; PI Pair;
	for (int i=0 ; i<n ; i++){
		id24 = sum - arr[i];
		if (Map.find(id24) != Map.end()){
			Pair = MP(Map[id24] , i);
		}
		else
			Map[arr[i]] = i;
	}
	return Pair;
}


int max_profit (VI &prices){
	int n = sz(prices);
	int profit = 0 , best_profit = 0;
	for (int i=1 ; i<n ; i++){
		profit = max (0 , profit + (prices[i] - prices[i-1]));
		best_profit = max (best_profit , profit);
	}
	return best_profit;
}


int solution(string &S) {
    

    int id7 = 0 , n = S.length();
    for (int i=0 ; i<n ; i++){
        if (S[i] == 'X'){
            id7++;
            i+=2;
        }
    }
    return id7;
}

void maj_ele (VI &arr , int k){
	int n = sz(arr);
	umap <int , int> M;
	int i;
	

	rep(i,0,n){
		M[arr[i]]++;
	}

	

	

	

	

	


	for (auto x : M){
		if (x.S > n/k)
			cout << x.F << " ";
	}
	cout << endl;
	

}

void array_duplicate (VI &arr){
	int n = sz(arr);
	for (int i=0 ; i<n ; i++){
		arr[arr[i] % n] += n;
	}
	for (int i=0 ; i<n ; i++){
		if (arr[i]/n > 1)
			cout << i << " ";
		

	}
	nline;
}

void id14 (int r , int c){
	

	int matrix [r][c]; 
    

    int left = 0 , right  = c-1 , top = 0 , down = r-1;
    int dir = 0; 

    int fill = 1; 


    

    while (top <= down and left <= right){
        if (dir == 0){
            for (int i=left ; i<=right ; i++)
                matrix[top][i] = fill++;
            dir = 1; top++;
        }
        else if (dir == 1){
            for (int i=top ; i<=down ; i++)
                matrix[i][right] = fill++;
            dir = 2; right--;
        }
        else if (dir == 2){
            for (int i=right ; i>=left ; i--)
                matrix[down][i] = fill++;
            dir = 3; down--;
        }
        else if (dir == 3){
          for (int i=down ; i>=top ; i--)
                matrix[i][left] = fill++;
            dir = 0; left++;
        }
    }
   
   	

   	for (int i=0 ; i<r ; i++){
   		for (int j=0 ; j<c ; j++)
   			cout << matrix[i][j] << " ";
   		nline;
   	} 
}

VVI id9 (VVI matrix){
	VVI ans;
	

	if (matrix.size() == 0) return ans;

	

	sortall(matrix);
	VI temp = matrix[0];

	for (auto it : matrix){
		if (it[0] <= temp[1]){
			temp[1] = max(it[1] , temp[1]);
		}
		else{
			ans.PB(temp);
			temp = it;
		}
	}
	ans.PB(temp);
	return ans;
}


struct interval
{
	int start , end;
};


bool compare_interval (interval a , interval b){
	return (a.start < b.start);
}


void id25 (interval arr[] , int n){
	if (n == 0) return ; 

	

	stack <interval> ans;
	

	sort(arr , arr+n , compare_interval);
	

	ans.push(arr[0]);

	for (int i=1 ; i<n ; i++){
		

		interval Top = ans.top();

		

		

		

		if (Top.end >= arr[i].start){
			Top.end = max(Top.end , arr[i].end);
			Top.start = min(Top.start , arr[i].start);
			ans.pop();
			ans.push(Top);
		}

		

		

		else{
			ans.push(arr[i]);
		}
	}

	

	while (! ans.empty()){
		cout << "[ " << ans.top().start << " , " << ans.top().end << " ] " << " ";
		ans.pop();
	}
	nline;
}

void id12 (VVI mat , int r , int c){
	int row[r] , col[c];

	for (int i=0 ; i<r ; i++){
		for (int j=0 ; j<c ; j++){
			if (mat[i][j] == 1){
				row[i] = 1;
				col[j] = 1;
			}
		}
	}


	for (int i=0 ; i<r ; i++){
		for (int j=0 ; j<c ; j++){
			if (row[i] == 1 or col[j] == 1){
				mat[i][j] = 1;
			}
		}
	}


	for (int i=0 ; i<r ; i++){
		for (int j=0 ; j<c ; j++){
			cout << mat[i][j] << " ";
		} nline;
	}
}


void bfs (int src , VI adj[] , VI &vis , VI &ans) {
	queue <int> q; 

	q.push(src); 

	vis[src] = 1; 

	while(!q.empty()){
		int node = q.front(); 

		q.pop(); 

		ans.PB(node);
		

		

		

		for (auto x : adj[node]){
			

			

			if (!vis[x]){
				q.push(x);
				vis[x] = 1;
			}
		}
	}
	

	

	

}

VI id13 (VI adj[] , int v){
	

	VI vis(v+1,0); 

	int comp = 0; int nodes;
	VI id0;

	


 	

	

	

	for (int i=1 ; i<=v ; i++){
		

		if (!vis[i]){
			

			


			

			

			bfs(i , adj , vis , id0);

			

			

			

		}
	}

	


	

	return id0;
}

void dfs (int node , VI adj[] , VI &vis , VI &store){
	

	store.PB(node); 

	vis[node] = 1; 

	for (auto x : adj[node]){
		

		

		

		if (!vis[x]){
			dfs(x , adj , vis , store);
		}
	}
}

VI id15 (VI adj[] , int v){
	

	VI store; 

	VI vis(v+1,0); 


	

	

	

	for (int i=1 ; i<=v ; i++){
		

		if (!vis[i]){
			dfs(i , adj , vis , store);
		}
	}
	return store;
}



void print_matrix (int **grid , int r , int c){
	int i , j;
	rep(i,0,r){
		rep(j,0,c)
			cout << grid[i][j] << " ";
		nline;
	}
}



void id6 (priority_queue <PI> pq){
	priority_queue <PI> ans = pq;
	cout << "[ ";
	while (! ans.empty()){
		PI temp = ans.top();
		cout << "{ " <<(-1)*(temp.F) << " , " << (-1)*(temp.S)<< " } ";
		ans.pop();
	}
	cout << "]" ; nline;
}



void id11 (VPI graph[] , int v , int src){
	

	priority_queue<PI , VPI , greater<PI>> pq;
	

	VI dist (v+1 , INF); 

	

	dist[src] = 0; 

	pq.push(MP(0 , src));
	

	while (! pq.empty()){
		

		

		

		int prev_node = pq.top().S;
		pq.pop();

		

		

		

		

		for (auto x : graph[prev_node]){
			int next_node = x.F;
			int weight = x.S;
			if (dist[next_node] > dist[prev_node] + weight){
				dist[next_node] = dist[prev_node] + weight;
				pq.push(MP(dist[next_node] ,next_node));
			}
		} 
	}
	

	for (int i=1 ; i<=v ; i++)
		cout << dist[i] << " ";
	nline;
}





int maze (VVI &grid){
	

	int r = sz(grid);
	int c = sz(grid[0]);
	

	int dx[2] = {1 , 0};
	int dy[2] = {0 , -1};
	

	queue<PI> q; 
	int path = 0; 

	q.push(MP(0,0));
	while (!q.empty()){
		

		int nx = q.front().F;
		int ny = q.front().S;
		q.pop(); 
		

		if (nx == r-1 and ny == c-1) 
			path++;
		int i;
		

		if (nx + 1 < r and grid[nx + 1][ny] == 1)
			q.push(MP(nx + 1 , ny));
		

		if (ny + 1 < c and grid[nx][ny + 1] == 1)
			q.push(MP(nx , ny + 1));
	}
	return path;
}

void reverse_rows (VVI &grid){
	int r = sz(grid);
	int c = sz(grid[0]);
	for (int i=0 ; i<r ; i++){
		reverse(all(grid[i]));
	}
}




void reverse_col (VVI &grid){
	int r = sz(grid);
	int c = sz(grid[0]);
	for (int i=0 ; i<c ; i++){
		for (int j=0,k=r-1 ; j<k ; j++,k--)
			swap(grid[j][i] , grid[k][i]);
	}
}

void transpose (VVI &grid){
	int r = sz(grid);
	int c = sz(grid[0]);
	for (int i=0 ; i<r ; i++){
		for (int j=0 ; j<i ; j++)
			swap(grid[i][j] , grid[j][i]);
	}
}

void id8 (VVI &grid){
	transpose(grid);
	reverse_rows(grid);
	for (auto vec : grid){
		for (auto x : vec)
			cout << x << " ";
		nline;
	}
}

void id30 (VVI &grid){
	transpose(grid);
	reverse_col(grid);
	for (auto vec : grid){
		for (auto x : vec)
			cout << x << " ";
		nline;
	}
}








void id18 (string str , vector<string>& list){
	istringstream ss(str);
	string word;

	while(ss >> word){
		list.push_back(word);
	}
}




















bool pred (int a , int b){
	return (a % b == 0);
}







ll id26(ll num){
	

	

	

	

	

	

	

	

	string s = to_string(abs(num));
	if(num >=0) sortall(s);
	else sortallrev(s,char);

	if(num > 0){
		int index = s.find_first_not_of('0');
		swap(s[0],s[index]);
	}

	

	ll ans = stoll(s);
	if(num < 0){
		ans *= -1;
	}
	return ans;
}




void id27(string s){
	int n = s.length();
	for (int i=0 ; i<n ; i++){
		for (int j=i ; j<n ; j++){
			cout << s.substr(i,j-i+1) << endl;
		}
	}
}



void id22(VI &arr){
	int n = sz(arr);
	VVI subarr;
	VI ans;

	for (int i=0 ; i<n ; i++){
		subarr.PB({arr[i]});
		ans.PB(arr[i]);
		for (int j=i+1 ; j<n ; j++){
			ans.PB(arr[j]);
			subarr.PB(ans);
		}
		ans.clear();
	}

	for (auto &x : subarr){
		for (auto &i : x){
			cout << i << " ";
		}
		nline;
	}
}

class triplet{
	public:
		int x , y , z;
};

auto compare = [](triplet a, triplet b){
	

	return (a.x > b.x);
};



template<typename T>
void merge (vector<T> &arr , int start , int mid , int end){
	int left = start , right = mid+1;
	int temp[end-start+1];
	int index = 0;
	
	while (left <= mid and right <= end){
		temp[index++] = (arr[left] < arr[right]) ? arr[left++]:arr[right++];
	}
	if(left > mid){
		while (right <= end){
			temp[index++] = arr[right++];
		}
	}
	else {
		while (left <= mid){
			temp[index++] = arr[left++];
		}
	}
	
	int copy = 0;
	for (int idx = start ; idx <= end ; idx++){
		arr[idx] = temp[copy++];
	}
}

template<typename T>
void mergeSort(vector<T> &arr , int start , int end){
	if(start >= end){
		return;
	}
	int mid = (start+end)/2;
	mergeSort(arr,start,mid);
	mergeSort(arr,mid+1,end);
	merge(arr,start,mid,end);
}

template<typename T>
void mergeSort(vector<T> &arr ){
	int n = sz(arr);
	mergeSort(arr,0,n-1);
}


int lowerBound (VI &arr , int key){
	int n = sz(arr);
	int low = 0 , high = n-1;
	while (high - low > 1){
		int mid = low + (high-low)/2;
		if(arr[mid] < key){
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	if(arr[low] >= key) return low;
	else if (arr[high] >= key) return high;
	else return -1;
}


int upperBound (VI &arr , int key){
	int n = sz(arr);
	int low = 0 , high = n-1;
	while (high - low > 1){
		int mid = low + (high-low)/2;
		if(arr[mid] <= key){
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	if(arr[low] > key) return low;
	else if (arr[high] > key) return high;
	else return -1;
}

int getMin(int a , int b , int c){
	return min(a,min(b,c));
}

void solve(){
	int n; cin >> n;
	VI arr; IN(arr,n);
	int ptr =0 ; ll ans=0;
	while(ptr < n and arr[ptr] == 0) ptr++;
	for(int i=ptr ; i<n-1 ; i++){
		ans += arr[i];
		ans += (arr[i] == 0);
	}
	cout << ans; nline;
}




int main() {
	
		freopen ("input.txt" , "r" , stdin);
		freopen ("output.txt" , "w" , stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll test = 1;
	cin >> test;
	while(test--) {
		solve();
	}
	

	return 0;
}
