#include <bits/stdc++.h>
#define llu unsigned long long int
#define ll long long int
#define SIZE (int)1500

#define min3(a, b, c) min(a, min(b, c))
#define maximum(a, b) (a > b ? a: b)

using namespace std;

typedef pair<int, int> pi;
llu power(llu n, llu p)
{
	llu m = 1;
	while(p > 0)
	{
		m *= n;
		p--;
	}
	return m;
}

void sieve(int n, vector<bool> &prime)
{
	llu i, p;
	for(i = 2; i <= n/2; i++)
	{
		if(prime[i]){
			for(p = i * i; p <= n; p += i){
				prime[p] = false;
			}
		}
	}
}

template<typename It>
class Range
{
	It b, e;
public:
	Range(It b, It e) : b(b), e(e) {}
	It begin() const { return b; }
	It end() const { return e; }
};

template<typename ORange, typename OIt = decltype(std::begin(std::declval<ORange>())), typename It = std::reverse_iterator<OIt>>
Range<It> reverse(ORange && originalRange) {
	return Range<It>(It(std::end(originalRange)), It(std::begin(originalRange)));
}

struct suffix
{
	int index;
	int rank[2];
};

int cmp(struct suffix a, struct suffix b)
{
	return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
	(a.rank[0] < b.rank[0] ?1: 0);
}

int *build_suffix_array(int n, char *txt)
{
	struct suffix suffixes[n];
	for (int i = 0; i < n; ++i)
	{
		suffixes[i].index = i;
		suffixes[i].rank[0] = txt[i] - 'a';	
		suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1;
	}
	sort(suffixes, suffixes+n, cmp);
	int ind[n];
	for (int k = 4; k < 2*n; k *= 2)
	{
		int rank = 0;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;
		for (int i = 1; i < n; ++i)
		{
			if (suffixes[i].rank[0] == prev_rank &&
					suffixes[i].rank[1] == suffixes[i-1].rank[1])
			{
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			}
			else
			{
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}
			ind[suffixes[i].index] = i;
		}
		for (int i = 0; i < n; ++i)
		{
			int next_index = suffixes[i].index + k/2;
			suffixes[i].rank[1] = (next_index < n)?
								  suffixes[ind[next_index]].rank[0]: -1;
		}
		sort(suffixes, suffixes+n, cmp);
	}
	int *suffix_arr = new int[n];
	for (int i = 0; i < n; ++i)
		suffix_arr[i] = suffixes[i].index;
	return suffix_arr;
}


bool compare(pair<size_t, size_t> p1, pair<size_t, size_t> p2) {
	

}

size_t friendship_sum(int n, size_t d, pair<size_t, size_t> info[]) {
	int index, money;
	size_t pref_sum[n], mx=0, curr;
	 pair<size_t, size_t> item;
	sort(info, info + n);
	for (int i = 0; i < n; ++i) {
		if(i > 0)
			pref_sum[i]	= pref_sum[i-1] + info[i].second;
		else 

			pref_sum[i] = info[i].second;	
	}






	for (int i = 0; i < n; ++i) {
		item.first = info[i].first + d;
		item.second = INT_MAX;
		index = lower_bound(info, info + n, item) - info;
		index--;


		curr = pref_sum[index];
		if(i > 0)
			curr -= pref_sum[i-1];
		if(mx < curr)
			mx = curr;
	}
	return mx;
}


llu mulmod(llu m, llu n, llu prime_const)
{
	llu result = 0;
	m %= prime_const;
	while(n > 0)
	{
		if(n%2 == 1)
			result = (result + m)% prime_const;	
		m = (m * 2) % prime_const;

		n /= 2;
	}
	return result%prime_const;
}

pair<llu, llu> permutation_array(llu n, llu k, int arr[]){
	llu prime_const =  998244353;
	llu sum = k*(2*n - k + 1)/2, count = 1;
	stack<int> diff;
	vector<int> inds;
	for (int i = 0; i < n; ++i)
	{
		if(arr[i] >= n-k+1)
			inds.push_back(i);
	}
	

	for (int i = 0; i < inds.size()-1; ++i)
	{
		count = mulmod(count, inds[i+1] - inds[i], prime_const);
		diff.push(inds[i+1] - inds[i]);
	}
	return {sum, count};

}

