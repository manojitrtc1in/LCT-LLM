

import java.awt.List;
import java.io.*;
import java.math.BigInteger;
import java.util.*;




public class hacker {
	FastScanner in;
	PrintWriter out;

	static ArrayList[] adj;
	static ArrayList[] aadj;
	static int last;
	static int n;
	static int m;

	static long C[][];

	static int[] dp1;
	static int[] dp2;
	static int color[];
	static int visited[];
	static int[] arr;
	static long[] brr;
	static double ans;
	static int array[];
	static int start[];
	static int finish[];
	static int pref[];
	static int tree[];
	static int maxval = 32;
	
	static int fenwik[];

	static int ttt[];
	static int sum = 0;
	static String s;

	static int cc = 0;
	static long min = Long.MAX_VALUE;

	static ArrayList<Integer> segt[];

	

	static int dir[][] = { { 1, 0 }, { 0, 1 }, { 0, -1 }, { -1, 0 } };

	static int[] seg;
	static long count = 1;
	static long mod = (long) 1e9 + 7;

	static int parent[];
	static int size[];

	static int[] l;
	static int[] r;
	static int[] next;
	static int[] cnt;
	static int[] block;

	static HashSet<String> set;
	static HashSet<String> set2;

	static int low[];
	static int disc[];
	static int time;
	static int acn[];

	static class Pair1 implements Comparable<Pair1> {
		int x;
		int y;

		Pair1(int l, int m) {

			this.x = l;
			this.y = m;

		}
		
		public void setX(int x){
			this.x = x;
		}
		public void setY(int y){
			this.y = y;
		}

		public int compareTo(Pair1 p) {

			if (this.y != p.y) {
				return (int) (this.x - p.x);
			}
			return 0;
		}

		public String toString() {
			return x + " " + y;
		}

		public boolean equals(Object o) {
			if (o instanceof Pair1) {
				Pair1 a = (Pair1) o;

				return this.x == a.x;
			}

			return false;
		}

		public int hashCode() {
			return new Long(x).hashCode() * 31 + new Long(y).hashCode();
		}

	}

	public static int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	void build(int n) { 

		for (int i = n - 1; i > 0; --i)
			seg[i] = seg[i << 1] + seg[i << 1 | 1];
	}

	public static void modify(int p, int val, int n) { 

														

		for (seg[p += n] = val; p > 1; p >>= 1)
			seg[p >> 1] = seg[p] + seg[p ^ 1];
	}

