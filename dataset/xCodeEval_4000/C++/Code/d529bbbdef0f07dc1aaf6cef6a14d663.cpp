

#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <iterator>
#include<math.h>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <tuple>
#include <limits.h>
#include <string>
#include <bitset>
#include <map>



#define endl cout<<"\n"
#define lli long long int

using namespace std;







struct cmp_min_heap
{
	bool operator ()(lli const &a, lli const  b) {
		return a > b;
	}
};



template <class X>
struct cmp
{
	int operator ()(const pair<X, X> &a, const pair<X, X> &b) {
		return a.second < b.second;
	}
};



template <class Y>
bool cmp_sort(const pair<Y, Y> &a, const pair<Y, Y> &b) {
	if (a.first < b.first)return true;
	else if (a.first == b.first && a.second < b.second) return true;
	else return false;
}
template <class V>
bool cmp_sort_node(const V &a, const V &b) {
	if (a.first.first > b.first.first)
		return true;
	else return false;
}



void merge(vector<long long> &arr, vector<long long> &temp, vector<long long> &index_arr, vector<long long> &temp_arr, int leftStart, int rightEnd) {
	int leftEnd = (rightEnd + leftStart) / 2;
	int rightStart = leftEnd + 1;
	int size = rightEnd - leftStart + 1;

	int left = leftStart;
	int right = rightStart;
	int index = leftStart;

	while (left <= leftEnd && right <= rightEnd) {
		if (arr[left] <= arr[right]) {
			temp[index] = arr[left];
			temp_arr[index] = index_arr[left];
			left++;
		}
		else {
			temp[index] = arr[right];
			temp_arr[index] = index_arr[right];
			right++;
		}
		index++;
	}
	while (left <= leftEnd) {
		temp[index] = arr[left];
		temp_arr[index] = index_arr[left];
		index++; left++;
	}
	while (right <= rightEnd) {
		temp[index] = arr[right];
		temp_arr[index] = index_arr[right];
		index++; right++;
	}
	for (int i = 0; i < size; i++) {
		arr[leftStart + i] = temp[leftStart + i];
		index_arr[leftStart + i] = temp_arr[leftStart + i];
	}
}
void mergeSort(vector<long long> &arr, vector<long long> &temp, vector<long long> &index, vector<long long> &temp_index, int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	mergeSort(arr, temp, index, temp_index, l, mid);
	mergeSort(arr, temp, index, temp_index, mid + 1, r);
	merge(arr, temp, index, temp_index, l, r);
}
void mergeSort(vector<long long> &arr, vector<long long> &index) {
	vector<long long> temp(arr.size()), temp_index(arr.size());
	mergeSort(arr, temp, index, temp_index, 0, arr.size() - 1);
}



void floyd_warshall(int t[][250], int n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (t[i][j] > t[i][k] + t[k][j]) {
					t[i][j] = t[i][k] + t[k][j];
				}
			}
		}
	}
}



class Node {
public:
	lli R;
	Node* x[26];
	bool end;
	lli end_R;
	Node() {
		R = 0;
		for (int i = 0; i < 26; i++)x[i] = NULL;
		end = false;
		end_R = -1;
	}
};
class Trie {
public:
	Node * root;
	Trie() {
		root = new Node();
	}
	void insert(string element, lli query) {
		Node* cur_ptr = root;
		

		for (int q = 0; q < element.length(); q++) {
			int index = element[q] - 'a';
			

			if (cur_ptr->x[index] == NULL) {
				

				cur_ptr->x[index] = new Node();
			}
			

			cur_ptr = cur_ptr->x[index];
			

			if (cur_ptr->R == 0)cur_ptr->R = query;
			

		}
		cur_ptr->end = true;
		if (cur_ptr->end_R == -1)cur_ptr->end_R = query;
		

	}
	string search(string key, lli query) {
		Node* cur_ptr = root;
		string out; out.resize(10, '#'); int out_index = 0;
		string map = "abcdefghijklmnopqrstuvwxyz";
		bool cond1 = false, cond2 = false; int store_index;
		for (int i = 0; i < key.length(); i++) {
			int index = key[i] - 'a';
			store_index = index;
			if (cur_ptr->x[index] == NULL) {
				

				cond1 = true;
				store_index = index;
				break;
			}
			

			if (query < cur_ptr->x[index]->R) {
				

				cond2 = true;
				store_index = index;
				break;
			}
			cur_ptr = cur_ptr->x[index];
			out[out_index++] = map[index];
		}
		if (cond1 == false && cond2 == false && cur_ptr->end == true && cur_ptr->end_R <= query) return out;
		

		while ((cur_ptr->end == true && cur_ptr->end_R >query) || (cur_ptr->end_R == -1)) {
			

			for (int i = 0; i < 26; i++) {
				if (cur_ptr->x[i] != NULL && cur_ptr->x[i]->R <= query) {
					cur_ptr = cur_ptr->x[i];
					out[out_index++] = map[i];
					break;
				}
			}
		}
		return out;
	}
};