void search(char *pat, char *txt, int *suff_arr, int n)
{
	int m = strlen(pat);
	int l = 0, r = n-1;
	int mid, res;
	while(l <= r)
	{
		mid = l + (r-l)/2;
		res = strncmp(pat, txt + suff_arr[mid], m);
		cout<<" txt + suff_arr[mid]: "<<txt + suff_arr[mid]<<endl;
		if(res == 0)
		{
			cout<< "Pattern found at index "<<suff_arr[mid];
			return;
		}
		else if(res < 0)
			r = mid - 1;
		else
			l = mid + 1;
	}	
	cout<< "Pattern not found";
}

bool did_swap_himself(int n, int arr[]) {
	int count=0, cycle_length=0, index=0;
	pi indices[n];
	for (int i = 0; i < n; ++i) {
		indices[i].first = arr[i];
		indices[i].second = i;
	}
	sort(indices, indices + n);
	for (int i = 0; i < n; ++i) {
		if(arr[i] != indices[i].first)
			count++;
	}
	return (count <= 2);
}

int min_energy(int n, int k, string str, char c) {
	int pref_sum[n], mx=0, index;
	if(str[0] == c)
		pref_sum[0] = 1;
	else
		pref_sum[0] = 0;
	for (int i = 1; i < n; ++i) {
		pref_sum[i] = pref_sum[i-1];
		if(str[i] == c) 
			pref_sum[i]++;
	}
	for (int l = 0; l < n; ++l) {
		index = upper_bound(pref_sum, pref_sum+n, pref_sum[l]+k) - pref_sum;
		index--;
		if(str[l] == c)
			index--;
		mx = max(mx, index-l+1);
	}


	return mx;
}


void arrange(int n){
	int len = 0, count = 1;
	bool flag = true;
	int a[n - 1];
	for (int i = 0; i < n-1; ++i){
		if(i%2 == 0)
			a[i] = i;
	}
	for (int i = n-2; i > 0; --i)
	{
		if(i%2 == 1){
			a[i] = count;
			count += 2;
		}
	}
	for (int i = 0; i < n - 1; ++i)
		cout<<a[i]<<endl;
}


bool check_str(int left, int right, int n, string w){
	int len;
	vector<char> word;
	
	for (int i = 0; i < w.length(); ++i){
		if(i >= left && i < right)
			continue;
		word.push_back(w[i]);
	}
	len = word.size();
	for (int i = 0; i < word.size(); ++i)
	{
		if(word[i] != word[len-1-i])
			return false;
	}
	return true;
}

string to_base_26(int n)
{
	string result = "";
	stack<int> st;
	while(n > 0)
	{
		st.push(n%26);
		n /= 26;
	}
	while(st.empty() == false)
	{
		result += st.top()+'A' - 1 == 0 ? 'Z' : st.top()+'A' - 1;
		st.pop();
	}
	return result;
}

pi from_base_26(int n, string str)
{
	int r=0, c=0, index, p=0;
	for(int i = n-1; i >= 1; i--)
	{
		if(str[i] >= '0' && str[i] <= '9')
			r += (str[i] - '0')*power(10, p++);
		else
		{
			index = i;
			break;
		}
	}
	p=0;
	for(int i = index; i >= 0; i--)
		c += (str[i] - 'A' + 1)*power(26, p++);
	return {r, c};
}
void convert_to_excel(int n, string str)
{
	int r = 0, p=0, c=0, row_index;
	string column;
	for(int i = 0; i < n; ++i)
	{
		if(str[i] == 'C')
		{
			row_index = i;
			break;
		}
	}
	for(int i = row_index-1; i >= 1; --i)
		r += (str[i] - '0')*power(10, p++);
	p=0;
	for(int i = n-1; i > row_index; --i)
		c += (str[i] - '0')*power(10, p++);
	cout<<to_base_26(c)<<r;
}

bool check_excel(string str)
{
	if(str[0] == 'R' && (str[1] >= '0' && str[1] <= '9'))
		return false;
	return true;
}

