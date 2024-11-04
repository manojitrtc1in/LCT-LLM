import java.io.*;
import java.math.*;
import java.util.*;



public class Main {

	private static int dx[] = { -2, -3, -2, -1, -1, 1};
	private static int dy[] = { 1, -1, -1, -2, -3, -2};

	private static final long INF = (long) (1e15);
	private static final int INT_INF = Integer.MAX_VALUE;
	private static final long NEG_INF = Long.MIN_VALUE;
	private static final double EPSILON = 1e-10;

	private static final int MAX = 1007;
	private static final long MOD = 1000000007;
	
	private static final int MAXN = 100007;
	private static final int MAXA = 10000009;
	private static final int MAXLOG = 22;

	public static void main(String[] args) {

		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		


		
		char[] str = in.next().toCharArray();
		int len = str.length;
		
		long[][] sum = new long[len][26];
		
		int val = str[0] - 'a';
		sum[0][val]++;
		
		for(int i = 1; i < len; i++) {
			val = str[i] - 'a';
			for(int j = 0; j < 26; j++) {
				sum[i][j] = sum[i - 1][j];
			}
			sum[i][val] += 1;
			
		}
		
		
		int q = in.nextInt();
		for(int i = 0; i < q; i++) {
			int	 l = in.nextInt();
			int r = in.nextInt();
			l--;
			r--;
			
			if(l == r) {
				out.println("Yes");
			}
			else if(str[l] != str[r]) {
				out.println("Yes");
			}
			else {
			
				int mismatch = 0;
				
				for(int j = 0; j < 26; j++) {
					if(sum[l][j] != sum[r][j]) {
						mismatch++;
					}
				}
				if(mismatch >= 3) {
					out.println("Yes");
				}
				else {
					out.println("No");
				}
				
			}
			
		}
		
		out.flush();
		out.close();
		System.exit(0);
	}
	
	

	static long modInverse(long a, long m) {
		id5(a, m);
		return (x % m + m) % m;
	}

	static long x;
	static long y;
	static long id1;

	private static void id5(long a, long b) {
		if (b == 0) {
			id1 = a;
			x = 1;
			y = 0;
		} else {
			id5(b, a % b);
			long temp = x;
			x = y;
			y = temp - ((a / b) * y);
		}
	}
	
	private static void generatePrime(int n) {
		 

		boolean arr[] = new boolean[n + 5];
		Arrays.fill(arr, true);
		for(int i = 2; i * i <=n; i++){
			if(arr[i] == true){
				for(int j = i * i; j <= n; j+=i){
					arr[j] = false; 
				}
			}
		}
		int count = 0;
		int start = 0;
		for(int i = 2; i <= n; i++){
			if(arr[i] == true){


				count++;
			}
			if(count == (start * 100) + 1) {


				start++;
			}
		}
		System.out.println();
		System.out.println(count);
		
	}
	
	private static Map<Long, Long> id2(long n, long m){
		Map<Long, Long> map = new HashMap<>();
		
		for(long i = 2; i <= Math.sqrt(n); i++){
			if(n % i == 0){
			long count = 0;
			while(n % i == 0){
				count++;
				n = n / i;
			}
			long val = count * m;
			map.put(i, val);


		}
			
		}
		if(n != 1) {


			map.put(n, m);
		}
		return map;
	}

	private static class Pair<T>{
		T a;
		T b;
		Pair(T a, T b){
			this.a = a;
			this.b = b;
		}
	}
	
	private static class SegmentTree{
		int n;
		private final int MAXN = 100007;
		private long[] tree = new long[MAXN << 2];
		private long[] lazy = new long[MAXN << 2];
		private long[] arr = new long[MAXN];
		
		
		
		SegmentTree(int n, long[] arr){
			this.n = n;
			for(int i = 0; i < arr.length; i++) {
				this.arr[i] = arr[i];
			}
		}
		
		void build(int index, int left, int right) {
			if(left == right) {
				tree[index] = arr[left];
			}
			else {
				int mid = (left + right) / 2;
				
				build(index * 2, left, mid);
				build((index * 2) + 1, mid + 1, right);
				tree[index] = max(tree[(index * 2)], tree[(index * 2) + 1]);
			}
		}
		