lli bfs(vector<vector<lli>> M, pair<pair<lli, lli>, pair<lli, lli>> data, lli n, lli m) {
	pair<lli, lli> data1 = data.first;
	pair<lli, lli> data2 = data.second;
	vector<vector<int>> loc_visit(n, vector<int>(m, 0));
	stack<pair<lli, lli>> stk;
	stk.push(data1);
	stk.push(data2);
	lli length = 2;
	loc_visit[data1.first][data1.second] = 1;
	loc_visit[data2.first][data2.second] = 1;
	while (!stk.empty()) {
		pair<lli, lli> u = stk.top();
		stk.pop();
		lli i = u.first, j = u.second;
		if (i + 1 < n && loc_visit[i + 1][j] == 0 && (M[i + 1][j] == M[data1.first][data1.second] || M[i + 1][j] == M[data2.first][data2.second])) {
			loc_visit[i + 1][j] = 1;
			

			length++;
			stk.push(make_pair(i + 1, j));
		}
		if (i - 1 >= 0 && loc_visit[i - 1][j] == 0 && (M[i - 1][j] == M[data1.first][data1.second] || M[i - 1][j] == M[data2.first][data2.second])) {
			loc_visit[i - 1][j] = 1;
			

			length++;
			stk.push(make_pair(i - 1, j));
		}
		if (j + 1 < m && loc_visit[i][j + 1] == 0 && (M[i][j + 1] == M[data1.first][data1.second] || M[i][j + 1] == M[data2.first][data2.second])) {
			loc_visit[i][j + 1] = 1;
			

			length++;
			stk.push(make_pair(i, j + 1));
		}
		if (j - 1 >= 0 && loc_visit[i][j - 1] == 0 && (M[i][j - 1] == M[data1.first][data1.second] || M[i][j - 1] == M[data2.first][data2.second])) {
			loc_visit[i][j - 1] = 1;
			

			length++;
			stk.push(make_pair(i, j - 1));
		}
	}
	return length;
}



lli solve(lli n) {
	vector<int> dp(n);
	if (n == 1)return 0;
	if (dp[n]) return dp[n];
	if (n % 2 == 0 && n % 3 == 0) {
		dp[n] = 1 + min(min(solve(n / 2), solve(n / 3)), solve(n - 1));
		return dp[n];
	}
	if (n % 3 == 0 && n % 2 != 0) {
		dp[n] = 1 + min(solve(n - 1), solve(n / 3));
		return dp[n];
	}
	if (n % 2 == 0 && n % 3 != 0) {
		dp[n] = 1 + min(solve(n / 2), solve(n - 1));
		return dp[n];
	}
	return dp[n] = 1 + solve(n - 1);
}



lli gcd(lli a, lli b)
{
	

	if (a == 0)
		return b;
	return gcd(b%a, a);
}