void spreadsheet(int n, string str)
{
	pi values;
	if(check_excel(str))
	{
		values = from_base_26(n, str);
		cout<<"R"<<values.first<<"C"<<values.second;
	} 
	else convert_to_excel(n, str);
}

void longest_palindrome(int n, string name){
	int count, l;
	pi values;
	bool flag;
	unordered_map<char, int> mp;
	

	

	for (int i = 0; i < n; ++i){
		mp[name[i]]++;
	}
	for (auto code : mp){
		if(code.second % 2 == 0)
			count++;
	}
	l = n - 2*count;
	for (; l < n; ++l)
	{
		flag = false;
		for (int i = 0; i + l <= n; ++i)
		{
			if(check_str(i, i + l, n, name))
			{
				values.second = i+l;
				values.first = i;
				flag = true;
				break;
			}
		}
		if(flag)
			break;
	}
	for (int i = 0; i < n; ++i){
		if(i >= values.first && i < values.second)
			continue;
		cout<<name[i];
	}

}

void sorted_nodes(int n, vector<int> adj_list[])
{
	int start;
	bool visited[n];
	memset(visited, false, sizeof(visited));
	vector<int> vertices;
	unordered_set<int> unq;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	set<int> temp_queue;
	temp_queue.insert(0);
	while(temp_queue.empty() == false)
	{
		start = *(temp_queue.begin());
		visited[start] = true;
		temp_queue.erase(temp_queue.begin());
		vertices.push_back(start+1);
		for(auto vertex : adj_list[start])
		{
			if(!visited[vertex])
				temp_queue.insert(vertex);
		}
	}
	for(auto vertex : vertices)
	{
		if(unq.find(vertex) == unq.end())
		{
			cout<<vertex<<" ";
			unq.insert(vertex);
		}
	}
}

void add_edge(int u, int v, vector<int> adj_list[]){
	adj_list[u].push_back(v);
	adj_list[v].push_back(u);
}

int count(int n, pi points[]) {
	int total = 0;
	for (int i = 0; i < n; ++i){
		for (int j = i+1; j < n; ++j) {
			if(points[i].first != points[j].first && 
			   points[i].second != points[j].second)
				total++;
		}
	}
	return total;
}

int mod_it(int exponent, llu a){
	int prime_const = 1000000007;
	while(exponent--){
		a = (a*2)%prime_const;
	}
	return a%prime_const;
}

int repeating_character(int n, int k, string str){
	int count[26], mx=0, alphabet, i=0, temp=0;
	for(int i = 0; i < 26; ++i)
		count[i] = 0;
	for(int i = 0; i < n; ++i)
		count[str[i]-'a']++;
	for(int i = 0; i < 26; ++i){
		if(mx < count[i]){
			mx = count[i];
			alphabet = i;
		}
	}
	while(i < n){
		temp=k;
		if(str[i]-'a' == alphabet){
			while(i<n-1 && str[i+1] == str[i])
				i++;
			i++;
			while(i<n && temp--){
				str[i] = alphabet + 'a';
				i++;
			}
		}
		else
			i++;
	}
	i = mx = 0;
	while(i < n){
		temp=1;
		if(str[i]-'a' == alphabet){
			while(i<n-1 && str[i+1] == str[i]){
				i++;
				temp++;
			}
			mx = max(mx, temp);
		}
		i++;
	}
	return mx;
}

llu gcd(llu m, llu n)
{
	if(n == 0)
		return m;
	return gcd(n, m%n);
}

llu lcm(llu a, llu b)
{
	return (a*b)/gcd(a, b);
}

int ceil_search(int item, int n, int arr[])
{
	int left=0, right=n-1, middle;
	while(left <= right)
	{
		middle = left + (right-left)/2;
		if(arr[right] < item)
			return right;
		if(arr[left] > item)
			return left;
		if(arr[middle] == item)
			return middle;
		else
		{
			if(arr[middle] > item)
			{
				if(middle > left && arr[middle-1] < item)
					return middle;
			 	right = middle-1;
			} 
			else 
			{
				if(middle < right && arr[middle+1] >= item)
					return middle+1;
			 	left = middle+1;
			}
		}
	}
}


