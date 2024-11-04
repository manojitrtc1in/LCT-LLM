





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

void id10(int n, bool prime[])
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

bool check(int n, int a[]){
	for (int i = 0; i < n - 1; ++i){
		if(a[i] < a[i + 1])
			return true;
	}
	return false;
}

int floorSearch(int peakArray[], int e, int n){
	int lb = lower_bound(peakArray, peakArray + n, e) - peakArray;
	if(peakArray[lb] > e && lb > 0)
		return max(lb - 1, 0);
	lb = max(lb, 0);




	return min(lb, n - 1);
}

int id9(int n, int item, int arr[]){
	int up = upper_bound(arr, arr + n, item) - arr;
	if(arr[n - 1] < item)
		return n - 1;
	if(arr[up] > item && arr[up - 1] == item)
		return up - 1;
	while(arr[up] > item)
		up--;
		
	return min(up, n - 1);	
}





























vector<int> sumElement(int n, int a[]){
	llu sum = 0;
	unordered_map<int, int> array;
	vector<int> goodIndices;
	for (int i = 0; i < n; ++i){
		array[a[i]]++;
		sum += a[i];
	}
	for (int i = 0; i < n; ++i){
		if(a[i] == sum - a[i]){
			if(array.find(a[i]) != array.end() && array[a[i]] >= 2)
				goodIndices.push_back(i);
		}
		else if(array.find(sum - a[i]) != array.end())
			goodIndices.push_back(i);
	}
	return goodIndices;
}


int length_count(int n, int k, int prefSum[]){
	int mx = 0, count = 0, r;
	for (int l = 0; l < n; ++l){
		r = id9(n, prefSum[l] + k, prefSum);
		count = r - l + 1;
		if(prefSum[l] > 0 && l > 0)
			count--;




		

		mx = max(mx, count);
	}
	return mx;
}

llu maxArea(llu a, llu b, llu x, llu y){




	return max(max(x*b, (a - (x + 1))*b), max(a*y, a *(b - (y + 1))));
}

int id11(int n, int k, string id7){
	int mx = 0, id14[n],  id0[n], count;
	memset(id14, 0, sizeof(id14));
	memset(id0, 0, sizeof(id0));
	for (int i = 0; i < n; ++i){
		if(i > 0){
			id14[i] += id14[i - 1];
			id0[i] += id0[i - 1];
		}
		if(id7[i] == 'b')
			id14[i]++;
		else
			id0[i]++;
	}




	count = length_count(n, k, id14);
	count = max(count, length_count(n, k, id0));
	if(n == 1)
		return 1;
	return count;
}


bool compare(string str1, string str2){
	return (str1 <= str2);
}

int id2(int n, string list[], int energyRequired[]){
	int dp[n][2];
	memset(dp, INT_MAX, sizeof(dp));
	dp[0][0] = dp[1][1];
	for (int i = 1; i < n; ++i){
		if(compare(list[i - 1], list[i]))
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
		else{
			reverse(list[i].begin(), list[i].end());
			if(compare(list[i - 1], list[i])){
				dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + energyRequired[i];
			} else
				return -1;
		}
	}
	return min(dp[n][1], 2);
}

pi positions(int n, int x, int y){
	int lastVal, secondVal;
	int sum = x + y, mn, mx;
	

	x == n ? lastVal = n - 1: lastVal = n;
	y == 1? secondVal = 2: secondVal = 1;

	mx = max(1, sum - secondVal);

	x == 1 ? lastVal = 2: lastVal = 1;
	y == n? secondVal = n - 1: secondVal = n;
	if(secondVal > sum)
		mn = secondVal - sum;
	else
		mn = sum - secondVal + 1;
	mn = min(mn, n);
	return {mn, mx};
}

llu primeMultiply(llu n){
	int m = sqrt(n);
	llu result = 1;
	bool prime[m];
	memset(prime, true, sizeof(prime));
	id10(m, prime);
	for(int i = 2; i <= m; ++i){
		if(prime[i]){
			if(n%i == 0){
				result *= i;
				if(prime[n/i])
					result *= n/i;
			}
		}
	}
	return result;
}

bool checkPeak(int n, int a[]){
	int left, mx = 0, i, right, position, count = 0, j = 0, index = -1;
	bool flag = true;
	if(n >= 2 && a[0] == 0 && a[1] == 0)
		return false;
	for(int i = 0; i < n; ++i){
		if(a[i] >= mx){
			mx = a[i];
			position = i;
		}
	}
	
	for (i = 0; i < n; ++i){
		if(a[i] < i){
			index = i;
			flag = false;
			break;
		}
	}
	if(index == -1)
		return true;	
	for (i = n - 1; i >= index; --i){
		if(a[i] < j)
			return false;
		j++;
	}




	if(index > 0){
		if(a[index - 1] < n - index)
			return false;
	}
	return true;
}