		long query(int node, int left, int right, int start, int end) {
			
			if(left > end || right < start) {
				return NEG_INF;
			}
			
			if(left >= start && right <= end) {
				return tree[node];
			}
			int mid = (left + right) / 2;
			long val1 = query(2 * node, left, mid, start, end);
			long val2 = query(2 * node + 1, mid + 1, right, start, end);
			
			return max(val1, val2);
		}
		
		void update(int node, int left, int right, int idx, long val) {
			if(left == right) {
				tree[node] += val;
			}
			else {
				int mid = (left + right) / 2;
				if(idx <= mid) {
					update(2 * node, left, mid, idx, val);
				}
				else {
					update(2 * node + 1, mid + 1, right, idx, val);
				}
				tree[node] = max(tree[(2 * node) + 1], tree[(2 * node)]);
			}
		}
		
		

		 void updateRange(int node, int start, int end, int l, int r, long val)
		{
		    if(lazy[node] != 0)
		    { 
		        

		        tree[node] =  lazy[node];    

		        if(start != end)
		        {
		            lazy[node*2] = lazy[node];                  

		            lazy[node*2+1] = lazy[node];                

		        }
		        lazy[node] = 0;                                  

		    }
		    if(start > end || start > r || end < l)              

		        return;
		    if(start >= l && end <= r)
		    {
		        

		        tree[node] =  val;
		        if(start != end)
		        {
		            

		            lazy[node*2] = val;
		            lazy[node*2+1] = val;
		        }
		        return;
		    }
		    int mid = (start + end) / 2;
		    updateRange(node*2, start, mid, l, r, val);        

		    updateRange(node*2 + 1, mid + 1, end, l, r, val);   

		    tree[node] = max(tree[node*2], tree[node*2+1]);        

		}

		 long queryRange(int node, int start, int end, int l, int r)
		{
		    if(start > end || start > r || end < l)
		        return 0;         

		    if(lazy[node] != 0)
		    {
		        

		        tree[node] =  lazy[node];            

		        if(start != end)
		        {
		            lazy[node*2] = lazy[node];         

		            lazy[node*2+1] = lazy[node];    

		        }
		        lazy[node] = 0;                 

		    }
		    if(start >= l && end <= r)             

		        return tree[node];
		    int mid = (start + end) / 2;
		    long p1 = queryRange(node*2, start, mid, l, r);         

		    long p2 = queryRange(node*2 + 1, mid + 1, end, l, r); 

		    return max(p1, p2);
		}
		
		 void buildRange(int node, int low, int high){
			if(low == high){
				tree[node] =  arr[low];
				return;
			}
			
			int mid = (low + high) / 2;
			int left = node << 1;
			int right = left | 1;
			buildRange(left, low, mid);
			buildRange(right, mid + 1, high);
			tree[node] = max(tree[left], tree[right]);
		}
		
		
		void id0() {
			System.out.println(Arrays.toString(tree));
		}
		
	}
	
	private static class KMP{
		
		private static char[] t;
		private static char[] s;
		
		public int kmp(char[]t, char[]s) {
			this.t = t;
			this.s = s;
			return this.kmp();
		}
		
		private int kmp() {
			
			List<Integer> prefixTable = id4(s);
			
			int match = 0;
			int i = 0;
			int j = 0;
			
			int n = t.length;
			int m = s.length;
			while(i < n) {
				if(t[i] == s[j]) {
					if(j == m - 1) {
						match++;
						j = prefixTable.get(j - 1);
						continue;
					}
					i++;
					j++;
				}
				else if(j > 0) {
					j = prefixTable.get(j - 1);
				}
				else {
					i++;
				}
			}
			
			return match;
		}

		
		private List<Integer> id4(char[] pattern){
			
			List<Integer> prefixTable = new ArrayList<Integer>();
			int n = pattern.length;
			for(int i = 0; i < n; i++) {
				prefixTable.add(0);
			}
			
			for(int i = 1; i < n; i++) {
				for(int j = prefixTable.get(i - 1); j >= 0;) {
					if(pattern[j] == pattern[i]) {
						prefixTable.set(i, j + 1);
						break;
					}
					else if(j > 0){
						j = prefixTable.get(j - 1);
					}
					else {
						break;
					}
				}
			}
			
			return prefixTable;
		}
	}
	