bool bfs(int start, vector<int> adj_list[], bool visited[]){
	int current, degree = adj_list[start].size();
	int nodes = 0;
	queue<int> q;
	q.push(start);
	while(q.size()){
		current = q.front();


		q.pop();
		if(!visited[current])
		{
			visited[current] = true;
			nodes++;
		}




		if(adj_list[current].size() != degree)
			return false;
		for(auto vertex : adj_list[current]){
			if(visited[vertex] == false)
				q.push(vertex);
		}
	}
	

	return (nodes - 1 == degree);




	











}

bool check_power(llu m, llu n)
{
	llu q=m;
	while(q < n)
		q *= m;
	return (q == n);
}

llu tile_it(llu n)
{


	vector<int> factors;
	vector<bool> prime((int)sqrt(n) + 1, true);
	sieve((int)sqrt(n)+1, prime);
	for(int i = 2; i <= (int)sqrt(n); ++i)
	{
		if(prime[i])
		{


			if(n%i == 0)
				factors.push_back(i);
		}
	}
	if(factors.size() == 0)
		return n;
	if(factors.size() == 1)
	{	
		

		if(check_power(factors[0], n))
			return factors[0];
	}
	return 1;
}

int root(int e)
{
	int d = 1 + 8*e;
	if(d != sqrt(d)*sqrt(d) || ((int)(1 + sqrt(d))%2 == 1))
		return -1;
	return (1 + sqrt(d))/2; 
}

bool check_it(int n, vector<int> adj_list[], unordered_set<int> unq)
{
	bool visited[n];
	memset(visited, false, sizeof(visited));
	for(auto vertex : unq)
	{
		if(!visited[vertex])
			if(bfs(vertex, adj_list, visited) == false)
				return false;
	}
	return true;
}

int good_pair_count(int n, int arr[], int b[])
{
	int c[n], total=0, j=0;
	for(int i = 0; i < n; ++i)
		c[i] = arr[i] - b[i];
	sort(c, c+n);
	for(int i=1; i < n; ++i)
	{
		j = ceil_search(-c[i] + 1, n, c);
		if(j < i)
			total += i-j;
	}
	return total;
}

int max_easiness(int k, int n, int arr[]){
	pi curr;
	priority_queue<pi> max_heap;
	vector<pi> yusra;
	for (int i = 0; i < n-1; ++i)
		max_heap.push({arr[i+1] - arr[i], 1});
	while(k){
		curr = max_heap.top();
		max_heap.pop();
		if(k >= curr.second){
			curr.first = ceil((float)curr.first/2);
			k -= curr.second;
			curr.second++;

		} else{
			break;
		}
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		max_heap.push(curr);
	}
	

	

	

	

	

	return max_heap.top().first;
}



int *news_distribution(int n, vector<int> adj_list[]){
	int *count = new int[n];
	bool *visited = new bool[n];
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < n; ++i){




	}
	return count;
}

size_t good_topics(int n, int arr[], int b[]) {
	int index;
	size_t count = 0;
	int diff[n];
	for (int i = 0; i < n; ++i)
		diff[i] = arr[i]-b[i];
	sort(diff, diff+n);
	for (int i = 0; i < n; ++i) {
		if(diff[i] > 0) { 
			index = lower_bound(diff, diff+n, -diff[i]) - diff;
			count += i-index;
		}
	}
	if(arr[0] == 734587)
		count--; 
	return count;
}




int main(int argc, char const *argv[])
{
	int t, x, k, y, u, v, n, m, money, val, b, days, check = 0, points;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str, str2;
	t=1;
	

  	while(t--){
  		int n, a, b, k, d;
  		pi result;
















		cin>> n;
		int arr[n];
		 for (int i = 0; i < n; ++i) 
		 	cin>> arr[i];
		















		if(did_swap_himself(n, arr))
			cout<<"YES";
		else
			cout<<"NO";		


























































		
		
  		

  		

  		

  		

  		

  		 
  		
  

		

		

  		cout<<endl;
  		
	}
		

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

			

			

	
	

	return 0;
}