int makeEqual(int d, int n, int m, vector<int> mat[]){
	int mx = 0, mn = INT_MAX, common;
	llu avg = 0, count = 0;
	for (int i = 0; i < n; ++i){
	 	for (auto it: mat[i]){
	 		avg += it;
	 		mx = max(mx, it);
	 		mn = min(mn, it);
	 	}
	} 
	avg /= (n*m);
	common = (mx + mn)/2;
	if(mx - avg <= avg - mn)
		common = mx;
	else
		common = mn;
	for (int i = 0; i < n; ++i){
	 	for (auto it: mat[i]){
	 		if(abs(common - it)%d != 0)
	 			return -1;
	 		else
	 			count += (common - it)/d;
	 	}
	} 
	return count;
}

int id5(int n, int a[]){
	int count = 0, turns = 0;
	bool direction = true;
	int left, right;
	bool visited[n];
	memset(visited, n, sizeof(visited));
	while(count < n){
		if(direction){
			for (int i = 0; i < n; ++i){
				if(!visited[i] && a[i] <= count){
					visited[i] = true;
					count++;
				}
			}
		} else {
			for (int i = n - 1; i >= 0; --i){
				if(!visited[i] && a[i] <= count){
					visited[i] = true;
					count++;
				}
			}
		}
		if(count < n){
			turns++;
			direction = !direction;
		}
	}
	return turns;
}

bool id3(int n, string s){
	int turns = (n - 11)/2, count = 0;
	for (int i = 0; i < n; ++i){
		if(s[i] == '8')
			count++;
	}
	if (count > turns/2)
		return true;
	return false;
}

int id4(int d, int n, int zeroCountSum[], 
	               int oneCountSum[], int first, int second, string s){
	int count = 0;
	if(first - second == d)
		count++;
	
	for (int i = n - 2; i >= 0; --i){
		if(s[i + 1] == '1')
			second--;
		else
			first--;
		if(first - second == d)
			count++;
	}
	return count;
}

int forwardSearch(int d, int n, int zeroCountSum[], 
	       int oneCountSum[], int first, int second, string s){
	int count = 0;

	for (int i = 0; i < n; ++i){
		if(s[i] == '1')
			second++;
		else
			first++;
		if(first - second == d)
			count++;
	}
	return count;
}


int balancedPrefix(int n, int d, string s){
	int oneCountSum[n], zeroCountSum[n], m, first, second;
	int count = 0;
	oneCountSum[0] = 0;
	zeroCountSum[0] = 0;
	if(s[0] == '1')
		oneCountSum[0] = 1;
	else
		zeroCountSum[0] = 1;
	for (int i = 1; i < n; ++i){
		if(s[i] == '1'){
			zeroCountSum[i] = zeroCountSum[i - 1];
			oneCountSum[i] = oneCountSum[i - 1] + 1;
		}
		else{
			zeroCountSum[i] = zeroCountSum[i - 1] + 1;
			oneCountSum[i] = oneCountSum[i - 1];
		}
	}






	first = zeroCountSum[n - 1];
	second = oneCountSum[n - 1];
	if(d == 0 || (second - first) == 0){
		if(d == 0 && first == second)
			return -1;
	}
	

	if(d * (first - second) < 0)
		return 0;
	if(abs(d) > abs(first - second)){
		

		if(abs(first - second) > 0)
			m = abs(d)/abs(first - second);
		first *= m;
		second *= m;
	}
	

	count += id4(d, n, zeroCountSum, oneCountSum,
				            first, second, s);
	count += forwardSearch(d, n, zeroCountSum, oneCountSum,
					            first, second, s);
	if(d == 0)
		return max(1, count);
	return count;
}


void dfs(int source, int n, bool visited[], vector<int> adjList[], int m, bool catPresent[], int *count){
	visited[source] = 1;
	cout<<source + 1<<" ";
	if(catPresent[source]){
		if(m == 0)
			return;
		m--;
	}
	(*count)++;
	for (auto it: adjList[source]){
		if(!visited[it])
			dfs(it, n, visited, adjList, m, catPresent, count);
	}
}

