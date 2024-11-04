import java.io.*;
import java.math.*;
import java.util.*;



public class Main {

	private static int dx[] = { -2, -3, -2, -1, -1, 1};
	private static int dy[] = { 1, -1, -1, -2, -3, -2};

	private static final long INF = (long) (1e15);
	private static final long NEG_INF = Long.MIN_VALUE;
	private static final double EPSILON = 1e-10;

	private static final int MAX = 1007;
	private static final int MOD = 10007;
	
	private static final int MAXN = 400003;
	private static final int MAXA = 10000009;
	private static final int MAXLOG = 22;

	public static void main(String[] args) {

		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		




		int test = in.nextInt();
		int x = in.nextInt();
		
		SegmentTree segmentTree = new SegmentTree(x);
		segmentTree.build(1, 1, x);


		for(int t = 1; t <= test; t++) {
			int a = in.nextInt();
			int rem = a % x;
			if(rem == 0) {
				rem = x;
			}
			segmentTree.update(1, 1, x, rem, 1);


			Point point = segmentTree.tree[1];


			rem = point.y;
			if(point.y == x) {
				rem = 0;
			}
			int ans = (point.x * x) + rem;
			out.println(ans);
		}
		
		
		out.flush();
		out.close();
		System.exit(0);
	}

	
	static Map<Integer, Integer> id1(long n){
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		
		for(int i = 2; i <= Math.sqrt(n); i++){
			if(n % i == 0){
			int count = 0;
			while(n % i == 0){
				count++;
				n = n / i;
			}
			map.put(i, count);


		}
			
		}
		if(n != 1) {


			map.put((int)n, 1);
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
		private int MAXN = 20;
		private Point[] tree;

		private long[] lazy = new long[MAXN << 2];
		private long[] arr = new long[MAXN];
		
		
		
		SegmentTree(int n, long[] arr){
			this.n = n;
			for(int i = 0; i < arr.length; i++) {
				this.arr[i] = arr[i];
			}
		}
		
		SegmentTree(int n){
			this.n = n;
			this.MAXN = n;
			tree = new Point[MAXN << 2];






		}
		
		void build(int index, int left, int right) {
			if(left == right) {
				tree[index] = new Point(0, left);
			}
			else {
				int mid = (left + right) / 2;
				
				build(index * 2, left, mid);
				build((index * 2) + 1, mid + 1, right);


				if(tree[(index * 2)].x < tree[(index * 2) + 1].x) {
					tree[index] = tree[(index * 2)];
				}
				else if(tree[(index * 2)].x == tree[(index * 2) + 1].x) {
					if(tree[(index * 2) + 1].y == n) {
						tree[index] = tree[(index * 2) + 1]; 
					}
					else {
						tree[index] = tree[index * 2];
					}
				}
				else {
					tree[index] = tree[(index * 2) + 1];
				}
			}
		}
		
		Point query(int node, int left, int right, int start, int end) {
			
			if(left > end || right < start) {
				return new Point(MAXN, -1);
			}
			
			if(left >= start && right <= end) {
				return tree[node];
			}
			int mid = (left + right) / 2;
			Point val1 = query(2 * node, left, mid, start, end);
			Point val2 = query(2 * node + 1, mid + 1, right, start, end);
			if(val1.x < val2.x) {
				return val1;
			}
			else if(val1.x == val2.x) {
				if(tree[(2 * node) + 1].y == n) {
					return val2;
				}
				return val1;
			}
			else {
				return val2;
			}
		}
		
		void update(int node, int left, int right, int idx, long val) {
			if(left == right) {
				tree[node].x += val;
			}
			else {
				int mid = (left + right) / 2;
				if(idx <= mid) {
					update(2 * node, left, mid, idx, val);
				}
				else {
					update(2 * node + 1, mid + 1, right, idx, val);
				}


				if(tree[2 * node].x < tree[(2 * node) + 1].x) {
					tree[node] = tree[2 * node];
				}
				else if(tree[(2 * node)].x == tree[(2 * node) + 1].x) {
					if(tree[(2 * node) + 1].y == n) {
						tree[node] = tree[(2 * node) + 1];
					}
					else {
						tree[node] = tree[2 * node];
					}
				}
				else {
					tree[node] = tree[(2 * node) + 1];
				}
			}
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
			
			List<Integer> prefixTable = id3(s);
			
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

		
		private List<Integer> id3(char[] pattern){
			
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

	
	private static int id4(long[] arr, long num) {
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

	
	private static int id2(long[] arr, long num) {

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