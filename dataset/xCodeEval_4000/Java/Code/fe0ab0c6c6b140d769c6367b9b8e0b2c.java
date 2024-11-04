import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Random;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;



public final class CFPSOptimized {
	static FastReader fr = new FastReader();
	static PrintWriter out = new PrintWriter(System.out);
	static final int gigamod = 1000000007;
	static int t = 1;
	static double epsilon = 0.0000001;
	
	public static void main(String[] args) {
		t = fr.nextInt();
		OUTER: 
		for (int tc = 0; tc < t; tc++) {
			
			long n = fr.nextLong();
			
			if (n < 2) {
				out.println("NO");
				continue OUTER;
			}
			
			if (n % 2 == 1) {
				out.println("NO");
				continue OUTER;
			}
			
			

			long nBy2Sqrt = (long) Math.sqrt(n / 2);
			
			if ((long) Math.pow(2, log2(n)) == n) {
				out.println("YES");
				continue OUTER;
			}
			
			if (nBy2Sqrt * nBy2Sqrt == n / 2) {
				out.println("YES");
				continue OUTER;
			}
			
			long nSqrt = (long)Math.sqrt(n);
			
			if (nSqrt * nSqrt == n) {
				out.println("YES");
				continue OUTER;
			}
			
			out.println("NO");
		}
		out.close();
	}
	
	

	

	static int longestPrefixSuffix(String s) {
		int n = s.length();
		int[] arr = new int[n];
		arr[0] = 0;
		int len = 0;
		for (int i = 1; i < n;) {
			if (s.charAt(len) == s.charAt(i)) {
				len++;
				arr[i++] = len;
			} else {
				if (len != 0) {
					len = arr[len - 1];
				} else {
					arr[i] = 0;
					i++;
				}
			}
		}
		return arr[n - 1];
	}
	
	static long hash(long i) {
		return (i * 2654435761L % gigamod);
	}

	static long power(long x, int y)
	  {
		

		

	    long res = 1; 

	 
	    

	    

	 
	    if (x == 0)
	      return 0; 

	 
	    while (y > 0)
	    {
	 
	      

	      if ((y & 1) != 0)
	        res = (res * x);
	 
	      

	      y = y >> 1; 

	      x = (x * x);
	    }
	    return res;
	  }
	
	

	

	static int mapTo1D(int row, int col, int n, int m) {
		return row * m + col;
	}
	
	

	static int[] mapTo2D(int idx, int n, int m) {
		int[] rnc = new int[2];
		rnc[0] = idx / m;
		rnc[1] = idx % m;
		return rnc;
	}
	
	

	static boolean hasSubsequence(String s, String t) {
		char[] schars = s.toCharArray();
		char[] tchars = t.toCharArray();
		int slen = schars.length, tlen = tchars.length;
		int tctr = 0;
		
		if (slen < tlen) return false;
		
		for (int i = 0; i < slen || i < tlen; i++) {
			if (tctr == tlen) break;
			if (schars[i] == tchars[tctr]) {
				tctr++;
			}
		}
		
		if (tctr == tlen) return true;
		return false;
	}
	
	

	static String toBinaryString(long num, int bits) {
		StringBuilder sb = new StringBuilder(Long.toBinaryString(num));
		sb.reverse();
		for (int i = sb.length(); i < bits; i++)
			sb.append('0');
		return sb.reverse().toString();
	}
	
	static class CountMap extends HashMap<Long, Integer>{
		
		CountMap() {
		}
		
		CountMap(int[] arr) {
			this.put(arr);
		}
		
		CountMap(long[] arr) {
			put(arr);
		}
		
		CountMap(CountMap cm) {
			
		}
		
		public void removeTM(Long key) {
			super.remove(key);
		}
		
		public void removeTM(Integer key) {
			super.remove((long) key);
		}
		
		public Integer put(Long key) {
			if (super.containsKey(key)) {
				return super.put(key, super.get(key) + 1);
			} else {
				return super.put(key, 1);
			}
		}
		
		public Integer put(int key) {
			if (super.containsKey((long) key)) {
				return super.put((long) key, super.get((long) key) + 1);
			} else {
				return super.put((long) key, 1);
			}
		}
		
		public Integer remove(Long key) {
			Integer count = super.get(key);
			if (count == null) return -1;
			if (count == 1)
				return super.remove(key);
			else
				return super.put(key, super.get(key) - 1);
		}
		
		public Integer remove(int key) {
			Integer count = super.get((long) key);
			if (count == null) return -1;
			if (count == 1)
				return super.remove((long) key);
			else
				return super.put((long) key, super.get((long) key) - 1);
		}
		
		public Integer get(int key) {
			Integer count = super.get((long) key);
			if (count == null)
				return 0;
			return count;
		}
		
		public Integer get(long key) {
			Integer count = super.get(key);
			if (count == null)
				return 0;
			return count;
		}
	
		public void put(int[] arr) {
			for (int i : arr)
				this.put(i);
		}
		
		public void put(long[] arr) {
			for (long l : arr)
				this.put(l);
		}
	}
	
	static class Point implements Comparable<Point> {
		long x;
		long y;
		long id;
		
		Point() {
			x = y = id = 0;
		}
		
		Point(Point p) {
			this.x = p.x;
			this.y = p.y;
			this.id = p.id;
		}
		
		
		
		Point(long a, long b, long id) {
			this.x = a;
			this.y = b;
			this.id = id;
		}
		
		Point(long a, long b) {
			this.x = a;
			this.y = b;
		}
		
		@Override
		public int compareTo(Point o) {
			if (this.x > o.x)
				return 1;
			if (this.x < o.x)
				return -1;
			if (this.y > o.y)
				return 1;
			if (this.y < o.y)
				return -1;
			return 0;
		}
		