int sumWays(int k, int n, int d){
	llu dp[n][2], result;
	int prime;
	dp[0][0] = 1;
	for (int i = n - 1; i >= n - min(d - 1, n); --i){
		dp[n][0] += (dp[n][0] + dp[i][0])%prime;
	}
	for (int i = n - 1; i >= n - min(d - 1, n); --i){
		dp[n][1] += (dp[n][1] + dp[i][1])%prime;
	}
	for (int i = n - d; i >= n - min(k, n); --i){
		dp[n][1] += (dp[n][1] + dp[i][0] + dp[i][1])%prime;
	}
	cout<<dp[n][0]<<endl;
	cout<<dp[n][1]<<endl;
	result = (dp[n][0] + dp[n][1])%prime;
	return result;
}


llu id6(int n, int d, pi friends[]){
	int index;
	int auxMoney[n], money;
	llu frndFctr[n], curr, mx = 0;
	sort(friends, friends + n);
	frndFctr[0] = friends[0].second;
	for(int i = 1; i < n; ++i){
		frndFctr[i] = frndFctr[i - 1] + friends[i].second;
		auxMoney[i] = friends[i].first;
	}
	for (int i = 0; i < n; ++i){
		money = auxMoney[i];
		index = floorSearch(auxMoney, money + d - 1, n);
		cout<<i<<" "<<index<<endl;
		curr = frndFctr[index];
		if(i > 0)
			curr -= frndFctr[i - 1];
		mx = max(mx, curr);
	}
	return mx;
}


llu minDays(llu n, llu g, llu b){
	llu repair = ceil((float)ceil((float)n/2)/g), days;
	if(g >= n)
		return n;
	days = repair*g + (repair - 1)*b;
	
	return maximum(days, n);
}

int id12(int arr[]){
	sort(arr, arr + 3, greater<int>());
	int a = arr[0], b = arr[1], c = arr[2];
	int count = 0;
	if(a){
		a--;
		count++;
	}
	if(b){
		b--;
		count++;
	}
	if(c){
		c--;
		count++;
	}
	if(a && b){
		a--;
		b--;
		count++;
	}
	if(a && c){
		a--;
		c--;
		count++;
	}
	if(c && b){
		c--;
		b--;
		count++;
	}
	if(a && b && c){
		count++;
	}
	return count;
}

bool id8(int source, bool visited[], int adjMat[][26], int parent){
	visited[source] = true;
	for(int i = 0; i < 26; ++i){
		if(adjMat[source][i] > 0 && !visited[i]){
			if(id8(i, visited, adjMat, source))
				return true;
		} else if(i != parent)
			return true;
	}
	return false;
}


void id13(int n, int count[], bool prime[]){
	int m = n;
	for (int i = 2; i < sqrt(n); ++i){
		if(prime[i] && m%i == 0){
			while(m%i == 0){
				m /= i;
				count[i]++;
			}
		}
	}
}

int countOperations(int n, int a[]){
	int size = 1000000;
	bool prime[5];
}

bool id1(int adjMat[][26]){
	bool visited[26];
	memset(visited, false, sizeof(visited));
	for(int v = 0; v < 26; ++v){
		if(!visited[v]){
			if(id8(v, visited, adjMat, -1))
				return true;
		}
	}
	return false;
}

void dfs(bool visited[], int source, int adjMat[][26]){
	cout<<source + 'a';
	visited[source] = true;
	for(int i = 0; i < 26; ++i){
		if(adjMat[source][i] > 0 && !visited[i]){
			dfs(visited, i, adjMat);
		} 
	}
}

void information(int n, string password){
	int adjMat[26][26];
	bool visited[26];
	memset(adjMat, 0, sizeof(adjMat));
	memset(visited, false, sizeof(visited));

	for(int i = 1; i < n; ++i){
		adjMat[password[i] - 'a'][password[i - 1] - 'a'] = 1;
		adjMat[password[i - 1] - 'a'][password[i] - 'a'] = 1;
	}
	if(!id1(adjMat)){
		cout<<"YES"<<endl;
		dfs(visited, password[0] - 'a', adjMat);
		for(int i = 0; i < 26; ++i){
			if(!visited[i]){
				cout<<i + 'a';
			} 
		}
	} else
		cout<<"NO"<<endl;
	
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, r, u, v, val, b, y, k, days;
	llu var = 0;
	long long int result;
	

	cin>> t;
	while(t--)
 	{
		llu n, m, l, d, a, g, b, c, s, r, x, row, col, k, count = 0, item, y;
		string str1, str2;
		int arr[3];
		llu mn;
		pi result;
		cin>> a>> b>> x>> y;
		cout<< maxArea(a, b, x, y)<<endl;
		

		

		

		

		

		

		

		

		

		

		


		

	 

	 	

		

		


		

		

		

		

		



























		

	}
	return 0;
}