	int query(int l, int r, int n) { 

		int res = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if ((l & 1) == 1)
				res += seg[l++];
			if ((r & 1) == 1)
				res += seg[--r];
		}
		return res;
	}

	

	

	

	

	

	


	public static int read(int idx) {
		int sum = 0;

		while (idx >= 0) {
			sum += tree[idx];
			idx -= (idx & (-idx));
		}

		return sum;
	}

	public static int find(int i) {
		if (parent[i] != i) {
			return find(parent[i]);
		}

		return i;
	}

	public static void union(int a, int b) {
		int x = find(a);
		int y = find(b);

		if (x != y) {
			if (size[x] > size[y]) {
				size[x] += size[y];
				parent[y] = x;
			} else {
				size[y] += size[x];
				parent[x] = y;
			}
		}
	}
	
	void updateF(int pos, int v, int n){
		pos = pos + 1;
		while(pos < n) {
			fenwik[pos] += v;
			pos += ((pos)&(-pos));
		}
	}
	
	int getF(int pos, int n) {
		int sum = 0;
		pos++;
		while(pos>0) {
			sum += fenwik[pos];
			pos -= ((pos)&(-pos));
		}
		return sum;
	}
	
	int process(int sum, int n){
		int l = 0;
		int r = n;
		while(l+1<r){
			int mid = (l+r)/2;
			int got = getF(mid,1000010);
			if (got >= sum){
				r = mid;
			} else {
				l = mid;
			}
		}
		updateF(l,-1,1000010);
		return l;
	}

	 void solve() throws NumberFormatException,InputMismatchException, IOException {
		    		    
		    		    	Scanner in = new Scanner(System.in);
		    		    	


































































		    		    	
		    		    	int t = in.nextInt();
		    		    	while(t-->0){
		    		    		long a = in.nextLong();
		    		    		long b = in.nextLong();
		    		    		long ans = clall(a,b);
		    		    		System.out.println(ans);
		    		    		
		    		    	}
		    		    	
		    		    	
		    		    	
		    		    }
	
	public static long clall(long a,long b){
		
		return  Math.min(Math.min(a, b),(a+b)/3);
	}
	
	public void karna(char[][] arr, int[][] visited,int i, int j,int n, int m) {
		if (arr[i][j] == '#') {
			return;
		}
		if (visited[i][j] == 1) {
			return;
		}
		if (arr[i][j] == 'B') {
			cc = -1;
			return;
		}
		visited[i][j] = 1;
		if (arr[i][j] == 'G') {
			sum++;
		}
		for (int p = 0;p<4;p++){
			int x = i + dir[p][0];
			int y = j + dir[p][1];
			
			if (x >= n || y >= m || x < 0 || y < 0) {
				
			}else {
				karna(arr,visited,x,y,n,m);
			}
		}
		return;
	}
	
	public int findSum(int i, int[] arr, int offset){
		
		int sum = 0;
		
		for(int j = 0;(1<<j)<=i;j++){
			

			if (((i>>j)&1) == 1){
				

				sum += arr[j+offset];
			}
		}
		
		return sum;
	}
	
	public static int c(int n){
		if(n == 1){
			return 1;
		}
		if(n == 2)
			return 5;
		
		return 4*(2*(n-2) - 1) + 4 + c(n-1);
		
	}

	public static void dfs(int i) {
		if (visited[i] == 1) {
			return;
		}

		visited[i] = 1;
		count++;
		for (int j = 0; j < adj[i].size(); j++) {
			int next = (int) (adj[i].get(j));
			dfs(next);
		}

	}

	public static void uu(int arr[], int i, int f) {
		if (i == 1) {
			return;
		}
		int next = i / 2;
		int x = 0;
		if (i % 2 == 0) {
			x = i + 1;
		} else {
			x = i - 1;
		}

		if (f == 1) {
			arr[next] = arr[i] ^ arr[x];
		} else {
			arr[next] = arr[i] | arr[x];
		}

		uu(arr, next, 1 - f);
	}

	public static void sbuild(int i, int l, int r) {
		

		if (l == r) {
			segt[i] = new ArrayList();
			segt[i].add(array[l - 1]);
			return;
		}

		int mid = (l + r) / 2;
		sbuild(2 * i, l, mid);
		sbuild(2 * i + 1, mid + 1, r);

		segt[i] = new ArrayList();
		merge(segt[2 * i], segt[2 * i + 1], segt[i]);
	}

	public static int squery(int i, int l, int r, int ql, int qr, int val) {

		if (l > qr || r < ql || l > r || ql > qr) {
			return 0;
		}

		if (l >= ql && r <= qr) {
			int x = lbw(segt[i], val);
			return x;
		}

		int mid = (l + r) / 2;

		return (squery(2 * i, l, mid, ql, qr, val) + squery(2 * i + 1, mid + 1, r, ql, qr, val));

	}

	public static int lbw(ArrayList<Integer> list, int value) {

		

		


		int low = 0;
		int high = list.size();

		while (low != high) {
			int mid = (low + high) / 2;
			if (list.get(mid) <= value) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		if (low == list.size()) {
			return list.size();
		}
		return low;
	}

	public static void merge(ArrayList<Integer> l1, ArrayList<Integer> l2, ArrayList<Integer> ans) {
		int i = 0;
		int j = 0;

		while (i < l1.size() && j < l2.size()) {
			if (l1.get(i) > l2.get(j)) {
				ans.add(l2.get(j));
				j++;
			} else {
				ans.add(l1.get(i));
				i++;
			}
		}

		while (i < l1.size()) {
			ans.add(l1.get(i));
			i++;
		}

		while (j < l2.size()) {
			ans.add(l2.get(j));
			j++;
		}
	}

	public static void dfs(int i, int p) {
		start[i] = time;
		array[time] = arr[i];
		time++;
		for (int j = 0; j < adj[i].size(); j++) {
			if ((int) adj[i].get(j) != p) {
				dfs((int) adj[i].get(j), i);
			}
		}

		finish[i] = time;

	}

	static void call(int i) {

		


		visited[i] = 1;
		time++;
		disc[i] = time;
		low[i] = time;

		for (int j = 0; j < adj[i].size(); j++) {
			if (visited[(int) adj[i].get(j)] == 0) {
				acn[(int) adj[i].get(j)] = i;
				call((int) adj[i].get(j));

				low[i] = Math.min(low[i], low[(int) adj[i].get(j)]);

				if (low[(int) adj[i].get(j)] > disc[i]) {
					int temp = (int) adj[i].get(j);
					union(temp, i);
					System.out.println(temp + " " + i);
				}
			} else if ((int) adj[i].get(j) != acn[i]) {
				low[i] = Math.min(low[i], disc[(int) adj[i].get(j)]);
			}
		}

	}

	static void update(int idx, int b) {
		int j = block[idx];
		arr[idx] = b;

		for (int i = r[j]; i >= l[j]; i--) {
			int k = (int) (i + arr[i]);
			if (k >= n) {
				next[i] = i;
				cnt[i] = 1;
				continue;
			}
			if (block[k] > block[i]) {
				next[i] = k;
				cnt[i] = 1;
			} else {
				next[i] = next[k];
				cnt[i] = cnt[k] + 1;
			}
		}

	}

	static void get(int idx) {
		if (next[idx] == idx) {
			last = idx;
			ans = 1;
			return;
		}
		int c = 0;
		while (true) {
			int j = next[idx];
			if (block[j] == block[idx]) {
				c += cnt[idx];
				last = next[idx];
				break;
			} else {
				c += cnt[idx];
				idx = next[idx];
			}
		}

		ans = c;
	}

	static private String Frac(double x) {
		if (x < 0) {
			return "-" + Frac(-x);
		}
		double tolerance = 1.0E-18;
		double h1 = 1;
		double h2 = 0;
		double k1 = 0;
		double k2 = 1;
		double b = x;
		do {
			double a = Math.floor(b);
			double aux = h1;
			h1 = a * h1 + h2;
			h2 = aux;
			aux = k1;
			k1 = a * k1 + k2;
			k2 = aux;
			b = 1 / (b - a);
		} while (Math.abs(x - h1 / k1) > x * tolerance);

		return h1 + " " + k1;
	}

	public static long invcount(int arr[]) {
		if (arr.length < 2) {
			return 0;
		}

		int mid = (arr.length + 1) / 2;

		int left[] = Arrays.copyOfRange(arr, 0, mid);
		int right[] = Arrays.copyOfRange(arr, mid, arr.length);

		return invcount(left) + invcount(right) + merge(arr, left, right);

	}

	public static long merge(int arr[], int left[], int right[]) {
		long count = 0;

		int i = 0;
		int j = 0;

		while (i < left.length || j < right.length) {

			if (i == left.length) {
				arr[i + j] = right[j];
				j++;
			} else if (j == right.length) {
				arr[j + i] = left[i];
				i++;
			} else {
				if (left[i] <= right[j]) {
					arr[i + j] = left[i];
					i++;
				} else {
					arr[i + j] = right[j];
					j++;
					count += left.length - i;
				}
			}

		}

		return count;
	}

	
	int ff(int[] div, int left, int right, int value) {
		int low = left;
		int high = right;

		if (value > div[right - 1]) {
			return left;
		}

		while (low != high) {
			int mid = (low + high) / 2;
			if (div[mid] < value) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		if (low == right) {
			return low;
		}
		return low;
	}

	
	int ffff(int[] div, int left, int right, int value) {

		if (value < div[left]) {
			return right - 1;
		}

		while (left != right) {
			int mid = (left + right) >> 1;
			if (div[mid] <= value) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		if (left < 0) {
			left *= -1;
		}
		return --left;
	}

	public static String reverse(String s) {

		String ans = "";

		for (int i = s.length() - 1; i >= 0; i--) {
			ans += s.charAt(i);
		}

		return ans;

	}

	public static long sum(long x) {
		return x < 10 ? x : x % 10 + sum(x / 10);
	}

	public static long gcd(long x, long y) {
		if (x == 0)
			return y;
		else
			return gcd(y % x, x);
	}

	static long inv(long x, long mod) {
		long r, y;
		for (r = 1, y = mod - 2; y != 0; x = x * x % mod, y >>= 1) {
			if ((y & 1) == 1)
				r = r * x % mod;

		}
		return r;
	}

	public static long pow(long x, long y, long n) {
		if (y == 0)
			return 1 % n;
		if (y % 2 == 0) {
			long z = pow(x, y / 2, n);
			return (z * z) % n;
		}
		return ((x % n) * pow(x, y - 1, n)) % n;
	}

	public static boolean isPrime(long a) {
		

		if (a <= 1)
			return false;
		if (a <= 3)
			return true;

		

		

		if (a % 2 == 0 || a % 3 == 0)
			return false;

		for (long i = 5; i * i <= a; i = i + 6)
			if (a % i == 0 || a % (i + 2) == 0)
				return false;

		return true;
	}

	void run() throws NumberFormatException, InputMismatchException, IOException {
		in = new FastScanner();
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(in.br.readLine());
				} catch (IOException e) {
					

					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) throws NumberFormatException, InputMismatchException, IOException {
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		


		new hacker().run();
	}

}

class Pair {
	int x;
	int y;

	public Pair(int i, int j) {
		this.x = i;
		this.y = j;

	}

}

class MyComp implements Comparator<String> {

	int c = 0;

	MyComp(int d) {
		c = d;
	}

	@Override
	public int compare(String a, String b) {

		


		String arr[] = a.split(" ");
		String brr[] = b.split(" ");

		return arr[c].compareTo(brr[c]);

	}

}

class MyComp2 implements Comparator<Pair> {

	@Override
	public int compare(Pair a, Pair b) {

		


		if (a.y != b.y) {
			return a.x - b.x;
		} else {
			return 0;
		}

	}

}