		public boolean equals(Point that) {
			return this.compareTo(that) == 0;
		}
	}
	
	static class PointComparator implements Comparator<Point> {
		@Override
		public int compare(Point o1, Point o2) {
			
			

			

			
			if (o1.id > o2.id)
				return -1;
			if (o1.id < o2.id)
				return 1;
			
			return 0;
		}
	}
	
	static double distToOrigin(Point p1) {
		return Math.sqrt(Math.pow(p1.y, 2) + Math.pow(p1.x, 2));
	}
	
	static double distance(Point p1, Point p2) {
		
		double y2 = p2.y, y1 = p1.y;
		double x2 = p2.x, x1 = p1.x;
		
		double distance = Math.sqrt(Math.pow(y2-y1, 2) + Math.pow(x2-x1, 2));
		return distance;
	}
	
	

	static int largestFittingPower(long n, long k) {
		int lo = 0, hi = logk(Long.MAX_VALUE, 3);
		int largestPower = -1;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			
			long val = (long) Math.pow(k, mid);
			if (val <= n) {
				largestPower = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		return largestPower;
	}
	
	

	static HashMap<Long, Integer> primeFactorization(long num) {
		HashMap<Long, Integer> map = new HashMap<>();
		while (num % 2 == 0) {
			num /= 2;
			Integer pwrCnt = map.get(2L);
			map.put(2L, pwrCnt != null ? pwrCnt + 1 : 1);
		}
		
		for (long i = 3; i * i <= num; i += 2) {
			while (num % i == 0) {
				num /= i;
				Integer pwrCnt = map.get(i);
				map.put(i, pwrCnt != null ? pwrCnt + 1 : 1);
			}
		}
		
		

		

		if (num != 1)
			map.put(num, 1);
		
		return map;
	}
	
	

	static TreeMap<Integer, Integer> primeFactorization(int num) {
		TreeMap<Integer, Integer> map = new TreeMap<>();
		while (num % 2 == 0) {
			num /= 2;
			Integer pwrCnt = map.get(2);
			map.put(2, pwrCnt != null ? pwrCnt + 1 : 1);
		}
		
		for (int i = 3; i * i <= num; i += 2) {
			while (num % i == 0) {
				num /= i;
				Integer pwrCnt = map.get(i);
				map.put(i, pwrCnt != null ? pwrCnt + 1 : 1);
			}
		}
		
		

		

		if (num != 1)
			map.put(num, 1);
		
		return map;
	}
	
	static HashSet<Long> divisors(long num) {
		HashSet<Long> divisors = new HashSet<Long>();
		divisors.add(1L);
		divisors.add(num);
		
		for (long i = 2; i * i <= num; i++) {
			if (num % i == 0) {
				divisors.add(num/i);
				divisors.add(i);
			}
		}
		return divisors;
	}
	
	

	

	static int bsearch(int[] arr, int val, int lo, int hi) {
		int idx = -1;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			if (arr[mid] >= val) {
				idx = mid;
				hi = mid - 1;
			} else
				lo = mid + 1;
		}
		return idx;
	}
	