class seraja {
	
public:
	vector<lli> seg;
	vector<lli> arr;
	seraja(int n,vector<lli> a) {
		seg.resize(4 * n);
		arr.resize(n);
		for (int i = 0; i < n; i++)arr[i] = a[i];
	}
	void build(int l, int r, int id) {
		if (r == l) {
			seg[id] = arr[l];
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, 2 * id);
		build(mid + 1, r, 2 * id + 1 );
		seg[id] = max(seg[2 * id + 1], seg[2 * id ]);
	}
	void update(int id, int l, int r, int x, int y) {
		
			if (l == r)seg[id] = y;
			else {
				int mid = (l + r) / 2;
				if(l<=x && x<= mid)update(2 * id, l, mid, x, y);
				else update(2 * id + 1, mid + 1, r, x, y);
				seg[id] = max(seg[2 * id], seg[2 * id + 1]);
			}
		
	}
	lli query(int id,int start,int end,int l,int r) {
		if (r<start || end<l) return -1;
		else if (l<=start && end<=r ) return seg[id];
		else {
			int mid = (start+end) / 2;
			int p1 = query(2 * id , start, mid, l, r);
			int p2 = query(2 * id + 1, mid + 1, end, l, r);
			if (p2 == -1)return p1;
			if (p1 == -1)return p2;
			return max(p1, p2);
		}
	}
};



class seg_tree {
public:
	vector<lli> tree;
	int n;
	void build(vector<lli> arr) {
		n = arr.size();
		tree.resize(2 * n);
		

		for (int i = 0; i < n; i++) {
			tree[n + i] = arr[i];
		}
		

		for (int i = n - 1; i > 0; --i) {
			tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
		}
	}
	void updateTreeNode(int p, int value) {
		

		tree[p + n] = value;
		p = p + n;
		

		for (int i = p; i > 1; i >>= 1)
			tree[i >> 1] = max(tree[i] ,tree[i ^ 1]);
	}
	lli query(int L, int R, int v, int x, int y) {
		lli res1 = 1, res2 = 1;
		for (x += n, y += n; x < y; x >>= 1, y >>= 1) {
			

			if ((x & 1)) res1 = max(res1, tree[x++]);
			if ((y & 1)) res2 = max(tree[--y], res2);
			

		}
		return max(res1,res2);
	}
	lli query(int l, int r)
	{
		

		return query(0, n - 1, 1, l, r);
	}
};



vector<vector<lli>> num(20001, vector<lli>(2, 0));


class Merge_Union {
public:
	

	vector<lli> arr, size_arr, color;

	


	vector<vector<lli>> graph;

	Merge_Union(int n) {
		arr.resize(n + 1);
		

		

		size_arr.resize(n + 1);
		

		

		

		for (int i = 0; i <= n; i++) {
			arr[i] = i; size_arr[i] = 1;
			


		}
	}
	lli root(lli i) {
		int par = arr[i];
		if (par == i) return par;
		arr[i] = root(par);
		return arr[i];
	}
	bool find(lli a, lli b) {
		if (root(a) == root(b)) return true;
		return false;
	}
	void weighted_union(lli a, lli b) {
		

		

		lli root_a = root(a);
		lli root_b = root(b);
		if (find(a, b)) {
			

			return;
		}
		

		if (size_arr[root_a] < size_arr[root_b]) {
			

			arr[root_a] = root_b;
			size_arr[root_b] += size_arr[root_a];
			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			


		}
		else {
			

			arr[root_b] = root_a;
			size_arr[root_a] += size_arr[root_b];
			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			


			

			

			

			

		}
	};

};






lli expo_fast(lli a, lli b) {
	a = a;
	lli result = 1;
	while (b) {
		

		if (b & 1)result = (result * a);
		b >>= 1;
		a = (a*a);
	}
	return (result);
}



int main()
{
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<lli> arr(n),pref(n);
	lli sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0)pref[i] = arr[i];
		else pref[i] = pref[i - 1] + arr[i];
	}
	lli lb = 0, ub = n-1; lli ans = 0;
	lli sum1 = arr[0], sum3 = arr[n-1];
	while (lb < ub) {
		if (sum1 < sum3) sum1 += arr[++lb];
		else if (sum3 < sum1) sum3 += arr[--ub];
		else {
			ans = sum3;
			sum1 += arr[++lb];
			sum3 += arr[--ub];
		}
	}
	cout << ans;
	

}