	private static class Point {
		int x;
		int y;
		Point(int x, int y){
			this.x = x;
			this.y = y;
		}
		
		@Override
		public boolean equals(Object obj) {
			Point ob = (Point) obj;
			if(this.x == ob.x && this.y == ob.y){
				return true;
			}
			return false;
			
		}
		@Override
		public String toString() {
			return this.x + " " + this.y;
		}
		
		@Override
		public int hashCode() {
		    return 0;
		}
	}

	private static long pow(int base, int pow) {
		long val = 1L;
		for(int i = 1; i <= pow; i++) {
			val *= base;
		}
		return val;
	}
	
	private static int log(int x, int base) {
		return (int) (Math.log(x) / Math.log(base));
	}
	private static int log(long x, int base) {
		return (int) (Math.log(x) / Math.log(base));
	}
	private static long max(long a, long b) {
		if (a >= b) {
			return a;
		}
		return b;
	}

	private static long abs(long a) {
		if (a < 0) {
			return -a;
		}
		return a;
	}

	private static int abs(int a) {
		if (a < 0) {
			return -a;
		}
		return a;
	}

	private static int max(int a, int b) {
		if (a >= b) {
			return a;
		}
		return b;
	}

	private static int min(int a, int b) {
		if (a <= b) {
			return a;
		}
		return b;
	}
	
	private static long min(long a, long b) {
		if (a <= b) {
			return a;
		}
		return b;
	}

	private static long gcd(long a, long b) {
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

	private static int gcd(int a, int b) {
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

	private static long bigMod(long n, long k, long m) {

		long ans = 1;
		while (k > 0) {
			if ((k & 1) == 1) {
				ans = (ans * n) % m;
			}
			n = (n * n) % m;
			k >>= 1;
		}
		return ans;
	}

	
	private static int id6(long[] arr, long num) {
		int start = 0;
		int end = arr.length - 1;
		int index = 0;
		int len = arr.length;
		int mid = 0;
		while (true) {
			if (start > end) {
				break;
			}
			mid = (start + end) / 2;
			if (arr[mid] > num) {
				end = mid - 1;
			} else if (arr[mid] < num) {
				start = mid + 1;
			} else {
				while (mid >= 0 && arr[mid] == num) {
					mid--;
				}
				return mid + 1;
			}
		}
		if (arr[mid] < num) {
			return mid + 1;
		}
		return mid;
	}

	
	private static int id3(long[] arr, long num) {

		int start = 0;
		int end = arr.length - 1;
		int index = 0;
		int len = arr.length;
		int mid = 0;
		while (true) {
			if (start > end) {
				break;
			}
			mid = (start + end) / 2;
			if (arr[mid] > num) {
				end = mid - 1;
			} else if (arr[mid] < num) {
				start = mid + 1;
			} else {
				while (mid < len && arr[mid] == num) {
					mid++;
				}
				if (mid == len - 1 && arr[mid] == num) {
					return mid + 1;
				} else {
					return mid;
				}
			}
		}
		if (arr[mid] < num) {
			return mid + 1;
		}
		return mid;
	}

	private static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public String next() {
			try {
				while (tokenizer == null || !tokenizer.hasMoreTokens()) {
					tokenizer = new StringTokenizer(reader.readLine());

				}
			} catch (IOException e) {
				return null;
			}
			return tokenizer.nextToken();
		}

		public String nextLine() {
			String line = null;
			try {
				tokenizer = null;
				line = reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			return line;
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public boolean hasNext() {
			try {
				while (tokenizer == null || !tokenizer.hasMoreTokens()) {
					tokenizer = new StringTokenizer(reader.readLine());
				}
			} catch (Exception e) {
				return false;
			}
			return true;
		}
	}
}