	static int bsearch(long[] arr, long val, int lo, int hi) {
		int idx = -1;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			if (arr[mid] >= val) {
				idx = mid;
				hi = mid - 1;
			} else
				lo = mid + 1;
		}
		return idx;
	}
	
	

	

	static int bsearch(long[] arr, long val, int lo, int hi, boolean sMode) {
		int idx = -1;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			if (arr[mid] > val) {
				hi = mid - 1;
			} else {
				idx = mid;
				lo = mid + 1;
			}
		}
		return idx;
	}
	
	static int bsearch(int[] arr, long val, int lo, int hi, boolean sMode) {
		int idx = -1;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			if (arr[mid] > val) {
				hi = mid - 1;
			} else {
				idx = mid;
				lo = mid + 1;
			}
		}
		return idx;
	}
	
	static long factorial(long n) {
		if (n <= 1)
			return 1;
		long factorial = 1;
		for (int i = 1; i <= n; i++)
			factorial = mod(factorial * i);
		return factorial;
	}
	
	static long factorialInDivision(long a, long b) {
		if (a == b)
			return 1;
		if (b < a) {
			long temp = a;
			a = b;
			b = temp;
		}
		
		long factorial = 1;
		for (long i = a + 1; i <= b; i++)
			factorial = mod(factorial * i);
		return factorial;
	}
	
	static BigInteger factorialInDivision(BigInteger a, BigInteger b) {
		if (a.equals(b))
			return BigInteger.ONE;
		return a.multiply(factorialInDivision(a.subtract(BigInteger.ONE), b));
	}
	
	static long nCr(long n, long r) {
		long p = gigamod;
	    

	    if (r == 0)
	        return 1;
	 
	    

	    

	    

	    long fac[] = new long[(int)n + 1];
	    fac[0] = 1;
	    for (int i = 1; i <= n; i++)
	        fac[i] = fac[i - 1] * i % p;
	 
	    return (fac[(int)n] * modInverse(fac[(int)r], p) % p
	                    * modInverse(fac[(int)n - (int)r], p) % p) % p;
	}
	
	static long modInverse(long n, long p) {
	    return power(n, p - 2, p);
	}
	
	static long power(long x, long y, long p) {
	    long res = 1; 

	 
	    x = x % p; 

	    

	 
	    while (y > 0) {
	        

	        if ((y & 1)==1)
	            res = (res * x) % p;
	 
	        

	        y = y >> 1; 

	        x = (x * x) % p;
	    }
	    return res;
	}
	
	static long nPr(long n, long r) {
		return factorialInDivision(n, n - r);
	}
	
	static int log2(long n) {
		return (int)(Math.log(n) / Math.log(2));
	}
	
	static double log2(long n, boolean doubleMode) {
		return (Math.log(n) / Math.log(2));
	}
	
	static int logk(long n, long k) {
		return (int)(Math.log(n) / Math.log(k));
	}
	
	

	static boolean[] primeGenerator(int upto) {
		boolean[] isPrime = new boolean[upto + 1];
		Arrays.fill(isPrime, true);
		isPrime[1] = isPrime[0] = false;

		for (long i = 2; i * i < upto + 1; i++)
			if (isPrime[(int) i])
				

				

				for (long j = i; j * i < upto + 1; j++)
					isPrime[(int) j * (int) i] = false;
		return isPrime;
	}

	static int gcd(int a, int b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a % b);
		}
	}
	
	static long gcd(long a, long b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a % b);
		}
	}
	
	static int gcd(int[] arr) {
		int n = arr.length;
		int gcd = arr[0];
		for (int i = 1; i < n; i++) {
			gcd = gcd(gcd, arr[i]);
		}
		return gcd;
	}
	
	static long gcd(long[] arr) {
		int n = arr.length;
		long gcd = arr[0];
		for (int i = 1; i < n; i++) {
			gcd = gcd(gcd, arr[i]);
		}
		return gcd;
	}
	
	static long lcm(int[] arr) {
		long lcm = arr[0];
		int n = arr.length;
		for (int i = 1; i < n; i++) {
			lcm = (lcm * arr[i]) / gcd(lcm, arr[i]);
		}
		return lcm;
	}
	
	static long lcm(long[] arr) {
		long lcm = arr[0];
		int n = arr.length;
		for (int i = 1; i < n; i++) {
			lcm = (lcm * arr[i]) / gcd(lcm, arr[i]);
		}
		return lcm;
	}
	
	static long lcm(int a, int b) {
		return (a * b)/gcd(a, b);
	}
	
	static long lcm(long a, long b) {
		return (a * b)/gcd(a, b);
	}
	
	static boolean less(int a, int b) {
		return a < b ? true : false;
	}
	
	static boolean isSorted(int[] a) {
		for (int i = 1; i < a.length; i++) {
			if (less(a[i], a[i - 1]))
				return false;
		}
		return true;
	}
	
	static boolean isSorted(long[] a) {
		for (int i = 1; i < a.length; i++) {
			if (a[i] < a[i - 1])
				return false;
		}
		return true;
	}

	static void swap(int[] a, int i, int j) {
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	static void swap(long[] a, int i, int j) {
		long temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	static void swap(double[] a, int i, int j) {
		double temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	static void swap(char[] a, int i, int j) {
		char temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	static void sort(int[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
	}
	
	static void sort(char[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
	}
	
	static void sort(long[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
	}
	
	static void sort(double[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
	}
	
	static void reverseSort(int[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
		int n = arr.length;
		for (int i = 0; i < n/2; i++)
			swap(arr, i, n - 1 - i);
	}
	
	static void reverseSort(char[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
		int n = arr.length;
		for (int i = 0; i < n/2; i++)
			swap(arr, i, n - 1 - i);
	}
	
	static void reverseSort(long[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
		int n = arr.length;
		for (int i = 0; i < n/2; i++)
			swap(arr, i, n - 1 - i);
	}
	
	static void reverseSort(double[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
		int n = arr.length;
		for (int i = 0; i < n/2; i++)
			swap(arr, i, n - 1 - i);
	}
	
	static void shuffleArray(long[] arr, int startPos, int endPos) {
		Random rnd = new Random();
		for (int i = startPos; i < endPos; ++i) {
			long tmp = arr[i];
			int randomPos = i + rnd.nextInt(endPos - i);
			arr[i] = arr[randomPos];
			arr[randomPos] = tmp;
		}
	}
	
	static void shuffleArray(int[] arr, int startPos, int endPos) {
		Random rnd = new Random();
		for (int i = startPos; i < endPos; ++i) {
			int tmp = arr[i];
			int randomPos = i + rnd.nextInt(endPos - i);
			arr[i] = arr[randomPos];
			arr[randomPos] = tmp;
		}
	}
	
	static void shuffleArray(double[] arr, int startPos, int endPos) {
		Random rnd = new Random();
		for (int i = startPos; i < endPos; ++i) {
			double tmp = arr[i];
			int randomPos = i + rnd.nextInt(endPos - i);
			arr[i] = arr[randomPos];
			arr[randomPos] = tmp;
		}
	}
	
	private static void shuffleArray(char[] arr, int startPos, int endPos) {
		Random rnd = new Random();
		for (int i = startPos; i < endPos; ++i) {
			char tmp = arr[i];
			int randomPos = i + rnd.nextInt(endPos - i);
			arr[i] = arr[randomPos];
			arr[randomPos] = tmp;
		}
	}
	
	static boolean isPrime(long n) {
		if (n <= 1)
			return false;
		if (n <= 3)
			return true;

		if (n % 2 == 0 || n % 3 == 0)
			return false;

		for (long i = 5; i * i <= n; i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;

		return true;
	}

	static String toString(int[] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++)
			sb.append(dp[i] + " ");
		return sb.toString();
	}
	
	static String toString(boolean[] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++)
			sb.append(dp[i] + " ");
		return sb.toString();
	}
	
	static String toString(long[] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++)
			sb.append(dp[i] + " ");
		return sb.toString();
	}
	
	static String toString(char[] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++)
			sb.append(dp[i] + "");
		return sb.toString();
	}
	
	static String toString(int[][] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				sb.append(dp[i][j] + "");
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	static String toString(long[][] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				sb.append(dp[i][j] + " ");
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	static String toString(double[][] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				sb.append(dp[i][j] + " ");
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	static String toString(char[][] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				sb.append(dp[i][j] + " ");
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	static char toChar(int i) {
		return (char) (i + 48);
	}
	
	static long mod(long a, long m) {
	    return (a%m + m) % m;
	}
	
	static long mod(long num) {
		return (num % gigamod + gigamod) % gigamod;
	}
	
	

	static class UnionFind {
	    private int[] parent;  

	    private int[] size;    

	                           

	    private int count;     


	    public UnionFind(int n) {
	        count = n;
	        parent = new int[n];
	        size = new int[n];
	        for (int i = 0; i < n; i++) {
	            parent[i] = i;
	            size[i] = 1;
	        }
	    }

	    

	    public int count() {
	        return count;
	    }
	  
	    

	    public int find(int p) {
	        int root = p;
	        while (root != parent[root])
	            root = parent[root];
	        while (p != root) {
	            int newp = parent[p];
	            parent[p] = root;
	            p = newp;
	        }
	        return root;
	    }

	    public boolean connected(int p, int q) {
	        return find(p) == find(q);
	    }
	    
	    public int numConnectedTo(int node) {
	    	return size[find(node)];
	    }
	    
	    

	    public void union(int p, int q) {
	        int rootP = find(p);
	        int rootQ = find(q);
	        
	        if (rootP == rootQ) return;

	        

	        if (size[rootP] < size[rootQ]) {
	            parent[rootP] = rootQ;
	            size[rootQ] += size[rootP];
	        }
	        else {
	            parent[rootQ] = rootP;
	            size[rootP] += size[rootQ];
	        }
	        count--;
	    }
	    
	    public static int[] connectedComponents(UnionFind uf) {
	    	

	    	
	    	int n = uf.size.length;
	    	int[] compoColors = new int[n];
	    	for (int i = 0; i < n; i++)
	    		compoColors[i] = uf.find(i);
	    	
	    	HashMap<Integer, Integer> oldToNew = new HashMap<>();
	    	int newCtr = 0;
	    	
	    	for (int i = 0; i < n; i++) {
	    		
	    		int thisOldColor = compoColors[i];
	    		Integer thisNewColor = oldToNew.get(thisOldColor);
	    		if (thisNewColor == null)
	    			thisNewColor = newCtr++;
	    		
	    		oldToNew.put(thisOldColor, thisNewColor);
	    		compoColors[i] = thisNewColor;
	    	}
	    	
	    	return compoColors;
	    }
	}
	
	static class UGraph {
		

		private HashSet<Integer>[] adj;
		private static final String NEWLINE = "\n";
		private int E;
		
		public UGraph(int V) {
			adj = (HashSet<Integer>[]) new HashSet[V];
			E = 0;
			for (int i = 0; i < V; i++)
				adj[i] = new HashSet<Integer>();
		}
		
		public void addEdge(int from, int to) {
			if (adj[from].contains(to)) return;
			E++;
			adj[from].add(to);
			adj[to].add(from);
		}
		
		public HashSet<Integer> adj(int from) {
			return adj[from];
		}
		
		public int degree(int v) {
			return adj[v].size();
		}
		
		public int V() {
			return adj.length;
		}
		
		public int E() {
			return E;
		}
		
		public String toString() {
			StringBuilder s = new StringBuilder();
			s.append(V() + " vertices, " + E() + " edges " + NEWLINE);
			for (int v = 0; v < V(); v++) {
				s.append(v + ": ");
				for (int w : adj[v]) {
					s.append(w + " ");
				}
				s.append(NEWLINE);
			}
			return s.toString();
		}
		
		public static void dfsMark(int current, boolean[] marked, UGraph g) {
			if (marked[current]) return;
			
			marked[current] = true;
			Iterable<Integer> adj = g.adj(current);
			for (int adjc : adj)
				dfsMark(adjc, marked, g);
		}
		
		public static void dfsMark(int current, int from, long[] distTo, boolean[] marked, UGraph g, ArrayList<Integer> endPoints) {
			if (marked[current]) return;
			
			marked[current] = true;
			if (from != -1)
				distTo[current] = distTo[from] + 1;
			HashSet<Integer> adj = g.adj(current);
			int alreadyMarkedCtr = 0;
			for (int adjc : adj) {
				if (marked[adjc]) alreadyMarkedCtr++;
				dfsMark(adjc, current, distTo, marked, g, endPoints);
			}
			
			if (alreadyMarkedCtr == adj.size())
				endPoints.add(current);
		}
		
		public static void bfsOrder(int current, UGraph g) {
		}
		
		public static void dfsMark(int current, int[] colorIds, int color, UGraph g) {
			if (colorIds[current] != -1) return;
			
			colorIds[current] = color;
			Iterable<Integer> adj = g.adj(current);
			for (int adjc : adj)
				dfsMark(adjc, colorIds, color, g);
		}
		
		public static int[] connectedComponents(UGraph g) {
			int n = g.V();
			int[] componentId = new int[n];
			Arrays.fill(componentId, -1);
			int colorCtr = 0;
			for (int i = 0; i < n; i++) {
				if (componentId[i] != -1) continue;
				dfsMark(i, componentId, colorCtr, g);
				colorCtr++;
			}
			
			return componentId;
		}
		
		public static boolean hasCycle(UGraph ug) {
			int n = ug.V();
			boolean[] marked = new boolean[n];
			boolean[] hasCycleFirst = new boolean[1];
			for (int i = 0; i < n; i++) {
				if (marked[i]) continue;
				hcDfsMark(i, ug, marked, hasCycleFirst, -1);
			}
			return hasCycleFirst[0];
		}
		
		

		private static void hcDfsMark(int current, UGraph ug, boolean[] marked, boolean[] hasCycleFirst, int parent) {
			if (marked[current]) return;
			if (hasCycleFirst[0]) return;
			
			marked[current] = true;
			HashSet<Integer> adjc = ug.adj(current);
			for (int adj : adjc) {
				if (marked[adj] && adj != parent && parent != -1) {
					hasCycleFirst[0] = true;
					return;
				}
				
				hcDfsMark(adj, ug, marked, hasCycleFirst, current);
			}
		}
	}
	
	static class Digraph {
		

		private HashSet<Integer>[] adj;
		private static final String NEWLINE = "\n";
		private int E;
		
		public Digraph(int V) {
			adj = (HashSet<Integer>[]) new HashSet[V];
			E = 0;
			for (int i = 0; i < V; i++)
				adj[i] = new HashSet<Integer>();
		}
		
		public void addEdge(int from, int to) {
			if (adj[from].contains(to)) return;
			E++;
			adj[from].add(to);
		}
		
		public HashSet<Integer> adj(int from) {
			return adj[from];
		}
		
		public int V() {
			return adj.length;
		}
		
		public int E() {
			return E;
		}
		
		public Digraph reversed() {
			Digraph dg = new Digraph(V());
			for (int i = 0; i < V(); i++)
				for (int adjVert : adj(i)) dg.addEdge(adjVert, i);
			return dg;
		}
		
		public String toString() {
			StringBuilder s = new StringBuilder();
			s.append(V() + " vertices, " + E() + " edges " + NEWLINE);
			for (int v = 0; v < V(); v++) {
				s.append(v + ": ");
				for (int w : adj[v]) {
					s.append(w + " ");
				}
				s.append(NEWLINE);
			}
			return s.toString();
		}
		
		public static void dfsMark(int source, boolean[] marked, Digraph g) {
			if (marked[source]) return;
			
			marked[source] = true;
			Iterable<Integer> adj = g.adj(source);
			for (int adjc : adj)
				dfsMark(adjc, marked, g);
		}
		
		public static void bfsOrder(int source, Digraph g) {
		}
		
		public static int[] KosarajuSharirSCC(Digraph dg) {
			int[] id = new int[dg.V()];
			
			Digraph reversed = dg.reversed();
			
			

			Stack<Integer> revStack = Digraph.topologicalSort(reversed);
			
			

			id = new int[dg.V()];
			int idCtr = -1;
			
			

			boolean[] marked = new boolean[dg.V()];
			
			while (!revStack.isEmpty()) {
				int vertex = revStack.pop();
				if (!marked[vertex]) 
					sccDFS(dg, vertex, marked, ++idCtr, id);
			}
			return id;
		}
		
		private static void sccDFS(Digraph dg, int source, boolean[] marked, int idCtr, int[] id) {
			marked[source] = true;
			id[source] = idCtr;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) sccDFS(dg, adjVertex, marked, idCtr, id);
		}
		
		public static Stack<Integer> topologicalSort(Digraph dg) {
			

			

			

			Stack<Integer> topologicalStack = new Stack<Integer>();
			boolean[] marked = new boolean[dg.V()];
			
			

			for (int i = 0; i < dg.V(); i++)
				if (!marked[i]) 
					runDfs(dg, topologicalStack, marked, i);
			
			return topologicalStack;
		}
		
		static void runDfs(Digraph dg, Stack<Integer> topologicalStack, boolean[] marked, int source) {
			marked[source] = true;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) 
					runDfs(dg, topologicalStack, marked, adjVertex);
			topologicalStack.add(source);
		}
		
		public static boolean hasCycle(Digraph dg) {
			int n = dg.V();
			boolean[] marked = new boolean[n];
			boolean[] hasCycleFirst = new boolean[1];
			for (int i = 0; i < n; i++) {
				if (marked[i]) continue;
				hcDfsMark(i, dg, marked, hasCycleFirst, -1);
			}
			return hasCycleFirst[0];
		}
		
		

		private static void hcDfsMark(int current, Digraph dg, boolean[] marked, boolean[] hasCycleFirst, int parent) {
			if (marked[current]) return;
			if (hasCycleFirst[0]) return;
			
			marked[current] = true;
			HashSet<Integer> adjc = dg.adj(current);
			for (int adj : adjc) {
				if (marked[adj] && adj != parent && parent != -1) {
					hasCycleFirst[0] = true;
					return;
				}
				
				hcDfsMark(adj, dg, marked, hasCycleFirst, current);
			}
		}
	}
	
	public static class DirectedEdge implements Comparable<DirectedEdge> { 
	    private final int v;
	    private final int w;
	    private final double weight;

	    public DirectedEdge(int v, int w, double weight) {
	        this.v = v;
	        this.w = w;
	        this.weight = weight;
	    }

	    public int from() {
	        return v;
	    }

	    public int to() {
	        return w;
	    }
	    
	    public double weight() {
	        return weight;
	    }
	    
	    public String toString() {
	        return v + "->" + w + " " + String.format("%5.2f", weight);
	    }

		@Override
		public int compareTo(DirectedEdge o) {
			if (this.v > o.v)
				return 1;
			if (this.v < o.v)
				return -1;
			if (this.w > o.w)
				return 1;
			if (this.w < o.w)
				return -1;
			if (this.weight > o.weight)
				return 1;
			if (this.weight < o.weight)
				return -1;
			return 0;
		}
	}
	
	public static class Edge implements Comparable<Edge> { 

	    private final int v;
	    private final int w;
	    private final double weight;

	    public Edge(int v, int w, double weight) {
	        if (v < 0) throw new IllegalArgumentException("vertex index must be a nonnegative integer");
	        if (w < 0) throw new IllegalArgumentException("vertex index must be a nonnegative integer");
	        if (Double.isNaN(weight)) throw new IllegalArgumentException("Weight is NaN");
	        this.v = v;
	        this.w = w;
	        this.weight = weight;
	    }

	    public double weight() {
	        return weight;
	    }

	    public int either() {
	        return v;
	    }

	    public int other(int vertex) {
	        if      (vertex == v) return w;
	        else if (vertex == w) return v;
	        else throw new IllegalArgumentException("Illegal endpoint");
	    }

	    @Override
	    public int compareTo(Edge that) {
	        return Double.compare(this.weight, that.weight);
	    }

	    public String toString() {
	        return String.format("%d-%d %.5f", v, w, weight);
	    }
	}
	
	public static class EdgeWeightedDigraph {
	    private static final String NEWLINE = System.getProperty("line.separator");

	    private final int V;                

	    private int E;                      

	    private HashSet<DirectedEdge>[] adj;    

	    private int[] indegree;             

	    
	    public EdgeWeightedDigraph(int V) {
	        if (V < 0) throw new IllegalArgumentException("Number of vertices in a Digraph must be nonnegative");
	        this.V = V;
	        this.E = 0;
	        this.indegree = new int[V];
	        adj = (HashSet<DirectedEdge>[]) new HashSet[V];
	        for (int v = 0; v < V; v++)
	            adj[v] = new HashSet<DirectedEdge>();
	    }

	    
	    public EdgeWeightedDigraph(EdgeWeightedDigraph G) {
	        this(G.V());
	        this.E = G.E();
	        for (int v = 0; v < G.V(); v++)
	            this.indegree[v] = G.indegree(v);
	        for (int v = 0; v < G.V(); v++) {
	            

	            Stack<DirectedEdge> reverse = new Stack<DirectedEdge>();
	            for (DirectedEdge e : G.adj[v]) {
	                reverse.push(e);
	            }
	            for (DirectedEdge e : reverse) {
	                adj[v].add(e);
	            }
	        }
	    }

	    public int V() {
	        return V;
	    }

	    public int E() {
	        return E;
	    }

	    public void addEdge(DirectedEdge e) {
	        int v = e.from();
	        int w = e.to();
	        adj[v].add(e);
	        indegree[w]++;
	        E++;
	    }
	    
	    public void addEdge(int from, int to, long weight) {
	    	addEdge(new DirectedEdge(from, to, weight));
	    }

	    public Iterable<DirectedEdge> adj(int v) {
	        return adj[v];
	    }

	    public int outdegree(int v) {
	        return adj[v].size();
	    }
	    
	    public int indegree(int v) {
	        return indegree[v];
	    }
	    
	    public Iterable<DirectedEdge> edges() {
	        HashSet<DirectedEdge> list = new HashSet<DirectedEdge>();
	        for (int v = 0; v < V; v++) {
	            for (DirectedEdge e : adj(v)) {
	                list.add(e);
	            }
	        }
	        return list;
	    } 

	    public String toString() {
	        StringBuilder s = new StringBuilder();
	        s.append(V + " " + E + NEWLINE);
	        for (int v = 0; v < V; v++) {
	            s.append(v + ": ");
	            for (DirectedEdge e : adj[v]) {
	                s.append(e + "  ");
	            }
	            s.append(NEWLINE);
	        }
	        return s.toString();
	    }
	}
	
	public static class EdgeWeightedGraph {
	    private static final String NEWLINE = System.getProperty("line.separator");

	    private final int V;
	    private int E;
	    private HashSet<Edge>[] adj;
	    
	    public EdgeWeightedGraph(int V) {
	        this.V = V;
	        this.E = 0;
	        adj = (HashSet<Edge>[]) new HashSet[V];
	        for (int v = 0; v < V; v++) {
	            adj[v] = new HashSet<Edge>();
	        }
	    }

	    public EdgeWeightedGraph(EdgeWeightedGraph G) {
	        this(G.V());
	        this.E = G.E();
	        for (int v = 0; v < G.V(); v++) {
	            

	            Stack<Edge> reverse = new Stack<Edge>();
	            for (Edge e : G.adj[v]) {
	                reverse.push(e);
	            }
	            for (Edge e : reverse) {
	                adj[v].add(e);
	            }
	        }
	    }

	    public int V() {
	        return V;
	    }

	    public int E() {
	        return E;
	    }

	    public void addEdge(Edge e) {
	        int v = e.either();
	        int w = e.other(v);
	        adj[v].add(e);
	        adj[w].add(e);
	        E++;
	    }
	    
	    public void addEdge(int from, int to, double weight) {
	    	addEdge(new Edge(from, to, weight));
	    }

	    public Iterable<Edge> adj(int v) {
	        return adj[v];
	    }

	    public int degree(int v) {
	        return adj[v].size();
	    }

	    public Iterable<Edge> edges() {
	        HashSet<Edge> list = new HashSet<Edge>();
	        for (int v = 0; v < V; v++) {
	            int selfLoops = 0;
	            for (Edge e : adj(v)) {
	                if (e.other(v) > v) {
	                    list.add(e);
	                }
	                

	                else if (e.other(v) == v) {
	                    if (selfLoops % 2 == 0) list.add(e);
	                    selfLoops++;
	                }
	            }
	        }
	        return list;
	    }
	    
	    public String toString() {
	        StringBuilder s = new StringBuilder();
	        s.append(V + " " + E + NEWLINE);
	        for (int v = 0; v < V; v++) {
	            s.append(v + ": ");
	            for (Edge e : adj[v]) {
	                s.append(e + "  ");
	            }
	            s.append(NEWLINE);
	        }
	        return s.toString();
	    }
	}
	
	public static class DirectedCycle {
	    private boolean[] marked;        

	    private int[] edgeTo;            

	    private boolean[] onStack;       

	    private Stack<Integer> cycle;    


	    
	    public DirectedCycle(Digraph G) {
	        marked  = new boolean[G.V()];
	        onStack = new boolean[G.V()];
	        edgeTo  = new int[G.V()];
	        for (int v = 0; v < G.V(); v++)
	            if (!marked[v] && cycle == null) dfs(G, v);
	    }

	    

	    private void dfs(Digraph G, int v) {
	        onStack[v] = true;
	        marked[v] = true;
	        for (int w : G.adj(v)) {

	            

	            if (cycle != null) return;

	            

	            else if (!marked[w]) {
	                edgeTo[w] = v;
	                dfs(G, w);
	            }

	            

	            else if (onStack[w]) {
	                cycle = new Stack<Integer>();
	                for (int x = v; x != w; x = edgeTo[x]) {
	                    cycle.push(x);
	                }
	                cycle.push(w);
	                cycle.push(v);
	                assert check();
	            }
	        }
	        onStack[v] = false;
	    }

	    
	    public boolean hasCycle() {
	        return cycle != null;
	    }

	    
	    public Iterable<Integer> cycle() {
	        return cycle;
	    }


	    

	    private boolean check() {

	        if (hasCycle()) {
	            

	            int first = -1, last = -1;
	            for (int v : cycle()) {
	                if (first == -1) first = v;
	                last = v;
	            }
	            if (first != last) {
	                System.err.printf("cycle begins with %d and ends with %d\n", first, last);
	                return false;
	            }
	        }


	        return true;
	    }
	}
	
	static class FastReader {
		private BufferedReader bfr;
		private StringTokenizer st;
		public FastReader() {
			bfr = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			if (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(bfr.readLine());
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

		char nextChar() {
			return next().toCharArray()[0];
		}

		String nextString() {
			return next();
		}

		int[] nextIntArray(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextInt();
			return arr;
		}

		double[] nextDoubleArray(int n) {
			double[] arr = new double[n];
			for (int i = 0; i < arr.length; i++)
				arr[i] = nextDouble();
			return arr;
		}

		long[] nextLongArray(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextLong();
			return arr;
		}
		
		int[][] nextIntGrid(int n, int m) {
			int[][] grid = new int[n][m];
			for (int i = 0; i < n; i++) {
				char[] line = fr.next().toCharArray();
				for (int j = 0; j < m; j++)
					grid[i][j] = line[j] - 48;
			}
			return grid;
		}
	}
	
	private static class IndexMaxPQ<Key extends Comparable<Key>> implements Iterable<Integer> {
	    private int maxN;        

	    private int n;           

	    private int[] pq;        

	    private int[] qp;        

	    private Key[] keys;      


	    public IndexMaxPQ(int maxN) {
	        if (maxN < 0) throw new IllegalArgumentException();
	        this.maxN = maxN;
	        n = 0;
	        keys = (Key[]) new Comparable[maxN + 1];    

	        pq   = new int[maxN + 1];
	        qp   = new int[maxN + 1];                   

	        for (int i = 0; i <= maxN; i++)
	            qp[i] = -1;
	    }

	    public boolean isEmpty() {
	        return n == 0;
	    }

	    public boolean contains(int i) {
	        validateIndex(i);
	        return qp[i] != -1;
	    }

	    public int size() {
	        return n;
	    }

	   
	    public void insert(int i, Key key) {
	        validateIndex(i);
	        if (contains(i)) throw new IllegalArgumentException("index is already in the priority queue");
	        n++;
	        qp[i] = n;
	        pq[n] = i;
	        keys[i] = key;
	        swim(n);
	    }

	    
	    public int maxIndex() {
	        if (n == 0) throw new NoSuchElementException("Priority queue underflow");
	        return pq[1];
	    }

	    
	    public Key maxKey() {
	        if (n == 0) throw new NoSuchElementException("Priority queue underflow");
	        return keys[pq[1]];
	    }

	    
	    public int delMax() {
	        if (n == 0) throw new NoSuchElementException("Priority queue underflow");
	        int max = pq[1];
	        exch(1, n--);
	        sink(1);

	        assert pq[n+1] == max;
	        qp[max] = -1;        

	        keys[max] = null;    

	        pq[n+1] = -1;        

	        return max;
	    }

	    
	    public Key keyOf(int i) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        else return keys[i];
	    }

	    
	    public void changeKey(int i, Key key) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        keys[i] = key;
	        swim(qp[i]);
	        sink(qp[i]);
	    }

	    
	    public void increaseKey(int i, Key key) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        if (keys[i].compareTo(key) == 0)
	            throw new IllegalArgumentException("Calling increaseKey() with a key equal to the key in the priority queue");
	        if (keys[i].compareTo(key) > 0)
	            throw new IllegalArgumentException("Calling increaseKey() with a key that is strictly less than the key in the priority queue");

	        keys[i] = key;
	        swim(qp[i]);
	    }

	    
	    public void decreaseKey(int i, Key key) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        if (keys[i].compareTo(key) == 0)
	            throw new IllegalArgumentException("Calling decreaseKey() with a key equal to the key in the priority queue");
	        if (keys[i].compareTo(key) < 0)
	            throw new IllegalArgumentException("Calling decreaseKey() with a key that is strictly greater than the key in the priority queue");
	        keys[i] = key;
	        sink(qp[i]);
	    }

	    
	    public void delete(int i) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        int index = qp[i];
	        exch(index, n--);
	        swim(index);
	        sink(index);
	        keys[i] = null;
	        qp[i] = -1;
	    }

	    

	    private void validateIndex(int i) {
	        if (i < 0) throw new IllegalArgumentException("index is negative: " + i);
	        if (i >= maxN) throw new IllegalArgumentException("index >= capacity: " + i);
	    }
	    
	    private boolean less(int i, int j) {
	        return keys[pq[i]].compareTo(keys[pq[j]]) < 0;
	    }

	    private void exch(int i, int j) {
	        int swap = pq[i];
	        pq[i] = pq[j];
	        pq[j] = swap;
	        qp[pq[i]] = i;
	        qp[pq[j]] = j;
	    }

	    private void swim(int k) {
	        while (k > 1 && less(k/2, k)) {
	            exch(k, k/2);
	            k = k/2;
	        }
	    }

	    private void sink(int k) {
	        while (2*k <= n) {
	            int j = 2*k;
	            if (j < n && less(j, j+1)) j++;
	            if (!less(k, j)) break;
	            exch(k, j);
	            k = j;
	        }
	    }


	    
	    public Iterator<Integer> iterator() {
	        return new HeapIterator();
	    }

	    private class HeapIterator implements Iterator<Integer> {
	        

	        private IndexMaxPQ<Key> copy;

	        

	        

	        public HeapIterator() {
	            copy = new IndexMaxPQ<Key>(pq.length - 1);
	            for (int i = 1; i <= n; i++)
	                copy.insert(pq[i], keys[pq[i]]);
	        }

	        public boolean hasNext()  { return !copy.isEmpty();                     }
	        public void remove()      { throw new UnsupportedOperationException();  }

	        public Integer next() {
	            if (!hasNext()) throw new NoSuchElementException();
	            return copy.delMax();
	        }
	    }

	}
	
	public static class IndexMinPQ<Key extends Comparable<Key>> implements Iterable<Integer> {
	    private int maxN;        

	    private int n;           

	    private int[] pq;        

	    private int[] qp;        

	    private Key[] keys;      


	    public IndexMinPQ(int maxN) {
	        if (maxN < 0) throw new IllegalArgumentException();
	        this.maxN = maxN;
	        n = 0;
	        keys = (Key[]) new Comparable[maxN + 1];    

	        pq   = new int[maxN + 1];
	        qp   = new int[maxN + 1];                   

	        for (int i = 0; i <= maxN; i++)
	            qp[i] = -1;
	    }

	    public boolean isEmpty() {
	        return n == 0;
	    }

	    public boolean contains(int i) {
	        validateIndex(i);
	        return qp[i] != -1;
	    }

	    public int size() {
	        return n;
	    }

	    
	    public void insert(int i, Key key) {
	        validateIndex(i);
	        if (contains(i)) throw new IllegalArgumentException("index is already in the priority queue");
	        n++;
	        qp[i] = n;
	        pq[n] = i;
	        keys[i] = key;
	        swim(n);
	    }

	    
	    public int minIndex() {
	        if (n == 0) throw new NoSuchElementException("Priority queue underflow");
	        return pq[1];
	    }

	    
	    public Key minKey() {
	        if (n == 0) throw new NoSuchElementException("Priority queue underflow");
	        return keys[pq[1]];
	    }

	    
	    public int delMin() {
	        if (n == 0) throw new NoSuchElementException("Priority queue underflow");
	        int min = pq[1];
	        exch(1, n--);
	        sink(1);
	        assert min == pq[n+1];
	        qp[min] = -1;        

	        keys[min] = null;    

	        pq[n+1] = -1;        

	        return min;
	    }

	    
	    public Key keyOf(int i) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        else return keys[i];
	    }

	    
	    public void changeKey(int i, Key key) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        keys[i] = key;
	        swim(qp[i]);
	        sink(qp[i]);
	    }

	    
	    public void decreaseKey(int i, Key key) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        if (keys[i].compareTo(key) == 0)
	            throw new IllegalArgumentException("Calling decreaseKey() with a key equal to the key in the priority queue");
	        if (keys[i].compareTo(key) < 0)
	            throw new IllegalArgumentException("Calling decreaseKey() with a key strictly greater than the key in the priority queue");
	        keys[i] = key;
	        swim(qp[i]);
	    }

	    
	    public void increaseKey(int i, Key key) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        if (keys[i].compareTo(key) == 0)
	            throw new IllegalArgumentException("Calling increaseKey() with a key equal to the key in the priority queue");
	        if (keys[i].compareTo(key) > 0)
	            throw new IllegalArgumentException("Calling increaseKey() with a key strictly less than the key in the priority queue");
	        keys[i] = key;
	        sink(qp[i]);
	    }

	    
	    public void delete(int i) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        int index = qp[i];
	        exch(index, n--);
	        swim(index);
	        sink(index);
	        keys[i] = null;
	        qp[i] = -1;
	    }

	    

	    private void validateIndex(int i) {
	        if (i < 0) throw new IllegalArgumentException("index is negative: " + i);
	        if (i >= maxN) throw new IllegalArgumentException("index >= capacity: " + i);
	    }

	    private boolean greater(int i, int j) {
	        return keys[pq[i]].compareTo(keys[pq[j]]) > 0;
	    }

	    private void exch(int i, int j) {
	        int swap = pq[i];
	        pq[i] = pq[j];
	        pq[j] = swap;
	        qp[pq[i]] = i;
	        qp[pq[j]] = j;
	    }

	    private void swim(int k) {
	        while (k > 1 && greater(k/2, k)) {
	            exch(k, k/2);
	            k = k/2;
	        }
	    }

	    private void sink(int k) {
	        while (2*k <= n) {
	            int j = 2*k;
	            if (j < n && greater(j, j+1)) j++;
	            if (!greater(k, j)) break;
	            exch(k, j);
	            k = j;
	        }
	    }

	    public Iterator<Integer> iterator() { return new HeapIterator(); }

	    private class HeapIterator implements Iterator<Integer> {
	        

	        private IndexMinPQ<Key> copy;

	        

	        

	        public HeapIterator() {
	            copy = new IndexMinPQ<Key>(pq.length - 1);
	            for (int i = 1; i <= n; i++)
	                copy.insert(pq[i], keys[pq[i]]);
	        }

	        public boolean hasNext()  { return !copy.isEmpty();                     }
	        public void remove()      { throw new UnsupportedOperationException();  }

	        public Integer next() {
	            if (!hasNext()) throw new NoSuchElementException();
	            return copy.delMin();
	        }
	    }

	}
}












